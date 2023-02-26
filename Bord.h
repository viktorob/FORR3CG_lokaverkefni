#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"

class Bord : public Bunadur {
    private:
        int saeta_fjoldi;
    public:
        Bord();
        Bord(int audkenni, int stadsetning, int verdmaeti, int saeta_fjoldi);
        int get_saeti();
        void set_saeti(int nyr_saeta_fjoldi);
        void prenta();
        std::string getType();
};