//George Kullen ScreenObject.h
#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include "uLCD_4DGL.h"

class ScreenObject
{
    public:
        virtual void draw(uLCD_4DGL &) = 0;
        virtual void update(uLCD_4DGL &) = 0;
        void setXPos(int x_Pos) { this->x_Pos = x_Pos; };
        void setYPos(int y_Pos) { this->y_Pos = y_Pos; };
        int getXPos() {return x_Pos; };
        int getYPos() {return y_Pos; };

    protected:
        int x_Pos;
        int y_Pos;
};
#endif