#include <iostream>
#include <typeinfo>

void draw(char grid[9]){
    std::cout<<"   |   |    \n";
    std::cout<<" "<<grid[0]<<" | "<<grid[1]<<" | "<<grid[2]<<"\n";
    std::cout<<"___|___|___\n";
    std::cout<<"   |   |    \n";
    std::cout<<" "<<grid[3]<<" | "<<grid[4]<<" | "<<grid[5]<<"\n";
    std::cout<<"___|___|___\n";
    std::cout<<"   |   |    \n";
    std::cout<<" "<<grid[6]<<" | "<<grid[7]<<" | "<<grid[8]<<"\n";
    std::cout<<"   |   |    \n";
}

void play_turn(char grid[9], int turn){
    int input;
    std::string string="Type '1' for top left square, '2' for top center square, '3' for top right square,\n '4' for middle left square, '5' for middle center square, '6' for middle right square,\n '7' for bottom left square , '8' for bottom center square, '9' for bottom right square.\n";
    bool valid_number=false,valid_position=false;
    if (turn%2!=0){
        std::cout<<"Turn "<<turn<<": Player One, place your 'X'\n";
        draw(grid);
        std::cout<<string;
        while(valid_number==false){
            valid_number=false;
            while (valid_position==false){
                valid_position=false;
                std::cin>>input;
                if(input){
                    valid_number=true;
                    if(grid[input-1]==' '){
                        valid_position=true;
                        grid[input-1]='X';
                    }
                    else{
                        std::cout<<"Please choose an unoccupied position.\n";
                    }
                }
                else{
                    std::cout<<"Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(100,'\n');
                }                  
            }
        }  
    }
    else{std::cout<<"Turn "<<turn<<": Player Two, place your 'O'\n";
        draw(grid);
        std::cout<<string;
        while(valid_number==false){
            valid_number=false;
            while (valid_position==false){
                valid_position=false;
                std::cin>>input;
                if(input){
                    valid_number=true;
                    if(grid[input-1]==' '){
                        valid_position=true;
                        grid[input-1]='O';
                    }
                    else{
                        std::cout<<"Please choose an unoccupied position.\n";
                    }
                }
                else{
                    std::cout<<"Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(100,'\n');
                }                  
            }
        }
    }  
}

void winning(char grid[9], int turn){
    draw(grid);
    if (turn%2!=0){
        std::cout<<"Player One wins!\n";
    }
    else{
         std::cout<<"Player Two wins!\n";
    }
}

bool is_win(char grid[9], int turn){
    if (grid[0]!=' ' && grid[0]==grid[3] && grid[0]==grid[6]){
        winning(grid,turn);
        return true;
    }
    else if (grid[0]!=' ' && grid[0]==grid[1] && grid[0]==grid[2]){
        winning(grid,turn);
        return true;
    }
    else if (grid[2]!=' ' && grid[2]==grid[5] && grid[2]==grid[8]){
        winning(grid,turn);
        return true;
    }
    else if (grid[6]!=' ' && grid[6]==grid[7] && grid[6]==grid[8]){
        winning(grid,turn);
        return true;
    }
    else if (grid[1]!=' ' && grid[1]==grid[4] && grid[1]==grid[7]){
        winning(grid,turn);
        return true;
    }
    else if (grid[3]!=' ' && grid[3]==grid[4] && grid[3]==grid[5]){
        winning(grid,turn);
        return true;
    }
    else if (grid[0]!=' ' && grid[0]==grid[4] && grid[0]==grid[8]){
        winning(grid,turn);
        return true;
    }
    else if (grid[2]!=' ' && grid[2]==grid[4] && grid[2]==grid[6]){
        winning(grid,turn);
        return true;
    }
    else{
        return false;
    }
}
