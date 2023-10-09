// LUCIU Alexandru-Cristian 311CB*

#include "header.h"

TLista alocCel(char id) {
  TLista L = (TLista) malloc(sizeof(TCelula));
  if (!L) {
    printf("Nu s-a alocat memorie pt alocCel");
    exit(-1);
  }
  L -> id = id;
  L -> urm = NULL;
  L -> ant = NULL;

  return L;
}

TBanda initializareLista() { // de facaut acasa
  TBanda B = (TBanda) malloc(sizeof(struct banda));
  if (B == NULL) {
    printf("NU s-a alocat memorie pt initializareLista\n");
    exit(-1);
  }
  TLista aux = alocCel('*'); //folosesc * ca unica valoare pentru Santinela
  if (aux == NULL) {
    printf("NU s-a alocat memorie pt initializareLista\n");
    exit(-1);
  }
  B -> L = aux;
  TLista primaCEl = alocCel('#'); //  initializez lista cu santinela
  if (primaCEl == NULL) {
    printf("Nu s-a alocat memorie pt initializareLista\n");
    exit(-1);
  }
  aux -> urm = primaCEl;
  aux -> ant = NULL;
  primaCEl -> urm = NULL;
  primaCEl -> ant = aux;
  B -> crt = primaCEl;

  return B;
}

void SHOW(TBanda B) {
  TLista aux = NULL;
  FILE * out = fopen("tema1.out", "a");
  if (out == NULL) {
    printf("Nu s-a deschs fierul tema1.out\n");
    eliberareBanda( & B);
    exit(-1);
  }
  for (aux = B -> L -> urm; aux != NULL; aux = aux -> urm) {
    if (B -> crt == aux) { // verific daca degetul este pe acel element
      fputc('|', out);
      fputc(aux -> id, out);
      fputc('|', out);
    } else {
      fputc(aux -> id, out);
    }
  }
  fputc('\n', out);
  fclose(out);
}

TLista MOVE_LEFT(TLista L, TLista crt) {

  if (crt -> ant -> id != '*')
    crt = crt -> ant;
  return crt;
}

TLista MOVE_RIGHT(TLista L, TLista crt) {
  TLista aux = NULL;
  if (crt -> urm == NULL) {
    aux = alocCel('#');
    crt -> urm = aux;
    aux -> ant = crt;
    crt = aux;
  } else {
    crt = crt -> urm;
  }
  return crt;
}

TLista MOVE_RIGHT_CHAR(TLista L, TLista crt, char c) {
  TLista aux = crt, ultim;

  for (; aux != NULL; aux = aux -> urm) {
    if (aux -> id == c) {
      return aux;
    }
    if (aux -> urm == NULL) ultim = aux;
  }
  aux = alocCel('#'); // adaug o celula noua cu caracterul # daca nu s-a gasit elementul cautat "c"
  ultim -> urm = aux;
  aux -> ant = ultim;

  return aux;
}

TLista MOVE_LEFT_CHAR(TLista L, TLista crt, char c) {
  TLista aux = crt;

  for (; aux -> id != '*'; aux = aux -> ant) {
    if (aux -> id == c) {
      return aux;
    }
  }
  return crt;
}

void WRITE(TLista * crt, char new) {
  ( * crt) -> id = new;
}

TLista INSERT_LEFT(TLista L, TLista crt, char c) {
  TLista aux = NULL;

  if (crt -> ant -> id != '*') {
    aux = alocCel(c);
    if (aux == NULL) {
      printf("Nu s-a alocat mem la insert left");
      exit(-1);
    }
    aux -> ant = crt -> ant;
    crt -> ant -> urm = aux;
    crt -> ant = aux;
    aux -> urm = crt;
    return aux;
  }
  return crt;
}

TLista INSERT_RIGHT(TLista L, TLista crt, char c) {
  TLista aux = NULL;

  aux = alocCel(c);
  if (aux == NULL) return NULL;

  if (crt -> urm != NULL) {
    crt -> urm -> ant = aux;
    aux -> urm = crt -> urm;
    crt -> urm = aux;
    aux -> ant = crt;
    return aux;
  }
  crt -> urm = aux;
  aux -> ant = crt;
  aux -> urm = NULL;
  return aux;
}

void SHOW_CURRENT(TLista crt) {
  TLista aux = NULL;
  FILE * out = fopen("tema1.out", "a");
  if (out == NULL) {
    printf("Nu s-a deschs fierul tema1.out\n");
    exit(-1);
  }
  fputc(crt -> id, out);
  fputc('\n', out);
  fclose(out);
}

TCoada alocCoada(char id[20]) {
  TCoada co = (TCoada) malloc(sizeof(struct coada));
  if (co == NULL) {
    printf("NU s-a alocat memorie pt alocCoada\n");
    exit(-1);
  }
  strcpy(co -> id, id);
  co -> urm = NULL;
  return co;
}

TCoada creezCoada(TCoada L, char comanda[20]) {
  TCoada aux = NULL, p;

  aux = alocCoada(comanda);
  if (L == NULL) {
    L = aux;
  } else {
    for (p = L; p -> urm != NULL; p = p -> urm);
    p -> urm = aux;
    aux -> urm = NULL;
  }
  return L;
}

void adaugUndo(Tundo * U, TLista crt) {
  Tundo aux = NULL;
  aux = (Tundo) malloc(sizeof(struct undo));
  if (aux == NULL) {
    printf("Nu s-a alocat memorie pentru Undo\n");
    exit(5);
  }
  aux -> locatie = crt;
  aux -> urm = * U;
  * U = aux;
}
void DistrugeLista(TLista * aL) {
  TLista p = ( * aL) -> urm, aux;
  while (p != NULL) {
    /* distrugere elementele listei */
    aux = p;
    p = p -> urm;
    free(aux);
  }

  free( * aL); /* distrugere santinela */
  * aL = NULL;
}

void eliberareBanda(TBanda * B) {
  DistrugeLista( & (( * B) -> L));
  ( * B) -> crt = NULL;
  free( * B);
}

void eliberareUNDO(Tundo * U) {
  Tundo aux = NULL, p = NULL;
  for (aux = ( * U); aux != NULL;) {
    p = aux;
    aux = aux -> urm;
    free(p);
  }

}