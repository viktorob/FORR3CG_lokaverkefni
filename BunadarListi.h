#pragma once

#include <iostream>
#include <string>

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
        int hash(int staerd);//gera betra (sem aukakröfu)
    public:
        BunadarListi();
        BunadarListi(int audkenni);
        //BunadarListi(BunadarListi& gamli); aukakrafa
        //BunadarListi& operator=(BunadarListi& gamli); aukakrafa
        void skra_bunad(Bunadur* bun);
        void skra_bord(int saeta_fjoldi, int audkenni, int verdmaeti, int stadsetning);
        void skra_stol(std::string tegund, int audkenni, int verdmaeti, int stadsetning);
        void skra_skjavarpa(int lumen, int audkenni, int verdmaeti, int stadsetning);
        void skra_tolvu(int kaupar, int audkenni, int verdmaeti, int stadsetning);
        void skoda_bunad(int audkenni);
        void eyda_bunadi(int audkenni);
        void breyta_stadsetningu(int audkenni, int ny_stadsetning);
        void prenta_i_husi(int hus);
        void prenta_allt();

};