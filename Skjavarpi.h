#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"

class Skjavarpi : public Bunadur {
    private:
        int lumen;
    public:
        Skjavarpi();
        Skjavarpi(int lumen, int audkenni, int verdmaeti, int stadsetning);
        int get_lumen();
        void set_lumen(int ny_lumen);
        void prenta();
        std::string getType();
};
