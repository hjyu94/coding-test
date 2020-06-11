#include <string>
#include <vector>
#include <set>
using namespace std;

int solution_mine(vector<int> scoville, int K) 
{
	int answer = 0;

	multiset<int> set_scoville;
	for (int i = 0; i < scoville.size(); ++i)
	{
		set_scoville.insert(scoville[i]);
	}

	int count = 0;
	while (true)
	{
		auto iter = set_scoville.begin();
		int first = *iter;
		if (K <= first)
		{
			answer = count;
			break;
		}
		if (set_scoville.size() == 1)
		{
			answer = -1;
			break;
		}
		++iter;
		int second = *iter;

		auto firstIter = set_scoville.begin();
		auto secondIter = ++(++set_scoville.begin());
		set_scoville.erase(firstIter, secondIter);

		set_scoville.insert(first + second * 2);
		count++;
	}
	return answer;
}

#include <queue>
int solution_other(vector<int> scoville, int K) 
{
	int answer = 0;
	
	int needHot;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
	
	while (pq.top() < K)
	{
		if (pq.size() == 1) 
			return answer = -1;

		needHot = pq.top();
		pq.pop();

		pq.push(needHot + pq.top() * 2);
		pq.pop();

		answer++;
	}

	return answer;
}

void main() {
	vector<int> scovile 
		= { 1, 2, 3, 9, 10, 12 };
		//= { 0, 0, 0 };
	solution_other(scovile, 2);
}

/*
	�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. ��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

	���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
	Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
	Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���� ����
	scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
	K�� 0 �̻� 1,000,000,000 �����Դϴ�.
	scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
	��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.
	����� ��
	scoville	K	return
	[1, 2, 3, 9, 10, 12]	7	2
	����� �� ����
	���ں� ������ 1�� ���İ� 2�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
	���ο� ������ ���ں� ���� = 1 + (2 * 2) = 5
	���� ������ ���ں� ���� = [5, 3, 9, 10, 12]

	���ں� ������ 3�� ���İ� 5�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
	���ο� ������ ���ں� ���� = 3 + (5 * 2) = 13
	���� ������ ���ں� ���� = [13, 9, 10, 12]

	��� ������ ���ں� ������ 7 �̻��� �Ǿ��� �̶� ���� Ƚ���� 2ȸ�Դϴ�.
*/