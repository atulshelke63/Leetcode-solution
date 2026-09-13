class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row=0;
        int column=0;
        for (string path:commands){
            if (path=="RIGHT"){
                column+=1;
            }else if (path=="LEFT"){
                column-=1;
            }else if (path=="UP"){
                row-=1;
            }else{
                row+=1;
            }
        }
        return (row*n)+column;
    }
};