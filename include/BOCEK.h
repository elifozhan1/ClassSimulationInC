/** 
* @file ./include/BOCEK.h
* @description Böcek için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef BOCEK_H
#define BOCEK_H

#include "CANLI.h"
#include <stdlib.h>

struct BOCEK {
    Canli super;

    struct BOCEK* (*olusturBocek)();
    void (*silBocek)(struct BOCEK*);
    
};

typedef struct BOCEK* Bocek;

Bocek olusturBocek();
char* gorunumBocek();
void silBocek(Bocek);

#endif