
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(const string& a, const string& b)
{
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> strings;

	for (int i : numbers)
		strings.push_back(to_string(i));

	sort(strings.begin(), strings.end(), compare);

	for (auto iter = strings.begin(); iter < strings.end(); ++iter)
		answer += *iter;

	if (answer[0] == '0')
		answer = "0";

	return answer;
}

void main()
{
	// cout << solution({ 3,30,34 }) << endl;
	cout << solution({ 0, 0 }) << endl;
}