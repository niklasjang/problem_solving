#include <iostream>
#include <vector>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(const vector<vector<int> >& map, vector<vector<bool> >& visited, int x, int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= map.size()) continue;
		if (ny < 0 || ny >= map[0].size()) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			dfs(map, visited, nx, ny);
		}
	}
	return;
}
int main(void) {
	int tc = 0; cin >> tc;
	
	while (tc--) {
		int m = 0, n = 0, k = 0;
		cin >> m >> n >> k;
		vector<vector<int> > map(m, vector<int>(n, 0));
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		int x = 0, y = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] && !visited[i][j]) {
					++ans;
					dfs(map, visited, i, j);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}