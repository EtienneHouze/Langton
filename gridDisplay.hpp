#ifndef GRIDDISPLAY_HPP
#define GRIDDISPLAY_HPP

#include <SDL2/SDL.h>

class LangtonGrid;
/**
 * @brief Manages the isplay via the SDL library.
 * 
 */
class GridDisplay{
private:
    SDL_Window * window;
    SDL_Renderer * renderer;
    LangtonGrid * grid;

public:
    GridDisplay(){}

    GridDisplay(LangtonGrid* parent){
        window = nullptr;
        renderer = nullptr;
        grid = parent;
    }

    bool init(int wH, int wW){
        window = SDL_CreateWindow("Langton Ant",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,wW,wH,SDL_WINDOW_SHOWN);
        if (window == nullptr)
            return false;
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
            return false;
        return true;
    }

    void display_world(int timePerTurn);
};

#endif