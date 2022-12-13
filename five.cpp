//가장 넓은 정사각형 구하기
//정사각형 넓이 구하기
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class P11 {
	//private 
//protected:
	vector< vector<int> > table;
	int width, height;
	int getArea(int top, int left);
	bool isSquare(int top, int left, int bottom, int right);
public:
	P11(vector< vector<int>> table);
	int solution();
};

P11::P11(vector< vector<int> > table) {
	this->table = table;
	width = table[0].size();
	height = table.size();
}


int P11::solution() {
	int maxarea = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int area = getArea(i, j);
			if (area > maxarea) maxarea = area;
		}
	}
	return maxarea;
}

int P11::getArea(int top, int left) {
	int maxarea = 0;
	for (int j = left; j < width; j++) {
		for (int i = top; i < height; i++) {
			if (isSquare(top, left, i, j)) {
				int area = (i - top + 1) * (j - left + 1);
				if (area > maxarea) maxarea = area;
			}
		}
	}
	return maxarea;
}
bool P11::isSquare(int top, int left, int bottom, int right) {
	if ((bottom - top) != (right - left)) return false;
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			if (table[i][j] != 1) return false;
	return true;
}
int main() {
	vector<int> row;
	vector< vector<int> > table;
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	table.push_back(row);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	table.push_back(row);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	table.push_back(row);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	table.push_back(row);
	P11 myp11(table);
	cout << myp11.solution() << endl;
}
*/