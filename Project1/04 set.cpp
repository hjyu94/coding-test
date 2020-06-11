// https://blockdmask.tistory.com/79?category=249379

/*
	���� �����̳�: set, multiset, map, multimap
	1) ��� ��� �����̳�
	2) ���� ����Ʈ���� ����
*/

/*
	## set
	- key �� �ߺ� ��� ���� ����
	- ���Ұ� insert �� ���ԵǸ� �ڵ� ���ĵȴ� (default: less)
	- inorder traversal(������ȸ)�� ��µȴ�.

	[] indexing �� ������ unordered_set �� �������!
	ex) unordered_s[3] ...
	
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
*/

#include <iostream>
#include <set>
using namespace std;

void showAll(set<int>& s, bool isAsc)
{
	if (isAsc) {
		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); ++iter)
		{
			cout << *iter << " ";
		}
	}

	else {
		set<int>::reverse_iterator iter;
		for (iter = s.rbegin(); iter != s.rend(); ++iter)
		{
			cout << *iter << " ";
		}
	}
	cout << endl;
}

void main(void) {
	set<int> s;
	
	s.insert(40);
	s.insert(20);
	s.insert(70);
	s.insert(10);
	s.insert(50);
	s.insert(90);
	s.insert(30);
	
	showAll(s, true);

	// �ߺ� �� �־��
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);

	showAll(s, false);

	// ���� ����
	set<int>::iterator iter = s.find(30);
	if (s.end() != iter) {
		cout << *iter << ": ����" << endl;
	}
	else {
		cout << "�������� ����" << endl;
	}

	iter = s.find(11);
	if (s.end() != iter) {
		cout << *iter << ": ����" << endl;
	}
	else {
		cout << "�������� ����" << endl;
	}
	
}