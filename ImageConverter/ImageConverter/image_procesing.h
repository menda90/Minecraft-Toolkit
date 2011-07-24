#ifndef _MODULE_IMAGEPROCESSING_
#define _MODULE_IMAGEPROCESSING_


#define MAX_HEIGHT 64

#include "engine.h"
#include "module.h"
using namespace EngineV1Namespace;

/// Klasa odpowiedzialna za przetwarzanie obrazka - obrobki na naszego minecraftowego screena !
class ImageProcessing : public Module
{
public:

	ImageProcessing(std::string _name);


	virtual void load();

	virtual void init();

	virtual void render();

	void run(){}; // do uzupelnienia

	void create_image();

	SDL_Surface *mImage;
	SDL_Surface *mResultImage;

	unsigned int bpp;
	unsigned int maxIndex;
	unsigned char* pixels;

	unsigned int** pixel_matrix;


};

#endif