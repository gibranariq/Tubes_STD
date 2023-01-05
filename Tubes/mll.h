#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#define info_pr(P) (P)->info_pr(P)
#define info_co(P) (P)->info_co(P)
#define next(P) (P)->next(P)
#define prev(P) (P)->prev(P)
#define next_pr(P) (P)->next_pr(P)
#define produk(P) (P)->produk(P)
#define next_relasi(P) (P)->next_relasi(P)

//parent
typedef struct infotype_co{
    string nama;
    int tahun;
}

typedef elm_co *adr_co;

typedef struct elm_co{
    infotype_co info_co;
    adr_co next;
    adr_co prev;
    next_relasi adr_relasi;
}

typedef struct list_co{
    adr_co first;
}
//relasi
typedef elm_relasi *adr_relasi;

typedef struct elm_relasi{
    adr_pr produk;
    adr_relasi next;
}


//child/produk
typedef struct infotype_pr{
        string jenis;
        string produk;
}

typedef elm_pr *adr_pr;

typedef struct elm_pr{
    infotype_pr info_pr;
    adr_pr next;
}

typedef struct list_pr{
    first adr_pr;
}

// fungsi dan procedure
void newPerusahaan(adr_co &E, infotype_co X);
void newProduk(adr_pr &E, infotype_pr X);
void newProduk(adr_relasi &E, adr_pr X);

void insertPerusahaan(list_co &L1,adr_co P);
void insertProduk(list_pr &L2,adr_pr P);

adr_co searchPerusahaan(list_co &L1, string nama);
void addProdukPerusahaan(list_co &L1 ,list_pr L2, string perusahaan, string produk);
void perusahaanProduk(list_co L,string produk);
void deletePerusahaan(list_co &L1, adr_co &P);
void deleteProdukPerusahaan(list_co &L1, adr_pr &P);
void showProdukPerusahaan(list_co L1);
int hitungJenisProduk(list_co L1, string nama);
void jangkauanTerluas(list_co L1);



#endif // MLL_H_INCLUDED
