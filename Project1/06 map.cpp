// https://blockdmask.tistory.com/87?category=249379

/*
	map:
		���� �����̳� �� �ϳ�
		��� ���, ���� ���� Ʈ�� ����
		key�� �ߺ� �Ұ��� -> multimap ���� ����
		set�� ���������� ���� �Ǹ鼭 �ڵ� ����
*/

#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// ������, ������
map<string, int> m;
map<string, int> m1(less()); // ���� ����
map<string, int> m2(m1);
bool isSame = (m1 == m2); // ==, !=, <, >, ...

/* 
	[��� �Լ�]

	begin(), end(), rbegin(), rend()
	
	clear()
	count(k)
	empty()
	
	insert(pair) insert(iter, pair)
	erase(start, end)
	
	find(k)
	upper_bound(k), lower_bound(k), equal_range(k)
	value_comp(), key_comp()
	
	size(), max_size()
*/

void temp()
{
	map<int, string> m;
	m.insert(pair<int, string>(40,"name40"));
	m.insert(pair<int, string>(35,"name35"));
	m.insert(pair<int, string>(10,"name10"));
	m.insert(pair<int, string>(90,"name90"));
	m.insert(pair<int, string>(65,"name65"));

	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << ", " << it->second << endl;
	}

	m[40] = "rename40";
}
