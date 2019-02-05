#ifndef SSHTUNNEL_H
#define SSHTUNNEL_H

#include <QString>
#include <QStringList>

class QProcess;

class SShConfig
{
 public:
    QString user;
    QString host;
    int port;
};

class SShTunnel
{
 public:
    SShTunnel(const SShConfig &config);
    ~SShTunnel();
    bool open(const int localPort, const QString &remoteAddress, const int remotePort);
    void close();

    SShConfig config() const;
    int localPort() const;
    QString remoteAddress() const;
    int remotePort() const;

 private:
    QProcess* m_ssh;
    SShConfig m_config;
    QStringList m_sshArgs;
    int m_localPort;
    QString m_remoteAddress;
    int m_remotePort;
};

#endif  // SSHTUNNEL_H
