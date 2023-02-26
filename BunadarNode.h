#pragma once

#include "Bunadur.h"

struct BunadarNode {
    Bunadur* bun;
    BunadarNode* next;

    BunadarNode(Bunadur* bun) {
        this->bun = bun;
        this->next = nullptr;
    }
};