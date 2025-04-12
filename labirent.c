#include <stdio.h>
#include <math.h>

// Struct 
typedef struct {
    int x;
    int y;
    double mesafe;
}
Kisi;
double oklidMesafesiHesapla(int x1, int y1, int x2, int y2);
double manhattanMesafesiHesapla(int x1, int y1, int x2, int y2);
void enYakinVeEnUzakKisiyiBul(Kisi kisiler[], int sayi, Kisi *enYakin, Kisi *enUzak);

int main() {
    int genislik, yukseklik, kisiSayisi, i, secim;
    int kullaniciX, kullaniciY, tespitMesafesi;
    Kisi kisiler[100]; // Max kişi
    // Kullanıcıdan Verileri al
    printf("Labirent genişliği: ");
    scanf("%d", &genislik);
    printf("Labirent yüksekliği: ");
    scanf("%d", &yukseklik);
    printf("Labirentte kaç kişi var? ");
    scanf("%d", &kisiSayisi);
    for (i = 0; i < kisiSayisi; i++) {
        printf("Kişi %d koordinatları (x y): ", i + 1);
        scanf("%d %d", &kisiler[i].x, &kisiler[i].y);
    }
    printf("Kendi konumunuz (x y): ");
    scanf("%d %d", &kullaniciX, &kullaniciY);
    printf("Tespit mesafesi: ");
    scanf("%d", &tespitMesafesi);
    printf("Uzaklık metodu seçiniz (1: Öklid, 2: Manhattan): ");
    scanf("%d", &secim);
    printf("Sizin noktanız: (%d, %d)\n", kullaniciX, kullaniciY);
    printf("Etrafınızdaki kişiler (%d mesafe içinde olanlar):\n", tespitMesafesi);
    for (i = 0; i < kisiSayisi; i++) {
        if (secim == 1) {
            kisiler[i].mesafe = oklidMesafesiHesapla(kullaniciX, kullaniciY, kisiler[i].x, kisiler[i].y);
        } else {
            kisiler[i].mesafe = manhattanMesafesiHesapla(kullaniciX, kullaniciY, kisiler[i].x, kisiler[i].y);
        }
        if (kisiler[i].mesafe <= tespitMesafesi) {
            printf("Kişi %d: (%d, %d) - Uzaklık: %.2f\n", i + 1, kisiler[i].x, kisiler[i].y, kisiler[i].mesafe);
        }
    }
    Kisi enYakin, enUzak;
    enYakinVeEnUzakKisiyiBul(kisiler, kisiSayisi, &enYakin, &enUzak);
    printf("En yakın kişi: (%d, %d) - Uzaklık: %.2f\n", enYakin.x, enYakin.y, enYakin.mesafe);
    printf("En uzak kişi: (%d, %d) - Uzaklık: %.2f\n", enUzak.x, enUzak.y, enUzak.mesafe);

    return 0;
}

// Öklid
double oklidMesafesiHesapla(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Manhattan
double manhattanMesafesiHesapla(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void enYakinVeEnUzakKisiyiBul(Kisi kisiler[], int sayi, Kisi *enYakin, Kisi *enUzak) {
    int i;
    enYakin->mesafe = enUzak->mesafe = kisiler[0].mesafe;
    enYakin->x = enUzak->x = kisiler[0].x;
    enYakin->y = enUzak->y = kisiler[0].y;

    for (i = 1; i < sayi; i++) {
        if (kisiler[i].mesafe < enYakin->mesafe) {
            enYakin->mesafe = kisiler[i].mesafe;
            enYakin->x = kisiler[i].x;
            enYakin->y = kisiler[i].y;
        }
        if (kisiler[i].mesafe > enUzak->mesafe) {
            enUzak->mesafe = kisiler[i].mesafe;
            enUzak->x = kisiler[i].x;
            enUzak->y = kisiler[i].y;
        }
    }
}
