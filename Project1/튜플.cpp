#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	
	vector<int> nums;

	queue<int> num;
	int i_num = 0;

	for (int i = 1; i < s.size()-1; ++i)
	{
		char ch = s.at(i);
		if (isdigit(ch))
		{
			num.push(atoi(&ch));
		}
		else if (ch == ',' || ch == '}')
		{
			for (int j = num.size()-1; j >= 0; --j)
			{
				i_num += num.front() * pow(10, j);
				num.pop();
			}
			if (0 != i_num)
			{
				nums.push_back(i_num);
				i_num = 0;
			}
		}
	}

	
	int count[500] = {0,};
	
	for (int num : nums)
	{
		count[num]++;
	}

	
	for(int target = 500; target>=1; --target)
	{
		for (int i = 0; i < 500; ++i)
		{
			if (count[i] == target)
			{
				answer.push_back(i);
				break;
			}
		}
	}
	
	for (int num : answer)
	{
		printf("%d, ", num);
	}
	return answer;
}

void main() {
	solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
}