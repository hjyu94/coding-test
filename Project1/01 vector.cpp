#include <vector>
#include <iostream>
using namespace std;

// 배열 기반, sequence container

// 생성자
vector<int> v;
vector<int> v1(5); // 기본값 0 으로 초기화 된 원소 5개
vector<int> v2(5, 2); // 기본값 2로 초기화 된 원소 5개

// 벡터 멤버 함수
void vector_member_func() 
{
	v.assign(5, 2); // 2의 값으로 5개의 원소 할당
	
	v.at(0);
	v[0];

	v.front();
	v.back();
	
	v.clear();	// 원소는 제거하고, 메모리는 남아있다. 
				// size는 줄고 capacity는 그대로
	v.push_back(1);
	v.pop_back();

	v.reserve(6); // 6개의 원소를 저장할 위치 예약. 미리 동적할당
	v.resize(2); // 크기를 2로 변환
	v.resize(6, 3); // 크기를 6으로 변환, 더 커질 경우 3으로 초기화

	v.size(); // 원소 갯수 리턴
	v.capacity(); // 할당된 공간 크기 리턴

	v2.swap(v1); // 원소와 capacity swap
	vector<int>().swap(v1); // v1의 capacity를 없애고 싶을때 사용, 메모리 날리기

	vector<int>::iterator iter = v.end();
	v.erase(iter); // size만 줄어들고 capacity(할당된 메모리)는 남는다!

	bool isEmpty = v.empty();
}

void vector_원소_순회()
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
	{
		cout << *iter << endl;
	}
}

/*
	size? 실제로 들어가 있는 원소 갯수
	capacity? 할당된 메모리 크기


	원소 갯수	capacity
			1	1
	---------------------
			2	2
	---------------------
			3	4
			4	4
	---------------------
			5	8
			6	8
			7	8
			8	8
	---------------------
			9	16
	...

	기존 capacity의 2배로 증가
*/
