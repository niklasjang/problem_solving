/*
LCS

N 최대가 100,000이고, NlogN은 1억이므로 NlogN까지는 가능한데, LogN짜리 알고리즘은 이분탐색 lower_bound밖에 없다.

A :1 2 3

B: 1 3 2에 대해서

vector<int>::iterator prev, curr;
prev = lower_bound(strA.begin(), strA.end(), A[0]);
dp[0] = 1; // 기본 LCS 길이 1
curr = lower_bound(strA.begin(), strA.end(), A[1]);
dp[1] = 1; //기본 LCS 길이 1
if(prev < curr){ //이번에 찾은게 저번에 찾은것보다 큰 위치면
	//dp[현재의 index] += 1;
}else{ //더 작은 위치에서 찾았으면 LCS 불가
	index++;
}

*/
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int main(void) {
	cin >> n;
	int* arrA = new int[n];
	int* arrB = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}

	int** dp = new int*[2];
	for (int i = 0; i < 2; i++) {
		dp[i] = new int[n+1];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				dp[i%2][j] = 0;
				continue;
			}
			if (arrA[i-1] == arrB[j-1]) {
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			}
			else {
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
			}
		}	
	}
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j <= n; j++) {
	//		cout << dp[i % 2][j] << " ";
	//	}
	//	cout << "\n";
	//}
	
	cout << dp[n % 2][n] << "\n";
	return 0;
}