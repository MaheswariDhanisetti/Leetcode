class Solution {
public:
    
    void bfs(vector<vector<int>>&adj ,vector<int>&vis , int node ,int val)
    {
        vis[node] = val;

        queue<int>q;

        q.push(node);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int i = 0;i<adj[curr].size();i++)
            {
                if(vis[adj[curr][i]] == 0)
                {
                    vis[adj[curr][i]] = val;
                    q.push(adj[curr][i]);
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<vector<int>>adj(c+1);

        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(c+1, 0);

        int val = 1;

        for(int i = 1;i<=c;i++)
        {
            if(vis[i]==0)
            {
                bfs(adj, vis,i,val);
                val++;
            }
        }

        vector<set<int>>tmp(val+1);

        for(int i=1;i<=c;i++)
        {
            tmp[vis[i]].insert(i);
        }

        vector<int>res , online(c+1 , 1);

        for(int i = 0;i<queries.size();i++)
        {
            int typ = queries[i][0];
            int st = queries[i][1];

            if(typ==1)
            {
                if(online[st]==1)
                {
                    res.push_back(st);
                }
                else{
                    int gp = vis[st];
                    if(!tmp[gp].empty())
                    {
                        res.push_back(*tmp[gp].begin());
                    }else{
                        res.push_back(-1);
                    }
                }
            }
            else{
                online[st] = 0;
                int gp = vis[st];
                tmp[gp].erase(st);
            }
        }

        return res;
        
    }
};