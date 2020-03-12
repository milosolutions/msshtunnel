#include <QtTest>

#include <sshtunnel.h>

class MSSHTunnelTest : public QObject
{
    Q_OBJECT

public:
    MSSHTunnelTest();
    ~MSSHTunnelTest();

private slots:
    void testSSHTunnelInitializeWithExpectedConfiguration();

};

MSSHTunnelTest::MSSHTunnelTest()
{

}

MSSHTunnelTest::~MSSHTunnelTest()
{

}

void MSSHTunnelTest::testSSHTunnelInitializeWithExpectedConfiguration()
{
    QString expectedUser = QStringLiteral("user1");
    QString expectesHost = QStringLiteral("127.0.0.1");
    constexpr int expectedPort = 65000;

    SShConfig config {
        expectedUser,
        expectesHost,
        expectedPort
    };

    SShTunnel sshTunnel(config);
    QCOMPARE(sshTunnel.config().user, expectedUser);
    QCOMPARE(sshTunnel.config().host, expectesHost);
    QCOMPARE(sshTunnel.config().port, expectedPort);
}

QTEST_APPLESS_MAIN(MSSHTunnelTest)

#include "tst_msshtunneltest.moc"
