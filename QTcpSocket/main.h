#ifndef MAIN_H
#define MAIN_H

#include <QTcpSocket>
#include <QDebug>
#include <QObject>

class Socket : public QObject {
	Q_OBJECT
public:
	explicit Socket(QObject *parent = nullptr);
	~Socket() override;

private:
	QTcpSocket *socket;
	
public slots:
	void Connect();
	void Disconnect();
	static void on_Connected();
	static void on_Disconnected();
signals:

};

#endif //MAIN_H
