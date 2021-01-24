//George Kullen ConcreteAsteroid.h
#include <AbstractAsteroid.h>

#ifndef CONCRETEASTEROID1_H
#define CONCRETEASTEROID1_H

class ConcreteAsteroid1 : public AbstractAsteroid
{
    public:
        ConcreteAsteroid1();
        ConcreteAsteroid1(int, int, int, int);
        virtual void draw(uLCD_4DGL &);
        virtual void update(uLCD_4DGL &);
};

class ConcreteAsteroid2 : public AbstractAsteroid
{
    public:
        ConcreteAsteroid2();
        ConcreteAsteroid2(int, int, int, int);
        virtual void draw(uLCD_4DGL &);
        virtual void update(uLCD_4DGL &);
};

class ConcreteAsteroid3 : public AbstractAsteroid
{
    public:
        ConcreteAsteroid3();
        ConcreteAsteroid3(int, int, int, int);
        virtual void draw(uLCD_4DGL &);
        virtual void update(uLCD_4DGL &);
};

class ConcreteAsteroid4 : public AbstractAsteroid
{
    public:
        ConcreteAsteroid4();
        ConcreteAsteroid4(int, int, int, int);
        virtual void draw(uLCD_4DGL &);
        virtual void update(uLCD_4DGL &);
};
#endif