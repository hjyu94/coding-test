#include <iostream>
#include <vector>

using namespace std;

bool visit[5];
vector<int> v; // 1부터 4까지 원소를 담을 벡터

void Permutation(int depth)
{
	// 3개를 다 뽑았으면 return
	if (depth == 3) {
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= 4; ++i)
	{
		// 방문하지 않았으면 방문했다고 해주고 
		// 백트래킹으로 다시 방문 취소해주기
		// visit[2]:true ? 2를 방문한적이 있다. 2를 센 적이 있다.
 		if (!visit[i])
		{
			visit[i] = 1;
			v.push_back(i);

			Permutation(depth + 1);
			
			v.pop_back();
			visit[i] = 0;
		}
	}
}

void Combination(int depth, int start)
{
	if (depth == 3) {
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
		return;
	}
	
	for (int i = start; i <= 4; ++i)
	{
 		//if (!visit[i])
		//{
		//	visit[i] = 1;
			v.push_back(i);
			Combination(depth + 1, i + 1);
			v.pop_back();
		//	visit[i] = 0;
		//}
	}
}


// 1, 2 를 가지고 3자리 수를 모두 만들어라!
void test(int depth)
{
	if (depth == 3) {
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= 2; ++i)
	{
 		//if (!visit[i])
		//{
		//	visit[i] = 1;
			v.push_back(i);
			test(depth + 1);
			v.pop_back();
		//	visit[i] = 0;
		//}
	}
}

void main()
{
	//Permutation(0); // 1~4 개의 숫자중 3개를 뽑아보자
	//Combination(0, 1); // 1~4 중에서 3개를 뽑는 모든 경우를 출력해보자 
	test(0); // 1, 2 를 가지고 3자리 수를 모두 만들어라!
}