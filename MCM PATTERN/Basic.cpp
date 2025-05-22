 

 /* 
    HERE ARE SOME BASIC STEPS TO RECONGNISE A MCM PROBLEM IN DYNAMIC PROGRAMING....  
    1. there will be a partition on array or string....(feel aayegi partition karne ki..)
    2. diffrent type of value in the expression ...(2*3+5-10)? 
    3. most optimal order to partition an array for min/max cost..
    4. check whether an expresion cna be true or not...
 */   


/* 
  STEP TO SOLVE ANY MCM BASED QUESTON ...
  
  step 1 :: recongnise boundry where we have to do partition (i,j) genearrly it will be (0,n-1) but not all the time may be varry question by question
  step 2::  check base case least optimal solution....
  step 3 :: k-loop (i to j but it will differ question wise )  ..IMP STEP..
  step 4::  find ans from temp ans by doing max(ans,tmep)(generally)..   */    


  // QUESTION :: there is an array for which have to find matrix multiplication maximum... and the order of matrix 
  //  for A[i]=A[i-1]*A[i].. 

  // input.. arr[n]={10,20,30,40,50};
  // output will be single integer....


     
#include<bits/stdc++.h>
using namespace std;   

      int fun(int i,int j, vector<int>&arr){
             if(i>=j) return 0;
           int ans=INT_MAX;
           for(int k=i;k<=j-1;k++){
               int temp=fun(i,k,arr) +fun(k+1,j,arr) +arr[i-1]*arr[k]*arr[j]; 
               ans=min(ans,temp);
           }  
           return ans; 
      }
   
     int helper(vector<int>&arr){ 
          int n=arr.size();
         return fun(1,n-1,arr);
     }   

int main(){
     vector<int>arr(5);
     for(int i=0;i<5;i++) cin>>arr[i];
      return helper(arr);
}  //
      














 
  
  
