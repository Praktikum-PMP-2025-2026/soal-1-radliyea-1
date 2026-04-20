//Amelia Rahma Nurradliyah
//EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026 
//Modul : 2 - Data Manipulation and External Files 
//Soal : soal1 
//Hari dan Tanggal : Senin, 20 April 2026
//Pembuat : Amelia Rahma Nurradliyah
//NIM : 13224020
//Deskripsi : mengerjakan soal 1 dimana perintahnya mendeteksi sensor badai untuk mengirimkan data intensitas angin secara berkala.

#include <stdio.h>
 
//input data sebelum dipakai tim analisis
int main(){
    int m;
    int a[m];
    scanf("%d",&m);
     //input pulihkan elemen array yang hilang lalu cari jumlah subbray maks
    for (int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++){
        if (a[i] == -1){
            int kiri = -1, kanan = -1;
            //jika hanya kiri ada pakai kiri berarti harus nyari kiri terdekatnya
            for (int j = i - 1; j >= 0; j--){
                if (a[j] != -1){
                    kiri = a[j];
                    break;
                }
            }
            //jika hanya kanan ada pakai kanan berarti harus nyari kanan terdekatnya
            for (int j = i + 1; j < m; j++){
                if (a[j] != -1){
                    kanan = a[j];
                    break;
                }
            }
            //nilai pengganti dari kanan dan kiri
            if (kiri != -1 && kanan != -1){
                a[i] = (kiri + kanan) / 2;
            } else if (kiri != -1) {
                a[i] = kiri;
            } else if (kanan != -1) {
                a[i] = kanan;
            } else {
                a[i] = 0;
            }
        }
    }
    //print recovered setelah semua elemen dipulihkan done, dan dihitung nantinya
    printf("RECOVERED ");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    //hitung jumlah maks dari semua subbray kontigu non kosong nya
    int max_sum = a[0];
    int current = a[0];
    for (int i = 1; i < m; i++) {
        if (current + a[i] > a[i]) {
            current = current + a[i];
        } else {
            current = a[i];
        }
        if (current > max_sum) {
            max_sum = current;
        }
    }
    printf("MAX_SUM %d\n", max_sum);
    return 0;
}
