#pragma once
#include <iostream>
#include <string>

#include "Bunadur.h"

class Stoll : public Bunadur {
    private:
        bool snuningur;
    public:
        Stoll();
        Stoll(int audkenni, int stadsetning, int verdmaeti, bool snuningur);
        bool get_snuningur();
        void set_tegund(bool nyr_snuningur);
        void prenta();
        std::string getType();
};