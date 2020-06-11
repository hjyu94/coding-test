#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
	string answer = "";

	int q;
	int r;

	while (true)
	{
		q = n / 3;
		r = n % 3;
		if (r == 0)
		{
			answer = to_string(4) + answer;
			q--;
			n--;
		}
		else
		{
			answer = to_string(r) + answer;
		}
		if (q == 0) break;
		n /= 3;
	}

	return answer;
}

void main() {
	int input;
	while (true)
	{
		cout << "input: ";
		cin >> input;
		cout << "answer: " << solution(input) << endl << endl;
	}
}