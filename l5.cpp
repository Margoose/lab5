#include "stdafx.h"
#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>


typedef long data;
typedef std::list<data> list;
typedef list::iterator iterator;
static const int SIZE_1 = 10;
static const int SIZE_2 = 5;

template<class T>
T build(const int &size)
{
	T new_ls;
	for (int i=1; i<=size; i++)
	{
		new_ls.push_back(rand());
	}
	return new_ls;
}

template<class T>
void print(const T &ls)
{  
	std::cout<<"\nSize: "<<ls.size()<<std::endl;
	std::cout<<"Printing of elements:\n";
	for(auto it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout<<"Element: "<<(*it)<<std::endl;
	}
}

template<class T>
void del(T &mp, int k, int n)
{
	if (int(mp.size()) < k+n && k>0 && n>=0) 
		return;

	auto itb = mp.begin();
	for (int i = 0; i<k; i++)
		itb++;

	auto ite = itb;
	for (int i = 0; i<n; i++)
		ite++;

	mp.erase(itb, ite);
}

void pr(const char &n)
{
	std::cout.fill(n);
	std::cout.width(35);
	std::cout<<""<<"\n";
}

template<class T>
bool _find(const list &ls, T t)
{
	for(auto it = ls.begin(); it != ls.end(); ++it)
		if (*it == t) return true;
	return false;
}

template<class T>
void find(const list &ls, T t)
{	
	std::cout<<"Finding data: "<<t<<std::endl;
	if (_find(ls, t)) std::cout<<t<<" is founded!\n\n";
	else std::cout<<t<<" is not founded!\n\n";
}

template<class T1>
iterator find(T1 &t1, data &d, bool &flag)
{
	for(auto it = t1.begin(); it != t1.end(); ++it)
		if (*it == d) return it;
	flag = false;
	return t1.end();
}

template<class T1, class T2>
void replace (T1 &t1, T2 &t2, data &d)
{
	bool flag = true;
	iterator it = find(t1, d, flag);
	if (!flag)
		std::cout<<"\nData: "<<d<<" is not found!\n";
	else 
	{
		std::cout<<"Replaced: "<<d<<std::endl;
		t2.push_back(d);
		t1.erase(it);
	}
}

template<class T1, class T2>
void replace(T1 &t1, T2 &t2, T2 &t3)
{
	t3.insert(t3.begin(), t1.begin(), t1.end());
	t3.insert(t3.end(), t2.begin(), t2.end());
}

template<class T1>
void count(T1 t1, data d)
{
	int count = 0;

	for(auto it = t1.begin(); it != t1.end(); ++it)
		if (*it == d) count++;

	if (count)
		std::cout<<"Found "<<count<<" elements '"<<d<<"'\n";
	else std::cout<<"Element '"<<d<<" is not found!\n";
}

void f1()
{
	list ls = build<list>(SIZE_1);

	std::cout<<"ls: \n";
	print(ls);

	std::cout<<"\nRemoving first and second elements...";
	ls.pop_front();
	ls.pop_front();

	std::cout<<"ls: \n";
	print(ls);

	std::cout<<"\nRemoving 6 elements from key = 1.\n";
	del(ls, 1, 6);

	std::cout<<"ls: \n";
	print(ls);

	list n_ls = build<list>(SIZE_2);

	pr('-');

	std::cout<<"Mixing First and Second ls.\n";
	ls.insert(ls.end(), n_ls.begin(), n_ls.end());

	std::cout<<"\nFirst ls (mixed):";
	std::cout<<"ls: \n";
	print(ls);
	std::cout<<"\nSecont ls:";
	std::cout<<"n_ls: \n";
	print(n_ls);
}

void f2()
{
	list ls = build<list>(SIZE_1);
	std::deque<data> dd;
	std::deque<data> n_dd;
	std::cout<<"ls: \n";
	print(ls);
	data d(51);

	pr('-');
	std::cout<<"Enter data for search:\n";
	std::cin>>d;

	find(ls, d);

	pr('-');
	std::cout<<"Replacing...\n";
	replace(ls, dd, d);
	std::cout<<"dd: \n";
	print(dd);	

	pr('-');
	std::cout<<"Sorting...\n";
	ls.sort();
	std::sort(dd.begin(), dd.end());

	std::cout<<"ls: \n";
	print(ls);
	std::cout<<"dd: \n";
	print(dd);

	pr('-');
	std::cout<<"Mixing ls and dd...\n";
	pr('-');
	replace(ls, dd, n_dd);

	std::cout<<"n_dd: \n";
	print(n_dd);

	std::cout<<"Enter data for count:\n";
	std::cin>>d;

	pr('-');
	std::cout<<"Counting\n";
	count(n_dd, d);
}

void main()
{
	srand(0);
	pr('*');
	f1();
	pr('*');
	pr('*');
	f2();
	pr('*');
	system("pause");
}