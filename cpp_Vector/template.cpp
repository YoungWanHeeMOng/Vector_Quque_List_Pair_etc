
#include <iostream>

using namespace std;

template <typename T>
void OutputType()
{
	cout << "======= OutputType =========" << endl;
	cout << typeid(T).name() << endl;
}

template <typename T> 
void OutputData(T data)
{
	cout << "======= OutputData =========" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}


typedef struct _tagStudent
{
	

}STUDENT, *PSTUDENT;

class CCar
{
	public:
		CCar()
		{

		}

		~CCar()
		{

		}

};

enum TEST
{

};

class CTemplate
{
	public:
		CTemplate()
		{
		}

		~CTemplate()
		{
		}

	public:
		template<class T, class T1>
		void Output(T a, T1 b)
		{
			cout << a << endl;
			cout << b << endl;
		}
};

template <typename T>
class CTemplate1
{
	public:
		CTemplate1()
		{
			cout << "Template1 class Type : " << typeid(T).name() << endl;
		}

		~CTemplate1()
		{

		}

	private:
		T	m_Data;
	public:
		void Output()
		{
			cout << typeid(T).name() << endl;
			cout << m_Data << endl;
		}
};


int main()
{

	OutputType<int> ();
	OutputType<float>();
	cout << endl;

	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<TEST>();
	cout << endl;


	OutputData<int> (123);
	OutputData<float> (123.4f);
	OutputData<const char *> ("YoungWan Kim");

	cout << endl;
	OutputData(10);
	OutputData(3.1);
	OutputData("Young Wan Kim");
	OutputData("Èñ¸ù ¹«¿ª");


	CTemplate tem;
	tem.Output(11,3.14f);

	CTemplate1<int> tem1;
	tem1.Output();

	CTemplate1<CTemplate> tem2;


return 0;
}