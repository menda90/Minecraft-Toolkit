#ifndef _MODULE_IMAGEPROCESSING_
#define _MODULE_IMAGEPROCESSING_

#include "engine.h"
#include "module.h"
using namespace EngineV1Namespace;

/// Klasa odpowiedzialna za przetwarzanie obrazka - obrobki na naszego minecraftowego screena !
class ImageProcessing : public Module
{
public:

	ImageProcessing(std::string _name);


	virtual void load();

	virtual void render();

	void run(){}; // do uzupelnienia

	SDL_Surface *mImage;

	unsigned int bpp;
	unsigned int maxIndex;
	unsigned char* pixels;


};

#endif