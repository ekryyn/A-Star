#include "RenderArea.h"

RenderArea::RenderArea(unsigned int width, unsigned int height) :
	window(0),
	width(width),
	height(height)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	drawables = new std::vector<Drawable*>();

}

void RenderArea::init()
{
	this->window = SDL_SetVideoMode(this->width,
											  this->height,
											  32,
											  SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void RenderArea::addDrawable(Drawable *drawable)
{
	drawables->push_back(drawable);
}

void RenderArea::display()
{
	Uint32 bgColor = SDL_MapRGB(window->format, 30, 30, 30);
	SDL_FillRect(window, NULL, bgColor);

	std::vector<Drawable*>::iterator it;
	for(it = drawables->begin(); it < drawables->end(); it++)
	{
		(*it)->draw(window);
	}

	SDL_Flip(window);
}

RenderArea::~RenderArea()
{
	SDL_Quit();
}
