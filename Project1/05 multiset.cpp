// https://blockdmask.tistory.com/79?category=249379

/*
	���� �����̳�: set, multiset, map, multimap
	1) ��� ��� �����̳�
	2) ���� ����Ʈ���� ����
*/

/*
	## multiset
	- key �� �ߺ� ��� !!

	set<int> s;

	set<int> s2(s1); s2.swap(s1);
	s(pred); // pred�� ���� ���ı����� �����
	s.begin(); s.end(); s.rbegin(); s.rend();
	s.clear(); s.count(k); s.empty();
	s.insert(k); s.insert(iter,k);
	s.erase(iter); s.erase(start, end);
	s.find(k);
	s.upper_bound(k); s.lower_bound(k); s.equal_range(k);
	s.value_comp(0; s.key_comp(); // ���� ������ ��ȯ
	s.size(); s.max_size(); (���� ������ ��ȯ)

	set�� �ٸ� ��?
	s.insert(k) -> pair ��ü�� ���ϵ�
	ms.insert(k) -> ������ ���� k�� ��ġ�� ����Ű�� �ݺ��ڰ� ���ϵ�
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