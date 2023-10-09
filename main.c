// LUCIU Alexandru-Cristian 311CB

   #include "header.h"

int main() {
  int i = 0;
  TBanda B = NULL;
  Tundo U = NULL, ultim_U = NULL, cp_U = NULL;
  Tundo R = NULL, ultim_R = NULL, cp_R = NULL;
  TCoada C = NULL, CC = NULL;
  TLista temp = NULL;

  int numar_instructiuni = 0;
  char query[] = "SHOW_CURRENT SHOW EXECUTE UNDO REDO";  // pentru verificarea comenzilor
  char instructiune[20] = "";
  FILE * f = fopen("tema1.out", "w");
  if (f == NULL) {
    printf("Nu s-a deschs fierul");  // se fac verificarile necesare la fiecaer dechidere de fisier
    eliberareBanda( & B);
    exit(-1);
  } else {
    fclose(f);
  }

  B = initializareLista();
  if (B -> L == NULL) {
    printf("NU s-a alocat lisat L =(");
    return 0;
  }

   temp = B->crt;

  FILE * fiser = fopen("tema1.in", "r");
  if (fiser == NULL) {
    printf("Nu s-a deschs fierul");
    eliberareBanda( & B);
    exit(-1);
  }

  fscanf(fiser, "%d", & numar_instructiuni);
  fgets(instructiune, 20, fiser);
  for (i = 0; i < numar_instructiuni; i++) {
    fgets(instructiune, 20, fiser);
    
    instructiune[strcspn(instructiune, "\n")] = '\0'; // elimin caraterul \n
    if (strcmp("SHOW", instructiune) == 0) {
      SHOW(B);
    }
    if (strcmp("SHOW_CURRENT", instructiune) == 0)
      SHOW_CURRENT(B -> crt);
   
    if (strcmp("UNDO", instructiune) == 0) {
       Tundo elimin = NULL;
       adaugUndo(&R, B->crt);
       B->crt = U->locatie;
       elimin = U;
       U = U->urm;
       free(elimin);
      }
    if (strcmp("REDO", instructiune) == 0) {
       Tundo elimin = NULL;
       adaugUndo(&U, B->crt);
       B->crt = R->locatie;
       elimin = R;
       R = R->urm;
       free(elimin);
      }
 
    if (strstr(query, instructiune) == NULL) {
      C = creezCoada(C, instructiune);
    }
    if (strcmp("EXECUTE", instructiune) == 0) {
      if (strcmp("MOVE_LEFT", C -> id) == 0) {
        temp = B -> crt;
        B -> crt = MOVE_LEFT(B -> L, B -> crt);
        if(B->crt != temp) {  // veerific daca s-a actualizat pozitia degetului
        adaugUndo(&U, temp);  // adaug valoarea din temp in lista de undo si actualizez temp
        }
      }
      if (strcmp("MOVE_RIGHT", C -> id) == 0) {
        temp = B->crt;  // Actualizez noua pozitie
        B -> crt = MOVE_RIGHT(B -> L, B -> crt); // Actualizez pozitia degetului
        adaugUndo(&U, temp);  // Adaug pozitia anterioara salvata in temp
       }
      if (strncmp("MOVE_RIGHT_CHAR", C -> id, 11) == 0) {
        if(B -> crt->id != C -> id[strlen(C -> id) - 1])
       B -> crt = MOVE_RIGHT_CHAR(B -> L, B -> crt, C -> id[strlen(C -> id) - 1]);  // extrag caracterul din MOVE_RIGHT_CHAR x
      }
      if (strncmp("MOVE_LEFT_CHAR", C -> id, 11) == 0) {
        TLista aux = B -> crt;
        if(B -> crt->id != C -> id[strlen(C -> id) - 1]) {
        B -> crt = MOVE_LEFT_CHAR(B -> L, B -> crt, C -> id[strlen(C -> id) - 1]);  // extrag caracterul din MOVE_LEFT_CHAR x
        if (aux == B -> crt) {  // verific daca pozitia degetului s-a mutat
          FILE * out = fopen("tema1.out", "a");
          if (out == NULL) {
            printf("Nu s-a deschs fierul tema1.out\n");
            exit(-1);
          }
          fprintf(out, "ERROR\n");  // in cazul negativ, elementul cautat nu a fost gasit, se afiseza mesajul ERROR
          fclose(out);
        }
        }
      }
      if (strncmp("WRITE", C -> id, strlen(C -> id) - 2) == 0)
        WRITE( & B -> crt, C -> id[strlen(C -> id) - 1]);  // extrag caracterul de scris in lista
      if (strncmp("INSERT_RIGHT", C -> id, strlen(C -> id) - 2) == 0)
        B -> crt = INSERT_RIGHT(B -> L, B -> crt, C -> id[strlen(C -> id) - 1]);
      if (strncmp("INSERT_LEFT", C -> id, strlen(C -> id) - 2) == 0) {
        TLista aux2 = B -> crt;
        B -> crt = INSERT_LEFT(B -> L, B -> crt, C -> id[strlen(C -> id) - 1]);
        if (aux2 == B -> crt) {
          FILE * out = fopen("tema1.out", "a");
          if (out == NULL) {
            printf("Nu s-a deschs fierul tema1.out\n");
            exit(-1);
          }
          fprintf(out, "ERROR\n");
          fclose(out);
        }
      }
       CC = C;  // elimni comada din C dupa ce a fost executata
       C = C -> urm;
       free(CC);
    }
  }
  free(C);
  eliberareUNDO(&U);
  eliberareUNDO(&R);
  eliberareBanda(&(B));
  fclose(fiser);

  return 0;
}