/** 
* @file ./src/PIRE.c
* @description Pire için kaynak kod dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#include "PIRE.h"

// Constructor
Pire olusturPire()
{
    Pire this;

    this = (struct PIRE*)malloc(sizeof(struct PIRE));

    this->super = olusturBocek(0,0,0);
    this->super->super->gorunum = &gorunumPire;
    this->silPire = &silPire;
    
    return this;
}

char* gorunumPire()
{
    return "P";
}

// Distructor
void silPire(struct PIRE* Pire)
{
    if(Pire == NULL) return;
    Pire->super->silBocek(Pire->super);
    free(Pire);
}