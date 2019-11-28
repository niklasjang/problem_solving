#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int answer = 0;
int n = 0;
vector<int> v;
void dfs(void) {
	if (v.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	v.push_back(1);
	dfs();
	v.pop_back();
	v.push_back(0);
	dfs();
	v.pop_back();
	return;
}

int main(void) {
	cin >> n;
	dfs();
	return 0;
}