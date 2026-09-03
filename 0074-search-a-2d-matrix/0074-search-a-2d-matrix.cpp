class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l1=0,h1=matrix.size()-1;
        int r=-1;
        while(l1<=h1){
            int m=l1+((h1-l1)>>1);
            if(matrix[m][0]<=target){
                if(matrix[m][0]==target){
                    return true;
                }
                r=m;
                l1=m+1;
            }else{
                h1=m-1;
            }
        }
        if(r==-1){return false;}
        int l=0,h=matrix[r].size()-1;
        while(l<=h){
            int m=l+((h-l)>>1);
            cout<<matrix[r][m]<<" ";
            if(matrix[r][m]>=target){
                if(matrix[r][m]==target){
                    return true;
                }
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return false;
    }
};