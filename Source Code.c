#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct queue{
    int nomor;
    char nama[10];
    char menu[30];
    int harga;
}data[MAX];

int head = -1, tail = -1;

int banyak, total, total2, no = 0;

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

void enqueue(int p)
{
    banyak=0;
    if(isempty())
    {
        head = tail = 0;
    }
    else{
        ++tail;
        printf("\nMasukkan nomor antrian : ");
        scanf("%d", &data[tail].nomor);
        printf("\nMasukan nama pelanggan :");
        scanf("%s", &data[tail].nama);
        lihat_menu();
        printf("Banyak menu yang ingin dipesan : ");
        scanf("%d", &banyak);
        for(int i=0; i<banyak; i++)
        {
            printf("\nMenu %d      : ", i+1);
            fflush(stdin);
            fgets(data[tail].menu,30,stdin);
            printf("Harga       : ", i+1);
            scanf("%d", &data[i].harga);
        }

        total  = 0;
        total2 = 0;
        
        for(int i=0; i<banyak; i++)
        {
            total = data[i].harga + data[i+1].harga;
            total2 = total2+total;
            i++;
        }
        printf("\nTotal Bayar = %d", total);
    }data[tail].nomor = p;
}

void lihat_antrian()
{
    int i;
    if(isempty())       //Mengecek apakah ada data pada antrian atau tidak
        printf("Maaf, antrian kosong!\n");
    else
    {
        printf("\nData antrian saat ini\n");    //menampilkan data yang ada pada antrian
        printf("\nNo Antrian\tNama Pelanggan\tPesanan\n");
        for(int i=head;i<=tail;i++)
        {
            printf("   %d\t\t  %s \t\t %s \n",data[i+1].nomor,data[i+1].nama,data[i+1].menu);
        }
    }
}

void dequeue()
{

}

void clear()
{

}

void tambah_menu()
{

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
    int pil, nomor;

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
            printf("Ketik Pilihan : ");
            scanf("%d", &pil);
            switch(pil)
            {
                case 1:
                    nomor = no;
                    printf("\n===================================\n");
                    printf("       NOMOR ANTRIAN ANDA\n\t      0%d\n", no);
                    printf("    Antrian yang Menunggu : %d\n", tail);
                    no++;
                    printf("===================================\n");
                    enqueue(nomor);
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
                    lihat_menu();
                    getch();
                    break;
            }
        }while(pil!=7);
        printf("\nAnda yakin ingin keluar? Tekan 1 jika ya ");
        getch();
        return 0;
}
