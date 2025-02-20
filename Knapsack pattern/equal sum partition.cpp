//here is the problem
// this problem is same as count ot say if there is a subset with sum k is present or not 
//in this problem the key diffrence is that we have to find k=sum/2.. note k sholud be a integerr


#include<bits/stdc++.h>
using namespace std;
 int fun(int i,vector<int>&arr,int k){
     if(i==arr.size()) return 0; 
     if(k==0) return 1;

     if(arr[i]<=k){
        return fun(i+1,arr,k-arr[i])+fun(i+1,arr,k); 
     }  
     else{
         return fun(i+1,arr,k);
     }
 } 
int main(){
 vector<int>v={1,2,3,4,5};   
 int sum=Accumulte(v.begin(),v.end(),0);
  if(sum/2%2!=0) return 0;
  
  cout<<fun(0,v,sum/2); 
}
