#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////////////

#define col GetStdHandle(STD_OUTPUT_HANDLE) //  콘솔창의 핸들정보 받기
 
//////////////////////////////////////////////////////////////////////////색깔정의 

#define RED SetConsoleTextAttribute( col,0x000c ); //빨간색

#define BLUE SetConsoleTextAttribute( col,0x0001 | 0x0008); //파란색

#define HIGH SetConsoleTextAttribute( col,0x00a); // 연두

#define WHITE SetConsoleTextAttribute( col,0x000f); // 흰색

#define SKY SetConsoleTextAttribute( col, 0x000b); //하늘색

#define YEL SetConsoleTextAttribute( col, 0x000e); //노란색

#define HIG SetConsoleTextAttribute( col, 0x000d); //형광

#define VIO SetConsoleTextAttribute( col,0x0001 | 0x0008 |0x000c); //보라
 
int main()
{
  HANDLE  hConsole;
  int k;
 
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
  // you can loop k higher to see more color choices
  for(k = 1; k < 255; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%3d  %s\n", k, "I want to be nice today!");
  }
 
  getchar();  // wait
  return 0;
}
 
