#include <string>
#include <vector>
#include <set>
using namespace std;

void Dfs(int depth, int lastDepth, vector<bool>& isImportDay, vector<vector<bool>>& choices)
{
	if (depth == lastDepth)
	{
		choices.push_back(isImportDay);
		return;
	}

	isImportDay.push_back(true);
	Dfs(depth+1, lastDepth, isImportDay, choices);
	isImportDay.pop_back();

	isImportDay.push_back(false);
	Dfs(depth+1, lastDepth, isImportDay, choices);
	isImportDay.pop_back();
}

int solution_1(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	vector<bool> isImportDay; // false, false, false
	vector<vector<bool>> choices;
	Dfs(0, dates.size(), isImportDay, choices);

	set<int> answers;
	for (int i = 0; i < choices.size(); ++i)
	{
		vector<bool>& isImportDay = choices[i];
		int count = 0;
		int remain = stock;
		for (int j = 0; j < isImportDay.size(); ++j)
		{
			if (j == 0)
				remain -= dates[j];
			else
				remain -= (dates[j] - dates[j - 1]);

			if (isImportDay[j])
			{
				remain += supplies[j];
				count++;
			}
			if (remain < 0)
			{
				break;
			}
		}
		remain -= (k - dates.back());
		if (remain < 0)
			continue;
		answers.insert(count);
	}
	return *answers.begin();
}

// �ð��ʰ� �ФФФФФФФФФФФФ�


/************************************************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

// ���Թ��� �� �ִ� ���޷� �� ���� ū ���� ����
int solution_2(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>> que;
	int i = 0;
	for (int day = 0; day != k; day++) {
		if (i < dates.size() && dates[i] == day) {
			que.push(supplies[i]);
			i++;
		}
		if (!stock) {
			stock += que.top();
			que.pop();
			answer++;
		}
		stock--;
	}
	return answer;
}

void main() {
	int stock = 4;
	vector<int> dates = { 4, 10, 15 };
	vector<int> supplies = { 20, 5, 10 };
	int k = 30;

	solution_2(stock, dates, supplies, k); // 2
}
/*

	��� ���忡���� �Ϸ翡 �а��縦 1�澿 ����մϴ�. ���� �а��縦 ���޹޴� ������ �������� ������ k�� ���Ŀ��� �а��縦 ���޹��� �� �ֱ� ������ �ؿ� ���忡�� �а��縦 �����ؾ� �մϴ�.

	�ؿ� ���忡���� ���� �а��縦 ������ �� �ִ� ��¥�� ������ �˷��־���, ��� ���忡���� ��ۺ� ���̱� ���� �ּ����� Ƚ���� �а��縦 ���޹ް� �ͽ��ϴ�.

	���� ���忡 �����ִ� �а��� ���� stock, �а��� ���� ����(dates)�� �ش� ������ ���� ������ �а��� ����(supplies), ���� �������κ��� ���޹��� �� �ִ� ���� k�� �־��� ��, �а��簡 �������� �ʰ� ������ ��ϱ� ���ؼ� �ּ��� �� �� �ؿ� �������κ��� �а��縦 ���޹޾ƾ� �ϴ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

	dates[i]���� i��° ���� �������� ���������, supplies[i]���� dates[i] ��¥�� ���� ������ �а��� ������ ��� �ֽ��ϴ�.

	���ѻ���
	stock�� �ִ� �а���� ����(0�� ����)���� ���˴ϴ�.
	stock�� k�� 2 �̻� 100,000 �����Դϴ�.
	dates�� �� ���Ҵ� 1 �̻� k �����Դϴ�.
	supplies�� �� ���Ҵ� 1 �̻� 1,000 �����Դϴ�.
	dates�� supplies�� ���̴� 1 �̻� 20,000 �����Դϴ�.
	k�� °���� �а��簡 ����� ���޵Ǳ� ������ k-1�Ͽ� ����� ���������� Ȯ���ϸ� �˴ϴ�.
	dates�� ����ִ� ��¥�� �������� ���ĵǾ� �ֽ��ϴ�.
	dates�� ����ִ� ��¥�� ���޵Ǵ� �а���� �۾� ���� �� ������ ���޵Ǵ� ���� �������� �մϴ�. ���� ��� 9��°�� �а��簡 �ٴڳ�����, 10��°�� ���޹����� 10��°���� ������ ��� �� �ֽ��ϴ�.
	�а��簡 �ٴڳ��� ���� �־����� �ʽ��ϴ�.
	����� ��
	stock	dates	supplies	k	result
	4	[4,10,15]	[20,5,10]	30	2
	����� �� ����
	���� �а��簡 4�� ���� �ֱ� ������ ���ð� 1�� ��~3�� �ı��� ����ϰ� ���� ��� �а��縦 �� ����մϴ�. ���� 4�� �Ŀ��� �ݵ�� �а��縦 ���޹޾ƾ� �մϴ�.
	4��° ���޹ް� ���� 15�� ���� ��ħ���� 9���� �а��簡 �����ְ� �ǰ�, �̶� 10���� �� ���޹����� 19���� �����ְ� �˴ϴ�. 15�� ���ĺ��� 29�� ���ı��� �ʿ��� �а���� 15���̹Ƿ� �� �̻��� ������ �ʿ� �����ϴ�.
	���� �� 2ȸ�� �а��縦 ���޹����� �˴ϴ�.

*/