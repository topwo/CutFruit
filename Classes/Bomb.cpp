#include "Bomb.h"

using namespace cocos2d;

bool Bomb::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 8;
		char* file = "bomb.png";
		b2Vec2 vertices[] = {
			b2Vec2(43.0/PTM_RATIO,54.0/PTM_RATIO),
			b2Vec2(23.0/PTM_RATIO,54.0/PTM_RATIO),
			b2Vec2(12.0/PTM_RATIO,41.0/PTM_RATIO),
			b2Vec2(12.0/PTM_RATIO,20.0/PTM_RATIO),
			b2Vec2(23.0/PTM_RATIO,10.0/PTM_RATIO),
			b2Vec2(44.0/PTM_RATIO,10.0/PTM_RATIO),
			b2Vec2(53.0/PTM_RATIO,18.0/PTM_RATIO),
			b2Vec2(53.0/PTM_RATIO,40.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
			count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypeBomb);
		this->setSplurt(CCParticleSystemQuad::create("explosion.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Bomb* Bomb::bombWithWorld(b2World* world){
	Bomb* bb = new Bomb;
	if(bb && bb->initWithWorld(world)){
		bb->autorelease();
		return bb;
	}

	CC_SAFE_DELETE(bb);
	return NULL;
}
