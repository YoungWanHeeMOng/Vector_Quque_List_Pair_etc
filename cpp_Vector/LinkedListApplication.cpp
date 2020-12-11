

#include <iostream>
#include <math.h>

using namespace std;

#define MAX_DEGREE	101

// ���׽��� ����� ������ �����ϴ� ����ü
typedef struct polynomial
{
	float coef;		// ���
	int expo;
}polynomial;


int main()
{
	int i;
	int deg1, deg2;			// ���׽��� �ְ������� ����
	int k=0, l=0, m=0;

	// �� ���׽��� ����
	polynomial p1[MAX_DEGREE], p2[MAX_DEGREE], p3[MAX_DEGREE];


	printf("���׽�1�� �ְ������� �Է��϶� :");
	scanf_s("%d", &deg1);

	// ����ڷκ��� x^0 .....x^n ���� ����� �Է¹޴´�
	for (i = 0; i <= deg1; i++)
	{
		// x^i ���� ������� �Է��Ͻÿ�
		printf("x^%d �� ����� �Է��Ͻÿ� :", i);
		scanf_s("%f",&p1[i].coef);
		// ���׽��� �������� ����
		p1[k++].expo=i;
	}

	// �ι�° ���׽��� �Է¹޴´�
	printf("\n���׽�2�� �ְ������� �Է��϶� :");
	scanf_s("%d", &deg2);

	for (i = 0; i <= deg2; i++)
	{
		printf("x^%d �� ����� �Է��Ͻÿ� :", i);
		scanf_s("%f", &p2[i].coef);
		p2[l++].expo=i;
	}

	// ù��° ���׽��� �����
	printf("\n���׽� 1 = %.1f", p1[0].coef);
	for (i = 0; i <= deg1; i++)
	{
		printf("+ %.1fx^%d", p1[i].coef,p1[i].expo);

	}

	// �ι�° ���׽��� ���
	printf("\n���׽� 2 = %.1f", p2[0].coef);
	for (i = 0; i <= deg2; i++)
	{
		printf("+ %.1fx^%d", p2[i].coef, p2[i].expo);

	}

	// �� ���׽��� ���� ���
	// ù ���׽��� �ְ������� ������ Ŭ ���
	if (deg1 > deg2)
	{
		for (i = 0; i <= deg2; i++)		// 0�� �׺��� - �ι�° ���� �ְ����ױ��� ����� ����
		{
			p3[m].coef=p1[i].coef + p2[i].coef;
			p3[m].expo=p1[i].expo;
			m++;
		}
		for (i = deg2+1; i <= deg1; i++)		// ù���� �׺��� - �ְ����� �ְ����ױ��� ����� ����
		{
			p3[m].coef = p1[i].coef ;
			p3[m].expo = p1[i].expo;
			m++;
		}
	}
	else {
		for (i = 0; i <= deg1; i++)
		{
			p3[m].coef=p1[i].coef+p2[i].coef;
			p3[m].expo=p1[i].expo;
			m++;
		}
		for (i = deg1+1; i <= deg2; i++)
		{
			p3[m].coef = p1[i].coef ;
			p3[m].expo = p1[i].expo;
			m++;
		}
	}

	// �� ���׽��� ���� ���
	printf("\n�� ������ �� = %.1f", p3[0].coef);
	for (i=1; i<m; i++)
		printf("  + %.1fx^%d", p3[i].coef,p3[i].expo);

	printf("\n");

system("pause");
return 0;
}