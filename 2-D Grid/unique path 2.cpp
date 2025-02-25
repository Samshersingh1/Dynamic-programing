
// here is questions..
/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot 
can only move either down or right at any point in time.An obstacle and space are marked as 1 or 0 respectively
in grid. A path that the robot takes cannot include any square that is an obstacle.Return the number of possible 
unique paths that the robot can take to reach the bottom-right corner.The testcases are generated so that the answer
 will be less than or equal to 2 * 109..........
 */ 
 
 #include<bits/stdc++.h>
 using namespace std; 
 int  NumberofPath(int i,int j,int m,int n,vector<vector<int>>&arr, vector<vector<int>>&dp){ 
    if( i<=m-1 && j<=n-1 && arr[i][j]==1) return 0; 
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0; 
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]= NumberofPath(i,j+1,m,n,arr,dp)+NumberofPath(i+1,j,m,n,arr,dp);  

  } 
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
 int m= obstacleGrid.size();
 int n=obstacleGrid[0].size(); 
 vector<vector<int>>dp(m,vector<int>(n+1,-1));
  return NumberofPath(0,0,m,n,obstacleGrid,dp);
  
} 

  int main(){
     int n,m;
     cin>>n>>m;
     vector<vector<int>>arr;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             cin>>arr[i][j];
         } 
     }    
    // return uniquePathsWithObstacles(arr); 
    vector<vector<int>>dp(m,vector<int>(n,0));    
     
    if(arr[0][0]==1) return 0; 
    dp[0][0]=1;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            if(arr[i][j]==1) dp[i][j]=0;
            else{
                if(i>0) dp[i][j]=dp[i-2][j];
                if(j>0) dp[i][j]=dp[i][j-1];
            } 
         }
     } 
      return dp[m-1][n-1];  //this is our answer.. 
      //tc:o(m*n)
      //sc:: o(m*n)
 }                  
