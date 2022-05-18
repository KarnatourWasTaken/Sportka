//TODO Zmenit barvu kulicek na zlutou

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

int zapis[7], tah1[7], tah2[7], shodnacisla[7]; //Deklarace poli aby mohli jít použít globálnì


void otevreni_cisla_v_obrazku(int cislo);
void generace_cisel_1(void);
void generace_cisel_2(void);
void porovnani_cisel(void);

int main()
{
    int i, j, cislo, poradi = 0 , loop = 0;
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
    system("cls");
    generace_cisel_1();
    printf("Vylosovana cisla prvniho tahu jsou: ");
    for (i = 0; i < 7; i++) {
        poradi++;
        if (poradi == 7) {
            printf("Dodatkove cislo je: %d",tah1[6]);
        }
        else {
            printf("%d  ", tah1[i]);
        }
    }
    Sleep(5000);
    printf("\n");
    system("pause");
    system("cls");
    poradi = 0;
    generace_cisel_2();
    printf("Vylosovana cisla druheho tahu jsou: ");
    for (i = 0; i < 7; i++) {
        poradi++;
        if (poradi == 7) {
            printf("Dodatkove cislo je: %d", tah2[6]);
        }
        else {
            printf("%d  ", tah2[i]);
        }
    }
    

    system("pause");
    return 0;
}

void generace_cisel_1() {
    int i, j, cislo;
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
        otevreni_cisla_v_obrazku(tah1[i]);
        Sleep(1500);
        system("cls");
    }
}

void generace_cisel_2() {
    int i, j, cislo;
    bool unikatni;
    for (i = 0; i < 7; i++) {
        do {
            cislo = rand() % 49 + 1;
            unikatni = true;
            for (j = 0; j < i; j++) {
                if (tah2[j] == cislo) unikatni = false;
            }
        } while (!unikatni);
        tah2[i] = cislo;
        otevreni_cisla_v_obrazku(tah2[i]);
        Sleep(1500);
        system("cls");
    }
}

void otevreni_cisla_v_obrazku(int cislo) {

    int c;
    char soubor[20];
    sprintf(soubor, ".\\cisla\\%d.txt",cislo);
    FILE* file;
    file = fopen(soubor, "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
        
        
    }
}

void porovnani_cisel() {
    int i,pocetshodnychcisel=0;
    bool dodatkovecislo;
    for (i = 0; i < 7; i++) {
        if (tah1[i] == zapis[i]) {
            shodnacisla[i] = tah1[i];
            pocetshodnychcisel++;
        }
    }


    printf("Vysledky prvniho tahu: ");
    printf("Vase tipovana cisla");
    for (i = 0; i < 7; i++) {
        printf("%d ", zapis[i]);
    }
    if (pocetshodnychcisel < 3) {
        printf("Bohuzel jste nevyhrali");
    }
    else if(pocetshodnychcisel==3)
    {
        printf("Gratulujeme k 5. mistu vase shodna cisla jsou:");
        for (i = 0; i < 3; i++) {
            printf("%d ", shodnacisla[i]);
        }
    }
    else if(pocetshodnychcisel==4)
    {
        printf("Gratulujeme k 4. mistu vase shodna cisla jsou:");
        for (i = 0; i < 4; i++) {
         printf("%d ", shodnacisla[i]);
        }
    }
    else if (pocetshodnychcisel == 5)
    {
        printf("Gratulujeme k 3. mistu vase shodna cisla jsou:");
        for (i = 0; i < 5; i++) {
            printf("%d ", shodnacisla[i]);
        }
    }
    else if (pocetshodnychcisel == 5)
    {
        printf("Gratulujeme k 4. mistu vase shodna cisla jsou:");
        for (i = 0; i < 4; i++) {
            printf("%d ", shodnacisla[i]);
        }
    }
    else if (pocetshodnychcisel == 6)
    {
        printf("Gratulujeme k 1. mistu vase shodna cisla jsou:");
        for (i = 0; i < 6; i++) {
            printf("%d ", shodnacisla[i]);
        }
    }

    for (i = 0; i < 7; i++) {
        if (tah2[i] == zapis[i]) {
            shodnacisla[i] = tah1[i];
            pocetshodnychcisel++;
        }
    }
}




