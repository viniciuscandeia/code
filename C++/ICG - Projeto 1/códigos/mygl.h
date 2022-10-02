#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

class Pixel
{

private:
    int posX, posY;
    int corR, corG, corB, corA;

public:
    void definirCor(int _corR, int _corG, int _corB, int _corA);

    void definirPos(int _posX, int _posY);

    Pixel interLinear(Pixel pixelI, Pixel pixelF, Pixel pixel);

    void setPosX(int _posX);
    int getPosX();

    void setPosY(int _posY);
    int getPosY();

    void setCorR(int _corR);
    int getCorR();

    void setCorG(int _corG);
    int getCorG();

    void setCorB(int _corB);
    int getCorB();

    void setCorA(int _corA);
    int getCorA();
};

double corReta(Pixel pixelI, Pixel pixelF, Pixel pixel);
void PutPixel(Pixel pixel);
void DrawLine(Pixel pixelF, Pixel pixelI);
void DrawTriangle(Pixel pixel1, Pixel pixel2, Pixel pixel3);


#endif // _MYGL_H_
