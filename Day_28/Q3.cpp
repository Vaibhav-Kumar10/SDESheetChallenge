// Problem: The Celebrity Problem
// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;
        while(top < down) {
            // If top knows down, it can not be a celebrity
            if(mat[top][down]) {
                top++;
            }
            // If down knowns top, it can not be a celebrity
            else if(mat[down][top]) {
                down--;
            }
            // If both does not know each other, both cannot be the celebrity
            else {
                top++; down--;
            }
        }
        // Return -1 if no celebrity is found
        if(top > down)
            return -1;
        
        for(int i = 0; i < n; i++) {
            if(i != top && (mat[i][top] == 0 || mat[top][i] == 1))
                return -1;
        }
        return top;

        // int n = mat.size();
        // vector<int> iKnow(n, 0), knowMe(n, 0);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i != j && mat[i][j] == 1){
        //             iKnow[i]++;
        //             knowMe[j]++;
        //         }
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     if(iKnow[i] == 0 && knowMe[i] == n-1)
        //         return i;
        // }
        // return -1;
    }
};
