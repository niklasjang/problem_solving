/*
dfs(x) : x에 연결된 모든 정점을 방문하면서 visited로 바꾼다.
이 때 visited[i] = true로 바꾸는 것을 dfs의 시작이 아니라,
다른 dfs()호출의 직전에 위치함으로써 x로 다시 돌아오는 dfs 싸이클도 판단할 수 있도록 한다. 

이거 왜 이렇게 어려웠지?

*/
#include <iostream>
#include <vector>

using namespace std;
int map[100][100] = { 0, };
int n = 0;
vector<int> visited;

void dfs(int x) {
	for (int i = 0; i < n; i++) {
		if (map[x][i] && !visited[i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		visited.assign(n, 0);
		dfs(i);

		for (int j = 0; j < n; j++) {
			if (visited[j]) 
				map[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}