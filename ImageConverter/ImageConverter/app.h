/// @file

#include "engine.h"

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
	

	private:

		bool mEnd; // koniec app

		int mCurrentTime; /// Czas aktualny

		int mPastTimeCounter; /// Czas od ostatniego sprawdzenia czasu

		SDL_Event mKeyEvent; /// Zdarzenie
		SDL_Surface * mScreen; /// NASZE OKNO



};