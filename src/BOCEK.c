/** 
* @file ./src/BOCEK.c
* @description Böcek için kaynak kod dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#include "BOCEK.h"

// Constructor
Bocek olusturBocek()
{
    Bocek this;

    this = (struct BOCEK*)malloc(sizeof(struct BOCEK));

    this->super = olusturCanli(0,0,0);
    this->super->gorunum = &gorunumBocek;
    this->silBocek = &silBocek;
    
    return this;
}

char* gorunumBocek()
{
    return "C";
}

// Distructor
void silBocek(struct BOCEK* Bocek)
{
    if(Bocek == NULL)   return;
    Bocek->super->silCanli(Bocek->super);
    free(Bocek);
}