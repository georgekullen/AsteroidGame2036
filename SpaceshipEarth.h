//George Kullen SpaceshipEarth.h
#include "ScreenObject.h"

#ifndef SPACESHIPEARTH_H
#define SPACESHIPEARTH_H

class SpaceShipEarth : public ScreenObject
{
    public:
        SpaceShipEarth();
        SpaceShipEarth(int, int);
        virtual void draw(uLCD_4DGL &);
        virtual void update(uLCD_4DGL &);
        void setExploded(bool exploded) { this->exploded = exploded; };
    private:
        bool exploded;
};
#endif