#include "macro.h"

void DFS(int n, vector<int>& numbers, vector<int>& pickNums, int target, int& answer)
{
	if (n == numbers.size())
	{
		int sum = 0;
		for (int i = 0; i < pickNums.size(); ++i)
		{
			sum += pickNums[i];
		}
		if (sum == target)
		{
			++answer;
		}
		return;
	}
	pickNums.push_back(numbers[n]);
	DFS(n + 1, numbers, pickNums, target, answer);
	pickNums.pop_back();

	pickNums.push_back(-numbers[n]);
	DFS(n + 1, numbers, pickNums, target, answer);
	pickNums.pop_back();
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	vector<int> pickNums;
	DFS(0, numbers, pickNums, target, answer);
	return answer;
}

void main()
{
	vector<int> numbers = { 1,2,3 };
	int target = 3;
	vector<int> pickNums;
	int ans = solution(numbers, target);
	cout << ans << endl;
}
