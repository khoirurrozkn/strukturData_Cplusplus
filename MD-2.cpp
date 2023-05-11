#include <iostream>
using namespace std;

struct Mahasiswa {
	string nama;
	string npm;
	string tahunMasuk;
	Mahasiswa *next;
} *head, *cur, *newNode;

void create(string nama, string npm, string tahunMasuk){
	newNode = new Mahasiswa();
	newNode->nama = nama;
	newNode->npm = npm;
	newNode->tahunMasuk = tahunMasuk;
	newNode->next = NULL;
	
	if( head == NULL ){
		head = new Mahasiswa();
		head = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void read(){
	cur = head;
	while( cur != NULL ){
		cout<<"nama :"<<cur->nama<<endl;
		cout<<"npm : "<<cur->npm<<endl;
		cout<<"tahun masuk : "<<cur->tahunMasuk<<endl;
		cout<<"next :"<<cur->next<<endl<<endl;
		cur = cur->next;
	}
}

int main(){
	int pilihan;
	string nama;
	string npm;
	string tahunMasuk;
	
	while(true){
		cout<<"Menu"<<endl;
		cout<<"1. Input data"<<endl;
		cout<<"2. Cetak"<<endl;
		cout<<"3. Exit"<<endl;
		
		cout<<"Pilihan : "; cin>>pilihan;
		
		if(pilihan == 1){
			cout<<"Masukan nama : "; cin>>nama;
			cout<<"Masukan npm : "; cin>>npm;
			cout<<"Masukan tahun masuk : "; cin>>tahunMasuk;
			create(nama, npm, tahunMasuk);
		}else if(pilihan == 2){
			read();
		}else{
			break;
		}
	}
}
