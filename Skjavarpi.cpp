#include "Skjavarpi.h"

Skjavarpi::Skjavarpi() {
    this->lumen = -1;
}

Skjavarpi::Skjavarpi(int audkenni, int stadsetning, int verdmaeti, int lumen) : Bunadur(audkenni, stadsetning, verdmaeti) {
    this->lumen = lumen;
}

int Skjavarpi::get_lumen() {
    return this->lumen;
}

void Skjavarpi::set_lumen(int ny_lumen) {
    this->lumen = ny_lumen;
}

void Skjavarpi::prenta() {
    std::cout << "Skjávarpi, lúmen: " << this->get_lumen() << ", auðkenni: " << this->get_audkenni()
              << ", verðmæti: " << this->get_verdmaeti() << " kr., hús: " << this->get_hus() 
              << ", hæð: " << this->get_haed() << ", herbergi: " << this->get_herbergi()
              << "\n";
}

std::string Skjavarpi::getType() {
    return "skjavarpi";
}
