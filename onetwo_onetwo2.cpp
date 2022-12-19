//SevenSegs 클래스 구현
//int n, vector<SevenSeg>
//SevenSegs(int n)//초기화, n은 임의의 양의 정수
//cout에 대한 <<operator overloading 
//1번과 달리 숫자 하나만 주어지는 것이 아닌 십의 자리, 백의 자리 그 이상 표현 가능


#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class SevenSegs;

class SevenSeg {
	//멤버 변수
	int n;
	char seg[15];
	void Set();
public:
	SevenSeg(int n); //constructure 구현
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
};

class SevenSegs {
	int n;
	vector<SevenSeg> segs;
	void Set();
public :
	SevenSegs(int n);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
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

void SevenSegs::Set() {
	for (int k = n; k > 0; k = k / 10) {
		SevenSeg temp(k % 10);
		segs.push_back(temp);
	}
}
SevenSegs::SevenSegs(int n) {
	this->n = n;
	Set();
}

//print 
ostream& operator<<(ostream& os, SevenSegs& ss) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = ss.segs.size() - 1; j >= 0; j--) {
			for (int l = 0; l < 3; l++) {
				os << ss.segs[j].seg[k + l];
			}
		}
		k += 3;
		os << endl;
	}
	return os;
}

int main() {
	SevenSegs myseg1(123), myseg2(54321);
	cout << myseg1 << myseg2;
}
