//course schedule-1
#include<bits/stdc++.h>

using namespace std;


//approch-1
//just have to find cycle in a directed graph
/*
  bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis){
        
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,adj,vis,pathVis))return true;
            }
            else if(pathVis[child])return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis))return false;
            }
        }
        
        return true;
            
     
    }

*/

//second approch is to apply topo sort algorithm
 bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indegree(numCourses,0);
        for(auto it:pre){
            indegree[it[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        if(q.size()==0)return false;
        int cnt=0;
        while(!q.empty()){
              int node=q.front();
              q.pop();
             /// cout<<node<<endl;
              cnt++;
              for(auto child:adj[node]){
                  indegree[child]--;
                  if(indegree[child]==0)q.push(child);
                  
              }
        }
       return cnt==numCourses;

    }

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);

    cout<<"working";

return 0;}

