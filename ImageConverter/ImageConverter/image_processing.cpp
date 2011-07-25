#include "image_procesing.h"


ImageProcessing::ImageProcessing(std::string _name) : Module(_name){}

void ImageProcessing::load()
{
	Module::load();
	mImage = NULL;
	mResultImage = NULL;
	pixel_matrix = NULL;
	
}


void ImageProcessing::render()
{
	if(mImage!=NULL)
	apply_surface(0,0, mImage, mEngine->mScreen);

	if(mImage!=NULL && mResultImage!=NULL)
	apply_surface(mImage->w + 30,0, mResultImage, mEngine->mScreen);

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
	dy = ceil((double)mImage->h / (double)MAX_HEIGHT);


	printf("[Module %s] BytesPerPixel: %d\n", mName.c_str(), bpp);
	printf("[Module %s] maxIndex: %d\n", mName.c_str(), maxIndex);
	printf("[Module %s] DY: %d\n", mName.c_str(), dy);



	int temp = 0;
	unsigned int tempX = 0;
	unsigned int tempY = 0;

	if(pixel_matrix!=NULL)
	{
		for(int i = 0 ; i < mImage->h ; i++)
		{
			delete [] pixel_matrix[i];
		}
		delete [] pixel_matrix;
	}

	pixel_matrix = new unsigned int*[mImage->h];
	for(int i = 0 ; i < mImage->h ; i++)
	{
		pixel_matrix[i] = new unsigned int[mImage->w];
	}
	

	for(unsigned i = 0 ; i < maxIndex - bpp ; i+=bpp)
	{
		memcpy(&temp, &pixels[i], bpp);
		//temp+= 16777216;
		

		if(tempX == mImage->w)
		{
			tempX = 0;
			tempY++;
			
		}

		pixel_matrix[tempY][tempX] = temp;

		tempX++;
	
		static int counter= 0;
		counter++;
		if(counter<3)
		printf("[Module %s] int at position %d is %d\n", mName.c_str(), i/bpp, temp);
	}
	create_image();
}

void ImageProcessing::create_image()
{
	
	if(mResultImage!=NULL)
	{
		SDL_FreeSurface(mResultImage);
	}

	// rewrite image
	mResultImage = SDL_CreateRGBSurface(SDL_SWSURFACE, mImage->w, mImage->h, 32, 0,0,0,0);
	apply_surface(0,0,mImage,mResultImage);

	unsigned char* tmpPixels = (unsigned char*)(mResultImage->pixels);
	srand(time(0));

	int b = 0x00FF00;
	
	b= b -16777216;
	printf("DECIMAL: %d\n",b);
	/*
	for(int k = 0 ; k < maxIndex; k++)
	{
		int t = -1;
		tmpPixels[k] = t;

	}*/

	// obliczmy ile musimy przemielic linii
	int lines_counter = mImage->h/dy;
	
	printf("Ilosc linii : %d\n", lines_counter);
	dy = 200;
	//for(int i = 0 ; i < dy ; i++)
		//for(int j = 0 ; j < dy ; j++)
			//memcpy(&pixel_matrix[i][j], &b, bpp);
	

	// szukamy odpowiedniej welny
	int c = 0;
	int multi = 0;
	int welna = 0;
	for(int i = 0 ; i < dy ; i++)
	{
		c = 0;
		multi = mImage->w*bpp*i;
		for(int j = 0 ; j < dy ; j++)
		{
			if(welna == 0)
			memcpy(&welna, &pixel_matrix[i][j], bpp);
			c+=bpp;
		}
		
	}


	// przekopiuj macierz do tmpPixels
	c = 0;
	multi = 0;
	for(int i = 0 ; i < dy ; i++)
	{
		c = 0;
		multi = mImage->w*bpp*i;
		for(int j = 0 ; j < dy ; j++)
		{
			//memcpy(&tmpPixels[multi+c], &pixel_matrix[i][j], bpp);
			memcpy(&tmpPixels[multi+c], &welna, bpp);
			c+=bpp;
		}
		
	}


		//memcpy(&tmpPixels[line], &b, bpp);


}