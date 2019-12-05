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

int n = 0;
vector<int> strA;
vector<pair<int, int> > strB, sortedB;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main(void) {
	cin >> n;
	int* dp = new int[n];
	int ans = 1;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		strA.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		strB.push_back(make_pair(t, i));
		sortedB.push_back(make_pair(t,i));
	}
	sort(sortedB.begin(), sortedB.end());
	vector<int>::iterator it; //strA[j]가 strB에서 등장하는 인덱스가 strA[i]보다 작은지 판단하기 위함
	vector<pair<int, int> >::iterator prev, curr;
	prev = lower_bound(sortedB.begin(), sortedB.end(), make_pair(strA[0], 0), compare);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		curr = lower_bound(sortedB.begin(), sortedB.end(), make_pair(strA[i],0), compare);
		if (prev->second < curr->second ) {
			dp[i] = dp[i - 1] + 1;
			ans = ans < dp[i] ? dp[i] : ans;
		}
		else {
			for (int j = 0; j < curr->second; j++) {
				//strA[i]를 반드시 포함하는 LCS를 구하고 싶으니, strB에서 strA[i]가 몇 번째에 등장하는지 찾은게 curr->second,
				//strB에서 curr->second보다 작은 위치에 등장하는 숫자들이 strA에서 몇 번째에 등장하는지 확인해서 curr->second보다 작으면 
				//strA[i]보다 앞에 있는 것이다. 
				it = lower_bound(strA.begin(), strA.end(), strB[j].first);
				int idx = it - strA.begin();
				if (idx < i) {
					if (dp[i] < dp[idx] + 1) dp[i] = dp[idx] + 1;
				}
			}
		}
		prev = curr;
	}
	
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";
	cout << ans << "\n";
	return 0;
}