#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "langtonGrid.hpp"

int main(int argc, char** argv){
    int windowH = 0;
    int windowW = 0;

    int gridH = 0;
    int gridW = 0;

    std::cout << " Welcome to the Langton Ant World !" << std::endl;
    std::cout << "Please enter the dimensions, in pixels, of the window (width height)"<<std::endl;

    while (windowH == 0 || windowW == 0){
        try{
            std::cin >> windowW >> windowH;
        }
        catch (...){
            std::cout << "Invalid dimensions, please try again" << std::endl;
        }
    }

    std::cout << "Now, enter the basic dimensions of the grid (even number only, the default is 20 20)\nThe format is still (width height)" << std::endl;
    try{
        std::cin >> gridW >> gridH;
    }
    catch (...){
        std::cout << "Invalide dimensions, the default has been applied." << std::endl;
    }

    LangtonGrid grid = LangtonGrid(gridW,gridH);

    std::cout << "Now, if you want some cells to be initally black, please enter their coordinates as follow:\n x y\nKnowing that the ant beigins in the (0,0) cell and is facing up" << std::endl;
    std::cout << "You can end this process by entering \"no\" " << std::endl;
    while(true){
        int x,y;
        std::string line;
        std::getline(std::cin,line);
        if (line == std::string("no"))
            break;
        else{
            if (line.size() > 1){
                auto stream = std::stringstream(line);
                stream >> x >> y;
                grid.setBlack(std::pair<int,int>(x,y));
                std::cerr << "black" << std::endl;
            }
        }
        std::cerr<<x <<" "<<y <<std::endl;
    }

    std::cout << "Now for the last step : enter how many rounds you want to run, and how long they should last\n The format is \n {number of turns} {time in ms par turn}" << std::endl;

    int numberOfTurns = 0;
    int timePerTurn = 0;

    grid.init(windowW,windowH);

    while (numberOfTurns == 0 || timePerTurn == 0){
        try{
            std::cin >> numberOfTurns >> timePerTurn;
        }
        catch (...){
            std::cout<<"Invalid Values, try again !" << std::endl;
        }
    }

    bool finished = false;
    while (!finished){
        grid.run_loop(numberOfTurns,timePerTurn);
        std::cout << "if you want to continue, please enter the number of additional steps. \n 0 will stop the simulation." << std::endl;
        int additionalSteps;
        try{
            std::cin >> additionalSteps;
            if (additionalSteps == 0)
                finished = true;
            numberOfTurns += additionalSteps;
        }
        catch (...){
            finished = true;
        }
    }

    return 0;
}