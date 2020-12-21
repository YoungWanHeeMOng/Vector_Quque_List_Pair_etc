
#include <iostream>

using namespace std;

//template<typename T>
//void print(const T x) {
//	static int var=10;
//	cout << ++var << endl;
//}
//
//void print(const double x) {
//	static int var =20;
//	cout << ++var << endl;
//}

template<typename T>
class Print {
	private:
		int x;
	public:
		static T var;
		void printVal() { cout << ++var << endl;}
};

template<class T>
T Print<T>::var=0;

int main()
{
	//print (1);
	//print(2);
	//print('x');
	//print (1.5);

	Print<int> p;
	p.printVal();
	p.printVal();
	
	Print<int> p1;
	p1.printVal();

	Print<float> f;
	f.printVal();
	f.printVal();

	Print<float> f1;
	f1.printVal();

return 0;
}