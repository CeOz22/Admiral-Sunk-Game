class gameRowCol{
    private:
        const int gameMaxRow = 10;
        int gamerow = 10, gamecol = 10, mode;
        std::string gamerowS, gamecolS, modeS;
        int Inter = 5;
    public:

        std::string setRowCol(){
            std::cout << "\nDo you want to play the default version(0) of the game or the customized version(1): " << std::flush;
            while(true){                
                std::cin >> modeS;
                IfDigit(&modeS, &mode, &Inter);
                if(Inter == 6){
                    std::cout << "Please enter a number.\n";
                    Inter = 5;
                    continue;
                };
                if(mode == 0)
                    break;
                else if(mode != 1){
                    std::cout << "Invalid! Please enter one of the specified numbers, default(0) and customized(1): ";
                    continue;
                }
                
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
                    break;
            }
        }
        int setGameRow(){
            return gamerow;
        }
        int setGameCol(){
            return gamecol;
        }
};
