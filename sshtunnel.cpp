#include "sshtunnel.h"
#include <QProcess>
#include <QThread>

Q_LOGGING_CATEGORY(ssh, "sshtunnel")

/*!
 * \brief SShTunnel::SShTunnel
 * \param user
 * \param host
 * \param port
 *
 * Assuming user has public key added on host so ssh will log without
 * prompting for password.
 */

SShTunnel::SShTunnel(const QString &user, const QString &host, const int port)
{
    m_ssh = new QProcess();
    m_ssh->setProgram("ssh");
    // connection parameters and prepare for forwading option
    m_sshArgs << QString("%1@%2").arg(user).arg(host) << "-p" << QString::number(port) << "-nNTL";
}

SShTunnel::~SShTunnel()
{
    close();
    delete m_ssh;
}

static bool waitForPortOpenning(int port)
{
    const unsigned int waitInterval{50};  // ms
    const unsigned int waitLimit{20000};  // ms
    QProcess netstat;
    netstat.setProgram("netstat");
    netstat.setArguments({"-tln"});
    QProcess grep;
    grep.setProgram("grep");
    grep.setArguments({QString(":%1").arg(port)});
    netstat.setStandardOutputProcess(&grep);
    // if socket is listening grep will return 0
    unsigned int waited = 0;
    do {
        QThread::msleep(waitInterval);  // wait at least a bit
        waited += waitInterval;
        if (waited > waitLimit) return false;
        netstat.start();
        netstat.waitForFinished();
        grep.start();
        grep.waitForFinished();
    } while (grep.exitCode() != 0);
    qCDebug(ssh, "Port opened in %dms", waited);
    return true;
}

bool SShTunnel::open(const int localPort, const QString &remoteAddress, const int remotePort)
{
    if (m_ssh->state() != QProcess::NotRunning) {
        qCWarning(ssh, "ssh process is already running");
        return false;
    }

    // add info for port forwarding
    m_sshArgs << QString("%1:%2:%3").arg(localPort).arg(remoteAddress).arg(remotePort);
    m_ssh->setArguments(m_sshArgs);

    m_ssh->start();
    qCDebug(ssh, "starting ssh");
    if (!m_ssh->waitForStarted(50)) {
        qCCritical(ssh, "Failed to start ssh");
        return false;
    }

    return waitForPortOpenning(localPort);
}

void SShTunnel::close()
{
    if (m_ssh->state() == QProcess::Running) {
        m_ssh->terminate();
        // return last arg so open can be called again
        m_sshArgs.removeLast();
        m_ssh->waitForFinished(50);
    }
}
