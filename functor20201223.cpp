
#include <iostream>

using namespace std;
//
//class Mul {
//	int _val;
//	public:
//		Mul(){}
//		Mul(int val) : _val{val} {}
//
//		int operator() (int val) {
//			return val*_val;
//		}
//};
//
//int main() {
//	Mul mul12(12);
//	cout << mul12(12) << endl;
//	cout << mul12(23)  << endl;
//
//	return 0;
//}

struct Date {
	unsigned int d : 5;
	unsigned int m : 4;
	unsigned int y;
};


int main()
{
	Date d;

	d.d=8; d.m=9; d.y=2020;
	cout << d.d << "/" << d.m << "/" << d.y << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(Date) << endl;

	return 0;
}