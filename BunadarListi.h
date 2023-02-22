#pragma once

#include <iostream>
#include <string>

#include "Bunadur.h"
#include "Bord.h"
#include "Stoll.h"
#include "Tolva.h"
#include "BunadarNode.h"

class BunadarListi {
    private:
        BunadarNode** heads;
        int staerd;
        int hash();//tekur inn eih gildi (bæta við)
    public:
        BunadarListi();
        BunadarListi(int staerd);
        BunadarListi(Bunadur& gamli);
        Bunadur& operator=(BunadarListi& gamli);
};