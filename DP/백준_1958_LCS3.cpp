/*
세 문자열의 LCS 구하기

문자열 3개이니까 dp배열이 3차원이 돼야한다. LCS를 출력하는건 필요없고 LCS의 길이만 출력하면 되니까
좀 더 backTracking 없이 dp의 가장 마지막 값만 찾으면 된다. 

직육면체의 가장 구석을 생각하면 인접한 블럭은 총 7개, 이 중 하나는 새롭게 추가된 문자가 모두 같은 경우이다.

잘못된 풀이
1. 세 문자열을 a,b,c라고할 때 세 문자열의 LCS인 ans는 a,b,c 모두에 포함되어 있다.
2. a,b의 LCS를 구하면 ans 또는 ans를 포함한 LCS를 구할 수 있다.
3. b,c의 LCS를 구하면 ans 또는 ans를 포함한 LCS를 구할 수 있다.
4. 2.와 3.의 LCS를 다시 구하면 ans를 얻을 수 있다. 
반례
A: dababcf
B: ababdef
C: df
LCS(A,B): ababf
LCS(LCS(A,B),C):  f
LCS(A,B,C): df
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dp[110][110][110] = { 0, };
string strA, strB, strC;
string lcs = "";
vector<int> adj;
int main(void) {
	cin >> strA >> strB >> strC;
	int lenA = strA.size();
	int lenB = strB.size();
	int lenC = strC.size();

	for (int i = 0; i <= lenA; i++) {
		for (int j = 0; j <= lenB; j++) {
			for (int k = 0; k <= lenC; k++) {
				if (i == 0 || j == 0 || k==0) continue;
				if (strA[i - 1] == strB[j - 1] && strB[j-1] == strC[k-1]) dp[i][j][k] = dp[i - 1][j - 1][k-1] + 1;
				else {
					adj.push_back(dp[i-1][j][k]);
					adj.push_back(dp[i][j-1][k]);
					adj.push_back(dp[i][j][k-1]);
					adj.push_back(dp[i-1][j-1][k]);
					adj.push_back(dp[i][j-1][k-1]);
					adj.push_back(dp[i-1][j][k-1]);
					sort(adj.begin(), adj.end(), greater<int>());
					dp[i][j][k] = adj.front();
					adj.clear();
				}
			}
		}
	}

	//LCS 길이 출력
	cout << dp[lenA][lenB][lenC]<< "\n";
	return 0;
}