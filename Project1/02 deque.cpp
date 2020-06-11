#include <iostream>
#include <deque>
using namespace std;

/*
	- vector�� ������ �����Ѵ�
	
	vector�� �� ���Ұ� �߰� �� �� �޸� ���Ҵ� �� ���� ���ҷ� �����ϱ� ������
	���Խÿ� ������ ���ϵǴ� ������ �ִ�.

	deque�� �� ������ �����ϱ� ���� �������� �޸� ����� �Ҵ��ϰ�
	�ϳ��� ���ó�� ����� ����� ����
	

	- vector�� ���������� �迭 ���
*/


// ������, ������
deque<int> dq;
deque<int> dq1(10);
deque<int> dq2(10, 4);
deque<int> dq2(dq1);
bool isSame = dq1 == dq2; // ==, !=, <, >, <=, >=


// ��� �Լ�
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

	dq.resize(99); // ũ�Ⱑ Ŀ���� ��� ���Ҹ� default 0 ���� �ʱ�ȭ
	dq.resize(100, 2); // ũ�Ⱑ Ŀ���� ��� ���Ҹ� 2�� �ʱ�ȭ
	dq.size();

	dq2.swap(dq1);
}


void dequeu_�߰�_����() 
{
	deque<int>::iterator iter = dq.begin();
	iter += 2;
	dq.insert(iter, 4); // 3��° ��ġ�� ���� 4�� ����
	dq.erase(dq.end());
}


void deque_����_��ȸ() 
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