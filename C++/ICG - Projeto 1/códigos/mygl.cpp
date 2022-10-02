#include "definitions.h"

/**
 * Define as posições do pixel.
 *
 * @param _posX A posição X do pixel.
 * @param _posY A posição Y do pixel.
 */
void Pixel::definirPos(int _posX, int _posY)
{
    setPosX(_posX);
    setPosY(_posY);
}

/**
 * Define as cores ao pixel.
 *
 * @param _corR O valor da cor vermelha do pixel.
 * @param _corG O valor da cor verde do pixel.
 * @param _corB O valor da cor azul do pixel.
 * @param _corA O valor do canal Alpha.
 */
void Pixel::definirCor(int _corR, int _corG, int _corB, int _corA)
{
    setCorR(_corR);
    setCorG(_corG);
    setCorB(_corB);
    setCorA(_corA);
}

/**
 * Define a posição X do pixel.
 *
 * @param _posX A nova posição X do pixel.
 */
void Pixel::setPosX(int _posX)
{
    posX = _posX;
}

/**
 * Retorna o valor da posição X.
 *
 * @return O valor da posição X da variável privada.
 */
int Pixel::getPosX()
{
    return posX;
}

/**
 * Define a posição Y do pixel.
 *
 * @param _posY A nova posição Y do pixel.
 */
void Pixel::setPosY(int _posY)
{
    posY = _posY;
}

/**
 * Retorna o valor da posição Y.
 *
 * @return O valor da posição Y da variável privada.
 */
int Pixel::getPosY()
{
    return posY;
}

/**
 * Define a cor vermelha.
 *
 * @param _corR O valor da cor vermelha do pixel.
 */
void Pixel::setCorR(int _corR)
{
    corR = _corR;
}

/**
 * Retorna o valor da cor vermelha.
 *
 * @return O valor da cor vermelha da variável privada.
 */
int Pixel::getCorR()
{
    return corR;
}

/**
 * Define a cor verde.
 *
 * @param _corG O valor da cor verde do pixel.
 */
void Pixel::setCorG(int _corG)
{
    corG = _corG;
}

/**
 * Retorna o valor da cor verde.
 *
 * @return O valor da cor verde da variável privada.
 */
int Pixel::getCorG()
{
    return corG;
}

/**
 * Define a cor azul.
 *
 * @param _corB O valor da cor azul do pixel.
 */
void Pixel::setCorB(int _corB)
{
    corB = _corB;
}

/**
 * Retorna o valor da cor azul.
 *
 * @return O valor da cor azul da variável privada.
 */
int Pixel::getCorB()
{
    return corB;
}

/**
 * Define o canal alpha.
 *
 * @param _corA O valor do canal alpha do pixel.
 */
void Pixel::setCorA(int _corA)
{
    corA = _corA;
}

/**
 * Retorna o valor do canal alpha do pixel.
 *
 * @return O valor do canal alpha da variável privada.
 */
int Pixel::getCorA()
{
    return corA;
}

/**
 * Recebe um número e retorna a raiz quadrada dele.
 * 
 * @param numero O número passado.
 * 
 * @return A raiz quadrada.
 */
float raiz_quadrada(float numero)
{
    int n;
    float recorre = numero;

    for (n = 0; n < 10; ++n)
        recorre = recorre / 2 + numero / (2 * recorre);

    return (recorre);
}

/**
 * Utilizado o algoritmo de Interpolação Linear para descobrir a cor do pixel.
 * 
 * @param pixelI O primeiro pixel da linha.
 * @param pixelF O último pixel da linha.
 * @param pixel O pixel que será pintado.
 * 
 * @return o pixel pintado.
 */
Pixel Pixel::interLinear(Pixel pixelI, Pixel pixelF, Pixel pixel)
{
    double disPixelTotal = raiz_quadrada((pixelF.getPosX() - pixelI.getPosX()) * (pixelF.getPosX() - pixelI.getPosX()) + (pixelF.getPosY() - pixelI.getPosY()) * (pixelF.getPosY() - pixelI.getPosY()));
    double disPixelRelativa = raiz_quadrada((pixelF.getPosX() - pixel.getPosX()) * (pixelF.getPosX() - pixel.getPosX()) + (pixelF.getPosY() - pixel.getPosY()) * (pixelF.getPosY() - pixel.getPosY()));
    double perc = disPixelRelativa / disPixelTotal;

    pixel.setCorR((perc * pixelI.getCorR() + (1 - perc) * pixelF.getCorR()));
    pixel.setCorG((perc * pixelI.getCorG() + (1 - perc) * pixelF.getCorG()));
    pixel.setCorB((perc * pixelI.getCorB() + (1 - perc) * pixelF.getCorB()));
    pixel.setCorA((perc * pixelI.getCorA() + (1 - perc) * pixelF.getCorA()));

    return pixel;
}

/**
 * Coloca um ponto no mapa com as cores e as posições do objeto Pixel passado.
 *
 * @param pixel O objeto que será colocado no mapa.
 */
void PutPixel(Pixel pixel)
{
    int offset = 4 * pixel.getPosX() + 4 * pixel.getPosY() * IMAGE_WIDTH;
    FBptr[offset + 0] = pixel.getCorR();
    FBptr[offset + 1] = pixel.getCorG();
    FBptr[offset + 2] = pixel.getCorB();
    FBptr[offset + 3] = pixel.getCorA();
}

/**
 * Desenha uma reta entre dois pixels passados.
 *
 * Há 12 cenários que são necessários criar:
 *  1) Reta vertical para cima.
 *  2) Reta vertical para baixo.
 *  3) Reta horizontal para direita.
 *  4) Reta horizontal para esquerda.
 *  5) Reta diagonal com o ângulo entre 0° e 45°.
 *  6) Reta diagonal com o ângulo entre 45° e 90°.
 *  7) Reta diagonal com o ângulo entre 90° e 135°.
 *  8) Reta diagonal com o ângulo entre 135° e 180°.
 *  9) Reta diagonal com o ângulo entre 180° e 225°.
 *  10) Reta diagonal com o ângulo entre 225° e 270°.
 *  11) Reta diagonal com o ângulo entre 270° e 315°.
 *  12) Reta diagonal com o ângulo entre 315° e 360° (0°).
 *  13) Reta diagonal com o ângulo de 45°.
 *  14) Reta diagonal com o ângulo de 135°.
 *  15) Reta diagonal com o ângulo de 225°.
 *  16) Reta diagonal com o ângulo de 315°.
 *
 * @param pixelF O pixel final.
 * @param pixelI O pixel inicial.
 */
void DrawLine(Pixel pixelF, Pixel pixelI)
{

    Pixel pixel;
    pixel.definirPos(pixelI.getPosX(), pixelI.getPosY());
    pixel.definirCor(pixelI.getCorR(), pixelI.getCorG(), pixelI.getCorB(), pixelI.getCorA());

    PutPixel(pixel);

    // Algoritmo de Bresenham
    double deltaX = pixelF.getPosX() - pixelI.getPosX();
    double deltaY = pixelF.getPosY() - pixelI.getPosY();
    double coefAng;
    if (deltaX != 0)
        coefAng = (deltaY) / (deltaX);
    else
        coefAng = 0;

    double coefLin = pixelI.getPosY() - coefAng * pixelI.getPosX();

    double a = deltaY;
    double b = -deltaX;
    double c = deltaX * coefLin;

    int sel;
    if (deltaY > 0) // 180° - 360° (0°)
        sel = 1;
    else // 0° - 180°
        sel = -1;

    if (coefAng > 1) // Reta diagonal com o ângulo entre 270° e 315°. || Reta diagonal com o ângulo entre 90° e 135°.
    {

        int decPos = (int)(2 * deltaX - deltaY) * (sel);
        int incH = (int)(2 * deltaX) * (sel);
        int incD = (int)(2 * (deltaX - deltaY)) * (sel);

        if (sel == 1) // Reta diagonal com o ângulo entre 270° e 315°.
        {

            while (pixel.getPosX() <= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosY(pixel.getPosY() + 1);
                }
                else
                {
                    decPos += incD;

                    pixel.setPosX(pixel.getPosX() + 1);
                    pixel.setPosY(pixel.getPosY() + 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }

        else // Reta diagonal com o ângulo entre 90° e 135°.
        {

            while (pixel.getPosX() >= (int)pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosY(pixel.getPosY() - 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() - 1);
                    pixel.setPosY(pixel.getPosY() - 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }
    }

    else if (coefAng < -1) // Reta diagonal com o ângulo entre 225° e 270°. || Reta diagonal com o ângulo entre 45° e 90°.
    {

        if (deltaY < 0) // Reta diagonal com o ângulo entre 45° e 90°.
            sel = 1;
        else // Reta diagonal com o ângulo entre 225° e 270°.
            sel = -1;

        int decPos = (int)(2 * deltaX - deltaY) * (sel);
        int incH = (int)(2 * deltaX) * (sel);
        int incD = (int)(2 * (deltaX + deltaY)) * (sel);

        if (sel == -1) // Reta diagonal com o ângulo entre 225° e 270°.
        {

            while (pixel.getPosX() >= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosY(pixel.getPosY() + 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() - 1);
                    pixel.setPosY(pixel.getPosY() + 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }

        else // Reta diagonal com o ângulo entre 45° e 90°.
        {

            while (pixel.getPosX() <= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosY(pixel.getPosY() - 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() + 1);
                    pixel.setPosY(pixel.getPosY() - 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }
    }

    else if (coefAng > 0 && coefAng < 1) // Reta diagonal com o ângulo entre 315° e 360° (0°). || Reta diagonal com o ângulo entre 135° e 180°.
    {

        int decPos = (int)(2 * deltaY - deltaX) * sel;
        int incH = (int)(2 * deltaY) * sel;
        int incD = (int)(2 * (deltaY - deltaX)) * sel;

        if (sel == 1) // Reta diagonal com o ângulo entre 315° e 360° (0°).
        {

            while (pixel.getPosX() <= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosX(pixel.getPosX() + 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() + 1);
                    pixel.setPosY(pixel.getPosY() + 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }

        else // Reta diagonal com o ângulo entre 135° e 180°.
        {

            while (pixel.getPosX() >= (int)pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosX(pixel.getPosX() - 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() - 1);
                    pixel.setPosY(pixel.getPosY() - 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }
    }

    else if (coefAng > -1 && coefAng < 0) // Reta diagonal com o ângulo entre 0° e 45°. || Reta diagonal com o ângulo entre 180° e 225°.
    {

        if (deltaX > 0) // Reta diagonal com o ângulo entre 0° e 45°.
            sel = 1;
        else // Reta diagonal com o ângulo entre 180° e 225°.
            sel = -1;

        int decPos = (int)(2 * deltaY - deltaX) * sel;
        int incH = (int)(-2 * deltaY) * sel;
        int incD = (int)(-2 * (deltaY + deltaX)) * sel;

        if (sel == 1) // Reta diagonal com o ângulo entre 0° e 45°.
        {

            while (pixel.getPosX() <= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosX(pixel.getPosX() + 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() + 1);
                    pixel.setPosY(pixel.getPosY() - 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }

        else // Reta diagonal com o ângulo entre 180° e 225°.
        {

            while (pixel.getPosX() >= pixelF.getPosX())
            {

                if (decPos <= 0)
                {
                    decPos += incH;
                    pixel.setPosX(pixel.getPosX() - 1);
                }
                else
                {
                    decPos += incD;
                    pixel.setPosX(pixel.getPosX() - 1);
                    pixel.setPosY(pixel.getPosY() + 1);
                }

                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }
    }

    else if (deltaX == 0) // Reta vertical para cima. || Reta vertical para baixo.
    {
        while (pixel.getPosY() != pixelF.getPosY())
        {
            pixel.setPosY(pixel.getPosY() + sel);
            pixel = pixel.interLinear(pixelI, pixelF, pixel);
            PutPixel(pixel);
        }
    }

    else if (deltaY == 0) // Reta horizontal para direita. || Reta horizontal para esquerda.
    {
        if (deltaX > 0)
            sel = 1;
        else
            sel = -1;

        while (pixel.getPosX() != pixelF.getPosX())
        {
            pixel.setPosX(pixel.getPosX() + sel);
            pixel = pixel.interLinear(pixelI, pixelF, pixel);
            PutPixel(pixel);
        }
    }

    else // Reta diagonal com o ângulo múltiplo de 45°.
    {

        if (coefAng == 1) // Reta diagonal com o ângulo de 45°. || Reta diagonal com o ângulo de 225°.
        {
            while (pixel.getPosX() != pixelF.getPosX())
            {
                pixel.setPosX(pixel.getPosX() + sel);
                pixel.setPosY(pixel.getPosY() + sel);
                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }

        else // Reta diagonal com o ângulo de 135°. || Reta diagonal com o ângulo de 315°.
        {
            while (pixel.getPosX() != pixelF.getPosX())
            {
                pixel.setPosX(pixel.getPosX() - sel);
                pixel.setPosY(pixel.getPosY() - sel);
                pixel = pixel.interLinear(pixelI, pixelF, pixel);
                PutPixel(pixel);
            }
        }
    }

    PutPixel(pixelF);
}

/**
 * Desenha um triângulo.
 *
 * @param pixel1 O primeiro vértice do triângulo.
 * @param pixel2 O segundo vértice do triângulo.
 * @param pixel3 O terceiro vértice do triângulo.
 */
void DrawTriangle(Pixel pixel1, Pixel pixel2, Pixel pixel3)
{
    DrawLine(pixel2, pixel1);
    DrawLine(pixel3, pixel2);
    DrawLine(pixel1, pixel3);
}

void MyGlDraw(void)
{

    Pixel pixel1, pixel2, pixel3, pixel4, pixel5, pixel6;

    pixel1.definirCor(0, 255, 255, 255);
    pixel1.definirPos(256, 256);

    pixel2.definirCor(255, 0, 255, 255);
    pixel2.definirPos(322, 222);

    pixel3.definirCor(255, 255, 255, 255);
    pixel3.definirPos(456, 226);

    pixel4.definirCor(255, 0, 0, 255);
    pixel4.definirPos(400, 290);

    pixel5.definirCor(0, 0, 255, 255);
    pixel5.definirPos(226, 476);

    pixel6.definirCor(50, 64, 12, 255);
    pixel6.definirPos(226, 76);

    DrawTriangle(pixel1, pixel5, pixel2);
    DrawTriangle(pixel3, pixel6, pixel4);
}