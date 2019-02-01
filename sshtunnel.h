#ifndef SSHTUNNEL_H
#define SSHTUNNEL_H

#include <QString>
#include <QStringList>

class QProcess;

class SShTunnel
{
 public:
    SShTunnel(const QString &user, const QString &host, const int port);
    ~SShTunnel();
    bool open(const int localPort, const QString &remoteAddress, const int remotePort);
    void close();

 private:
    QProcess* m_ssh;
    QStringList m_sshArgs;
};

#endif  // SSHTUNNEL_H
