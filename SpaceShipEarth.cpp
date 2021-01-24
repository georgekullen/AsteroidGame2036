//George Kullen SpaceShipEarth.cpp
#include <SpaceshipEarth.h>
using namespace std;

#define EARTH_WIDTH 10
#define EARTH_HEIGHT 10
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

int spaceship_earth1[EARTH_WIDTH * EARTH_HEIGHT] = {
    _,_,S,S,S,S,S,S,_,_,
    _,S,I,I,I,I,I,I,S,_,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,S,_,
    _,S,S,S,S,S,S,S,_,_,
};
 
int spaceship_explosion[EARTH_WIDTH * EARTH_HEIGHT] = {
    r,_,_,_,_,r,_,_,_,_,
    _,r,_,_,_,r,_,_,_,r,
    _,_,r,_,_,r,_,_,r,_,
    _,_,_,_,R,_,_,r,_,_,
    r,r,r,_,R,R,R,_,_,_,
    _,_,_,R,R,R,_,r,r,r,
    _,_,r,_,_,R,_,_,_,_,
    _,r,_,_,r,_,_,r,_,_,
    r,_,_,_,r,_,_,_,r,_,
    _,_,_,_,r,_,_,_,_,r,
};

SpaceShipEarth::SpaceShipEarth()
{
    x_Pos = 0;
    y_Pos = 0;
    this->exploded = false;
}

SpaceShipEarth::SpaceShipEarth(int x_Pos, int y_Pos)
{
    this->x_Pos = x_Pos;
    this->y_Pos = y_Pos;
    this->exploded = false;
}

void SpaceShipEarth::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(x_Pos, y_Pos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_earth1);
}

void SpaceShipEarth::update(uLCD_4DGL & uLCD) //check implementation
{
    uLCD.filled_rectangle(x_Pos - 1, y_Pos - 1, x_Pos + EARTH_WIDTH + 1, y_Pos + EARTH_HEIGHT + 1, BLACK);
    if (this->exploded) {
        uLCD.BLIT(x_Pos, y_Pos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_explosion);
        return;
    }
    uLCD.BLIT(x_Pos, y_Pos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_earth1); //this is right
}