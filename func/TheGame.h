void TheGame(std::vector<std::vector<int>>& ships1, std::vector<std::vector<int>>& ships2, int gamerow, int gamecol, int shipsingame){
    int Inter = 5;
    std::string rowS, columnS;
    int row, column;
    int hits1 = 0, hits2 = 0, NumofTurns = 0;
    while(true){
        while(true){
            std::cout << "\nPlayer 1\nSelect coordinates \nChoose a row number between 1 and " << gamerow << ": ";
            std::cin >> rowS;
            IfDigit(&rowS, &row, &Inter);
            if(Inter == 6){
                std::cout << "\nPlease enter a number.\n";
                Inter = 5;
                continue;
            };

            std::cout << "Choose a column number between 1 and " << gamecol << ": ";
            std::cin >> columnS;
            IfDigit(&columnS, &column, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };
            if((row > gamerow) || (column > gamecol) || (row < 1) || (column < 1)){
                std::cout << "\nThis location is out of the map.\nReposition the hit location.\n"; 
                continue;
            }
            row--;
            column--;

            if(ships2[row][column] == 2 || ships2[row][column] == 3){
                std::cout << "\nYou have already hit this location. Choose another one.\n";
            }else if(ships2[row][column] == 0){
                ships2[row][column] = 2;
                Display(ships1, ships2);
                std::cout<<"You missed!\n";
                break;
            }else{
                hits1++;
                if(shipsingame - hits1 != 0){
                    ships2[row][column] = 3;
                    Display(ships1, ships2);
                    std::cout << "You hit! " << shipsingame - hits1 <<" left. (" << hits1 << "/" <<shipsingame << ")\n";
                    break;
                }else{
                    ships2[row][column] = 3;
                    Display(ships1, ships2);
                    std::cout << "You hit the last ship!\n";
                    break;
                }
            }
        }
        NumofTurns++;
        if((shipsingame - hits1) == 0){
            break;
        }

        while(true){
            std::cout << "\nPlayer 2\nSelect coordinates \nChoose a row number between 1 and " << gamerow << ": ";
            std::cin >> rowS;
            IfDigit(&rowS, &row, &Inter);
            if(Inter == 6){
                std::cout << "Please enter a number.\n";
                Inter = 5;
                continue;
            };

            std::cout << "Choose a column number between 1 and " << gamecol << ": ";
            std::cin >> columnS;
            IfDigit(&columnS, &column, &Inter);
            if(Inter == 6){
                std::cout << " \nPlease enter a number.\n";
                Inter = 5;
                continue;
            };

            if((row > gamerow) || (column > gamecol) || (row < 1) || (column < 1)){
                std::cout << "\nThis location is out of the map.\nReposition the hit location.\n"; 
                continue;
            }
            row--;
            column--;

            if(ships1[row][column] == 2 || ships1[row][column] == 3){
                std::cout << "You have already hit this location. Choose another one.\n";
                continue;
            }else if(ships1[row][column] == 0){
                ships1[row][column] = 2;
                Display(ships1, ships2);
                std::cout<<"You missed!\n";                    
                break;
            }else{
                hits2++;
                if(shipsingame - hits2 != 0){
                    ships1[row][column] = 3;
                    Display(ships1, ships2);
                    std::cout << "You hit! " << shipsingame - hits2 <<" left. (" << hits2 << "/" <<shipsingame << ")\n";
                    break;
                }else{
                    ships1[row][column] = 3;
                    Display(ships1, ships2);
                    std::cout << "You hit the last ship!\n";
                    break;
                }
            }
        }
        if((shipsingame - hits2) == 0){
            break;
        }
    }
    if((shipsingame - hits1) == 0)
        std::cout << "\nPlayer 1 won in " << NumofTurns << " rounds. Total number of shots: " << NumofTurns * 2 - 1 << "\n";
    else
        std::cout << "\nPlayer 2 won in " << NumofTurns << " rounds. Total number of shots: " << NumofTurns * 2  << "\n";

}
