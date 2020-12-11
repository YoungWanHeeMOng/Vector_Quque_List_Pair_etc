
#include <iostream>

using namespace std;

template <typename T> class TestC
{
	public:
		void func1(){ cout <<  " func1 "  << endl; }
		void func2(){ cout << " func2 " << endl; }
};

//template void TestC<int>::func1();

template<typename T> T testFunc(T a)
{
	return a+a;
}

//template int testFunc<int>(int);

int main()
{
	int s1 = testFunc(5);
	int s2=testFunc<int>(10);
	cout << s1 << " : " << s2 << endl;

	TestC<int> t1;

	t1.func1();
	t1.func2();



	system("pause");
	return 0;
}