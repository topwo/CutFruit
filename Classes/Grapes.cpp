#include "Grapes.h"


using namespace cocos2d;

bool Grapes::initWithWorld(b2World* world){
	bool bRet = false;
	do 
	{
		int32 count = 8;
		char *file = "grapes.png";
		b2Vec2 vertices[] = {
			b2Vec2(14.0/PTM_RATIO,61.0/PTM_RATIO),
			b2Vec2(13.0/PTM_RATIO,39.0/PTM_RATIO),
			b2Vec2(18.0/PTM_RATIO,16.0/PTM_RATIO),
			b2Vec2(30.0/PTM_RATIO,3.0/PTM_RATIO),
			b2Vec2(39.0/PTM_RATIO,3.0/PTM_RATIO),
			b2Vec2(50.0/PTM_RATIO,29.0/PTM_RATIO),
			b2Vec2(54.0/PTM_RATIO,50.0/PTM_RATIO),
			b2Vec2(42.0/PTM_RATIO,62.0/PTM_RATIO)
		};

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		b2Body* body = createBodyForWorld(world, b2Vec2(winSize.width/2/PTM_RATIO,winSize.height/2/PTM_RATIO), 0.0f, vertices,
			count, 5.0f, 0.2f, 0.2f);

		CC_BREAK_IF(!initWithFileBodyOriginal(file, body, true));

		this->setType(kTypeGrapes);
		this->setSplurt(CCParticleSystemQuad::create("grapes_splurt.plist"));
		this->getSplurt()->stopSystem();

		bRet = true;
	} while (0);

	return bRet;
}

Grapes* Grapes::grapesWithWorld(b2World* world){
	Grapes* g = new Grapes;
	if(g && g->initWithWorld(world)){
		g->autorelease();
		return g;
	}
	CC_SAFE_DELETE(g);
	return NULL;
}