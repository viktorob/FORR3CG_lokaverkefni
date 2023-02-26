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

BunadarListi::BunadarListi(BunadarListi& gamli) {
    this->staerd = gamli.staerd;
    this->heads = new BunadarNode*[this->staerd]();
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* gamli_current = gamli.heads[idx];
        while(gamli_current) {
            if(gamli_current->bun->getType() == "bord") {
                Bord* b = (Bord*)gamli_current->bun; // typecastar búnaðarpointer í borðapointer
                this->skra_bunad(new Bord(b->get_audkenni(), b->get_stadsetning(), b->get_verdmaeti(), b->get_saeti()));
            } else if(gamli_current->bun->getType() == "stoll") {
                Stoll* s = (Stoll*)gamli_current->bun; // typecastar búnaðarpointer í stólapointer
                this->skra_bunad(new Stoll(s->get_audkenni(), s->get_stadsetning(), s->get_verdmaeti(), s->get_snuningur()));
            } else if(gamli_current->bun->getType() == "skjavarpi") {
                Skjavarpi* sv = (Skjavarpi*)gamli_current->bun; // typecastar búnaðarpointer í skjávarpapointer
                this->skra_bunad(new Skjavarpi(sv->get_audkenni(), sv->get_stadsetning(), sv->get_verdmaeti(), sv->get_lumen()));
            } else if(gamli_current->bun->getType() == "tolva") {
                Tolva* t = (Tolva*)gamli_current->bun; // typecastar búnaðarpointer í tölvupointer
                this->skra_bunad(new Tolva(t->get_audkenni(), t->get_stadsetning(), t->get_verdmaeti(), t->get_kaupar()));
            }
            gamli_current = gamli_current->next;
        }
    }
}

BunadarListi& BunadarListi::operator=(BunadarListi& gamli) {
    this->staerd = gamli.staerd;
    this->heads = new BunadarNode*[this->staerd]();
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* gamli_current = gamli.heads[idx];
        while(gamli_current) {
            if(gamli_current->bun->getType() == "bord") {
                Bord* b = (Bord*)gamli_current->bun; // typecastar búnaðarpointer í borðapointer
                this->skra_bunad(new Bord(b->get_audkenni(), b->get_stadsetning(), b->get_verdmaeti(), b->get_saeti()));
            } else if(gamli_current->bun->getType() == "stoll") {
                Stoll* s = (Stoll*)gamli_current->bun; // typecastar búnaðarpointer í stólapointer
                this->skra_bunad(new Stoll(s->get_audkenni(), s->get_stadsetning(), s->get_verdmaeti(), s->get_snuningur()));
            } else if(gamli_current->bun->getType() == "skjavarpi") {
                Skjavarpi* sv = (Skjavarpi*)gamli_current->bun; // typecastar búnaðarpointer í skjávarpapointer
                this->skra_bunad(new Skjavarpi(sv->get_audkenni(), sv->get_stadsetning(), sv->get_verdmaeti(), sv->get_lumen()));
            } else if(gamli_current->bun->getType() == "tolva") {
                Tolva* t = (Tolva*)gamli_current->bun; // typecastar búnaðarpointer í tölvupointer
                this->skra_bunad(new Tolva(t->get_audkenni(), t->get_stadsetning(), t->get_verdmaeti(), t->get_kaupar()));
            }
            gamli_current = gamli_current->next;
        }
    }
    return *this;
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

void BunadarListi::skra_bunad(int audkenni, int stadsetning, int verdmaeti) {
    this->skra_bunad(new Bunadur(audkenni, stadsetning, verdmaeti));
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
            return true;
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
            current = current->next;
        }
    }
}

bool BunadarListi::prenta_eftir_audkenni(int audkenni) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if (current->bun->get_audkenni() == audkenni) {
                current->bun->prenta();
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void BunadarListi::prenta_bord() {
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if(current->bun->getType() == "bord") {
                current->bun->prenta();
            }
            current = current->next;
        }
    }
}

void BunadarListi::prenta_stola() {
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if(current->bun->getType() == "stoll") {
                current->bun->prenta();
            }
            current = current->next;
        }
    }
}

void BunadarListi::prenta_skjavarpa() {
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if(current->bun->getType() == "skjavarpi") {
                current->bun->prenta();
            }
            current = current->next;
        }
    }
}

void BunadarListi::prenta_tolvur() {
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            if(current->bun->getType() == "tolva") {
                current->bun->prenta();
            }
            current = current->next;
        }
    }
}

bool BunadarListi::prenta_a_sama_stad(int hus, int haed, int herbergi) {
    bool fannst = false;
    for(int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            // ef hús, hæð og herbergi er það sama
            if(current->bun->get_hus() == hus && current->bun->get_haed() == haed && current->bun->get_herbergi() == herbergi) {
                current->bun->prenta();
                fannst = true;
            }
            current = current->next;
        }
    }
    return fannst;
}

bool BunadarListi::prenta_allt() {
    bool fannst = false;
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadarNode* current = this->heads[idx];
        while(current) {
            current->bun->prenta();
            current = current->next;
            fannst = true;
        }
    }
    return fannst;
}

// Les úr skrá sem notandi velur og breytir því sem er í henni í objecta og setur í Búnaðarlista
// tekur inn skráarheiti
// skilar pointer á BunadarLista með gögnunum í skránni
BunadarListi& BunadarListi::lesa_ur_skra(std::string skraarheiti) {
    std::ifstream lesa(skraarheiti+".txt");
    BunadarListi* bl = new BunadarListi;

    if(!lesa) {
        return *bl; // skilar pointer á tóman BunadarLista
    } else {
        std::string gerd;
        int audkenni, stadsetning, verdmaeti, saeta_fjoldi, lumen, kaupar;
        bool snuningur;
        // les úr skránni og býr til object eftir hvernig týpa gögnin eru
        while(lesa >> gerd >> audkenni >> stadsetning >> verdmaeti) {
            if(gerd == "bord") {
                lesa >> saeta_fjoldi;
                bl->skra_bord(audkenni, stadsetning, verdmaeti, saeta_fjoldi);
            } else if(gerd == "stoll") {
                lesa >> snuningur;
                bl->skra_stol(audkenni, stadsetning, verdmaeti, snuningur);
            } else if(gerd == "skjavarpi") {
                lesa >> lumen;
                bl->skra_skjavarpa(audkenni, stadsetning, verdmaeti, lumen);
            } else if(gerd == "tolva") {
                lesa >> kaupar;
                bl->skra_tolvu(audkenni, stadsetning, verdmaeti, kaupar);
            } else { // ef bara búnaður
                bl->skra_bunad(audkenni, stadsetning, verdmaeti);
            }
        }
    }
    return *bl;
}

bool BunadarListi::skrifa_i_skra(std::string skraarheiti) {
    std::ofstream skrifa(skraarheiti+".txt");

    if(!skrifa) {
        return false;
    } else {
        for(int idx = 0; idx < this->staerd; idx++) {
            BunadarNode* current = this->heads[idx];
            while(current) {
                //skrifa í skránna
                skrifa << current->bun->getType() << " " << current->bun->get_audkenni() << " " << current->bun->get_stadsetning() << " " << current->bun->get_verdmaeti();
                if(current->bun->getType() == "bord") {
                    Bord* b = (Bord*)current->bun; // typecastar búnaðarpointer í borðapointer
                    skrifa << " " << b->get_saeti() << "\n";

                } else if(current->bun->getType() == "stoll") {
                    Stoll* s = (Stoll*)current->bun; // typecastar búnaðarpointer í borðapointer
                    skrifa << " " << s->get_snuningur() << "\n";

                } else if(current->bun->getType() == "skjavarpi") {
                    Skjavarpi* sk = (Skjavarpi*)current->bun; // typecastar búnaðarpointer í borðapointer
                    skrifa << " " << sk->get_lumen() << "\n";

                } else if(current->bun->getType() == "tolva") {
                    Tolva* t = (Tolva*)current->bun; // typecastar búnaðarpointer í borðapointer
                    skrifa << " " << t->get_kaupar() << "\n";

                }
                current = current->next;
            }
        }
    }
    skrifa.close();
    return true;
}
