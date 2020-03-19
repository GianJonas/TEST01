#include "DemoLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* CDemoLayer::createScene()
{
	return CDemoLayer::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool CDemoLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CDemoLayer::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	DrawVector();

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	/*
	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}*/
	return true;
}


void CDemoLayer::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void CDemoLayer::DrawVector()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = ccp(size.width / 2, size.height / 2);

	//用纹理缓存（资源池）加载纹理  这里的纹理就是一个点
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("tex.png");

	//创建批处理渲染方式的精灵节点
	CCSpriteBatchNode *mgr = CCSpriteBatchNode::createWithTexture(texture);
	//添加到层中
	this->addChild(mgr);


	//画x轴
	CCSprite *sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));  //设置精灵的锚点在（0,0）
	sp->setPosition(origin);       //将精灵放在屏幕中心
	sp->setScaleX(300 / 2);        //设置精灵x方向的缩放系数
	mgr->addChild(sp);

	//画y轴 
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(300 / 2);
	sp->setRotation(-90); //逆时针旋转90度
	mgr->addChild(sp);


	CCPoint v1 = ccp(13, 73);
	CCPoint v2 = ccp(124, 124);
	
	//画向量v1，红色
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));//设置精灵的锚点在（0,0）
	sp->setPosition(origin);//将精灵放在屏幕中心
	sp->setScaleX(v1.getLength() / 2);//通过得到向量v1的长度设置缩放系数
	sp->setRotation(-(v1.getAngle() / 3.1415 * 180));//弧度化
	sp->setColor(ccc3(255, 0, 0));//设置为红色
	mgr->addChild(sp);

	
	//画向量v2，绿色
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v2.getLength() / 2);
	sp->setRotation(-(v2.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(0, 255, 0));//设置为绿色
	mgr->addChild(sp);


	//画向量v3 v3 ＝ v1 ＋ v2，黄色
	CCPoint v3 = ccpAdd(v1, v2);//向量的加
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v3.getLength() / 2);
	sp->setRotation(-(v3.getAngle() / 3.1415 * 180)); //弧化度
	sp->setColor(ccc3(255, 255, 0));
	mgr->addChild(sp);

	//画向量v4 v4 ＝ v1 － v2，橘色
	CCPoint v4 = ccpSub(v1, v2);//减
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v4.getLength() / 2);
	sp->setRotation(-(v4.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(255, 127, 80));
	mgr->addChild(sp);

	//画向量v5 v5 ＝ v1 ＊ －3，蓝色
	CCPoint v5 = ccpMult(v1, -3);//积
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v5.getLength() / 2);
	sp->setRotation(-(v5.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(0, 0, 255));
	mgr->addChild(sp);
}