#ifndef __WATER_MELON_H__
#define __WATER_MELON_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Watermelon : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Watermelon* wmWithWorld(b2World* world);
};

#endif