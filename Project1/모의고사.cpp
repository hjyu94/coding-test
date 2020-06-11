#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) 
{
	vector<int> answer;
	vector<int> correct_count(3);
	vector<vector<int>> supoja = { {1,2,3,4,5}, { 2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
	for (int i = 0; i < answers.size(); ++i)
	{
		int answer = answers[i];
		for (int j = 0; j < 3; ++j)
		{
			int patternIdx = i % supoja[j].size();
			int choice = supoja[j][patternIdx];
			if (answer == choice)
			{
				correct_count[j]++;
			}
		}
	}
	int max_count = *max_element(correct_count.begin(), correct_count.end());
	for (int i = 0; i < 3; ++i)
	{
		if (correct_count[i] == max_count)
		{
			answer.push_back(i+1);
		}
	}
	return answer;
}

void main()
{
	vector<int> answers 
		= { 1,2,3,4,5 };
		// = { 1,3,2,4,2 };
	vector<int> answer = solution(answers);
	answer;
}

/*
	�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

	1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
	2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
	3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

	1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���� ����
	������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
	������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
	���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.
	����� ��
	answers	return
	[1,2,3,4,5]	[1]
	[1,3,2,4,2]	[1,2,3]
	����� �� ����
	����� �� #1

	������ 1�� ��� ������ �������ϴ�.
	������ 2�� ��� ������ Ʋ�Ƚ��ϴ�.
	������ 3�� ��� ������ Ʋ�Ƚ��ϴ�.
	���� ���� ������ ���� ���� ����� ������ 1�Դϴ�.

	����� �� #2

	��� ����� 2�������� ������ϴ�.
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1,2,3,4,5 };
vector<int> two = { 2,1,2,3,2,4,2,5 };
vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution_other(vector<int> answers) {
	vector<int> answer;
	vector<int> they(3);
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == one[i % one.size()]) they[0]++;
		if (answers[i] == two[i % two.size()]) they[1]++;
		if (answers[i] == thr[i % thr.size()]) they[2]++;
	}
	int they_max = *max_element(they.begin(), they.end());
	for (int i = 0; i < 3; i++) {
		if (they[i] == they_max) answer.push_back(i + 1);
	}
	return answer;
}