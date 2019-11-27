/*
STACK을 이용한 GREEDY

1. 가능하면 앞자리를 크게 만들어주는게 좋으니 계속 스택에 쌓으면서 자기보다 큰게 앞에 있으면 지워버린다.
2. 끝까지 갔는데 더 지워야 되면 뒤에서부터 지우는게 최선이다.

남은 k개만큼을 뒤에서 모두 pop하는 것이 정당한 이유
위의 for문에서 number[i]에 대해서 number[i]보다 작은 값이 있으면
그 값을 모두 지우고 제일 앞에 위치시키는 과정을 진행했다.
뒤에 어떤 숫자가 오든, 가장 높은 자리수의 숫자가 큰 것이 크기 때문에
뒷자리는 신경쓰지말고 그 때 그 때 큰 수를 최대한 앞으로 보내기면 하면 된다.

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
		//k는 몇 개의 숫자를 지울 수 있는지를 나타냄
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