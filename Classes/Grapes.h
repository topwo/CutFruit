#ifndef __GRAPES_H__
#define __GRAPES_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Grapes : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Grapes* grapesWithWorld(b2World* world);
};


#endif