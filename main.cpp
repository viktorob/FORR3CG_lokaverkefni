// Viktor Óli Bjarkason
// FORR3CG - Lokaverkefni
// Innsláttur
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "BunadarListi.h"
#include "rlutil.h"

// Villumeðhöndlun
// Tekur inn orðið sem skilst ekki (strengur)
// Prentar villumeldingu
void skil_ekki(std::string ordid) {
    rlutil::setColor(rlutil::RED);
    std::cout << "Villa, skil ekki orðið: " << ordid << "!\n";
    rlutil::setColor(rlutil::BLUE);
}

int main() {
    rlutil::saveDefaultColor();
    rlutil::setConsoleTitle("FORR3CG Lokaverkefni - Viktor");
    rlutil::setColor(rlutil::BLUE);
    std::cout << "Viktor Óli Bjarkason\n";
    std::cout << "FORR3CG Lokaverkefni\n";
    std::cout << "--------------------\n";
    
    rlutil::setColor(rlutil::GREEN);
    std::cout << "Velkomin/n\n\n";
    rlutil::setColor(rlutil::BLUE);

    BunadarListi bl;
    /*
    // PRÓFUNARGÖGN eru útfærð í gogn.txt
    // nóg að skrifa bara "lesa" og þá eru gögnin úr gogn.txt lesin inn (prófunargögnin)
    */

    //ATH: þótt listinn sé raðaður prentast hann ekki þannig því ég þarf að útfæra það í prenta_allt fallinu líka (auka)
    
    std::string inntak, skipun, gerd, er_snuningur, prentun, skraarheiti, lesa_bara;
    int audkenni, stadsetning, verdmaeti, saeta_fjoldi, lumen, kaupar, ny_stadsetning, hus, haed, herbergi;
    bool snuningur;

    do {
        rlutil::setColor(rlutil::BLUE);
        std::cout << "Sláðu inn skipun: ";
        rlutil::resetColor();
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
                std::cout << "Staðsetningu búnaðar nr. " << audkenni << " breytt\n";
            } else {
                rlutil::setColor(rlutil::RED);
                std::cout << "Villa, ekki tókst að uppfæra staðsetningu búnaðar nr. " << audkenni << "\n";
            }
        } else if(skipun == "eyða") {
            ss >> audkenni;
            //eyðir búnaði og prentar hvort það tókst eða ekki
            if(bl.eyda_bunadi(audkenni)) {
                rlutil::setColor(rlutil::GREEN);
                std::cout << "Búnaði nr. " << audkenni << " eytt\n";
            } else {
                rlutil::setColor(rlutil::RED);
                std::cout << "Villa, ekki tókst að eyða búnaði nr. " << audkenni << "!\n";
            }
        } else if(skipun == "vista") {
                // ef ekki annað orð þá er skráarheitið t.d. listi.txt
                // annars er orð nr 2 skráarheitið
                ss >> skraarheiti;
                if(skraarheiti.length() == 0) {
                    skraarheiti = "gogn";
                }
                if(!bl.skrifa_i_skra(skraarheiti)) {
                    rlutil::setColor(rlutil::RED);
                    std::cout << "Villa, ekki tókst að vista gögn!\n";
                } else {
                    rlutil::setColor(rlutil::GREEN);
                    std::cout << "Gögn vistuð.\n";
                }
            } else if(skipun == "lesa") { // lesa úr skrá
                ss >> skraarheiti >> lesa_bara;
                if(skraarheiti.length() == 0) { // ef notandi valdi skráarheiti sjálfur
                    skraarheiti = "gogn";
                }
                bl = bl.lesa_ur_skra(skraarheiti);
                rlutil::setColor(rlutil::GREEN);
                std::cout << "Gögn lesin inn úr " << skraarheiti << ".txt\n";
                
            } else if(skipun == "prenta") {
                ss >> prentun;
            if(prentun == "allt") {
                rlutil::setColor(rlutil::YELLOW);
                // reynir að prenta en ef listi er tómur prentar villu
                if(!bl.prenta_allt()) {
                    rlutil::setColor(rlutil::RED);
                    std::cout << "Villa, ekkert til að prenta!\n";
                }
                
            } else if(prentun == "hús") {
                ss >> hus;
                rlutil::setColor(rlutil::YELLOW);
                bl.prenta_i_husi(hus);
                
            } else if(prentun == "id") {
                ss >> audkenni;
                rlutil::setColor(rlutil::YELLOW);
                // prentar eftir auðkenni frá notanda og prentar villumeldingu ef fann ekki auðkennið
                if(!bl.prenta_eftir_audkenni(audkenni)) {
                    rlutil::setColor(rlutil::RED);
                    std::cout << "Villa, fann ekki búnað nr. " << audkenni << "!\n";
                }
                
            } else if(prentun == "stað") {
                ss >> hus >> haed >> herbergi;
                rlutil::setColor(rlutil::YELLOW);
                // prentar búnað á stað sem notandi valdi og prentar villu ef enginn finnst
                if(!bl.prenta_a_sama_stad(hus, haed, herbergi)) {
                    rlutil::setColor(rlutil::RED);
                    std::cout << "Villa, enginn búnaður fannst í húsi " << hus << ", hæð " << haed << ", herbergi " << herbergi << "!\n";
                }
                
            } else if(prentun == "borð") {
                rlutil::setColor(rlutil::YELLOW);
                bl.prenta_bord();
            } else if(prentun == "stóla") {
                rlutil::setColor(rlutil::YELLOW);
                bl.prenta_stola();
            } else if(prentun == "skjávarpa") {
                rlutil::setColor(rlutil::YELLOW);
                bl.prenta_skjavarpa();
            } else if(prentun == "tölvur") {
                rlutil::setColor(rlutil::YELLOW);
                bl.prenta_tolvur();
            } else if(prentun == "skrá") {
                BunadarListi bl2;
                ss >> skraarheiti;
                if(skraarheiti.length() == 0) {
                    skraarheiti = "gogn";
                }
                bl2 = bl.lesa_ur_skra(skraarheiti);
                rlutil::setColor(rlutil::YELLOW);
                bl2.prenta_allt();
            } else {
                skil_ekki(prentun);
            }

        } else if(skipun != "hætta") {
            skil_ekki(skipun);
        }

    } while(skipun!= "hætta");
    rlutil::setColor(rlutil::GREEN);
    std::cout << "Sjáumst síðar!\n";
    return 0;
}
// Útsláttur