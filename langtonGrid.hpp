#ifndef LANGTON_HPP
#define LANGTON_HPP

#include <vector>
#include <set>

#include "ant.hpp"
#include "gridDisplay.hpp"

/**
 * @brief Describes the grid where the ant lives.
 * 
 */

class LangtonGrid{

    typedef std::pair<int,int> cell;

private:
    Ant ant;
    /**
     * @brief Stores all black cells in a set. All others cells are considered white.
     * 
     */
    std::set<cell> blackCells;
    GridDisplay display;
    int currentRound;
    cell top_left;
    cell bottom_right; 

public:
    LangtonGrid(int w, int h){
        ant = Ant();
        blackCells = std::set<std::pair<int,int>>();
        currentRound = 0;
        top_left = cell(-w/2,-h/2);
        bottom_right = cell(w/2,h/2);
        display = GridDisplay(this);
        }

    /**
     * @brief Add a black cell at the given position.
     * 
     */
    void setBlack(std::pair<int,int> position){
        blackCells.insert(position);
    }

    /**
     * @brief Main loop of the algorithm.
     * 
     * @param numberOfRounds how many turns to run.
     * @param timePerTurn time in millisec between two turns.
     */
    bool run_loop(int numberOfRounds, int timePerTurn){
        while (currentRound < numberOfRounds){
            auto antPos = ant.getPos();
            if (antPos.first < top_left.first || antPos.first > bottom_right.first || antPos.second < top_left.second || antPos.second > bottom_right.second){
                dezoom();
            }
            std::set<std::pair<int,int>>::iterator cellPos = blackCells.find(antPos);
            if (cellPos == blackCells.end()){
                ant.turnLeft();
                blackCells.insert(antPos);
            }
            else{
                ant.turnRight();
                blackCells.erase(cellPos);
            }
            ant.forward();
            display.display_world(timePerTurn);
            // std::cerr << blackCells.size() << std::endl;
            currentRound ++;
        }
        return true;
    }

    /**
     * @brief Get the top left corner position in the world coordinates.
     */
    cell getTopLeft(){
        return cell(top_left);
    }

    /**
     * @brief Get the bottom right corner position in the world coordinates.
     * 
     * @return cell 
     */
    cell getBottomRight(){
        return bottom_right;
    }

    /**
     * @brief Accessor to the set of black cells.
     * 
     * @return std::set<cell>* 
     */
    std::set<cell>* getBlack(){
        return &blackCells;
    }

    /**
     * @brief initialize the display window.
     * 
     * @param windowW width of the windonw, in pixels
     * @param windowH height of the window, in pixels.
     * @return true 
     * @return false 
     */
    bool init(int windowW, int windowH){
        return display.init(windowH,windowW);
    }

private :
    void dezoom(){
        top_left.first *= 2;
        top_left.second *= 2;
        bottom_right.first *= 2;
        bottom_right.second *= 2;
    }
};

#endif