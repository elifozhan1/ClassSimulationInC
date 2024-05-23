/** 
* @file ./src/CANLI.c
* @description Canlı için kaynak kod dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#include "CANLI.h"

#include <stdio.h>
#include <stdlib.h>

// Constructor
Canli olusturCanli(int sayi, int x, int y) {

    Canli this;

    this = (struct CANLI*)malloc(sizeof(struct CANLI));

    this->sayi = sayi;
    this->x = x;
    this->y = y;

    this->silCanli = &silCanli;

    return this;
}

// Distructor
void silCanli(const Canli canli)
{
    if(canli == NULL) return;
    free(canli);
}