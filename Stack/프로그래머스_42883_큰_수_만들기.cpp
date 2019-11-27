/*
STACK�� �̿��� GREEDY

1. �����ϸ� ���ڸ��� ũ�� ������ִ°� ������ ��� ���ÿ� �����鼭 �ڱ⺸�� ū�� �տ� ������ ����������.
2. ������ ���µ� �� ������ �Ǹ� �ڿ������� ����°� �ּ��̴�.

���� k����ŭ�� �ڿ��� ��� pop�ϴ� ���� ������ ����
���� for������ number[i]�� ���ؼ� number[i]���� ���� ���� ������
�� ���� ��� ����� ���� �տ� ��ġ��Ű�� ������ �����ߴ�.
�ڿ� � ���ڰ� ����, ���� ���� �ڸ����� ���ڰ� ū ���� ũ�� ������
���ڸ��� �Ű澲������ �� �� �� �� ū ���� �ִ��� ������ ������� �ϸ� �ȴ�.

*/
#include <string>
#include <stack>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size();
	stack<char> s1;
	stack<char> s2;
	for (int i = 0; i < len; i++) {
		//k�� �� ���� ���ڸ� ���� �� �ִ����� ��Ÿ��
		while (!s1.empty() && s1.top() < number[i] && k) {
			s1.pop();
			k--;
		}
		s1.push(number[i]);
	}
	
	while (k--) s1.pop();
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		answer += s2.top();
		s2.pop();
	}
	return answer;
}