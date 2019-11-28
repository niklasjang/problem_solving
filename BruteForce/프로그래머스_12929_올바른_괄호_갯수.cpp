/*
괄호문제는 일단 stack이 먼저 생각난다. 하지만 ((()))의 경우 (((까지 넣었을 때 왼쪽 괄호를 몇개 넣었느지 알고있어야 한다는 문제가 있다. 재귀의 매개변수가 많아지기도 하고 복잡해진다. 더 간단한 방법을 생각해보자.

1. n을 입력받아서 최대 2*n개의 괄호를 넣을 수 있다. 왼쪽 괄호를 +1, 오른쪽 괄호를 -1로 생각하자.
2. ((()))의 예제에서 볼 수 있듯이 왼쪽괄호가 먼저 많이 들어가는 것은 문제가 되지 않는다. 오른쪽 괄호를 맞춰서 넣으면 되니까.
3. 하지만 오른쪽 괄호를 왼쪽괄호보다 많이 넣으면 고칠 수가 없다. 이는 +1/-1의 개념을 적용해서 음수가 된 경우 오른쪽 괄호가 왼쪽 괄호보다 많은 경우라고 생각할 수 있다.
4. 재귀가 끝나는 조건은 자명하게 2*n개의 괄호를 넣었을 때이고,
5. 중간에 재귀를 더이상 진행하지 않아도 되는 경우는 음수가 되었을 때다.
6. 그리고 매 재귀마다 왼쪽괄호를 넣을 수도 있고, 오른쪽 괄호를 넣을 수도 있다.
7. ndl 14이므로 2*n 은 28이고 2^28은 1억보다 작다.
*/
#include <string>
#include <vector>

using namespace std;
int len = 0;
int foo(int count, int sum){
    if(sum < 0) return 0;
    if(count == 2 * len){
        if(sum == 0)   return 1;
        else return 0;
    }
    return foo(count+1, sum+1) + foo(count+1, sum-1);
}

int solution(int n) {
    len = n;
    return foo(0,0);
}


/*
sum을 사용하지 않고 왼쪽 괄호/오른쪽 괄호의 갯수로 푼 경우
*/
#include <string>
#include <vector>

using namespace std;
int len = 0;
int foo(int left, int right){
    if(left < right) return 0;
    if(left + right == 2 * len){
        if(left == right) return 1;
        else return 0;
    }
    return foo(left+1, right) + foo(left, right+1);
}

int solution(int n) {
    len = n;
    return foo(0,0);
}
