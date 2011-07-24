#ifndef _CLASS_MODULE_
#define _CLASS_MODULE_

#include "engine.h"

using namespace EngineV1Namespace;

class Module
{
public:
	
	Module(std::string _name = "unknown") : mName(_name){}


	virtual void load()
	{
		printf("\nModule %s loaded\n", mName.c_str());

	}

	void set_engine(EngineV1* _engine)
	{
		mEngine = _engine;
	}


	virtual void init()
	{
		printf("\nModule %s initiation\n", mName.c_str());
	};

	virtual void render(){};


	std::string mName;
	EngineV1* mEngine;
};

#endif