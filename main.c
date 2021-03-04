#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct komsular
{
    int plaka;
    struct komsular* next;

};

struct sehirler {
    int plaka;
    char sehiradi[20];
    char bolge[10];
    int komsusayisi;
    struct sehirler* next;
    struct sehirler* prev;
    struct komsular* komsu;

};
struct sehirler* start=NULL;

struct sehirler* dugumOlustur(int plaka,char sehiradi[50],char bolge[10],int ks)
 {
     struct sehirler* yeniDugum=(struct sehirler*)malloc(sizeof(struct sehirler));
     yeniDugum->plaka=plaka;
     strcpy(yeniDugum->sehiradi,sehiradi);
     strcpy(yeniDugum->bolge,bolge);
     yeniDugum->komsusayisi=ks;
     yeniDugum->next=NULL;
     yeniDugum->prev=NULL;
     return yeniDugum;
 };

void sonaEkle(int plaka,char sehiradi[50],char bolge[10],int ks)
{
    struct sehirler* sonaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    if(start==NULL)
    {
        start=sonaEklenecek;
    }
    else
    {
    //Traverse
    struct sehirler* temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    sonaEklenecek->prev=temp;
    temp->next=sonaEklenecek;

    }
}

int oku_kontrol(char buffer[200])
{
    if(isdigit(buffer[0])==1){
        return 1;
    }
        return 0;



}

void yazdir()
{
   FILE *file=fopen("cikti.txt","w");
    if(file==NULL){
        printf("Dosya acilamadi");
        exit(1);
    }
    while(start!=NULL){
        fprintf(file,"[%s Bolge:%s Plaka:%d]",start->sehiradi,start->bolge,start->plaka);
        while(start->komsu!=NULL){

            fprintf(file,"→[%d]",start->komsu->plaka);
            if(start->komsu->next==NULL) break;
            start->komsu=start->komsu->next;
        }
        fprintf(file,"\n");

        fprintf(file,"  ↑↓\n");
        if(start->next==NULL) break;
        start=start->next;
    }

    fclose(file);
}


//tek yonlu bagli liste degiskenleri ve fonksiyonlari


void add(struct komsular** yref, int yeniVeri)
{

    struct komsular* yeni = (struct komsular*) malloc(sizeof(struct komsular));
    struct komsular *sonuncu = *yref;
    yeni->plaka = yeniVeri;
    yeni->next = NULL;
    if (*yref == NULL)
    {
    *yref = yeni;
    return;
    }
    while (sonuncu->next != NULL)
    sonuncu = sonuncu->next;
    sonuncu->next = yeni;
    return;
}

//tek yönlü baðlý liste deðiþkenler ve fonksiyonlar sonu

//plaka kontrol fonksiyonlari


     void pkontrol1(struct sehirler* temp,int x,int y);

    //plaka kontrol sonu
    void ister4(char bolge[5]);
    void ister5(int a);
    void ister2(char sehir[15]);
    void ister6(int min,int max,char sehir1[15],char sehir2[15]);
    //ister3
    void sehirsil(char sehir[20]);
    void komsuSil(char sehir[20],char silinecek[20]);
    void sehirEkle(int plaka,char sehiradi[20],char bolge[10],int ks);
    void komsuEkle(char sehir[20],char eklenecek[20]);
    void sehirOku(int plaka,char sehiradi[50],char bolge[10],int ks);
int main()
{


    FILE *dosya=fopen("sehirler.txt","r");
    char buffer[200];
    int i,j,k;
    int virgul=0;
    i=0,j=0,k=0;
    if(dosya==NULL)
    {
        printf("Dosya okunamadi");
    }

    while(!feof(dosya)){

      fgets(buffer,200,dosya);

    if(buffer[strlen(buffer)-1]=='\n'){
        buffer[strlen(buffer)-1]='\0';
    }
    else{
        buffer[strlen(buffer)]='\0';
    }

        i=0,j=0,k=0;
        char sehir[50];
        char bolge[5];
        int komsusayisi=0;
        virgul=0;
        int plaka=0;
        while(buffer[i]!='\n' && buffer[i]!='\0'){
            if(isdigit(buffer[i])==1){
                while(buffer[i]!=','){
                    plaka=plaka*10+(buffer[i]-48);
                    i++;
                }
                i--;

            }
            else if(buffer[i]==',' && virgul==0){
                    i++;
                    j=0;
                while(buffer[i]!=','){
                    sehir[j]=buffer[i];
                    i++;
                    j++;
                }
                sehir[j]='\0';
                virgul++;
                i--;
            }
            else if(buffer[i]==',' && virgul==1){
                    i++;
                    j=0;
                while(buffer[i]!=','){
                    bolge[j]=buffer[i];
                    i++;
                    j++;
                }
                bolge[j]='\0';
                virgul++;
                i--;
            }
            else if(buffer[i]==',') virgul++;


            i++;

        }
                komsusayisi=virgul-2;
                sehirOku(plaka,sehir,bolge,komsusayisi);


    }
    rewind(dosya);
    char komsu_sehirler[50][50];
    int size=0;
    while(!feof(dosya)){

        int sevki=0;
        char city[50];
        i=0;
        virgul=0;
        size=0;
        j=0;
        int k=0;
        fgets(buffer,100,dosya);

    if(buffer[strlen(buffer)-1]=='\n'){
        buffer[strlen(buffer)-1]='\0';
    }
    else{
        buffer[strlen(buffer)]='\0';
    }
        while(buffer[i]!='\n' && buffer[i]!='\0'){
                    if(buffer[i]==',' && virgul<1) {
                            i++;
                            j=0;
                        while(buffer[i]!=',' && buffer[i]!='\0'){
                            city[j]=buffer[i];
                            i++;
                            j++;
                        }
                        city[j]='\0';
                        virgul++;
                        i--;
                    }
            else if(virgul==1) virgul++;
            else if(buffer[i]==',' && virgul>=2){
                    i++;
                    j=0;
                while(buffer[i]!=',' && buffer[i]!='\0'){
                    komsu_sehirler[size][j]=buffer[i];
                    i++;
                    j++;
                }
                komsu_sehirler[size][j]='\0';
                size++;
                virgul++;
                i--;
            }
            i++;
        }



        int komsup_sira[size];

        for(k=0;k<size;k++){
        while(start->next!=NULL)
        {
        if(strcmp(start->sehiradi,komsu_sehirler[k])==0)
        {
            komsup_sira[sevki]=start->plaka;
            sevki++;
            break;
        }
        start=start->next;
        }
        while(start!=NULL){
                if(start->prev==NULL) break;
                start=start->prev;
            }

    }
        for(i=0;i<sevki;i++){
            for(j=0;j<sevki-1;j++){
                if(komsup_sira[j]>komsup_sira[j+1]){
                    int t=komsup_sira[j];
                    komsup_sira[j]=komsup_sira[j+1];
                    komsup_sira[j+1]=t;
                }
            }

        }
        while(start!=NULL){
            if(strcmp(start->sehiradi,city)==0)
            {
                struct komsular *temp=NULL;
                for(i=0;i<sevki;i++){
                add(&temp,komsup_sira[i]);
                }
                start->komsu=temp;
            break;
            }
            if(start==NULL) break;
            start=start->next;
        }
        while(start!=NULL){
                if(start->prev==NULL) break;
                start=start->prev;
            }

    }

    while(start!=NULL){
                if(start->prev==NULL) break;
                start=start->prev;
            }


//menü işlemleri burada başlıyor....

while(1){
    int a;
    char bolge[5];
    int ksayisi;
    int mink,maxk;
    int plaka;
    char sehir[20];
    char sehir1[20];
    char sehir2[20];
    char silsehir[20];

    int secim;
    printf("\n\n       ---MENU---");
    printf("\n 1-Yeni bir sehir/komsuluk ekle.");
    printf("\n 2-Sehir bilgisi ara.");
    printf("\n 3-Bir sehir/komsuluk dugumu sil.");
    printf("\n 4-Bolgeye gore sehir bilgileri goruntule.");
    printf("\n 5-Komsu sayisina gore sehir goruntule.");
    printf("\n 6-Belli bir sayi araliginda komsu sayisina sahip sehirlerden belirli ortak komsulara sahip olan sehirlerin listele.");
    printf("\n Cikis icin -1'e basiniz.");
    printf("\n Yapmak istediginiz islemi seciniz:");
    scanf("%d",&secim);

    switch(secim){
    case -1:
    yazdir();
    printf("\n Cikis islemi yapildi...");
    exit(1);

    case 1:

    printf("\n Sehir ekleme icin 1'e,komsu eklemek icin 2'ye basiniz:");
    scanf("%d",&a);
    if(a==1)
    {
        printf("\n Eklemek istediginiz sehrin plakasini yaziniz:");
        scanf("%d",&plaka);

        printf("\n Eklemek istediginiz sehrin ismini yaziniz:");
        scanf("%s",sehir);

        printf("\n Eklemek istediginiz sehrin bolgesinin kisaltmasini yaziniz:");
        scanf("%s",bolge);

        printf("\n Eklemek istediginiz sehrin komsu sayisini yaziniz:");
        scanf("%d",&ksayisi);
        sehirEkle(plaka,sehir,bolge,ksayisi);
    }
    if(a==2)
    {
        printf("\n Hangi sehre komsu eklemek istiyorsunuz?:");
        scanf("%s",sehir1);
        printf(" Eklemek istediginiz sehrin ismi nedir?:");
        scanf("%s",sehir2);
        komsuEkle(sehir1,sehir2);
    }
    break;

    case 2:

    printf("\n Bilgilerini goruntulemek istediginiz sehrin adini girin:");
    scanf("%s",sehir);
    ister2(sehir);
    break;

    case 3:
    printf("\n Sehir silmek icin 1'e,komsu silmek icin 2'ye basiniz:");
    scanf("%d",&a);


    if(a==1)
    {
        printf("\n Silmek istediginiz sehri yaziniz:");
        scanf("%s",silsehir);
        sehirsil(silsehir);
    }
    if(a==2)
    {
        printf("\n Hangi sehirden komsuluk silmek istiyorsunuz?:");
        scanf("%s",sehir1);
        printf("\n   Silmek istediginiz komsu sehir nedir?:");
        scanf("%s",sehir2);
        komsuSil(sehir1,sehir2);
    }


    break;

    case 4:
    printf("\n Sehirlerini gormek istediginiz bolgenin kisaltmasini giriniz:");
    scanf("%s",bolge);
    ister4(bolge);
    break;

    case 5:

    printf("\n Komsu sayisini giriniz:");
    scanf("%d",&ksayisi);
    ister5(ksayisi);
    break;


    case 6:

    printf("\n Min komsu sayisini giriniz:");
    scanf("%d",&mink);
    printf("\n Max komsu sayisini giriniz:");
    scanf("%d",&maxk);
    printf("\n Aratmak istediginiz 1.ortak komsuyu giriniz:");
    scanf("%s",sehir1);
     printf("\n Aratmak istediginiz 2.ortak komsuyu giriniz:");
    scanf("%s",sehir2);
    ister6(mink,maxk,sehir1,sehir2);


    break;


    default:
    printf(" Hatali bir deger girdiniz.Lutfen tekrar deneyiniz.");
    break;



    }

}



    return 0;

}
void ister4(char bolge[5])
{
    struct sehirler* temp=start;
    while(temp!=NULL)
    {
        if(!strcmp(temp->bolge,bolge)==1){
        printf(" %d %s %s %d\n",temp->plaka,temp->sehiradi,temp->bolge,temp->komsusayisi);

        }
        temp=temp->next;

    }
}
void ister5(int a)
{
    printf("\n Komsu sayisi %d ve uzeri olan iller:\n",a);
    struct sehirler* temp=start;
    while(temp!=NULL)
    {
        if(temp->komsusayisi>=a){
        printf(" %s -> %d komsu \n",temp->sehiradi,temp->komsusayisi);

        }
        temp=temp->next;

    }
}
void ister2(char b[20])
{
    struct komsular* a=NULL;
    int kontrol=0;
    int plaka,ksayisi;
    char bolge[10];
    int tercih;
    struct sehirler* temp=start;
    while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,b)){
        printf("\n Sehir adi: %s",temp->sehiradi);
        printf("\n Plaka kodu: %d",temp->plaka);
        printf("\n Bolge: %s",temp->bolge);
        printf("\n Komsu sayisi:%d\n",temp->komsusayisi);
        a=temp->komsu;
        kontrol++;
        printf(" Komsular:\n");

        while(a!=NULL){
            temp=start;
        while(temp->next!=NULL){
            if(temp->plaka==a->plaka){
                break;
            }
            temp=temp->next;
        }
            printf(" ->%s Plaka:%d Bolge: %s\n",temp->sehiradi,a->plaka,temp->bolge);
            a=a->next;
        }

        }
        temp=temp->next;

    }
    if(kontrol==1)
    {
        return;
    }
        if(kontrol==0){
        printf("\n Aradiginiz sehir bulunamadi.Eklemek ister misiniz?(EVET=1 HAYIR=0):");
        scanf("%d",&tercih);

        if(tercih==1){
        printf("\n Eklemek istediginiz sehrin plakasini yaziniz:");
        scanf("%d",&plaka);

        printf("\n Eklemek istediginiz sehrin bolgesinin kisaltmasini yaziniz:");
        scanf("%s",bolge);

        printf("\n Eklemek istediginiz sehrin komsu sayisini yaziniz:");
        scanf("%d",&ksayisi);
        sehirEkle(plaka,b,bolge,ksayisi);
        }
        if(tercih==0){
        printf("\n  Ekleme islemi yapmak istemediniz.Menuye donuluyor...\n");

        }

    }
}
void ister6(int min,int max,char sehir1[15],char sehir2[15])

{
    struct sehirler* temp=start;
    int plaka1,plaka2;

    while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehir1)){
        plaka1=temp->plaka;
        }
        temp=temp->next;

    }

    temp=start;
      while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehir2)){
        plaka2=temp->plaka;
        }
        temp=temp->next;

    }



    printf("\n Komsu sayisi %d ile %d arasinda olan illerden %s ve %s illerine komsu olan iller:\n",min,max,sehir1,sehir2);

    temp=start;


    while(temp->next!=NULL)
    {
         if(max>=temp->komsusayisi&&min<=temp->komsusayisi){


        pkontrol1(temp,plaka1,plaka2);

        }
        temp=temp->next;

    }


}

   void pkontrol1(struct sehirler* temp,int x,int y)
    {

    struct sehirler* q=temp;
    int a=0,b=0;
    struct komsular* ilk=q->komsu;
            while(q->komsu->next!=NULL){

                if(q->komsu->plaka==x)
                {
                    a=1;


                }
                if(q->komsu->plaka==y)
                {
                   b=1;

                }


                q->komsu=q->komsu->next;


            }
        q->komsu=ilk;
        if(a+b==2){
            printf("->%s\n",q->sehiradi);

        }
    }

void sehirsil(char sehir[20])
    {

    struct sehirler* temp=start;
    struct sehirler* bulunan=NULL;
     while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehir)){
        bulunan=temp;
        break;
        }
        temp=temp->next;

    }
    if(bulunan==NULL)
    {
        printf("\n  Silmek istediginiz sehir yok!");
        return;
    }

    if(bulunan->prev==NULL)
    {
    //bastan silme.
    struct sehirler* ikinci=start->next;
    free(start);
    ikinci->prev=NULL;
    start=ikinci;

    }
    //sondan silme
    else if(bulunan->next==NULL)
    {
    struct sehirler* onceki=bulunan->prev;
    bulunan->komsu=NULL;
    free(bulunan);
    onceki->next=NULL;
    }
    //aradan silme
    else
    {
    struct sehirler* onceki=bulunan->prev;
    struct sehirler* sonraki=bulunan->next;
    bulunan->komsu=NULL;
    free(bulunan);
    onceki->next=sonraki;
    sonraki->prev=onceki;

    }

    printf("\n  Silme islemi gerceklesti.\n");
    }
void komsuSil(char sehir[20],char silinecek[20]){
    int plaka=0;
    int kontrol=0;
    struct sehirler* temp=start;
    struct sehirler* bulunan=NULL;

      while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehir)){
        bulunan=temp;
        break;
        }
        temp=temp->next;

    }

    temp=start;
    while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,silinecek)){
        plaka=temp->plaka;
        }
        temp=temp->next;

    }

    struct komsular* q=bulunan->komsu;



    while(q!=NULL){

        if(q->plaka==plaka)
        {
            kontrol++;
            break;

        }
        q=q->next;
    }


    if(kontrol==0)
    {
        printf("\n   Silmeye calistiginiz komsuluk mevcut degil!!");
        return;
    }

    //bastan silme
    if(q->plaka==bulunan->komsu->plaka)
    {
    struct komsular *ikinci=NULL;
    ikinci=bulunan->komsu->next;
    free(bulunan->komsu);
    bulunan->komsu=ikinci;
    bulunan->komsusayisi--;
    printf("\n   Komsuluk silindi.");
    return;
    }

    //Sondan silme

    if(q->next==NULL){
    q=bulunan->komsu;
    while(q->next->next!=NULL)
    {
        q=q->next;
    }
    free(q->next);
    q->next=NULL;
    bulunan->komsusayisi--;
    printf("\n   Komsuluk silindi.");
    return;
    }
   //ortadan silme
    else
    {

     struct komsular* onceki=NULL;
     struct node* sonraki=NULL;
     q=bulunan->komsu;

     while(q->next->plaka!=plaka)
     {
        q=q->next;
     }

     onceki=q;
     sonraki=q->next->next;
     free(q->next);
     onceki->next=sonraki;
     bulunan->komsusayisi--;
     printf("\n   Komsuluk silindi.\n");
     return;
     }

}
 void sehirEkle(int plaka,char sehiradi[20],char bolge[10],int ks)
 {

    struct sehirler* temp;
    temp=start;
    while(temp->next!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehiradi)==1||temp->plaka==plaka){
            printf("\n Ayni plakali veya adli,sehir ekleyemezsiniz!!\n");
            return;
        }

        temp=temp->next;
    }


    temp=start;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    //sona ekleme

    if(plaka>(temp->plaka)){
    struct sehirler* sonaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    sonaEklenecek->prev=temp;
    temp->next=sonaEklenecek;
    printf("  \n Sehir eklendi.");
    return;


}

    if(plaka<start->plaka)
    {
    struct sehirler* basaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    start->prev=basaEklenecek;
    basaEklenecek->next=start;
    start=basaEklenecek;
    printf("  \n Sehir eklendi.");
    return;
    }
    else{
        sehirOku(plaka,sehiradi,bolge,ks);
        printf(" \n Sehir eklendi!!");
        return;
    }

    }
void komsuEkle(char sehir[20],char eklenecek[20])
{

    struct sehirler* temp=start;
    struct komsular *baslangic=NULL;
    struct komsular *q=NULL;
    struct sehirler* bulunan=NULL;

    int plaka=0;
    while(temp!=NULL)
    {
        if(!strcmp(temp->sehiradi,sehir))
        {
            bulunan=temp;
        }

        if(temp->next==NULL) break;
        temp=temp->next;
    }

    temp=start;


    while(temp->next!=NULL)
    {
        if(!strcmp(temp->sehiradi,eklenecek)){
        plaka=temp->plaka;
        break;
        }
        if(temp->next==NULL) break;
        temp=temp->next;

    }

    baslangic=bulunan->komsu;
    q=baslangic;

    while(q!=NULL)
    {
        if(q->plaka==plaka){
            printf("\n Ayni plakali veya adli,sehir ekleyemezsiniz!!\n");
            return;
        }

        q=q->next;
    }





    if(bulunan->komsu==NULL)
    {



        struct komsular *oldu=(struct komsular*)malloc(sizeof(struct komsular));
        oldu->plaka=plaka;
        oldu->next=NULL;

        if(oldu->next==NULL)
        {

        }
        struct komsular *temp=NULL;

        add(&temp,plaka);

        bulunan->komsu=temp;
        bulunan->komsusayisi++;
        printf("\n Komsuluk eklendi!!");
        return;
    }

    q=baslangic;
    while(q->next!=NULL)
    {
        q=q->next;
    }

    //sona ekleme
    if(plaka>(q->plaka)){

    struct komsular *eklenen=(struct komsular*)malloc(sizeof(struct komsular));
    eklenen->plaka=plaka;
    eklenen->next=NULL;

    q->next=eklenen;

    printf("\n  Komsuluk eklendi!!\n");
    bulunan->komsusayisi++;

    return;
    }
    if(plaka<(baslangic->plaka))
    {
         struct komsular *basaGelecek=(struct komsular*)malloc(sizeof(struct komsular));
            basaGelecek->plaka=plaka;
            basaGelecek->next=baslangic;
            bulunan->komsu=basaGelecek;
            printf("\n  Komsuluk eklendi!!\n");
            bulunan->komsusayisi++;

        return;

    }
    //araya ekleme

    else
    {
    struct komsular* onune=(struct komsular*)malloc(sizeof(struct komsular));
    struct komsular* arayaEklenecek=(struct komsular*)malloc(sizeof(struct komsular));
    q=bulunan->komsu;

    while(q!=NULL){

        if(plaka<(q->plaka)){
            onune=q;
            break;
        }
        q=q->next;
    }

    arayaEklenecek->plaka=plaka;
    q=bulunan->komsu;

    while(q->next->plaka!=onune->plaka)
    {

    q=q->next;
    }


    onune=q->next;
    q->next=arayaEklenecek;
    arayaEklenecek->next=onune;


            bulunan->komsusayisi++;
    printf("\n Komsuluk eklendi!!");
    return;

    }

    }

void sehirOku(int plaka,char sehiradi[50],char bolge[10],int ks)
{

    struct sehirler* temp=start;
    if(start==NULL)
    {
    struct node* basaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    start=basaEklenecek;
    return;

    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

   //basa ekleme
    if(plaka<(start->plaka)){
    struct sehirler* basaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    start->prev=basaEklenecek;
    basaEklenecek->next=start;
    start=basaEklenecek;
    return;
    }
    //sona ekleme
    if(plaka>(temp->plaka)){
    struct sehirler* sonaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    //Traverse
    struct sehirler* temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    sonaEklenecek->prev=temp;
    temp->next=sonaEklenecek;
    return;

    }

    //Araya ekleme
    else
    {
    struct sehirler* temp=start;
    struct sehirler* arayaEklenecek=dugumOlustur(plaka,sehiradi,bolge,ks);
    struct sehirler* onceki=NULL;
    struct sehirler* kiminonune=NULL;
    while(temp->next!=NULL){
        if((temp->plaka)>plaka){
            kiminonune=temp;
        break;
        }
        temp=temp->next;
    }
    temp=start;
    while(temp->next!=NULL)
    {
        if(temp->plaka==kiminonune->plaka)
        {
            onceki=temp->prev;
            break;

        }
        temp=temp->next;

    }
    temp->prev=arayaEklenecek;
    arayaEklenecek->next=temp;
    arayaEklenecek->prev=onceki;
    onceki->next=arayaEklenecek;
    return;

    }

    }
