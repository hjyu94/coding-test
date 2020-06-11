#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void DFS(int n, vector<int>& numbers, vector<int>& pickNums, vector<int>& sums)
{
	if (n == numbers.size())
	{
		int sum = 0;
		for (int i = 0; i < pickNums.size(); ++i)
		{
			sum += pickNums[i];
		}
		sums.push_back(sum);
		return;
	}
	pickNums.push_back(numbers[n]);
	DFS(n + 1, numbers, pickNums, sums);
	pickNums.pop_back();

	pickNums.push_back(0);
	DFS(n + 1, numbers, pickNums, sums);
	pickNums.pop_back();
}

int solution(int n) {
	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		numbers.push_back(pow(3, i));
	}
	vector<int> pickNums;
	vector<int> sums;
	DFS(0, numbers, pickNums, sums);
	sort(sums.begin(), sums.end());
	
	return sums[n];
}

void main()
{
	solution(4); // 9
}