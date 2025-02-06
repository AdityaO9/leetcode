class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector <int> hor(rows,0);
        vector <int> ver(cols,0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    hor[i]++;
                    ver[j]++;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(hor[i]>0 || ver[j]>0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};