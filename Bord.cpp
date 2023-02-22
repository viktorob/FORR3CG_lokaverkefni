#include "Bord.h"

Bord::Bord() {
    this->saeta_fjoldi = -1;
}

Bord::Bord(int saeta_fjoldi, int audkenni, int verdmaeti, int stadsetning) : Bunadur(audkenni, verdmaeti, stadsetning) {
    this->saeta_fjoldi = saeta_fjoldi;
}

int Bord::get_saeti() {
    return this->saeta_fjoldi;
}

void Bord::set_saeti(int nyr_saeta_fjoldi) {
    this->saeta_fjoldi = nyr_saeta_fjoldi;
}

void Bord::prenta() {
    std::cout << "Borð, sætafjöldi: " << std::to_string(this->get_saeti()) << ", auðkenni: " << std::to_string(this->get_audkenni())
              << ", verðmæti: " << std::to_string(this->get_verdmaeti()) << " kr., staðsetning: " << std::to_string(this->get_stadsetning())
              << "\n";
}

std::string Bord::getType() {
    return "bord";
}
