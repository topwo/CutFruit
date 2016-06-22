#ifndef __PINEAPPLE_H__
#define __PINEAPPLE_H__


#include "cocos2d.h"
#include "PolygonSprite.h"

class Pineapple : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Pineapple* appleWithWorld(b2World* world);
};

#endif