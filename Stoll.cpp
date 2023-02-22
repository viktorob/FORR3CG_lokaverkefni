#include "Stoll.h"

Stoll::Stoll() {
    this->tegund = "";
}

Stoll::Stoll(std::string tegund, int audkenni, int verdmaeti, int stadsetning) : Bunadur(audkenni, verdmaeti, stadsetning) {
    this->tegund = tegund;
}

std::string Stoll::get_tegund() {
    return this->tegund;
}

void Stoll::set_tegund(std::string ny_tegund) {
    this->tegund = ny_tegund;
}

void Stoll::prenta() {
    //KLÁRA
    std::cout << "Stóll";
}

std::string Stoll::getType() {
    return "stoll";
}
