/*
구현하고 보니 N^2LogN...

시간초과는 당연하고

6
3 1 2 4 5 6
6 2 4 1 5 3

의 경우

1 1 1 2 3 1을 출력하긴 한다.

vector<pair<int ,int> >를 sort하는 방법, custom compare 함수를 작성하는 방법을 배웠다.
sort의 3번째 인자인 값도 make_pair로 넣어야 한다.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101010
int n = 0;
int ans = 0;

int main(void) {
	cin >> n;
	vector<int> A(MAX,0); //A[i] = j : i가 수열 A에서 j 번째로 등장했다.
	vector<int> B(MAX,0); //A[B[i]] = j : B의 i번째 문자가 A[]에 j번째 등장했던 문자다.
	int temp = 0;
	for (int i = 1; i <=n; i++) {
		cin >> temp;
		A[temp] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
	}
	vector<int> lis;
	for (int i = 1; i <=n; i++) {
		if (lis.empty() || lis.back() < A[B[i]]) {
			lis.push_back(A[B[i]]);
			ans++;
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), A[B[i]]);
			*it = A[B[i]];
		}
	}

	cout <<ans<< "\n";
	return 0;
}