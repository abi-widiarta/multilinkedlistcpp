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
     cout<<endl<<endl;
};

address_p findElement(List_p L, infotype_p x) {
     address_p P = first(L);
     while (P!=NULL) {
         if(info(P) == x) {
              return P;
         };
         P = next(P);
    };
    return NULL;;
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
     address_c P = first(L);
     cout<<"=== List Driver (Child)"<<endl << endl;
         cout << "   Nama Driver \tTempat Tinggal" << endl;
     while(P!=NULL){
         cout << "   " << info(P).nama << "\t";
         cout << info(P).tempatTinggal << endl;
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
    return NULL;;
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

void printRelasi(List_p LP, List_c LC) {
    address_p P;
    address_c C;

    P = first(LP);
    cout << "   === List Relasi" << endl << endl;
    while(P!= NULL) {
        cout << "      Kecamatan : " << info(P) << endl;
        cout << "   Nama Driver \tTempat Tinggal" << endl;
        C = first(LC);
        while(C!=NULL) {
            if(parent(C) == P) {
                cout << "   ";
                cout << info(C).nama << "\t";
                cout << info(C).tempatTinggal << endl;
            }
            C = next(C);
        }
        cout << endl << endl;
        P = next(P);
    }
    cout << endl;
}

// FOR MENU

int selectMenu_1301213196() {
    cout << "========================= JASA TRANSPORTASI =====================" << endl;
    cout << "=============================== MENU ============================" << endl;
    cout << "+ 1. Tambah Kecamatan." << endl;
    cout << "+ 2. Tambah Driver." << endl;
    cout << "+ 3. Tampilkan Kecamatan." << endl;
    cout << "+ 4. Tampilkan Driver." << endl;
    cout << "+ 5. Menghapus data (parent) beserta relasinya (child-nya)." << endl;
    cout << "+ 6. Menghitung jumlah data pada kecamatan dan setiap drivernya." << endl;
    cout << "+ 7. Menampilkan jumlah driver paling banyak di suatu kecamatan." << endl;
    cout << "+ 8. Menampilkan jumlah driver paling sedikit di suatu kecamatan." << endl;
    cout << "+ 0. Exit" << endl;
    cout << "=================================================================" << endl;
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
    cout << endl << "   Jumlah data child pada setiap parentnya :" << endl;
    while(p != NULL) {
        q = first(LC);
        while(q != NULL) {
            if(parent(q) == p) {
                hasilHitung++;
            }
            q = next(q);
        }
        cout << "   " << info(p) << " : " << hasilHitung << endl;
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
    cout << "   Total Data Pada List Parent : " << i << endl;
}

void countChild(List_c LC) {
    address_c C = first(LC);
    int j = 0;
    while(C != NULL) {
        j++;
        C = next(C);
    }
    cout << "   Total Data Pada List Child : " << j << endl;
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

bool findParentChild(List_p LP,List_c LC) {
    bool lanjut = true;
    address_p hasilJP;
    address_c hasilJC;
    infotype_c x;
    string jawaban,jP,jCNama,jCTempatTinggal,jLanjut;
    while(lanjut) {
        cout << endl << "   === Cari data pada parent atau child?" << endl;
        cout << "   1. Parent" << endl;
        cout << "   2. Child" << endl;
        cout << "   Jawab : ";
        cin >> jawaban;

        if(jawaban == "1") {
            cout << endl << "   Data yang akan dicari di parent : ";
            cin >> jP;
            hasilJP = findElement(LP,jP);
            if(hasilJP != NULL) {
                cout << "   Hasil : Data " << jP << " tersedia!" << endl;
            } else {
                cout << "   Hasil : Data " << jP << " tidak tersedia." << endl;
            }
        } else if(jawaban == "2") {
            cout << endl << "   Data yang akan dicari di child : " << endl;
            cout << "   Nama Driver : ";
            cin >> jCNama;
            cout << "   Tempat Tinggal : ";
            cin >> jCTempatTinggal;

            x.nama = jCNama;
            x.tempatTinggal = jCTempatTinggal;

            hasilJC = findElement(LC,x);
            if(hasilJC != NULL) {
                cout << "   Hasil : Data  tersedia!" << endl;
            } else {
                cout << "   Hasil : Data tidak tersedia." << endl;
            }
        }

        cout << endl << "   Lanjut Mencari? " << endl;
        cout << "   1. Ya" << endl;
        cout << "   2. Tidak" << endl;
        cout << "   Jawab : ";
        cin  >> jLanjut;

        if(jLanjut != "1") {
            lanjut = false;
        }
    }
    cout << endl;


};


