int IfDigit(const std::string* ciN, int* Int, int* Intermediate){
    static int Imcounter = 0;
    for(char c : *ciN) {
        if (!isdigit(c)) {
            Imcounter++;
            if(Imcounter > 10 && Imcounter <= 20)
                std::cout << "Are you an imbecile?\n";
            else if(Imcounter > 20 && Imcounter <= 30){
                std::cout << "Are you an imbecile?\n";
                std::cout << "If you keep it up a little longer...\n";
            }
            else if(Imcounter > 40)
                std::cout << "\n\n\n\n\n\n\nWhat are you doing? STOP!\n\n\n\n\n\n\n";
            return ++*Intermediate;
        }
    }
    return *Int = stoi(*ciN);

}
