#include "app.h"
/*******************************************************************************************/
using namespace EngineV1Namespace;



App::App()
{
	load();
	init();
	while(!mEnd)
	{
		mCurrentTime = SDL_GetTicks();
	
		if(mCurrentTime - mPastTimeCounter >= 100)
		{
			run_keys();
			run();
			render();
			mPastTimeCounter = mCurrentTime;
		}	



		SDL_Delay(2);
	}
	quit();

}

/*******************************************************************************************/
void App::load()
{
	mEnd = false;
	mCurrentTime = SDL_GetTicks();
	mPastTimeCounter = SDL_GetTicks();
	
	//Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return;  
    }

	mEngine.mScreen = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE ); //Ustaw wymiary okna
	
	SDL_WM_SetCaption( "ImageConverter", NULL ); //Ustaw tytul

	SDL_EnableKeyRepeat(5,SDL_DEFAULT_REPEAT_DELAY/4);


	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 0, 0, 8000, 1024, TRUE);

	freopen("CON", "w", stdout); // redirects stdout
	freopen("CON", "w", stderr); // redirects stderr

	printf("\n[App] Function LOAD - APP started\n");

	// add modules

	mModules.push_back(new FontRendering("FontRendering"));
	mModules.push_back(new ImageProcessing("ImageProcessing"));


	/// load all modules
	for(int i = 0 ; i < mModules.size() ; i++)
	{
		mModules.at(i)->set_engine(&mEngine);
		mModules.at(i)->load();
		///printf("%s\n",typeid(mModules.at(i)).name());

	}

}

void App::init()
{
	printf("***********************************************************************\n");
	printf("[App] Function INIT - APP restarted\n");
	printf("***********************************************************************\n");
	for(int i = 0 ; i < mModules.size(); i++)
		mModules.at(i)->init();
	printf("***********************************************************************\n");

}


/*******************************************************************************************/

void App::run_keys()
{
	   while( SDL_PollEvent( &mKeyEvent ) )
        {
			if(mKeyEvent.type == SDL_KEYDOWN)
			{
				switch(mKeyEvent.key.keysym.sym)
				{

					case SDLK_ESCAPE: 
						mEnd = true;
					break;

					case SDLK_F2:
						init();
					break;
				}
			}	

			if(mKeyEvent.type == SDL_QUIT)
			{
				exit(0);
			}
			

	   }
		
}

/*******************************************************************************************/

void App::run()
{


}

/*******************************************************************************************/

void App::render()
{
	// rysuj biale tlo
	SDL_FillRect(mEngine.mScreen, &mEngine.mScreen->clip_rect, SDL_MapRGB( mEngine.mScreen->format, 0xFF, 0xFF, 0xFF ) );




	// render all modules
	for(int i = 0 ; i < mModules.size() ; i++)
	{
		mModules.at(i)->render();
	}

	

	

	//Aktualizuj obraz
    SDL_Flip( mEngine.mScreen );
}

/*******************************************************************************************/

void App::quit()
{
	//Posprzataj

    //Wyjdz z SDL
    SDL_Quit();
}

/*******************************************************************************************/

App::~App()
{
	quit();
}



