#include <iostream>
using namespace std;

struct Murid {
    string nama, npm;
    int nilaiUts, nilaiUas;
    Murid* next;
} *que, *stk, *node, *cur;

int nodeQue = 0;
int nodeStk = 0;

void stack(string nama, string npm, int nilaiUts, int nilaiUas) {
    node = new Murid();
    node->nama = nama;
    node->npm = npm;
    node->nilaiUas = nilaiUas;
    node->nilaiUts = nilaiUts;
    node->next = NULL;

    if (stk == NULL) {
        stk = node;
    } else {
        node->next = stk;
        stk = node;
    }
    nodeStk++;
}

void queue(string nama, string npm, int nilaiUts, int nilaiUas) {
    node = new Murid();
    node->nama = nama;
    node->npm = npm;
    node->nilaiUas = nilaiUas;
    node->nilaiUts = nilaiUts;
    node->next = NULL;

    if (que == NULL) {
        que = node;
    } else {
        cur = que;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
    nodeQue++;
}

void show() {
    cur = stk;
    int i = 1;
    int rUts = 0;
    int rUas = 0;
    cout << "STACK" << endl;
    while (cur != NULL) {
        cout << "Data ke " << i << endl;
        cout << "Nama      : " << cur->nama << endl;
        cout << "Npm       : " << cur->npm << endl;
        cout << "Nilai uts : " << cur->nilaiUts << endl;
        cout << "Nilai uas : " << cur->nilaiUas << endl;
        rUts += cur->nilaiUts;
        rUas += cur->nilaiUas;
        cur = cur->next;
        i++;
    }
    if (nodeStk > 0) {
        cout << "Rata-rata Uts : " << rUts / nodeStk << endl;
        cout << "Rata-rata Uas : " << rUas / nodeStk << endl;
    } else {
        cout << "Tidak ada data dalam stack." << endl;
    }  
    cout << endl;

    cur = que;
    rUts = 0;
    rUas = 0;
    i = 1;
    cout << "QUEUE" << endl;
    while (cur != NULL) {
        cout << "Data ke " << i << endl;
        cout << "Nama      : " << cur->nama << endl;
        cout << "Npm       : " << cur->npm << endl;
        cout << "Nilai uts : " << cur->nilaiUts << endl;
        cout << "Nilai uas : " << cur->nilaiUas << endl;
        rUts += cur->nilaiUts;
        rUas += cur->nilaiUas;
        cur = cur->next;
        i++;
    }
    if (nodeQue > 0) {
        cout << "Rata-rata Uts : " << rUts / nodeQue << endl;
        cout << "Rata-rata Uas : " << rUas / nodeQue << endl;
    } else {
        cout << "Tidak ada data dalam queue." << endl;
    }
    cout << endl;
}

int main() {
    int pilihan;
    string nama, npm;
    int nilaiUts, nilaiUas;

    while (true) {
        cout << "menu:" << endl;
        cout << "1. Input data" << endl;
        cout << "2. Cetak" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "1. Stack" << endl;
            cout << "2. Queue" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;

            cout << "Masukkan nama      : ";
            cin >> nama;
            cout << "Masukkan npm       : ";
            cin >> npm;
            cout << "Masukkan nilai UTS : ";
            cin >> nilaiUts;
            cout << "Masukkan nilai UAS : ";
            cin >> nilaiUas;

            if (pilihan == 1) {
                stack(nama, npm, nilaiUts, nilaiUas);
            } else {
                queue(nama, npm, nilaiUts, nilaiUas);
            }
        } else if (pilihan == 2) {
            show();
        } else {
            break;
        }
    }
}
