#include "Bord.h"

Bord::Bord() {
    this->saeta_fjoldi = -1;
}

Bord::Bord(int audkenni, int stadsetning, int verdmaeti, int saeta_fjoldi) : Bunadur(audkenni, stadsetning, verdmaeti) {
    this->saeta_fjoldi = saeta_fjoldi;
}

int Bord::get_saeti() {
    return this->saeta_fjoldi;
}

void Bord::set_saeti(int nyr_saeta_fjoldi) {
    this->saeta_fjoldi = nyr_saeta_fjoldi;
}

void Bord::prenta() {
    std::cout << "Borð, sætafjöldi: " << this->get_saeti() << ", auðkenni: " << this->get_audkenni()
              << ", verðmæti: " << this->get_verdmaeti() << " kr., hús: " << this->get_hus() 
              << ", hæð: " << this->get_haed() << ", herbergi: " << this->get_herbergi()
              << "\n";
}

std::string Bord::getType() {
    return "bord";
}
