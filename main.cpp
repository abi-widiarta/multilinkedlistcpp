#include "tubes.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int pilihan;
    char prev;
    int pilihanKecamatanDriver;
    string inputKecamatan,inputNama,inputTempatTinggal,inputKecamatanDriver, inputNopol;

    List_p kecamatan;
    List_c driver;

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
    cout << " +     RADITYA AYDIN        (1301213292)   +" << endl;
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
                {
                    int n,i;
                    i = 1;
                    cout << " Masukkan Jumlah Kecamatan : ";
                    cin >> n;
                    cout << endl;
                    cout << " Masukkan Nama Kecamatan   : " << endl;
                    while(i <= n) {
                        cout << " [" << i << "] ";
                        //cin >> inputKecamatan;
                        cin.ignore();
                        getline(cin, inputKecamatan);
                        insertFirst(kecamatan,alokasiP(inputKecamatan));
                        i++;
                    }
                    cout << endl << " ================================" << endl;
                    cout << " + Kecamatan Berhasil Ditambah! +" << endl;
                    cout << " ================================" << endl;

                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

            case 2:
                {
                    printInfo(kecamatan);
                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }



            case 3:
                {
                    int i,n;
                    i = 1;
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

                        cout << " Masukkan Jumlah Driver : ";
                        cin >> n;
                        cout << endl;
                        cout << " Nb : Gunakan \"_\" untuk spasi" << endl;
                        cout << endl;
                        while(i <= n) {
                            cout << " [" << i << "]" <<endl;
                            cout <<  " Nama Driver    : ";
                            cin.ignore();
                            getline(cin, inputNama);

                            cout << " Tempat Tinggal : ";
                            getline(cin, inputTempatTinggal);

                            cout << " Input Nopol    : ";
                            cin.ignore();
                            getline(cin, inputNopol);

                            cout << endl;

                            x.nama = inputNama;
                            x.tempatTinggal = inputTempatTinggal;
                            x.nopol = inputNopol;
                            address_c C = alokasiC(x);
                            insertFirst(driver,C);
                            connect(P,C);

                            i++;
                        }

                    } else {
                        cout << " List Kecamatan Kosong! Masukkan Daftar Kecamatan Terlebih Dahulu" << endl << endl;

                    }

                    if(first(driver) != NULL) {
                        cout << " ================================" << endl;
                        cout << " +   Driver Berhasil Ditambah!  +" << endl;
                        cout << " ================================" << endl << endl;
                    }
                    cout  << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

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
                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

            case 5:
                {
                    string target;
                    address_p p;
                    printInfo(kecamatan);


                    if(first(kecamatan) != NULL) {
                        cout << " Masukkan Nama Kecamatan yang ingin dihapus : ";
                        cin >> target;
                        deleteKecematan(kecamatan, driver, p, target);
                    }

                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;

                }

            case 6:
                {
                    string namaDriver, nopolDriver;
                    address_c p;
                    printInfo(driver);

                    if(first(driver) != NULL) {
                        cout << " Masukkan Detail Driver Yang Ingin Dihapus!" << endl;
                        cout << endl << " Nama Driver  : ";
                        cin >> namaDriver;
                        cout << " Nopol Driver : ";
                        cin >> nopolDriver;

                        deleteDriver(driver,p,namaDriver,nopolDriver);
                    }

                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

            case 7:
                {
                    countMax(kecamatan,driver);
                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

            case 8:
                {
                    countMin(kecamatan,driver);
                    cout << endl << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }
            case 9:
                {
                    countParent(kecamatan);
                    countChild(driver);
                    cout << " Tekan ENTER untuk kembali ke menu...";
                    break;
                }

            case 10:
                {
                    infotype_c x;
                    cout << " MASUKKAN NOPOL DRIVER : " << endl;
                    cout << " > ";
                    cin >> x.nopol;
                    address_c target = findNopol(driver, x);

                    if(target == NULL) {
                        cout << endl << " Driver tidak ditemukan!" << endl;
                    } else {
                        cout << " =======================" << endl;
                        cout << " +  Driver Ditemukan!  +" << endl;
                        cout << " =======================" << endl << endl;

                        cout << " Nama Driver     :  " << info(target).nama << endl;
                        cout << " Tempat Tinggal  :  " << info(target).tempatTinggal << endl;
                        cout << " Nopol           :  " << info(target).nopol << endl;
                        cout << " Kecamatan       :  " << info(parent(target)) << endl;
                    }

                    cout << endl <<  " Tekan ENTER untuk kembali ke menu...";
                    break;
                }
            default:
                {
                    cout << " Input tidak valid, Masukkan input dengan benar!" << endl << endl;
                    cout <<  " Tekan ENTER untuk kembali ke menu...";
                    cin.sync();
                    cin.get();
                    system("cls");
                    pilihan = selectMenu_1301213196();
                    continue;
                }
        }

        cin.sync();
        cin.get();
        system("cls");
        pilihan = selectMenu_1301213196();
    }
    if (pilihan == 0) {
        cout << endl << " ANDA TELAH KELUAR DARI PROGRAM!" << endl;
    }

    return 0;
}
