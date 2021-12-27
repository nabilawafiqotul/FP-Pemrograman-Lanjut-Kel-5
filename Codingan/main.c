#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ======= KELOMPOK 5 ======= 
//	Nabila Wafiqotul Azizah        20081010140
//	Hanif Nur Fadillah            20081010231
//	Leonhoss Hutagaol            20081010215
//	Farhan Jelang Ramadhan        20081010213
//	Dipika Syaiban Ainun            20081010216


void menampilkan();
void mencari();
void memperbarui();
void pembelian();
void mengurutkan();
void keluar();

typedef struct SiPan{
    char nama_restoran [150]; 
    char nama_makanan [100][100];
	float harga_makanan[100];
	char lokasi_restoran[50];
	int stok_slrh;
}data_SiPan;

data_SiPan SiPan[100];

int i,b,c,e,a,n = 0;
int j;
char batas[100];
char yakin[10];

void pembuat_data_menu(int n, char array_makanan[6][100], float array_harga[6]){
	for(i = 0; i < 6; i++){
		strcpy(SiPan[n].nama_makanan[i], array_makanan[i]);
		SiPan[n].harga_makanan[i] =  array_harga[i];
	}
}

void menu(){
 int pilih;
 
printf("||==============================================||\n");
printf("||\t\tAPLIKASI Si-Pan\t\t\t||\n");
printf("||\tSELAMAT DATANG DI APLIKASI Si-Pan\t||\n");
printf("||==============================================||\n");
	printf("||==============================================||\n");
	printf("||\t\tSILAHKAN MEMILIH MENU		||\n");
	printf("||==============================================||\n");
	getch();
	printf("|| 1. Menampilkan data restoran			||\n");
	printf("|| 2. Mengupdate data restoran			||\n");
	printf("|| 3. Mengurutkan data restoran			||\n");
	printf("|| 4. Mencari data restoran			||\n");
	printf("|| 5. Pembelian Makanan ke Restoran		||\n");
	printf("|| 6. Keluar Si-Pan				||\n");
	printf("||==============================================||\n");
	printf("||==============================================||\n");
	printf("Pilihan [1..6]:"); scanf("%d",&pilih );

	printf("\n\n");
	switch(pilih){
		case 1:
			menampilkan();
		break;
		case 2:
			memperbarui();
		break;
		case 3:
			mengurutkan();
		break;
		case 4:
			mencari();
		break;
		case 5:
			pembelian();
		break;
		case 6:
			keluar();
			exit;
		break;
		default :
			printf (" Maaf Inputan yang Anda Masukkan Tidak Ada di Menu, Silahkan Anda Memilih Menu Kembali :) \n");
			menu();
		break;
	}
}


void menampilkan(){
	system ("cls");
	for(n = 0; n < 11; n++){
	printf("Data berada di indeks ke - %d\n",n);
       			printf("Nama Restoran		: %s\n",SiPan[n].nama_restoran);
				printf("Lokasi Restoran         : %s\n",SiPan[n].lokasi_restoran);
				printf("Daftar Menu Restoran	: \n");
					for(i = 0; i < 6; i++){
				printf(" %s	= %.3f\n" , SiPan[n].nama_makanan[i], SiPan[n].harga_makanan[i]);
				}
				printf("Stok Makanan Secara Keseluruhan = %d" ,SiPan[n].stok_slrh);
				printf("\n\n");
	}
	
	printf("Jika ingin kembali ke menu ketik '1' dan jika ingin keluar ketik '0' : ");
	scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}
		
}


void mencari(){
	char kota [100]; 
	char namaresto [150];
	
		printf("1. Mencari melalui kota \n");
		printf("2. Mencari melalui nama restoran \n");
		printf ("Pilihlah Opsi Diatas yang sesuai Kebutuhan Anda [1..2]: "); scanf("%d", &a);
		if (a==1){
			printf ("Masukkan data dari nama kota yang ingin dicari makanan : ");fflush(stdin); gets(kota);
			for( n = 0; n<11; n++){
				if(strcmp(kota,SiPan[n].lokasi_restoran) == 0) {
					printf("Data berada di indeks ke - %d\n",n);
	       			printf("Nama Restoran         : %s\n",SiPan[n].nama_restoran);
					printf("Lokasi Restoran       : %s\n",SiPan[n].lokasi_restoran);
					printf("Daftar Menu Restoran  : \n");
						for(i = 0; i < 6; i++){
							printf ("%s = %.3f\n" , SiPan[n].nama_makanan[i], SiPan[n].harga_makanan[i]);
						}
					printf ("Stok Makanan Secara Keseluruhan = %d" ,SiPan[n].stok_slrh);
					printf("\n\n");
				}
			}
        		if (n>11){
				printf("Data tidak ada");
				}
	printf("Jika ingin kembali ke menu ketik '1' dan jika ingin keluar ketik '0' : ");
	scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}			
		}
		
	if (a==2){
		printf ("Masukkan data dari nama restoran yang ingin dicari makanan : ");fflush(stdin); gets(namaresto);
			for( n = 0; n<11; n++){
		if(strcmp(namaresto,SiPan[n].nama_restoran) == 0){
				printf("data berada di indeks ke - %d\n",n);
       			printf (" Nama Restoran       	: %s\n",SiPan[n].nama_restoran);
				printf (" Lokasi Restoran       : %s\n",SiPan[n].lokasi_restoran);
				printf ("Daftar Menu Restoran	: \n");
					for(i = 0; i < 6; i++){
						printf (" %s = %.3f\n" , SiPan[n].nama_makanan[i], SiPan[n].harga_makanan[i]);
					}
				printf (" Stok Makanan Secara Keseluruhan = %d" ,SiPan[n].stok_slrh);
				printf("\n\n");
			}
		}
			if(n>11){
				printf("Data tidak ada");
			}
	}
	printf("Jika ingin kembali ke menu ketik '1' dan jika ingin keluar ketik '0' : ");
	scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}
		
}

void memperbarui(){
	int stok_mkn;
	printf ("Masukkan stok makanan yang ingin diupdate : "); scanf("%d", &stok_mkn);

	for( n = 0; n<11; n++){
		if(SiPan[n].stok_slrh == stok_mkn){
				system("cls");
				printf (" Stok Makanan Secara Keseluruhan = "); scanf("%d", &SiPan[n].stok_slrh);
				printf (" Nama Restoran       	: %s\n",SiPan[n].nama_restoran);
				printf (" Lokasi Restoran       : %s\n",SiPan[n].lokasi_restoran);
				printf ("Daftar Menu Restoran	: \n");
				for(i = 0; i < 6; i++){
				printf (" %s = %.3f\n" , SiPan[n].nama_makanan[i], SiPan[n].harga_makanan[i]);
			} 
			break;
		}
		else{
			printf("Data tidak ada\n");
		}
	}
	printf("\nJika ingin kembali ke menu ketik '1' dan jika ingin keluar ketik '0' : ");
	scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
				printf("Terima kasih...");
			exit;
		}
		
}


void pembelian(){
	char resto[150];
	char mkn[150];
	float unit;
	float byr;
	float hrg;
	float nml;
	float kembalian;
	
	printf("Masukkan restoran yang ingin Anda kunjungi			: "); fflush(stdin); gets(resto);
	printf("Masukkan makanan yang ingin Anda beli pada restoran tersebut	: "); fflush(stdin); gets(mkn);
	printf("Masukkan jumlah makanan yang ingin Anda beli			: "); scanf("%d",&unit);
	printf("Masukkan harga per makanan					: "); scanf("%d",&hrg);
		
	if ((strcmp(resto,SiPan[n].nama_restoran) == 0) || (unit>0)){
	printf("Pembelian Anda Sedang Diproses, Mohon Ditunggu!!\n\n");
}
else {
		("Pembelian Anda Ditolak, Silahkan Pilih Menu Kembali !!");
	}
		for( n = 0; n<11; n++){
		for(i = 0; i < 6; i++){
		byr = unit*hrg;
		}
		}

		printf("\nJumlah yang harus anda bayarkan sebesar Rp %f", byr);
		printf("\nMasukkan nominal yang dibayarkan (dalam satuan angka): "); scanf("%d",&nml);
		if(nml>byr){
			kembalian=nml-byr;
			printf("\n\nUang kembalian bernilai Rp %d", kembalian);
		}
		else if(nml==byr){
			printf("\n\nTidak ada uang kembalian!!");
		}
		else{
			printf("\n\n Uang yang Anda berikan kurang dari nominal pembayaran, silahkan masukkan tambahan uang !!");
		}
		printf("\n\n Makanan Sudah Siap, Silahkan Menikmati, Semoga Hari Anda Menyenangkan :)\n\n ");
		
printf("Jika ingin kembali ke menu ketik '1' dan jika ingin keluar ketik '0' : ");
scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}	
}

void mengurutkan(){
	char insernamamkn[100];
	char insernamaresto[100];
	char inserlksresto[100];
	float inserharga;
	int inserstok;
		
	 	printf("1. Mengurutkan Data Secara Ascending \n");
	 	printf("2. Mengurutkan Data Secara Descending \n");
	  	printf("Pilihlah Opsi Diatas yang sesuai Kebutuhan Anda [1..2]: "); scanf("%d", &e);
		
	if (e==1){
		for ( b = 0; b < 11; b++) {
			c=b;
			while(c>0 && strcmp(SiPan[c-1].nama_restoran, SiPan[c].nama_restoran) > 0){
			
     			strcpy (insernamaresto, SiPan[c].nama_restoran);
	 			strcpy (SiPan[c].nama_restoran, SiPan[c-1].nama_restoran);
     			strcpy (SiPan[c-1].nama_restoran, insernamaresto);

     			strcpy (inserlksresto, SiPan[c].lokasi_restoran);
	 			strcpy (SiPan[c].lokasi_restoran, SiPan[c-1].lokasi_restoran);
     			strcpy (SiPan[c-1].lokasi_restoran, inserlksresto);
     				
				strcpy (insernamamkn, SiPan[c].nama_makanan[i]);
	 			strcpy (SiPan[c].nama_makanan[i], SiPan[c-1].nama_makanan[i]);
     			strcpy (SiPan[c-1].nama_makanan[i], insernamamkn);

     			inserharga = SiPan[c].harga_makanan[i];
	 			SiPan[c].harga_makanan[i] = SiPan[c-1].harga_makanan[i];
     			SiPan[c-1].harga_makanan[i] = inserharga;
     			
     			inserstok =  SiPan[c].stok_slrh;
	 			SiPan[c].stok_slrh =  SiPan[c-1].stok_slrh;
     			SiPan[c-1].stok_slrh = inserstok;
     			
     			--c;
			}
	}
	printf("Jika ingin melihat hasil pengurutkan\n silahkan ke menu menampilkan data, ketik '1' untuk ke menu dan jika ingin keluar ketik '0' : ");
	scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}
			
}
	if (e==2){
		for ( b = 0; b < 11; b++) {
			c=b;
			while(c>0 && strcmp(SiPan[c-1].nama_restoran, SiPan[c].nama_restoran) < 0){
				
     			strcpy (insernamaresto, SiPan[c].nama_restoran);
	 			strcpy (SiPan[c].nama_restoran, SiPan[c-1].nama_restoran);
     			strcpy (SiPan[c-1].nama_restoran, insernamaresto);

     			strcpy (inserlksresto, SiPan[c].lokasi_restoran);
	 			strcpy (SiPan[c].lokasi_restoran, SiPan[c-1].lokasi_restoran);
     			strcpy (SiPan[c-1].lokasi_restoran, inserlksresto);
     			
     			strcpy (insernamamkn, SiPan[c].nama_makanan[i]);
	 			strcpy (SiPan[c].nama_makanan[i], SiPan[c-1].nama_makanan[i]);
     			strcpy (SiPan[c-1].nama_makanan[i], insernamamkn);

     			inserharga = SiPan[c].harga_makanan[i];
	 			SiPan[c].harga_makanan[i] = SiPan[c-1].harga_makanan[i];
     			SiPan[c-1].harga_makanan[i] = inserharga;
     			
     			inserstok =  SiPan[c].stok_slrh;
	 			 SiPan[c].stok_slrh =  SiPan[c-1].stok_slrh;
     			 SiPan[c-1].stok_slrh = inserstok;
     			
     			--c;
			}
		}
	}
	
printf("Jika ingin melihat hasil pengurutkan\n silahkan ke menu menampilkan data, ketik '1' untuk ke menu dan jika ingin keluar ketik '0' : ");
scanf("%d", &j);
	
		if(j == 1 ){
			printf("\n");
			system("cls");
			menu();
		} else{
			printf("Terima kasih...");
			exit;
		}
		
}


void keluar(){
				
	system("cls");
	printf("===Keluar Program ===\n\n");				
	printf("Anda yakin akan keluar?\nKetik 'ya' jika ingin keluar : ");
	scanf("%s",& yakin);				
	if( strcmp(yakin, "ya") ){
    	printf("\n");
    	system("cls");
		menu();
  	} else {
        printf("\nTerima Kasih...");
    	exit;
		}	
						
}

int write(){
	char *filename = "SiPan.txt";

	// open the file for writing
   	FILE *BSiPan = fopen(filename, "w");
    if (BSiPan == NULL)
	{
	    printf("Error opening the file %s", filename);
	    return -1;
    }

	for( n = 0; n < 11; n++){
        fprintf(BSiPan,"\nNama Restoran : %s\nLokasi Restoran : %s\nStok Makanan Secara Keseluruhan : %d\n",&SiPan[n].nama_restoran,&SiPan[n].lokasi_restoran,&SiPan[n].stok_slrh);
       	for( i = 0; i < 6; i++){
       		fprintf(BSiPan, "\n%s = %.3f\n", &SiPan[n].nama_makanan[i], &SiPan[n].harga_makanan[i]);
       	}
    }
    // close the file
	fclose(BSiPan);
	return 0;
}

int isiData(){
	//dt 1
	strcpy(SiPan[0].nama_restoran,"Warung Apung Rahmawati");
	strcpy(SiPan[0].lokasi_restoran,"Sidoarjo");
	char makanan1[6][100] = {"Ayam Bakar Rujak","Gurami Bakar Kecap","Kepiting soka telur asin","Bandeng Bakar tanpa duri","Cumi goreng crispy","udang asam manis"};
	float harga1[6] = {68.000,68.000,66.000,45.000,45.000,56.000};
	pembuat_data_menu(0, makanan1, harga1);
	SiPan[0].stok_slrh = 900;
	
	// dt 2
	strcpy(SiPan[1].nama_restoran,"Lesehan joyo");
	strcpy(SiPan[1].lokasi_restoran,"Sidoarjo");
	char makanan2[6][100] = {"Paket A","Paket B","Paket C","Paket D","Paket E","Paket F"};
	float harga2[6] = {375.000,475.000,528.000,565.000,788.000,788.000};
	pembuat_data_menu(1, makanan2, harga2);
	SiPan[1].stok_slrh =  600;

	//dt 3
	strcpy(SiPan[2].nama_restoran,"Warung Nako");
	strcpy(SiPan[2].lokasi_restoran,"Bogor");
	char makanan3[6][100] = {"Camilan Hari Ini","Eskrim Matcha NAKO","Eskrim Vanilla","Kopi Nusantara","Chocolate","Latte"};
	float harga3[6] = {15.000,10.000,10.000,27.000,25.000,29.000};
	pembuat_data_menu(2, makanan3, harga3);
	SiPan[2].stok_slrh = 1100;
	
	//dt  4
	strcpy(SiPan[3].nama_restoran,"Pak D");
	strcpy(SiPan[3].lokasi_restoran,"Sidoarjo");
	char makanan4[6][100] = {"Ayam Boiler","Ayam Bakar","Bebek Goreng","Gurame Bakar","Paket A","Paket B"};
	float harga4[6] = {28.000,28.000,33.000,50.000,18.000,22.000};
	pembuat_data_menu(3, makanan4, harga4);
	SiPan[3].stok_slrh = 750;
	
	//dt 5
	strcpy(SiPan[4].nama_restoran,"Botanika");
	strcpy(SiPan[4].lokasi_restoran,"Surabaya");
	char makanan5[6][100] = {"Kroket Rendang","Lumpia Mini","Kids Meal","Botanika Tea Set","Cah Kangkung","Es Jeruk Nipis"};
	float harga5[6] = {38.000,36.000,35.000,110.000,35.000,20.000};
	pembuat_data_menu(4, makanan5, harga5);
	SiPan[4].stok_slrh = 600;
	
	//dt 6
	strcpy(SiPan[5].nama_restoran,"Rawon Rosobo");
	strcpy(SiPan[5].lokasi_restoran,"Jombang");
	char makanan6[6][100] = {"Rawon","Rames","Sayur Asem","Ayam Goreng","Cah Kangkung","Es Teh"};
	float harga6[6] = {28.000,35.000,10.000,25.000,11.000,5.000};
	pembuat_data_menu(5, makanan6, harga6);
	SiPan[5].stok_slrh = 1000;
	
	//dt 7
	strcpy(SiPan[6].nama_restoran,"Repoeblik Telo");
	strcpy(SiPan[6].lokasi_restoran,"Jombang");
	char makanan7[6][100] = {"Bakso","Cwimie","Soto Ayam","Rawon","Jus Telo","Es Teh"};
	float harga7[6] = {23.000,20.000,25.000,25.000,8.000,5.000};
	pembuat_data_menu(6, makanan7, harga7);
	SiPan[6].stok_slrh = 820;
	
	//dt 8
	strcpy(SiPan[7].nama_restoran,"Javanine Resto");
	strcpy(SiPan[7].lokasi_restoran,"Malang");
	char makanan8[6][100] = {"Semur Lidah","Tahu Brontak","Nasi Buk Javanine","Penyet Ikan Pari","Nasi Sop Buntut","Nasi Iga Penyet"};
	float harga8[6] = {60.000,18.000,60.000,38.000,75.000,35.000};
	pembuat_data_menu(7, makanan8, harga8);
	SiPan[7].stok_slrh = 620;
	
	//dt 9
	strcpy(SiPan[8].nama_restoran,"Rajungan Ndoro Bei");
	strcpy(SiPan[8].lokasi_restoran,"Tuban");
	char makanan9[6][100] = {"Udang Cereal","Cumi Siram Pedas","Kerapu Uyah Lombok","Kakap Lada Hitam","Gurame Asam Manis","Rajungan Tepung"};
	float harga9[6] = {47.900,49.900,47.900,54.900,44.900,115.000};
	pembuat_data_menu(8, makanan9, harga9);
	SiPan[8].stok_slrh = 790;
	
	//dt 10
	strcpy(SiPan[9].nama_restoran,"Pawon Cabe");
	strcpy(SiPan[9].lokasi_restoran,"Gresik");
	char makanan10[6][100] = {"Bebek Goreng Rica-Rica","Ayam Penyet","Bakso Penyet","Udang Penyet","Lele Penyet","Jus Alpukat"};
	float harga10[6] = {35.000,23.000,25.000,33.000,23.000,15.000};
	pembuat_data_menu(9, makanan10, harga10);
	SiPan[9].stok_slrh = 1200;
	
	//dt 11
	strcpy(SiPan[10].nama_restoran,"Soto Gading");
	strcpy(SiPan[10].lokasi_restoran,"Solo");
	char makanan11[6][100] = {"Nasi Soto Biasa","Nasi Soto Brutu","Nasi Soto Pisah","Nasi Soto Separuh","Empal","Paru"};
	float harga11[6] = {7.000,7.000,11.000,4.000,4.000,3.500};
	pembuat_data_menu(10, makanan11, harga11);
	SiPan[10].stok_slrh = 1300;
}

int main(){
	
	int aktif = 1;
	isiData();
	write();
	menu();
}
