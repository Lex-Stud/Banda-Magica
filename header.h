 // LUCIU Alexandru-Cristian 311CB
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
  
  
  typedef struct celula {
   char id;
   struct celula *urm, *ant;
  }TCelula, *TLista;

  typedef struct banda {
  TLista L;
  TLista crt;
} *TBanda;
   
  typedef struct coada {
    char id[20];
    struct coada *urm;
  }*TCoada;

  typedef struct undo {
    TLista locatie;
    struct undo *urm;
  } *Tundo;

  TCoada alocCoada(char id[20]);
  TLista alocCel(char id);
  TBanda initializareLista();
  void SHOW(TBanda B);
  TLista MOVE_LEFT(TLista L, TLista crt);
  TLista MOVE_RIGHT(TLista L, TLista crt);
  TLista MOVE_RIGHT_CHAR(TLista L, TLista crt, char c);
  TLista MOVE_LEFT_CHAR(TLista L, TLista crt, char c);
  void WRITE(TLista *crt, char new);
  TLista INSERT_LEFT(TLista L, TLista crt, char c);
  TLista INSERT_RIGHT(TLista L, TLista crt, char c);
  void SHOW_CURRENT(TLista crt);
  TCoada creezCoada(TCoada L, char *comanda);
  void adaugUndo(Tundo *L, TLista crt);
  void DistrugeLista(TLista *aL);
  void eliberareBanda(TBanda *B);
  void eliberareUNDO(Tundo *U);
