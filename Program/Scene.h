
#include <ncurses/curses.h>
#include <fstream>
#include <conio!getch.h>//conio.h yg diedit getch nya karena tabrakan dgn curses.h

using namespace std;
string ombak1 = "~`'^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`", 
ombak2="_,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,.-=~'`^`'~=-.,__,.-=~'",
ombak3="-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-==--^'~=-.,__,.-=~' ",
ombak4="_,.;^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__, ",
ombak5=";,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~= ",
ombak6=";_,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,";
 

void Lake(int skor){
refresh();
clear();
start_color();
init_pair(4,COLOR_YELLOW,COLOR_BLACK);
init_pair(5,COLOR_BLUE,COLOR_BLACK);
mvprintw(1,40,"Tugas anda selesai nikmatilah healing anda");
mvprintw(2,40,"Skor anda : %d",skor);
mvprintw(1,1, R"(              ,.  _~-.,               .								            )");
mvprintw(2,1, R"(           ~'`_ \/,_. \_												            )");
mvprintw(3,1, R"(          / ,"_>@`,__`~.)             |           .					            )");
mvprintw(4,1, R"(          | |  @@@@'  ",! .           .          '					                )");
mvprintw(5,1, R"(          |/   ^^@     .!  \          |         /						            )");
mvprintw(6,1, R"(          `' .^^^     ,'    '         |        .             .			            )");
mvprintw(7,1, R"(           .^^^   .          \                /          .				            )");
mvprintw(8,1, R"(          .^^^       '  .     \       |      /       . '				            )");
attron(COLOR_PAIR(4)); mvprintw(9,1, R"(.,.,.)");attroff(COLOR_PAIR(4));mvprintw(9,6,R"(     ^^^             ` .   .,+~'`^`'~+,.     , '					            )");
attron(COLOR_PAIR(4)); mvprintw(10,1, R"(&&&&&&,)");attroff(COLOR_PAIR(4));mvprintw(10,7,R"(  ,^^^^.  . ._ ..__ _  .'             '. '_ __ ____ __ _ .. .  .            )");
attron(COLOR_PAIR(4)); mvprintw(11,1,R"(%%%%%%%%%^^^^^^%%&&;,_,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,	            )");attroff(COLOR_PAIR(5));
attron(COLOR_PAIR(4)); mvprintw(12,1,R"(&&&&&%%%%%%%%%%%%%%%%%%&&;)"); attroff(COLOR_PAIR(4)); mvprintw(12,26,R"(,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=           )");
attron(COLOR_PAIR(4)); mvprintw(13,1,R"(%%%%%&&&&&&&&&&&%%%%&&&_,.;^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,           )"); mvprintw(14,1,R"(%%%%%%%%%&&&&&&&&&-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-==--^'~=-.,__,.-=~'           )");
mvprintw(15,1,R"(##mjy#####*"'															            )");
mvprintw(16,1,R"(_,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,.-=~'`^`'~=-.,__,.-=~'           )");
mvprintw(17,1,R"(																		            )");
mvprintw(18,1,R"(~`'^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`^`'~=-.,__,.-=~'`            )");
attroff(COLOR_PAIR(4)); attron(COLOR_PAIR(5));

ofstream myfile;
myfile.open("Skor",ios::app);
    if(!myfile.fail()){
    myfile<<skor<<endl;
    myfile.close();
    }
    refresh();
}
 //buat animasi ombak
void animatedLake(int maxX, int maxY){
//initscr();
start_color();
init_pair(6,COLOR_BLUE,COLOR_BLUE);

    //box(win, 0, 0);
    
    while(true){
    	if (kbhit()) {
    		char input = getch();
    		if (input == 'q') break;
  			}
    int shift_per_frame = 1; // number of characters to shift per frame
    ombak1 = ombak1.substr(shift_per_frame) + ombak1.substr(0, shift_per_frame);// Shift text
    ombak2 = ombak2.substr(shift_per_frame) + ombak2.substr(0, shift_per_frame);
	ombak3 = ombak3.substr(shift_per_frame) + ombak3.substr(0, shift_per_frame);// Shift text
    ombak4 = ombak4.substr(shift_per_frame) + ombak4.substr(0, shift_per_frame);
	ombak5 = ombak5.substr(shift_per_frame) + ombak5.substr(0, shift_per_frame);// Shift text
    ombak6 = ombak6.substr(shift_per_frame) + ombak6.substr(0, shift_per_frame);
	
	//wrefresh(win);
	mvprintw(18,1,ombak1.c_str());// Print shifted text
	mvprintw(16,1,ombak2.c_str());
    mvprintw(14,16,ombak3.c_str());// Print shifted text
	mvprintw(13,20,ombak4.c_str());
    mvprintw(12,22,ombak5.c_str());// Print shifted text
	mvprintw(11,18,ombak6.c_str());
    //wrefresh(win);
	// Delay between frames
    Sleep(90);
    refresh();
	}
}

