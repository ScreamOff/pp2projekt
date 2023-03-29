#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const int N5=5;
const int N14=14;

typedef struct tablica
{
    int *T;
    int dlugosc;
}Tablica;

typedef struct gracz
{

   int punkty;
   Tablica wyniki;
   Tablica kosci;
}Gracz;

Gracz inicjuj()
{
    int i;
    Gracz G;
    G.punkty=0;
    G.wyniki.dlugosc=N14;
    G.wyniki.T=(int *)malloc(N14*sizeof(int));
    for(i=0;i<N14;i++) G.wyniki.T[i]=-1;
    G.kosci.dlugosc=N5;
    G.kosci.T=(int *)malloc(N5*sizeof(int));
    for(i=0;i<N5;i++) G.kosci.T[i]=0;
    return G;
}

int wyswietltablicewynikow(Tablica tab)
{
  int i, sumatablicy =0;
  for(i=0;i<tab.dlugosc;i++){
    sumatablicy=sumatablicy+tab.T[i];
    printf("%d, ", tab.T[i]);
  }
  printf("\n");
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

void wyswietlenie_kosci1(Tablica tab)
{
	int i;
	printf("Twoje kosci: ");
	for(i=0;i<tab.dlugosc;i++) printf("%d, ",tab.T[i]);
	printf("\n");
}

int para(Tablica kosci)
{
    int i, j, para=0, wynik=0;
    int *p; //p[i] przechowuje ile jest oczek o numerze i, czyli na przyklad p[5] przechowuje ile jest piatek
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for(i=1;i<7;i++) if(p[i]==2) para++;
    if(para==1)
    {
      for(i=1;i<7;i++) if(p[i]==2) wynik=wynik+2*i;
    }
    free(p);
    return wynik;
}

int dwiePary(Tablica kosci)
{
    int i, j, pary=0, wynik=0;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for(i=1;i<7;i++) if(p[i]==2) pary++;
    if(pary==2)
    {
      for(i=1;i<7;i++) if(p[i]==2) wynik=wynik+2*i;
    }
    free(p);
    return wynik;

}


int trojka(Tablica kosci)
{
int i, j, tr=0, pa=0, wynik=0;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for(i=1;i<7;i++)
    {
      if(p[i]==3) tr=1; //zliczam tam gdzie jest trojka
      if(p[i]==2) pa++; //ale moze tez byc para gdzies indziej
    }

    if(tr==1 && pa!=1) //czyli jest trojka, ale w innych nie ma pary, czyli nie ma fulla
    {
      for(i=1;i<7;i++) if(p[i]==3) wynik=3*i;
    }
    free(p);
    return wynik;
}

int malystrit(Tablica kosci) {
    int i, wynik=1; //zakladam ze jest strit
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for (i=1;i<=5;i++) {
        if (p[i]!=1) wynik=0; //jezeli gdzies jest wiecej niz 1, to nie ma strita i daje wynik na 0
    }
    if(wynik) wynik=15; //jezeli jest maly strit
    free(p);
    return wynik;
}

int duzystrit(Tablica kosci) {
    int i, wynik=1;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for (i=2;i<=6;i++) {
        if (p[i]!=1) wynik=0;
    }
    if(wynik) wynik=20; //jezeli jest duzy strit
    free(p);
    return wynik;
}

int full(Tablica kosci)
{
int i, j, tr=0, pa=0, wynik=0;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<kosci.dlugosc;i++) p[kosci.T[i]]++;
    for(i=1;i<7;i++)
    {
      if(p[i]==3) tr=1; //zliczam tam gdzie jest trojka
      else
      if(p[i]==2) pa++; //ale moze tez byc para gdzies indziej
    }

    if(tr==1 && pa==1) //czyli jest trojka i para czyli full
    {
      wynik=25;
    }
    free(p);
    return wynik;
}

int general(Tablica kosci)
{
    int i, j, gen=0, wynik=0;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<5;i++) p[kosci.T[i]]++;
    for(i=1;i<7 && p[i]!=5;i++) if(p[i]==5) gen=i;
    free(p);
    if(gen) return 30;

}
int kareta(Tablica kosci)
{
    int i, j, kar=0, wynik=0;
    int *p;
    p=(int*)malloc(7*sizeof(int));
    for(i=0;i<7;i++) p[i]=0;
    for(i=0;i<5;i++) p[kosci.T[i]]++;
    for(i=1;i<7 && p[i]!=4;i++) if(p[i]==4) kar=i; //zapamietuje jaki numer tworzy karete
    free(p);
    if(kar) return 4*kar;
}

int jedynki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 1)
            suma++;
    }
    return suma;
}
int dwojki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 2)
            suma++;
    }
    return 2*suma;
}
int trojki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 3)
            suma++;
    }

    return 3*suma;
}
int czworki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 4)
            suma++;
    }

    return 4*suma;
}
int piatki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 5)
            suma++;
    }
    return 5*suma;
}

int szostki(Tablica kosci) {
    int i;
    int suma = 0;
    for (i = 0; i < kosci.dlugosc; i++) {
        if (kosci.T[i] == 6)
            suma++;
    }
    return 6*suma;
}


Gracz wybor_dodania_punktow(Gracz G){
    int n;
    int m;
    int punkty;
    printf("Do czego chcesz dodac punkty 0(para),1(dwie pary), 2(trojka), 3(kareta), 4(maly strit) , 5(duzy strit), 6(full) ,\n 7(general) , 8(jedynki), 9(dwojki) , 10(trojki), 11(czworki) , 12(piatki), 13(szostki) : ");

    do{
    scanf("%d", &n);
    switch(n)
    {
        case 0:
            punkty = para(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 1:
            punkty = dwiePary(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 2:
            punkty = trojka(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 3:
            punkty = kareta(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 4:
            punkty = malystrit(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 5:
            punkty = duzystrit(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 6:
            punkty=full(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 7:
            punkty = general(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 8:
            punkty = jedynki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 9:
            punkty = dwojki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 10:
            punkty = trojki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 11:
            punkty = czworki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 12:
            punkty = piatki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        case 13:
            punkty=szostki(G.kosci);
            G.wyniki.T[n]=punkty;
            break;
        default:
            printf("Nie podales zadnej z liczb\n podaj jeszcze raz: \n");
    }}while(n>13);
    return G;
}

int rzutkoscia()
{
      int kosc;
      kosc= (rand ()%6 )+ 1;
      return kosc;
}

void wyswietlanieMozliwosci(Tablica tab)
{
	int i;
  printf("Zostaly opcje nr\n");
  for(i = 0;i<tab.dlugosc;i++){
    if(tab.T[i]== -1) printf("%d, ", i);
  }
  printf("\n");
}
Gracz sprawdzanietablicywynikow(Gracz G, int pozycja ,int punkty){
    if(G.wyniki.T[pozycja]== -1) G.wyniki.T[pozycja]= punkty;
    else puts("Za oszukiwanie sie przegrywa ??");
    return G;
}

Tablica indeksydozmiany() //funkcja zwracajaca tablice indeksow do zmiany
{
	int i, ile, ind;
	Tablica R;
    printf("(pierwsza kosc to 0) Ile kosci chcesz wybrac do zwrotu: ");
    scanf("%d", &ile);
    if(ile>=0 && ile<=5) //jezeli liczba indeksow do zmiany jest w sensownym zakresie czyli 0...5
    {
	   R.dlugosc=ile;
       if(ile>0)R.T=(int*)malloc(ile*sizeof(int));
       for(i=0;i<ile;i++)
       {
	      printf("Podaj nr %d indeksu do zmiany: ", i+1);
          scanf("%d", &ind);
          if(ind>=0 && ind<5) R.T[i]=ind; else //jezeli numer indeksu do zmiany jest w zakresie 0...4
          {
	         R.T[i]=-1; //jezeli nie to wstawiam -1, wtedy przy zmianie to pomine
             printf("Niewlasciwy numer indeksu do zmiany, brak zmiany\n");
          }
       }
    } else printf("Niewlasciwa liczba kosci do zwrotu\n");
    return R;
}

Gracz ponownelosowanie(Gracz G)
{
  Tablica Z;
  int i;
  Z=indeksydozmiany(); //wczytanie indeksow do zmiany funkcja poprzednia
  for(i=0;i<Z.dlugosc;i++){ //przegladam tablice zmian
	if(G.kosci.T[Z.T[i]]>=0) //jezeli indeks ma liczbe 0...4, czyli nie ma tam -1
    G.kosci.T[Z.T[i]]= rzutkoscia(); //to w tablicy kosci podmieniam ponownym losowaniem
    //sleep(2);
    }
    if(Z.dlugosc>0) free(Z.T); //jezeli tablica ma dlugosc przynajmniej 1 czyli gracz cos wybral do zmiany, to zwalniam ja
    return G;
}

void wyswietltablice(Tablica tab){
  int i;
  for(i = 0;i<tab.dlugosc;i++){
    printf("%d, ", tab.T[i]);
  }
  printf("\n");
}

int sprawdzczypelna(Tablica tab)
{
  int i;
  for(i=0;i<tab.dlugosc;i++)
  {
    if(tab.T[i]==-1) return 0;
  }
  return 1;
}


Gracz turaGracza(Gracz G)
{
  int i=0;
  wyswietlanieMozliwosci(G.wyniki);
  //sleep(2);
  for(i=0;i<5;i++){
    G.kosci.T[i]=rzutkoscia();
    wyswietlanie_kosci(G.kosci.T[i]);
  }
  wyswietlenie_kosci1(G.kosci);
  G=ponownelosowanie(G);
  for(i=0;i<5;i++){
  wyswietlanie_kosci(G.kosci.T[i]);}
  wyswietlenie_kosci1(G.kosci);
  G=ponownelosowanie(G);
  for(i=0;i<5;i++){
  wyswietlanie_kosci(G.kosci.T[i]);}
  wyswietlenie_kosci1(G.kosci);
  wyswietlanieMozliwosci(G.wyniki);
  G=wybor_dodania_punktow(G);
  //sleep(2);
  wyswietltablicewynikow(G.wyniki);
  //sleep(1);
  return G;
}

void gra1()
{
  Gracz G1, G2;
  G1=inicjuj();
  G2=inicjuj();
  //sleep(2);

  do {
    puts("tura gracza nr 1");
    //sleep(1);
    G1=turaGracza(G1);
    puts("tura gracza nr 2");
    //sleep(1);
    G2=turaGracza(G2);
  } while(sprawdzczypelna(G1.wyniki)==0);
  G1.punkty=wyswietltablicewynikow(G1.wyniki);
  G2.punkty=wyswietltablicewynikow(G2.wyniki);
  if(G1.punkty>G2.punkty) puts("gracz1 wygrywa");
  else if(G1.punkty<G2.punkty) puts("gracz2 wygrywa");
  else puts("remis");
}

int gra2(){
    short int kosc=0;
    short int kosc2=0;
    short int guess=0;
    int cash=100;
    int wybor = 1;


    while(cash > 0 || wybor == 1)
    {
        int bet;
        printf("twoje pieniadze %d $\n",cash);
        printf("ile pienidzy chcesz betowac : ");
        scanf("%d", &bet);
        kosc=rzutkoscia();
        kosc2=rzutkoscia();
        puts("czy suma kosci jest : (0)parzysta czy (1)nieparzysta?" );
        scanf("%d",&guess);
        if ((kosc+kosc2) % 2 == 0 && guess == 0)
        {
            wyswietlanie_kosci(kosc);
            wyswietlanie_kosci(kosc2);
            printf("suma byly parzysta");
            cash = cash + bet;
        }
        else if((kosc+kosc2) % 2 == 1 && guess == 1)
        {
            wyswietlanie_kosci(kosc);
            wyswietlanie_kosci(kosc2);
            printf("suma byly nieparzysta");
            cash = cash + bet;
        }
        else if((kosc+kosc2) % 2 == 0 && guess == 1)
        {
            wyswietlanie_kosci(kosc);
            wyswietlanie_kosci(kosc2);
            printf("suma byly parzysta");
            cash = cash - bet;
        }
        else if((kosc+kosc2) % 2 == 1 && guess == 0)
        {
            wyswietlanie_kosci(kosc);
            wyswietlanie_kosci(kosc2);
            printf("kosci byly nieparzysta");
            cash = cash - bet;
        }

        int tak_nie;
        printf("\nczy chesz zagrac dalej?(0(tak)/1(nie) : ");
        scanf("%d",&tak_nie);
        if(tak_nie == 1)
        {
            printf("\ntwoje pieniadze %d $\n",cash);
            break;
        }
    }

}


int main()
{
  srand(time(NULL));
  printf("Ktora gre wybierasz 1(gra w kosci), 2(p//pn): ");
  int gamechoice = 0;
  scanf("%d",&gamechoice);
  if(gamechoice == 1)
  {
      gra1();
  }
  else if(gamechoice ==2)
  {
      gra2();
  }
  else{
    printf("nie podana wlasciwego numeru");
  }

}
