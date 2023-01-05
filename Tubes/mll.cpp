#include "mll.h"

void newPerusahaan(adr_co &E, infotype_co X){
    E = new elm_co;
    info_co(E) = X;
    next(E) = NULL;
    prev(E) = NULL;
}
void newProduk(adr_pr &E, infotype_pr X){
    E = new elm_pr;
    info_pr(E) = X;
    next(E) = NULL;
}
void newRelasi(adr_relasi &E, adr_pr X){
    E = new elm_relasi;
    produk(E) = X;
    next(E) = NULL;
}

void insertPerusahaan(list_co &L1,adr_co P){
    if (first(L1) == NULL){
        first(L1) = P;
    }else{
        adr_co Q = first(L1);
        while(next(L1) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void insertProduk(list_pr &L2,adr_pr P){
    if (first(L2) == NULL){
        first(L2) = P;
    }else{
        adr_pr Q = first(L2);
        while(next(L2) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adr_co searchPerusahaan(list_co &L1, string nama){
    adr_co P = first(L1);

    while(P != NULL){
        if (info_co(L1).nama == nama){
            return P;
        }
        P = next(P);
    }
    return(P);
}

adr_pr searchPeroduk(list_pr &L2, string produk){
    adr_pr P = first(L2);

    while(P != NULL){
        if (info_pr(L2).produk == produk){
            return P;
        }
        P = next(P);
    }
    return(P);
}

void addProdukPerusahaan(list_co &L1 ,list_pr L2, string perusahaan, string produk){
    adr_co P = searchPerusahaan(L1, perusahaan);
    adr_pr Q = searchPeroduk(L2, produk);
    adr_relasi R;
    newRelasi(R,Q);
    if (next_relasi(P) == NULL){
        next_relasi(P) = R;
    }else{
        adr_relasi p = next_relasi(P);
        while(next(p) != NULL){
            p = next(p);
        }
        next(p) = R;
    }

}
void perusahaanProduk(list_co L,string produk){
    adr_co P = first(L);
    adr_relasi p;
    while(P != NULL){
        while(p != NULL){
            if(produk == info_pr(produk(p)).produk){
                cout<<info_co(P).nama<<endl;
            }
            p = next(p);
        }
        P = next(P);
    }
}
void deletePerusahaan(list_co &L1, adr_co &P){

}
void deleteProdukPerusahaan(list_co &L1, adr_pr &P);
void showProdukPerusahaan(list_co L1){
    adr_co P = first(L1);
    adr_relasi p;
    while(P != NULL){
        cout<<"Perusahaan "<< info_co(P).nama<<endl;
        while(p != NULL){
            cout<<info_pr(produk(p)).produk<<endl;
            p = next(p);
        }
        P = next(P);
    }
}
int hitungJenisProduk(list_co L1, string nama);
void jangkauanTerluas(list_co L1);

