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
public:
	FX(long long n);
	long long solution();
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
int main() {
	long long n = 7;
	FX myfx(n);
	cout << n << ":" << myfx.solution() << endl;
}
