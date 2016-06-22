#include "Banana.h"


using namespace cocos2d;

bool Banana::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 8;
		char* file = "banana.png";
		b2Vec2 vertices[] = {
			b2Vec2(5.0/PTM_RATIO,10.0/PTM_RATIO),
			b2Vec2(16.0/PTM_RATIO,6.0/PTM_RATIO),
			b2Vec2(32.0/PTM_RATIO,6.0/PTM_RATIO),
			b2Vec2(49.0/PTM_RATIO,13.0/PTM_RATIO),
			b2Vec2(61.0/PTM_RATIO,33.0/PTM_RATIO),
			b2Vec2(54.0/PTM_RATIO,59.0/PTM_RATIO),
			b2Vec2(48.0/PTM_RATIO,59.0/PTM_RATIO),
			b2Vec2(5.0/PTM_RATIO,20.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
			count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypeBanana);
		this->setSplurt(CCParticleSystemQuad::create("banana_splurt.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Banana* Banana::bananaWithWorld(b2World* world){
	Banana* ba = new Banana;
	if(ba && ba->initWithWorld(world)){
		ba->autorelease();
		return ba;
	}
	CC_SAFE_DELETE(ba);
	return NULL;
}