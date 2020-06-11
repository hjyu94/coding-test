/*
	문제 설명
	n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 
	예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

	-1+1+1+1+1 = 3
	+1-1+1+1+1 = 3
	+1+1-1+1+1 = 3
	+1+1+1-1+1 = 3
	+1+1+1+1-1 = 3

	사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 
	숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

	제한사항
		주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
		각 숫자는 1 이상 50 이하인 자연수입니다.
		타겟 넘버는 1 이상 1000 이하인 자연수입니다.

	입출력 예
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
	
	// 갯수 찾기
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
