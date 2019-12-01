/*
�� ���ڿ��� LCS ���ϱ�

���ڿ� 3���̴ϱ� dp�迭�� 3������ �ž��Ѵ�. LCS�� ����ϴ°� �ʿ���� LCS�� ���̸� ����ϸ� �Ǵϱ�
�� �� backTracking ���� dp�� ���� ������ ���� ã���� �ȴ�. 

������ü�� ���� ������ �����ϸ� ������ ���� �� 7��, �� �� �ϳ��� ���Ӱ� �߰��� ���ڰ� ��� ���� ����̴�.

�߸��� Ǯ��
1. �� ���ڿ��� a,b,c����� �� �� ���ڿ��� LCS�� ans�� a,b,c ��ο� ���ԵǾ� �ִ�.
2. a,b�� LCS�� ���ϸ� ans �Ǵ� ans�� ������ LCS�� ���� �� �ִ�.
3. b,c�� LCS�� ���ϸ� ans �Ǵ� ans�� ������ LCS�� ���� �� �ִ�.
4. 2.�� 3.�� LCS�� �ٽ� ���ϸ� ans�� ���� �� �ִ�. 
�ݷ�
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

	//LCS ���� ���
	cout << dp[lenA][lenB][lenC]<< "\n";
	return 0;
}