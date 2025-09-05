#include "../class/randomship.h"
std::array<int, 4> getCount(int shipsIngame);
void GameFieldDesign(std::vector<std::vector<int>>& ships1, std::vector<std::vector<int>>& ships2, int gamerow, int gamecol, int shipsingame){
    int Inter = 5;
    std::string rowS, columnS;
    int row, column;
    int shipcounter = 0;
    std::string rs;

    auto shipcount = getCount(shipsingame);
    bool randomness = false;

    std::cout << "Do you want to place ships randomly (Yes - No): " << std::flush;
    while(true){
        std::cin >> rs;
        if(rs == "Yes" || rs == "yes" || rs == "Y" || rs == "y" || rs == "No" || rs == "no" || rs == "N" || rs == "n"){
            if(rs == "Yes" || rs == "yes" || rs == "Y" || rs == "y"){
                randomness = true;
                int fieldcount[4] = {1, 2, 3, 4};
                randomship random;
                random.setrandom(ships1, shipcount, fieldcount, gamerow, gamecol);
                std::cout << "\nPlayer 1's gamefield:" << std::endl;
                for(int i = 0; i < gamerow; i++){
                    for(int j = 0; j < gamecol; j++){
                        if(ships1[i][j] == 1)
                            std::cout <<"C ";
                        else
                            std::cout <<"O ";
                    }
                    std::cout << std::endl;
                }
                system("pause");
                system("CLS");

                random.setrandom(ships2, shipcount, fieldcount, gamerow, gamecol);
                std::cout << "Player 2's gamefield:" << std::endl;
                for(int i = 0; i < gamerow; i++){
                    for(int j = 0; j < gamecol; j++){
                        if(ships2[i][j] == 1)
                            std::cout <<"C ";
                        else
                            std::cout <<"O ";
                    }
                    std::cout << std::endl;
                }
                system("pause");
                system("CLS");
                break;
            }else
                break;
        }else{
            std::cout << "Invalid! Please enter one of the specified answers.\n";
            continue;
        }
    }

    if(randomness == 0){
        std::cout << "\nPlayer 1\nWhich row and column do you want to put the ships in?\n";
        do{
            std::cout << "Row: ";
            std::cin >> rowS;
            IfDigit(&rowS, &row, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };
            std::cout << "Column: ";
            std::cin >> columnS;
            IfDigit(&columnS, &column, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };

            if((row < 1) || (column < 1) || (row > gamerow) || (column > gamecol)){
                std::cout << "This location is out of the map.\nReposition the ship\n";
                continue;
            }

            if(ships1[row-1][column-1] != 0){
                if((1 <= row && 1 <= column) && (row <= gamerow && column <= gamecol)){
                std::cout << "There is already a ship at this location.\nReposition the ship.\n";
                continue;
                }
            }else{
                ships1[row-1][column-1] = 1;

                for(int i = 0; i < gamerow; i++){
                    for(int j = 0; j < gamecol; j++){
                        if(ships1[i][j] == 1)
                            std::cout <<"C ";
                        else
                            std::cout <<"O ";
                    }
                    std::cout <<std::endl;
                }
            }
            std::cout <<"\n";
            shipcounter++;
        }while(shipcounter < shipsingame);
        system("pause");
        system ("CLS");
        
        shipcounter = 0;
        std::cout << "\nPlayer 2\nWhich row and column do you want to put the ships in?\n";
        
        do{
            std::cout << "Row: ";
            std::cin >> rowS;
            IfDigit(&rowS, &row, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };
            std::cout << "Column: ";
            std::cin >> columnS;
            IfDigit(&columnS, &column, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };

            if((row < 1) || (column < 1) || (row > gamerow) || (column > gamecol)){
                std::cout << "This location is out of the map.\nReposition the ship\n";
                continue;
            }

            if(ships2[row-1][column-1] != 0){
                if((1 <= row && 1 <= column) && (row <= gamerow && column <= gamecol)){
                std::cout << "There is already a ship at this location.\nReposition the ship.\n";
                continue;
                }
            }else{
                ships2[row-1][column-1] = 1;

                for(int i = 0; i < gamerow; i++){
                    for(int j = 0; j < gamecol; j++){
                        if(ships2[i][j] == 1)
                            std::cout <<"C ";
                        else
                            std::cout <<"O ";
                    }
                    std::cout <<std::endl;
                }
            }
            std::cout <<"\n";
            shipcounter++;
            
        }while(shipcounter < shipsingame);
        system("pause");
        system ("CLS");
    }
}
std::array<int, 4> getCount(int shipsIngame){
    switch(shipsIngame){                            // If the player wants the ships to be placed randomly, the ships will be designed according to the shipsingame variable. 
        case 20:    return {4, 3, 2, 1};
        case 19:    return {3, 3, 2, 1};
        case 18:    return {4, 2, 2, 1};
        case 17:    return {3, 2, 2, 1};
        case 16:    return {3, 3, 1, 1};
        case 15:    return {4, 2, 1, 1};

        case 14:    return {4, 2, 2, 0};
        case 13:    return {3, 2, 2, 0};
        case 12:    return {3, 3, 1, 0};
        case 11:    return {2, 3, 1, 0};
        case 10:    return {3, 2, 1, 0};
        case 9:     return {2, 2, 1, 0};

        case 8:     return {4, 2, 0, 0};
        case 7:     return {3, 2, 0, 0};
        case 6:     return {2, 2, 0, 0};
        case 5:     return {3, 1, 0, 0};
        case 4:     return {2, 1, 0, 0};

        case 3:     return {3, 0, 0, 0};
        case 2:     return {2, 0, 0, 0};
        case 1:     return {1, 0, 0, 0};
        default:    exit(1);
    }
}
