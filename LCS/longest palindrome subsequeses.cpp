//we are given two string we have to find the longest common palindromic subsequence...

// input s1="abcdcef", s2="bcdce"
#include<bits/stdc++.h>
using namespace  std;

  int fun(int i,int j,string s1,string s2){
       if(i>=s1.size() || j>=s2.size()) return 0;

       if(s1[i]==s2[j]){
         return 1+fun(i+1,j+1,s1,s2);
       }  
       else{
         return max(fun(i+1,j,s1,s2),fun(i,j+1,s1,s2));
       } 
  }  
int main(){
    string s1="abcdcef";
    string s2="bcdce";
    reverse(s2.begin(),s2.end());

    cout<<fun(0,0,s1,s2); 
    }     