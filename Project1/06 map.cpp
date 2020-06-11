// https://blockdmask.tistory.com/87?category=249379

/*
	map:
		연관 컨테이너 중 하나
		노드 기반, 균형 이진 트리 구조
		key는 중복 불가능 -> multimap 에서 가능
		set과 마찬가지로 삽입 되면서 자동 정렬
*/

#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// 생성자, 연산자
map<string, int> m;
map<string, int> m1(less()); // 정렬 기준
map<string, int> m2(m1);
bool isSame = (m1 == m2); // ==, !=, <, >, ...

/* 
	[멤버 함수]

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
