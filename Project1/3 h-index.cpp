#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int h = citations.size(); h >= 0; --h)
	{
		int minIdx = citations.size() - h;
		if (h == 0) return 0;
 		if (citations[minIdx] >= h)
		{
			return h;
		}
	}
	return answer;
}

void main() {
	vector<int> citiations
		//= { 3,0,6,1,5 };
		= { 0 };
		//= { 3, 3 };
	int answer = solution(citiations);
	answer;
}
/*
	���� ����
	H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

	� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

	� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
	���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
	����� ��
	citations	return
	[3, 0, 6, 1, 5]	3
	����� �� ����
	�� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

	�� ���� - 2019�� 2�� 28�� �׽�Ʈ ���̽��� �߰��Ǿ����ϴ�.
*/