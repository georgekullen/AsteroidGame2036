//George Kullen main.cpp
#include "ScreenObject.h"
#include "SpaceshipEarth.h"
#include "ConcreteAsteroid.h"
#include "mbed.h"
#include "MMA8452.h"
#include "PinDetect.h"
#include "Speaker.h"
#include "time.h"

using namespace std;

#define NUM_ASTEROIDS 4

#define ASTEROID_HEIGHT 12
#define ASTEROID_WIDTH 15

bool overlap(ScreenObject & objectA, ScreenObject & objectB) //checks for collision between two ScreenObjects should be used as (SpaceshipEarth, Asteroid) for accuracy
{
    if (objectA.getXPos() > objectB.getXPos() && objectA.getXPos() < objectB.getXPos() + 15 && objectA.getYPos() > objectB.getYPos() && objectA.getYPos() < objectB.getYPos() + 12) {//check top left corner
        return true;
    } else if (objectA.getXPos() + 10 > objectB.getXPos() && objectA.getXPos() + 10 < objectB.getXPos() + 15 && objectA.getYPos() > objectB.getYPos() && objectA.getYPos() < objectB.getYPos() + 12) {//check top left corner
        return true;
    } else if (objectA.getXPos() > objectB.getXPos() && objectA.getXPos() < objectB.getXPos() + 15 && objectA.getYPos() + 10 > objectB.getYPos() && objectA.getYPos() + 10 < objectB.getYPos() + 12) {//check top left corner
        return true;
    } else if (objectA.getXPos() + 10 > objectB.getXPos() && objectA.getXPos() + 10 < objectB.getXPos() + 15 && objectA.getYPos() + 10 > objectB.getYPos() && objectA.getYPos() + 10 < objectB.getYPos() + 12) {//check top left corner
        return true;
    } else {
        return false;
    }
}

uLCD_4DGL uLCD(p9, p10, p11); // serial tx, serial rx, reset pin;

Speaker mySpeaker(p26);
Serial pc(USBTX,USBRX);

PinDetect pb1(p21);
PinDetect pb2(p22);
PinDetect pb3(p23);

int main() {
    pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    
    MMA8452 acc(p28, p27, 40000); //instantiate an acc object!
    //set parameters -- use these and don't change
    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_100);
    
    uLCD.baudrate(300000);
    wait(0.2);
    srand(time(0)); // do this srand call here ONLY... no where else in the code!
    
    int x = 0, y = 0, z = 0;
    
    ScreenObject * ActiveAsteroids[NUM_ASTEROIDS];

    SpaceShipEarth ship(70,70);
    
    //intro screen
    uLCD.cls();
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.locate(1,1);
    uLCD.printf("\n");
    uLCD.printf(" Survive\n");
    uLCD.printf("   for\n");
    uLCD.printf(" 30 Secs!\n");
    wait(4);
    uLCD.cls();
    
    ship.draw(uLCD);
    
    //initialize asteroid positions
    for (int i = 0; i < 4; i++) {     
        int randSwitch = rand() % 4 + 1; //Determine which side of screen to start on
        switch(i + 1) {
            case 1:
                if (randSwitch == 1) {
                    ActiveAsteroids[i] = new ConcreteAsteroid1(1, rand() % 106 + 10, rand() % 2 + 1, rand() % 4 - 2);
                } else if (randSwitch == 2) {
                    ActiveAsteroids[i] = new ConcreteAsteroid1(112, rand() % 106 + 10, -1 * (rand() % 2 + 1), rand() % 4 - 2);
                } else if (randSwitch == 3) {
                    ActiveAsteroids[i] = new ConcreteAsteroid1(rand() % 112, 116, rand() % 4 - 2, -1 * (rand() % 2 + 1));
                } else {
                    ActiveAsteroids[i] = new ConcreteAsteroid1(rand() % 112, 10, rand() % 4 - 2, rand() % 2 + 1);
                }
                break;
            case 2:
                if (randSwitch == 1) {
                    ActiveAsteroids[i] = new ConcreteAsteroid2(1, rand() % 106 + 10, rand() % 2 + 1, rand() % 4 - 2);
                } else if (randSwitch == 2) {
                    ActiveAsteroids[i] = new ConcreteAsteroid2(112, rand() % 106 + 10, -1 * (rand() % 2 + 1), rand() % 4 - 2);
                } else if (randSwitch == 3) {
                    ActiveAsteroids[i] = new ConcreteAsteroid2(rand() % 112, 116, rand() % 4 - 2, -1 * (rand() % 2 + 1));
                } else {
                    ActiveAsteroids[i] = new ConcreteAsteroid2(rand() % 112, 10, rand() % 4 - 2, rand() % 2 + 1);
                }
                break;
            case 3:
                if (randSwitch == 1) {
                    ActiveAsteroids[i] = new ConcreteAsteroid3(1, rand() % 106 + 10, rand() % 2 + 1, rand() % 4 - 2);
                } else if (randSwitch == 2) {
                    ActiveAsteroids[i] = new ConcreteAsteroid3(112, rand() % 106 + 10, -1 * (rand() % 2 + 1), rand() % 4 - 2);
                } else if (randSwitch == 3) {
                    ActiveAsteroids[i] = new ConcreteAsteroid3(rand() % 112, 116, rand() % 4 - 2, -1 * (rand() % 2 + 1));
                } else {
                    ActiveAsteroids[i] = new ConcreteAsteroid3(rand() % 112, 10, rand() % 4 - 2, rand() % 2 + 1);
                }
                break;
            case 4:
                if (randSwitch == 1) {
                    ActiveAsteroids[i] = new ConcreteAsteroid4(1, rand() % 106 + 10, rand() % 2 + 1, rand() % 4 - 2);
                } else if (randSwitch == 2) {
                    ActiveAsteroids[i] = new ConcreteAsteroid4(112, rand() % 106 + 10, -1 * (rand() % 2 + 1), rand() % 4 - 2);
                } else if (randSwitch == 3) {
                    ActiveAsteroids[i] = new ConcreteAsteroid4(rand() % 112, 116, rand() % 4 - 2, -1 * (rand() % 2 + 1));
                } else {
                    ActiveAsteroids[i] = new ConcreteAsteroid4(rand() % 112, 10, rand() % 4 - 2, rand() % 2 + 1);
                }
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < 4; i++) {
        ActiveAsteroids[i]->draw(uLCD);
    }
    time_t startTime;
    startTime = time(0); //declare startTime
    bool game = true;
    bool lose = false;
    
    uLCD.filled_rectangle(0, 0, 120, 8, BLUE);
    while(time(0)-startTime < 30 && game) { //run game for 30 seconds or until termination
        int timeElapsed = time(0) - startTime;
        uLCD.filled_rectangle(0, 0, timeElapsed * 4, 10, BLACK); //Timer bar
        
        if (!acc.isXYZReady()) {
            wait(0.01);
        } else {
            //spaceship movement
            acc.readXYZCounts(&x,&y,&z);
            if (x > 0.4) {
                ship.setYPos(ship.getYPos() + 1);
            }
            if (x < -0.4) {
                ship.setYPos(ship.getYPos() - 1);
            }
            if (y > 0.4) {
                ship.setXPos(ship.getXPos() + 1);
            }
            if (y < -0.4) {
                ship.setXPos(ship.getXPos() - 1);
            }
            
            ship.update(uLCD);
            
            for (int i = 0; i < 4; i++) { 
                wait(0.005); //slow game down slightly for readability
                ActiveAsteroids[i]->update(uLCD);
                if (overlap(ship, * ActiveAsteroids[i])) { //check for collision
                    game = false; //exit game loop
                    lose = true; //go to lose screen on game exit
                    ship.setExploded(true); //Explode ship for next update call
                    ship.update(uLCD);
                    mySpeaker.PlayNote(300.0,0.25,0.1); //Play loss sound
                    mySpeaker.PlayNote(250.0,0.25,0.1);
                    mySpeaker.PlayNote(200.0,0.25,0.1);
            
                    wait(2);
                }
            }
        }
    }
    uLCD.cls();
    if (lose) { //Lose Sequence
        uLCD.text_width(2);
        uLCD.text_height(2);
        uLCD.locate(1,1);
        uLCD.printf("  You\n");
        uLCD.printf("  Lose\n");
        uLCD.printf("Game Over\n");  
    } else { //Win Sequence
        mySpeaker.PlayNote(200.0,0.25,0.1);
        mySpeaker.PlayNote(250.0,0.25,0.1);
        mySpeaker.PlayNote(300.0,0.25,0.1);
        uLCD.text_width(2);
        uLCD.text_height(2);
        uLCD.locate(1,1);
        uLCD.printf("\n");
        uLCD.printf("You Win\n");
        uLCD.printf("Congrats!\n");
    }
}