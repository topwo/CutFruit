#ifndef CutCutCut_RaycastCallback_h
#define CutCutCut_RaycastCallback_h

#include "Box2D/Box2D.h"
#include "PolygonSprite.h"
#include "cocos2d.h"
#include "platform/platform.h"

#define collinear(x1,y1,x2,y2,x3,y3) fabsf((y1-y2) * (x1-x3) - (y1-y3) * (x1-x2))

class RaycastCallback : public b2RayCastCallback {
public:
	long millisecondNow(){
		cocos2d::cc_timeval now;
		cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL);
		return (now.tv_sec * 1000 + now.tv_usec / 1000);
	}

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction){
		if(!fixture->GetBody()->GetUserData())
			return 1;
		PolygonSprite* ps = (PolygonSprite*)fixture->GetBody()->GetUserData();
		if(!ps->getSliceEntered()){
			ps->setSliceEntered(true);

			ps->setEntryPoint(ps->getBody()->GetLocalPoint(point));
			
			ps->setSliceEntryTime((double)millisecondNow() + 1000);

			
		}else if(!ps->getSliceExited()){
			ps->setExitPoint(ps->getBody()->GetLocalPoint(point));
			
			b2Vec2 entrySide = ps->getEntryPoint() - ps->getCentroid();
			b2Vec2 exitSide = ps->getExitPoint() - ps->getCentroid();

			if(entrySide.x * exitSide.x < 0 || entrySide.y * exitSide.y < 0){
				ps->setSliceExited(true);
			}else{
				b2Fixture* fixture = ps->getBody()->GetFixtureList();
				b2PolygonShape* polygon = (b2PolygonShape*)fixture->GetShape();
				int count = polygon->GetVertexCount();

				bool onSameLine = false;
				for(int i = 0; i < count; i++){
					b2Vec2 pointA = polygon->GetVertex(i);
					b2Vec2 pointB;
					if(i == count - 1){
						pointB = polygon->GetVertex(0);
					}else{
						pointB = polygon->GetVertex(i + 1);
					}

					float collinear1 = collinear(pointA.x,pointA.y, ps->getEntryPoint().x, ps->getEntryPoint().y, pointB.x,pointB.y);

					if (collinear1 <= 0.00001f)
					{
						float collinear2 = collinear(pointA.x,pointA.y,ps->getExitPoint().x,ps->getExitPoint().y,pointB.x,pointB.y);
						if (collinear2 <= 0.00001f)
						{
							onSameLine = true;
						}
						break;
					}

				}
				if(onSameLine){
					ps->setEntryPoint(ps->getExitPoint());
					ps->setSliceEntryTime((double)millisecondNow() + 1000);
					ps->setSliceExited(false);
				}else{
					ps->setSliceExited(true);
				}
			}
			
		}

		return 1;
	}

};


#endif