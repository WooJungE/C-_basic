//Puzzle
//implement puzzle class to represent a 8-number puzzle 
//0은 빈칸을 의미
//suffle 랜덤하게 바꿈
//move 0를 이동 
//U, D, L, R
//notMoveable 좌표 밖을 벗어날 경우 실행되지 않게 함

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//예외를 위한 class
class notMoveable{};

class Puzzle {
	int cell[9];
	int x, y;
	void shuffle();
	int convert(int x, int y);
public:
	Puzzle();
	void move(char c);
	bool isDone();
	friend ostream& operator<<(ostream& os, Puzzle& pz);
};
int Puzzle::convert(int x, int y) {
	return 3 * y + x;
}

Puzzle::Puzzle() {
	for (int i = 0; i < 8; i++) cell[i] = i + 1;
	cell[8] = 0;
	x = 2; y = 2;
	shuffle();
}
void Puzzle::shuffle() {
	srand(time(NULL));
	int rn;
	for (int i = 0; i < 4; i++) { //i < n // n= 원하는 횟수
		rn = rand() % 4;
		try {
			switch (rn) {
			case 0: move('u'); break;
			case 1: move('d'); break;
			case 2: move('l'); break;
			case 3: move('r'); break;
			}
		}
		catch (notMoveable &e){
		}
	}
}
void Puzzle::move(char c) {
	int to, from;
	switch (c) {
	case 'u':
		if (y == 0) throw notMoveable();
		to = convert(x, y - 1);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		y--;
		break;
	case 'd':
		if (y == 2) throw notMoveable();
		to = convert(x, y + 1);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		y++;
		break;
	case'l':
		if (x == 0) throw notMoveable();
		to = convert(x-1, y);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x--;
		break;
	case'r':
		if (x == 2) throw notMoveable();
		to = convert(x+1, y);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x++;
		break;
	default:
		throw notMoveable();
	}
}
bool Puzzle::isDone() {
	for (int i = 0; i < 8; i++) if (cell[i] != i + 1) return false;
	if (cell[8] != 0) return false;
	return true;
}
ostream& operator<<(ostream& os, Puzzle& pz) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			os << pz.cell[k++] << ' ';
		os << endl;
	}
}

int main() {
	Puzzle mypuzzle;
	cout << mypuzzle;
	while (!(mypuzzle.isDone())) {
		char c;
		cout << "Choice movement: ";
		cin >> c;
		try {
			mypuzzle.move(c);
			cout << mypuzzle;
		}
		catch (notMoveable& e) {
		}
	}
	cout << "It's done" << endl;
}
