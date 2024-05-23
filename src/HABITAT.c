/**
 * @file ./src/HABITAT.c
 * @description Habitat için kaynak kod dosyası
 * @course 1. öğretim A grubu
 * @assignment 2. Ödev
 * @date 03.05.2024
 * @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "HABITAT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor
Habitat olusturHabitat()
{

    Habitat this;

    this = (struct HABITAT *)malloc(sizeof(struct HABITAT));

    this->yemeKontrol = &yemeKontrol;
    this->silHabitat = &silHabitat;

    return this;
}

void yemeKontrol(Canli canli1, Canli canli2)
{
    // Bitki ise kıyaslama
    if (strcmp(canli1->gorunum(), "B") == 0)
    {
        // İkinci canlı ihtimalleri
        // Böcek
        if (strcmp(canli2->gorunum(), "C") == 0)
        {
            canli1->sayi = 0;
        }
        // Pire
        else if (strcmp(canli2->gorunum(), "P") == 0)
        {
            canli2->sayi = 0;
        }
        // Sinek
        else if (strcmp(canli2->gorunum(), "S") == 0)
        {
            canli2->sayi = 0;
        }
        // Bitki
        else if (strcmp(canli2->gorunum(), "B") == 0)
        {
            if (canli1->sayi == canli2->sayi)
            {
                if (canli1->x > canli2->x || canli1->y > canli2->y)
                {
                    canli1->sayi = 0;
                }

                else
                    canli2->sayi = 0;
            }

            else if (canli1->sayi > canli2->sayi)
            {
                canli2->sayi = 0;
            }

            else
                canli1->sayi = 0;
        }
    }

    // Böcek ise kıyaslama
    else if (strcmp(canli1->gorunum(), "C") == 0)
    {
        // İkinci canlı ihtimalleri
        // Bitki
        if (strcmp(canli2->gorunum(), "B") == 0)
        {
            canli2->sayi = 0;
        }
        // Pire
        else if (strcmp(canli2->gorunum(), "P") == 0)
        {
            canli2->sayi = 0;
        }
        // Sinek
        else if (strcmp(canli2->gorunum(), "S") == 0)
        {
            canli1->sayi = 0;
        }
        // Böcek
        else if (strcmp(canli2->gorunum(), "C") == 0)
        {
            if (canli1->sayi == canli2->sayi)
            {
                if (canli1->x > canli2->x || canli1->y > canli2->y)
                {
                    canli1->sayi = 0;
                }

                else
                    canli2->sayi = 0;
            }

            else if (canli1->sayi > canli2->sayi)
            {
                canli2->sayi = 0;
            }

            else
                canli1->sayi = 0;
        }
    }

    // Pire ile kıyaslama
    else if (strcmp(canli1->gorunum(), "P") == 0)
    {
        // İkinci canlı ihtimalleri
        // Bitki
        if (strcmp(canli2->gorunum(), "B") == 0)
        {
            canli1->sayi = 0;
        }
        // Böcek
        else if (strcmp(canli2->gorunum(), "C") == 0)
        {
            canli1->sayi = 0;
        }
        // Sinek
        else if (strcmp(canli2->gorunum(), "S") == 0)
        {
            canli1->sayi = 0;
        }
        // Pire
        else if (strcmp(canli2->gorunum(), "P") == 0)
        {
            if (canli1->sayi == canli2->sayi)
            {
                if (canli1->x > canli2->x || canli1->y > canli2->y)
                {
                    canli1->sayi = 0;
                }

                else
                    canli2->sayi = 0;
            }

            else if (canli1->sayi > canli2->sayi)
            {
                canli2->sayi = 0;
            }

            else
                canli1->sayi = 0;
        }
    }

    // Sinek ise kıyaslama
    else if (strcmp(canli1->gorunum(), "S") == 0)
    {
        // İkinci canlı ihtimalleri
        // Böcek
        if (strcmp(canli2->gorunum(), "C") == 0)
        {
            canli2->sayi = 0;
        }
        // Pire
        else if (strcmp(canli2->gorunum(), "P") == 0)
        {
            canli2->sayi = 0;
        }
        // Bitki
        else if (strcmp(canli2->gorunum(), "B") == 0)
        {
            canli1->sayi = 0;
        }
        // Sinek
        else if (strcmp(canli2->gorunum(), "S") == 0)
        {
            if (canli1->sayi == canli2->sayi)
            {
                if (canli1->x > canli2->x || canli1->y > canli2->y)
                {
                    canli1->sayi = 0;
                }

                else
                    canli2->sayi = 0;
            }

            else if (canli1->sayi > canli2->sayi)
            {
                canli2->sayi = 0;
            }

            else
                canli1->sayi = 0;
        }
    }
}

// Distructor
void silHabitat(struct HABITAT *Habitat)
{
    free(Habitat);
}