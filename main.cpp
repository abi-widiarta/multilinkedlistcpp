#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    int i,j,pilihan,banyak;
    char prev;
    int nP,nC;
    string inputKecamatan,inputNama,inputTempatTinggal,inputKecamatanDriver;

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
                cout << "Masukkan Kecamatan : ";
                cin >> inputKecamatan;
                insertFirst(kecamatan,alokasiP(inputKecamatan));
                prev = 'Y';
                cout << endl;
                break;

            case 2:
                cout << "Daftar Kecamatan" << endl;
                printInfo(kecamatan);
                cout << "Pilih Kecamatan Driver : ";
                cin >> pilihanKecamatanDriver;
                cout << "User Memilih Kecamatan : " << pilihanKecamatanDriver << endl;

                cout << "Nama Driver : ";
                cin >> inputNama;
                cout << "Tempat Tinggal : ";
                cin >> inputTempatTinggal;
                cout << endl;

                x.nama = inputNama;
                x.tempatTinggal = inputTempatTinggal;
                insertFirst(driver,alokasiC(x));
                break;

            case 3:
                cout << "== Daftar Kecamatan" << endl;
                printInfo(kecamatan);
                prev = 'Y';
                break;

            case 4:
                {

                cout << "4. Menambahkan relasi antara kecamatan dan driver." << endl << endl;
                address_c r = first(driver);
                 cout << "   Nama Driver \tTempat Tinggal \tKecamatan" << endl;
                 while(r!=NULL){
                     cout << "   " << info(r).nama << "\t";
                     cout << info(r).tempatTinggal << "\t";
                     cin >> inputKecamatanDriver;
                     P = findElement(kecamatan,inputKecamatanDriver);
                     C = findElement(driver,info(r));
                     connect(P,C);
                     r = next(r);
                 };
                 cout << endl;
                 printRelasi(kecamatan,driver);
                break;
                }

            case 5:
                cout << "tes" << endl;
                break;

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
