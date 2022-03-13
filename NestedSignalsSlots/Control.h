#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>

class Control : public QWidget {
Q_OBJECT
public:
	explicit Control(QWidget *parent = nullptr);
	~Control() override;
	QSlider *slider;
	QLabel *label;
signals:
	void closeSignal();
private:
	QHBoxLayout *hLayout;
protected:
	void closeEvent(QCloseEvent *event) override;
};

#endif
