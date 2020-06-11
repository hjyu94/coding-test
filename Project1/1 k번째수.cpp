/*
	�迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�.

	���� ��� array�� [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��

	array�� 2��°���� 5��°���� �ڸ��� [5, 2, 6, 3]�Դϴ�.
	1���� ���� �迭�� �����ϸ� [2, 3, 5, 6]�Դϴ�.
	2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�
	.
	�迭 array, [i, j, k]�� ���ҷ� ���� 2���� �迭 commands�� �Ű������� �־��� ��, 
	commands�� ��� ���ҿ� ���� �ռ� ������ ������ �������� �� ���� ����� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
		array�� ���̴� 1 �̻� 100 �����Դϴ�.
		array�� �� ���Ҵ� 1 �̻� 100 �����Դϴ�.
		commands�� ���̴� 1 �̻� 50 �����Դϴ�.
		commands�� �� ���Ҵ� ���̰� 3�Դϴ�.

	����� ��
		array		[1, 5, 2, 6, 3, 7, 4]	
		commands	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]
		return		[5, 6, 3]
*/

#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); ++i)
	{
		int cut_front = commands[i][0];
		int cut_back = commands[i][1];
		int index_ans = commands[i][2];
		
		multiset<int> cut_array;
		for (int j = cut_front - 1; j < cut_back; ++j)
		{
			cut_array.insert(array[j]);
		}

		multiset<int>::iterator iter;
		int count = 0;
		for (iter = cut_array.begin(); iter != cut_array.end(); ++iter)
		{
			++count;
			if (count == index_ans) 
			{
				answer.push_back(*iter);
				break;
			}
		}
	}
	return answer;
}

void main()
{
	vector<int> array 
		= { 1,1,1,15,2,6,3,7,4 };
		//= {10, 1, 3, 21, 5, 6, 9};
	vector<vector<int>> commands 
		= { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> ans = solution(array, commands);
	for (int num : ans)
	{
		cout << num << endl;
	}
}