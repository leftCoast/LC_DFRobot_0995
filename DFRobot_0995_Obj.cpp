#include "DFRobot_0995_Obj.h"

float		percBlack = 0;  
colorObj	gColor; 


colorObj* sDim(colorObj* inColor) {

	//return inColor;							// Debug. Keeps display on.
	if (percBlack<=0) return inColor;
	if (percBlack>=100) return &black;
	gColor.setColor(inColor);
	gColor.blend(&black,percBlack);
	return &gColor;
}
	
  
DFRobot_0995_Obj::DFRobot_0995_Obj(byte inCS,byte inRST)
  :displayObj(true,true,false,false,false) {

  theTFT = NULL;
  cs = inCS;
  rst = inRST;
}

DFRobot_0995_Obj::~DFRobot_0995_Obj(void) {

    if (theTFT) { 
      delete theTFT;
      theTFT = NULL;
    }
  }

  
bool DFRobot_0995_Obj::begin(void) { 

  theTFT = new Adafruit_ST7789(cs,LC_DC,rst);
  if (theTFT!=NULL) {
    theTFT->init(TFT_WIDTH, TFT_HEIGHT);
    return true;
  }
  return false;
}


int	DFRobot_0995_Obj::width(void)																							{ return theTFT->width(); }
int	DFRobot_0995_Obj::height(void)																						{ return theTFT->height(); }
void	DFRobot_0995_Obj::setRotation(byte inRotation)																	{ theTFT->setRotation(inRotation); }
void	DFRobot_0995_Obj::setTextColor(colorObj* inColor)																{ theTFT->setTextColor(sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::setTextColor(colorObj* tColor,colorObj* bColor)											{ theTFT->setTextColor(sDim(tColor)->getColor16(),sDim(bColor)->getColor16()); }
void	DFRobot_0995_Obj::setTextSize(byte inSize)																		{ theTFT->setTextSize(inSize); }
void	DFRobot_0995_Obj::setTextWrap(boolean wrap)																		{ theTFT->setTextWrap(wrap); }

rect	DFRobot_0995_Obj::getTextRect(const char* inText) {

	rect bounds(0,0,0,0);
	int16_t	bX;
	int16_t	bY;
	uint16_t	bW;
	uint16_t	bH;
	
	bX = 0;
	bY = 0;
	bW = 0;
	bH = 0;
	theTFT->getTextBounds(inText,getCursorX(),getCursorY(),&bX,&bY,&bW,&bH);
	bounds.setRect(bX,bY,bW,bH);
	return bounds;
}

void	DFRobot_0995_Obj::setFont(const GFXfont* font)																	{ theTFT->setFont(font); }
void	DFRobot_0995_Obj::setCursor(int x,int y)																			{ theTFT->setCursor(gX(x),gY(y));  }
int	DFRobot_0995_Obj::getCursorX(void)																					{ return lX(theTFT->getCursorX()); }
int	DFRobot_0995_Obj::getCursorY(void)																					{ return lY(theTFT->getCursorY()); }
void	DFRobot_0995_Obj::drawText(const char* inText)																	{ theTFT->print(inText); }
void	DFRobot_0995_Obj::fillScreen(colorObj* inColor)																	{ theTFT->fillScreen(sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::fillRect(int x,int y,int width,int height,colorObj* inColor)						{ theTFT->fillRect(gX(x),gY(y), width, height,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawRect(int x,int y,int width,int height,colorObj* inColor)						{ theTFT->drawRect(gX(x),gY(y), width, height,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::fillRect(rect* inRect,colorObj* inColor)													{ theTFT->fillRect(gX(inRect->x),gY(inRect->y), inRect->width, inRect->height,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawRect(rect* inRect,colorObj* inColor)													{ theTFT->drawRect(gX(inRect->x),gY(inRect->y), inRect->width, inRect->height,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::fillRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theTFT->fillRoundRect(gX(x),gY(y),width,height,radius,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theTFT->drawRoundRect(gX(x),gY(y),width,height,radius,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawCircle(int x,int y,int diam, colorObj* inColor)									{ drawRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void	DFRobot_0995_Obj::drawCircleHelper(int x,int y,int rad,byte corner,colorObj* inColor)				{ theTFT->drawCircleHelper(gX(x),gY(y),rad,corner,inColor->getColor16()); }
void	DFRobot_0995_Obj::fillCircle(int x,int y,int diam, colorObj* inColor)									{ fillRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void	DFRobot_0995_Obj::drawTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor) 					{ theTFT->drawTriangle(gX(pt0->x),gX(pt0->y),gX(pt1->x),gX(pt1->y),gX(pt2->x),gX(pt2->y),inColor->getColor16()); }
void	DFRobot_0995_Obj::fillTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor)					{ theTFT->fillTriangle(gX(pt0->x),gX(pt0->y),gX(pt1->x),gX(pt1->y),gX(pt2->x),gX(pt2->y),inColor->getColor16()); }
void	DFRobot_0995_Obj::drawVLine(int x,int y,int height,colorObj* inColor)									{ theTFT->drawFastVLine(gX(x),gY(y),height,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawHLine(int x,int y,int width,colorObj* inColor)										{ theTFT->drawFastHLine(gX(x),gY(y),width,sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawLine(int x,int y,int x2,int y2,colorObj* inColor)									{ theTFT->drawLine(gX(x),gY(y),gX(x2),gY(y2),sDim(inColor)->getColor16()); }
void	DFRobot_0995_Obj::drawPixel(int x,int y,colorObj* inColor)													{ theTFT->drawPixel(gX(x),gY(y),sDim(inColor)->getColor16()); }







 
