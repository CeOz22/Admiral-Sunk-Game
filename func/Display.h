void Display(const std::vector<std::vector<int>>& s1, const std::vector<std::vector<int>>& s2){
    std::cout << "\nPlayer 1\n";
    for (const auto& i : s1) {
            for (int j : i) {
                switch(j){
                    case 0:
                    case 1:                                     // This is actually for the letter C, but when it is not added here, the display is incomplete.
                        std::cout << "O ";
                        break;
                    case 2:
                        std::cout << "X ";
                        break;
                    case 3:
                        std::cout << "S ";
                        break;
                }
            }
            std::cout << "\n";
    }
    std::cout << "\nPlayer 2\n";
    for (const auto& i : s2) {
            for (int j : i) {
                switch(j){
                    case 0:
                    case 1:
                        std::cout << "O ";
                        break;
                    case 2:
                        std::cout << "X ";
                        break;
                    case 3:
                        std::cout << "S ";
                        break;
                }
            }
            std::cout << "\n";
    }
}
