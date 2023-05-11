#include <iostream>
using namespace std;

struct Schema{
	string namaBarang;
	string harga;
	string barangTiba;
};

string create(string nama, string harga, string barangsatu, Schema barang[100], int index){
	barang[index].namaBarang = nama;
	barang[index].harga = harga;
	barang[index].barangTiba = barangsatu;
	
	return "barang anda sudah di tambahkan";
}

void read(Schema barang[100], int index){
	for(int i = 0; i < index; i++){
		cout<<"nomer "<<(i + 1)<<endl;
		cout<<"nama barang  : "<<barang[i].namaBarang<<endl;
		cout<<"harga barang : "<<barang[i].harga<<endl;
		cout<<"barang tiba  : "<<barang[i].barangTiba<<endl<<endl;
	}
}

int main(){
	string inputNamaBarang;
	string inputBarangTiba;
	string inputHarga;
	string ulang;
	
	Schema barang[100];
	int index = 0;
	
	do{
		cout<<"input nama barang  : "; cin>>inputNamaBarang;
		cout<<"input harga barang : "; cin>>inputHarga;
		cout<<"input barang tiba  : "; cin>>inputBarangTiba;
		cout<<create(inputNamaBarang, inputHarga, inputBarangTiba, barang, index)<<endl;
		index++;
		read(barang, index);
		
		
		
		cout<<"Apakah anda ingin mengulang ? (y/n)"<<endl;
		cin>>ulang;
	}while(ulang == "y" || ulang == "Y`");
}
