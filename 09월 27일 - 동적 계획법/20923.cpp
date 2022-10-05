#include <iostream>
#include <deque>

/* 참고 코드: https://seastar105.tistory.com/75 */

/* 참고 부분: 처음에는 도도와 수연이의 deck과 ground를
 * 각각 D_deck와 D_ground, S_deck와 S_ground로 놓고 문제를 풀려고 했었다.
 * 그런데 써 내려가면 써 내려갈수록 점점 고려해야 할 것이 많아지더라.
 * 그래서 검색해 본 결과 이 블로그의 덱 배열을 만드는 방식을 참고하게 되었다.
 * 나중에 되짚어 보기 위해서 원래 썼던 코드를 맨 밑에 백업해 둔다. */

using namespace std;

#define DODO 0
#define SUYEON 1

deque<int> deck[2];
deque<int> ground[2];

int N, M;
int turn = 0;

int winnerCheck() {
    if(ground[DODO].size() && ground[DODO].front() == 5) {
        return DODO;
    }
    else if(ground[SUYEON].size() && ground[SUYEON].front() == 5) {
        return DODO;
    }
    else if(ground[DODO].size() && ground[SUYEON].size() && ground[DODO].front() + ground[SUYEON].front() == 5) {
        return SUYEON;
    }
    return -1;
}

void gamePlay() {
    ground[turn].push_front(deck[turn].front());
    deck[turn].pop_front();
    if (deck[turn].empty()) {
        cout << (turn ? "do" : "su") << '\n';
        exit(0);
    }
    
    int win = winnerCheck();
    if (win != -1) {
        int lose = 1 - win;
        while (ground[lose].size()) {
            deck[win].push_back(ground[lose].back());
            ground[lose].pop_back();
        }
        while (ground[win].size()) {
            deck[win].push_back(ground[win].back());
            ground[win].pop_back();
        }
    }
    turn = 1 - turn;
}

void printResult() {
    if(deck[DODO].size() > deck[SUYEON].size()) {
        cout << "do" << '\n';
    }
    else if(deck[DODO].size() < deck[SUYEON].size()) {
        cout << "su" << '\n';
    }
    else {
        cout << "dosu" << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false); //시간초과 방지

    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        
        deck[DODO].push_front(a);
        deck[SUYEON].push_front(b);
    }
    
    for(int i=0; i<M; ++i) {
        gamePlay();
    }

    printResult();

    return 0;
}

/* 원래 작성했던 코드: 예시 코드는 통과, but 백준은 통과 실패
 * 반례 추정: turn을 bellRing 함수까지 가야지 바꿀 수 있기 때문에
 * 만약 그 전에 승부가 결정(?) 되었다면 파악할 수가 없다. */

/* #include <iostream>
#include <deque>

using namespace std;

deque<int> D_deck, S_deck;
deque<int> D_ground, S_ground;

#define DODO 1
#define SUYEON 2

int turn = DODO;
int d = 0, s = 0;

int bellRing() {
    
    // 경우의 수
    1. 도도가 종을 친다. : 그라운드의 맨 위 카드 중 한 개가 5이다. 
    2. 수연이가 종을 친다. : 그라운드의 맨 위 카드 두 개의 합이 5이다.
    3. 둘 모두 종을 치지 못한다. : default
    
    
    //경우 1
    if(turn == SUYEON && (d == 5 || s == 5)) {
        return DODO;
    }
    
    //경우 2
    else if(turn == DODO && (d + s == 5)) {
        return SUYEON;
    }
    
    else {
        if(turn == DODO) turn = SUYEON;
        else turn = DODO;
        
        return -1;
    }
}

void bellRinged(int br_res) {
    //도도가 벨을 울렸을 때
    if(br_res == DODO) {
        while(!S_ground.empty()) {
            D_deck.push_back(S_ground.back());
            S_ground.pop_back();
        }
        while(!D_ground.empty()) {
            D_deck.push_front(D_ground.back());
            D_ground.pop_back();
        }
        
        d = 0, s = 0;
    }
    
    //수연이가 벨을 울렸을 때
    if(br_res == SUYEON) {
        while(!D_ground.empty()) {
            S_deck.push_back(D_ground.back());
            D_ground.pop_back();
        }
        while(!S_ground.empty()) {
            S_deck.push_back(S_ground.back());
            S_ground.pop_back();
        }
        
        d = 0, s = 0;
    }
}

bool gamePlay() { //1턴 진행을 gamePlay 함수 1번으로 봄
    int br_res;
    
    d = D_deck.front();
    D_deck.pop_front();
    D_ground.push_front(d);
    
    br_res = bellRing();
    bellRinged(br_res);
    
    s = S_deck.front();
    S_deck.pop_front();
    S_ground.push_front(s);
    
    br_res = bellRing();
    bellRinged(br_res);
    
    //한 명이 비었으면 게임종료 
    if(D_deck.empty() || S_deck.empty()) {
        return true;
    }
    
    return false;
}

void printResult() {
    if(D_deck.size() > S_deck.size()) {
        cout << "do";
    }
    else if(D_deck.size() == S_deck.size()) {
        cout << "dosu";
    }
    else {
        cout << "su";
    }
}

int main()
{   cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    while(n--) {
        int d, s;
        cin >> d >> s;
        
        D_deck.push_front(d);
        S_deck.push_front(s);
    } //초기 덱 완성, ground는 비어 있음
    
    while(m--) {
        bool res = gamePlay();
        if(res) break;
    }
    printResult();
    
    return 0;
} */