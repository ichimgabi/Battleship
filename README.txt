CERINTA 1

Am creat meniul intr-o fereasta (my_menu_win) in care am scris fiercare optiune. Ma plimb prin optiuni cu sagetile sus-jos.
La fiecare apasare se apeleaza wmove() in timp ce scade sau creste "y"-ul (coordonata liniilor, relativa cu fereastra), pentru a face highlight pe optiunea urmatoare.
La apasarea tastei ENTER se apeleaza functia corespunzatoare optiunii alese, iar la apasarea tastei "q" reapare meniul (pusa acolo pentru a putea accesa meniul dupa ce se intra in fereastra "Tutorial". Pentru "Newgame" e un alt case dintr-un switch()).
***Optiunea "Resume Game" nu functioneaza, dar am creat totusi fisiere text pentru a salva matricele din timpul jocului.***

CERINTA 2

Am generat fiecare harta in 2 ferestre diferite pozitionate in colturile opuse ale ecranului.
Harta jucatorului se afla in fisierul "input.txt" si e in acelasi format ca cel din exemple (cu "|" intre fiecare casuta).
Harta computerului a fost generata dintr-o matrice 12x12 careia i-au fost taiate marginile. Am facut asta pentru a putea inconjura fiecare nava pozitionata cu un alt element pentru a putea arata ca acolo nu se mai pot genera alte nave. Astfel, daca un "1" (pozitia navei) era pe margine, nu se puteau genera "2"-uri (spatii care nu sunt valide) in jurul lui, asa ca am avut nevoie de inca un set de margini (as fi putut totusi sa mai adaug un set de if-uri pentru a elimina situatiile astea, dar mi s-a parut ca asa e mai usor). 
 
CERINTA 3

Dupa selectare optiunii "New Game", aplicatia inta in functia newgame() in care afiseaza hartile si il lasa pe jucator sa inceapa.
Miscarea jucatorului se face prin tastele cu sageti intr-un switch(), iar apasarea tastei ENTER schimba casuta selectata cu "X", daca a fost nimerita o nava (iar jucatorul poate continua cu mutarile) sau cu "-" daca nu (moment in care e randul computerului sa faca miscarea).
Computerul alege la intamplare une din casute, atat timp cat nu a mai fost aleasa anterior.
**Am modificat intervalul dintre mutarile computerului la 1 secunda de la 3 pentru ca mi s-a parut ca dura prea mult un joc (idee luata de pe forum).
Pentru a imi da seama al cui este randul am adugat cate un "Randul jucatorului" sau "Randul computerului" care se schimba la fiecare mutare.


CERINTA 4

Pentru Destroy in Advance am folosit un for() care, atat timp cat casutele alese la intamplare nu au mai fost selectate anterior afiseaza cate o casuta, pana la 10. Valabil atat pentru jucatori cat si pentru computer.
***Randomize Map nu functioneaza, dar i-am pus un prompt ("Press r for Randomize Map").

CARINTA 5

Afisez cine a castigat.
Daca a castigat computerul, jucatorului i se afiseaza numar de puncte acumulate (pana la 20), adica cate "X"-uri a nimerit.
Daca castiga jucatorul, nu se mai afiseaza punctajul lui pentru ca este maxim.
In cazul remizei, se afiseaza un mesaj special (apare de cele mai multe ori in urma spamului de Destroy in Advance).

BONUS

Jocul incepe cu un "Opening" screen care are titlul jocului in format de ASCII art (cautat pe net, dar modificat putin).
Am adaugat optiunea "Tutorial" in meniu pentru o scurta explicatie generala a jocului si a selectiei casutelor inamicului.
Daca computerul nimereste o nava, urmatoare lui miscare va fi in una dintre cele 4 pozitii laterale (sus, jos, stanga, dreapta). In schimb, daca nu nimereste, data viitoare mutarea lui va fi tot aleatorie.