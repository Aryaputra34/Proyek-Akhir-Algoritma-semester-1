#include <iostream> 
#include <conio.h>  
#include <string>   
#include <fstream>  
using namespace std;

bool loginmember();
void menu();
void beli(int choice);
void create();
bool verification(int choice);
void review();
int pilihan();

 int main(){  
	int jml, total_minuman , kode, total_makanan , total , choice, harga_member ; 
	string username, password;
	char is_lanjut;

	choice = pilihan();
	while (choice != 4){
   
	switch (choice){
		case 1:
			create();
			break;
		
		case 2:
			verification(choice);
			break;
		
		case 3:
			menu(); 
			beli(choice);
			review();
			system("pause");
			system("cls");
			break;
		
		default:
			cout<<"ERROR"<<endl;
			break;
	}

		label_lanjut:
		
		cout<<"lanjutkan? (y/n)"<<endl;
		cin>>is_lanjut;
		
		if (is_lanjut == 'Y' || is_lanjut == 'y'){ 
			system("cls");
			choice = pilihan(); 
		} else if (is_lanjut == 'N' || is_lanjut == 'n'){ 
			break; 
		} else {
			goto label_lanjut;
		}
   
   
}
   system("cls");
   cout<<"Akhir dari Program"<<endl;
   cin.get();   
   return 0;
}

int pilihan(){
	int pilihan;
	cout<<"Selamat datang di warung makan KINGSLAIVE"<<endl;
	cout<<"1. Registrasi Member"<<endl;
	cout<<"2. Login Member"<<endl;
	cout<<"3. Tanpa Member"<<endl;
	cout<<"4. Selesai"<<endl;
	cout<<"\nPilihan anda : ";cin>>pilihan; 
	system("cls");
	cin.clear();
	cin.ignore( 1000, '\n' );
	return pilihan;
}

bool loginmember(){ 
	string username,password,id,pw; 
	
	cout<<"username : ";cin>>username; 
   	cout<<"password : ";cin>>password;
	ifstream read(username + ".txt"); 
   	getline(read,id);
   	getline(read,pw);
   	
   	if (id == username && pw == password) 
	{
		return true;	
	}else
	{
		return false;  
	}
	
}

void menu(){
	
	cout<<"\t\t\t<<===================================================================>>\n";  
	cout<<"\t\t\t||                       WARUNG MAKAN KINGSLAIVE                     ||\n";  
	cout<<"\t\t\t<<===================================================================>>\n\n";  
   

   
	cout<<"- Masukkan SKU item <spasi> jumlah item\n";  
	cout<<"- Contoh: 1 2\n";  
	cout<<"- Ketik 0 <spasi> 0\n";  
	cout<<"jika sudah selesai\n\n";  
	cout<<"==============================================================\n";  
	cout<<"|| Minuman          \t\t 	 || 	Harga     ||\n";  
	cout<<"==============================================================\n";  
	cout<<"|| 1) Aqua botol    \t\t 	 || Rp   3000,-   ||\n";  
	cout<<"|| 2) Coca Cola     \t\t 	 || Rp   4000,-   ||\n";  
	cout<<"|| 3) Es Teh        \t\t	 || Rp   3500,-   ||\n";  
	cout<<"|| 4) Pulpy Oranges \t\t 	 || Rp   5000,-   ||\n";  
	cout<<"==============================================================\n";
   
	cout<<"==============================================================\n";  
	cout<<"|| Makanan                 \t\t || 	Harga     ||\n";  
	cout<<"==============================================================\n";  
	cout<<"|| 1) Nasi Tahu Tempe Telor\t\t || Rp   10000,-  ||\n";  
	cout<<"|| 2) Nasi Kulit Crispy    \t\t || Rp   12000,-  ||\n";  
	cout<<"|| 3) Nasi Ayam Geprek     \t\t || Rp   15000,-  ||\n";  
	cout<<"|| 4) Nasi Steak Ayam      \t\t || Rp   25000,-  ||\n";  
	cout<<"==============================================================\n";  
}

void beli(int choice){
	int minuman[4]={3000, 4000, 3500, 5000};  
	int makanan[4]={10000, 12000, 15000, 25000}; 
	int total_minuman = 0, total_makanan = 0, total = 0;
	int jml1,jml2,kode1,kode2;
	  
	do {  
		cout<<"Pesanan Minuman : ";  
    	cin>>kode1>>jml1;  
     
    	if (kode1 > 4){
			break;
	 	}	 
			total_minuman += (minuman[(kode1-1)]) * jml1;
			
		} while (kode1 != 0 && jml1 !=0);  
		
	cout<<"\n\t\t\tTOTAL HARGA MINUMAN: Rp."<< total_minuman<<endl;  
   
	do {  
		cout<<"Pesanan Makanan : ";  
		cin>>kode2>>jml2;
			
		if (kode2 > 4){
			break;
		}  
		total_makanan += (makanan[(kode2-1)]) * jml2;
		      		
		} while (kode2 != 0 && jml2 !=0  );  
   		
	cout<<"\n\t\t\tTOTAL HARGA MAKANAN: Rp."<< total_makanan<<endl<<endl;
		
  	 	
	total += total_minuman + total_makanan;
	int harga_member = 0;
	harga_member = total - (total*20/100); 
	
	if (total >= 30000 && choice == 2 ){ 
			cout<<"\n\t\t\tTOTAL HARGA KESELURUHAN: Rp."<<harga_member<<endl<<endl; 
	}
   		else if (choice == 3){ 
  			cout<<"\n\t\t\tTOTAL HARGA KESELURUHAN: Rp."<< total<<endl<<endl;
	}
   		else if (choice == 2 && total < 30000){
   			cout<<"\n\t\t\tTOTAL HARGA KESELURUHAN: Rp."<< total<<endl<<endl; 
   	}
}

void create(){
	string username,password; 
		
	cout<<"Buat Username anda : ";cin>>username; 
	cout<<"Buat Password adna : ";cin>>password; 
		
	ofstream file; 
	file.open(username + ".txt"); 
	file << username << endl << password; 
	file.close(); 
	system("cls"); 
}

bool verification(int choice){


	bool status = loginmember(); 
	
	if (status == false){
	cout<<"!!! Username atau Password salah"<<endl;
	system("pause");
	system("cls");
	
	}else if(status == true)
	{
	cout<<"Dapat Potongan 20%"<<endl;
	
	system("pause"); 	
	system("cls");
	
	menu();
	beli(choice);
	review();
	
	system("pause");
	system("cls");
	}
   
}

void review(){
   	char ch= 3; 
   	char jawab; 
   	cout<<"APAKAH ANDA PUAS DENGAN PELAYANAN KAMI ? Y/N ";
   	cin>>jawab; 
   
  	   if (jawab == 'Y' || jawab == 'y'){ 
   		cout<<endl<<ch<<"DITUNGGU KEDATANGANNYA KEMBALI"<<ch<<endl<<endl; 
  	 } else if (jawab == 'N' || jawab == 'n'){ 
  	 	cout<<"\nKAMI AKAN MENINGKATKAN PELAYANAN KAMI, TERIMAKASIH ATAS PENILAIAN NYA :)"<<endl<<endl; 
  	 }
}
