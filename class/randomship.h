class randomship{
    unsigned seed = static_cast<unsigned>(std::time(nullptr));
    std::mt19937 gen;                                                                   // A generator for producing random numbers.
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

        int setrandom(vecvec& sh, std::array<int, 4> shipcount, int fieldcount[4], int gamerow, int gamecol){
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
                    int direction = generator(0, 1);
                    int rowship   = generator(0, gamerow - 1);
                    int colship   = generator(0, gamerow - 1);
                    int F1count = fieldcount[Fcount - 1];
                    if(direction == 0){
                        colship = generator(0, gamecol - F1count);
                        sh = column(sh, F1count, gamerow, gamecol, rowship, colship);
                    }else{
                        rowship = generator(0, gamerow - F1count);
                        sh = row(sh, F1count, gamerow, gamecol, rowship, colship);
                    }
                }Fcount--;
            }while(Fcount != 0);
        }

        vecvec column(const vecvec& ship, int F1count, int gamerow, int gamecol, int rowship, int& colship){
            bool condition = true;
            vecvec copy = ship;
            int i = 0;
            while(condition && i < F1count){
                for(i = 0; i < F1count; ++i){
                    if(copy.at(rowship).at(colship + i) == 1){                          //If two ships collide, this statement will prevent it
                        colship = generator(0, gamecol - F1count);
                        rowship = generator(0, gamerow - F1count);
                        condition = false;
                        break;
                    }
                    copy.at(rowship).at(colship + i) = 1;
                }
                if(!condition)
                    break;
            }
            if(condition)
                return copy;
            else
                return column(ship, F1count, gamerow, gamecol, rowship, colship);
        }
        vecvec row(const vecvec& ship, int F1count, int gamerow, int gamecol, int& rowship, int colship){
            bool condition = true;
            vecvec copy = ship;
            int i = 0;
            while(condition && i < F1count){
                for(i = 0; i < F1count; ++i){
                    if(copy.at(rowship + i).at(colship) == 1){
                        colship = generator(0, gamecol - F1count);
                        rowship = generator(0, gamerow - F1count);
                        condition = false;
                        break;
                    }
                    copy.at(rowship + i).at(colship) = 1;
                }
                if(!condition)
                    break;
            }
            if(condition)
                return copy;
            else
                return row(ship, F1count, gamerow, gamecol, rowship, colship);
        }
};