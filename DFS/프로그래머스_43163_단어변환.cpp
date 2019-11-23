/*
visited[x] : words에 x번째로 들어가 있는 string까지 변환하기 위해서 begind이 거쳐야 하는 변환의 수

isDiffOneChar는 각 string끼리 변환이 될 수 있는지 여부를 return한다. 
이 함수의 결과를 사용해서 인접리스트를 만든다. 단, 인접리스트를 만들 때 begin string도 words에 포함되서
인접리스트를 만들어야 한다.
이때 begin string과 target string의 위치를 기억하고 있어야 한다.

인접리스트를 만들었으면 begin string의 위치를 기억해둔 beginIndex에서부터 dfs를 진행한다.
dfs의 결과 targetIndex가 갱신되었으면 이를 출력하고 갱신되지 않았으면 0을 출력한다. 

처음에는 시간초과가 떴느데 [CRITICAl] 이미 더 빨리 갈 수 없는 것이 확정되면 진행하지 않는다. 이 부분을 수정하니 통과했다.

2시간 정도 걸렸는데 그래도 기분 좋다! 인접리스트로 바꿔서 생각하는 부분이 포인트 인듯
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDiffOneChar(const string &a, const string &b){
    int size = a.size();
    int diff = 0;
    for(int i=0; i<size; i++){
        if(a[i] != b[i]) ++diff;
    }
    if(diff == 1) return true;
    else return false;
}

// bfs(adj, beginIndex, 0);
void dfs(const vector<vector<int> > &adj, vector<int> &visited, int x, int depth ,int max){
    if(depth == max) return;
    visited[x] = visited[x] >  depth ? depth : visited[x];
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(visited[next] >= depth ) // [CRITICAl] 이미 더 빨리 갈 수 없는 것이 확정되면 진행하지 않는다.
            dfs(adj, visited, next, depth+1, max);
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    int size = words.size();
    int beginIndex = size-1;
    int targetIndex = -1;
    vector<vector<int> > adj(size, vector<int>());
    vector<int> visited(size, 987654321);
    //words끼리 서로 어떻게 연결되어 있는지 파악한다.
    for(int i=0; i<size; i++){
        if(target.compare(words[i]) == 0) targetIndex = i; 
        for(int j = i+1; j<size; j++){
            if(isDiffOneChar(words[i], words[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    //words에 target이 없으면 변환할 수 없는 경우
    if(targetIndex == -1) return 0;
    // else cout<<"targetIndex : "<< targetIndex<<"\n";
    //begin과 연결된 단어의 갯수
    // cout<<"beginIndex size : "<< adj[beginIndex].size()<<"\n";
    dfs(adj, visited, beginIndex, 0, size);
    return visited[targetIndex] != 987654321 ? visited[targetIndex] : 0 ;
}