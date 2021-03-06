#include "HaD_Badge.h"

uint8_t ballX = 4;
uint8_t ballY = 9;

//Hint: look in HaD_Badge.h for function and constant definitions

void eraseBall() {
    //uses global variables to erase current ball
    displayPixel(ballX, ballY, OFF);
    displayLatch();
}

void moveLeft() {
    if (ballX > 0) {
        //only move if we're not already at the edge
        eraseBall();
        --ballX;
        displayPixel(ballX, ballY, ON);
        displayLatch();
    }
}

void moveRight() {
    if (ballX < TOTPIXELX-1) {
        //only move if we're not already at the edge
        eraseBall();
        ++ballX;
        displayPixel(ballX, ballY, ON);
        displayLatch();
    }
}

void moveUp() {
    if (ballY > 0) {
        //only move if we're not already at the edge
        eraseBall();
        --ballY;
        displayPixel(ballX, ballY, ON);
        displayLatch();
    }
}

void moveDown() {
    if (ballY < TOTPIXELY-1) {
        //only move if we're not already at the edge
        eraseBall();
        ++ballY;
        displayPixel(ballX, ballY, ON);
        displayLatch();
    }
}

void animateBadge(void) {

    displayPixel(ballX, ballY, ON);
    displayLatch();
    uint32_t lastTime = getTime();

    while(1) {
        
        //This shows how to use non-blocking getTime() function
        if (getTime() > lastTime+1000) {
            lastTime = getTime();
            Buffer[14] ^= 0xFF;
        }
        
        //This shows how to get user input
        switch (getControl()) {
            case (ESCAPE):
                displayClose();
                return;
            case (LEFT):
                moveLeft();
                break;
            case (RIGHT):
                moveRight();
                break;
            case (UP):
                moveUp();
                break;
            case (DOWN):
                moveDown();
                break;
        }
    }
}