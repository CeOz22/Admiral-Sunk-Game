class randomship{
    unsigned seed = static_cast<unsigned>(std::time(nullptr));
    // Mersenne Twister engine for producing random numbers.
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    using vecvec = std::vector<std::vector<int>>;
    public:
        randomship(){
            gen.seed(seed);
        }
        int generator(int min, int max) {
            dis = std::uniform_int_distribution<>(min, max);
            return dis(gen);
        }

        // Places the ships randomly on the field
        int putrandom(vecvec& sh, int SiG, int fieldcount[4], int gamerow, int gamecol){
            auto shipcount = getCount(SiG);
            int Fcount;
            while(true){
                static int i = 0;
                if(shipcount[3 - i] == 0){
                    i++;
                }
                else{
                    Fcount = fieldcount[3 - i];
                    break;
                }
            }
            do{
                for(int i = 0; i < shipcount[Fcount - 1]; ++i){
                    int F1count = fieldcount[Fcount - 1];
                    sh = shipplacer(sh, F1count, gamerow, gamecol);
                }Fcount--;
            }while(Fcount != 0);
        }

        vecvec shipplacer(const vecvec& ship, int F1count, int gamerow, int gamecol){
            vecvec copy = ship;
            std::vector<int> dir = {generator(0, 1), 1};
            bool condition = true;
            int rowship, colship;
            if(dir.at(0) == 1){
                dir.at(1) = 0;
                rowship = generator(0, gamerow - F1count);
                colship = generator(0, gamerow - 1);
            }else{
                dir.at(1) = 1;
                rowship = generator(0, gamerow - 1);
                colship = generator(0, gamecol - F1count);
            }
            int i = 0;
            while(condition && i < F1count){
                for(i = 0; i < F1count; ++i){
                    //Before positioning the ship, it checks whether there are any ships in the area. If there is a ship, it sets itself to call the function again.
                    if(copy.at(rowship + i * dir.at(0)).at(colship + i * dir.at(1)) == 1){
                        dir.at(0) = generator(0, 1);
                        condition = false;
                        break;
                    }
                    copy.at(rowship + i * dir.at(0)).at(colship + i * dir.at(1)) = 1;
                }
                if(!condition)
                    break;
            }
            if(condition)
                return copy;
            else
                return shipplacer(ship, F1count, gamerow, gamecol);
        }

        std::array<int, 4> getCount(int shipsIngame){
            // If the player wants the ships to be placed randomly, the ships will be designed according to the shipsingame variable. 
            switch(shipsIngame){
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
};
