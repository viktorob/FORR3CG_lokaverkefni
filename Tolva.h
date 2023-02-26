#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"

class Tolva : public Bunadur {
    private:
        int kaupar;
    public:
        Tolva();
        Tolva(int audkenni, int stadsetning, int verdmaeti, int kaupar);
        int get_kaupar();
        int set_kaupar(int nytt_kaupar);
        void prenta();
        std::string getType();
};