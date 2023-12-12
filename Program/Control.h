#include <conio!getch.h>//conio.h yg diedit getch nya karena tabrakan dgn curses.h
void controlKeyboard(char arah, bool game){
        if (kbhit()) {
        switch (getchar()) {
            case 'a': if(arah!='d')arah = 'a'; break;
            case 'w': if(arah!='s')arah = 'w'; break;
            case 's': if(arah!='w')arah = 's'; break;
            case 'd': if(arah!='a')arah = 'd'; break;
            case 'q': game = false; break;
            }
        }
    }

// void arahPointer(char arah, int y, int x){
//     if (arah == 'w') {
//         y--;
//     }
//     if (arah == 's') {
//         y++;
//     }
//     if (arah == 'a') {
//         x--;
//     }
//     if (arah == 'd') {
//         x++;
//     }
//     mvprintw(y, x, "k");
//     Sleep(30);
//     refresh();
// }