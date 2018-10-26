#include <iostream>
#include <vector>
using namespace std;

int n;

void print_queen(const vector<int>& queen)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queen[i] == j) cout << " X ";
            else cout << " O ";
        }
        cout << endl;
    }
}

bool consistent(int row, int col, const vector<int>& queen)
{
    int k = queen.size();
    for (int i = 0; i < k; i++) {
        if (col == queen[i]) return false;
        if (row == i) return false;
        if (row+col == i+queen[i]) return false;
        if (row-col == i-queen[i]) return false;
    }
    return true;
}

bool recursive_backtracking(vector<int>& queen)
{
    if (queen.size() == n) {
        print_queen(queen);
        return true;
    }
    int row = queen.size(); // select unassigned queen
    for (int col = 0; col < n; col++) {
        if (consistent(row,col,queen)) {
            queen.push_back(col);
            bool result = recursive_backtracking(queen);
            if (result) return result;
            queen.pop_back();
        }
    }
    return false;
}

int main()
{
    cin >> n;
    vector<int> queen;
    recursive_backtracking(queen);
    return 0;
}
