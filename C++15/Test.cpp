#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void test_op1()
{
	srand(time(0));
	const int N = 1000000;

	list<int> lt1;
	list<int> lt2;

	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand()+i;
		lt1.push_back(e);
		v.push_back(e);
	}

	int begin1 = clock();
	// ����
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt1.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

void test_op2()
{
	srand(time(0));
	const int N = 1000000;

	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt1.push_back(e);
		lt2.push_back(e);
	}

	int begin1 = clock();
	// ����vector

	vector<int> v(lt2.begin(), lt2.end());
	// ����
	sort(v.begin(), v.end());

	// ������lt2
	lt2.assign(v.begin(), v.end());

	int end1 = clock();

	int begin2 = clock();
	lt1.sort();
	int end2 = clock();

	printf("list copy vector sort copy list sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}
//
//int main()
//{
//	test_op2();
//
//	return 0;
//}

#include"list.h"

int main()
{
	//bit::test_list3();
	bit::test_list2();

	return 0;
}