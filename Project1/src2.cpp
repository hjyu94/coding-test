#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> ops;
vector<string> vec_operand;

int sum_nums(queue<int>& queue_num) {
	int sum = 0;
	while (!queue_num.empty())
	{
		int i = queue_num.front();
		queue_num.pop();
		sum += i * pow(10, queue_num.size());
	}
	return sum;
}

vector<bool> visit; 
vector<string> v; 
vector<long long> sums;

long long computeSum(vector<string> vec_operand, vector<string> quiz)
{
	long long sum = 0;

	queue<string> queue_operand;
	for (int i = 0; i < vec_operand.size(); ++i)
	{
		queue_operand.push(vec_operand[i]);
	}

	while (!queue_operand.empty())
	{
		string operand = queue_operand.front();
		for (int i = 1; i < quiz.size(); i = i+2)
		{
			if (quiz[i] == operand)
			{
				long long num1 = atoi(quiz[i-1].c_str());
				long long num2 = atoi(quiz[i+1].c_str());
				char op = *operand.c_str();
				if ('+' == op)
				{
					quiz[i-1] = to_string(num1 + num2);
				}
				else if ('-' == op)
				{
					quiz[i-1] = to_string(num1 - num2);
				}
				else if ('*' == op)
				{
					quiz[i-1] = to_string(num1 * num2);
				}
				quiz.erase(quiz.begin() + i);
				quiz.erase(quiz.begin() + i);
				i -= 2;
			}
		}
		queue_operand.pop();
	}

	return abs(atoll(quiz.front().c_str()));
}

void Permutation(int depth, vector<string>& vec_operand) // 0, {-,+,*}
{
	if (depth == vec_operand.size()) {
		long long sum = computeSum(v, ops);
		sums.push_back(sum);
	}

	for (int i = 0; i < vec_operand.size(); ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			v.push_back(vec_operand[i]);
			Permutation(depth + 1, vec_operand);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

long long solution(string expression) {
	long long answer = 0;
	
	// ����, ������ push
	queue<int> temp_num;
	for (int i = 0; i < expression.size(); ++i)
	{
		char ch = expression[i];
		bool is = isdigit(ch);

		if (i == expression.size() - 1)
		{
			int num = atoi(&ch);
			temp_num.push(num);
			int operand = sum_nums(temp_num);
			ops.push_back(to_string(operand));
		}
		else if (isdigit(ch) && i < expression.size() - 1)
		{
			int num = atoi(&ch);
			temp_num.push(num);
		}
		else
		{
			int operand = sum_nums(temp_num);
			ops.push_back(to_string(operand));
			ops.push_back(expression.substr(i,1));
		}
	}
	
	// �����ڸ� ���� �̾Ƽ� �ߺ����� �ϱ�
	for (int i = 1; i < ops.size(); i = i+2)
	{
		vec_operand.push_back(ops[i]);
	}
	sort(vec_operand.begin(), vec_operand.end());
	auto last = unique(vec_operand.begin(), vec_operand.end());
	vec_operand.erase(last, vec_operand.end());

	// ������ �����ؼ� answer �ĺ����� sums�� �߰�
	for (int i = 0; i < vec_operand.size(); ++i)
	{
		visit.push_back(0);
	}
	Permutation(0, vec_operand);

	// sums ���� max ã��
	return *max_element(sums.begin(), sums.end());
}

void main()
{
	string expression
		//= "50*6-3*2"; // 300
		= "100-200*300-500+20"; // 60420
	long long answer = solution(expression);
	printf("%d ", answer);
}

/*
�׽�Ʈ 1 ��	��� (0.04ms, 4.03MB)
�׽�Ʈ 2 ��	��� (0.03ms, 4.09MB)
�׽�Ʈ 3 ��	��� (0.05ms, 4.1MB)
�׽�Ʈ 4 ��	��� (0.06ms, 4.14MB)
�׽�Ʈ 5 ��	��� (0.06ms, 3.98MB)
�׽�Ʈ 6 ��	��� (0.07ms, 4.14MB)
�׽�Ʈ 7 ��	��� (0.06ms, 4.04MB)
�׽�Ʈ 8 ��	��� (0.06ms, 3.99MB)
�׽�Ʈ 9 ��	��� (0.09ms, 4.03MB)
�׽�Ʈ 10 ��	��� (0.09ms, 4.13MB)
�׽�Ʈ 11 ��	��� (0.11ms, 4.05MB)
�׽�Ʈ 12 ��	��� (0.08ms, 4.14MB)
�׽�Ʈ 13 ��	��� (0.08ms, 4.02MB)
�׽�Ʈ 14 ��	��� (0.09ms, 4.03MB)
�׽�Ʈ 15 ��	��� (0.10ms, 4.04MB)
�׽�Ʈ 16 ��	��� (0.04ms, 3.97MB)
�׽�Ʈ 17 ��	��� (0.05ms, 3.98MB)
�׽�Ʈ 18 ��	��� (0.03ms, 4.02MB)
�׽�Ʈ 19 ��	��� (0.05ms, 4.09MB)
�׽�Ʈ 20 ��	��� (0.03ms, 4.04MB)
�׽�Ʈ 21 ��	��� (0.05ms, 4.16MB)
�׽�Ʈ 22 ��	��� (0.07ms, 4.05MB)
�׽�Ʈ 23 ��	��� (0.04ms, 4.12MB)
�׽�Ʈ 24 ��	��� (0.13ms, 4.15MB)
�׽�Ʈ 25 ��	��� (0.11ms, 4.04MB)
�׽�Ʈ 26 ��	��� (0.04ms, 4.12MB)
�׽�Ʈ 27 ��	���� (0.15ms, 4.02MB)
�׽�Ʈ 28 ��	���� (0.09ms, 4.04MB)
�׽�Ʈ 29 ��	���� (0.09ms, 4.16MB)
�׽�Ʈ 30 ��	��� (0.06ms, 4.04MB)
*/