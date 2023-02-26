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
        } else { // ef stakið í listanum minni en nýja stakið
            BunadarNode* current = this->heads[idx];
            BunadarNode* prev = this->heads[idx];
            while(current && *current->bun <= *bun) { //fer í gegnum listann á meðan stakið er minna eða jafnt og nýja stakið
                prev = current;
                current = current->next;
            }
            if (current) { // ef current er ekki nullptr
                new_bun->next = current;
                prev->next = new_bun;
            } else {
                prev->next = new_bun;
            }
        }
    }
}

void BunadarListi::skra_bord(int audkenni, int stadsetning, int verdmaeti, int saeta_fjoldi) {
    this->skra_bunad(new Bord(audkenni, stadsetning, verdmaeti, saeta_fjoldi));
}

void BunadarListi::skra_stol(int audkenni, int stadsetning, int verdmaeti, bool tegund) {
    this->skra_bunad(new Stoll(audkenni, stadsetning, verdmaeti, tegund));
}

void BunadarListi::skra_skjavarpa(int audkenni, int stadsetning, int verdmaeti, int lumen) {
    this->skra_bunad(new Skjavarpi(audkenni, stadsetning, verdmaeti, lumen));
}

void BunadarListi::skra_tolvu(int audkenni, int stadsetning, int verdmaeti, int kaupar) {
    this->skra_bunad(new Tolva(audkenni, stadsetning, verdmaeti, kaupar));
}

bool BunadarListi::skoda_bunad(int audkenni) {
    int idx = this->hash(audkenni);
    BunadarNode* current = this->heads[idx];
    while(current) { // á meðan current er ekki nullptr
        if (current->bun->get_audkenni() == audkenni) { // ef auðkenni er það sama
            current->bun->prenta(); //prentar stakið
            return true;
        }
        current = current->next; // færir current í næsta stak
    }
    return false;
}

bool BunadarListi::eyda_bunadi(int audkenni) {
    int idx = this->hash(audkenni);
    if(this->heads[idx]) { // ef listi er ekki tómur
        if(this->heads[idx]->bun->get_audkenni() == audkenni) { // ef stak með auðkenni fannst
            BunadarNode* new_head = this->heads[idx]->next;
            delete this->heads[idx];
            this->heads[idx] = new_head;
            return true;
        } else { // ef stak fannst ekki
            BunadarNode* current = this->heads[idx];
            BunadarNode* prev = this->heads[idx];
            while(current && current->bun->get_audkenni() != audkenni) { // keyrir á meðan auðkenni finnst ekki
                prev = current;
                current = current->next;
            }
            if (current) {
                prev->next = current->next;
                delete current;
                return true;
            }
        }
    }
    return false;
}

bool BunadarListi::breyta_stadsetningu(int audkenni, int ny_stadsetning) {
    int idx = this->hash(audkenni);
    if(this->heads[idx]) { // ef listi er ekki tómur
        if(this->heads[idx]->bun->get_audkenni() == audkenni) { // ef stak með auðkennið fannst og er fremst
            this->heads[idx]->bun->set_stadsetning(ny_stadsetning); // uppfærir staðsetningu
        } else { // ef stak fannst ekki
            BunadarNode* current = this->heads[idx];
            while(current && current->bun->get_audkenni() != audkenni) { // keyrir á meðan auðkenni finnst ekki
                current = current->next;
            }
            // ef stak með auðkennið fannst
            if (current) {
                current->bun->set_stadsetning(ny_stadsetning);
                return true;
            }
        }
    }
    // ef auðkenni fannst ekki
    return false;
}

void BunadarListi::prenta_i_husi(int hus) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if (current->bun->get_hus() == hus) {
                current->bun->prenta();
                return;
            }
        }
    }
}

void BunadarListi::prenta_eftir_audkenni(int audkenni) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if (current->bun->get_audkenni() == audkenni) {
                current->bun->prenta();
                return;
            }
        }
    }
}

void BunadarListi::prenta_allt() {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            current->bun->prenta();
            current = current->next;
        }
    }
}
