/** 
* @file ./include/PIRE.h
* @description Pire için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef PIRE_H
#define PIRE_H

#include "BOCEK.h"
#include <stdlib.h>

struct PIRE {
    Bocek super;

    struct PIRE* (*olusturPire)();
    void (*silPire)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire olusturPire();
char* gorunumPire();
void silPire(Pire);

#endif