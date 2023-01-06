#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    int i,j,pilihan,banyak;
    char prev;
    int nP,nC;
    string inputKecamatan,inputNama,inputTempatTinggal,inputKecamatanDriver, inputNopol;

    List_p kecamatan;
    List_c driver;

    address_p P;
    address_c C;

    infotype_c x;

    // VAR ASISTENSI
    int pilihanKecamatanDriver;

    createList(kecamatan);
    createList(driver);
    pilihan = selectMenu_1301213196();
    while(pilihan != 0) {
        switch(pilihan) {
            case 1 :
                cout << "Masukkan Nama Kecamatan : ";
                cin >> inputKecamatan;
                insertFirst(kecamatan,alokasiP(inputKecamatan));
                prev = 'Y';
                cout << endl;
                break;

            case 2:
                {
                    bool checkEmpty = first(kecamatan) == NULL;
                    if(!checkEmpty) {
                        printInfo(kecamatan);
                        cout << "Pilih Kecamatan Driver : ";
                        cin >> pilihanKecamatanDriver;

                        address_p P = first(kecamatan);
                        int z = 1;
                        while(z < pilihanKecamatanDriver){
                             P = next(P);
                             z++;
                         };
                        cout << endl << "Nama Driver    : ";
                        cin >> inputNama;
                        cout << "Tempat Tinggal : ";
                        cin >> inputTempatTinggal;
                        cout << "Input Nopol : ";
                        cin >> inputNopol;
                        cout << endl;

                        x.nama = inputNama;
                        x.tempatTinggal = inputTempatTinggal;
                        x.nopol = inputNopol;
                        address_c C = alokasiC(x);
                        insertFirst(driver,C);
                        connect(P,C);
                    } else {
                        cout << "List Kecamatan Kosong! Masukkan Daftar Kecamatan Terlebih Dahulu" << endl;
                        prev = 'Y';
                    }
                }

                break;

            case 3:
                cout << "== Daftar Kecamatan" << endl;
                printInfo(kecamatan);
                prev = 'Y';
                break;

            case 4:
                {

                cout << "== Daftar Kecamatan : " << endl;
                int pilihanKecamatan;
                bool checkEmpty = first(kecamatan) == NULL;
                    if(!checkEmpty) {
                        printInfo(kecamatan);
                        cout << "Pilih Kecamatan : ";
                        cin >> pilihanKecamatan;
                        cout << endl;
                        address_p P = first(kecamatan);
                        int z = 1;
                        while(z < pilihanKecamatan){
                             P = next(P);
                             z++;
                         };

                        printRelasi(kecamatan,driver,P);
                    } else {
                        cout << "List Kosong!" << endl;
                        prev = 'Y';
                    }
                cout << endl;
                break;
                }

            case 5:
                {
                    string target;
                    address_p p;
                    cout << "Masukkan Kecamatan yang ingin dihapus: ";
                    cin >> target;

                    deleteKecematan(kecamatan, driver, p, target);
                    printInfo(kecamatan);
                    break;

                }

            case 6:
                cout << "6. Menghitung jumlah data pada kecamatan dan setiap drivernya." << endl << endl;
                countParent(kecamatan);
                countChild(driver);
                countData(kecamatan,driver);
                break;

            case 7:
                cout << "7. Menampilkan jumlah driver paling banyak di suatu kecamatan." << endl << endl;
                countMax(kecamatan,driver);
                break;

            case 8:
                cout << "8. Menampilkan jumlah driver paling sedikit di suatu kecamatan." << endl << endl;
                countMin(kecamatan,driver);
                break;

            case 10:
                cout << "10. Menghapus Data Driver." << endl << endl;
                string namaDriver, nopolDriver;
                address_c p;
                cout << "Masukkan nama Driver yang ingin dihapus: ";
                cin >> namaDriver;
                cout << "Nopol Driver : ";
                cin >> nopolDriver;
                deleteDriver(driver,p,namaDriver,nopolDriver);
                break;
        }
        if(prev=='Y') {
            pilihan = selectMenu_1301213196();
        }
    }
    if (pilihan == 0) {
        cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    }

    /*

    CADANGAN

    createList(kecamatan);
    insertFirst(kecamatan,alokasiP("Batununggal"));
    insertFirst(kecamatan,alokasiP("Bojongsoang"));
    insertFirst(kecamatan,alokasiP("Antapani"));
    printInfo(kecamatan);

    createList(driver);
    insertFirst(driver,alokasiC("Bambang")); // Batununggal
    insertFirst(driver,alokasiC("Agus")); // Bojongsoang
    insertFirst(driver,alokasiC("Ucok")); // Bojongsoang
    insertFirst(driver,alokasiC("Yayan")); // Batununggal
    insertFirst(driver,alokasiC("Lukman")); // Antapani
    printInfo(driver);


    P = findElement(kecamatan,"Batununggal");
    C = findElement(driver,"Bambang");
    connect(P,C);

    P = findElement(kecamatan,"Bojongsoang");
    C = findElement(driver,"Agus");
    connect(P,C);

    P = findElement(kecamatan,"Bojongsoang");
    C = findElement(driver,"Ucok");
    connect(P,C);

    P = findElement(kecamatan,"Batununggal");
    C = findElement(driver,"Yayan");
    connect(P,C);

    P = findElement(kecamatan,"Antapani");
    C = findElement(driver,"Lukman");
    connect(P,C);


    printRelasi(kecamatan,driver);

    */
    return 0;
}
