#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, npm;
    int uts, uas, rata;
    Mahasiswa* next;
}*head, * node, * cur;

string tambah(string nama, string npm, int uts, int uas) {
    node = new Mahasiswa();
    node->nama = nama;
    node->npm = npm;
    node->uts = uts;
    node->uas = uas;

    if (head == NULL) {
    	head = new Mahasiswa();
        head = node;
    }else {
        node->next = head;
        head = node;
    }

    return "Data telah ditambahkan";
}

int total() {
    cur = head;
    int hasil = 0;

    while (cur != NULL) {
        hasil++;
        cur = cur->next;
    }

    return hasil;
}

void bubbleSort() {
    cur = head;

    for (int i = 0; i < (total() - 1); i++) {

        for (int j = 1; j < total(); j++) {
            Mahasiswa* temp1 = head;
            Mahasiswa* temp2 = head->next;

            for (int k = 0; k < (total() - 1); k++) {
                if (temp1->uts + temp1->uas < temp2->uts + temp2->uas) {
                    string tempNama = temp1->nama;
                    string tempNPM = temp1->npm;
                    int tempUTS = temp1->uts;
                    int tempUAS = temp1->uas;

                    temp1->nama = temp2->nama;
                    temp1->npm = temp2->npm;
                    temp1->uts = temp2->uts;
                    temp1->uas = temp2->uas;

                    temp2->nama = tempNama;
                    temp2->npm = tempNPM;
                    temp2->uts = tempUTS;
                    temp2->uas = tempUAS;
                }

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }
}

string binarySearch(string npm) {
    cur = head;
    int low = 0;
    int high = total() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        Mahasiswa* temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        if (temp->npm == npm) {
            return temp->nama;
        }
        else if (temp->npm < npm) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return "NPM tidak ditemukan";
}

void show(){
	cur = head;
    while (cur != NULL) {
        cout << "Nama: " << cur->nama << endl;
        cout << "NPM: " << cur->npm << endl;
        cout << "UTS: " << cur->uts << endl;
        cout << "UAS: " << cur->uas << endl;
        cout << endl;
        cur = cur->next;
    }
}

int main() {
	int pilihan, uts, uas;
	string nama, npm;
	while( true ){
		cout<<"1. Masukan data"<<endl;
		cout<<"2. Cari"<<endl;
		cout<<"3. exit"<<endl;
		cout<<"Masukan pilihan : "; cin>>pilihan;
		if( pilihan == 1 ){
			cout<<"Masukan nama : "; cin>>nama;
			cout<<"Masukan npm  : "; cin>>npm;
			cout<<"Masukan uts  : "; cin>>uts;
			cout<<"Masukan uas  : "; cin>>uas;
			cout<<tambah(nama, npm, uts, uas)<<endl;
			bubbleSort();
			show();
		}else if( pilihan == 2){
			cout<<"Masukan npm mahasiswa : "; cin>>npm;
			cout<<"Mahasiswa "<<npm<<" : "<<binarySearch(npm)<<endl;
		}else{
			break;
		}
	}
}
