#include "image_procesing.h"


ImageProcessing::ImageProcessing(std::string _name) : Module(_name){}

void ImageProcessing::load()
{
	Module::load();
	mImage = NULL;
	
}


void ImageProcessing::render()
{
	apply_surface(0,0, mImage, mEngine->mScreen);

}

void ImageProcessing::init()
{
	Module::init();

	if(mImage!=NULL)
	{
		SDL_FreeSurface(mImage);
	}

	mImage = load_texture("Data/image.bmp");

	bpp = mImage->format->BytesPerPixel;
	maxIndex = (mImage->w * mImage->h * bpp) - bpp;    
	pixels = (unsigned char*)(mImage->pixels);



	printf("[Module %s] BytesPerPixel: %d\n", mName.c_str(), bpp);
	printf("[Module %s] maxIndex: %d\n", mName.c_str(), maxIndex);

	unsigned int temp = 0;

	for(unsigned i = 0 ; i < maxIndex ; i+=bpp)
	{
		memcpy(&temp, &pixels[i], bpp);
		temp+= 16777216;
		printf("[Module %s] int at position %d is %d\n", mName.c_str(), i/bpp, temp);
	}
}