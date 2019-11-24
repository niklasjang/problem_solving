/*
각 원소를 넣는 경우/ 안넣는 경우를 둘다 dfs돌리면서 넣은 경우 vector의 size로 종료 조건을 판단한다.
혹은 더이상 넣을 수 있는 것이 없는 경우 종료한다. 
*/
#include <iostream>
#include <vector>

using namespace std;
vector<int> numbers;
vector<int> selected;
int n = 0;
void dfs(int x) {
	//numbers[x]를 넣을지 말지 결정하고 x+1을 호출한다. 
	if (x == n) {//n-1까지 다 
		if (selected.size() == 6) {
			for (int i = 0; i < 6; i++) {
				cout << selected[i] << " ";
			}
			cout << "\n";
		}
		return;
	}
	selected.push_back(numbers[x]);
	dfs(x + 1);
	selected.pop_back();
	dfs(x + 1);
}

int main(void) {
	while (true) {
		cin >> n;
		if (n == 0) break;
		numbers = vector<int>(n,0);
		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
		}
		dfs(0);
		cout << "\n";
	}
	return 0;
}