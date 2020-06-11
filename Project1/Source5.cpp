#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	int weight;
	int depth;
	Node* prev_node_ptr;
	vector<Node*> next_node_ptrs;
};

bool compare(const Node& a, const Node& b)
{
	return a.depth < b.depth;
}

vector<int> solution(int total_sp, vector<vector<int>> skills) {
	vector<int> answer = {};
	
	vector<int> skill_ids;
	for (int i = 0; i < skills.size(); ++i)
	{
		vector<int>& skill = skills[i];
		skill_ids.push_back(skill[0]);
		skill_ids.push_back(skill[1]);
	}
	int node_count = *max_element(skill_ids.begin(), skill_ids.end());
	
	vector<Node> nodes(node_count);
	for (int i = 0; i < skills.size(); ++i)
	{
		vector<int>& skill = skills[i];
		int cur_id = skill[0] - 1;
		int next_id = skill[1] - 1;

		Node& cur_node = nodes[cur_id];
		Node& next_node = nodes[next_id];

		cur_node.next_node_ptrs.push_back(&next_node);
		next_node.prev_node_ptr = &cur_node;
		next_node.depth = cur_node.depth + 1;
	}
	
	sort(nodes.begin(), nodes.end(), compare);
	for (int i = 0; i < nodes.size(); ++i)
	{
		Node& node = nodes[i];
		if(node.next_node_ptrs.empty())
			node.weight = 1;
		else
		{
			node.weight = node.next_node_ptrs.size() * (node.next_node_ptrs[0]->weight);
		}
	}
	return answer;
}

void main()
{
	vector<vector<int>> skills = { {1, 2}, {1, 3}, {3, 6}, {3, 4}, {3, 5} };
	vector<int> ans = solution(21, skills);
	ans; //  {44, 11, 33, 11, 11, 11};
}


