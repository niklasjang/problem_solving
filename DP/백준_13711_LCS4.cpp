/*
LCS

N �ִ밡 100,000�̰�, NlogN�� 1���̹Ƿ� NlogN������ �����ѵ�, LogN¥�� �˰����� �̺�Ž�� lower_bound�ۿ� ����.

A :1 2 3

B: 1 3 2�� ���ؼ�

vector<int>::iterator prev, curr;
prev = lower_bound(strA.begin(), strA.end(), A[0]);
dp[0] = 1; // �⺻ LCS ���� 1
curr = lower_bound(strA.begin(), strA.end(), A[1]);
dp[1] = 1; //�⺻ LCS ���� 1
if(prev < curr){ //�̹��� ã���� ������ ã���ͺ��� ū ��ġ��
	//dp[������ index] += 1;
}else{ //�� ���� ��ġ���� ã������ LCS �Ұ�
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