//four.cpp와 같은 문제
//주어진 수를 10진수 2진수로 바꾸기
//주어진 수에서 1큰 값부터 차례대로
//주어진 수와 비교하여 
//0과 1이 2이하로 다른 수 찾기(조건을 만족하는 최솟값)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FX {
protected: //상속
	long long n;
	int diff(long long n, long long i);
	virtual int limit();
public:
	FX(long long n);
	long long solution();
};

class FX2 : public FX {
protected:
	virtual int limit();
public:
	FX2(long long n);
};

FX::FX(long long n) { this->n = n; }
long long FX::solution() {
	long long i;
	for (i = n + 1; diff(n, i) > limit(); i++);
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
int FX::limit() { return 2; }
FX2::FX2(long long n) : FX(n) { ; }
int FX2::limit() { return 3; }
int main() {
	long long n = 7;
	FX myfx(n);
	FX2 myfx2(n);
	cout << n << ":" << myfx.solution() << endl;
	cout << n << ":" << myfx2.solution() << endl;
}
