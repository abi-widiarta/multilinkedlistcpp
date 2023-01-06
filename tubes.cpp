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

void printInfo(List_p L) {
     if(first(L) == NULL) {
        cout << "List Kosong!" << endl;
     } else {
        address_p P = first(L);
        int i = 1;
        while(P!=NULL){
             cout << "[" << i << "] " << info(P) << endl;
             P = next(P);
             i++;
         };
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

void deleteFirstParent(List_p &LP, List_c &LC, address_p &P){
    address_c c = first(LC);
    while(c != NULL){
        if(parent(c) == first(LP)){
            parent(c) = NULL;
        }
        c = next(c);
    }
    deleteFirst(LP,P);
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

void deleteKecematan(List_p &LP, List_c &LC, address_p &P, infotype_p x){
    address_p target = findElement(LP, x);
    address_c c = first(LC);
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
}


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
     address_c P = first(L);
     cout<<"=== List Driver (Child)"<<endl << endl;
         cout << "   Nama Driver \tTempat Tinggal" << endl;
     while(P!=NULL){
         cout << "   " << info(P).nama << "\t";
         cout << info(P).tempatTinggal << "\t";
         cout << info(P).nopol << endl;
         P = next(P);
     };
     cout<<endl<<endl;
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
            cout << "Data Driver Tidak Ditemukan!" << endl;
        }else{
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
    cout << "=== Kecamatan " << info(P) << endl;
    bool adaDriver = false;
    int i =1;
        while(C!=NULL) {
            if(parent(C) == P) {
                adaDriver = true;
                cout << i << ".";
                cout << " Nama Driver    : " << info(C).nama << endl;
                cout << "   Tempat Tinggal : " << info(C).tempatTinggal << endl;
                cout << "   Nopol          : " << info(C).nopol << endl;
                i++;
            }
            C = next(C);
        }

        if(!adaDriver) {
            cout << "Tidak Ada Driver" << endl;
        }

        cout << "===" << endl;
}

bool checkParent(List_p L){
    return first(L) == NULL;
};

// FOR MENU

int selectMenu_1301213196() {
    cout << "================= JASA TRANSPORTASI ================" << endl;
    cout << "======================= MENU =======================" << endl;
    cout << "+ 1. Tambah Kecamatan." << endl;
    cout << "+ 2. Tambah Driver." << endl;
    cout << "+ 3. Tampilkan Kecamatan." << endl;
    cout << "+ 4. Tampilkan Driver." << endl;
    cout << "+ 5. Hapus Kecamatan" << endl;
    cout << "+ 6. Tampilkan Jumlah Data Kecamatan Dan Driver" << endl;
    cout << "+ 7. Kecamatan Dengan Driver Paling Banyak" << endl;
    cout << "+ 8. Kecamatan Dengan Driver Paling Sedikit" << endl;
    cout << "+ 9. Tampilkan Driver Berdasarkan Tempat Tinggal" << endl;
    cout << "=================== CEK LAGI BII ===================" << endl;
    cout << "+ 10. Delete Driver" << endl;
    cout << "+ 11. Cari Driver berdasarkan Nopol" << endl;
    cout << "+ 0. Exit" << endl;
    cout << "=====================================================" << endl;
    cout << "Masukkan menu : ";

    int input = 0;
    cin >> input;
    cout << endl;
    return input;
}

void countData(List_p LP, List_c LC){
    address_p p;
    address_c q;

    int hasilHitung = 0;
    p = first(LP);
    cout << endl << "Jumlah data driver pada setiap kecamatan :" << endl;
    while(p != NULL) {
        q = first(LC);
        while(q != NULL) {
            if(parent(q) == p) {
                hasilHitung++;
            }
            q = next(q);
        }
        cout << "- " << info(p) << " : " << hasilHitung << endl;
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
    cout << "Total Data Kecamatan : " << i << endl;
}

void countChild(List_c LC) {
    address_c C = first(LC);
    int j = 0;
    while(C != NULL) {
        j++;
        C = next(C);
    }
    cout << "Total Data Driver : " << j << endl;
}

void countMax(List_p LP, List_c LC){
    address_p p;
    address_c q;

    address_p temp;
    int hasilHitung = 0;
    int nilaiMax = 0;

    p = first(LP);
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
    cout << "   ";
    cout << "Jumlah data paling banyak dimiliki oleh parent \""<< info(temp) << "\" dengan jumlah data driver sebanyak : "<< nilaiMax << endl;
    cout << endl;
};

void countMin(List_p LP, List_c LC){
    address_p p;
    address_c q;

    address_p temp;
    int hasilHitung = 0;
    int nilaiMin = INT_MAX;

    p = first(LP);
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
    cout << "   ";
    cout << "Jumlah data paling sedikit dimiliki oleh parent \""<< info(temp) << "\" dengan jumlah data driver sebanyak : "<< nilaiMin << endl;
    cout << endl;
};

//bool findParentChild(List_p LP,List_c LC) {
//    bool lanjut = true;
//    address_p hasilJP;
//    address_c hasilJC;
//    infotype_c x;
//    string jawaban,jP,jCNama,jCTempatTinggal,jLanjut;
//    while(lanjut) {
//        cout << endl << "   === Cari data pada parent atau child?" << endl;
//        cout << "   1. Parent" << endl;
//        cout << "   2. Child" << endl;
//        cout << "   Jawab : ";
//        cin >> jawaban;
//
//        if(jawaban == "1") {
//            cout << endl << "   Data yang akan dicari di parent : ";
//            cin >> jP;
//            hasilJP = findElement(LP,jP);
//            if(hasilJP != NULL) {
//                cout << "   Hasil : Data " << jP << " tersedia!" << endl;
//            } else {
//                cout << "   Hasil : Data " << jP << " tidak tersedia." << endl;
//            }
//        } else if(jawaban == "2") {
//            cout << endl << "   Data yang akan dicari di child : " << endl;
//            cout << "   Nama Driver : ";
//            cin >> jCNama;
//            cout << "   Tempat Tinggal : ";
//            cin >> jCTempatTinggal;
//
//            x.nama = jCNama;
//            x.tempatTinggal = jCTempatTinggal;
//
//            hasilJC = findElement(LC,x);
//            if(hasilJC != NULL) {
//                cout << "   Hasil : Data  tersedia!" << endl;
//            } else {
//                cout << "   Hasil : Data tidak tersedia." << endl;
//            }
//        }
//
//        cout << endl << "   Lanjut Mencari? " << endl;
//        cout << "   1. Ya" << endl;
//        cout << "   2. Tidak" << endl;
//        cout << "   Jawab : ";
//        cin  >> jLanjut;
//
//        if(jLanjut != "1") {
//            lanjut = false;
//        }
//    }
//    cout << endl;
//
//
//};


