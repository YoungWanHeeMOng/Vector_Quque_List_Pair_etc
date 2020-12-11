

#include <iostream>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

#define NAME_SIZE	32

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, *PSTUDENT;

typedef struct _tagNode
{
	STUDENT		tStudent;
	_tagNode *	pNext;
	_tagNode *	pPrev;
}NODE, *PNODE;

typedef struct _tagList
{
	//   pBegin 과 pEnd는 명시적으로 처음과 끝을 의미하도록 만든다. 실제 데이터를 저장하는 
	// 노드는 아니다. 실제 데이터를 저장하는 노드는 pBegin과  pEnd 사이에 존재하게 만들어준다.
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;
}LIST, *PLIST;


int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize-1);
}


void InitLIst(PLIST pList)
{
	pList->iSize =0;

	pList->pBegin=new NODE;
	pList->pEnd=new NODE;

	// 시작노드의 다음 노드
	pList->pBegin->pNext=pList->pEnd;
	pList->pEnd->pPrev=pList->pBegin;

	pList->pEnd->pNext=NULL;
	pList->pBegin->pPrev=NULL;

}









int main()
{
	LIST		tList;

	InitLIst(&tList);

	while (true)
	{

	}

	system ("pause");
	return 0;
}