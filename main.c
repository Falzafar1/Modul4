#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HitungKarakter(){
    char kata[100]="";
    char kalimat[100]="";
    char x[100]="";
    int totalhuruf=0;

    fgets(x, sizeof(x), stdin);
    strcpy(kalimat, x);
    strcpy(kata, strtok(x," "));

    while (strlen(kalimat)>1){
        totalhuruf = totalhuruf*10 + strlen(kata);
        memmove(kalimat, kalimat + strlen(kata)+1, strlen(kalimat + strlen(kata)) + 1);
        if (strcmp(kalimat,"") != 0){
            strcpy(kata, strtok(NULL," "));
        }
    }
    return totalhuruf-1;
}

int FPB(int x, int y){
    if (y==0){
        return x;
    }
    else{
        return FPB(y, x % y);
    }
}

int main() {
    int i,j;
    int jam, hasilkurang;
    
    printf("Pesan Koko Ang: ");
    i= HitungKarakter();  
    printf("Balasan: ");
    j= HitungKarakter();

    jam = FPB (i, j);
    hasilkurang = jam - 24;

    if ((jam%24) <=24 && jam != 1 && i !=1 && j !=1){
        if (hasilkurang > 0){
            printf("Besok nonton jam %d skuy", (jam % 24));
        }
        else{
            printf("Besok ke kebun binatang jam %d skuy", jam);
        }

    }
    else{
        printf("Ditolak nih\nPadam abangkuh :(");
    }
    
    return 0;
}
