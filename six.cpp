//좌표에서 움직였을 때 도착지가 어디인지 찍기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Path {
	int x1, y1, x2, y2;
public:
	Path(int xx1, int yy1, int xx2, int yy2);
	friend bool operator==(Path& a, Path& b);
};
Path::Path(int xx1, int yy1, int xx2, int yy2) {
	x1 = xx1; y1 == yy1; x2 = xx2; y2 = yy2;
}
bool operator==(Path& a, Path& b) {
	if (a.x1 == b.x1 && a.y1 == b.y1 && a.x2 == b.x2 && a.y2 == b.y2) return true;
	if (a.x1 == b.x2 && a.y1 == b.y2 && a.x2 == b.x1 && a.y2 == b.y1) return true;//방향 반대
	return false;
}

class OutofBound{};

class MyGame {
	int x, y;
	void move(char c);
public:
	MyGame();
	void move(string& commands);
	int getX();
	int getY();
	//int getCount();
};
MyGame::MyGame() { x = 0; y = 0; }
int MyGame::getX() { return x; }
int MyGame::getY() { return y; }

void MyGame::move(string& commands) { //파라미터 string //public
	for (int i = 0; i < commands.length(); i++) {
		try {
			move(commands[i]); //파라미터 char 1개 //private
		}
		catch (OutofBound& e) {
		}
	}
}

void MyGame::move(char c) {
	switch (c) {
	case 'U':
		if (y == 5) throw OutofBound();
		else y++;
		break;
	case 'D':
		if (y == -5) throw OutofBound();
		else y--;
		break;
	case 'R':
		if (x == 5) throw OutofBound();
		else x++;
		break;
	case 'L':
		if (x == -5) throw OutofBound();
		else x--;
		break;
	}
}

int main() {
	MyGame game;
	string commands = "LULLLLLLU";
	game.move(commands);
	cout << "(" << game.getX() << "," << game.getY() << ")" << endl;
	
}
