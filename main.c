/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : Recursion
 *   Hari dan Tanggal    : Senin, 18 Maret 2024
 *   Nama (NIM)          : Naufal Afiq Muzaffar (13222025)
 *   Nama File           : main.c
 *   Deskripsi           : Menentukan apakah Koko Aang dan kekasihnya akan pergi dan di jam berapa bergantung dengan
 *                         pesan yang dikirim dengan menghitung panjang karakter pada kedua kalimat kata dan dilakukan
 *                         FPB kepada keduanya.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int HitungKarakter(char *x){

    int totalangka=0;
    int ambilangka=0;
    char ParsedWords[8][100]={};
    int count=0;
    int j;

    //Menghitung jumlah spasi  
    for ( j = 0; j < strlen(x); j++){
        if (x[j] == ' '){
            count +=1;
        }
    }

    //Memisahkan setiap kata pada kalimat 
    strcpy(ParsedWords[0],strtok(x," "));
    for (j = 0; j < count; j++){
        strcpy(ParsedWords[j+1], strtok(NULL," "));
    }

    // Mendapatkan jumlah karakterpada kata
    for (j = 0; j < count+1; j++){
        ambilangka = strlen(ParsedWords[j]);
        totalangka = totalangka*10 + ambilangka;
    }
    return totalangka;
}

// Rekursi FPB 
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
    int x;
    int hasilmod;
    char pesan[100];

    printf("Pesan Koko Ang: ");
    fgets(pesan, sizeof(pesan), stdin);
    i = HitungKarakter(pesan);
    printf("Balasan: ");
    fgets(pesan, sizeof(pesan), stdin);
    j = HitungKarakter(pesan);

    //FPB 
    x = FPB(i-1,j-1);

    hasilmod = x % 24;

    if (hasilmod <=24 && hasilmod != 1){
        printf("Besok ke kebun binatang jam %d skuy", hasilmod);
    }
    else{
        printf("Ditolak nih\nPadam abangkuh :(");
    }
    return 0;
}
