// 그림판의 "그리는"기능 포함 및 메인 화면

#include "Drawing.h"

bool Line::drawLine() { // 출력
	gotoxy(x, y);
	setcolor(0, color);
	cout << "  ";

	return true;
}

bool Line::setLineColor(int n) {
	int tmp = color + 10;
	setcolor(0, 0);
	gotoxy(tmp, 0); cout << "  ";
	gotoxy(tmp, 2); cout << "  ";

	color = x - 10;

	if (n == -1)
		color = 0xF;

	tmp = color + 10;
	setcolor(12, 0);
	gotoxy(tmp, 0); cout << "▼";
	gotoxy(tmp, 2); cout << "▲";

	return true;	
}

void Line::initBoard() {
	setcolor(0, 0);
	for (int i = 3; i < 39; i++) {
		gotoxy(0, i); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　";
	}

	///////////////////////////////////// 시작 일련과정 재개
	// 글자 색 설정
	gotoxy(10, 1);
	for (int i = 0; i < 16; i++) {
		setcolor(0, i); cout << "  ";
	}

	setLineColor(-1);

}

void gotoxy(int x, int y) { //gotoxy함수 
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)

{

	color &= 0xf;

	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);

}