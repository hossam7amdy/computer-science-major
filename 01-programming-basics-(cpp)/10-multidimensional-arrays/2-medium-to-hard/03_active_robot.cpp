#include<iostream>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    int cur_row{}, cur_col{};
    while(k--){
        int dir{}, steps{};
        cout << "1 Up\n2 Right\n3 Down\n4 Left\nEnter choice: ";
        cin >> dir;
        cout << "Steps: ";
        cin >> steps;
        switch(dir){
        case 1:
            cur_row = ((cur_row-steps)%n + n) % n;
            cout << "Robot now at (" << cur_row << ", " << cur_col << ")\n";
            break;
        case 2:
            cur_col = (cur_col+steps)%m;
            cout << "Robot now at (" << cur_row << ", " << cur_col << ")\n";
            break;
        case 3:
            cur_row = (cur_row+steps)%n;
            cout << "Robot now at (" << cur_row << ", " << cur_col << ")\n";
            break;
        case 4:
            cur_col = ((cur_col-steps)%m + m) % m;
            cout << "Robot now at (" << cur_row << ", " << cur_col << ")\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }

    return 0;
}
