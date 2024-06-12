/*Programma che prende in input 10 numeri e li inserisce in un array di interi e tramite altre due funzioni inserite nel main stampa e riordina*/



#include<stdio.h>
#define SIZE 5 // se si deve dichiarare in maniera statica la lunghezza dell'array conviene sempre definirla come variabile globlale
#define SIZE_BUFF 100 // definisco una variabile globale per un buffer


void bof() {
    int vector[5], i, j, k; // buffer overflow in quanto il programmatore dichiare un array di 5 interi
    int swap_var;

    printf("Inserire 5 interi:\n");

    for (i = 0; i < 10; i++) { // ma il ciclo itera fino a 10 causando scrivendo in spazi di memoria non consentiti dal programmatore
        int c = i + 1;
        printf("[%d]: ", c);
        scanf("%d", &vector[i]);
    }

    printf("Il vettore inserito e':\n");
    for (i = 0; i < 5; i++) {
        int t = i + 1;
        printf("[%s]: %s\n", t, vector[i]);  //cambio nel print il variabile da stampare per creare il segmentation fault, quindi passo da interi a stringa
    }

    for (j = 0; j < 5 - 1; j++) {
        for (k = 0; k < 5 - j - 1; k++) {
            if (vector[k] > vector[k + 1]) {
                swap_var = vector[k];
                vector[k] = vector[k + 1];
                vector[k + 1] = swap_var;
            }
        }
    }

    printf("Il vettore ordinato e':\n");
    for (j = 0; j < 5; j++) {
        int g = j + 1;
        printf("[%d]: %d\n", g, vector[j]);
    }
}
void nobof() {
    int vector[SIZE], i, j, k;
    int swap_var;
    int input;

    printf("Inserire %d numeri interi:\n", SIZE);

    for (i = 0; i < SIZE; i++) {
        int c = i + 1;
        printf("[%d]: ", c);

       
        char buffer[SIZE_BUFF]; // inizializzo un buffer che tramite i due cicli if verifichera gli input dall'utente
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Errore durante la lettura dell'input.\n");
            return;
        }

        if (sscanf(buffer, "%d", &input) != 1) {
            printf("Input non valido. Riprova.\n");
            i--;
            continue;
        }

        vector[i] = input;
    }

    printf("Il vettore inserito e':\n");
    for (i = 0; i < SIZE; i++) {
        int t = i + 1;
        printf("[%d]: %d\n", t, vector[i]);
    }

    for (j = 0; j < SIZE - 1; j++) {
        for (k = 0; k < SIZE - j - 1; k++) {
            if (vector[k] > vector[k + 1]) {
                swap_var = vector[k];
                vector[k] = vector[k + 1];
                vector[k + 1] = swap_var;
            }
        }
    }

    printf("Il vettore ordinato e':\n");
    for (j = 0; j < SIZE; j++) {
        int g = j + 1;
        printf("[%d]: %d\n", g, vector[j]);
    }
}




int main(){
    int scelta;
    
    do {
        printf("1) Per avviare il bof\n");
        printf("2) Per inserire il codice corretto\n");
        printf("3) Esci dal programma\n");

        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                printf("bof\n");
                bof();
                break;
            case 2:
                printf("programma 2\n");
                nobof();
                break;
            case 3:
                printf("esco dal programma\n");
                break;
            default:
                printf("Inserisci una scelta valida....\n");
        } 
    } while(scelta != 3);
    
    return 0;
}



