#include "Pineapple.h"


using namespace cocos2d;

bool Pineapple::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 7;
		char* file = "pineapple.png";
		b2Vec2 vertices[] = {
			b2Vec2(61.0/PTM_RATIO,64.0/PTM_RATIO),
			b2Vec2(39.0/PTM_RATIO,64.0/PTM_RATIO),
			b2Vec2(0.0/PTM_RATIO,23.0/PTM_RATIO),
			b2Vec2(0.0/PTM_RATIO,10.0/PTM_RATIO),
			b2Vec2(11.0/PTM_RATIO,0.0/PTM_RATIO),
			b2Vec2(29.0/PTM_RATIO,0.0/PTM_RATIO),
			b2Vec2(64.0/PTM_RATIO,39.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
			count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypePineapple);
		this->setSplurt(CCParticleSystemQuad::create("pineapple_splurt.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Pineapple* Pineapple::appleWithWorld(b2World* world){
	Pineapple* pa = new Pineapple;
	if(pa && pa->initWithWorld(world)){
		pa->autorelease();
		return pa;
	}
	CC_SAFE_DELETE(pa);
	return NULL;
}
