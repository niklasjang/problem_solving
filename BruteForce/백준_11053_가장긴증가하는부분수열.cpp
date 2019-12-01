#include <iostream>
using namespace std;
#define MAX(a,b) (a) < (b) ? (b) : (a)
int arr[1001] = { 0, };
int dp[1001][1001]; // dp[i][j]는 i번째에서 j번째까지 보았을 때 가장 긴 LIS의 길이
int n = 0;
int ans = 0;
int LIS(void) {
	int max = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				dp[i][j] = 1;
				max = arr[i];
			}
			else {
				if (max < arr[j]) {
					dp[i][j] = dp[i][j - 1] + 1;
					max = arr[j];
				}
				else if(max == arr[j]) {
					dp[i][j] = dp[i][j - 1];
				}
				else {
					max = arr[j];
					dp[i][j] = dp[i][j - 1];
				}
			}
			ans = MAX(ans, dp[i][j]);
		}
	}
	return ans;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << LIS() << "\n";

	return 0;
}