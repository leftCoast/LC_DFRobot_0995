
#ifndef DFRobot_0995_Obj_h
#define DFRobot_0995_Obj_h

#include "displayObj.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <LC_SPI.h>


#define TFT_WIDTH		172	//< The width of the display
#define TFT_HEIGHT	320	//< The height of the display

#define PORTRAIT      0  	// Wires up
#define LANDSCAPE     1  	// Wires left
#define INV_PORTRAIT  2  	// Wires down
#define INV_LANDSCAPE 3  	// Wires right


extern float	percBlack;


class DFRobot_0995_Obj : public displayObj {

  public :
  				DFRobot_0995_Obj(byte inCS,byte inRST);
  virtual	~DFRobot_0995_Obj(void);
  
	virtual	int	width(void);
	virtual	int	height(void);
	virtual 	bool	begin(void);
	virtual 	void	setRotation(byte inRotation);
	virtual 	void	setTextColor(colorObj* tColor);
	virtual 	void	setTextColor(colorObj* tColor,colorObj* bColor);
	virtual 	void	setTextSize(byte inSize);
	virtual 	void	setTextWrap(boolean wrap);
	virtual	rect	getTextRect(const char* inText);
	virtual 	void	setFont(const GFXfont* font);
	virtual 	void	setCursor(int x,int y);
	virtual	int	getCursorX(void);
	virtual	int	getCursorY(void);
	virtual 	void	drawText(const char* inText);
	virtual 	void	fillScreen(colorObj* inColor);
	virtual 	void	fillRect(int x,int y,int width,int height,colorObj* inColor);
	virtual 	void	drawRect(int x,int y,int width,int height,colorObj* inColor);
	virtual 	void	fillRect(rect* inRect,colorObj* inColor);
	virtual 	void	drawRect(rect* inRect,colorObj* inColor);
	virtual 	void	fillRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor);
	virtual 	void	drawRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor);
	virtual 	void	drawCircle(int x,int y,int diam, colorObj* inColor);
	virtual	void	drawCircleHelper(int x,int y,int rad,byte corner,colorObj* inColor);
	virtual 	void	fillCircle(int x,int y,int diam, colorObj* inColor);
	virtual	void	drawTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor);
	virtual	void	fillTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor);
	virtual 	void	drawVLine(int x,int y,int height,colorObj* inColor);
	virtual 	void	drawHLine(int x,int y,int width,colorObj* inColor);
	virtual 	void	drawLine(int x,int y,int x2,int y2,colorObj* inColor);
	virtual 	void	drawPixel(int x,int y,colorObj* inColor);
	
	
  private:
          Adafruit_ST7789*		theTFT;
          byte              	cs;
          byte              	rst;
};
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

#endif