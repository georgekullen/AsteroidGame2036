//George Kullen ConcreteAsteroid.cpp
#include <ConcreteAsteroid.h>
using namespace std;

#define ASTEROID_HEIGHT 12
#define ASTEROID_WIDTH 15
#define Q 0x808000 //OLIVE
#define I 0x008000 //GREEN
#define S 0xC0C0C0 //SILVER
#define C 0x17202A //UFO GLASS
#define D 0x797D7F //DARK GREY
#define L 0x00FF00 //LIME
#define P 0xFF00FF //PINK
#define R 0xF1C40F //YELLOW
#define O 0xF39C12 //ORANGE
#define G 0xAAB7B8 //GREY
#define _ 0x000000 //BLACK
#define X 0xFFFFFF //WHITE
#define B 0x0000FF //BLUE
#define r 0xFF0000 //RED

int asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,X,X,X,X,X,X,X,_,_,_,
    _,_,_,X,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    X,X,X,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,_,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,X,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,X,_,_,_,_,_,X,_,
    X,_,_,_,_,_,X,X,_,_,_,_,X,_,_,
    _,X,_,_,_,X,_,X,_,_,_,_,X,_,_,
    _,_,X,_,X,_,_,X,_,_,_,X,_,_,_,
    _,_,_,X,_,_,_,X,X,X,X,_,_,_,_
};

int asteroid_sprite_2[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,X,X,_,_,
    _,_,_,X,X,X,_,_,_,_,X,_,_,X,_,
    _,_,X,_,_,_,X,X,_,X,_,_,_,_,X,
    _,X,_,_,_,_,_,_,X,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,X,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,X,_,_,_,
    _,_,_,X,X,X,X,X,X,X,X,_,_,_,_
};

int asteroid_sprite_3[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,X,X,X,X,X,X,X,X,X,_,_,_,
    _,_,_,_,X,_,_,_,_,_,_,_,X,X,_,
    _,_,_,X,_,_,_,_,_,_,_,_,_,_,X,
    _,X,X,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,X,X,_,
    X,_,_,_,_,_,_,_,_,_,X,X,_,_,_,
    X,_,_,_,_,_,_,_,_,X,_,_,_,_,_,
    X,_,_,_,_,_,_,_,_,_,X,X,_,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,X,X,_,
    _,X,_,_,_,_,_,X,X,_,_,_,_,_,X,
    _,_,X,_,_,X,X,_,_,X,X,_,X,X,_,
    _,_,_,X,X,_,_,_,_,_,_,X,_,_,_
};

int asteroid_sprite_4[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,X,X,_,_,X,X,X,_,_,_,
    _,_,_,X,_,_,_,X,X,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
    _,X,_,_,_,_,_,_,_,_,_,_,_,X,_,
    _,_,X,_,_,X,X,_,_,_,_,_,X,_,_,
    _,_,_,X,X,_,_,X,X,X,X,X,_,_,_
};

ConcreteAsteroid1::ConcreteAsteroid1()
{
    x_Pos = 0;
    y_Pos = 0;
}

ConcreteAsteroid1::ConcreteAsteroid1(int x_Pos, int y_Pos, int deltaX, int deltaY)
{
    this->x_Pos = x_Pos;
    this->y_Pos = y_Pos;
    this->deltaX = deltaX;
    this->deltaY = deltaY;
}

void ConcreteAsteroid1::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_1);
}

void ConcreteAsteroid1::update(uLCD_4DGL & uLCD) //check implementation
{
    uLCD.filled_rectangle(x_Pos, y_Pos, x_Pos + ASTEROID_WIDTH, y_Pos + ASTEROID_HEIGHT, BLACK);
    if (this->x_Pos + deltaX < 1 || this->y_Pos + deltaY < 10 || this->x_Pos + deltaX > 112 || this->y_Pos + deltaY > 116) { //out of bounds, declare new positions
        int randSwitch = rand() % 4 + 1; //Determine which side of screen to start on
        if (randSwitch == 1) {
            this->x_Pos = 1;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = rand() % 2 + 1;
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 2) {
            this->x_Pos = 112;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = -1 * (rand() % 2 + 1);
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 3) {
            this->x_Pos = rand() % 112;
            this->y_Pos = 116;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = -1 * (rand() % 2 + 1);
        } else {
            this->x_Pos = rand() % 112;
            this->y_Pos = 10;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = rand() % 2 + 1;
        }
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_1);
    } else {
        this->x_Pos = this->x_Pos + deltaX;
        this->y_Pos = this->y_Pos + deltaY;
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_1);
    }
}

//ASTEROID 2

ConcreteAsteroid2::ConcreteAsteroid2()
{
    x_Pos = 0;
    y_Pos = 0;
}

ConcreteAsteroid2::ConcreteAsteroid2(int x_Pos, int y_Pos, int deltaX, int deltaY)
{
    this->x_Pos = x_Pos;
    this->y_Pos = y_Pos;
    this->deltaX = deltaX;
    this->deltaY = deltaY;
}

void ConcreteAsteroid2::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_2);
}

void ConcreteAsteroid2::update(uLCD_4DGL & uLCD) //check implementation
{
    uLCD.filled_rectangle(x_Pos, y_Pos, x_Pos + ASTEROID_WIDTH, y_Pos + ASTEROID_HEIGHT, BLACK);
    if (this->x_Pos + deltaX < 1 || this->y_Pos + deltaY < 10 || this->x_Pos + deltaX > 112 || this->y_Pos + deltaY > 116) { //out of bounds, declare new positions
        int randSwitch = rand() % 4 + 1; //Determine which side of screen to start on
        if (randSwitch == 1) {
            this->x_Pos = 1;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = rand() % 2 + 1;
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 2) {
            this->x_Pos = 112;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = -1 * (rand() % 2 + 1);
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 3) {
            this->x_Pos = rand() % 112;
            this->y_Pos = 116;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = -1 * (rand() % 2 + 1);
        } else {
            this->x_Pos = rand() % 112;
            this->y_Pos = 10;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = rand() % 2 + 1;
        }
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_2);
    } else {
        this->x_Pos = this->x_Pos + deltaX;
        this->y_Pos = this->y_Pos + deltaY;
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_2);
    }
}

//ASTEROID 3

ConcreteAsteroid3::ConcreteAsteroid3()
{
    x_Pos = 0;
    y_Pos = 0;
}

ConcreteAsteroid3::ConcreteAsteroid3(int x_Pos, int y_Pos, int deltaX, int deltaY)
{
    this->x_Pos = x_Pos;
    this->y_Pos = y_Pos;
    this->deltaX = deltaX;
    this->deltaY = deltaY;
}

void ConcreteAsteroid3::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_3);
}

void ConcreteAsteroid3::update(uLCD_4DGL & uLCD) //check implementation
{
    uLCD.filled_rectangle(x_Pos, y_Pos, x_Pos + ASTEROID_WIDTH, y_Pos + ASTEROID_HEIGHT, BLACK);
    if (this->x_Pos + deltaX < 1 || this->y_Pos + deltaY < 10 || this->x_Pos + deltaX > 112 || this->y_Pos + deltaY > 116) { //out of bounds, declare new positions
        int randSwitch = rand() % 4 + 1; //Determine which side of screen to start on
        if (randSwitch == 1) {
            this->x_Pos = 1;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = rand() % 2 + 1;
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 2) {
            this->x_Pos = 112;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = -1 * (rand() % 2 + 1);
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 3) {
            this->x_Pos = rand() % 112;
            this->y_Pos = 116;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = -1 * (rand() % 2 + 1);
        } else {
            this->x_Pos = rand() % 112;
            this->y_Pos = 10;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = rand() % 2 + 1;
        }
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_3);
    } else {
        this->x_Pos = this->x_Pos + deltaX;
        this->y_Pos = this->y_Pos + deltaY;
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_3);
    }
}

//ASTEROID 4

ConcreteAsteroid4::ConcreteAsteroid4()
{
    x_Pos = 0;
    y_Pos = 0;
}

ConcreteAsteroid4::ConcreteAsteroid4(int x_Pos, int y_Pos, int deltaX, int deltaY)
{
    this->x_Pos = x_Pos;
    this->y_Pos = y_Pos;
    this->deltaX = deltaX;
    this->deltaY = deltaY;
}

void ConcreteAsteroid4::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_4);
}

void ConcreteAsteroid4::update(uLCD_4DGL & uLCD) //check implementation
{
    uLCD.filled_rectangle(x_Pos, y_Pos, x_Pos + ASTEROID_WIDTH, y_Pos + ASTEROID_HEIGHT, BLACK);
    if (this->x_Pos + deltaX < 1 || this->y_Pos + deltaY < 10 || this->x_Pos + deltaX > 112 || this->y_Pos + deltaY > 116) { //out of bounds, declare new positions
        int randSwitch = rand() % 4 + 1; //Determine which side of screen to start on
        if (randSwitch == 1) {
            this->x_Pos = 1;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = rand() % 2 + 1;
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 2) {
            this->x_Pos = 112;
            this->y_Pos = rand() % 106 + 10;
            this->deltaX = -1 * (rand() % 2 + 1);
            this->deltaY = rand() % 4 - 2;
        } else if (randSwitch == 3) {
            this->x_Pos = rand() % 112;
            this->y_Pos = 116;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = -1 * (rand() % 2 + 1);
        } else {
            this->x_Pos = rand() % 112;
            this->y_Pos = 10;
            this->deltaX = rand() % 4 - 2;
            this->deltaY = rand() % 2 + 1;
        }
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_4);
    } else {
        this->x_Pos = this->x_Pos + deltaX;
        this->y_Pos = this->y_Pos + deltaY;
        uLCD.BLIT(x_Pos, y_Pos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_4);
    }
}