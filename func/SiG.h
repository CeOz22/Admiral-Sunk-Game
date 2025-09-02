int ShipsInGame(int gamerow, int gamecol){
    int Inter = 5;
    int shipsingame;
    std::string SiG;
    int max = gamerow * gamecol / 7;
    while(true){
        std::cout << "\nHow many ships will be in the game (Min: 1 - Max: " << (max) <<"): " << std::flush;
        std::cin >> SiG;
        IfDigit(&SiG, &shipsingame, &Inter);
        if(Inter == 6){
            std::cout << "Please enter a number.\n";
            Inter = 5;
            continue;
        };

        if((shipsingame < 1) || (shipsingame > (max))){
            if(shipsingame < 1)
                std::cout << "This value cannot be less than one. Choose a larger value:\n";
            else
                std::cout << "This value cannot be larger than " << (max) << ". Choose a smallar value:\n";
        }else
            break;
    }
    return shipsingame;
}