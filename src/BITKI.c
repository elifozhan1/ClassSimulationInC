/** 
* @file ./src/BITKI.c
* @description Bitki için kaynak kod dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#include "BITKI.h"

// Constructor
Bitki olusturBitki()
{
    Bitki this;

    this = (struct BITKI*)malloc(sizeof(struct BITKI));

    this->super = olusturCanli(0, 0, 0);
    this->super->gorunum = &gorunumBitki;
    this->silBitki = &silBitki;
    
    return this;
}

char* gorunumBitki()
{
    return "B";
}

// Distructor
void silBitki(struct BITKI* Bitki)
{
    if(Bitki == NULL)   return;
    Bitki->super->silCanli(Bitki->super);
    free(Bitki);
}