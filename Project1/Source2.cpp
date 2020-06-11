#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Stick { 
public:
	int v1; 
	int v2; 

	Stick(int v1, int v2) {
		this->v1 = v1;
		this->v2 = v2;
	}
};

int solution(string arrangement) {
	int answer = 0;
	
	int len = arrangement.size();
	vector<char> argm;
	for (int i = 0; i < len; ++i)
	{
		argm.push_back(arrangement[i]);
	}

	vector<int> lazers;
	vector<Stick> sticks;
	stack<int> vertex;

	for (int i = 0; i < len-1; ++i)
	{
		char ch = argm[i];
		char next = argm[i + 1];
		if (ch == '(' && next == ')')
		{
			lazers.push_back(i);
			++i;
		}
		else
		{
			if (ch == ')')
			{
				Stick stick(vertex.top(), i);
				sticks.push_back(stick);

				vertex.pop();
			}
			else
			{
				vertex.push(i);
			}
		}
	}

	Stick stick(vertex.top(), argm.size()-1);
	sticks.push_back(stick);

	for (Stick stick : sticks) {
		int cut_count = 0;
		for (int i = 0; i < lazers.size(); ++i)
		{
			if (stick.v1 < lazers[i] && lazers[i] < stick.v2)
			{
				cut_count++;
			}
		}
		answer += cut_count + 1;
	}

	return answer;
}

void main() {
	//int answer = solution("()(((()())(())()))(())"); //17
	int answer = solution("((()))"); //6
}