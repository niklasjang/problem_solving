/*
���α׷��ӽ� ��ũ ��Ʈ�ѷ� ������ Ǯ�ٰ� ���� �з��� '��'�ε�, ���� �켱���� ť�ΰ͵� �𸣰� �־���.

1. ���� Ư���� ��Ģ�� ������ Ʈ����, ���� �̿��ؼ� �켱���� ť�� ������ �� �ֽ��ϴ�.
2. ���̶�? �켱���� ť�� ���Ͽ� ������� �ڷᱸ���̴�.
3.���� ���� ���� �߿��� �ִ��̳� �ּڰ��� ������ ã�Ƴ����� ������� �ڷᱸ��
4. ���� ������ ������ ����(������ ���� ����) �� �����Ѵ�. ū ���� ���� ������ �ְ� ���� ���� ���� ������ �ִٴ� ���� \
������ ���ϸ� �θ� ����� Ű ���� �ڽ� ����� Ű ������ �׻� ū(����) ���� Ʈ���� ���Ѵ�
5. ���� ���� ��ü���� ����� ������ �Ʒ����� ����. �ϴ� ����ϴ� ������ �����. �ϴ� A�� ����!
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

//MY_STRUCT�� ���� �� �����ڱ��� �������ش�. 
bool operator<(const MY_STRUCT& a, const MY_STRUCT& b) {
	if (a.second != b.second) return a.second < b.second; 
	else return a.first < b.first;
}

//class�� �����ϸ� priority_queue ���ǿ� ���� �� ����.
struct MY_STRUCT_COMPARE { 
	bool operator()(const MY_STRUCT& a, const MY_STRUCT& b) { //operator<�� �ƴ϶� operator()�ӿ� ����!
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	}
};
int main(void) {
	//�⺻
	priority_queue<int> pq;
	for (int i = 0; i < 10; i++) {
		pq.push(i);
	}
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	cout << "\n";
	
	//��üȭ less, greater
	priority_queue<int, vector<int>, less<int> > lesspq; //top���� leaf�� ���鼭 �۾�����
	priority_queue<int, vector<int>, greater<int> > greaterpq; //top���� leaf�� ���鼭 Ŀ����
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
	//�ڷ��� pair<int, int>
	//priority_queue<pair<int,int>, vector<pair<int, int> >, pairCompare > //error!
	//��� 1. pq.push(make_pair(mypair.second, mypair.first))�� ������ ������ compare �񱳿����ڿ� ���� ȿ���� �� �� �ִ�.
	
	//��� 2. �ۼ� struct�� �����ϰ�, �� �����ڱ��� �����Ѵ�.
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
	//��� 3. operator() �������̵�
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