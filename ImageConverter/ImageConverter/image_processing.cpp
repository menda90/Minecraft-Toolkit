#include "image_procesing.h"


ImageProcessing::ImageProcessing(std::string _name) : Module(_name){}

void ImageProcessing::load()
{
	Module::load();
	mImage = load_texture("Data/image.bmp");
}

void ImageProcessing::render()
{
	apply_surface(0,0, mImage, mEngine->mScreen);

}