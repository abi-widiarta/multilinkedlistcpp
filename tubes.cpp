#include "tubes.h"

// FOR PARENT

void createList(List_p &L){
     first (L) = NULL;
};

address_p alokasiP(infotype_p x) {
     address_p P = new elm_p;
     info(P) = x;
     next(P) = NULL;
     return P;
};

void insertFirst(List_p &L, address_p P){
    if(first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
};

void deleteFirst(List_p &L, address_p &P) {
     P = first(L);
     if(P!=NULL) {
         first(L) = next(P);
         next(P) = NULL;
     }
};

void deleteMiddle(List_p &L, address_p &x){
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        address_p pertama = first(L);
        address_p kedua = first(L);
        while(next(pertama) != x){
            pertama = next(pertama);
        }
        kedua = pertama;
        pertama = next(next(pertama));
        next(kedua) = pertama;
        next(x) = NULL;
    }
}

void deleteLast(List_p &L, address_p &P){
    address_p p = first(L);
    if(first(L) == NULL){
        cout << "List kosong" << endl;
    }else if(next(p) == NULL){
        first(L) = NULL;
    }else{
        while(next(next(p)) != NULL){
            p = next(p);
        }
        next(p) = NULL;
    }
}

void deleteKecematan(List_p &LP, List_c &LC, address_p &P, infotype_p x){
    address_p target = findElement(LP, x);
    address_c c = first(LC);
    if(target != NULL) {
        while(c != NULL){
            if(parent(c) == target){
                parent(c) = NULL;
            }
            c = next(c);
        }
        if(target == first(LP)){
            deleteFirst(LP, P);
        }else if(next(target) == NULL){
            deleteLast(LP, P);
        }else{
            deleteMiddle(LP, target);
        }

        cout << endl << " Daftar Kecamatan Setelah Penghapusan : " << endl << endl;
        printInfo(LP);
    } else if(target == NULL){
        cout << endl << " Kecamatan Tidak Ditemukan!" << endl;
    }
}


void printInfo(List_p L) {
    cout << " " << left << setw(30) << setfill('=') << "";
    cout << endl;
    cout << left << setw(30) << setfill(' ') << " | DAFTAR KECAMATAN";
    cout << "|" << endl;
    cout << " " << left << setw(30) << setfill('=') << "";
    cout << endl;
    cout << left << setw(30) << setfill(' ') << " |";
    cout << "|" << endl;

     if(first(L) == NULL) {
        cout << left << setw(30) << setfill(' ') << " | Tidak Ada Data Kecamatan";
            cout << "|" << endl;
            cout << left << setw(30) << setfill(' ') << " |";
            cout << "|" << endl;
            cout << " " << left << setw(30) << setfill('=') << "";
     } else {
        address_p P = first(L);
        int i = 1;
        while(P!=NULL){
            cout << left <<  " | [" << i << "] " << setw(23) << setfill(' ') << info(P);
            cout << "|" << endl;
             P = next(P);
             i++;
         };
         cout << left << setw(30) << setfill(' ') << " |";
         cout << "|" << endl;
         cout << " " << left << setw(30) << setfill('=') << "";
     }
     cout<<endl;
};

address_p findElement(List_p L, infotype_p x) {
     address_p P = first(L);
     while (P!=NULL) {
         if(info(P) == x) {
              return P;
         };
         P = next(P);
    };
    return NULL;
};





// FOR CHILD

void createList(List_c &L){
     first (L) = NULL;
};

address_c alokasiC(infotype_c x) {
     address_c P = new elm_c;
     info(P) = x;
     next(P) = NULL;
     parent(P) = NULL;
     return P;
};

void insertFirst(List_c &L, address_c P){
    if(first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
};

void deleteFirst(List_c &L, address_c &P) {
     P = first(L);
     if(P!=NULL) {
         first(L) = next(P);
         next(P) = NULL;
     }
};

void printInfo(List_c L) {
    cout << " " << left << setw(40) << setfill('=') << "";
    cout << endl;
    cout << left << setw(40) << setfill(' ') << " | DAFTAR DRIVER";
    cout << "|" << endl;
    cout << " " << left << setw(40) << setfill('=') << "";
    cout << endl;
    cout << left << setw(40) << setfill(' ') << " |";
    cout << "|" << endl;

     if(first(L) == NULL) {
        cout << left << setw(40) << setfill(' ') << " | Tidak Ada Data Driver";
            cout << "|" << endl;
            cout << left << setw(40) << setfill(' ') << " |";
            cout << "|" << endl;
            cout << " " << left << setw(40) << setfill('=') << "";
     } else {
        address_c P = first(L);
        int i = 1;
        while(P!=NULL){
                cout << left << " | [" << i << "]  Nama Driver    : " << setw(15) << setfill(' ') << info(P).nama;
                cout << "|" << endl;
                cout << left << " |      Tempat Tinggal : " << setw(15) << setfill(' ') << info(P).tempatTinggal;
                cout << "|" << endl;
                cout << left << " |      Nopol          : " << setw(15) << setfill(' ') << info(P).nopol;
                cout << "|" << endl;
                if(parent(P) != NULL) {
                    cout << left << " |      Kecamatan      : " << setw(15) << setfill(' ') << info(parent(P));
                    cout << "|" << endl;
                } else {
                    cout << left << " |      Kecamatan      : " << setw(15) << setfill(' ') << "Belum Terdaftar";
                    cout << "|" << endl;
                }
                i++;
                P = next(P);
                cout << left << setw(40) << setfill(' ') << " |";
                cout << "|" << endl;
         };
         cout << left << setw(40) << setfill(' ') << " |";
         cout << "|" << endl;
         cout << " " << left << setw(40) << setfill('=') << "";
     }
     cout<<endl;
};

address_c findElement(List_c L, infotype_c x) {
     address_c P = first(L);
     while (P!=NULL) {
         if(info(P).nama == x.nama && info(P).tempatTinggal == x.tempatTinggal) {
              return P;
         };
         P = next(P);
    };
    return NULL;
};

address_c findNopol(List_c L, infotype_c x){
    address_c P = first(L);
    while (P!=NULL) {
        if(info(P).nopol == x.nopol){
            return P;
        }
        P = next(P);
    }
    return NULL;
};

void deleteMiddle(List_c &L, address_c &x){
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        address_c pertama = first(L);
        address_c kedua = first(L);
        while(next(pertama) != x){
            pertama = next(pertama);
        }
        kedua = pertama;
        pertama = next(next(pertama));
        next(kedua) = pertama;
        next(x) = NULL;
    }
}

void deleteLast(List_c &L, address_c &P){
    address_c p = first(L);
    if(first(L) == NULL){
        cout << "List kosong" << endl;
    }else if(next(p) == NULL){
        first(L) = NULL;
    }else{
        while(next(next(p)) != NULL){
            p = next(p);
        }
        next(p) = NULL;
    }
}

void deleteDriver(List_c &L, address_c &P, string namaDriver, string nopolDriver){ //x = nama, m = nopol
    address_c Q = first(L);
    bool found = false;
    while(Q != NULL){
        if(info(Q).nama == namaDriver && info(Q).nopol == nopolDriver){
            found = true;
            if(Q == first(L)){
                disconnect(Q);
                deleteFirst(L, P);
            }else if(next(Q) == NULL){
                disconnect(Q);
                deleteLast(L, P);
            }else{
                disconnect(Q);
                deleteMiddle(L, Q);
            }
        }
        Q = next(Q);
    }
    if(found == false) {
        cout << endl << " Data Driver Tidak Ditemukan!" << endl;
    }else if(first(L) == NULL){
        cout << endl << " Semua data Driver telah dihapus"<<endl;
    }else{
        cout << endl << " Data Driver Setelah Dilakukan Penghapusan :" << endl;
        printInfo(L);
    }
};


// FOR RELASI

void connect(address_p &P, address_c &C) {
     if (P!=NULL && C!=NULL) {
         parent(C) = P;
         }
};

void disconnect(address_c &C) {
     if (C!=NULL) {
         parent(C)= NULL;
    }
}

void printRelasi(List_p LP, List_c LC,address_p P) {
    address_c C = first(LC);
    cout << " " << left << setw(40) << setfill('=') << "";
    cout << endl;
    cout << left << " | Kecamatan " << setw(27) << setfill(' ') << info(P);
    cout << "|" << endl;
    cout << " " << left << setw(40) << setfill('=') << "";
    cout << endl;
    cout << left << setw(40) << setfill(' ') << " |";
    cout << "|" << endl;
    cout << left << setw(40) << setfill(' ') << " |";
    cout << "|" << endl;

    bool adaDriver = false;
    int i =1;
        while(C!=NULL) {
            if(parent(C) == P) {
                adaDriver = true;
                cout << left << " | [" << i << "]  Nama Driver    : " << setw(15) << setfill(' ') << info(C).nama;
                cout << "|" << endl;
                cout << left << " |      Tempat Tinggal : " << setw(15) << setfill(' ') << info(C).tempatTinggal;
                cout << "|" << endl;
                cout << left << " |      Nopol          : " << setw(15) << setfill(' ') << info(C).nopol;
                cout << "|" << endl;
                i++;
                cout << left << setw(40) << setfill(' ') << " |";
                cout << "|" << endl;
            }
            C = next(C);
        }

        if(adaDriver) {
            cout << left << setw(40) << setfill(' ') << " |";
            cout << "|" << endl;
            cout << " " << left << setw(40) << setfill('=') << "";
        } else {
            cout << left << setw(40) << setfill(' ') << " | Tidak Ada Driver";
            cout << "|" << endl;
            cout << left << setw(40) << setfill(' ') << " |";
            cout << "|" << endl;
            cout << left << setw(40) << setfill(' ') << " |";
            cout << "|" << endl;
            cout << " " << left << setw(40) << setfill('=') << "";
        }
        cout << endl;
}

bool checkParent(List_p L){
    return first(L) == NULL;
};

// FOR MENU

int selectMenu_1301213196() {
    cout << " ====================================================" << endl;
    cout << " +              MENU JASA TRANSPORTASI              +" << endl;
    cout << " ====================================================" << endl;
    cout << " +                                                  +" << endl;
    cout << " +  1. Tambah Kecamatan                             +" << endl;
    cout << " +  2. Tampilkan Kecamatan                          +" << endl;
    cout << " +  3. Tambah Driver                                +" << endl;
    cout << " +  4. Tampilkan Driver                             +" << endl;
    cout << " +  5. Hapus Kecamatan                              +" << endl;
    cout << " +  6. Hapus Driver                                 +" << endl;
    cout << " +  7. Kecamatan Dengan Driver Paling Banyak        +" << endl;
    cout << " +  8. Kecamatan Dengan Driver Paling Sedikit       +" << endl;
    cout << " +  9. Tampilkan Jumlah Data Kecamatan Dan Driver   +" << endl;
    cout << " +  10. Cari Driver berdasarkan Nopol               +" << endl;
    cout << " +  0. Exit                                         +" << endl;
    cout << " +                                                  +" << endl;
    cout << " ====================================================" << endl;
    cout << " Masukkan menu (0-10) : ";

    int input;
    cin >> input;
    cout << endl;
    return input;
}

void countData(List_p LP, List_c LC){
    address_p p;
    address_c q;

    int hasilHitung = 0;
    p = first(LP);
    cout << endl << " Jumlah data driver pada setiap kecamatan :" << endl;
    while(p != NULL) {
        q = first(LC);
        while(q != NULL) {
            if(parent(q) == p) {
                hasilHitung++;
            }
            q = next(q);
        }
        cout << " - " << info(p) << " : " << hasilHitung << endl;
        hasilHitung = 0;
        p = next(p);
    }
    cout << endl;
};

void countParent(List_p LP) {
    address_p P = first(LP);
    int i = 0;
    while(P != NULL) {
        i++;
        P = next(P);
    }
    printInfo(LP);
    cout << " Total Data Kecamatan : " << i << endl;
}

void countChild(List_c LC) {
    address_c C = first(LC);
    int j = 0;
    while(C != NULL) {
        j++;
        C = next(C);
    }
    cout << endl;
    printInfo(LC);
    cout << " Total Data Driver    : " << j << endl;
}

void countMax(List_p LP, List_c LC){
    address_p p;
    address_c q;

    address_p temp;
    int hasilHitung = 0;
    int nilaiMax = 0;

    p = first(LP);
    if(p == NULL) {
        cout << " Data Kecamatan Tidak Ditemukan!" << endl;
    } else {
        while(p != NULL) {
            q = first(LC);
            while(q != NULL) {
                if(parent(q) == p) {
                    hasilHitung++;
                }
                q = next(q);
            }
            if(hasilHitung > nilaiMax) {
                nilaiMax = hasilHitung;
                temp = p;
            }
            hasilHitung = 0;
            p = next(p);
        }
        if(nilaiMax != 0) {
            cout << " Jumlah data paling banyak dimiliki oleh Kecamatan \""<< info(temp) << "\" dengan jumlah data driver sebanyak : "<< nilaiMax << endl;
        } else if (nilaiMax == 0) {
            cout << " Tidak ada driver" << endl;
        }
    }
};

void countMin(List_p LP, List_c LC){
    address_p p;
    address_c q;

    address_p temp;
    int hasilHitung = 0;
    int nilaiMin = INT_MAX;

    p = first(LP);
    if(p == NULL) {
        cout << " Data Kecamatan Tidak Ditemukan" << endl;
    } else {
        while(p != NULL) {
            q = first(LC);
            while(q != NULL) {
                if(parent(q) == p) {
                    hasilHitung++;
                }
                q = next(q);
            }
            if(hasilHitung < nilaiMin) {
                nilaiMin = hasilHitung;
                temp = p;
            }
            hasilHitung = 0;
            p = next(p);
        }
        cout << " Jumlah data paling sedikit dimiliki oleh Kecamatan \""<< info(temp) << "\" dengan jumlah data driver sebanyak : "<< nilaiMin << endl;
    }
};
