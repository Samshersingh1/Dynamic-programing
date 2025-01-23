#include<bits/stdc++.h>
// PROBLEM STATEMENT ::  given two array weight and value of items and there is bag with a fixed capacity we have to take the items and put it into bag with maxximum profit.
// there is diffrent type of knapsack is there...
// 1.FRACTIONAL KNAPSACK :: in this we  can take fraction of items too...
//2.0-1 KNAPSACK:: in this knapsack we can only take or not take that item in this fraction will not allow..



using namespace std;

 // this is memosiazation technique
 int maxprofit(int i,vector<int>&weight,vector<int>&value,int w,vector<vector<int>> &dp){
     if(w==0) return 0;
     if(i<0) return 0;
 if(dp[i][w]!=-1) return dp[i][w];   //memosie it 
     if(weight[i]<=w){
            return dp[i][w]=max(value[i]+maxprofit(i-1,weight,value,w-weight[i],dp),maxprofit(i-1,weight,value,w,dp)); // here we are taking the maximum value because we have to maxximise the profit so we see in which path taking or not taking which is giving us max..
           // return  maxprofit(i-1,weight,value,w);
     }
     return  dp[i][w]=maxprofit(i-1,weight,value,w,dp);
 }  

 
int main(){
      int n,w;
      cin>>n>>w; 
   vector<int>weight(n),value(n);
   for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>value[i];
   } 
   vector<vector<int>>dp(n,vector<int>(w+1,0));  // here we are w+1 beacuse we want till the w,   changing parameter will make sure how 2d or 3d which dp requried
 //cout<<maxprofit(n-1,weight,value,w,dp); 


 // this is tabulation technique
  for(int i=0;i<n;i++) dp[i][0]=0;      //initailse the first row en sbko recursive ka base case dekhkr solve karo ache se..
  for(int j=0;j<=w;j++) dp[0][j]=0; //intialise the first colomn...
         
                   for(int i=1;i<n;i++){                // fill the remaing  colomn..
                  for(int j=1;j<=w;j++){   
                     // fill the  remaing rows 
                     if(weight[i]<=j) {      // here we will consider whether to take (i-1) wala index or not ....
                             dp[i][j]=max(value[i]+dp[i-1][j-weight[i]],dp[i-1][j]); 
                           }  
                  else{
                      dp[i][j]=dp[i-1][j];
                  }                 // take the help of table to compute the remaing boxes of the grid
              }  
         } 
         cout<<dp[n-1][w];  // last box.....
}      