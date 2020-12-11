

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void add2(int i) {
	cout << i+2 << endl;
}


template <int val>
void addVal(int i) {
	cout << val+i << endl;
}


set<int> myset={3,1,25,7,12};
set<int, less<int>> myset2={3,1,25,7,12};

// sort function 1
bool lsb_less(int x, int y) {
	return (x%10) < (y%10);
}

// sort function 2
class Lsb_less {
	public:
		bool operator() (int x, int y) {
			return (x%10) < (y%10);
	}
};


int main() {
	vector<int> vec={2,3,4,5};
	auto pr=for_each(vec.begin(),vec.end(), add2);
		cout << *pr <<   " " << pr <<endl;

		for_each(vec.begin(), vec.end(), addVal<2>);

		for_each(vec.begin(), vec.end(), [](auto& n) {cout << n <<  " " ;});
	cout << endl;
	for_each(myset2.begin(), myset2.end(), [](auto& n) {cout << n << " "; });
	cout << endl;

	for_each(myset.begin(), myset.end(), [](auto& n) {cout << n << " "; });
	cout << endl;

	for_each(myset.begin(), myset.end(), [](auto& n) {cout << lsb_less (n,15) << " "; });
	cout << endl;

	system("pause");
	return 0;
}