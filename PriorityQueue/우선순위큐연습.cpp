/*
프로그래머스 디스크 컨트롤러 문제를 풀다가 문제 분류가 '힙'인데, 힙이 우선순위 큐인것도 모르고 있었다.

1. 힙은 특정한 규칙을 가지는 트리로, 힙을 이용해서 우선순위 큐를 구현할 수 있습니다.
2. 힙이란? 우선순위 큐를 위하여 만들어진 자료구조이다.
3.여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조
4. 힙은 일종의 반정렬 상태(느슨한 정렬 상태) 를 유지한다. 큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있다는 정도 \
간단히 말하면 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리를 말한다
5. 힙에 대한 구체적인 설명과 구현은 아래에서 보자. 일단 사용하는 법부터 배우자. 일단 A형 부터!
https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html
*/
#include <iostream>
#include <queue>

using namespace std;

bool pairCompare(const pair<int, int> & a, const pair<int, int>& b) {
	if (a.second != b.second) return a.second < b.second;
	else a.first < b.first;
}

class MY_STRUCT {
public:
	int first;
	int second;
	MY_STRUCT(int x, int y) : first(x), second(y) {};
};

//MY_STRUCT에 대한 비교 연산자까지 정의해준다. 
bool operator<(const MY_STRUCT& a, const MY_STRUCT& b) {
	if (a.second != b.second) return a.second < b.second; 
	else return a.first < b.first;
}

//class로 정의하면 priority_queue 정의에 넣을 수 없다.
struct MY_STRUCT_COMPARE { 
	bool operator()(const MY_STRUCT& a, const MY_STRUCT& b) { //operator<가 아니라 operator()임에 주의!
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	}
};
int main(void) {
	//기본
	priority_queue<int> pq;
	for (int i = 0; i < 10; i++) {
		pq.push(i);
	}
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	cout << "\n";
	
	//구체화 less, greater
	priority_queue<int, vector<int>, less<int> > lesspq; //top에서 leaf로 가면서 작아지게
	priority_queue<int, vector<int>, greater<int> > greaterpq; //top에서 leaf로 가면서 커지게
	for (int i = 0; i < 10; i++) {
		lesspq.push(i);
		greaterpq.push(i);
	}
	while (!lesspq.empty()) {
		cout << lesspq.top() << "\n";
		lesspq.pop();
	}
	cout << "\n";
	while (!greaterpq.empty()) {
		cout << greaterpq.top() << "\n";
		greaterpq.pop();
	}
	cout << "\n";
	//자료형 pair<int, int>
	//priority_queue<pair<int,int>, vector<pair<int, int> >, pairCompare > //error!
	//방법 1. pq.push(make_pair(mypair.second, mypair.first))로 위에서 구현한 compare 비교연산자와 같은 효과를 낼 수 있다.
	
	//방법 2. 작성 struct를 정의하고, 비교 연산자까지 정의한다.
	priority_queue<MY_STRUCT, vector< MY_STRUCT> > mystruct_pq;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mystruct_pq.push(MY_STRUCT(i,j));
		}
	}
	while (!mystruct_pq.empty()) {
		cout << mystruct_pq.top().first << "," << mystruct_pq.top().second << "\n";
		mystruct_pq.pop();
	}
	cout << "\n";
	//방법 3. operator() 오버라이딩
	priority_queue<MY_STRUCT, vector< MY_STRUCT>, MY_STRUCT_COMPARE > mystruct_pq2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mystruct_pq2.push(MY_STRUCT(i, j));
		}
	}
	while (!mystruct_pq2.empty()) {
		cout << mystruct_pq2.top().first << "," << mystruct_pq2.top().second << "\n";
		mystruct_pq2.pop();
	}
	return 0;
}