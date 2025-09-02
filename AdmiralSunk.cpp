#include "AdmiralSunk.h"

int main()
{
    gameRowCol gRowCol;
    gRowCol.setRowCol();
    int gamerow = gRowCol.setGameRow();
    int gamecol = gRowCol.setGameCol();

    std::vector<std::vector<int>> ships1(gamerow, std::vector<int>(gamecol));
    std::vector<std::vector<int>> ships2(gamerow, std::vector<int>(gamecol));

    for(int i = 0; i < gamerow; i++){
        for(int j = 0; j < gamecol; j++){
            ships1[i][j] = 0;
            ships2[i][j] = 0;
        }
    }

    int shipsingame = ShipsInGame(gamerow, gamecol);

    GameFieldDesign(ships1, ships2, gamerow, gamecol, shipsingame);
    TheGame(ships1, ships2, gamerow, gamecol, shipsingame);
    
    return 0;
}