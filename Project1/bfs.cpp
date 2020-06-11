#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;

int c[7];
// �湮�ߴ����� ǥ����
// c[0]: 1�� ��带 �湮������ ��Ÿ��

vector<int> a[8]; 
// �׷����� ���� ���¸� ǥ���� ���� �迭
// a[1]�� ���Ұ����� 1�� ����� ��� �ε�����

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);

		// ���� ť���� ���� ���ҿ� ������ ����� ���� �湮�ϸ鼭
		for (int i = 0; i < a[x].size(); ++i)
		{
			// ������ ��带 �湮�� ���°� �ƴ϶�� ť�� ��´�
			int y = a[x][i];
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

void execute(int ex_num)
{
	// (1,2), (1,3), (2,3), (2,4), (2,5), (3,6), (3,7), (4,5), (6,7)
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1); // �������� 1�̴�!
}

void main() {
	int ex_num;
	while (true)
	{
		cout << "ex: ";
		cin >> ex_num;
		execute(ex_num);
		
		for (int i = 0; i <= 8; ++i)
		{
			a[i].clear();
			if (i != 8) {
				c[i] = false;
			}
		}
		cout << endl;
	}
}