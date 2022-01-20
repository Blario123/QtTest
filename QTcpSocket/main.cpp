#include "main.h"

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Socket s;
	s.Connect();
	s.Disconnect();
	return app.exec();
}

Socket::Socket(QObject *parent) : QObject(parent) {
	socket = new QTcpSocket(this);
	
	connect(socket, SIGNAL(connected()), this, SLOT(on_Connected()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(on_Disconnected()));
}

Socket::~Socket() = default;

void Socket::Connect() {
	socket->connectToHost("localhost", 27015);
	if(!socket->waitForConnected(3000)) {
		if(socket->error() == QAbstractSocket::SocketTimeoutError) {
			qDebug() << "Could not connect to" << socket->peerName() << ":" << socket->peerPort();
		}
	}
}

void Socket::Disconnect() {
	socket->close();
}

void Socket::on_Connected() {
	qDebug() << "Connected";
}

void Socket::on_Disconnected() {
	qDebug() << "Disconnected";
}
