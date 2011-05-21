#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL/SDL.h>

#include "ui/RenderArea.h"
#include "EventListener.h"

class Application : public EventListener
{
public:
    Application();

	 void run();

	 void onEvent(SDL_Event event);

private:
	 RenderArea *ra;
	 bool running;
};

#endif // APPLICATION_H
