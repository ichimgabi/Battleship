#include<stdio.h>
#include<unistd.h>
#include<curses.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void menu();

void init()											//Initializarea curses
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
}

void resumegame()									
{
	
}

void matrice_calculator(int a[13][13])				//crearea matricei randomizate a computerului
{
	int x, y, i, j, coloana, linie;
	time_t t;
	srand((unsigned)time(&t));

	for(i=0;i<12;i++)								//umplerea matricei cu 0-uri (oceanul gol)
		for(j=0;j<12;j++)
			a[i][j]=0;

	for(i=0;i<10;i++)
	{
		linie = rand() % 10 + 1;					//alege pozitiile pe care va fi plasata prima "piesa" a nevei
		coloana = rand() % 10 + 1;

		if(i==0 || i==1 || i==2 || i==3)			//aseaza navele de dimensiune 1
		{
			if(a[linie][coloana] == 0)
			{
				a[linie][coloana]=1;
				for(x=linie-1;x<linie+2;x++)
					for(y=coloana-1;y<coloana+2;y++)
						if(a[x][y] != 1)
							a[x][y] = 2;		
			}
			else
				i--;								//daca locul ales este ocupat sau langa o alta nava, reface floop-ul cu acelasi "i"
		}
		else
			if(i==4 || i==5 || i==6)				//aseaza navele de dimensiune 2
			{
				if(a[linie][coloana] == 0)
				{
					if(a[linie-1][coloana] == 0 && linie-1!=0)				//verifica daca casutele de langa cea initiala sunt
					{														//valide pentru a le completa cu "1" in functie de
						a[linie][coloana]=1;								//dimenisunea navei.
						a[linie-1][coloana]=1;								//Se aplica tuturor navelor, indiferent
						for(x=linie-2;x<linie+2;x++)						//de dimensiune.
							for(y=coloana-1;y<coloana+2;y++)
								if(a[x][y] != 1)
									a[x][y] = 2;
					}
					else
						if(a[linie+1][coloana]==0 && linie+1!=11)
						{
							a[linie][coloana]=1;
							a[linie+1][coloana]=1;
							for(x=linie-1;x<linie+3;x++)
								for(y=coloana-1;y<coloana+2;y++)
									if(a[x][y] != 1)
										a[x][y] = 2;
						}
						else
							if(a[linie][coloana-1] == 0 && coloana-1!=0)
							{
								a[linie][coloana]=1;
								a[linie][coloana-1]=1;
								for(x=linie-1;x<linie+2;x++)
									for(y=coloana-2;y<coloana+2;y++)
										if(a[x][y] != 1)
											a[x][y] = 2;
							}
							else
								if(a[linie][coloana+1] == 0 && coloana+1!=11)
								{
									a[linie][coloana]=1;
									a[linie][coloana+1]=1;
									for(x=linie-1;x<linie+2;x++)
										for(y=coloana-1;y<coloana+3;y++)
											if(a[x][y] != 1)
												a[x][y] = 2;
								}
								else
									i--;
				}
				else
					i--;
			}
			else
				if(i==7 || i==8)				//aseaza navele de dimensiune 3
				{
					if(a[linie][coloana] == 0)
					{
						if(a[linie-1][coloana]==0 && a[linie-2][coloana]==0 && linie-2!=0 && linie-1!=0)
						{
							a[linie][coloana]=1;
							a[linie-1][coloana]=1;
							a[linie-2][coloana]=1;
							for(x=linie-3;x<linie+2;x++)
								for(y=coloana-1;y<coloana+2;y++)
									if(a[x][y] != 1)
										a[x][y] = 2;
						}
						else
							if(a[linie+1][coloana]==0 && a[linie+2][coloana]==0 && linie+2!=11 && linie+1!=11)
							{
								a[linie][coloana]=1;
								a[linie+1][coloana]=1;
								a[linie+2][coloana]=1;
								for(x=linie-1;x<linie+4;x++)
									for(y=coloana-1;y<coloana+2;y++)
										if(a[x][y] != 1)
											a[x][y] = 2;
							}
							else
								if(a[linie][coloana-1]==0 && a[linie][coloana-2]==0 && coloana-2!=0 && coloana-1!=0)
								{
									a[linie][coloana]=1;
									a[linie][coloana-1]=1;
									a[linie][coloana-2]=1;
									for(x=linie-1;x<linie+2;x++)
										for(y=coloana-3;y<coloana+2;y++)
											if(a[x][y] != 1)
												a[x][y] = 2;
								}
								else
									if(a[linie][coloana+1]==0 && a[linie][coloana+2]==0 && coloana+2!=11 && coloana+1!=11)
									{
										a[linie][coloana]=1;
										a[linie][coloana+1]=1;
										a[linie][coloana+2]=1;
										for(x=linie-1;x<linie+2;x++)
											for(y=coloana-1;y<coloana+4;y++)
											if(a[x][y] != 1)
												a[x][y] = 2;
									}
									else
										i--;
					}
					else
						i--;
				}
				else
					if(i==9)					//aseaza nava de dimensiune 4
						if(a[linie][coloana] == 0)
						{
							if(a[linie-3][coloana]==0 && a[linie-2][coloana]==0 && a[linie-1][coloana]==0 && linie-3!=0 && linie-2!=0 && linie-1!=0)
							{
								a[linie][coloana]=1;
								a[linie-1][coloana]=1;
								a[linie-2][coloana]=1;
								a[linie-3][coloana]=1;
								for(x=linie-4;x<linie+2;x++)
									for(y=coloana-1;y<coloana+2;y++)
										if(a[x][y] != 1)
											a[x][y] = 2;
							}
							else
								if(a[linie+3][coloana]==0 && a[linie+2][coloana]==0 && a[linie+1][coloana]==0 && linie+3!=11 && linie+2!=11 && linie+1!=11)
								{
									a[linie][coloana]=1;
									a[linie+1][coloana]=1;
									a[linie+2][coloana]=1;
									a[linie+3][coloana]=1;
									for(x=linie-1;x<linie+5;x++)
										for(y=coloana-1;y<coloana+2;y++)
											if(a[x][y] != 1)
												a[x][y] = 2;
								}
								else
									if(a[linie][coloana-1]==0 && a[linie][coloana-2]==0 && a[linie][coloana-3]==0 && coloana-3!=0 && coloana-2!=0 && coloana-1!=0)
									{
										a[linie][coloana]=1;
										a[linie][coloana-1]=1;
										a[linie][coloana-2]=1;
										a[linie][coloana-3]=1;
										for(x=linie-1;x<linie+2;x++)
											for(y=coloana-4;y<coloana+2;y++)
												if(a[x][y] != 1)
													a[x][y] = 2;
									}
									else
										if(a[linie][coloana+1]==0 && a[linie][coloana+2]==0 && a[linie][coloana+3]==0 && coloana+3!=11 && coloana+2!=11 && coloana+1!=11)
										{
											a[linie][coloana]=1;
											a[linie][coloana+1]=1;
											a[linie][coloana+2]=1;
											a[linie][coloana+3]=1;
											for(x=linie-1;x<linie+2;x++)
												for(y=coloana-1;y<coloana+5;y++)
													if(a[x][y] != 1)
														a[x][y] = 2;
										}
										else
											i--;
						}
						else
							i--;
	}

	for(i=1;i<11;i++)									//Transforma matricea rezultata din 12x12 in 10x10, prin taierea marginilor
		for(j=1;j<11;j++)
			if(a[i][j] == 2)
				a[i][j] = 0;
}


void newgame(char* nume_fisier)
{
	int x, y=0, x_std, y_std, i, j, a[13][13], c, linie, coloana, ok=1, score_player=0, score_cpu=0, p, u;
	WINDOW *player_win, *computer_win;
	time_t t;
	srand((unsigned)time(&t));
	getmaxyx(stdscr,y_std,x_std);
	player_win = newwin(y_std/2+2, x_std/2-15, 0, 0);  //crearea ferestrei jucaotrului
	keypad(player_win, TRUE);

	FILE *input = fopen(nume_fisier, "r");
	char buffer[1005];

	if(input != NULL)								//ia fisierul dat in linia de comanda si il afiseaza pe ecran sub o alta forma (asemanatoare hartii computeruli)
	{
		while(fgets(buffer, 1005, input) != NULL)
		{
			for(x=1;x<20;x++)
			{
				if(buffer[x] == 'X')
					mvwprintw(player_win,y,x,"1");
				else
					if(buffer[x] == '|')
						mvwprintw(player_win,y,x," ");
					else
						if(buffer[x] == ' ')
							mvwprintw(player_win,y,x,"0");
			}
			y++;
		}
		fclose(input);
	}

	computer_win = newwin(y_std,x_std,y_std/2+2,x_std/2+20);   //crearea ferestrei computerului
	keypad(computer_win, TRUE);
	matrice_calculator(a);									//apelarea functiei pentru crearea hartii computerului

	y=0;
	for(i=1;i<11;i++)
	{
		x=0;
		for(j=1;j<11;j++)
		{
			mvwprintw(computer_win,y,x,"-");
			x+=2;
		}
		y++;
	}
	mvprintw(y_std-4,0,"Press d for Destroy in Advance");
	mvprintw(y_std-3,0,"Press r for Randomize Map");
	mvprintw(y_std-1,0,"Press q for Menu");
	refresh();

	y=0;
	x=0;
	wmove(computer_win,y,x);
	wrefresh(computer_win);

	mvwprintw(player_win,y_std/2-1,0,"Randul Playerului...");
	wrefresh(player_win);

	while(c = wgetch(computer_win))					//ia miscarile jucatorului
	{  switch(c)
	    {	case KEY_DOWN:
	    	{
	    		if(y<10)
		        	y++;
		        wmove(computer_win,y,x);
		    }
				break;
			case KEY_UP:
			{
				if(y!=0)
		        	y--;
		        wmove(computer_win,y,x);
			}
				break;
			case KEY_LEFT:
			{
				if(x!=0)
		        	x-=2;
		        wmove(computer_win,y,x);
			}
				break;
			case KEY_RIGHT:
			{
				if(x<18)
		        	x+=2;
		        wmove(computer_win,y,x);
			}
				break;
			case 113:								//la apasarea tatei q intra in meniu
				menu(nume_fisier);
			break;
			case 100:								//la apasarea tastei d incepe destroy in advance
			{
				for(p=1;p<11;p++)
				{
					linie = rand() % 10;
					coloana = rand() % 19;
					if(coloana%2 == 0)
						coloana++;
					if(mvwinch(player_win,linie,coloana)=='1')  //verifica daca casutele selectate sunt valide pentru harta computerului
					{
						score_cpu++;
						mvwprintw(player_win,linie,coloana,"X");
					}
					else
						if(mvwinch(player_win,linie,coloana) == '0')
							mvwprintw(player_win,linie,coloana,"-");
						else
							if(mvwinch(player_win,linie,coloana) == '-')
								p--;
							else
								if(mvwinch(player_win,linie,coloana) == 'X')
									p--;
				}
				for(p=1;p<11;p++)
				{
					linie = rand() % 10;
					coloana = rand() % 19;
					if(coloana%2 != 0)
						coloana++;
					if(mvwinch(computer_win,linie,coloana) == '0') //verifica daca casutele selectate sunt valide pentru harta jucatorului
						p--;
					else
						if(mvwinch(computer_win,linie,coloana) == 'X')
						{
							score_player--;
							p--;
						}
					if(a[linie+1][coloana/2+1] == 1)
					{
						score_player++;
						mvwprintw(computer_win,linie,coloana,"X");
					}
					else
						mvwprintw(computer_win,linie,coloana,"0");
				}
			}
			break;
			case 10:											//apasarea tastei enter
			{
				if(a[y+1][x/2+1]==1)							//verifica daca jucatorul nimereste o nava
				{
					mvwprintw(computer_win,y,x,"X");
					score_player++;
				}
				else
					if(a[y+1][x/2+1]==0)						//ratarea jucatorului si randul computerului
					{
						mvwprintw(computer_win,y,x,"0");
						wrefresh(computer_win);
						mvwprintw(player_win,y_std/2-1,0,"Randul Computerului...");
						wrefresh(player_win);
						linie = rand() % 10;
						coloana = rand() % 19;
						if(coloana%2 == 0)
							coloana++;
						while(mvwinch(player_win,linie,coloana) == '-' || mvwinch(player_win,linie,coloana) == 'X')
						{
							linie = rand() % 10;
							coloana = rand() % 19;
							if(coloana%2 == 0)
								coloana++;
						}
						while(ok==1)
						{
							if(mvwinch(player_win,linie,coloana)=='1')
							{
								score_cpu++;
								mvwprintw(player_win,linie,coloana,"X");
								sleep(1);
								u = rand() % 4;
								if(u == 0)					//optimizarea mutailor computerului, daca acesta nimereste o nava
								{
									if(linie<9)
										linie++;
									else
										linie--;
								}
								else
									if(u == 1)
									{
										if(linie>0)
											linie--;
										else
											linie++;
									}
									else
										if(u == 2)
										{
											if(coloana<18)
												coloana+=2;
											else
												coloana-=2;
										}
										else
											if(u == 3)
											{
												if(coloana>2)
													coloana-=2;
												else
													coloana+=2;
											}
							}
							else
							{
								mvwprintw(player_win,linie,coloana,"-");
								sleep(1);
								ok=0;
							}
						}
						ok=1;
						mvwprintw(player_win,y_std/2-1,0,"Randul Playerului...");
					}
			}
			break;
		}
		wrefresh(computer_win);
		wrefresh(player_win);
		if(score_player == score_cpu && score_cpu == 20)	//cazul de remiza
		{
			mvwprintw(player_win,y_std/2-1,0,"REMIZA! AMBII JUCATORI AU DOBORAT TOATE NAVELE IN ACELASI TIMP");
			wrefresh(player_win);
			break;
		}
		if(score_player == 20 && score_cpu != 20)			//jucatorul castiga
		{
			mvwprintw(player_win,y_std/2-1,0,"AI DOBORAT TOATE NAVELE  INAMICE! BRAVO!");
			wrefresh(player_win);
			break;
		}
		else
			if(score_cpu == 20 && score_player !=20)		//jucatorul pierde
			{
				mvwprintw(player_win,y_std/2-1,0,"%d","AI PIERDUT! Scorul tau:",score_player);
				wrefresh(player_win);
				break;
			}
	}
 }

void tutorial(char* nume_fisier)						//afisarea tutorialului
{
	int y = 0, y_std, x_std;
	WINDOW *tutorial_win;
	getmaxyx(stdscr,y_std,x_std);

	tutorial_win = newwin(y_std, x_std, 0, 0);
	keypad(tutorial_win, TRUE);

	wrefresh(tutorial_win);

	FILE * pFile;
	char buffer[1005];

	pFile = fopen("tutorial.txt", "r");

	if(pFile != NULL)
	{
		while(fgets(buffer, 1005, pFile) != NULL)
		{
			mvprintw(y, 0, buffer);
			y++;
		}
		fclose(pFile);
	}
	mvprintw(y_std-1,0,"Press q for Menu");
	refresh();
}

void opening()								//afisarea openingului
{
	int y_std,x_std, y = y_std/2;
	WINDOW *opening_win;

	getmaxyx(stdscr,y_std,x_std);
	opening_win = newwin(0, 0, y_std/2-7, x_std/2-13);
	keypad(opening_win, TRUE);

	refresh();
	wrefresh(opening_win);

	FILE * pFile;
	char buffer[1005];

	pFile = fopen("opening.txt", "r");

	if(pFile != NULL)
	{
		while(fgets(buffer, 1005, pFile) != NULL)
		{
			mvprintw(y+5, x_std/4-6, buffer);
			y++;
		}
		fclose(pFile);
	}
	mvprintw(y+5, x_std/4+2, "Apasa orice tasta pentru a continua");
	refresh();

	int ch=getch();

	move(0,0);
	clrtobot();
	wrefresh(opening_win);
	refresh();
}

void menu(char* nume_fisier)				//crearea meniului
{
	int c, i, y=0, x=0;
    WINDOW *my_menu_win;

	my_menu_win = newwin(10,15,8,33);
    keypad(my_menu_win, TRUE);

    mvwprintw(my_menu_win,0,0,"-Resume Game");			//optiunile din meniu
    mvwprintw(my_menu_win,1,0,"-New Game");
    mvwprintw(my_menu_win,2,0,"-Tutorial");
    mvwprintw(my_menu_win,3,0,"-Quit");

    wmove(my_menu_win,y,x);
	wrefresh(my_menu_win);

	while(c = wgetch(my_menu_win))						//navigarea in meniu
	{   switch(c)
	    {	case KEY_DOWN:
	    	{
	    		if(y!=3)
		   			y++;
		   		wmove(my_menu_win,y,x);
		      }
				break;
			case KEY_UP:
			{
				if(y!=0)
					y--;
				wmove(my_menu_win,y,x);
			}
				break;
			case 113:
			{
				clear();
				refresh();
				mvwprintw(my_menu_win,0,0,"-Resume Game");
	    		mvwprintw(my_menu_win,1,0,"-New Game");
			   	mvwprintw(my_menu_win,2,0,"-Tutorial");
	   			mvwprintw(my_menu_win,3,0,"-Quit");
			}
				break;
			case 10:									//selectarea fiecarei optiuni
			{
				clear();
				if(y==0)
					resumegame();
				else
					if(y==1)
						newgame(nume_fisier);
					else
						if(y==2)
							tutorial(nume_fisier);
				break;
			}
			break;
		}
		wrefresh(my_menu_win);
		if(c == 10 && y==3)						//iesirea din aplicatie in urma apasarii optiunii Quit
		{
			clear();
			endwin();
		}
	}	
}

int main(int argc, char *argv[])				//apelarea principalelor functii
{
	if(argv[1] == NULL)							//eroare pentru rularea fara argumente
	{
		printf("Nu s-au dat argumente de comanda (harta jucatorului)\n");
		return 1;
	}
	init();
	opening();
	menu(argv[1]);
	return 0;
}