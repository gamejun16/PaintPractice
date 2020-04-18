/******

180103
C++Ȱ�� �ֱܼ�� �׸��� ī��

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

	

	//Ŀ�� ������ ����
	removeCursor();

	// ����¿� ���� �ڵ��� �����ɴϴ�.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Line line;	// �������� ������ �����ϴ� ��ü ( ��ǥ, �� )
				// ���� '�ڷΰ���'�� ���� ��� ������ ���� �ʼ�


	// ���� �� ���� UI
	gotoxy(10, 1);
	for (int i = 0; i < 16; i++) {
		setcolor(0, i); cout << "  ";
	}
	// ��ü���� UI
	setcolor(0, 14);
	gotoxy(30, 1); cout << "��";

	while (true) {

		setcolor(0, 0xF);

		gotoxy(0, 0);
		cout << "( " << rec.Event.MouseEvent.dwMousePosition.X << " , " << rec.Event.MouseEvent.dwMousePosition.Y << " )";

		// ����ڷκ��� �Է��� �޽��ϴ�.
		PeekConsoleInput(hIn, &rec, 1, &dw);
		// ���콺 ��� �Ͼ �� ��쿡�� ReadConsoleInput()�Լ��� ��ħ.
		if (dw > 0)
			ReadConsoleInput(hIn, &rec, 1, &dw);

		

		// ��Ŭ�� �߻�
		if (rec.Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) {
			line.setPos(rec.Event.MouseEvent.dwMousePosition.X, rec.Event.MouseEvent.dwMousePosition.Y); // ��ǩ�� ����
			if (line.checkPos()) { // '�׸�'�� �ǵ��� Ŭ�������� Ȯ���ϴ� �Լ�
				if (line.getYPos() != 39 && line.getYPos() != 3)
					line.drawLine(); // ���
			}
			else {	// '�׸�' ���� ���� �ǵ��� Ŭ���� ���
				if (line.getXPos() >= 10 && line.getXPos() <= 25)
					line.setLineColor();
				else if (line.getXPos() == 30) // �׸� �ʱ�ȭ

					line.initBoard();
			}
		}

		/*
		// ��Ŭ�� �߻�
		if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
			line.setColor(0);
			line.setPos(rec.Event.MouseEvent.dwMousePosition.X, rec.Event.MouseEvent.dwMousePosition.Y); // ��ǩ�� ����

			if (line.checkPos()) // '�׸�'�� �ǵ��� Ŭ�������� Ȯ���ϴ� �Լ�
				line.DrawLine(); // ���
		}
		*/

	}

	return 0;
}

void removeCursor(void)//Ŀ�� ������ ����
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}