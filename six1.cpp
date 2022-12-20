//좌표에서 움직였을 때 도착지가 어디인지 찍기
//도착지까지의 거리 구하기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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
class PathQue {
	vector< Path > paths;
	bool isIn(Path& a);
public:
	void push(Path& a);
	int count();
};
//
bool PathQue::isIn(Path& a) {
	for (int i = 0; i < paths.size(); i++)
		if (paths[i] == a)return true;
	return false;
}
//
void PathQue::push(Path& a) {
	if (!isIn(a)) paths.push_back(a);
}
//
int PathQue::count() { return paths.size(); }
//
class OutofBound {};

class MyGame {
	int x, y;
	PathQue myque;
	void move(char c);
public:
	MyGame();
	void move(string& commands);
	int getX();
	int getY();
	int getCount();
};
MyGame::MyGame() { x = 0; y = 0; }
int MyGame::getX() { return x; }
int MyGame::getY() { return y; }
int MyGame::getCount() { return myque.count(); }
void MyGame::move(string& commands) {
	for (int i = 0; i < commands.length(); i++) {
		try {
			int preX = x;
			int preY = y;
			move(commands[i]);
			Path temp(preX, preY, x, y);
			myque.push(temp);
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

//
int main() {
	MyGame game;
	string commands = "ULURRDLLU";
	game.move(commands);
	cout << "(" << game.getX() << "," << game.getY() << ") -> " << game.getCount() << endl;
	//Path path1(1, 2, 3, 4), path2(3, 4, 1, 2);
	//cout << (path1 == path2) << endl;
	//Path path3(1, 2, 3, 4), path4(1,2,3,4);
	//cout << (path3 == path4) << endl;
	//Path path5(1, 2, 3, 4), path6(3, 4, 1, 1);
	//cout << (path5 == path6) << endl; //110
	Path p1(1, 2, 3, 4), p2(1, 2, 5, 6), p3(3, 4, 1, 2);
	PathQue myque;
	myque.push(p1);
	myque.push(p2);
	myque.push(p3);
	cout << myque.count() << endl;
}
