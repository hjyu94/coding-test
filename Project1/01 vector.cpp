#include <vector>
#include <iostream>
using namespace std;

// �迭 ���, sequence container

// ������
vector<int> v;
vector<int> v1(5); // �⺻�� 0 ���� �ʱ�ȭ �� ���� 5��
vector<int> v2(5, 2); // �⺻�� 2�� �ʱ�ȭ �� ���� 5��

// ���� ��� �Լ�
void vector_member_func() 
{
	v.assign(5, 2); // 2�� ������ 5���� ���� �Ҵ�
	
	v.at(0);
	v[0];

	v.front();
	v.back();
	
	v.clear();	// ���Ҵ� �����ϰ�, �޸𸮴� �����ִ�. 
				// size�� �ٰ� capacity�� �״��
	v.push_back(1);
	v.pop_back();

	v.reserve(6); // 6���� ���Ҹ� ������ ��ġ ����. �̸� �����Ҵ�
	v.resize(2); // ũ�⸦ 2�� ��ȯ
	v.resize(6, 3); // ũ�⸦ 6���� ��ȯ, �� Ŀ�� ��� 3���� �ʱ�ȭ

	v.size(); // ���� ���� ����
	v.capacity(); // �Ҵ�� ���� ũ�� ����

	v2.swap(v1); // ���ҿ� capacity swap
	vector<int>().swap(v1); // v1�� capacity�� ���ְ� ������ ���, �޸� ������

	vector<int>::iterator iter = v.end();
	v.erase(iter); // size�� �پ��� capacity(�Ҵ�� �޸�)�� ���´�!

	bool isEmpty = v.empty();
}

void vector_����_��ȸ()
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
	{
		cout << *iter << endl;
	}
}

/*
	size? ������ �� �ִ� ���� ����
	capacity? �Ҵ�� �޸� ũ��


	���� ����	capacity
			1	1
	---------------------
			2	2
	---------------------
			3	4
			4	4
	---------------------
			5	8
			6	8
			7	8
			8	8
	---------------------
			9	16
	...

	���� capacity�� 2��� ����
*/
