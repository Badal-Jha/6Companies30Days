#include<bits/stdc++.h>

using namespace std;

 vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
       sort(nums.begin(),nums.end());
         vector<int>dp(n,1),hash(n,-1);
         int lastIndex=-1,ans=-1;
         for(int i=0;i<n;i++){
             hash[i]=i;
             for(int j=0;j<i;j++){
                 if((nums[i]%nums[j]==0 ) && 1+dp[j]>dp[i]){
                     dp[i]=1+dp[j];
                     hash[i]=j;
                 }
             }
             if(dp[i]>ans){
                 ans=dp[i];
                 lastIndex=i;
             }
         }
         vector<int>res;
         res.push_back(nums[lastIndex]);
        
        while(lastIndex!=hash[lastIndex]){
            lastIndex=hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        reverse(res.begin(),res.end());
        return res;
    }

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);

  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  
  vector<int>res=largestDivisibleSubset(v);
  for(auto x:res)cout<<x<<" ";

return 0;}

