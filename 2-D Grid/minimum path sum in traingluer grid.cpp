//here is the problem
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or 
index i + 1 on the next row.


  //approach  recursion 

  //we can start from last index and go up to i==0 index by taking care of index bound...
    int helper(int i,int j,vector<vector<int>>& triangle) {  
                 if(i==0&& j==0) return triangle[i][j]; 
                  if(i<0 || j<0 || j>=triangle[i].size())  return INT_MAX;    

                  int up=helper(i-1,j,triangle);
                  int down=(j>0)?helper(i-1,j-1,triangle):INT_MAX;
                return triangle[i][j]+min(up,down); 
           }  

  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); 
         int   ans=INT_MAX; 
            for(int j=0;j<triangle[n-1].size();j++) {
                 ans= min(ans,helper(n-1,j,triangle));     
             }   
return ans;
    } 
//tc: o(2^n)..
sc// o(n)..

//space optimastion 
 int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); 
         int   ans=INT_MAX; 
             int m=triangle[n-1].size();
          vector<int>prev(n,INT_MAX),curr(m,INT_MAX);
           prev[0]=triangle[0][0];
           curr[0]=triangle[0][0];
          for(int i=1;i<n;i++){ 
            for(int j=0;j<triangle[i].size();j++){
                int up=prev[j];
                 int down=INT_MAX;
                if(j>0){
                     down=prev[j-1]; 
                } 
                curr[j]=triangle[i][j]+min(up,down);
            }   
            prev=curr;
          }     
 
  for(int i=0;i<prev.size();i++){
      ans=min(ans,prev[i]);
  } 
          return ans;
    }    
}; 
//tc:; o(n^2)
sc:: o(n) because we are storing only single things ..
