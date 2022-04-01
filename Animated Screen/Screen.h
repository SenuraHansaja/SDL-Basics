#ifndef SCREEN_H
#define SCREEN_H
//#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <string.h>

namespace screenSimulate {
class Screen
{
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGH = 600;

        Screen();
        bool init();
        bool processEvents();
        void close();
        void setPixel (int x,int y,Uint8 red,Uint8 green,Uint8 blue);
        void update();

    protected:

    private:
         SDL_Window * m_window;
         SDL_Renderer *m_renderer;
         SDL_Texture *m_texture;
         Uint32 * m_buffer;

};
}
#endif // SCREEN_H
