/*
�����ϰ� ���� N^2LogN...

�ð��ʰ��� �翬�ϰ�

6
3 1 2 4 5 6
6 2 4 1 5 3

�� ���

1 1 1 2 3 1�� ����ϱ� �Ѵ�.

vector<pair<int ,int> >�� sort�ϴ� ���, custom compare �Լ��� �ۼ��ϴ� ����� �����.
sort�� 3��° ������ ���� make_pair�� �־�� �Ѵ�.

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
	vector<int> A(MAX,0); //A[i] = j : i�� ���� A���� j ��°�� �����ߴ�.
	vector<int> B(MAX,0); //A[B[i]] = j : B�� i��° ���ڰ� A[]�� j��° �����ߴ� ���ڴ�.
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