//
// Created by GiTaek Lee on 2020/07/29.
//


// 연구소 /  삼성 SW역량테스트 기출문제
/*

첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

0이 있는 지점에서 만들 수 있는 3개의 벽을 다 만들어 본 후에, BFS/DFS를 통해서 바이러스가 있는 지점에서

바이러스를 모두 퍼뜨려 본 후에, 안전 영역의 크기(0의 갯수)를 Count 하고 최댓값을 찾으면 되는 알랄라같은 문제이다.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 9
#define dc 4

int temp_map[MAX_N][MAX_N];
int m[MAX_N][MAX_N]; // 연구소 영역
int ans = 0; // 안전 영역 최대크기
int N; // 세로 크기
int M; // 가로 크기
int dx[dc] = {0,0,-1,1};
int dy[dc] = {-1,1,0,0};

vector<pair<int,int>> virus; // 코로나 바이러스
vector<int> safety_zone; // 격리안전지역

void copy_map(int(*a)[MAX_N],int(*b)[MAX_N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            a[i][j] = b[i][j];
        }
    }
}

// bfs로 바이러스를 전파한다. 우쾅콰아코아코콰콰코쾅

void bfs_virus(){
    int after_wall[MAX_N][MAX_N];
    // 벽으로 커버치고 상황 카피함.
    copy_map(after_wall,temp_map);

    queue<pair<int,int>> q;
    // 초기 바이러스 좌표를 큐에 넣는다.
    for(int i = 0; i< virus.size(); i++){
        q.push(virus[i]);
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(0 <= nx && nx < N && 0 <= ny && ny < M){
                if(after_wall[nx][ny] == 0){
                    after_wall[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    int safety_size = 0;
    // 안전 영역의 크기를 구한다.
    for(int i = 0; i<N; i++){
        for(int j=0; j<M; j++){
            if(after_wall[i][j] == 0){
                safety_size++;
            }
        }
    }
    ans = ans>safety_size ? ans : safety_size;
}

void recur_wall(int cnt){
    if(cnt == 3){
        bfs_virus();
        return;
    }
    // 벽이 3개면 안전영역의 크기 저장

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            // 빈칸이면
            if(temp_map[i][j] == 0){
                temp_map[i][j] = 1;
                // 벽을 설치한다.
                recur_wall(cnt + 1);
                temp_map[i][j] = 0;
                // 벽을 한개 추가한다.
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> m[i][j];
            // 바이러스 좌표 저장
            if (m[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(m[i][j] == 0){
                copy_map(temp_map,m);
                temp_map[i][j] = 1;
                recur_wall(1);
                temp_map[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
//    BFS를 사용하여 바이러스를 퍼뜨렸고, 재귀를 사용하여 문제에서 요구한 3개의 벽을 세웠다.
//
//    1. map에 전체 입력을 받음 (이때, 바이러스에 해당하는 2가 들어오면 바로 큐에 넣음)
//
//    2. 3개의 벽을 세우기 위해 전체를 돌며 0이 보이면 tmp에 map을 카피한 후 재귀로 3개의 벽을 세움.
//
//            즉, tmp는 최초 map의 모든 0에 벽을 세우기 위한 임시배열.
//
//    3. 벽을 다 세웠으면 BFS로 들어가서 afterWall이라는 배열에 다시 복사를 한다.
//
//            그리고 다시 복사한 이 afterWall 배열을 가지고 바이러스를 퍼뜨린다.
//
//    4. 매 회 바이러스가 퍼진 이후 0의 개수를 세서 그 최대가 되는 때를 출력.
//
//
//
//     바이러스가 퍼진 이후 전체를 탐색하여 0의 개수를 세고싶지 않아 zeroCnt 변수를 하나 두고 이를 가지고 최대 0의 개수를 찾는데 사용하였다.



    return 0;

}