#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (int i = 0; i < phone_book.size(); ++i)
	{
		for (int j = 0; j < phone_book.size(); ++j)
		{
			if (i == j)
				continue;

			int strlen = phone_book[i].length();
			string prefix = phone_book[j].substr(0, strlen);
			if (phone_book[i] == prefix)
			{
				return false;
			}
		}
	}

	return answer;
}

void main()
{
	vector<string> phone_book
		= { "119", "97674223", "1195524421"}; // false
		//= { "124", "456","789" }; // true
		//= { "12", "123", "1235", "567", "88" }; // false
	cout << solution(phone_book) << endl;
}
/*
	��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
	��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

	������ : 119
	���ؿ� : 97 674 223
	������ : 11 9552 4421
	��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���� ����
	phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
	�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
*/