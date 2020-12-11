
#include <iostream>
#include <array>
#include <limits>
#include <string>

using namespace std;

const int cMkts = 4, cFacts = 3;
double TransportCosts[][cMkts] = {
   { 32.19, 47.29, 31.99, 19.11 },
   { 11.29, 22.49, 33.47, 17.29 },
   { 41.97, 22.09,  9.76, 22.55 }
};
double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts);

class Point
{
	public:
		Point()
		{

		}
		Point(int, int)
		{

		}
};

Point aPoint[3] = { Point(3,3)};

// initializing_arrays2.cpp
class WindowColors
{
public:
	static const char* rgszWindowPartList[7];
};

const char* WindowColors::rgszWindowPartList[7] = {
    "Active Title Bar", "Inactive Title Bar", "Title Bar Text",
    "Menu Bar", "Menu Bar Text", "Window Background", "Frame" };

int main()
{
	// declare
	std::array<int, 5> myarray;

	std::array<int , 5> myarray1={1,2,3,4,5};
	std::array<int, 5> myarray2 {1,2,3,4,5};

	myarray={6,7,8,9,10};
	
	std::array<int , 10> myarray3={0};
	myarray ={ myarray1};
	//myarray3 ={ myarray2,myarray };

	for (auto & element:myarray)
		cout << " Array : " << element << ' ';

	cout <<  endl;
	for (const auto& element : myarray3)
		cout << " Array : " << element << ' ';
	cout << endl;

	const int num=sizeof(myarray2)/sizeof(myarray2[0]);
	for (int i=0; i < num ; i++)
		cout << " myarray2 : " << myarray2[i] << ' ';
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		myarray3[i]=myarray[i]+myarray2[num -1-i];
		cout << " myarray3 : " << i << " : " << myarray3[i] << ' ';
	}
	cout << endl;

	const int num3 = (sizeof(myarray3) / sizeof(myarray3[0]));
	for (int i = num; i < num3; i++)
	{
		myarray3.at(i) = myarray[i-num] * myarray2[num3-i-1];
		cout << " myarray3 : " << i << " : " <<  myarray3[i] << ' ';
	}
	cout << endl;

	int size=9;
	double * numbers=new double[size] {0};
	const int num4 = (sizeof(numbers) / sizeof(numbers[0]));
	for (int i = 0; i < num4; i++)
	{
		cout << " numbers : " << sizeof(numbers) << " : " << numbers[i] << ' ';
	}
	cout << endl;

	numbers[0]=1;
	for (int i = 0; i < size; i++)
	{
		cout << i <<"  : "  << numbers[i] << ' ';
	}
	cout << endl;

	double *p=numbers;
	for (int i = 0; i < size; i++)
	{
		cout << i << "  : " << *p++ << " // ";
	}
	delete[] numbers;
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////////////////
	/// limits
	

	// Declare a float that represents the transportation costs

	const int cFactories=sizeof(TransportCosts)/sizeof(double[cMkts]);
	

	double MinCost;
	int c=3;
	MinCost=FindMinToMkt(c, TransportCosts, cFacts);
	cout << "The minimum cost to Market " << c << " is: "		<< MinCost << "\n";
	cout << endl;

	for (int i =0; i < 7; i++)
		cout << WindowColors::rgszWindowPartList[i] << endl;

	cout << endl;

	array<int, 3> arr1 = { 91, 92, 93 };

	//test1 : iterator
	cout << " 1. iterator : ";
	array<int, 3>::iterator iter;
	for (iter = arr1.begin(); iter != arr1.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//test2 : data
	cout << " 2. data()" << endl;
	cout << " arr1.data() : " << arr1.data() << endl;
	cout << " *(arr1.data())     : " << *(arr1.data()) << endl;
	cout << " *(arr1.data() + 1) : " << *(arr1.data() + 1) << endl;
	cout << " *(arr1.data() + 2) : " << *(arr1.data() + 2) << endl;

	cout << endl;
	//test3 : at, operator[]
	cout << " 3. at(n), operator[n]" << endl;
	cout << " arr.at(0) : " << arr1.at(0) << endl;
	cout << " arr.at(1) : " << arr1.at(1) << endl;
	cout << " arr.at(2) : " << arr1.at(2) << endl;
	cout << " arr[0] : " << arr1[0] << endl;
	cout << " arr[1] : " << arr1[1] << endl;
	cout << " arr[2] : " << arr1[2] << endl;

	cout << endl;

	array<string, 3> arr11 = { "blockdmask", "C++", "coding" };

	//1. front, back
	cout << " 1. front, back" << endl;
	cout << " arr11.front() : " << arr11.front() << endl;
	cout << " arr11.back() : " << arr11.back() << endl;
	cout << endl;

	//2. fill, swap
	cout << " 2. fill, swap" << endl;
	cout << " arr11 default : " << arr11[0] << ", " << arr11[1] << ", " << arr11[2] << endl;

	//string  ch[3]={"array example"};
	arr11.fill("array example");
	cout << " arr11 fill() : " << arr11[0] << ", " << arr11[1] << ", " << arr11[2] << endl;

	array<string, 3> arr21 = { "tmp1", "tmp2", "tmp3" };
	arr11.swap(arr21);
	cout << " arr11 swap() : " << arr11[0] << ", " << arr11[1] << ", " << arr11[2] << endl;

	cout << endl;


return 0;
}

double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts)
{
	double MinCost=DBL_MAX;
	cout << "The cost to Market " << MinCost << "\n";
	for(size_t i=0; i < cFacts; i++)
	{
		MinCost=(MinCost < TransportCosts[i][Mkt]) ? MinCost  : TransportCosts[i][Mkt];
		cout << "The cost to Market " << MinCost  << "\n";
		}

return MinCost;
}