#ifndef _CLASS_ENGINE_V1_
#define _CLASS_ENGINE_V1_

#include <windows.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_draw.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <typeinfo>


namespace EngineV1Namespace
{
	class EngineV1 
	{
		public: 
		SDL_Surface* mScreen;
	};


	// naklada teksture na teksture
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

	// Wczytaj teksture
	SDL_Surface* load_texture(std::string name);




}

#endif