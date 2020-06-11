#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> PAIR;

struct CompareInput
{
	bool operator() (const vector<int>& a, const vector<int>& b)
	{
		if (a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] < b[0];
	};
};

struct MyCompare
{
	bool operator() (const PAIR& a, const PAIR& b)
	{
		if (a.second > b.second) return true;
		else return false;
	};
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int total = 0;

	sort(jobs.begin(), jobs.end(), CompareInput());
	priority_queue<PAIR, vector<PAIR>, MyCompare> pq;

	int cur = 0;
	int i = 0;
	bool isWorking = false;
	int complete = 0;
	PAIR job;
	while (true)
	{
		while (i< jobs.size())
		{
			if (cur == jobs[i][0])
				pq.push(PAIR(jobs[i][0], jobs[i][1]));
			else
				break;
			++i;
		}

		if (!isWorking && !pq.empty())
		{
			job = pq.top();
			total += cur - job.first;
			pq.pop();
			isWorking = true;
		}
		
		if(isWorking)
		{
			job.second--;
			total++;

			if (job.second == 0)
			{
				isWorking = false;
				complete++;
				if (complete == jobs.size()) break;
			}
		}
		
		cur++;
	}
	
	return total / jobs.size();
}



void main()
{
	vector<vector<int>> jobs
		//= { {0,3}, {1,9}, {2,6} }; // 9
		 = { {24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1} }; // 74
		//= { {24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1} }; // 74
	int answer = solution(jobs); 
	answer;
}

/*
	���� ����
	�ϵ��ũ�� �� ���� �ϳ��� �۾��� ������ �� �ֽ��ϴ�. ��ũ ��Ʈ�ѷ��� �����ϴ� ����� ���� ������ �ֽ��ϴ�. ���� �Ϲ����� ����� ��û�� ���� ������� ó���ϴ� ���Դϴ�.

	�������

	- 0ms ������ 3ms�� �ҿ�Ǵ� A�۾� ��û
	- 1ms ������ 9ms�� �ҿ�Ǵ� B�۾� ��û
	- 2ms ������ 6ms�� �ҿ�Ǵ� C�۾� ��û
	�� ���� ��û�� ���Խ��ϴ�. �̸� �׸����� ǥ���ϸ� �Ʒ��� �����ϴ�.
	Screen Shot 2018-09-13 at 6.34.58 PM.png

	�� ���� �ϳ��� ��û���� ������ �� �ֱ� ������ ������ �۾��� ��û���� ������� ó���ϸ� ������ ���� ó�� �˴ϴ�.
	Screen Shot 2018-09-13 at 6.38.52 PM.png

	- A: 3ms ������ �۾� �Ϸ� (��û���� ������� : 3ms)
	- B: 1ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 12ms ������ �۾� �Ϸ�(��û���� ������� : 11ms)
	- C: 2ms���� ����ϴٰ�, 12ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 16ms)
	�� �� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 10ms(= (3 + 11 + 16) / 3)�� �˴ϴ�.

	������ A �� C �� B ������� ó���ϸ�
	Screen Shot 2018-09-13 at 6.41.42 PM.png

	- A: 3ms ������ �۾� �Ϸ�(��û���� ������� : 3ms)
	- C: 2ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 9ms ������ �۾� �Ϸ�(��û���� ������� : 7ms)
	- B: 1ms���� ����ϴٰ�, 9ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 17ms)
	�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

	�� �۾��� ���� {�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�}�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

	���� ����
	jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
	jobs�� �� ���� �ϳ��� �۾��� ���� {�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�} �Դϴ�.
	�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
	�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
	�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
	����� ��
	jobs	return
	{{0, 3}, {1, 9}, {2, 6}}	9
	����� �� ����
	������ �־��� ���� �����ϴ�.

	0ms ������ 3ms �ɸ��� �۾� ��û�� ���ɴϴ�.
	1ms ������ 9ms �ɸ��� �۾� ��û�� ���ɴϴ�.
	2ms ������ 6ms �ɸ��� �۾� ��û�� ���ɴϴ�.



	{{24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1}} 74
    {{24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1}} 74
*/