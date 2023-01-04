#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define parent(P) P->parent

// FOR PARENT

typedef string infotype_p;
typedef struct elm_p *address_p;

struct elm_p {
    infotype_p info;
    address_p next;
};

struct List_p {
    address_p first;
};

void createList(List_p &L);
address_p alokasiP(infotype_p x);
void insertFirst(List_p &L, address_p P);
void deleteFirst(List_p &L, address_p &P);
void printInfo(List_p L);
void deleteLast(List_p &LP, address_p &P);
void deleteMiddle(List_p &L, address_p &x);
address_p findElement(List_p L, infotype_p x);

// FOR CHILD

typedef struct elm_c *address_c;

struct infotype_c {
    string nama;
    string nopol;
    string tempatTinggal;
};

struct elm_c {
    infotype_c info;
    address_c next;
    address_p parent;
};

struct List_c {
    address_c first;
};

void createList(List_c &L);
address_c alokasiC(infotype_c x);
void insertFirst(List_c &L, address_c P);
void deleteFirst(List_c &L, address_c &P);
void printInfo(List_c L);
address_c findElement(List_c L, infotype_c x);
address_c findNopol(List_c L, infotype_c x);
void deleteDriver(List_c &L, address_c &P, infotype_c x);
void deleteLast(List_c &L, address_c &P);
void deleteMiddle(List_c &L, address_c &x);

// FOR RELASI
bool checkParent(List_p L);
void connect(address_p &P, address_c &C);
void disconnect(address_c &C);
void printRelasi(List_p LP, List_c LC,address_p P);


// FOR MENU
int selectMenu_1301213196();
void countData(List_p LP,List_c LC);
void countParent(List_p LP);
void countChild(List_c LC);
void countMax(List_p LP, List_c LC);
void countMin(List_p LP, List_c LC);
bool findParentChild(List_p LP,List_c LC);

void deleteFirstParent(List_p &LP, List_c &LC, address_p &P);
void deleteKecematan(List_p &LP, List_c &LC, address_p &P, infotype_p x);


#endif // TUBES_H_INCLUDED
