//SevenSeg 클래스 구현
//int n, char seg[15]
//SevenSeg(int n)//초기화 0<=n<=9
//cout에 대한 << operator overloading
// - 
//| |
// -
//| |
// _

/*
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class SevenSeg {
	//멤버 변수
	int n;
	char seg[15];
	void Set();
public:
	SevenSeg(int n); //constructure 구현
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
};
void SevenSeg::Set() {
	seg[0] = ' ';
	seg[2] = ' ';
	seg[4] = ' ';
	seg[6] = ' ';
	seg[8] = ' ';
	seg[10] = ' ';
	seg[12] = ' ';
	seg[14] = ' ';
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[1] = '-'; else seg[1] = ' ';
	if (n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[3] = '|'; else seg[3] = ' ';
	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 || n == 0) seg[5] = '|'; else seg[5] = ' ';
	if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) seg[7] = '-'; else seg[7] = ' ';
	if (n == 2 || n == 6 || n == 8 || n == 0) seg[9] = '|'; else seg[9] = ' ';
	if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[11] = '|'; else seg[11] = ' ';
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) seg[13] = '-'; else seg[13] = ' ';
}
SevenSeg::SevenSeg(int n) {
	this->n = n;
	Set();
}

//print 
ostream& operator<<(ostream& os, SevenSeg& ss) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			os << ss.seg[k++];
		}
		os << endl;
	}
	return os;
}
int main() {
	SevenSeg myseg1(1), myseg2(2), myseg3(3), myseg4(4), myseg5(5), myseg6(6), myseg7(7), myseg8(8), myseg9(9), myseg0(0);
	cout << myseg1 << myseg2 << myseg3 << myseg4 << myseg5 << myseg6 << myseg7 << myseg8 << myseg9 << myseg0;
}
*/