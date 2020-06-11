/*
	���� ����
	n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. 
	���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

	-1+1+1+1+1 = 3
	+1-1+1+1+1 = 3
	+1+1-1+1+1 = 3
	+1+1+1-1+1 = 3
	+1+1+1+1-1 = 3

	����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� 
	���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
		�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
		�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
		Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.

	����� ��
		numbers				target	return
		[1, 1, 1, 1, 1]		3		5
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void ShuffleOperand(int depth, int count, vector<bool>& pickOperands, vector<vector<bool>>& shuffledOperands)
{
	if (depth == count)
	{
		vector<bool> ops;
		for (bool operand : pickOperands)
		{
			ops.push_back(operand);
		}
		shuffledOperands.push_back(ops);
		return;
	}

	for (int i = 0; i <= 1; ++i)
	{
		pickOperands.push_back(i);
		ShuffleOperand(depth + 1, count, pickOperands, shuffledOperands);
		pickOperands.pop_back();
	}
	
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	
	// true: +, false: -
	vector<vector<bool>> shuffledOperands;
	vector<bool> pickOperands;
	ShuffleOperand(0, numbers.size(), pickOperands, shuffledOperands);

	// compute ans
	vector<int> computes;
	for (int i = 0; i < shuffledOperands.size(); ++i)
	{
		int sum = 0;
		vector<bool> ops = shuffledOperands[i];
		for (int j = 0; j < numbers.size(); ++j)
		{
			if (1 == ops[j])
				sum += numbers[j];
			else
				sum -= numbers[j];
		}
		computes.push_back(sum);
	}
	
	// ���� ã��
	for (int i = 0; i < computes.size(); ++i)
	{
		if (computes[i] == target)
		{
			++answer;
		}
	}

	return answer;
}

void main()
{
	vector<int> numbers = { 1,1,1,1,1 };
	int target = 3;
	int ans = solution(numbers, target);
	cout << ans << endl;
}
