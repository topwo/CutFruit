#ifndef __BOMB_H__
#define __BOMB_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Bomb : public PolygonSprite {
public:
	bool initWithWorld(b2World* world);

	static Bomb* bombWithWorld(b2World* world);
};

#endif