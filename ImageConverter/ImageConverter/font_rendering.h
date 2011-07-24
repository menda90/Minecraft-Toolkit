#ifndef _MODULE_FONT_
#define _MODULE_FONT_

#include "engine.h"
#include "module.h"
using namespace EngineV1Namespace;


///@class FontRendering
/// Odpowiedzialna za renderowanie bzdetnych inforamcji na ekranie
class FontRendering : public Module
{
public:

	FontRendering(std::string _name);


	virtual void load();

	virtual void render();

};

#endif