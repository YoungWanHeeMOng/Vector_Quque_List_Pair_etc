
#include <iostream>
#include <string>

class Book;

template <typename data, typename compare>
data* get_maxpos(data* base, size_t n, compare com)
{
	size_t mi=0;
	size_t index;
	for (index = 1; index < n; index++)
	{
		if (com(base[mi], base[index]) < 0)
		{
			mi=index;
		}
	}

	return base + mi;  // base 에서 mi의 번쨰 간다
}

int compare_int(int a, int b)
{
	return a-b;
}

class Book
{
	std::string isbn;
	std::string title;

	public:
		Book(std::string isbn, std::string title)
		{
			this->isbn=isbn;
			this->title=title;
		}
		void View() const
		{
			std::cout << "제목 : " << title << " ,isbn : " << isbn << std::endl;
		}
		std::string GetISBN() const {return isbn;}
		std::string GetTitle() const {return title;}

};

int compare_sibn(Book* book1, Book* book2)
{
	std::string isbn1=book1->GetISBN();
	std::string isbn2=book2->GetISBN();
	return isbn1.compare(isbn2);
}

int main()
{
	int arr[10]={5,2,3,49,34,7,6,4,8,19};

	int *mi=get_maxpos(arr, 10, compare_int);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;


	std::cout << "최대값 : " << *mi <<  " 최대값 요소의 인덱스 : " << mi - arr << std::endl;

	Book *books[5];
	books[0]=new Book("1234", "C언어");
	books[1] = new Book("7234", "C++");
	books[2] = new Book("1734", "알고리즘");
	books[3] = new Book("6734", "자료구조");
	books[4]= new Book("1294", "C#");

	Book ** mbi = get_maxpos(books, 5, compare_sibn);
	for (int i = 0; i < 5; i++)
	{
		books[i]->View();
	}
	std::cout << std::endl;
	std::cout << "==============최대값 ISBN ============== " << std::endl;
	(*mbi)->View();

	std::cout << "=최대값 ISBN ==요소  " <<  mbi-books <<std::endl;




return 0;
}