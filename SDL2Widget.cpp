/*
	File   : SDL2Widget.cpp
	Author : hubenchang0515@outlook.com
	Blog   : www.kurukurumi.com
*/

#include <SDL2Widget.h>

SDL2Widget::SDL2Widget(QWidget* parent):QWidget(parent)
{
	/* SDL2初始化 */
	SDL_Init(SDL_INIT_EVERYTHING);
	/* 把QWidget转换为SDL_Window */
	window = SDL_CreateWindowFrom((void*)this->winId());
	/* SDL2 Image初始化 */
	IMG_Init(IMG_INIT_PNG);
	/* 加载图片，创建surface */
	surface = IMG_Load("demo.jpg");
}

SDL2Widget::~SDL2Widget()
{

}

/* 绘图操作必须在paintEvent事件里进行 */
void SDL2Widget::paintEvent(QPaintEvent* event)
{
	/* 在window上创建一个render */
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
						| SDL_RENDERER_PRESENTVSYNC);
	/* 创建一个texture */
	texture = SDL_CreateTextureFromSurface(render, surface);
	/* 清空render的内容 */
	SDL_RenderClear(render);
	/* 将texture复制到render上 */
	SDL_RenderCopy(render, texture, NULL, NULL);
	/* 将render显示到window上 */
	SDL_RenderPresent(render);
	SDL_RenderPresent(render); //我的电脑上，需要调用两次才能显示出来，原因不明
	/* 销毁render和texture，释放内存 */
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);

}