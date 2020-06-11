#include <iostream>
#include <vector>

using namespace std;

bool visit[5];
vector<int> v; // 1���� 4���� ���Ҹ� ���� ����

void Permutation(int depth)
{
	// 3���� �� �̾����� return
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
		// �湮���� �ʾ����� �湮�ߴٰ� ���ְ� 
		// ��Ʈ��ŷ���� �ٽ� �湮 ������ֱ�
		// visit[2]:true ? 2�� �湮������ �ִ�. 2�� �� ���� �ִ�.
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


// 1, 2 �� ������ 3�ڸ� ���� ��� ������!
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
	//Permutation(0); // 1~4 ���� ������ 3���� �̾ƺ���
	//Combination(0, 1); // 1~4 �߿��� 3���� �̴� ��� ��츦 ����غ��� 
	test(0); // 1, 2 �� ������ 3�ڸ� ���� ��� ������!
}