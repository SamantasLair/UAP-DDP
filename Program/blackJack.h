#include <ncurses/curses.h>
#include <windows.h>


void awalPimsid2(){
	srand(time(nullptr));
    std::string str1 = "Selamat Datang Di Kerjaan Pimsid 2 ";
    std::string str2 = "Semoga Kamu Menjalani Tugasmu Dengan Sepenuh Hati ";
    std::string str3 = "Pantang Semangat, Dan Teruslah Menyerah ";
    
    for(int i = 0; i < sizeof(str1)+10; i++){
        refresh();
        char charstring=str1[i];
        char str[] = {charstring, '\0'};
        mvprintw(1, 1+i,str);
        Sleep(50+rand()%30);
    }
    for(int i = 0; i < sizeof(str2)+26; i++){
        refresh();
        char charstring=str2[i];
        char str[] = {charstring, '\0'};
        mvprintw(2, 1+i,str);
        Sleep(50+rand()%30);
    }
    for(int i = 0; i < sizeof(str3)+16; i++){
        refresh();
        char charstring=str3[i];
        char str[] = {charstring, '\0'};
        mvprintw(3, 1+i,str);
        Sleep(50+rand()%30);
    }
}

int dek(){
    int kartu = rand()%13;
 return kartu;
}

void kartu(int angka, int kartuKe){
	int pos = 10;

        mvprintw(pos  ,10+kartuKe*6,R"(.------.)");
        mvprintw(pos+1,10+kartuKe*6,R"(|A.--. |)");
        mvprintw(pos+2,10+kartuKe*6,R"(| |/\| |)");
        mvprintw(pos+3,10+kartuKe*6,R"(| :\/: |)");
        mvprintw(pos+4,10+kartuKe*6,R"(| '--'A|)");
        mvprintw(pos+5,10+kartuKe*6,R"(`------')");
    switch(angka){
        case 1 :
            mvprintw(pos+1,11+kartuKe*6,R"(A.)");
            mvprintw(pos+4,15+kartuKe*6,R"('A)");
            break;
        case 2 :
            mvprintw(pos+1,11+kartuKe*6,R"(2.)");
            mvprintw(pos+4,15+kartuKe*6,R"('2)");
            break;
        case 3 :
            mvprintw(pos+1,11+kartuKe*6,R"(3.)");
            mvprintw(pos+4,15+kartuKe*6,R"('3)");
            break;
        case 4 :
            mvprintw(pos+1,11+kartuKe*6,R"(4.)");
            mvprintw(pos+4,15+kartuKe*6,R"('4)");
            break;
        case 5 :
            mvprintw(pos+1,11+kartuKe*6,R"(5.)");
            mvprintw(pos+4,15+kartuKe*6,R"('5)");
            break;
        case 6 :
            mvprintw(pos+1,11+kartuKe*6,R"(6.)");
            mvprintw(pos+4,15+kartuKe*6,R"('6)");
            break;
        case 7 :
            mvprintw(pos+1,11+kartuKe*6,R"(7.)");
            mvprintw(pos+4,15+kartuKe*6,R"('7)");
            break;
        case 8 :
            mvprintw(pos+1,11+kartuKe*6,R"(8.)");
            mvprintw(pos+4,15+kartuKe*6,R"('8)");
            break;
        case 9 :
            mvprintw(pos+1,11+kartuKe*6,R"(9.)");
            mvprintw(pos+4,15+kartuKe*6,R"('9)");
            break;
        case 10 :
            mvprintw(pos+1,11+kartuKe*6,R"(10)");
            mvprintw(pos+4,15+kartuKe*6,R"(10)");
            break;
        case 11 :
            mvprintw(pos+1,11+kartuKe*6,R"(J.)");
            mvprintw(pos+4,15+kartuKe*6,R"('J)");
            break;
        case 12 :
            mvprintw(pos+1,11+kartuKe*6,R"(Q.)");
            mvprintw(pos+4,15+kartuKe*6,R"('Q)");
            break;
        case 13 :
            mvprintw(pos+1,11+kartuKe*6,R"(K.)");
            mvprintw(pos+4,15+kartuKe*6,R"('K)");
            break;
    }
    refresh();
}



