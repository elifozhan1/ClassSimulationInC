/** 
* @file ./include/SINEK.h
* @description Sinek için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef SINEK_H
#define SINEK_H

#include "BOCEK.h"
#include <stdlib.h>

struct SINEK {
    Bocek super;

    struct SINEK* (*olusturSinek)();
    void (*silSinek)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek olusturSinek();
char* gorunumSinek();
void silSinek(Sinek);

#endif