// https://blockdmask.tistory.com/79?category=249379

/*
	연관 컨테이너: set, multiset, map, multimap
	1) 노드 기반 컨테이너
	2) 균형 이진트리로 구성
*/

/*
	## set
	- key 값 중복 허용 하지 않음
	- 원소가 insert 로 삽입되면 자동 정렬된다 (default: less)
	- inorder traversal(중위순회)로 출력된다.

	[] indexing 을 쓰려면 unordered_set 을 사용하자!
	ex) unordered_s[3] ...
	
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

	// 중복 값 넣어보기
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);

	showAll(s, false);

	// 존재 여부
	set<int>::iterator iter = s.find(30);
	if (s.end() != iter) {
		cout << *iter << ": 존재" << endl;
	}
	else {
		cout << "존재하지 않음" << endl;
	}

	iter = s.find(11);
	if (s.end() != iter) {
		cout << *iter << ": 존재" << endl;
	}
	else {
		cout << "존재하지 않음" << endl;
	}
	
}