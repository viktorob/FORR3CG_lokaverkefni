#include "Bunadur.h"

Bunadur::Bunadur() {
    this->audkenni = -1;
    this->verdmaeti = -1;
    this->stadsetning[0] = -1;
    
}

Bunadur::Bunadur(int audkenni, int verdmaeti, int stadsetning) {
    this->audkenni = audkenni;
    this->verdmaeti = verdmaeti;
    set_stadsetning(stadsetning);
}

int Bunadur::get_audkenni() {
    return this->audkenni;
}

void Bunadur::set_audkenni(int nytt_audkenni) {
    this->audkenni = nytt_audkenni;
}

int Bunadur::get_verdmaeti() {
    return this->verdmaeti;
}

void Bunadur::set_verdmaeti(int nytt_verdmaeti) {
    this->verdmaeti = nytt_verdmaeti;
}

int Bunadur::get_stadsetning() {
    //SKOÐA BETUR
    return this->stadsetning[0] * 1000 + this->stadsetning[1] * 100 + this->stadsetning[2];
}

void Bunadur::set_stadsetning(int ny_stadsetning) {
    //Hús fundið og sett í fylkið
    this->stadsetning[0] = ny_stadsetning / 1000;
    //Hæð fundin og sett í fylkið
    this->stadsetning[1] = (ny_stadsetning - this->stadsetning[0] * 1000) / 100;
    //Herbergi fundið og sett í fylkið
    this->stadsetning[2] = (ny_stadsetning % 100);
}

int Bunadur::get_hus() {
    return this->stadsetning[0];
}

void Bunadur::set_hus(int nytt_hus) {
    this->stadsetning[0] = nytt_hus;
}

int Bunadur::get_haed() {
    return this->stadsetning[1];
}

void Bunadur::set_haed(int ny_haed) {
    this->stadsetning[1] = ny_haed;
}

int Bunadur::get_herbergi() {
    return this->stadsetning[2];
}

void Bunadur::set_herbergi(int nytt_herbergi) {
    this->stadsetning[2] = nytt_herbergi;
}

void Bunadur::prenta() {
    std::cout << "Búnaður, auðkenni: " << std::to_string(this->get_audkenni()) << ", verðmæti: " 
              << std::to_string(this->get_verdmaeti()) << ", hús: " << std::to_string(this->get_hus()) 
              << ", hæð:" << std::to_string(this->get_haed()) << ", herbergi: " << std::to_string(this->get_herbergi()) 
              << "\n";
}

std::string Bunadur::getType() {
    return "dýr";
}

bool Bunadur::operator<(Bunadur& hinn) {
    return this->get_verdmaeti() < hinn.get_verdmaeti();
}

bool Bunadur::operator>(Bunadur& hinn) {
    return hinn < *this;
}

bool Bunadur::operator<=(Bunadur& hinn) {
    return !(*this > hinn);
}

bool Bunadur::operator>=(Bunadur& hinn) {
    return !(*this < hinn);
}
