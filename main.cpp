#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {

        int x = 0, o = 0;

        // 统计X和O数量
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X')
                    x++;
                else if (board[i][j] == 'O')
                    o++;
            }
        }

        // X先手，数量不符合直接错误
        if (!(x == o || x == o + 1))
            return false;


        bool xWin = false;
        bool oWin = false;


        // 判断三行
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] &&
                board[i][1] == board[i][2]) {

                if (board[i][0] == 'X')
                    xWin = true;
                if (board[i][0] == 'O')
                    oWin = true;
            }
        }


        // 判断三列
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == board[1][j] &&
                board[1][j] == board[2][j]) {

                if (board[0][j] == 'X')
                    xWin = true;
                if (board[0][j] == 'O')
                    oWin = true;
            }
        }


        // 判断主对角线
        if (board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {

            if (board[0][0] == 'X')
                xWin = true;
            if (board[0][0] == 'O')
                oWin = true;
        }


        // 判断副对角线
        if (board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {

            if (board[0][2] == 'X')
                xWin = true;
            if (board[0][2] == 'O')
                oWin = true;
        }


        // 两人同时获胜，不可能
        if (xWin && oWin)
            return false;


        // X获胜时，X必须多一步
        if (xWin) {
            return x == o + 1;
        }


        // O获胜时，数量必须相等
        if (oWin) {
            return x == o;
        }


        return true;
    }
};


int main()
{
    vector<string> board;

    string aRow;

    for(int i=0; i<3; i++)
    {
        getline(cin,aRow);
        board.push_back(aRow);
    }

    bool res=Solution().validTicTacToe(board);

    cout<<(res?"true":"false")<<endl;

    return 0;
}