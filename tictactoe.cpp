#include <iostream>
#include <vector>
#include "functions.hpp"

int main(){
    char grid[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char playerone='X', playertwo='O';
    int input;
    int turn=1;
    bool win=false;
    while (win==false && turn<10){
     play_turn(grid,turn);
     win=is_win(grid,turn);
     turn++;
     if (turn==10&&win==false){
         draw(grid);
         std::cout<<"It's a tie!\n";
     }
    }
    
    
    
}