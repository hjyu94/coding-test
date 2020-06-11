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

int total;

void DFS(vector<int>& numbers, int& target, int sum, int n) {
	if (n >= numbers.size()) {
		if (sum == target) total++;
		return;
	}

	DFS(numbers, target, sum + numbers[n], n + 1);
	DFS(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	DFS(numbers, target, numbers[0], 1);
	DFS(numbers, target, -numbers[0], 1);

	answer = total;

	return answer;
}

void main()
{
	vector<int> numbers = { 1,2,3,4,5 };
	int target = 3;
	int ans = solution(numbers, target);
	cout << ans << endl;
}
