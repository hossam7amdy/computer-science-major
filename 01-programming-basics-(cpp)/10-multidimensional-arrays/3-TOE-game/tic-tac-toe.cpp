#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

// empty = 0
// player x = 1
// player o = 2

class player{
private:
    int number{};
    bool status{};
public:
    player(const int &num):
        status(false), number(num){
    }
    bool getStatus() const {
        return this->status;
    }
    void setStatus(const bool &status){
        this->status = status;
    }
    int getNumber() const {
        return this->number;
    }
};

class TOE{
private:
    static const int MAX{100};
    int sz{};
    int players{};
    int turn{};
    player* grid[MAX][MAX]{};

    void ShowGrid(){
        for(int r=0; r<sz; ++r){
            for(int c=0; c<sz; ++c){
                if(!grid[r][c]) cout << ".";
                else cout << grid[r][c]->getNumber();
            }
            cout << "\n";
        }
    }

public:
    TOE(const int &sz, const int &players):
        sz(sz), players(players){
            assert(sz < MAX);
    }
    void play(){
        ShowGrid();
    }
};


int N;
const int MAX{10};
int grid[MAX][MAX]{};

void print(){
    int toe{};
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j)
            (!grid[i][j])? cout << "." : (grid[i][j]==1)? cout << "X" : cout << "O";
        cout << "\n";
    }
}

bool isWinner(int turn, int r, int c){
    int dr[]{1,0,1,-1};
    int dc[]{1,1,0,1};

    int path{}, nr{r}, nc{c};
    for(int i{r!=c}; i<3; ++i){
        for(int j=0; j<N; ++j){
            nr = (nr + dr[i]) % N;
            nc = (nc + dc[i]) % N;
            path += (grid[nr][nc] == turn + 1);
            if(path==N)
                return true;
        }
        path=0, nr=r, nc=c;
    }

    if(r+c == N-1){ // special handling for right diagonal
        path = 0, nr = r, nc = c;
        for(int i=0; i<N; i++){
            nr = (nr+dr[3]) % N;
            if(nr<0) nr+=N;
            nc = (nc+dc[3]) % N;

            path += (grid[nr][nc] == turn + 1);
        }
    }
    return path == N;
}

bool play(int turn){
    char sympol{};
    (!turn) ? sympol = 'x' : sympol = 'o';
    cout << "Player " << sympol << " turn. Enter empty location (r, c): ";

    int r,c;
    cin >> r >> c;

    if(1>r || r>N || 1>c || c>N || grid[--r][--c]){
        cout << "Invalid input. Try again\n";
        return play(turn);
    }else
        grid[r][c] = turn + 1;

    return isWinner(turn, r,c);
}

void Run(){
    cout << "Enter grid dimension: "; cin >> N;
    int turn{}, steps{};
    while(true){
        print();
        if(steps == N*N){
            cout << "tie\n";
            break;
        }
        if(play(turn)){
            if(!turn)
                cout << "Player X won\n";
            else
                cout << "Player O won\n";
            print();
            break;
        }
        turn = !turn;
        steps++;
    }
}

int main(){
    //TOE game(10, 5);
    //game.play();

    Run();


    return 0;
}

/*
tie
3
1 1
1 3
1 2
2 2
3 2
2 1
2 3
3 3
3 1


X won
3
1 1
1 3
1 2
2 1
2 2
3 3
3 2

O won
3
1 1
1 3
1 2
2 1
2 2
3 3
3 1
2 3
*/
