#include "Watermelon.h"

using namespace cocos2d;

bool Watermelon::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 7;
		char* file = "watermelon.png";
		b2Vec2 vertices[] = {
			b2Vec2(5.0/PTM_RATIO,15.0/PTM_RATIO),
			b2Vec2(18.0/PTM_RATIO,7.0/PTM_RATIO),
			b2Vec2(32.0/PTM_RATIO,5.0/PTM_RATIO),
			b2Vec2(48.0/PTM_RATIO,7.0/PTM_RATIO),
			b2Vec2(60.0/PTM_RATIO,14.0/PTM_RATIO),
			b2Vec2(34.0/PTM_RATIO,59.0/PTM_RATIO),
			b2Vec2(28.0/PTM_RATIO,59.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
					count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypeWatermelon);
		this->setSplurt(CCParticleSystemQuad::create("watermelon_splurt.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Watermelon* Watermelon::wmWithWorld(b2World* world){
	Watermelon* wm = new Watermelon;
	if(wm && wm->initWithWorld(world)){
		wm->autorelease();
		return wm;
	}
	CC_SAFE_DELETE(wm);
	return NULL;
}