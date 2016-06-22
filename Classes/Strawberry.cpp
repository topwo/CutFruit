#include "Strawberry.h"

using namespace cocos2d;

bool Strawberry::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 7;
		char* file = "strawberry.png";
		b2Vec2 vertices[] = {
			b2Vec2(51.0/PTM_RATIO,5.0/PTM_RATIO),
			b2Vec2(56.0/PTM_RATIO,21.0/PTM_RATIO),
			b2Vec2(54.0/PTM_RATIO,45.0/PTM_RATIO),
			b2Vec2(37.0/PTM_RATIO,62.0/PTM_RATIO),
			b2Vec2(8.0/PTM_RATIO,48.0/PTM_RATIO),
			b2Vec2(12.0/PTM_RATIO,24.0/PTM_RATIO),
			b2Vec2(34.0/PTM_RATIO,5.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
			count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypeStrawberry);
		this->setSplurt(CCParticleSystemQuad::create("strawberry_splurt.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Strawberry* Strawberry::strawberryWithWorld(b2World* world){
	Strawberry* sb = new Strawberry;
	if(sb && sb->initWithWorld(world)){
		sb->autorelease();
		return sb;
	}
	CC_SAFE_DELETE(sb);
	return NULL;
}