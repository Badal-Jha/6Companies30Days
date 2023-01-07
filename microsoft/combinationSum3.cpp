#include<bits/stdc++.h>

using namespace std;

    vector<vector<int>>ans;
    void solve(int start,int k,int n,vector<int>&v){
         if(v.size()==k && n==0){
            ans.push_back(v);
            return;
        }
        if(v.size()>k || start>9)return ;
        
       
       // cout<<start<<n<<endl;
        for(int i=start;i<=9;i++){
            v.push_back(i);
            solve(i+1,k,n-i,v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(1,k,n,v);
       return ans;
        
    }

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);
    int k,n;
    cin>>k>>n;
    
    vector<vector<int>>ans1=combinationSum3(k,n);
    for(int i=0;i<ans1.size();i++){
    	for(int j=0;j<k;j++){
    		cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
 

return 0;}

