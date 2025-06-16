class Solution {
public:

    void bfs(int node , vector<vector<int>>vis , vector<vector<int>>&adj ,int &mini ){

        vis[node][0] = node;
        vis[node][1] = 0;

        queue<pair<int,pair<int,int>>>q; //node  , {par , dist}

        q.push({node , {node , 0}});

        while(!q.empty()){
            int node = q.front().first;

            int par = q.front().second.first;

            int currdist = q.front().second.second;

            q.pop();

            for(int i=0;i<adj[node].size();i++){

                if(vis[adj[node][i]][0] !=-1){
                    if(adj[node][i]!=par) mini = min(mini , vis[adj[node][i]][1]+currdist+1);
                }
                else{
                    vis[adj[node][i]] = {node , currdist+1};
                    q.push({adj[node][i] , {node , currdist+1}});
                }

            }


        }

    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>vis(n ,vector<int>(2,-1));

        // for(int i=0;i<n;i++){
        //     cout<<vis[i][0]<<" "<<vis[i][1]<<endl;
        // }

        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            
            bfs(i , vis , adj , mini);
            // cout<<i<<" "<<mini<<endl;
            
        }
        
        return mini==INT_MAX?-1:mini;

    }
};