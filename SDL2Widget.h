/*
	File   : SDL2Widget.h
	Author : hubenchang0515@outlook.com
	Blog   : www.kurukurumi.com
*/

#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <QWidget>
#include <QPaintEvent>

class SDL2Widget : public QWidget
{
	Q_OBJECT
public:
	SDL2Widget(QWidget* parent=0);
	~SDL2Widget();
protected:
	void paintEvent(QPaintEvent* event);
	
private:	
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Surface *surface;
	SDL_Texture *texture;
};


#endif