/*
공통 부분 문자열

LCS와 달리 연속된 부분 문자열 중 가장 긴것을 찾는 문제
*/

#include <iostream>
#include <string>
using namespace std;
int dp[4010][4010];
int ans = 0;
void longestSubString(const string& a, const string& b) {
	for (int r = 0; r < a.size(); r++) {
		for (int c = 0; c < b.size(); c++) {
			if (r == 0 || c == 0) {
				dp[r][c] = 0;
				continue;
			}
			if (a[r - 1] == b[c - 1]) {
				dp[r][c] = dp[r - 1][c - 1] + 1;
				ans = ans < dp[r][c] ? dp[r][c] : ans;
			}
			else {
				dp[r][c] = 0;
			}
		}
	}
}

int main(void) {
	string a, b;
	cin >> a >> b;
	longestSubString(a, b);
	cout << ans << "\n";
	return 0;
}