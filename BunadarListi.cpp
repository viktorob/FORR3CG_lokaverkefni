#include "BunadarListi.h"

int BunadarListi::BunadarListi::hash(int audkenni) { // flækja meira (aukastig)
    return audkenni % this->staerd;
}

BunadarListi::BunadarListi() {
    this->staerd = 10;
    this->heads = new BunadarNode*[this->staerd]();
}

BunadarListi::BunadarListi(int staerd) {
    this->staerd = staerd;
    this->heads = new BunadarNode*[this->staerd]();
}

void BunadarListi::skra_bunad(Bunadur* bun) {
    int idx = this->hash(bun->get_audkenni());
    BunadarNode* new_bun = new BunadarNode(bun);
    if (!this->heads[idx]) { // ef nullptr (listi er tómur)
        this->heads[idx] = new_bun; // setur búnaðinn í listann
    } else { // ef listinn er ekki tómur
        if (*this->heads[idx]->bun >= *bun) { // ef búnaðurinn sem er til staðar (núverandi stak) er stærri eða jafn stór og nýji búnaðurinn
            new_bun->next = this->heads[idx];
            this->heads[idx] = new_bun;
        } else { // ef stakið í listanum mini en nýja stakið
            BunadarNode* current = this->heads[idx];
            BunadarNode* prev = this->heads[idx];
            while(current && *current->bun <= *bun) { //fer í gegnum listann á meðan stakið er minna eða jafnt og nýja stakið
                prev = current;
                current = current->next;
            }
            if (current) {
                new_bun->next = current;
                prev->next = new_bun;
            } else {
                prev->next = new_bun;
            }
        }
    }
}

void BunadarListi::skra_bord(int saeta_fjoldi, int audkenni, int verdmaeti, int stadsetning) {
    this->skra_bunad(new Bord(saeta_fjoldi, audkenni, verdmaeti, stadsetning));
}

void BunadarListi::skra_stol(std::string tegund, int audkenni, int verdmaeti, int stadsetning) {
    this->skra_bunad(new Stoll(tegund, audkenni, verdmaeti, stadsetning));
}

void BunadarListi::skra_skjavarpa(int lumen, int audkenni, int verdmaeti, int stadsetning) {
    this->skra_bunad(new Skjavarpi(lumen, audkenni, verdmaeti, stadsetning));
}

void BunadarListi::skra_tolvu(int kaupar, int audkenni, int verdmaeti, int stadsetning) {
    this->skra_bunad(new Tolva(kaupar, audkenni, verdmaeti, stadsetning));
}

void BunadarListi::skoda_bunad(int audkenni) {

}

void BunadarListi::eyda_bunadi(int audkenni) {

}

void BunadarListi::breyta_stadsetningu(int audkenni, int ny_stadsetning) {

}

void BunadarListi::prenta_i_husi(int hus) {

}

void BunadarListi::prenta_allt() {

}
