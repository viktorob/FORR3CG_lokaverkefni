#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Bunadur.h"
#include "Bord.h"
#include "Stoll.h"
#include "Skjavarpi.h"
#include "Tolva.h"
#include "BunadarNode.h"

class BunadarListi {
    private:
        BunadarNode** heads;
        int staerd;
        int hash(int audkenni);//gera betra (sem aukakröfu)
    public:
        BunadarListi();
        BunadarListi(int staerd);
        BunadarListi(BunadarListi& gamli); //aukakrafa
        BunadarListi& operator=(BunadarListi& gamli); //aukakrafa
        void skra_bunad(Bunadur* bun);
        void skra_bunad(int audkenni, int stadsetning, int verdmaeti);
        void skra_bord(int audkenni, int stadsetning, int verdmaeti, int saeta_fjoldi);
        void skra_stol(int audkenni, int stadsetning, int verdmaeti, bool snuningur);
        void skra_skjavarpa(int audkenni, int stadsetning, int verdmaeti, int lumen);
        void skra_tolvu(int audkenni, int stadsetning, int verdmaeti, int kaupar);
        bool skoda_bunad(int audkenni);
        bool eyda_bunadi(int audkenni);
        bool breyta_stadsetningu(int audkenni, int ny_stadsetning);
        void prenta_i_husi(int hus);
        bool prenta_eftir_audkenni(int audkenni);
        void prenta_bord();
        void prenta_stola();
        void prenta_skjavarpa();
        void prenta_tolvur();
        bool prenta_a_sama_stad(int hus, int haed, int herbergi);
        bool prenta_allt();
        BunadarListi& lesa_ur_skra(std::string skraarheiti);
        bool skrifa_i_skra(std::string skraarheiti);
};