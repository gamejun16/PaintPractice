/******

180103
C++활용 콘솔기반 그림판 카피

						******/


#include <iostream>
#include <Windows.h>

#include "Drawing.h"

using namespace std;

void removeCursor(void);

HANDLE hIn, hOut;
INPUT_RECORD rec;
DWORD dw;

#define RGB(r,g,b) ((COLORREF)(((BYTE)(r) | ((WORD)((BYTE)(g))<<8)) | (((DWORD)(BYTE)(b))<<16)))


int main() {

//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),);

	

	//커서 깜빡임 제거
	removeCursor();

	// 입출력에 사용될 핸들을 가져옵니다.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Line line;	// 선에대한 정보를 저장하는 객체 ( 좌표, 색 )
				// 이후 '뒤로가기'와 같은 기능 구현을 위한 초석


	// 글자 색 설정 UI
	gotoxy(10, 1);
	for (int i = 0; i < 16; i++) {
		setcolor(0, i); cout << "  ";
	}
	// 전체삭제 UI
	setcolor(0, 14);
	gotoxy(30, 1); cout << "♪";

	while (true) {

		setcolor(0, 0xF);

		gotoxy(0, 0);
		cout << "( " << rec.Event.MouseEvent.dwMousePosition.X << " , " << rec.Event.MouseEvent.dwMousePosition.Y << " )";

		// 사용자로부터 입력을 받습니다.
		PeekConsoleInput(hIn, &rec, 1, &dw);
		// 마우스 제어가 일어났 을 경우에만 ReadConsoleInput()함수를 거침.
		if (dw > 0)
			ReadConsoleInput(hIn, &rec, 1, &dw);

		

		// 좌클릭 발생
		if (rec.Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) {
			line.setPos(rec.Event.MouseEvent.dwMousePosition.X, rec.Event.MouseEvent.dwMousePosition.Y); // 좌푯값 전달
			if (line.checkPos()) { // '그림'을 의도한 클릭인지를 확인하는 함수
				if (line.getYPos() != 39 && line.getYPos() != 3)
					line.drawLine(); // 출력
			}
			else {	// '그림' 외의 것을 의도한 클릭일 경우
				if (line.getXPos() >= 10 && line.getXPos() <= 25)
					line.setLineColor();
				else if (line.getXPos() == 30) // 그림 초기화

					line.initBoard();
			}
		}

		/*
		// 우클릭 발생
		if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
			line.setColor(0);
			line.setPos(rec.Event.MouseEvent.dwMousePosition.X, rec.Event.MouseEvent.dwMousePosition.Y); // 좌푯값 전달

			if (line.checkPos()) // '그림'을 의도한 클릭인지를 확인하는 함수
				line.DrawLine(); // 출력
		}
		*/

	}

	return 0;
}

void removeCursor(void)//커서 깜빡임 제거
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}