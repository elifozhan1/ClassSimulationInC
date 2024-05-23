/** 
* @file ./src/SINEK.c
* @description Sinek için kaynak kod dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#include "SINEK.h"

// Constructor
Sinek olusturSinek()
{
    Sinek this;

    this = (struct SINEK*)malloc(sizeof(struct SINEK));

    this->super = olusturBocek(0,0,0);
    this->super->super->gorunum = &gorunumSinek;
    this->silSinek = &silSinek;

    return this;
}

char* gorunumSinek()
{
    return "S";
}

// Distructor
void silSinek(struct SINEK* Sinek)
{
    if(Sinek == NULL)   return;
    Sinek->super->silBocek(Sinek->super);
    free(Sinek);
}