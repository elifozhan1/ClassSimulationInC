/** 
* @file ./include/BITKI.h
* @description Bitki için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef BITKI_H
#define BITKI_H

#include "CANLI.h"
#include <stdlib.h>

struct BITKI {
    Canli super;

    struct BITKI* (*olusturBitki)();
    void (*silBitki)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki olusturBitki();
char* gorunumBitki();
void silBitki(Bitki);

#endif