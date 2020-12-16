
//#include <windows.h>
#include <iostream>

using namespace std;

int add(int A, int B)
{
	return A+B;
}

int sub(int A, int B)
{
	return A - B;
}

typedef int (*mathFun)(int, int);
typedef int (*mathFun1)(int, int);
//mathFun fun(int type) {
//	if (type==1) return add;
//	if (type==2) return sub;
//}
//int main(int argc, char* argv[])
//{
//	int (*someFun)(int, int) ;
//	someFun=fun(2);
//
//	int c= someFun(1,2);
//
//
//	cout << c << endl;
//	printf("%d\n",c);
//
//system ("pause");
//return 0;
//}

int main(int argc, char* argv[])
{
	
	//mathFun1 Arr[2] = { add,sub };
	int (* Arr[2])(int,int) = { add,sub };
	int b = (*Arr[0])(1, 2);
	int d = (*Arr[1])(2, 1);

	cout << b << endl;
	cout << d << endl;

	system("pause");
	return 0;
}

