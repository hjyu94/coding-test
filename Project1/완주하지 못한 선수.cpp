#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//1) ���� ���� �� ��
string solution1(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); ++i)
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}
	return answer;
}

// 2) multiset �� �����ڸ� ��� ��Ƴ��� �����ڵ��� �����
#include <unordered_set>
string solution2(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_multiset<string> names;

	for (int i = 0; i < participant.size(); ++i)
	{
		names.insert(participant[i]);
	}
	for (int i = 0; i < completion.size(); ++i)
	{
		unordered_multiset<string>::iterator iter = names.find(completion[i]);
		names.erase(iter);
	}

	answer = *names.begin();
	return answer;
}

void main()
{
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "mislav", "ana" };
	string sol = solution2(participant, completion);
}