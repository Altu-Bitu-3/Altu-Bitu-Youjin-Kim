#include <iostream> //입출력 헤더
#include <vector> //벡터 사용 헤더

using namespace std; //std 라이브러리 사용

struct info { //내구도와 로봇 존재 여부
    int power; //내구도 변수
    bool is_on; //로봇이 올라가 있음을 의미하는 변수
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소 (올리는 위치와 내리는 위치를 변경)
    if (--pos >= 0) { //아직 포지션이 0보다 크다면
        return pos; //1만 빼서 전달하고
    }
    return n * 2 - 1; //0보다 크지 않다면? (마이너스라면)
    //2n-1을 리턴해서 반대쪽 끝으로 인덱스 위치를 올림
}

void second(int n, int start, int end) { //n (최초 입력), 현재 start, end를 받는다. (start = 올리는 위치)
    int cur = end; //시작할 때는 cur을 현재 end인 위치로 옮긴다.
    while (cur != start) { //end - 1 부터 start 까지 검사
        cur = minusPosition(n, cur); //인덱스 감소 시키는 함수를 호출 
        int next = (cur + 1) % (n * 2); //다음 위치를 잡는다.
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false; //로봇을 옮겼으면 옮긴 자리의 로봇 유무를 false로 바꾼다.
            belt[next].power--; //로봇이 옮겨졌으니까 내구도를 1 감소
            if (next != end) { //내리는 위치가 아닐 경우만
                belt[next].is_on = true; //로봇 옮기기
            }
            if (belt[next].power == 0) { //만약에 다음 벨트의 내구도가 0이 되었다면
                zero_power++; //내구도가 0으로 떨어진 수를 추가한다.
            }
        }
    }
}

void third(int start) { //올리는 위치를 인자로 받는다. 
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true; //올렸으면 로봇의 존재 여부를 존재로 바꾼다.
        belt[start].power--; //올렸으니까 내구도도 감소시킨다.
        if (belt[start].power == 0) { //내구도가 감소한 결과 내구도가 0이 되었다면
            zero_power++; //또 내구도가 떨어진 만큼 수를 추가한다.
        }
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() { //메인 함수
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //처리 시간 감소

    int n, k; //입력을 받기 위한 변수

    //입력
    cin >> n >> k; //변수에 입력
    belt.assign(n * 2, {0, false}); //belt의 개수만큼 내구도 초기 0, 로봇 없는 상태로 초기화
    for (int i = 0; i < n * 2; i++) { //2n개의 벨트를 순회하면서
        cin >> belt[i].power; //각각 칸에 내구도를 입력한다.
    }

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수
    while (true) { //무한 루프를 돌다가 내구도가 0인 수가 k보다 커지면 빠져나간다.
        start = minusPosition(n, start); //턴이 시작하면 벨트가 돌아가니까 시작 인덱스를 돌아가는 위치로 변경한다.
        end = minusPosition(n, end); //역시 벨트가 돌아갔으니 끝 인덱스도 변경한다.
        if (belt[end].is_on) { //벨트 회전 후, 로봇이 내리는 위치에 있다면 내린다.
            belt[end].is_on = false; //내렸으니까 false로 변경한다.
        }
        second(n, start, end); //2단계 호출
        third(start); //3단계 호출
        step++; //단계를 1개 추가한다.
        if (zero_power >= k) { //내구도 0인 수 체크
            break; //조건을 충족했을 시 빠져나간다.
        }
    }

    //출력
    cout << step; //몇 번째 단계였는지 출력하고 마친다.
    return 0;
}