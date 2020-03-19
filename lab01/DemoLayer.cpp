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

	//�������棨��Դ�أ���������  ������������һ����
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("tex.png");

	//������������Ⱦ��ʽ�ľ���ڵ�
	CCSpriteBatchNode *mgr = CCSpriteBatchNode::createWithTexture(texture);
	//��ӵ�����
	this->addChild(mgr);


	//��x��
	CCSprite *sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));  //���þ����ê���ڣ�0,0��
	sp->setPosition(origin);       //�����������Ļ����
	sp->setScaleX(300 / 2);        //���þ���x���������ϵ��
	mgr->addChild(sp);

	//��y�� 
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(300 / 2);
	sp->setRotation(-90); //��ʱ����ת90��
	mgr->addChild(sp);


	CCPoint v1 = ccp(13, 73);
	CCPoint v2 = ccp(124, 124);
	
	//������v1����ɫ
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));//���þ����ê���ڣ�0,0��
	sp->setPosition(origin);//�����������Ļ����
	sp->setScaleX(v1.getLength() / 2);//ͨ���õ�����v1�ĳ�����������ϵ��
	sp->setRotation(-(v1.getAngle() / 3.1415 * 180));//���Ȼ�
	sp->setColor(ccc3(255, 0, 0));//����Ϊ��ɫ
	mgr->addChild(sp);

	
	//������v2����ɫ
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v2.getLength() / 2);
	sp->setRotation(-(v2.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(0, 255, 0));//����Ϊ��ɫ
	mgr->addChild(sp);


	//������v3 v3 �� v1 �� v2����ɫ
	CCPoint v3 = ccpAdd(v1, v2);//�����ļ�
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v3.getLength() / 2);
	sp->setRotation(-(v3.getAngle() / 3.1415 * 180)); //������
	sp->setColor(ccc3(255, 255, 0));
	mgr->addChild(sp);

	//������v4 v4 �� v1 �� v2����ɫ
	CCPoint v4 = ccpSub(v1, v2);//��
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v4.getLength() / 2);
	sp->setRotation(-(v4.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(255, 127, 80));
	mgr->addChild(sp);

	//������v5 v5 �� v1 �� ��3����ɫ
	CCPoint v5 = ccpMult(v1, -3);//��
	sp = CCSprite::createWithTexture(texture, CCRectMake(0, 0, 2, 2));
	sp->setAnchorPoint(ccp(0, 0));
	sp->setPosition(origin);
	sp->setScaleX(v5.getLength() / 2);
	sp->setRotation(-(v5.getAngle() / 3.1415 * 180));
	sp->setColor(ccc3(0, 0, 255));
	mgr->addChild(sp);
}