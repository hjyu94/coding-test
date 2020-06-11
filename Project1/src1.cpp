#include <string>
#include <vector>

using namespace std;
class Finger {
public:
	Finger(int row, int col) {
		this->row = row;
		this->col = col;
	}
	int row;
	int col;
};

Finger left_finger(3, 0);
Finger right_finger(3, 2);

bool isNearLeftHand(int num, int& row, int& col, string hand)
{
	if (num == -1)
	{
		row = 3;
		col = 1;
	}
	else
	{
		row = num / 3;
		col = num % 3;
	}
	
	int distance_left = abs(row - left_finger.row) + abs(col - left_finger.col);
	int distance_right = abs(row - right_finger.row) + abs(col - right_finger.col);
	if (distance_left < distance_right)
	{
		return true;
	}
	else if (distance_left > distance_right)
	{
		return false;
	}
	else
	{
		if (hand == "left")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void click_middle_num(int num, string& answer, string hand)
{
	int row, col;
	if (isNearLeftHand(num, row, col, hand))
	{
		answer += "L";
		left_finger.row = row;
		left_finger.col = col;
	}
	else
	{
		answer += "R";
		right_finger.row = row;
		right_finger.col = col;
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	for (int i = 0; i < numbers.size(); ++i)
	{
		int num_click = --numbers[i];
		if (num_click == -1)
		{
			click_middle_num(num_click, answer, hand);
		}
		else if (num_click % 3 == 0)
		{
			answer += "L";
			left_finger.row = num_click / 3;
			left_finger.col = 0;
		}
		else if (num_click % 3 == 2)
		{
			answer += "R";
			right_finger.row = num_click / 3;
			right_finger.col = 2;
		}
		else
		{
			click_middle_num(num_click, answer, hand);
		}
	}
	return answer; // LRLLLRLLRRL
}

void main()
{
	vector<int> nums 
		= { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	string hand = "left";
	printf(solution(nums, hand).c_str()); // LRLLRRLLLRR
}