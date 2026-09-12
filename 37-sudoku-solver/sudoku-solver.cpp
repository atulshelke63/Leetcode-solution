class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char digit){
        for (int i=0;i<9;i++){
           if (board[row][i]==digit){
                return false;
           }
        }
        for (int j=0;j<9;j++){
            if (board[j][col]==digit){
                return false;
            }
        }
        int srow=(row/3)*3;
        int scol=(col/3)*3;
        for (int i=srow;i<srow+3;i++){
            for (int j=scol;j<scol+3;j++){
                if (board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board,int row,int col){
        if (row==9){
            return true;
        }
        int nextrow=row,nextcol=col+1;
        if (nextcol==9){
            nextcol=0;
            nextrow=row+1;
        }
        if (board[row][col]!='.'){
            return sudoku(board,nextrow,nextcol);
        }
        for (char digit='1';digit<='9';digit++){
            if (issafe(board,row,col,digit)){
                board[row][col]=digit;
                if (sudoku(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};