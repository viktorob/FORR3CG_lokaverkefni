#include "Tolva.h"

Tolva::Tolva() {
    this->kaupar = -1;
}

Tolva::Tolva(int audkenni, int stadsetning, int verdmaeti, int kaupar) : Bunadur(audkenni, stadsetning, verdmaeti) {
    this->kaupar = kaupar;
}

int Tolva::get_kaupar() {
    return this->kaupar;
}

void Tolva::set_kaupar(int nytt_kaupar) {
    this->kaupar = nytt_kaupar;
}

void Tolva::prenta() {
    std::cout << "Tölva, kaupár: " << this->get_kaupar() << ", auðkenni: " << this->get_audkenni()
              << ", verðmæti: " << this->get_verdmaeti() << " kr., hús: " << this->get_hus() 
              << ", hæð: " << this->get_haed() << ", herbergi: " << this->get_herbergi()
              << "\n";
}

std::string Tolva::getType() {
    return "tolva";
}
