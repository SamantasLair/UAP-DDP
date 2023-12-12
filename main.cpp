#include <iostream>
#include <fstream>
#include <windows.h>
#include <ncurses/curses.h>
#include <mmsystem.h>
#include <chrono>
#include "Program/Scene.h"
#include "Program/Opening.h"
#include "Program/Control.h"
#include "Program/Sound.h"
#include "Program/blackJack.h"

int maxX,maxY,x,y;
int score = 0;
bool game = true;
		bool terpilihq = 0;
int skor = 200, waktu = 1320;  
int dekkartu[30]={0}, kartuHost=0;

void gameover(int sekor, int kartuhost){
	clear();
	mvprintw(maxY/2,20,"Kamu telah kalah dengan skor %d",sekor);
	mvprintw(maxY/2+1,20,"kartu host terakhir adalah : %d",kartuhost);
	mvprintw(maxY/2+2,20,"Setelah kerja yg berat, nikmati healingmu ke pantai kepantai ");
	if(sekor == 0){
		mvprintw(maxY/2+3,20,"Kasian Awoak");
		int A = 0;
		for(int i =0; i<4; i++ ){
		attron(COLOR_PAIR(i));
		mvprintw(maxY/2+3,31+A,"awok");
		A+=4;
		attroff(COLOR_PAIR(i));
		refresh();
		Sleep(150);
		}
	}
	refresh();
	Sleep(4000);
	Lake(sekor);
	animatedLake(maxX,maxY);
	refresh();
}

void pimsid2(){
	int bet = 0;
	bool game2 = true;
  	clear();
  	srand(time(nullptr));
	awalPimsid2();
	refresh();
	
  	while(game2) {
  		mvprintw(1,500,"%d",skor);
		refresh();
  		
		int kartuke = 3;
  		mvprintw(5, 1, "Masukan taruhan ?			");
    	mvprintw(6, 1, "1. Ya						");
    	mvprintw(7, 1, "2. Selesai					");
    	
		
		int plis = getch();

		switch(plis){
		case '1': break;
		case '2': Lake(skor); animatedLake(maxX,maxY); break;
    }
		
    	dekkartu[0] = dek();
    	dekkartu[1] = dek();
    	kartu(dekkartu[0],1);
    	kartu(dekkartu[1],2);
    	
		lol :
    	mvprintw(17, 1, "Apa yang anda ingin lakukan ?");
    	mvprintw(18, 1, "1. Tambah Kartu	");
    	mvprintw(19, 1, "2. Stand	 		");
		mvprintw(20, 1, "3. Quit	 		");
		int jmlh=0;
		for(int i = 0; i <10; i++){
			jmlh += dekkartu[i];
		}
		mvprintw(16,1,"%d",jmlh);
		refresh();
		bool goer = true;
		while(goer){
		if(kbhit()){
			kartuHost = dek()+dek();
     		while(kartuHost<16){
     			kartuHost += dek();
	 		}
			int aa = getch();
				switch(aa){
				case '2':
				if(kartuHost>=jmlh||jmlh>=22){
					 gameover(0, kartuHost); break;
				}
				else skor = skor *2; goto lol; break;
				
				case '1': dekkartu[kartuke] = dek();kartu(dekkartu[kartuke-1],kartuke); kartuke++; goto lol ;break;
			
				
			
				case '3': gameover(skor,kartuHost); break;
				}
			}
		}	
			refresh();
}
}

void pimsid1() {
	clear();
	mvprintw(1,1,"Sorry Belum Ada Karena Banyak Betul Kalo Buat Kode Tentang Order... hehe");
	refresh(); getch();
	//maunya kayak dibuat choice game, make rand jadi kalo hoki yang order cuma dikit. 
	//dikasih waktu sekitar 11 jam(dibuat 1320 = 11 jam * 60 menit * 2 omongan(30 detik))
	//Order diskusi itu makan waktu 60 (30 menit), order makan waktu 6(3 menit), ijin dkk makan waktu 1(30 detik)
	//game over kalo waktunya habis
	//menang kalo udh nyusurin bab 1 - 8 + evaluasi ulang sebelum waktu habis
}

int main() {
    initscr();
    getmaxyx(stdscr, maxY, maxX);
    y = maxY / 2;
    x = maxX / 2;
    start_color();
    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_WHITE,COLOR_BLACK);
    playHammer(1);
    noecho();//Supaya enggak ada huruf saat ngetik, ntar dihapus kalo mau make 
    curs_set(0);  // Hide the cursor
    
	title();
    if(mainMenu()==0)return 0;
    int pilihanpimsid = pilihPimsid();
	switch(pilihanpimsid){
	case 1: pimsid1(); break;
	case 2: pimsid2(); break;
	case 3: clear(); mvprintw(1,1,"Kebanyakan teks, skip :)");break;
	case 4: clear(); Lake(skor); animatedLake(maxX,maxY);refresh();  break;
	default : clear(); mvprintw(1,1,"Coba masukkan pilihan");break;
	}
    endwin();
    system("PAUSE");
    return 0;
}
