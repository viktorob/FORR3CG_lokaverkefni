// Innsláttur
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "BunadarListi.h"
#include "rlutil.h"

// Villumeðhöndlun
// Tekur inn orðið sem skilst ekki (strengur)
// Prentar villumeldingu
void skil_ekki(std::string ordid) {
    rlutil::setColor(rlutil::RED);
    std::cout << "Villa, skil ekki orðið: " << ordid << "!\n";
    rlutil::resetColor();
}

// COMMANDS
// TÝPA = borð, stóll, skjávarpi og tölva
// AUKA = sætafjöldi, snúningur, lúmen, kaupár

// SKRÁ búnað - syntax
// skrá TÝPA {auðkenni} {stadsetning} {verðmæti} {AUKA}
// Dæmi: skrá borð 501 21209 1000 4

// EYÐA búnaði - syntax
// eyða {auðkenni}
// Dæmi: eyða 501

// UPPFÆRA staðsetningu búnaðar
// uppfæra {auðkenni} {ný staðsetning}
// Dæmi: uppfæra 501 23250

// PRENTA búnað eftir auðkenni
// prenta id {auðkenni}
// Dæmi: prenta 501

// PRENTA búnað eftir húsi
// prenta hús {hús}
// Dæmi: prenta hús 09



int main() {
    rlutil::saveDefaultColor();

    BunadarListi bl;
    
    // PRÓFUNARGÖGN
    bl.skra_bord(501, 21209, 1000, 4);
    bl.skra_bord(502, 10410, 2000, 2);
    bl.skra_stol(503, 21209, 4000, 0);
    bl.skra_stol(504, 21209, 4000, 0);
    bl.skra_skjavarpa(505, 10410, 100000, 4000);
    bl.skra_skjavarpa(506, 21209, 100000, 4000);
    bl.skra_tolvu(507, 21209, 50000, 2019);
    bl.skra_tolvu(508, 21209, 50000, 2019);
    bl.skra_tolvu(509, 21209, 50000, 2019);
    bl.skra_tolvu(510, 21209, 50000, 2019);

    //ATH: þótt listinn sé raðaður prentast hann ekki þannig því ég þarf að útfæra það í prenta_allt fallinu líka (auka)
    
    std::string inntak, skipun, gerd, er_snuningur, prentun;
    int audkenni, stadsetning, verdmaeti, saeta_fjoldi, lumen, kaupar, ny_stadsetning, hus;
    bool snuningur;

    do {
        std::cout << "Sláðu inn skipun: ";
        std::getline(std::cin, inntak); // les inntak frá notanda inn í inntaks breytuna
        std::stringstream ss;
        ss << inntak;
        ss >> skipun;
        if (skipun == "skrá") {
            ss >> gerd >> audkenni >> stadsetning >> verdmaeti; //les orðin inn í breytur
            if(gerd == "borð") {
                ss >> saeta_fjoldi; // les sætafjölda í breytu
                bl.skra_bord(audkenni, stadsetning, verdmaeti, saeta_fjoldi);
            } else if(gerd == "stól") {
                ss >> er_snuningur;
                snuningur = false;
                // þýðir inntak frá notanda (já/nei) yfir í boolean gildi (true/false)
                if(er_snuningur == "já" || er_snuningur == "Já" || er_snuningur == "ja" || er_snuningur == "JÁ" || er_snuningur == "JA") {
                    snuningur = true;
                }
                bl.skra_stol(audkenni, stadsetning, verdmaeti, snuningur);
            } else if(gerd == "skjávarpa") {
                ss >> lumen;
                bl.skra_skjavarpa(audkenni, stadsetning, verdmaeti, lumen);
            } else if(gerd == "tölvu") {
                ss >> kaupar;
                bl.skra_tolvu(audkenni, stadsetning, verdmaeti, kaupar);
            }

        } else if(skipun == "uppfæra") {
            ss >> audkenni >> ny_stadsetning;
            // breytir staðsetningu búnaðar og lætur notanda vita hvort það tókst
            if(bl.breyta_stadsetningu(audkenni, ny_stadsetning)) {
                rlutil::setColor(rlutil::GREEN);
                std::cout << "Staðsetningu búnaðar nr. " << audkenni << " breytt";
                rlutil::resetColor();
            } else {
                rlutil::setColor(rlutil::RED);
                std::cout << "Ekki tókst að uppfæra staðsetningu búnaðar nr. " << audkenni;
                rlutil::resetColor();
            }
        } else if(skipun == "eyða") {
            ss >> audkenni;
            //eyðir búnaði og prentar hvort það tókst eða ekki
            if(bl.eyda_bunadi(audkenni)) {
                rlutil::setColor(rlutil::GREEN);
                std::cout << "Búnaði nr. " << audkenni << " eytt\n";
                rlutil::resetColor();
            } else {
                rlutil::setColor(rlutil::RED);
                std::cout << "Ekki tókst að eyða búnaði nr. " << audkenni;
                rlutil::resetColor();
            }
            
        } else if(skipun == "prenta") {
            ss >> prentun;
            //útfæra allt prenta dót hér
            if(prentun == "allt") {
                rlutil::setColor(rlutil::BLUE);
                bl.prenta_allt();
                rlutil::resetColor();
            } else if(prentun == "hús") {
                ss >> hus;
                rlutil::setColor(rlutil::BLUE);
                bl.prenta_i_husi(hus);
                rlutil::resetColor();
            } else if(prentun == "id") {
                ss >> audkenni;
                rlutil::setColor(rlutil::BLUE);
                bl.prenta_eftir_audkenni(audkenni);
                rlutil::resetColor();
            }
        } else if(skipun != "hætta") {
            skil_ekki(skipun);
        }



    } while(skipun!= "hætta");

    

    return 0;
}
// Útsláttur