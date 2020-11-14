/*Programma cifratura di un messaggio.
  Riccardo Cristofani
  N.matricola:330205*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
time_t tempo;

#define ncaratteri  128  //127 caratteri possibili (del messaggio) + l'ultimo di fine stringa "/0".

char str_messaggio[ncaratteri];
char str_chiave[ncaratteri];
char str_mes_cifrato[ncaratteri];

unsigned int n_p;//numero procedura
int Lung_messaggio, Lung_chiave, Lung_mcifrato;

//FUNZIONI:

  //(LEGGO LA CHIAVE INSERITA DA TASTIERA)
  void procedura1(){
    //leggo chiave
    printf("Inserire una chiave:\n");
    while (getchar()!='\n');//svuoto il buffer
    fgets(str_chiave, ncaratteri, stdin);

    //controllo la chiave
    Lung_chiave = strlen(str_chiave);
    printf("Lunghezza chiave:%d\n", Lung_chiave);
    while(Lung_chiave < Lung_messaggio){
        printf("inserire una chiave più lunga: \n");
        fgets(str_chiave,ncaratteri,stdin);
        Lung_chiave = strlen(str_chiave);
    }
    //chiave ok, la stampo
    printf("la tua chiave è: %s\n",str_chiave );
  }

  //(GENERO LA CHIAVE)
  void procedura2(){
    //genero caratteri random dal 33 al 127, tanti quanti sono i caratteri del messaggio
    for (int i = 0; i < Lung_messaggio ; i++) {
      str_chiave[i] = rand()%(127-33+1)+33 ;//(vmax-vmin+1)+vmin
    }
    printf("la tua chiave è:\n");
    printf("%s\n",str_chiave );
    Lung_chiave = strlen(str_chiave);
  }

int main() {
  srand((unsigned) time(&tempo));

/*leggo messaggio e lo stampo*/
  do{
    printf("Scrivi il tuo messaggio:");
    fgets(str_messaggio, ncaratteri ,stdin);//prende da tastiera: ncaratteri-1('/0') cioè 127.
    Lung_messaggio = strlen(str_messaggio);
  }while (Lung_messaggio == 1);
  while (getchar()!='\n');//svuoto il buffer
  printf("Il tuo messaggio è:%s\n",str_messaggio);

/*scelta della procedura*/
  printf("\nScegliere la procedura da seguire:\n");
  printf("-Digitare 1 se si vuole inserire manualmente una chiave\n");
  printf("-Digitare 2 se si vuole generare casualmente una chiave \n");
  scanf("%u",&n_p );

  //controllo ed eseguo una delle due procedure
  while (n_p == 0 || n_p > 2){
    printf("Il tuo numero %u non è corretto,riprovare \n",n_p);
    scanf("%u",&n_p );
  }
  if (n_p == 1) {
    printf("È stata scelta la procedura numero 1\n");
    procedura1();
  }
  else if(n_p == 2){
    printf("È stata scelta la procedura numero 2\n");
    procedura2();
  }

/*cifratura*/
  for (int i=0; i < Lung_messaggio; i++)
    str_mes_cifrato[i] = str_messaggio[i] ^ str_chiave[i];

  printf("Messaggio cifrato:\n");
  printf("%s\n",str_mes_cifrato );

/*decifratura*/
  for (int i=0; i < Lung_messaggio; i++)
    str_messaggio[i] = str_mes_cifrato[i] ^ str_chiave[i];
  printf("\nIl messaggio decifrato è: \n");
  printf("%s\n",str_messaggio);

  return 0;
}
