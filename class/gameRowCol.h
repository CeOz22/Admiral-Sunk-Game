class gameRowCol{
    private:
        int Inter = 5;
        int gameMaxRow = 10;
        std::string gamerowS, gamecolS;
    public:
        int gamerow, gamecol;
        
        std::string setRowCol(){
            std::cout << "How many rows and colums will be in the game (Min: 5 - Max: " << gameMaxRow <<")\n";
                do{
                    std::cout << "Row: ";
                    std::cin >> gamerowS;
                    IfDigit(&gamerowS, &gamerow, &Inter);
                    if(Inter == 6){
                        std::cout << "Please enter a number.\n";
                        Inter = 5;
                        continue;
                    };
                    if(gamerow < 5 || gamerow > gameMaxRow){
                        std::cout << "Invalid! Please enter the rows that will be in the game, again (Min: 5 - Max: " << gameMaxRow <<")\n";
                        continue;
                    }

                    std::cout << "Column: ";
                    std::cin >> gamecolS;
                    IfDigit(&gamecolS, &gamecol, &Inter);
                    if(Inter == 6){
                        std::cout << "Please enter a number.\n";
                        Inter = 5;
                        continue;
                    };
                    if(gamecol < 5 || gamecol > gameMaxRow){
                        std::cout << "Invalid! Please enter the columns that will be in the game, again (Min: 5 - Max: " << gameMaxRow <<")\n";
                        continue;
                    }

                }while((gamerow < 5 || gamerow > gameMaxRow) || (gamecol < 5 || gamecol > gameMaxRow));
        }
        int setGameRow(){
            return gamerow;
        }
        int setGameCol(){
            return gamecol;
        }
};