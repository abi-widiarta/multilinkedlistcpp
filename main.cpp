#include "tubes.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i,j,banyak,pilihan;
    char prev,opening;
    int nP,nC,pilihanKecamatanDriver;
    string inputKecamatan,inputNama,inputTempatTinggal,inputKecamatanDriver, inputNopol;

    const char separator    = ' ';
    const int nameWidth     = 50;
    const int numWidth      = 8;



    List_p kecamatan;
    List_c driver;

    address_p P;
    address_c C;

    infotype_c x;

    createList(kecamatan);
    createList(driver);

    cout << " ===========================================" << endl;
    cout << " +       TUBES STD KELOMPOK FLASHDISK      +" << endl;
    cout << " +            JASA TRANSPORTASI            +" << endl;
    cout << " +                 TIPE A                  +" << endl;
    cout << " ===========================================" << endl;
    cout << " +                                         +" << endl;
    cout << " +            ANGGOTA KELOMPOK             +" << endl;
    cout << " +     RADITYA AYDIN        (1301213196)   +" << endl;
    cout << " +     I WAYAN ABI WIDIARTA (1301213196)   +" << endl;
    cout << " +                                         +" << endl;
    cout << " ===========================================" << endl << endl;
    cout << " Tekan ENTER untuk melanjutkan...";

    cin.ignore();
    system("cls");

    pilihan = selectMenu_1301213196();
    while(pilihan != 0) {
        switch(pilihan) {
            case 1:
                cout << " MASUKKAN NAMA KECAMATAN : " << endl;
                cout << " > ";
                cin >> inputKecamatan;
                insertFirst(kecamatan,alokasiP(inputKecamatan));
                cout << endl << " ================================" << endl;
                cout << " + Kecamatan Berhasil Ditambah! +" << endl;
                cout << " ================================" << endl;
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;

            case 2:
                {
                    bool checkEmpty = first(kecamatan) == NULL;
                    if(!checkEmpty) {

                        printInfo(kecamatan);

                        cout << " Pilih Kecamatan Driver : ";
                        cin >> pilihanKecamatanDriver;

                        address_p P = first(kecamatan);
                        int z = 1;
                        while(z < pilihanKecamatanDriver){
                             P = next(P);
                             z++;
                         };
                        cout << endl << " Nama Driver    : ";
                        cin >> inputNama;
                        cout << " Tempat Tinggal : ";
                        cin >> inputTempatTinggal;
                        cout << " Input Nopol    : ";
                        cin >> inputNopol;
                        cout << endl;

                        x.nama = inputNama;
                        x.tempatTinggal = inputTempatTinggal;
                        x.nopol = inputNopol;
                        address_c C = alokasiC(x);
                        insertFirst(driver,C);
                        connect(P,C);

                    } else {
                        cout << " List Kecamatan Kosong! Masukkan Daftar Kecamatan Terlebih Dahulu" << endl;

                    }
                }
                cout << " ================================" << endl;
                cout << " +   Driver Berhasil Ditambah!  +" << endl;
                cout << " ================================" << endl << endl;
                cout << " Kembali ke menu? (y/n) : ";
                cin >> prev;

                break;

            case 3:
                printInfo(kecamatan);

                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;

            case 4:
                {


                int pilihanKecamatan;
                bool checkEmpty = first(kecamatan) == NULL;
                    if(!checkEmpty) {
                        printInfo(kecamatan);
                        cout << " Pilih Kecamatan : ";
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
                        printInfo(kecamatan);
                    }
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                cout << endl;
                break;
                }

            case 5:
                {
                    string target;
                    address_p p;
                    printInfo(kecamatan);

                    cout << " Masukkan Nama Kecamatan yang ingin dihapus : ";
                    cin >> target;

                    deleteKecematan(kecamatan, driver, p, target);

                    cout << endl << " Kembali ke menu? (y/n) : ";
                    cin >> prev;
                    break;

                }

            case 6:
                {
                string namaDriver, nopolDriver;
                address_c p;
                printInfo(driver);
                cout << " Masukkan Detail Driver Yang Ingin Dihapus!" << endl;
                cout << endl << " Nama Driver  : ";
                cin >> namaDriver;
                cout << " Nopol Driver : ";
                cin >> nopolDriver;

                deleteDriver(driver,p,namaDriver,nopolDriver);
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;
                }

            case 7:
                countMax(kecamatan,driver);
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;

            case 8:
                countMin(kecamatan,driver);
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;
            case 9:
                countParent(kecamatan);
                countChild(driver);
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;

            case 10:
                {
                infotype_c x;
                cout << " MASUKKAN NOPOL DRIVER : " << endl;
                cout << " > ";
                cin >> x.nopol;
                address_c target = findNopol(driver, x);

                if(target == NULL) {
                    cout << " Driver tidak ditemukan!" << endl;
                } else {
                    cout << " =======================" << endl;
                    cout << " +  Driver Ditemukan!  +" << endl;
                    cout << " =======================" << endl << endl;

                    // cout << "Detail Driver   : " << endl;
                    cout << " Nama Driver     :  " << info(target).nama << endl;
                    cout << " Tempat Tinggal  :  " << info(target).tempatTinggal << endl;
                    cout << " Nopol           :  " << info(target).nopol << endl;
                    cout << " Kecamatan       :  " << info(parent(target)) << endl;
                }

                cout << endl;
                cout << endl << " Kembali ke menu? (y/n) : ";
                cin >> prev;
                break;
                }
            default:
                {
                    cout << "Input tidak valid, Masukkan input dengan benar!" << endl << endl;
                    pilihan = selectMenu_1301213196();
                }
        }

        if(prev == 'Y' || prev == 'y') {
            system("cls");
            pilihan = selectMenu_1301213196();
        } else {
            pilihan = 0;
        }
    }
    if (pilihan == 0) {
        cout << endl << "ANDA TELAH KELUAR DARI PROGRAM!" << endl;
    }

    return 0;
}
