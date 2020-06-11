// https://blockdmask.tistory.com/79?category=249379

/*
	연관 컨테이너: set, multiset, map, multimap
	1) 노드 기반 컨테이너
	2) 균형 이진트리로 구성
*/

/*
	## multiset
	- key 값 중복 허용 !!

	set<int> s;

	set<int> s2(s1); s2.swap(s1);
	s(pred); // pred를 통해 정렬기준을 세운다
	s.begin(); s.end(); s.rbegin(); s.rend();
	s.clear(); s.count(k); s.empty();
	s.insert(k); s.insert(iter,k);
	s.erase(iter); s.erase(start, end);
	s.find(k);
	s.upper_bound(k); s.lower_bound(k); s.equal_range(k);
	s.value_comp(0; s.key_comp(); // 정렬 조건자 반환
	s.size(); s.max_size(); (남은 사이즈 반환)

	set과 다른 점?
	s.insert(k) -> pair 객체가 리턴됨
	ms.insert(k) -> 삽입한 원소 k의 위치를 가리키는 반복자가 리턴됨
*/

#include <set>
#include <iostream>
using namespace std;

void main()
{
	multiset<int> ms;

	ms.insert(9);
	ms.insert(13);
	ms.insert(5);
	ms.insert(7);
	ms.insert(3);
	ms.insert(1);
	ms.insert(11);
	ms.insert(15);
	ms.insert(11);
	ms.insert(11);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	// lower_bound(), upper_bound()
	multiset<int>::iterator start, end;
	start = ms.lower_bound(11);
	end = ms.upper_bound(11);
	for (iter = start; iter != end; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	// equal_range()
	pair <multiset<int>::iterator, multiset<int>::iterator> equal_pair = ms.equal_range(11);
	for (iter = equal_pair.first; iter != equal_pair.second; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

}