// function handing in C++

#include <iostream>

using namespace std;

class Base {
	public:
		void fun() {cout << "Void" << endl; }
		int fun(int i) {
			cout << "Base" << endl;
			return i;
		}
};

class Derived : public Base {
	public:
		using Base::fun;

		int fun(char c) {
			cout << "Derived" << endl;

			return c;
		}
};

int main()
{
	Derived d;
	d.Base::fun(1);
	d.fun(1);
	d.fun('a');
	d.fun();
	d.Base::fun();



//system("pause");
return 0;
}