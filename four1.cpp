//four.cpp와 같은 문제
//10진수 2진수로 바꾸어서 0과 1이 2이하로 다른 수 찾기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FX {
protected: //상속
	long long n;
	int diff(long long n, long long i);
public:
	FX(long long n);
	long long solution();
};

class FX2 : public FX {
public:
	FX2(long long n);
	long long solution(); //override
};

FX::FX(long long n) { this->n = n; }
long long FX::solution() {
	long long i;
	for (i = n + 1; diff(n, i) > 2; i++);
	return i;
}
int FX::diff(long long n, long long i) {
	int count = 0;
	int len = sizeof(n) * 8; //n bit 구하기
	long long mask = 1;
	for (int j = 0; j < len; j++) {
		if ((n & mask) != (i & mask)) count++;
		mask = mask << 1;
	}
	return count;
}

FX2::FX2(long long n) : FX(n) { ; }
long long FX2::solution() {
	long long i;
	for (i = n + 1; diff(n, i) > 3; i++);
	return i;
}

int main() {
	long long n = 7;
	FX myfx(n);
	FX2 myfx2(n);
	cout << n << ":" << myfx.solution() << endl;
	cout << n << ":" << myfx2.solution() << endl;
}
