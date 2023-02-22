#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"

class Stoll : public Bunadur {
    private:
        std::string tegund;
    public:
        Stoll();
        Stoll(std::string tegund, int audkenni, int verdmaeti, int stadsetning);
        std::string get_tegund();
        void set_tegund(std::string ny_tegund);
        void prenta();
        std::string getType();
};