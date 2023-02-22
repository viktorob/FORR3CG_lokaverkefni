#include "Skjavarpi.h"

Skjavarpi::Skjavarpi() {
    this->lumen = -1;
}

Skjavarpi::Skjavarpi(int lumen, int audkenni, int verdmaeti, int stadsetning) : Bunadur(audkenni, verdmaeti, stadsetning) {
    this->lumen = lumen;
}

int Skjavarpi::get_lumen() {
    return this->lumen;
}

void Skjavarpi::set_lumen(int ny_lumen) {
    this->lumen = ny_lumen;
}

void Skjavarpi::prenta() {
    //KLÁRA
    std::cout << "Skjávarpi";
}

std::string Skjavarpi::getType() {
    return "skjavarpi";
}
