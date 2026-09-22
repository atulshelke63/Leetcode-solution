class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int row,int column,int index){
        if (row<0 || column<0 || row>=board.size() || column>=board[0].size()){
            return false;
        }
        if (board[row][column] != word[index]){
            return false;
        }
        if (index == word.size()-1){
            return true;
        }

        char temp=board[row][column];
        board[row][column]='#';

        bool found =
           helper(board,word,row+1,column,index+1) ||
           helper(board,word,row-1,column,index+1) ||
           helper(board,word,row,column+1,index+1) ||
           helper(board,word,row,column-1,index+1);

        board[row][column]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int row=0;row<board.size();row++){
            for (int column=0;column<board[0].size();column++){
                if (board[row][column]==word[0]){
                    if (helper(board,word,row,column,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};