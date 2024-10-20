#include "Arduino.h"
#include "nethelperlib.h"

#include <stdlib.h>
#include<string.h>

const char *lobby[] = {
    "File DV6",
    "Password DV6",
    "Password DV8",
    "Skunk",
    "Wisp",
    "Killer"
};

// Struttura basici
const char *basici[] = {
    "Sabertooth",
    "Raven x2",
    "Hellhound",
    "Wisp",
    "Raven",
    "Password DV6",
    "File DV6",
    "Control Node",
    "Password DV6",
    "Skunk",
    "Asp",
    "Scorpion",
    "Killer, Skunk",
    "Wisp x3",
    "Liche"
};

// Struttura normale
const char *normale[] = {
    "Hellhound x2",
    "Hellhound, Killer",
    "Skunk x2",
    "Sabertooth",
    "Scorpion",
    "Hellhound",
    "Password DV8",
    "File DV8",
    "Control Node DV8",
    "Password DV8",
    "Asp",
    "Killer",
    "Liche",
    "Asp",
    "Raven x3",
    "Liche, Raven"
};

// Struttura discreti
const char *discreti[] = {
    "Kraken",
    "Hellhound, Scorpion",
    "Hellhound, Killer",
    "Raven x2",
    "Sabertooth",
    "Hellhound",
    "Password DV10",
    "File DV10",
    "Control Node DV10",
    "Password DV10",
    "Killer",
    "Liche",
    "Dragon",
    "Asp, Raven",
    "Dragon, Wisp",
    "Giant"
};

// Struttura avanzati
const char *avanzati[] = {
    "Hellhound x3",
    "Asp x2",
    "Hellhound, Liche",
    "Wisp x3",
    "Hellhound, Sabertooth",
    "Kraken",
    "Password DV12",
    "File DV12",
    "Control Node DV12",
    "Password DV12",
    "Giant",
    "Dragon",
    "Killer, Scorpion",
    "Kraken",
    "Raven, Wisp, Hellhound",
    "Dragon x2"
};


static uint8_t NetHelperLib::rollD6(){
    // rand() % (max - min + 1) + min;
    return rand() % (6);      // Returns a pseudo-random integer between 0 and RAND_MAX.
}
static uint8_t NetHelperLib::roll3D6(){
    return rand() % (16);      // Returns a pseudo-random integer between 0 and RAND_MAX.
}
static uint8_t NetHelperLib::rollD10(){
    // rand() % (max - min + 1) + min;
    return rand() % (10);      // Returns a pseudo-random integer between 0 and RAND_MAX.
}

char * NetHelperLib::generaPiano(char piano, char diff, char* branchId){
    // return str(piano)+idBranch+ " " + incontroPiano
    char *incontroPiano = (char*)malloc(10*sizeof(char));
    if(piano <= 2){
        // piano lobby
        strcpy(incontroPiano, lobby[rollD6()]);
    }else{
        char roll = roll3D6();
        switch (diff) {
            
            case 1 :
                strcpy(incontroPiano, normale[roll]);
                break;
            case 2 :
                strcpy(incontroPiano, discreti[roll]);
                break;
            case 3 :
                strcpy(incontroPiano, avanzati[roll]);
                break;
            default: 
                strcpy(incontroPiano, basici[roll]);
                break;
        }
    }
    char * buffer = (char*) malloc((22+6)*sizeof(char));
    sprintf(buffer, ("%d%s: %s"), piano,branchId,incontroPiano);
    free(incontroPiano);
    return buffer;
}

char** NetHelperLib::generaPiani(char numPiani,  char diff, char numeroDiramazioni){
    // resituisce un array di char contente i piani
    // alloca spazio per tutti i piani
    char** arr = malloc(numPiani*sizeof(char*));
    char i = 0;
    while(i <= numPiani ){
        if(rollD10() == 9){
            // dirama
            // n seguenti hanno etichetta "a"
            // quelli seguenti (tutti ) etichetta b
            uint8_t n = (numPiani-i)/2;
            uint8_t x = 0;
            for(; x < n; x++){
                //genero i piani
                arr[i] =generaPiano(i, diff, ("|a")); 
                i++;
            }
            x = 0;
            for(; x <= n; x++){
                //genero i piani
                arr[i] =generaPiano(i, diff, ("|b")); 
                i++;
            }
        }else{
            arr[i] =generaPiano(i, diff, ""); 
            i++;
        }
    }

    return arr;
}