#include <iostream> //입출력 함수
#include <vector> //vector 이용 함수

using namespace std; //std 라이브러리 사용
const int INF = 1e8; //도시의 수 N은 2에서 10 사이, 각 행렬의 성분은 1,000,000 이하의 양의 정수
//10 * 1,000,000 = 1e8

//재귀함수에는 전역변수!

vector<bool> visited; //방문했는지 여부를 검사하는 배열
vector<vector<int>> matrix; //비용을 저장하는 행렬 (사각형으로 배열이 정렬되어 있으므로 2차원 벡터)

int n, ans = INF; //최소 비용 저장 위해 미리 "최댓값으로" 초기화
//더 작은 비용이 들어오면 그것으로 교체하는 함수 포함되어 있기 때문

void backtracking(int cnt, int cur_city, int cost) {
//cnt: 몇 번 이동했는지, cur_city: 지금 어느 도시에 있는지, cost: 비용
    if (cost >= ans) { //현재 비용이 ans(즉, 마지막으로 저장된 최소 비용)보다 크다면
        return; //더 계산해도 더 커질 뿐이기 때문에 이번 루프를 종료
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //cur_city에서 0번 도시로 가는 값이 0(불가능)이 아니라면
            ans = min(ans, cost + matrix[cur_city][0]); //ans 업데이트
            //min을 사용해 기존 최솟값과 새 값 중에 어느 것이 더 큰지 최종 확인함
        }
        return; //입력했다면 이번 루프를 종료
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문한 도시에 방문했다고 표시
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            //재귀함수 호출: !visited[i]에 의해 line 31에서 true로 표시된 도시에는 방문하지 않게 됨
            visited[i] = false; //함수 호출이 끝나면 다시 false로 초기화
        }
    }
}

/*
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, "어느 도시에서 시작하든 값은 같으므로" 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n; //도시의 수 입력
    visited.assign(n, false); //도시의 수만큼 visited을 false로 초기화: 아직 가지 않은 도시를 표시
    matrix.assign(n, vector<int>(n, 0)); //matrix에 포함된 vector n개를 각각 n개의 0으로 초기화
    
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < n; j++) { //n번 반복
            cin >> matrix[i][j]; //matrix에 비용 정보 입력
        }
    }

    //연산
    visited[0] = true; //0번째 도시에서 출발!
    backtracking(1, 0, 0); //재귀함수이므로 1, 0, 0에서 백트래킹 연산 시작

    //출력
    cout << ans; //결과 출력
    return 0;
}