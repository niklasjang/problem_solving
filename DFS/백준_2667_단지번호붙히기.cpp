/*
2019-11-23

dfs로 돌면서 숫자를 세고 return 하면서 answer에 push_back

*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n = 0;
int map[25][25];
bool visited[25][25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
	int num = 1;
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			num += dfs(nx, ny);
		}
	}
	return num;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visited[i][j]) {
				answer.push_back(dfs(i, j));
			}
		}
	}
	printf("%d\n", answer.size());
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}