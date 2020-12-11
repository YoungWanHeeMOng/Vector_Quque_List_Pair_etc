
#include <iostream>
#include<vector>

using namespace std;

int main()
{
	vector <int>  v;//={0,1,2,3,4,5};
	vector<int>::iterator rv;

	std::cout << "[ v[i] , v.size(), v.capacity() ] " << std::endl;
	for (int i = 0; i <= 64; i++) {
		v.push_back(i + 1);
		std::cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity() << "]" << std::endl;
	}
	std::cout<<std::endl;
	for (int i = 0; i <= 64; i++) {
		
		std::cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity() << "]" << std::endl;
	}
	v[64]=999;

	rv=v.begin();
	rv=v.insert(rv,66);

	v.insert(rv+30,1,300);

	rv = v.begin();
	std::vector<int> anothervector(2, 400);
	v.insert(rv + 2, anothervector.begin(), anothervector.end());



	std::cout << std::endl;
	for (int i = 0; i < v.size(); i++) {

		std::cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity() << "]" << std::endl;
	}

	std::cout << std::endl;
	int i=0;
	for (rv= v.begin(); rv <v.end(); rv++)
	{
		std::cout << "vector <int>::iterator " << i << "  [" << *rv <<  "]" << std::endl;
		i++;
	}

system("pause");
return 0;
}