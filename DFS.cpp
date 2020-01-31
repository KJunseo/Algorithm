#include <iostream>
#include <vector>

using namespace std;

int number = 7; // node의 개수
int checked[7]; // 각 node의 방문처리를 위한 배열 
vector<int> a[8]; // node의 인접관계를 나타내기 위한 벡터

void dfs(int x) {
    if(checked[x]) return; // 해당 node를 이미 방문했다면 return
    checked[x] = true; // 처음 방문하는 것이면 방문처리

    cout << x << ' '; // 해당 node 출력

    for(int i=0;i<a[x].size();i++){ // 해당 node와 인접한 node를 하나씩 방문하면서 dfs 실행
        int y = a[x][i];
        dfs(y);
    }
}

int main(void) {

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);

    return 0;
}