/*
두 문자열의 LCS 길이 구하고 실제 LCS 구하기.

LCS 길이는 dp 테이블의 가장 구석에 있는 값.
LCS는 가작 구석에서부터
1. 해당 칸에 대응하는 두 문자열의 문자가 같으면 [i-1][j-1]로
2. 아니라면 [i][j-1]과 [i-1][j]를 비교해서 차이가 있으면 큰 칸으로,
3. 차이가 없으면 아무 칸으로나 간다.
*/
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
		if (dp[i][j - 1] < dp[i - 1][j]) {
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