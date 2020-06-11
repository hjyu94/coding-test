#include <queue>
using namespace std;

/*
	template <	
				typename T,
				typename Container = vector<T>
				typename Compare = less<typename Container::value_type>
			>
*/

// ������, ������
priority_queue<int> pq;
priority_queue<int, deque<int>> pq;
priority_queue<int, vector<int>, greater<int>> pq;

void priority_queue_example() 
{
	priority_queue<int> pq;

	pq.empty();
	pq.push(10);
	pq.top();
	pq.size();
	pq.pop();
}
