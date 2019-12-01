#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1010][1010] = { 0, };
string strA, strB;
string lcs = "";
void backTracking(int i, int j) {
	if (!dp[i][j]) return;
	if (strA[i - 1] == strB[j - 1]) {
		lcs = strA[i - 1] + lcs;
		backTracking(i - 1, j - 1);
	}
	else {
		if (dp[i][j-1] < dp[i - 1][j]) {
			backTracking(i - 1, j);
		}
		else {
			backTracking(i, j - 1);
		}
	}
}

int main(void) {
	cin >> strA >> strB;
	int lenA = strA.size();
	int lenB = strB.size();
	
	for (int i = 0; i <= lenA; i++) {
		for (int j = 0; j <= lenB; j++) {
			if (i == 0 || j == 0) continue;
			if (strA[i - 1] == strB[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	//for (int i = 0; i <= lenA; i++) {
	//	for (int j = 0; j <= lenB; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//LCS 길이 출력
	cout << dp[lenA][lenB] << "\n";
	//LCS 출력
	backTracking(lenA, lenB);
	cout << lcs << "\n";
	return 0;
}