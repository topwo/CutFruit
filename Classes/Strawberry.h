#ifndef __STRAWBERRY_H__
#define __STRAWBERRY_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Strawberry : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Strawberry* strawberryWithWorld(b2World* world);
};

#endif