#pragma once
#include "cocos2d.h"

class CDemoLayer : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void DrawVector();

	// implement the "static create()" method manually
	CREATE_FUNC(CDemoLayer);
};