void GameFieldDesign(std::vector<std::vector<int>>& ships1, std::vector<std::vector<int>>& ships2, int gamerow, int gamecol, int shipsingame){
    int Inter = 5;
    std::cout << "\nPlayer 1\nWhich row and column do you want to put the ships in?\n";
    std::string rowS, columnS;
    int row, column;
    int shipcounter = 0;

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
    system ("CLS");
}