#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <map>
int solution_mine(vector<vector<string>> clothes) 
{
	int answer = 1;
	map<string, int> how_many_clothes;

	for (int i = 0; i < clothes.size(); ++i)
	{
		string category = clothes[i][1];
		auto iter = how_many_clothes.find(category);
		if (how_many_clothes.end() == iter) {
			how_many_clothes.insert(pair<string, int>(category, 1));
		}
		else {
			how_many_clothes[category] = ++(*iter).second;
		}
	}

	for (map<string, int>::iterator iter = how_many_clothes.begin(); 
		iter != how_many_clothes.end(); 
		iter++) 
	{
		answer *= (iter->second + 1);
	}
	answer--;

	return answer;
}

#include <unordered_map>
int solution_others(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> attributes; // �ʱⰪ 0

	for (int i = 0; i < clothes.size(); i++)
		attributes[clothes[i][1]]++;

	for (auto it = attributes.begin(); it != attributes.end(); it++)
		answer *= (it->second + 1);
	answer--;

	return answer;
}

void main()
{
	vector<vector<string>> clothes = 
		{{"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"}};
		//{{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}};
	cout << solution_mine(clothes) << endl;
}