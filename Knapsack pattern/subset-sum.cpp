//whether a subset is present in the array whose sum is k

//we have to count the number the number of subsets such that their sum is equal to K.....

#include<bits/stdc++.h>
using namespace std;
 int fun(int i,vector<int>&arr,int k){
     if(i==arr.size()) return 0; 
     if(k==0) return 1;
   int nottake= fun(i+1,arr,k);
    int take=0;
     if(arr[i]<=k){
          take=fun(i+1,arr,k-arr[i]); 
     }  
     retunr take|| nottake;
 } 
int main(){
 vector<int>v={1,2,3,4,5};   
 int k=5;
 cout<<fun(0,v,k);
}

//note if there is 0 in the array we have to multiply pow(n,2(*ans) dry run for this test case arr[3]={0,0,1}
