#ifndef __BANANA_H__
#define __BANANA_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Banana : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Banana* bananaWithWorld(b2World* world);
};

#endif