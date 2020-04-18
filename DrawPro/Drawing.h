#ifndef __MAINPRO__

#include <iostream>
#include <windows.h>

using namespace std;

class Line {
private:
	int x, y; // 좌푯값
	int color; // 16진수 , 색상

public:
	Line() { x = 25; y = 0; initColor(); setLineColor(); } // 생성자
	~Line() {} // 소멸자

	// 좌푯값 설정
	void setPos(int px, int py) { x = px/2; y = py; }

	// 상단 2줄(y값 0 ~ 1)은 설정 바. 즉 '입력'이 아닌 '설정'을 위한 클릭일 경우 false를 반환
	bool checkPos() { if (y >= 3) return true; else return false; } 
	
	// 선 색상 흰색으로 초기화
	void initColor() { color = 0xF; }
	
	// 보드 초기화(검정)
	void initBoard();

	int getXPos() { return x; }
	int getYPos() { return y; }
	
	int getColor() { return color; }

	bool setLineColor(int n = 0); // 색상 변경

	bool drawLine(); // 선 출력
	//bool setLine(); // 선 색 설정
};


void gotoxy(int x, int y);

void setcolor(int color, int bgcolor);

#endif __MAINPRO__