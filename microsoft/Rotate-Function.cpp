#include<bits/stdc++.h>

using namespace std;


 int maxRotateFunction(vector<int>& nums) {
 	
 	    
    // TLE 

    // int n=nums.size(), mx=INT_MIN;
    // for(int k=0; k<n; k++){
    //     int sum = 0;
    //     for(int i=0; i<n; i++){
    //         sum += i*nums[(i+k)%n];
    //     }
    //     mx = max(mx, sum);
    // }
    // return mx;


    // Optimized

    // sum = 1A + 1B + 1C + 1D

    // f(0) = 0A + 1B + 2C + 3D
    // f(1) = 0D + 1A + 2B + 3C

    // f(1) - f(0) = 1A + 1B + 1C - 3D = (1A + 1B + 1C + 1D) - 4D = sum - n*nums[n-1]
    // f(1) = f(0) + sum - n*nums[n-1]
       // int sum=0;
        // int F=0;//F0
        // vector<int>dp(nums.size()+1,0);
        // for(int i=0;i<nums.size();i++){
        //     dp[0]+=i*nums[i];
        //     sum+=nums[i];

        // }
        // int n=nums.size(),maxm=dp[0];
        // for(int i=1;i<=n;i++){
        //     dp[i]=dp[i-1]+sum-n*(nums[n-i]);
        //     maxm=max(maxm,dp[i]);

        // }
        // return maxm;
        int sum=0,F=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            F+=i*nums[i];//F0
            sum+=nums[i];
        }
        int maxm=INT_MIN;
        for(int i=1;i<=n;i++){
            F=F+sum-n*(nums[n-i]);
            maxm=max(maxm,F);
        }
        return maxm;
    }


int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);

   vector<int>v={4,3,2,6};
   cout<<maxRotateFunction(v);
   
return 0;}

