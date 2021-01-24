//George Kullen AbstractAsteroid.h
#include <ScreenObject.h>

#ifndef ABSTRACTASTEROID_H
#define ABSTRACTASTEROID_H

class AbstractAsteroid : public ScreenObject
{
    public:
        virtual void draw(uLCD_4DGL &) = 0;
        virtual void update(uLCD_4DGL &) = 0;
        void setDeltaX(int deltaX) { this->deltaX = deltaX; };
        void setDeltaY(int deltaY) { this->deltaY = deltaY; };

    protected:
        int deltaX;
        int deltaY;
};
#endif