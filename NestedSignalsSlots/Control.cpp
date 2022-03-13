#include "Control.h"

Control::Control(QWidget *parent) : QWidget(parent){
	hLayout = new QHBoxLayout;
	slider = new QSlider;
	label = new QLabel;
	
	label->setText(QString::number(slider->value()));
	slider->setOrientation(Qt::Horizontal);
	slider->setRange(0, 255);
	hLayout->addWidget(label);
	hLayout->addWidget(slider);
	
	setLayout(hLayout);
}

Control::~Control() = default;

void Control::closeEvent(QCloseEvent *event) {
	emit closeSignal();
}
