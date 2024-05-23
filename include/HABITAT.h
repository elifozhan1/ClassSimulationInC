/** 
* @file ./include/HABITAT.h
* @description Habitat için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef HABITAT_H
#define HABITAT_H

#include "BITKI.h"
#include "BOCEK.h"
#include "CANLI.h"
#include "PIRE.h"
#include "SINEK.h"
#include <stdlib.h>

struct HABITAT {

    struct HABITAT* (*olusturHabitat)();
    void(*yemeKontrol)(Canli, Canli);
    void (*silHabitat)(struct HABITAT*);
    
};

typedef struct HABITAT* Habitat;

Habitat olusturHabitat();
void yemeKontrol(Canli, Canli);
void silHabitat(Habitat);

#endif