#include <iostream>
using namespace std;

int totalPelanggan = 0;
int harga = 12000;
int untung = 0;
int stokMie = 10;

struct Pelanggan{
	int urutan, kembalian;
	Pelanggan *next;
}*head, *node, *cur;

string beli(int bayar){
	if( bayar < 12000){
		return "Uang kurang";
	}else{
		if( stokMie <= 0 ){
			return "Stok mie sudah habis";
		}
	}
	
	stokMie--;
	totalPelanggan++;
    node = new Pelanggan();
    node->urutan = totalPelanggan;
    node->kembalian = bayar - harga;
    node->next = NULL;

    if( head == NULL ){
        head = new Pelanggan();
        head = node;
    } else{
        node->next = head;
        head = node;
    }

	untung += harga;
    return "Pesanan di list";
}

void read(){
    cur = head;
    while( cur != NULL ){
        cout<<"\nPelanggan ke : "<<cur->urutan<<endl;
        cout<<"Pesanan   : Mie ayam"<<endl;
        cout<<"Kembalian : Rp. "<<cur->kembalian<<endl<<endl;
        cur = cur->next;
    }
}

string pesananSelesai(){
    if (head == NULL) {
    	return "Tidak ada pesanan";
    }
    
    cout<<"Pesanan Pelanggan terdahulu selesai"<<endl;
    cout<<"Kembalian : "<<head->kembalian<<endl;
    
    cur = head;
    head = head->next;
    
    return "Pelanggan di hapus dalam list";
}

int main(){
    int pilihan, bayar;

    while(true){
        cout<<"Menu"<<endl;
        cout<<"1. Pesan Mie Ayam (Rp. "<<harga<<")"<<endl;
        cout<<"2. Lihat Pesanan"<<endl;
        cout<<"3. Hapus Pesanan Selesai"<<endl;
        cout<<"4. Hitung total Pelanggan dan Untung / pulang"<<endl<<endl;

        cout<<"Pilihan : "; cin>>pilihan;

        if(pilihan == 1){
        	cout<<"Bayar terlebih dahulu : "; cin>>bayar;
        	cout<<endl<<beli(bayar)<<endl<<endl;
        } else if(pilihan == 2){
            read();
        } else if(pilihan == 3){
            cout<<pesananSelesai()<<endl<<endl;
        } else{
            cout<<"Total pelanggan : "<<totalPelanggan<<endl;
            cout<<"Untung hari ini : "<<untung<<endl;
            break;
        }
    }
}
