#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct queue{
    char nama[10];
    int banyak;
    int total;
    int nomor;
    struct pesanan{
        char menu[30];
        int harga;
    }data[MAX];
}antrian[MAX];

int head = -1, tail = -1,no_order=1;

int isempty()
{
    if(tail == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(tail == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue()
{
    if(isempty()){
        head = tail = 0;
        enqueue();
    }
    else if(isfull()){
        printf("\nAntrian Sudah Penuh!");
    }
    else{
        printf("\n===================================\n");
        printf("       NOMOR ANTRIAN ANDA\n\t      0%d\n", no_order);
        printf("    Antrian Yang Menunggu : %d\n", tail);
        printf("===================================\n");
        printf("\nMasukan Nama Pelanggan : ");
        fflush(stdin);
        fgets(antrian[tail].nama,10,stdin);
        //lihat_menu();
        printf("Banyak menu yang ingin dipesan : ");
        scanf("%d", &antrian[tail].banyak);
        for(int i=0; i<antrian[tail].banyak; i++)
        {
            printf("\nMenu %d      : ", i+1);
            fflush(stdin);
            fgets(antrian[tail].data[i].menu,30,stdin);
            printf("Harga       : ", i+1);
            scanf("%d", &antrian[tail].data[i].harga);
        }
        antrian[tail].total=0;
        for(int i=0; i<antrian[tail].banyak; i++)
        {
            antrian[tail].total = antrian[tail].total + antrian[tail].data[i].harga;
        }
        printf("\nTotal Bayar = %d", antrian[tail].total);
        antrian[tail].nomor = no_order;
        ++no_order;
        ++tail;
    }
}

void lihat_antrian()
{
    if(isempty()){
        printf("\nMaaf, antrian kosong!\n");
    }
    else{
        printf("\nData Antrian Saat Ini :\n");
        printf("\nNo Antrian\tNama Pelanggan\tPesanan\n");
        for(int i=head;i<tail;i++)
        {
            int count = antrian[i].banyak;
            printf("%d\t\t%s",antrian[i].nomor,antrian[i].nama);
            for(int j=0;j<count;j++){
                printf("\t\t\t\t%s\n",antrian[i].data[j].menu);
            }
        }
    }
}

void dequeue()
{
    int count;
    if(isempty()){
        printf("\nMaaf, antrian kosong!\n");
    }
    else{
        for(int i=head;i<tail;i++){
            if(antrian[i].banyak>antrian[i+1].banyak){
                count=antrian[i].banyak;
            }
            if(antrian[i].banyak>antrian[i+1].banyak){
                count=antrian[i].banyak;
            }
            if(antrian[i].banyak<antrian[i+1].banyak){
                count=antrian[i+1].banyak;
            }
            for(int j=0;j<count;j++){
                strcpy(antrian[i].data[j].menu,antrian[i+1].data[j].menu);
                antrian[i].data[j].harga = antrian[i+1].data[j+1].harga;
            }
            strcpy(antrian[i].nama,antrian[i+1].nama);
            antrian[i].banyak = antrian[i+1].banyak;
            antrian[i].total = antrian[i+1].total;
            antrian[i].nomor = antrian[i+1].nomor;
        }
        tail--;
        printf("\nAntrian Berhasil Dihapus!");
    }
}

void clear()
{
    if(isempty()){
        printf("\nMaaf, antrian kosong!\n");
    }
    else{
        head=tail=-1;
        printf("\nAntrian Berhasil Dikosongkan!");
    }
}

void tambah_menu()
{
    name *s
    int n, i, j;
    printf("Berapa Menu yang ingin ditambahkan? : ");
    scanf("%d",&n);
    
    s = (name*)calloc(n, sizeof(name));
    
    for(i=0;i<n;i++) {
        printf("Masukan Nomor : ");
        scanf ("%d",&s[i]);
        fflush(stdin);
        printf("Masukan Menu  :");
        scanf ("%[^\n]s",s[i].menu);
        for(j=0;j<1;j++){
            printf("Masukan Harga %d : ", j+1);
            scanf ("%d",&s[i].sub[j].mark); 
        }
    } 
}

void lihat_menu()
{

}

void title(){
    system ("cls");
    printf("=============== PROGRAM ANTRIAN RUMAH MAKAN ===============\n\n");
}

int main()
{
    int pil,out;

    do{
            title();
            printf("Pilihan Menu : \n");
            printf("   1. Tambah Antrian\n");
            printf("   2. Lihat Antrian\n");
            printf("   3. Pelayanan\n");
            printf("   4. Kosongkan Antrian\n");
            printf("   5. Tambah Menu\n");
            printf("   6. Lihat Menu\n");
            printf("   7. Exit\n");
            printf("\nKetik Pilihan : ");
            scanf("%d", &pil);
            switch(pil)
            {
                case 1:
                    enqueue();
                    getch();
                    break;
                case 2 :
                    lihat_antrian();
                    getch();
                    break;
                case 3 :
                    dequeue();
                    getch();
                    break;
                case 4 :
                    clear();
                    getch();
                    break;
                case 5 :
                    tambah_menu();
                    getch();
                    break;
                case 6 :
                    //lihat_menu();
                    getch();
                    break;
            }
        }while(pil!=7);
        printf("\nAnda Yakin Ingin Keluar? Tekan 1 Jika Ya ");\
        scanf("%d",&out);
        if(out!=1){
            main ();
        }
        return 0;
}
