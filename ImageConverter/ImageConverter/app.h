#ifndef _CLASS_APP_
#define _CLASS_APP_

/// @file

#include "engine.h"
#include "image_procesing.h"

///@class App
///@brief Glowna klasa, ktora tworzy okno aplikacji

class App
{
	public:
	App();
	~App();


	void load(); // ladowane na starcie

	void init(); // tzw. reset - new game - etc...

	void render(); // Renderuj grafike

	void run(); // Funkcja obsluguje mechanike gry

	void run_keys(); // Funkcja do obslugi klawiszy

	
	void quit(); // Wyjdz z aplikacji
	
	SDL_Surface *mScreen;

	EngineV1 mEngine;

	private:


		bool mEnd; // koniec app

		int mCurrentTime; /// Czas aktualny

		int mPastTimeCounter; /// Czas od ostatniego sprawdzenia czasu

		SDL_Event mKeyEvent; /// Zdarzenie
		

		std::vector<Module*> mModules;


		



};

#endif