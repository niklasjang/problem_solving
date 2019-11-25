#include <iostream>
#include <vector>
using namespace std;

int map[100][100] = { 0, };
int map2[100][100] = { 0, };
bool visited[100][100] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n = 0;

void dfs(int x, int y, int depth) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;
		if (map[nx][ny]> depth && !visited[nx][ny]) {
			dfs(nx, ny, depth);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			map2[i][j] = map[i][j];
		}
	}
	int answer = -1;
	for (int d = 0; d < 101; d++) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = map2[i][j];
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > d && !visited[i][j]) {
					++ans;
					dfs(i, j, d);
				}
			}
		}
		answer = answer < ans ? ans : answer;
	}
	
	cout << answer << "\n";

	return 0;

}