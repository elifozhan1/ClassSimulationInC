/**
 * @file ./src/TEST.c
 * @description Test için kaynak kod dosyası
 * @course 1. öğretim A grubu
 * @assignment 2. Ödev
 * @date 03.05.2024
 * @author Elif Özhan elif.ozhan1@ogr.sakarya.edu.tr
 */

#include "CANLI.h"
#include "HABITAT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Object;

int main()
{
    Canli *canlilar = NULL; // Canli türünde bir dinamik dizi
    Object* canlilarTur = NULL;
    int canli_sayisi = 0;
    int max_canli_sayisi = 1000;

    int satir_sayaci = 0;
    int sutun_sayaci = 0;
    int sayi;

    FILE *file = fopen("veri.txt", "r");

    if (file == NULL)
    {
        fprintf(stderr, "Dosya acilamadi\n");
        return 1;
    }

    canlilar = (Canli *)malloc(max_canli_sayisi * sizeof(Canli));
    canlilarTur = (Object*)malloc(max_canli_sayisi * sizeof(Object));
    if (canlilar == NULL)
    {
        fprintf(stderr, "Bellek ayirma basarisiz\n");
        return 1;
    }

    while (fscanf(file, "%d", &sayi) != EOF)
    {
        if (canli_sayisi >= max_canli_sayisi)
        {
            // Dizi boyutunu artır
            max_canli_sayisi *= 2;
            canlilar = (Canli*)realloc(canlilar, max_canli_sayisi * sizeof(Canli));
            canlilarTur = (Object*)realloc(canlilar, max_canli_sayisi * sizeof(Object));
            if (canlilar == NULL)
            {
                fprintf(stderr, "Bellek ayirma basarisiz\n");
                return 1;
            }
        }

        // Gelen sayıya göre canlı oluşturur
        if (sayi >= 1 && sayi <= 9)
        {
            Bitki bitki = olusturBitki();
            bitki->super->sayi = sayi;
            bitki->super->x = satir_sayaci;
            bitki->super->y = sutun_sayaci;
            canlilar[canli_sayisi] = bitki->super;
            canlilarTur[canli_sayisi] = bitki;
        }

        else if (sayi >= 10 && sayi <= 20)
        {
            Bocek bocek = olusturBocek();
            bocek->super->sayi = sayi;
            bocek->super->x = satir_sayaci;
            bocek->super->y = sutun_sayaci;
            canlilar[canli_sayisi] = bocek->super;
            canlilarTur[canli_sayisi] = bocek;
        }

        else if (sayi >= 21 && sayi <= 50)
        {
            Sinek sinek = olusturSinek();
            sinek->super->super->sayi = sayi;
            sinek->super->super->x = satir_sayaci;
            sinek->super->super->y = sutun_sayaci;
            canlilar[canli_sayisi] = sinek->super->super;
            canlilarTur[canli_sayisi] = sinek;
        }

        else if (sayi >= 51 && sayi <= 99)
        {
            Pire pire = olusturPire();
            pire->super->super->sayi = sayi;
            pire->super->super->x = satir_sayaci;
            pire->super->super->y = sutun_sayaci;
            canlilar[canli_sayisi] = pire->super->super;
            canlilarTur[canli_sayisi] = pire;
        }

        if (fgetc(file) == '\n')
        {
            printf("\n");
            satir_sayaci++;
            sutun_sayaci = 0;
        }

        else
        {
            sutun_sayaci++;
        }
        
        canli_sayisi++;
    }

    fclose(file);

    // Yazdır
    for (int i = 0; i < satir_sayaci + 1; i++)
    {
        for (int j = 0; j < sutun_sayaci; j++)
        {
            printf("%s ", canlilar[i * sutun_sayaci + j]->gorunum());
        }

        printf("\n");
    }

    printf("\n\nProgramin calismaya devam etmesi icin herhangi bir tusa basin.\n");
    getchar();

    Habitat habitat = olusturHabitat();
    Canli canli1 = canlilar[0];
    Canli canli2 = canlilar[1];

    Canli kazanan = canlilar[0];

    for (int i = 0; i < ((satir_sayaci + 1) * sutun_sayaci - 1); i++)
    {
        system("CLS");
        habitat->yemeKontrol(canli1, canli2);

        for (int k = 0; k < satir_sayaci + 1; k++)
        {
            for (int j = 0; j < sutun_sayaci; j++)
            {
                if (canlilar[k * sutun_sayaci + j]->sayi == 0)
                    printf("X ");
                else
                    printf("%s ", canlilar[k * sutun_sayaci + j]->gorunum());
            }

            printf("\n");
        }

        if (canli1->sayi == 0)
        {
            canli1 = canli2;
        }
        
        if(i+2 <= ((satir_sayaci + 1) * sutun_sayaci - 1))
        {
            canli2 = canlilar[i + 2];
        }
        else    break;

        kazanan = canli1;
    }

    printf("Kazanan: %s (%d, %d)", kazanan->gorunum(), kazanan->x, kazanan->y);

    for (int i = 0; i < canli_sayisi; i++)
    {
        if(strcmp(canlilar[i]->gorunum(),"B") == 0)
        {
            Bitki bitki = (Bitki)canlilarTur[i];
            bitki->silBitki(bitki);
        }
        
        if(strcmp(canlilar[i]->gorunum(),"C") == 0)
        {
            Bocek bocek = (Bocek)canlilarTur[i];
            bocek->silBocek(bocek);
        }
        
        if(strcmp(canlilar[i]->gorunum(), "S") == 0)
        {
            Sinek sinek = (Sinek)canlilarTur[i];
            sinek->silSinek(sinek);
        }
        
        if(strcmp(canlilar[i]->gorunum(), "P") == 0)
        {
            Pire pire = (Pire)canlilarTur[i];
            pire->silPire(pire);
        }
    }

    silHabitat(habitat);
    free(canlilar);

    return 0;
}