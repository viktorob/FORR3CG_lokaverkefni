#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"

class Tolva : public Bunadur {
    private:
        int kaupar;
    public:
        Tolva();
        Tolva(int kaupar, int audkenni, int verdmaeti, int stadsetning);
        int get_kaupar();
        int set_kaupar(int nytt_kaupar);
        void prenta();
        std::string getType();
};