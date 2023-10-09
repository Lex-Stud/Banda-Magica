Total: 100.0/100
Valgrind: 20/20
Am declarat structura "celula" pentru a creea lista dublu inlantuita cu santinela.
Unde id = valoarea elementului
     urm = conexiunea cu urmatorul element
     ant = conexiunea cu elementul anterior

TLista alocareCel aloca memorie pentru o celula si intoarce exit(-1) daca  nu s-a alocat memoria

TLista initializareLista() initializeaza o lista dublu inlantuita unde santinela primeste valoarea * si se initializeaza o celula cu valoarea #

void SHOW:  Se dechide fierup tema1.out se parcurg banda data ca parametru (TBanda), cu ajutorul unei variabile aux se fce verifcarea daca aux == cu elementul curent (in bcaz afiramtiv acesta se afisaza in formula | element curent | ) 

TLista MOVE_LEFT(TLista L, TLista crt) : se verifca daca degetul se poate muta la stanga cu o pozitie si se returneaza adresa noua pt Crt. Altfel daca elementul din stanga are valoarea '*' nu se executa nimic.

TLista MOVE_CHAR(TLista L, TLista crt): verifca daca elementul crt se poate muta la dreapata in caza afirmativ se returneaza noua adresa. Altfel se creeza o noua celula cu valoarea '#'

TLista MOVE_LEFT_CHAR(TLista L, TLista crt, char c): Cu ajutorul variabilei aux se parcurge litsa L si se cauta elementul 'c' in caza afirmativ se returneaza pozitia unde acesta s-a gait. Altfel se afisaza mesajul "ERROR"

TLista MOVE_LEFT_CHAR(TLista L, TLista crt, char c): cu ajutorul variabilei aux se parcurge litsa L si se cauta elementul 'c' in caza afirmativ se returneaza pozitia unde acesta s-a gait. Altfel se creeaza o noua celula cu valoarea '#'

TLista INSERT_LEFT(TLista L, TLista crt, char c) Se verifica daca elementul din stanag este diderit de santinela. In caz afirmativ se creeaza o noua celula cu valoarea 'c' altfel se afisaza mesajul ERROR 

TLista INSERT_RIGHT(TLista L, TLista crt, char c) Se creeaza o noua celula cu valoarea 'c'

TCoada creezCoada(TCoada L, char comanda[20]) Se parcurge coada L cu ajutorul unui  for (p = L; p -> urm != NULL; p = p -> urm); pentru a ajunge la finalul cozii unde se apeleaza functia alocCoada(char id[20]) pentru a aloca spatiu pentru o noua caelula si adauga sirul primit ca parametru in celula.

Tundo adaugaUndo(Tundo L, TLista crt) se aloca memorie pentru o noua celula. Se verifaca daca lista initiala e vida in caza afirmativ acesaata se initializeaza cu valoarea alocata in aux. Altfel se parcurge pana la final cu ajutorul unui  for (p = L; p -> urm != NULL; p = p -> urm); UNde se introduce noua valoarea

Functiile de eliberare pargurg listele si elibereaza element cu element.

Functaia MAIN
Se initalizeaza variabilele necesare : char query[] = "SHOW_CURRENT SHOW EXECUTE UNDO REDO"; Contine comenzile care se executa la intalnire acestora.

Se dechide fierul tema1.out in modul write si se inchide pentru a se sterge ce a fost scris anterior.
Se initializeaza banda B. Si se salveaza adresa primului element in variabila temp
Se dechde fierul tema1.in in modul read - se citeste un numar de tip int numar_de_instructiuni 
                                        - cu ajutorul unui for se citesc numar_de_instructiuni 

Se verifica daca cuvantul citit in instructiune se gasete in query. In caz afirmativ se executa, altfel se adauga in coada.
La intalnirea comenzii EXECUTE se comapra prima valoare din coada si se executa la final cu ajutorul cariablei cc se elimina din coada.
Dupa executarea uenia dintre functiile MOVE_LEFT MOVE_RiGHT MOVE_RiGHT_Char si MOVE_LEFT CHAR actualizez pozitia degetului se adauga fosta pozitie a degetului la lista de UNDO:  U si se initializeaza variabila temp cu noua pozitie a degetului.