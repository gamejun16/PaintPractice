#ifndef __MAINPRO__

#include <iostream>
#include <windows.h>

using namespace std;

class Line {
private:
	int x, y; // ��ǩ��
	int color; // 16���� , ����

public:
	Line() { x = 25; y = 0; initColor(); setLineColor(); } // ������
	~Line() {} // �Ҹ���

	// ��ǩ�� ����
	void setPos(int px, int py) { x = px/2; y = py; }

	// ��� 2��(y�� 0 ~ 1)�� ���� ��. �� '�Է�'�� �ƴ� '����'�� ���� Ŭ���� ��� false�� ��ȯ
	bool checkPos() { if (y >= 3) return true; else return false; } 
	
	// �� ���� ������� �ʱ�ȭ
	void initColor() { color = 0xF; }
	
	// ���� �ʱ�ȭ(����)
	void initBoard();

	int getXPos() { return x; }
	int getYPos() { return y; }
	
	int getColor() { return color; }

	bool setLineColor(int n = 0); // ���� ����

	bool drawLine(); // �� ���
	//bool setLine(); // �� �� ����
};


void gotoxy(int x, int y);

void setcolor(int color, int bgcolor);

#endif __MAINPRO__