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
	
	// 숫자, 연산자 push
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
	
	// 연산자만 따로 뽑아서 중복제거 하기
	for (int i = 1; i < ops.size(); i = i+2)
	{
		vec_operand.push_back(ops[i]);
	}
	sort(vec_operand.begin(), vec_operand.end());
	auto last = unique(vec_operand.begin(), vec_operand.end());
	vec_operand.erase(last, vec_operand.end());

	// 연산자 조합해서 answer 후보들을 sums에 추가
	for (int i = 0; i < vec_operand.size(); ++i)
	{
		visit.push_back(0);
	}
	Permutation(0, vec_operand);

	// sums 에서 max 찾기
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
테스트 1 〉	통과 (0.04ms, 4.03MB)
테스트 2 〉	통과 (0.03ms, 4.09MB)
테스트 3 〉	통과 (0.05ms, 4.1MB)
테스트 4 〉	통과 (0.06ms, 4.14MB)
테스트 5 〉	통과 (0.06ms, 3.98MB)
테스트 6 〉	통과 (0.07ms, 4.14MB)
테스트 7 〉	통과 (0.06ms, 4.04MB)
테스트 8 〉	통과 (0.06ms, 3.99MB)
테스트 9 〉	통과 (0.09ms, 4.03MB)
테스트 10 〉	통과 (0.09ms, 4.13MB)
테스트 11 〉	통과 (0.11ms, 4.05MB)
테스트 12 〉	통과 (0.08ms, 4.14MB)
테스트 13 〉	통과 (0.08ms, 4.02MB)
테스트 14 〉	통과 (0.09ms, 4.03MB)
테스트 15 〉	통과 (0.10ms, 4.04MB)
테스트 16 〉	통과 (0.04ms, 3.97MB)
테스트 17 〉	통과 (0.05ms, 3.98MB)
테스트 18 〉	통과 (0.03ms, 4.02MB)
테스트 19 〉	통과 (0.05ms, 4.09MB)
테스트 20 〉	통과 (0.03ms, 4.04MB)
테스트 21 〉	통과 (0.05ms, 4.16MB)
테스트 22 〉	통과 (0.07ms, 4.05MB)
테스트 23 〉	통과 (0.04ms, 4.12MB)
테스트 24 〉	통과 (0.13ms, 4.15MB)
테스트 25 〉	통과 (0.11ms, 4.04MB)
테스트 26 〉	통과 (0.04ms, 4.12MB)
테스트 27 〉	실패 (0.15ms, 4.02MB)
테스트 28 〉	실패 (0.09ms, 4.04MB)
테스트 29 〉	실패 (0.09ms, 4.16MB)
테스트 30 〉	통과 (0.06ms, 4.04MB)
*/