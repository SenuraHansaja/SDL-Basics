#define SDL_MAIN_HANDLED
#include <iostream>
#include <string.h>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
using namespace std;
using namespace screenSimulate;
int main()
{
    Screen screen;
    if(screen.init()==false)
    {
        cout << "error initalising SDL" << endl;
    }
    int max = 0;

    while(true)
    {
        //update particle
        //Draw particle
        int elapsed = SDL_GetTicks();
        unsigned char green = (1+sin(elapsed*0.001))*128;
        unsigned char red = (1+sin(elapsed*0.002))*128;
        unsigned char blue = (1+cos(elapsed*0.003))*128;

        for(int y=0; y< Screen::SCREEN_HEIGH;y++)
        {
            for (int x=0;x<Screen::SCREEN_WIDTH;x++)
            {
                screen.setPixel(x,y,red,green,blue);
            }
        }

        // screen update
        screen.update();
        //check for message / events
        if (screen.processEvents() == false)
        {
            break;
        }
    }
    screen.close();
    return 0;
}
