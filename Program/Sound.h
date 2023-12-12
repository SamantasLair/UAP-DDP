#include <mmsystem.h>

void playHammer(int i){
switch(i){
case 1 : PlaySound(TEXT("hammering.wav"), NULL, SND_FILENAME | SND_ASYNC ); break;
case 2 : PlaySound(TEXT("hammering1.wav"), NULL, SND_FILENAME | SND_ASYNC ); break;
case 3 : PlaySound(TEXT("hammering2.wav"), NULL, SND_FILENAME | SND_ASYNC ); break;
}
}
