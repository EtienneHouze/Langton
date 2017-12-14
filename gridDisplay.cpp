#include "gridDisplay.hpp"
#include "langtonGrid.hpp"

#include <set>

void GridDisplay::display_world(int timePerTurn){
    SDL_RenderClear(renderer);
    int minX = grid->getTopLeft().first;
    int maxX = grid->getBottomRight().first;
    int minY = grid->getTopLeft().second;
    int maxY = grid->getBottomRight().second;
    int windowW = 0;
    int windowH = 0;
    SDL_GetWindowSize(window,&windowW,&windowH);
    double cellW = ((double)windowW)/((double)maxX-minX);
    double cellH = ((double)windowH)/((double)maxY-minY);
    SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0x00);
    SDL_RenderFillRect(renderer,NULL);
    auto cellBlack = grid->getBlack();
    SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
    for (std::set<std::pair<int,int>>::iterator it = cellBlack->begin(); it != cellBlack->end(); ++it){
        SDL_Rect newRect = SDL_Rect();
        newRect.x = (it->first - minX) * cellW;
        newRect.y = (it->second - minY) * cellH;
        newRect.h = cellH;
        newRect.w = cellW;
        // std::cerr << newRect.x << " " << newRect.y << " " << newRect.h << " " << newRect.w <<std::endl;
        SDL_RenderFillRect(renderer,&newRect);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(timePerTurn);

}