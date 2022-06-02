/* 
SISTEM RESERVASI KERETA API INDONESIA - PROYEK AKHIR ALGORITMA PEMROGRAMAN-03

Muhammad Rafli Nurhidayat - 2006465924
Thoriksyah Putra - 2006466082
Zahran Mizuya Kusmana - 2006536302

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "Proyek Kereta.h"

//Function
int biodata();
int print_jadwal1();
int print_jadwal2();
int print_jadwal3();
int stasiun_asal();
int stasiun_asal_bandung();
int stasiun_asal_gambir();
int stasiun_asal_semarangtawang();
int bandung_gambir();
int bandung_semarangtawang();
int gambir_bandung();
int gambir_semarangtawang();
int semarangtawang_bandung();
int semarangtawang_gambir();
void add_node();
void bangku_kereta(void);
int harga_argoparahyangan_eksekutif();
int harga_argoparahyangan_ekonomi();
int harga_brawijaya_eksekutif();
int harga_argomuria_eksekutif();
int harga_harina_eksekutif();
int harga_harina_ekonomi();
int lihat_pemesanan();
float help();
int print_menu();

typedef struct mynode{
	char name[20];
	char gen[6];
	int age;
	struct mynode* link;
} Node;
Node* start = NULL;

struct BST
{
	int data;
	struct BST* left;
	struct BST* right;
};

typedef struct BST node;

node* root = NULL;

node* createNode(int ktp)
{
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->data=ktp;
	newnode->left=newnode->right=NULL;
	return newnode;
}

node* insert(node* root, int ktp)
{
	if(root== NULL)
	{
		root = createNode(ktp);
	}
	else if (ktp<=root->data)
	{
		root->left=insert(root->left,ktp);
	}
	else 
	{
		root->right=insert(root->right,ktp);
	}
	return root;
}

int search(node* root, int cek)
{
	int lanjut;
	if(root==NULL)
		printf("\n\nMaaf, nomor identitas %d belum terdaftar\n",cek);
	else if(cek==root->data)
	{
		lihat_pemesanan();
	}
	else
		printf("\n\nMaaf, nomor identitas %d belum terdaftar\n",cek);
}

//Var
int kereta, jam, c, a, z, i, j, n, b, temp, jumlah, harga, pilihan, lanjut, tahun, bulan, tanggal, found;
int cek;
int row1[100], column1[100], Seats[100][100];
char cetak, pesan;
char nama[10000];


int main(){
	system("COLOR F0");
	int ktp;
	//Menu Utama
	menu:
	printf("-------------------------------------------Selamat Datang Di PT KAI Indonesia-------------------------------------------\n\n");
	printf("\t\t\t\t\t       Pilih yang anda perlukan :\n");
    printf("\t\t\t\t\t       1. Pemesanan Tiket\n\t\t\t\t\t       2. View Pemesanan\n\t\t\t\t\t       3. Help\n\t\t\t\t\t       4. Exit\n\n");
    printf("\t\t\t\t\t       Masukan pilihan Anda : ");
    scanf("%d",&pilihan);
    system("cls");
    
    if(pilihan==1){
    	//Biodata
	    biodata();
	    //Pilih Stasiun Asal
	    stasiun_asal();
	    //Pilih Bangku Kereta
	    bangku_kereta();
	    
	Reserveseat:    
	    for (i=0; i<n; i++){
	        pilih_bangku:
            printf("\t\tPilih baris tempat duduk tempat duduk ke- %d (contoh: 1/2/3/4): ", i+1);
            scanf("%d", &row1[i]);
            printf("\t\tPilih kolom tempat duduk tempat duduk ke- %d (contoh: 1/2/3/4): ", i+1);
            scanf("%d", &column1[i]);
            if (row1[i] > 9 || column1[i] > 6){
		        printf("\n\n\t\tMelebihi kapasitas !! Coba lagi");
			    printf("\n\t\tSilahkan Pilih (1) untuk mengulang, (2) untuk keluar = ");
	            scanf("%d",&lanjut);
	            if(lanjut==1){
			        printf("\n");
			        bangku_kereta();
                    goto pilih_bangku;
		        }
		        else if(lanjut==2){
		            exit(0);
	            }
            }
            else if (Seats[row1[i]- 1][column1[i] - 1] != 0){
			    printf("\n\n\t\tKursi sudah direservasi!!");
			    printf("\n\t\tSilahkan Pilih (1) untuk mengulang, (2) untuk keluar = ");
	            scanf("%d",&lanjut);
	            if(lanjut==1){
			        printf("\n");
			        bangku_kereta();
                    goto pilih_bangku;
		        }
		        else if(lanjut==2){
		            exit(0);
	            }
            }
            else{
			    Seats[row1[i]- 1][column1[i] - 1] = 1;
                printf("\n\n\t\tSelamat kursi baris %d kolom %d berhasil direservasi!!\n", row1[i],column1[i]);
			    printf("\n");
                bangku_kereta();
            } 	
		}
	
	    //sorting//
	    sort(i, n, row1, column1);
			
        for (i = 0; i < n; i++)
		{	
		    printf("\n\t\tKursi Penumpang ke -%d: Kursi nomor %d%d", i+1, row1[i], column1[i]);
		}
	    printf("\n\n\t\tAnda Yakin?\n\t\tPilih \"1\" untuk selesai dan \"2\" untuk keluar \n\n\t\tAnda memilih = ");
	    scanf("%d",&lanjut); 
	    if(lanjut==1){
		    system("cls");
		    goto menu;
	    }
	    else if(lanjut==2){
		    exit(0);
    	}  
	}
	if(pilihan==2){
	    printf("Masukan nomor identitas Anda : ");
	    scanf("%d",&cek);
	    for(i=0; i<z; i++){
	    	if(ktp == cek){
	    		found = i;
			}
		}
		search(root,cek);
	}
	if(pilihan==3){
		//Print Help Desk
		help();
		printf("\n\n\t\tInput (1) Untuk Kembali Ke Menu awal, (2) Untuk Keluar   ");
	    scanf("%d",&lanjut);
	    if(lanjut==1){
		    system("cls");
		    goto menu;
	    }
	    else if(lanjut==2){
		    exit(0);
    	}
    	else if(lanjut<1 || lanjut>2){
    		printf("\t\tinput salah, program akan mengulang dari awal\n");
    		sleep(3);
    		system ("cls");
    		goto menu;
		}
	}
	if(pilihan==4){
		return 0;
	}
}

//FUNCTION

int biodata(ktp){
//	struct nama;
	printf("\n\n\t\tIdentitas Diri Pemesan:\n");
	printf("\t\tMasukan nama Anda: ");
	gets(nama);
	scanf("%[^\n]", &nama);
	printf("\t\tMasukan nomor identitas Anda (KTP) : ");
	scanf("%d",&ktp);
	root = insert(root, ktp);
		
	printf("\n\t\tPilih (1) untuk melanjutkan, (2) untuk kembali mengisi data diri, (3) untuk keluar = ");
	scanf("%d",&lanjut);
	if(lanjut==1){
			system("cls");
			print_jadwal1();
	}
	else if(lanjut==2){
	    biodata();
	}
	else if(lanjut==3){
		exit(0);
	}
}
int print_jadwal1(){
	printf("\n\t\t\t\t\tJadwal Keberangkatan\n\n");
	printf("\t\tMasukan Tanggal\t(contoh: 1, 10, 31, dsb)\t= ");
	scanf("%d",&tanggal);
	if(tanggal<1 || tanggal>31){
	    printf("\t\tTanggal yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali mengisi jadwal keberangkatan, (2) Untuk keluar ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
	        print_jadwal1();
		}
		else if(lanjut==2){
			exit(0);
		}
	}
	print_jadwal2();
}
int print_jadwal2(){
	printf("\t\tMasukan Bulan\t(contoh: 1, 10, 12, dsb)\t= ");
	scanf("%d",&bulan);
	if(bulan>12 || bulan<1){
	    printf("\t\tBulan yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali mengisi jadwal keberangkatan, (2) Untuk keluar ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
	        print_jadwal1();
		}
		else if(lanjut==2){
			exit(0);
		}
	}
	print_jadwal3();
}
int print_jadwal3(){
	printf("\t\tMasukan Tahun\t(Contoh: 2022)\t\t\t= ");
	scanf("%d",&tahun);
	if(tahun<2022 || tahun>2026){
		printf("\t\tTahun yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali mengisi jadwal keberangkatan, (2) Untuk keluar ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
	        print_jadwal1();
		}
		else if(lanjut==2){
			exit(0);
		}
 	}
}

int stasiun_asal(){
	printf("\n\t\t\t\tStasiun Asal Kereta\n\n");
	printf("\t\tPilih Stasiun Asal Kereta :\n\t\t1.Bandung\n\t\t2.Gambir\n\t\t3.Semarang Tawang\n\t\t0.Keluar\n\n\t\tMasukan pilihan Anda = ");
	scanf("%d",&b);
	if(b==0){
		exit(0);
	}
	else if(b==1){
		stasiun_asal_bandung();
	}
	else if(b==2){
		stasiun_asal_gambir();
	}
	else if(b==3){
		stasiun_asal_semarangtawang();
	}
	else if(b>3 || b<0){
		printf("\t\tInput yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali Memilih Stasiun Asal, (2) Untuk Keluar = ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
			stasiun_asal();
		}
		else if(lanjut==2){
			exit(0);
		}
	}
}
int stasiun_asal_bandung(){
	printf("\n\t\t\t\tStasiun Tujuan Kereta\n\n");
	printf("\t\tPilih Stasiun Tujuan Kereta :\n\t\t1.Gambir\n\t\t2.Semarang Tawang\n\t\t0.Keluar\n\n\t\tMasukan pilihan Anda = ");
	scanf("%d",&c);
	if(c==0){
		exit(0);
	}
	else if(c==1){
		sleep(2);
		system ("cls");
		bandung_gambir();
	}
	else if(c==2){
		sleep(2);
		system ("cls");
		bandung_semarangtawang();
	}
	else if(c>3 || c<0){
		printf("\t\tInput yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali Memilih Stasiun Asal, (2) Keluar = ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
			stasiun_asal_bandung;
		}
		else if(lanjut==2){
			system("cls");
		    exit(0);
		}
	}
}
int stasiun_asal_gambir(){
	printf("\n\t\t\t\tStasiun Tujuan Kereta\n\n");
	printf("\t\tPilih Stasiun Tujuan Kereta :\n\t\t1.Bandung\n\t\t2.Semarang Tawang\n\t\t0.Keluar\n\n\t\tMasukan pilihan Anda = ");
	scanf("%d",&c);
	if(c==0){
		exit(0);
	}
	else if(c==1){
		sleep(2);
		system ("cls");
		gambir_bandung();
	}
	else if(c==2){
		sleep(2);
		system ("cls");
		gambir_semarangtawang();
	}
	else if(c>3 || c<0){
		printf("\t\tInput yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali Memilih Stasiun Asal, (2) Untuk Keluar = ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
			stasiun_asal_gambir;
		}
		else if(lanjut==2){
			exit(0);
		}
	}
	
}
int stasiun_asal_semarangtawang(){
	printf("\n\t\t\t\tStasiun Tujuan Kereta\n\n");
	printf("\t\tPilih Stasiun Tujuan Kereta :\n\t\t1.Bandung\n\t\t2.Gambir\n\t\t0.Keluar\n\n\t\tMasukan pilihan Anda = ");
	scanf("%d",&c);
	if(c==0){
		exit(0);
	}
	else if(c==1){
		sleep(2);
		system ("cls");
		semarangtawang_bandung();
	}
	else if(c==2){
		sleep(2);
		system ("cls");
		semarangtawang_gambir();
	}
	else if(b>3 || b<0){
		printf("\t\tInput yang anda masukkan salah\n\n");
		printf("\n\n\t\tInput (1) Untuk Kembali Memilih Stasiun Asal, (2) Untuk Keluar = ");
		scanf("%d",&lanjut);
		if(lanjut==1){
			system("cls");
			stasiun_asal_semarangtawang;
		}
		else if(lanjut==2){
			exit(0);
		}
	}
}
int bandung_gambir(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                 PEMBELIAN TIKET                                     \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|    KERETA      | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Argo Parahyangan| Eksekutif |06:10 | 08:50 | 11:10 | 15:15 | 19:20 | Rp 125.000 |\n");
	printf("\t\t|2 |Argo Parahyangan| Ekonomi   |06:10 | 08:50 | 11:10 | 15:15 | 19:20 | Rp  90.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	print_menu();
	if(kereta==1){
		harga_argoparahyangan_eksekutif();
	}
	else if(kereta==2){
		harga_argoparahyangan_ekonomi();
	}
}
int bandung_semarangtawang(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                 PEMBELIAN TIKET                                     \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|    KERETA      | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Harina          | Eksekutif |20:25 | 20.45 | 22.00 | 22.20 | 23.03 | Rp 420.000 |\n");
	printf("\t\t|2 |Harina          | Ekonomi   |20:25 | 20.45 | 22.00 | 22.20 | 23.03 | Rp 240.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	print_menu();
	if(kereta==1){
		harga_harina_eksekutif();
	}
	else if(kereta==2){
		harga_harina_ekonomi();
	}
}
int gambir_bandung(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                 PEMBELIAN TIKET                                     \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|       KERETA   | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Argo Parahyangan| Eksekutif |04:55 | 06:40 | 08:10 | 10:10 | 12:30 | Rp 125.000 |\n");
	printf("\t\t|2 |Argo Parahyangan| Ekonomi   |04:55 | 06:40 | 08:10 | 10:10 | 12:30 | Rp  90.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	print_menu();
	if(kereta==1){
		harga_argoparahyangan_eksekutif();
	}
	else if(kereta==2){
		harga_argoparahyangan_ekonomi();
	}
}
int gambir_semarangtawang(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                PEMBELIAN TIKET                                      \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|    KERETA      | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Argo Muria      | Eksekutif |07:05 | 08:10 | 10:10 | 12:30 | 14.00 | Rp 350.000 |\n");
	printf("\t\t|2 |Brawijaya       | Eksekutif |15:45 | 16.10 | 16.35 | 17.40 | 18.00 | Rp 450.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	print_menu();
	if(kereta==1){
		harga_argomuria_eksekutif();
	}
	else if(kereta==2){
		harga_brawijaya_eksekutif();
	}	
}
int semarangtawang_bandung(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                 PEMBELIAN TIKET                                     \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|    KERETA      | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Harina          | Eksekutif |21:50 | 22.00 | 22.20 | 23.03 | 00.00 | Rp 420.000 |\n");
	printf("\t\t|2 |Harina          | Ekonomi   |21:50 | 22.00 | 22.20 | 23.03 | 00.00 | Rp 240.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	print_menu();
	if(kereta==1){
		harga_harina_eksekutif();
	}
	else if(kereta==2){
		harga_harina_ekonomi();
	}
}
int semarangtawang_gambir(){
	printf("\t\t*************************************************************************************\n"); 
	printf("\t\t                                 PEMBELIAN TIKET                                     \n"); 
	printf("\t\t*************************************************************************************\n\n");
	printf("\t\t                                  DAFTAR KERETA                                      \n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|No|    KERETA      | Kelas     |           JAM KEBERANGKATAN          | Harga      |\n");
	printf("\t\t|  |                |           |  1   |   2   |   3   |   4   |   5   |            |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");
	printf("\t\t|1 |Argo Muria      | Eksekutif |00:15 | 04.00 | 05.10 | 06.25 | 07.00 | Rp 350.000 |\n");
	printf("\t\t|2 |Brawijaya       | Eksekutif |00:15 | 04.00 | 05.10 | 06.25 | 07.00 | Rp 450.000 |\n");
	printf("\t\t+-------------------+-----------+------+-------+-------+-------+-------+------------+\n");	
	print_menu();
	if(kereta==1){
		harga_argomuria_eksekutif();
	}
	else if(kereta==2){
		harga_brawijaya_eksekutif();
	}	
}
int print_menu(){
	printf("\t\tPilih Kereta (1-2)\t: ");
	scanf("%d", &kereta);
	while (kereta < 1 || kereta > 2){
	printf ("\t\tError! Input Invalid!\n");
	print_menu();
	}
	printf("\t\tPilih Jam ke (1-5)\t: ");
	scanf("%d", &jam);
	while (jam < 1 || jam > 5){
	printf ("\t\tError! Input Invalid!\n");
	printf("\t\tPilih Jam ke (1-5)\t: ");
	scanf("%d", &jam);
	}
	printf("\t\tBerapa Jumlah Tiket yang Anda Pesan: ");
	scanf("%d", &n);
	char val[20], gen[6];
    for (i = 1; i <= n; i++) {
        printf("\t\tMasukan nama penumpang ke-%d: ", i);
        fflush(stdin);
        gets(val);
        printf("\t\tMasukan gender penumpang ke-%d: ", i);
        fflush(stdin);
        gets(gen);
        printf("\t\tMasukan umur penumpang ke-%d: ", i);
        fflush(stdin);
        scanf("%d", &a);
    }
	//memanggil fungsi menambahkan node disetiap data penumpang dengan linkedlist//
	add_node(val, gen, a);
}
//menambahkan detail di node masing-masing data penumpang dengan linkedlist//
void add_node(char lol[20], char der[6], int b)
{
    Node *newptr = NULL, *ptr;
    newptr = (Node*)malloc(sizeof(Node));
    strcpy(newptr->name, lol);
    strcpy(newptr->gen, der);
    newptr->age = b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else {
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}
void bangku_kereta(void){
	int a, b;
	sleep(1);
	system("cls");
    printf("\n\n\t\t\t\tSilahkan pilih tempat duduk");
    printf("\n\t\tSeats\n");
    printf("\t\t\t1 2 3 4 5 6\n");
	for (a = 0; a < 9; a++){
        printf("\t\tRows %d: ", a + 1);
        for (b = 0; b < 6; b++)
        printf("%d ", Seats[a][b]);
        printf("\n");
    }
    printf("\n");
}
int harga_argoparahyangan_eksekutif(){
	harga = n*125000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
int harga_argoparahyangan_ekonomi(){
	harga = n*90000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
int harga_brawijaya_eksekutif(){
	harga = n*450000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
int harga_argomuria_eksekutif(){
	harga = n*350000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
int harga_harina_eksekutif(){
	harga = n*420000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
int harga_harina_ekonomi(){
	harga = n*240000;
	printf("\t\tTotal Harga : %d", harga);
	sleep(2);
}
//ini nanti bisa liat summary pesenannya//
int lihat_pemesanan(){
	printf("\n\t\t\t\tRingkasan Pembelian Tiket Kereta \n",cek);
	printf("\n\t\tNama Pemesan \t\t: %s",nama);
	printf("\n\t\tJumlah Tiket \t\t: %d",n);
	printf("\n\t\tStasiun Asal \t\t: ");
	if(b==1)
	{
		printf("Bandung");
	}
	else if(b==2)
	{
		printf("Gambir");
	}
	else if(b==3)
	{
		printf("Semarang Tawang");
	}
	
	printf("\n\t\tStasiun Tujuan \t\t: ");	
	if(b==1)
	{
		if(c==1)
		{
			printf("Gambir");
		}
		else if(c==2)
		{
			printf("Semarang Tawang");
		}
	}
	else if(b==2)
	{
		if(c==1)
		{
			printf("Bandung");
		}
		else if(c==2)
		{
			printf("Semarang Tawang");
		}
	}
	else if(b==3)
	{
		if(c==1)
		{
			printf("Bandung");
		}
		else if(c==2)
		{
			printf("Gambir");
		}
	}
		
	printf("\n\t\tTanggal keberangkatan \t: %d ",tanggal);
	switch(bulan)
	{
		case 1:
			printf("Januari");
			break;
		case 2:
			printf("Februari");
			break;
		case 3:
			printf("Maret");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("Mei");
			break;
		case 6:
			printf("Juni");
			break;
		case 7:
			printf("Juli");
			break;
		case 8:
			printf("Agustus");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("Oktober");
			break;
		case 11:
			printf("November");
			break;
		case 12:
			printf("Desember");
			break;
		default:
			printf("\"bulan error\"");
			break;
	}	
	printf(" %d\n",tahun);
	
	//sorting//
	sort(i, n, row1, column1);
	
	for (i = 0; i < n; i++){	
		printf("\n\t\t  Kursi Penumpang ke -%d : Kursi nomor %d%d", i+1, row1[i], column1[i]);
	}
	printf("\n\n\t\tTagihan biaya yang didapatkan sebesar Rp%d \n\n",harga);
    printf("\t\t\t--------Terima Kasih Telah Menggunakan Jasa Kereta Kami---------\t\t\t");
}
float help(){
	printf("\n\t\t\t\t-------Layanan Kereta Api PT.KAI-------\t\t\t\t\n\n");
	printf("\n\t\t1. Penulisan nama dan nomor identitas harus sesuai dengan yang tertera \n\t\t   pada bukti identitas yang dimiliki (KTP/SIM/Pasport)");
	printf("\n\t\t2. Tarif adalah tarif per orang sekali jalan, sudah termasuk asuransi");
	printf("\n\t\t3. Pemesan tiket harap melihat intruksi pada menu yang disediakan");
	printf("\n\t\t4. Pemesan dapat melihat ringkasan pembelian tiket pada menu \"View\"\n\t\t   sebelum mencetak Tiket");
	printf("\n\t\t5. Apabila ada pertanyaan lebih lanjut silahkan hubungi Call Center 123");
}



