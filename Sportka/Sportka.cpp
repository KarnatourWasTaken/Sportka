#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

int tah1[7], tah2[7]; //Deklarace poli aby mohli jít použít globálnì

void otevreni_cisla_v_obrazku(int cislo);
void generace_cisel_1();
void generace_cisel_2(void);

int main()
{
    int zapis[7];
    int i, j, cislo, loop = 0;
    bool unikatni;
    srand(time(NULL)); // Každé èíslo bude jiné
    printf("Zadejte cisla\n");
    for (i = 0; i < 7; i++) {
        do {
            unikatni = true;
            scanf("%d", &cislo);
            if (cislo > 49 || cislo < 0) {
            unikatni = false;
            printf("Spatne zadane cislo. Zadejte prosim cislo od 1 do 49");
            }
            for (j = 0; j < i; j++) {
                if (zapis[j] == cislo){
                    unikatni = false;
                    printf("Cislo se shoduje jiz cislem zadanym");
                }
            }
           } while (!unikatni);
        zapis[i] = cislo;
            
    }
    for (i = 0; i < 7; i++) {
        printf("%d\n", zapis[i]);
    }
    generace_cisel_1();
    system("pause");
    return 0;
}

void generace_cisel_1() {
    int i, j, x,cislo, umelecislo;
    bool unikatni;
    for (i = 0; i < 7; i++) {
        do{
        cislo = rand() % 49 + 1;
        unikatni = true;
        for (j = 0; j < i; j++) {
            if (tah1[j] == cislo) unikatni = false;
        }
        } while (!unikatni);
        tah1[i] = cislo;
        printf("%d\n", tah1[i]);
        otevreni_cisla_v_obrazku(tah1[i]);
       for (x = 0; x < 5; x++) {
            umelecislo = rand() % 49 + 1;
            printf("   %d   ", umelecislo);
            Sleep(100);
        }
       printf("%d\n", tah1[i]);
    }
}



void otevreni_cisla_v_obrazku(int cislo) {

    int c;
    char soubor[10];
    sprintf(soubor, "%d.txt",cislo);
    FILE* file;
    file = fopen(soubor, "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}





