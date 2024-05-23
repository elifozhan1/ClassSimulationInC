/** 
* @file ./include/CANLI.h
* @description Canlı için başlık dosyası
* @course 1. öğretim A grubu
* @assignment 2. Ödev
* @date 03.05.2024
* @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
*/

#ifndef CANLI_H
#define CANLI_H

#include <stdlib.h>

// Canlı için struct yapısı oluşturulur
struct CANLI {
    int sayi;
    int x;
    int y;

    char* (*gorunum)(); // Abstract function
    struct CANLI* (*olusturCanli)(int, int, int);
    void (*silCanli)(struct CANLI*);
};

typedef struct CANLI* Canli;

Canli olusturCanli(int, int, int);
void silCanli(const Canli);

#endif