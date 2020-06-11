#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;

int c[7];
// 방문했는지를 표시함
// c[0]: 1번 노드를 방문했음을 나타냄

vector<int> a[8]; 
// 그래프의 연결 상태를 표시할 벡터 배열
// a[1]의 원소값들은 1과 연결된 노드 인덱스임

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);

		// 현재 큐에서 꺼낸 원소와 인접한 얘들을 전부 방문하면서
		for (int i = 0; i < a[x].size(); ++i)
		{
			// 인접한 노드를 방문한 상태가 아니라면 큐에 담는다
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

	bfs(1); // 시작점은 1이다!
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