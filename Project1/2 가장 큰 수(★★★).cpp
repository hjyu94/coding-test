/*
	0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

	���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

	0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, 
	������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���� ����
		numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
		numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
		������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
	
	����� ��
		numbers				return
		------------------------------
		[6, 10, 2]			6210
		[3, 30, 34, 5, 9]	9534330
*/


/*
	[���� Ǭ Ǯ��] -> �ð� �ʰ�
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PickByDfs(int depth, vector<int> numbers, vector<string>& pickNumsVec, vector<bool>& IsVisited, vector<int>& pickNums)
{
	if (depth == IsVisited.size()) {
		string ans = "";
		for (int num : pickNums)
		{
			ans = ans + to_string(num);
		}
		pickNumsVec.push_back(ans);
		return;
	}

	for (int i = 0; i <= IsVisited.size()-1; ++i)
	{
		if (!IsVisited[i])
		{
			IsVisited[i] = true;
			pickNums.push_back(numbers[i]);
			PickByDfs(depth + 1, numbers, pickNumsVec, IsVisited, pickNums);
			pickNums.pop_back();
			IsVisited[i] = false;
		}
	}
}


string solution(vector<int> numbers) {
	
	vector<string> pickNumsVec;
	
	vector<bool> IsVisited;
	vector<int> pickNums;
	for (int i = 0; i < numbers.size(); ++i)
	{
		IsVisited.push_back(false);
	}
	PickByDfs(0, numbers, pickNumsVec, IsVisited, pickNums);

	sort(pickNumsVec.begin(), pickNumsVec.end(), greater<string>());
	return pickNumsVec[0];
}

void main()
{

	cout << solution({ 3,30,34 }) << endl;
}
