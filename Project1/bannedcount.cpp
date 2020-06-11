#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isEqual(string str_banned, string str_user) // fr*d*, frodo
{
	if (str_banned.size() != str_user.size()) {
		return false;
	}

	for (int i = 0; i < str_banned.size(); ++i)
	{
		char char_banned = str_banned[i];
		char char_user = str_user[i];

		if (char_banned == '*') continue;
		else if (char_banned != char_user) return false;
	}
	return true;
}

bool isDuplicated(vector<int> vec, int num)
{
	for(int iter : vec)
	{
		if (iter == num) {
			return true;
		}
	}
	return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	vector<vector<int>> str_idx;
	
	for (int i = 0; i < banned_id.size(); ++i)
	{
		vector<int> idx = {};

		for (int j = 0; j < user_id.size(); ++j)
		{
			if (isEqual(banned_id[i], user_id[j]))
			{
				idx.push_back(j);
			}
		}
		str_idx.push_back(idx);
	}
	
	vector<int> pick;
	int row = 0;
	int col = 0;
	while (true)
	{
		if (col >= str_idx[row].size())
		{
			--row;
		}
		int targetNum = str_idx[row][col];
		if (!pick.empty() && isDuplicated(pick, targetNum))
		{
			++col;
		}
		else
		{
			pick.push_back(targetNum); 
			if (pick.size() == str_idx.size())
			{
				++answer;
				pick.pop_back();
				++col;
			}
			else
			{
				row++; col = 0;
			}
		}
	}


	//vector<int> pick;
	//int i = 0; 
	//int j = 0;
	//while (true)
	//{
	//	int targetNum = str_idx[i][j]; // 0,0 / 1,0 / 1,1 / 2,0

	//	if (!pick.empty() && isDuplicated(pick, targetNum))
	//	{
	//		++j;
	//	}
	//	else
	//	{
	//		pick.push_back(targetNum);
	//		++i; j = 0;
	//		if (i == banned_id.size())
	//		{
	//			++answer;
	//			pick.pop_back();
	//			--i;
	//			++j;
	//			if (j == str_idx[i].size())
	//			{
	//				i = 0;
	//			}
	//		}
	//	}
	//}


	
	return answer;
}

void main()
{
	vector<string> userid 
		= { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	
	vector<string> bannedid 
		= { "fr*d*", "*rodo", "******" };
		//= { "fr*d*", "*rodo", "******", "******" };
		//= { "fr*d*", "abc1**" };

	solution(userid, bannedid);

			//isEqual("fr*d*", "crodo");
}


/* 
	b: 3∞≥¿œ∂ß
	u: 0,1,2 / 0,1,3 / 0,1,4 / 0,2,3 / 0,2,4 / 0,3,4 / 1,2,3 / 1,2,4 / 1,3,4 / 2,3,4
		
*/