#include <windows.h>
#include <ncurses/curses.h>             

void title(){
for(int i = 9; i>=1;i--){
refresh();
mvprintw(i,1,   R"(																									)");
mvprintw(i+1,1, R"( _____       _            _____ _           _                _____ _   _             			)");
mvprintw(i+2,1, R"(|     |___ _| |___ ___   |  _  |_|_____ ___|_|___ ___ ___   |   __|_|_| |___ ___ ___ 			)");
mvprintw(i+3,1, R"(|  |  |  _| . | -_|  _|  |   __| |     | . | |   | .'|   |  |__   | | . | .'|   | . |			)");
mvprintw(i+4,1, R"(|_____|_| |___|___|_|    |__|  |_|_|_|_|  _|_|_|_|__,|_|_|  |_____|_|___|__,|_|_|_  |			)");
mvprintw(i+5,1, R"(                                       |_|                                      |___|			)");
mvprintw(i+6,1, R"(																									)");
Sleep(120);
}

}

void  startAnimation (){

}

int mainMenu() {
refresh();
mvprintw(12,20,R"(Selamat Datang, apa kamu siap melaksanakan tugas ?)");
mvprintw(13,20,R"(1. Ya ?)");
mvprintw(14,20,R"(2. Keluar ?)");
bool terpilih=0;
while(!terpilih){
char key = getch();
switch(key){
	case '1':  return 1 ; break;
	case '2':  return 0	; break;
	default : mvprintw(16, 20, "Hmmmm sepertinya yang anda mau tidak ada di pilihan.");
}
}

}

int pilihPimsid(){
	mvprintw(16,20,R"(Pilih Tugas Anda :)");
	mvprintw(17,20,"	1. Pimsid 1 (Dalam Tahap Pengembangan)");
	mvprintw(18,20,"	2. Pimsid 2");
	mvprintw(19,20,"	3. Pimsid 3 (Skip dulu, teks semua)");
	mvprintw(20,20,"	4. Healing");
	bool terpilih = 0;
	while(!terpilih){
	switch(getch()){
	case '1': terpilih = 1; return 1 ; break;
	case '2': terpilih = 1; return 2 ; break;
	case '3': terpilih = 1; return 3 ; break;
	case '4': terpilih = 1; return 4 ; break;
	default : mvprintw(16, 20, "Hmmmm sepertinya yang anda mau tidak ada di pilihan.");
}
}

}

