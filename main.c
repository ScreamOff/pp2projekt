#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int wyswietltablicewynikow(int tablica[]){
  int sumatablicy =0;
  for(int i = 0;i<14;i++){
    sumatablicy=sumatablicy+tablica[i];
    printf("%d\n", tablica[i]);
  }
  return sumatablicy;
}
void wyswietlanie_kosci(int liczba){
    switch(liczba)
    {
        case 1: printf("---------\n|       |\n|   o   |\n|       |\n---------\n");
            break;
        case 2: printf("---------\n|  o    |\n|       |\n|    o  |\n---------\n");
            break;
        case 3: printf("---------\n|  o    |\n|   o   |\n|    o  |\n---------\n");
            break;
        case 4: printf("---------\n|  o o  |\n|       |\n|  o o  |\n---------\n");
            break;
        case 5: printf("---------\n|  o o  |\n|   o   |\n|  o o  |\n---------\n");
            break;
        case 6: printf("---------\n|  o o  |\n|  o o  |\n|  o o  |\n---------\n");
            break;
        default:;
    }
}
void selectionsort(int tablica[]){
    int min,i,j,temp;
    for (i=0;i<5-1;i++)
    {
    min=i;
    for (j=i+1;j<5;j++)
    if (tablica[j]<tablica[min]) min=j;
    temp=tablica[min];
    tablica[min]=tablica[i];
    tablica[i]=temp;
  }}
void wyswietlanie_tytul(){
    int a;
    printf("                                       ________________________________________________\n");
    printf("                                     |   __  ___   ______        _______.  ______  __  |\n");
    printf("                                     |  |  |/  /  /  __  \\      /       | /      ||  | |\n");
    printf("                                     |  |  '  /  |  |  |  |    |   (----`|  ,----'|  | |\n");
    printf("                                     |  |    <   |  |  |  |     \\   \     |  |     |  | |\n");
    printf("                                     |  |  .  \\  |  `--'  | .----)   |   |  `----.|  | |\n");
    printf("                                     |  |__|\__\\   \\______/  |_______/     \\______||__| |\n");
    printf("                                       ________________________________________________\n");
    puts("wprowadz jeden zeby zaczac\n");
    scanf("%d", &a);
    system ("tput clear");


}
int para(int *karty) {
    int i, j, para;
    for (i = 0; i < 5; i++) {
        para = 0;
        for (j = i + 1; j < 5; j++) {
            if (karty[j] == karty[i]) {
                para++;
            }
        }
        if (para == 1) {
            return 1;
        }
    }
    return 0;
}
int dwiePary(int *karty) {
    int i, j, para1, para2;
    para1 = para2 = 0;
    int suma = 0; // dodane
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (karty[j] == karty[i]) {
                if (para1 == 0) {
                    para1 = karty[j];
                } else if (karty[j] != para1 && para2 == 0) {
                    para2 = karty[j];
                }
            }
        }
    }
    if (para1 != 0 && para2 != 0) {
        suma = para1 * 2 + para2 * 2; // oblicz sum� oczek obu par
        return suma;
    } else {
        return 0;
    }
}
int punkty_para(int *karty) {
    int i, j, para;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        para = 0;
        for (j = i + 1; j < 5; j++) {
            if (karty[j] == karty[i]) {
                para++;
                suma_pkt = karty[j] + karty[i];
            }
        }
        if (para == 1) {
            return suma_pkt;
        }
    }
    return 0;
}
int punkty_trojka(int *karty) {
    int i, j, para;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        para = 0;
        for (j = i + 1; j < 5; j++) {
            if (karty[j] == karty[i]) {
                para++;
                suma_pkt = karty[i];
            }
        }
        if (para == 2) {
            return 3*suma_pkt;
        }
    }
    return 0;
}
int trojka(int *karty) {
    int i, j, para;
    for (i = 0; i < 5; i++) {
        para = 0;
        for (j = i + 1; j < 5; j++) {
            if (karty[j] == karty[i]) {
                para++;
            }
        }
        if (para == 2) {
            return 1;
        }
    }
    return 0;
}
int strit(int *karty) {
    int i;
    for (i = 0; i < 4; i++) {
        if (karty[i + 1] != karty[i] + 1) {
            return 0;
        }
    }
    return 1;
}
int general(int *kosci) {
    int i, j;
    for (i = 0; i < 5; i++) {
        int licznik = 0;
        for (j = 0; j < 5; j++) {
            if (kosci[j] == kosci[i]) {
                licznik++;
            }
        }
        if (licznik == 5) {
            return 1;
        }
    }
    return 0;
}
int kareta(int *kosci) {
    int i, j;
    for (i = 0; i < 5; i++) {
        int licznik = 0;
        for (j = 0; j < 5; j++) {
            if (kosci[j] == kosci[i]) {
                licznik++;
            }
        }
        if (licznik == 4) {
            return 1;
        }
    }
    return 0;

}
int punkty_jednyka(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 1)
            repeat++;
    }

    return repeat*1;
}
int punkty_dwojka(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 2)
            repeat++;
    }

    return repeat*2;
}
int punkty_trojki(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 3)
            repeat++;
    }

    return repeat*3;
}
int punkty_cztery(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 4)
            repeat++;
    }

    return repeat*4;
}
int punkty_piec(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 5)
            repeat++;
    }

    return repeat*5;
}
int punkty_szesc(int *kosci) {
    int i;
    int repeat = 0;
    int suma_pkt = 0;
    for (i = 0; i < 5; i++) {
        if (kosci[i] == 6)
            repeat++;
    }

    return repeat*6;
}


int wybor_dodania_punktow(int *kosci,int tablicawynikow[]){
    int n;
    int m;
    int punkty;
    printf("Do czego chcesz dodac punkty 0(para),1(dwie pary), 2(trojka), 3(kareta), 4(maly strit) , 5(duzy strit), 6(kareta) ,\n 7(general) , 8(jednyki), 9(dwujki) , 10(trojki), 11(czworki) , 12(piatki), 13(szostki) : ");

    scanf("%d", &n);
    switch(n)
    {
        case 0:
            if(para(kosci))
            {
                punkty = punkty_para(kosci);
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        case 1:
            {
                punkty = dwiePary(kosci);
                tablicawynikow[n]=punkty;
                break;
            }

        case 2:
            if(trojka(kosci))
            {
                punkty = punkty_trojka(kosci);
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        case 3:
            if(kareta(kosci))
            {
                punkty = kosci[0]+kosci[1]+kosci[2]+kosci[3];
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        case 4:
            if(strit(kosci)&& kosci[0] == 1)
            {
                punkty = 15;
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        case 5:
            if(strit(kosci)&& kosci[0] == 2)
            {
                punkty = 20;
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        case 6:
            if(general(kosci))
            {
                punkty = 30;
                tablicawynikow[n]=punkty;
            }
            else
            {
                break;
            }
        case 7:{
            if(para(kosci)&&trojka(kosci))
            {
                punkty = punkty_trojka(kosci)+ punkty_para(kosci) + 10;
                tablicawynikow[n]=punkty;
                break;
            }
            else
            {
                break;
            }
        }
        case 8:{
            punkty = punkty_jednyka(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        case 9:{
            punkty = punkty_dwojka(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        case 10:{
            punkty = punkty_trojki(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        case 11:{
            punkty = punkty_cztery(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        case 12:{
            punkty = punkty_piec(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        case 13:{
            punkty = punkty_szesc(kosci);
            tablicawynikow[n]=punkty;
            break;
        }
        default:
            printf("Nie podales zadnej z liczb\n");
    }


    return punkty;}
int rzutkoscia(){

      int kosc;
      kosc= (rand ()%6 )+ 1;
      //wyswietlanie_kosci(kosc);
      return kosc;
    }
void wyswietlanieMozliwosci(int tablicawynikowGracza[]){
  printf("Zostaly opcje nr\n");
  for(int i = 0;i<14;i++){
    if(tablicawynikowGracza[i]== -1){
      printf("%d\n", i);
    }
  }
}
int sprawdzanietablicywynikow(int pozycja ,int tablicawynikowGracza[],int punkty){
    if(tablicawynikowGracza[pozycja]== -1)
    {
      tablicawynikowGracza[pozycja]= punkty;

      return 1;
    }
    else{
      puts("Za oszukiwanie sie przegrywa :)");
      sleep(5);

      return 0;
    }
}
void ponownelosowanie(int tablica[]){
  int ilekosci, j;
  printf("ile kosci chcesz wybrac do zwrotu:\n");
  scanf("%d",&ilekosci);
  for(int i=0;i<ilekosci;i++){
    printf("podaj numer indexu %d. kosci:\n ",i);
    scanf("%d", &j);
    tablica[j]= rzutkoscia();
    sleep(2);
    printf("ZOSTALA WYLOSOWANA: %d\n",tablica[j]);
    }

}
void wyswietltablice(int tablica[]){
  for(int i = 0;i<5;i++){
    printf("%d\n", tablica[i]);
  }
}
int sprawdzczypelna(int tablica[]){
  for(int i=0;i<14;i++){
    if(tablica[i]==-1){
      return 0;
    }
  }
  return 1;}
void turaGracza1(char gracz[],int punktygracza,int tablicawynikow[],int kosci[]){
  system("clear");
  int i=0;
  wyswietlanieMozliwosci(tablicawynikow);
  sleep(2);
  system("clear");
  for(i=0;i<5;i++){
    kosci[i]=rzutkoscia();
    wyswietlanie_kosci(kosci[i]);
  }
  selectionsort(kosci);
  ponownelosowanie(kosci);
  selectionsort(kosci);
  system("clear");
  for(i=0;i<5;i++){
  wyswietlanie_kosci(kosci[i]);}
  ponownelosowanie(kosci);
  selectionsort(kosci);
  for(i=0;i<5;i++){
  wyswietlanie_kosci(kosci[i]);}
  wyswietlanieMozliwosci(tablicawynikow);
  wybor_dodania_punktow(kosci,tablicawynikow);
  sleep(2);
  system("clear");
  wyswietltablicewynikow(tablicawynikow);
  sleep(1);
  system("clear");



}
int gra1(){
  char gracz1[40];
  char gracz2[40];
  int punktygracza1=0;
  int punktygracza2=0;
  int tablicawynikow1[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int tablicawynikow2[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int kosci[5];
  srand(time(NULL));
  wyswietlanie_tytul();
  sleep(2);
  system("clear");

  do {
    puts("tura gracza nr 1");
    sleep(1);
    turaGracza1(gracz1,punktygracza1,tablicawynikow1,kosci);
    puts("tura gracza nr 2");
    sleep(1);
    turaGracza1(gracz2,punktygracza2,tablicawynikow2,kosci);
  } while(sprawdzczypelna(tablicawynikow1)==0);
  punktygracza1=wyswietltablicewynikow(tablicawynikow1);
  punktygracza2=wyswietltablicewynikow(tablicawynikow2);

  if(punktygracza1>punktygracza2){
    puts("gracz1 wygrywa");
  }
  else if(punktygracza1<punktygracza2){
    puts("gracz2 wygrywa");
  }
  else{
    puts("remis");
  }


  return 0;
  }
int gra2(){
    int kosc=0;
    int guess=0;
    int punkty=0;
    do {
      /* code */

    kosc=rzutkoscia();
    puts("(1)nieparzyste? czy (2)parzyste");
    scanf("%d",guess);
    if(kosc%2==guess){
      punkty=punkty+1;
    }    } while(punkty<10);
}


int main(){

  system("clear");
  puts("ktora gre chcesz zagrac? 1(poker),2(p//np)");
  int gamechoice=0;
  scanf("%d",&gamechoice);
  if(gamechoice==1){
    system("clear");
    gra1();
  }
  else{
    gra2();
  }
}
