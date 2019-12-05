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
	vector<int>::iterator it; //strA[j]�� strB���� �����ϴ� �ε����� strA[i]���� ������ �Ǵ��ϱ� ����
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
				//strA[i]�� �ݵ�� �����ϴ� LCS�� ���ϰ� ������, strB���� strA[i]�� �� ��°�� �����ϴ��� ã���� curr->second,
				//strB���� curr->second���� ���� ��ġ�� �����ϴ� ���ڵ��� strA���� �� ��°�� �����ϴ��� Ȯ���ؼ� curr->second���� ������ 
				//strA[i]���� �տ� �ִ� ���̴�. 
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