Basic of dynamic progrming ... 
1.recursion (top-down) 
2.tabulation (bottom-up)
3.space optimasatation (most optimal)..

  TYPES OF DP 
  1. 1-D dp :; in dp state there will be only one variable will be there...

// HOW TO APPROACH A DP PROBLEM..
  
STEP 1::  understand question properly and in the question there will be term like (min/max or explore all the possibilities types.) ..
STEP 2::  defind the dp state by the chnging variable . note :: the number of  changing vaiable will be the dimention of the dp..
STEP 3::  declare the trasaction of the dp , How you will calculate the current cell by the help of the previous cells.. (HARDEST STEP IT IS )..
STEP 4:: your answer will be in the last [n] cell...........

 FORMATE OF 1-d TABLE WILL BE 
  vector<int>dp(n+1,-1); //inisalation of the dp table ..
  1. base case define the first cell then 
  for(int i=1;i<=n;i++){
    //by help of the trasaction function we will calculate dp[i]..
  } 
 //at last return ans...
  retunr dp[n];
}   
//THIS IS FORMATE OF 1-d DP TC(O(N))...;
