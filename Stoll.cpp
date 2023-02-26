#include "Stoll.h"

Stoll::Stoll() {
    this->snuningur = "";
}

Stoll::Stoll(int audkenni, int stadsetning, int verdmaeti, bool snuningur) : Bunadur(audkenni, stadsetning, verdmaeti) {
    this->snuningur = snuningur;
}

bool Stoll::get_snuningur() {
    return this->snuningur;
}

void Stoll::set_tegund(bool nyr_snuningur) {
    this->snuningur = nyr_snuningur;
}

void Stoll::prenta() {
    std::string er_snuningur = "Nei";
    if(this->get_snuningur()) {
        er_snuningur = "Já";
    }
    std::cout << "Stóll, snúningur: " << er_snuningur << ", auðkenni: " << this->get_audkenni()
              << ", verðmæti: " << this->get_verdmaeti() << " kr., hús: " << this->get_hus() 
              << ", hæð: " << this->get_haed() << ", herbergi: " << this->get_herbergi()
              << "\n";
}

std::string Stoll::getType() {
    return "stoll";
}
