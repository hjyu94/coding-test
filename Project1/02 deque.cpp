#include <iostream>
#include <deque>
using namespace std;

/*
	- vector의 단점을 보완한다
	
	vector는 새 원소가 추가 될 때 메모리 재할당 후 이전 원소롤 복사하기 때문에
	삽입시에 성능이 저하되는 단점이 있다.

	deque는 이 단점을 보완하기 위해 여러개의 메모리 블록을 할당하고
	하나의 블록처럼 여기는 기능을 제공
	

	- vector와 마찬가지로 배열 기반
*/


// 생성자, 연산자
deque<int> dq;
deque<int> dq1(10);
deque<int> dq2(10, 4);
deque<int> dq2(dq1);
bool isSame = dq1 == dq2; // ==, !=, <, >, <=, >=


// 멤버 함수
void deque_member_func() {
	dq.assign(4, 3);

	dq.at(2);
	dq[2];

	dq.front();
	dq.back();
	dq.clear();

	dq.push_front(0);
	dq.push_back(9);
	dq.pop_front();
	dq.pop_back();

	dq.resize(99); // 크기가 커지는 경우 원소를 default 0 으로 초기화
	dq.resize(100, 2); // 크기가 커지는 경우 원소를 2로 초기화
	dq.size();

	dq2.swap(dq1);
}


void dequeu_중간_삽입() 
{
	deque<int>::iterator iter = dq.begin();
	iter += 2;
	dq.insert(iter, 4); // 3번째 위치에 원소 4를 삽입
	dq.erase(dq.end());
}


void deque_원소_순회() 
{
	deque<int> dq;
	for (int i = 0; i < 5; ++i)
	{
		dq.push_back(i);
	}

	for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
	{
		cout << *it << endl;
	}
	
	dq.clear();
	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(99);
	dq.push_back(100);

	for (int i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << endl;
	}
	for (deque<int>::reverse_iterator it = dq.rbegin(); it != dq.rend(); ++it)
	{
		cout << *it << endl;
	}
}

// https://blockdmask.tistory.com/73?category=249379