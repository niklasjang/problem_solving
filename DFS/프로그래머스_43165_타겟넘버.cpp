2#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dfs(const vector<int> &number, const int &target, int curr, int d){
    if(d == number.size()){
        if(curr == target) return 1;
        else return 0;
    }
    int num = 0;
    num += dfs(number, target, curr + number[d], d+1);
    num += dfs(number, target, curr - number[d], d+1);
    return num;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer += dfs(numbers, target,0,0);
    return answer;
}