/*
	File   : main.cpp
	Author : hubenchang0515@outlook.com
	Blog   : www.kurukurumi.com
*/

#include <QApplication>
#include <SDL2Widget.h>
#include <QLayout>
#include <QPushButton>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QVBoxLayout* layout = new QVBoxLayout;
	SDL2Widget* sdlWidget = new SDL2Widget;
	QPushButton* button = new QPushButton("Button");
	layout->addWidget(sdlWidget);
	layout->addWidget(button);
	QWidget w;
	w.setLayout(layout);
	w.show();
	w.resize(640,400);
	QObject::connect(button,&QPushButton::clicked,
	    sdlWidget,(void(SDL2Widget::*)(void))&SDL2Widget::repaint);
	return app.exec();
}
