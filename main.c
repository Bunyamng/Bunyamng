#include <stdio.h>
#include <string.h>

#define MAX_URUN 100

typedef struct {
    char kod[10];
    char isim[50];
    float fiyat;
    int stok;
    int aktif;
} Urun;

Urun urunler[MAX_URUN];
int urun_sayisi = 0;

void kod_uret(char *kod, int index) {
    sprintf(kod, "U%03d", index + 1);
}

void urun_ekleme() {
    if (urun_sayisi >= MAX_URUN) {
        printf("Maksimum urun sayisina ulasaildi!\n");
        return;
    }

    Urun yeni;
    kod_uret(yeni.kod, urun_sayisi);

    printf("Urun Adi: ");
    scanf(" %[^\n]", yeni.isim);
    printf("Fiyat: ");
    scanf("%f", &yeni.fiyat);
    printf("Stok: ");
    scanf("%d", &yeni.stok);

    yeni.aktif = 1;
    urunler[urun_sayisi++] = yeni;

    printf("Urun eklendi! Urun kodu: %s\n", yeni.kod);
}

void urun_listele() {
    printf("\n--- Urun Listesi ---\n");
    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].aktif) {
            printf("Kod: %s | Ad: %s | Fiyat: %.2f TL | Stok: %d\n",
                   urunler[i].kod, urunler[i].isim, urunler[i].fiyat, urunler[i].stok);
        }
    }
}

void urun_guncelleme() {
    char kod[10];
    printf("Guncellenecek urun kodunu girin: ");
    scanf("%s", kod);

    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].aktif && strcmp(urunler[i].kod, kod) == 0) {
            printf("Yeni ad: ");
            scanf(" %[^\n]", urunler[i].isim);
            printf("Yeni fiyat: ");
            scanf("%f", &urunler[i].fiyat);
            printf("Yeni stok: ");
            scanf("%d", &urunler[i].stok);
            printf("Urun guncellendi.\n");
            return;
        }
    }
    printf("Urun bulunamadi.\n");
}

void urun_silme() {
    char kod[10];
    printf("Silinecek urun kodunu girin: ");
    scanf("%s", kod);

    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].aktif && strcmp(urunler[i].kod, kod) == 0) {
            urunler[i].aktif = 0;
            printf("Urun silindi.\n");
            return;
        }
    }
    printf("Urun bulunamadi.\n");
}

int main() {
    int secim;

    do {
        printf("\n--- Urun Ýsleme Sistemi ---\n");
        printf("1. Urun Ekleme\n");
        printf("2. Urunleri Göster\n");
        printf("3. Urun Guncelleme\n");
        printf("4. Urun Silme\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: urun_ekleme(); break;
            case 2: urun_listele(); break;
            case 3: urun_guncelleme(); break;
            case 4: urun_silme(); break;
            case 0: printf("Programdan cikiliyor...\n"); break;
            default: printf("Hatali Secim.\n");
        }
    } while (secim != 0);

    return 0;
}
