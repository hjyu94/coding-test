#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	sort(v.begin(), v.end(), less<int>());
*/

void array_sort_example() 
{
	int arr[10] = { 3,5,2,6,3,6,7,2,3,62 };
	sort(arr, arr + 10);
}

void vector_sort_example()
{
	vector<int> v(10);
	for (int i = 0; i < v.size(); ++i)
	{
		v.push_back(i);
	}

	vector<int>::iterator iter = v.begin();
	iter = iter + 2;
	sort(iter, v.end());

	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	sort(v.begin(), v.end(), less<int>());
}

/**************************************************/

struct Student {
	string name;
	int age;
};

bool student_compare(Student a, Student b) // 우선 이름순, 같은 이름은 어린 순
{
	if (a.name == b.name)
	{
		return a.age < b.age;
	}
	else
	{
		return a.name < b.name;
	}
};

void my_compare_example() {
	vector<Student> v(10);
	sort(v.begin(), v.end(), student_compare);
}

/****************************************************/

bool my_greater(const string& a, const string& b)
{
	if (b + a < a + b)
		return true;
	return false;
}

struct my_greater_struct {
	bool operater(string& a, string& b) {
		if (b + a < a + b)
			return true;
		return false;
	};
};

void 가장_큰_수() 
{
	vector<string> strings = { "3", "30", "34" };
	sort(strings.begin(), strings.end(), my_greater);
	sort(strings.begin(), strings.end(), my_greater_struct());
}

