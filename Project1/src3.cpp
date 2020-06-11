#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int[2]> picks;
vector<string> unique_jems;

int GetDistance(vector<string>& gems, vector<string> gems_category, int front, int back)
{
	for (int i = front; i <= back; ++i)
	{
		for (int j = 0; j < gems_category.size(); ++j)
		{
			if (gems[i] == gems_category[j])
			{
				gems_category.erase(gems_category.begin() + j);
			}
		}
		if (gems_category.size() == 0)
		{
			return back - front;
		}
	}
	return 9999;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	// unique_gems
	for (int i = 0; i < gems.size(); i++)
	{
		unique_jems.push_back(gems[i]);
	}
	sort(unique_jems.begin(), unique_jems.end());
	auto last = unique(unique_jems.begin(), unique_jems.end());
	unique_jems.erase(last, unique_jems.end());

	int answerfront = -1;
	int answerback = -1;
	int minDistance = 99999;
	for (int front = gems.size()-1; front >= 0; --front)
	{
		for (int back = gems.size() - 1; back >= front; --back)
		{
			if (back-front + 1 < unique_jems.size()) continue;
			int distance = GetDistance(gems, unique_jems, front, back);
			if ( distance <= minDistance)
			{
				answerfront = front;
				answerback = back;
				minDistance = distance;
			}
		}
	}
	
	answer.push_back(answerfront + 1);
	answer.push_back(answerback + 1);
	return answer;
}

void main()
{
	vector<string> gems =
		{ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" }; // 2 6 -> 3 7
		//{"AA", "AB", "AC", "AA", "AC"}; // 0, 2 -> 1 3
		//{"XYZ", "XYZ", "XYZ"}; // 0,0 -> 1,1
		//{ "ZZZ", "YYY", "NNNN", "YYY", "BBB" }; // 1,5
	vector<int> ans = solution(gems); 
}