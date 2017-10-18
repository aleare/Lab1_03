#include "Librerie/libreria_principale.h" //Gli include sono già inclusi nella libreria...
//Costanti:
#define MAX_RIGHE 30
#define MAX_PAROLA 20
#define MAX_RIGA 200

int main() {
    //Variabili:
    FILE *f1;
    FILE *f2;
    FILE *o;
    int r = 0;
    char parola[MAX_PAROLA];
    int x = 0;
    char ch;
    int i = 0;
    char sost[MAX_PAROLA][MAX_PAROLA] = {' '};
    char riga[MAX_RIGA] = {'\0'};
    //Programma:
    printf("LABORATORIO 1 ES 3:\n");
    //Apertura Files...
    printf("Primo file:\n");
    f1 = FILE_apri_file(FILENAME_MAX, "r");
    printf("Secondo file:\n");
    f2 = FILE_apri_file(FILENAME_MAX, "r");
    printf("File di destinazione:\n");
    o = FILE_apri_file(FILENAME_MAX, "w");
    //Lettura di sost.
    fscanf(f2, " %d ", &r);
    for (int i = 0; i < r; ++i) {
        if (feof(f2)) exit(EXIT_FAILURE);
        fscanf(f2, " %d %s", &x, parola);
        strcpy(sost[x], parola);
    }
    x = 0; //Azzero x che uso anche dopo nel programma
    for (int j = 0; j < MAX_PAROLA; ++j) { //Azzero la parola
        parola[j] = '\0';
    }
    while (fgets(riga, MAX_RIGA, f1) != NULL) { //Fino alla fine del file
        for (i = 0; riga[i] != '\n' && riga[i] != '\0'; ++i) { //Vai fino alla fine della riga o del testo...
            ch = riga[i];
            if (isalpha(ch)) { //creo la parola
                parola[x] = ch;
                x++;
            } else { //ho trovato una parola, eseguo le operazioni su di essa
                if (sost[x][0] == '\0') fprintf(o, "%s", parola); //sost[0][0] preimpostata a ' '
                else if (x == 0);
                else fprintf(o, "%s", sost[x]);
                for (int j = 0; parola[j] != '\0'; ++j) { //Azzero la parola
                    parola[j] = '\0';
                }
                fputc(ch, o);
                x = 0;
            }
        } //Resetto la parola alla fine della riga-->NON SERVE DATO CHE LEGGO SEMPRE \n\r ALLA FINE DELLA RIGA
    }
    //Chiusura dei Files...
    fclose(f1);
    fclose(f2);
    fclose(o);
    return EXIT_SUCCESS;
}