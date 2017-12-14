#ifndef ANT_HPP
#define ANT_HPP

#include <vector>
#include <iostream>
#include <cmath>

/**
 * @brief Describes the Langton Ant
 * 
 */
class Ant{
private:
    std::pair<int,int> currentPos;
    short direction;

public:
    /**
     * @brief Initialize at (0,0), facing up. 
     * 
     */
    Ant(){
        currentPos = std::pair<int,int>(0,0);
        direction = 0;
    }

    /**
     * @brief Make 90° turn left.
     * 
     */
    void turnLeft(){
        if (direction == 0)
            direction = 3;
        else
            direction -= 1;
    }

    /**
     * @brief Make 90° turn right.
     * 
     */
    void turnRight(){
        if (direction == 3)
            direction = 0;
        else
            direction ++;
    }

    /**
     * @brief Moves the ant according to its direction.
     * 
     */
    void forward(){
        // std::cerr << direction << std::endl;
        // std::cerr << currentPos.first << " " << currentPos.second << std::endl;
        switch (direction){
            case 0:
                currentPos = std::pair<int,int>(currentPos.first,currentPos.second-1);
                break;
            case 1:
                currentPos = std::pair<int,int>(currentPos.first+1,currentPos.second);
                break;
            case 2:
                currentPos = std::pair<int,int>(currentPos.first,currentPos.second+1);
                break;
            case 3:
                currentPos = std::pair<int,int>(currentPos.first-1,currentPos.second);
                break;
            default:
                std::cerr << "Invalide direction !" << std::endl;
        }
    }

    /**
     * @brief Returns the position of the ant.
     * 
     */
    std::pair<int,int> getPos(){
        return std::pair<int,int>(currentPos);
    }   
};

#endif