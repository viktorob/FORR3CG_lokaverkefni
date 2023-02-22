#include "Tolva.h"

Tolva::Tolva() {
    this->kaupar = -1;
}

Tolva::Tolva(int kaupar, int audkenni, int verdmaeti, int stadsetning) : Bunadur(audkenni, verdmaeti, stadsetning) {
    this->kaupar = kaupar;
}

int Tolva::get_kaupar() {
    return this->kaupar;
}

int Tolva::set_kaupar(int nytt_kaupar) {
    this->kaupar = nytt_kaupar;
}

void Tolva::prenta() {
    //KLÁRA
    std::cout << "Tölva";
}

std::string Tolva::getType() {
    return "tolva";
}
