#include "Librerie/libreria_principale.h"
#define MAX_RIGHE 30
#define MAX_PAROLA 20

int main() {
    FILE *f1; FILE *f2; int r=0;
    char parola[MAX_PAROLA]; int x=0;
    char sost[MAX_PAROLA][MAX_PAROLA]={0,0};
    printf("LABORATORIO 1 ES 3:\n");
    //Apertura Files...
    printf("Primo file:\n");
    f1=FILE_apri_file(FILENAME_MAX,"r");
    printf("Secondo file:\n");
    f2=FILE_apri_file(FILENAME_MAX,"r");
    //Lettura di sost.
    fscanf(f2," %d ",&r);
    for (int i = 0; i < r; ++i) {
        fscanf(f2," %d %s",&x,parola);
        strcpy(sost[x],parola);
        if (feof(f2)) exit(EXIT_FAILURE);
    }
    return 0;
}


