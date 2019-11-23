#include <string>
#include <vector>
#include <queue>
using namespace std;

void dfs(int n, const vector<vector<int>> &computers, vector<bool> &visited, int x){
    visited[x] = true;
    for(int i=0; i<n; i++){
        if(x==i) continue;
        if(computers[x][i] && !visited[i]){
            dfs(n, computers, visited, i);
        }
    }
}

void bfs(int n, const vector<vector<int>> &computers, vector<bool> &visited, int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(i==x) continue;
            if(computers[front][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ++answer;
            // dfs(n, computers, visited, i);
            bfs(n, computers, visited, i); 
        }
    }
    return answer;
}