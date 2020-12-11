
#include <iostream>
#include <vector>


int main()
{
// Construct : Constructs a vector, initializing its contents depending on the constructor version used:
// empty, fill, range, copy, move, initialozer list

std::vector<int> first;
std::vector<int> second (4,100);
std::vector<int> third(second.begin(), second.end());
std::vector<int> fourth(third);

int myints[]={16,2,77,29};
std::vector<int> fifth (myints,myints+sizeof(myints)/sizeof(int));

std::cout << "The contents of fifth are : " ;
for (std::vector<int>::iterator it=fifth.begin(); it != fifth.end(); ++it)
	{
	std::cout << ' ' << *it ;
	}
std::cout <<std::endl;

std::cout << "The contents of Fourth are : ";
for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
{
	std::cout << ' ' << *it;
}
std::cout << std::endl;

std::cout << "The contents of Third are : ";
for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
{
	std::cout << ' ' << *it;
}
std::cout << std::endl;

//fifth.~vector();			// make initialze VECTOR

std::cout << "The contents of fifth are : ";
for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
{
	std::cout << ' ' << *it;
}
std::cout << std::endl;
std::cout <<fifth.size() << std::endl;
std::cout << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////
/// std::vector::operator=
std::vector<int> bar (5,0);
std::vector<int> foo(3,0);

bar=foo;
foo=std::vector<int>();

std::cout << "Size of foo : " << int(foo.size()) << std::endl;
std::cout << "size of bar : " << int(bar.size()) << std::endl;

bar =third;
for (std::vector<int>::iterator it=bar.begin(); it !=bar.end(); it++)
	std::cout << "bar data : " << *it << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////
/// std::vector::rbegin
std::vector<int> foo1(5);
std::vector<int>::reverse_iterator rit=foo1.rbegin();

int i=0;

for (;rit != foo1.rend(); rit++)
	*rit=++i;

std::cout << "foo1 : ";
for (std::vector<int>::iterator it=foo1.begin(); it != foo1.end() ; it++)
	std::cout << ' ' <<  *it  ;
std::cout << std::endl;

std::cout << std::endl;

int c=fifth.size();

std::cout << "fifth : ";
for (int it = (c-1); it >= 0;it--)
std::cout << ' ' << fifth[it];
std::cout << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////
/// std::vector::max_size   // Returns the maximum number of elements that the vector can hold.

std::cout << "max_size: " << fifth.max_size() << "\n";
std::cout << "capacity: " << fifth.capacity() << "\n";

////////////////////////////////////////////////////////////////////////////////////////////
/// std::vector::at   // Returns a reference to the element at position n in the vector.
for (unsigned int i=0; i < foo1.size() ; i++)
	foo1.at(i)=i*2;

std::cout << "foo1 : ";
for (unsigned int i=0; i <foo1.size() ; i++)
	std::cout << ' ' << foo1.at(i);
std::cout << std::endl;
for (unsigned int i = 0; i < foo1.size(); i++)
	std::cout << ' ' << foo1[i];
std::cout << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////
/// std::vector::data   // Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
std::vector<int> myvector(5);

int* p = myvector.data();

*p = 10;
++p;
*p = 20;
p[3] = 100;

std::cout << "myvector contains:";
for (unsigned i = 0; i < myvector.size(); ++i)
	std::cout << ' ' << myvector[i];
std::cout << '\n';









std::cout << std::endl;
system("pause");
return 0;
}