// why operator over loading
// use when it makes sense.

#include <iostream>

using namespace std;

class Point {
	int x,y;
	public:
		Point():x(0), y(0) {}
		Point(int x, int y) :x(x), y(y) {}
		Point operator + (const Point& p2) {
			Point p;
			p.x=x+p2.x;
			p.y=y+p2.y;

			return p;
		}
		void Print()
		{
			cout << "x= " << x << " y= " << y << endl;
		}
};

int main()
{
	Point p1(2,3), p2(4,5);
	Point p3=p1+p2;
	p3.Print();
	string str="YoungWan Kim";
	str=str + "C++ Hope Dream Trading";
	cout << str << endl;

	return 0;
}