/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth

Problem Link : https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/

*/

class Solution {
public:
    typedef long long int ll;
    struct Edge
    {
        ll vertex;
        ll weight;
    };

    struct compare
    {
        bool operator() (Edge& a , Edge& b)
        {
            return a.weight > b.weight;
        }

    };

    vector < ll > dijkstra(vector < vector < Edge > >& graph , int src)
    {
        priority_queue < Edge , vector < Edge > , compare > pq;
        ll n = graph.size();
        vector < ll > dist(n , INT64_MAX);
        pq.push({src , 0});
        dist[src] = 0;

        while(!pq.empty())
        {
            Edge curr = pq.top();
            int u = curr.vertex;
            int currDist = curr.weight;
            pq.pop();
            
            if(dist[u] < currDist) continue;

            for(auto x : graph[u])
            {
                int v = x.vertex;
                int wt = x.weight;

                if(dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({v , dist[v]});
                }
            }
        }

        return dist;

    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector < vector < Edge > > graph(n);
        vector < vector < Edge > > revGraph(n);
        
        for(auto edge : edges)
        {
            graph[edge[0]].push_back({edge[1] , edge[2]});
            revGraph[edge[1]].push_back({edge[0] , edge[2]});
        }
        vector < ll > d1 = dijkstra(graph , src1);
        vector < ll > d2 = dijkstra(graph , src2);
        vector < ll > d3 = dijkstra(revGraph , dest);
        
        ll ans = INT64_MAX;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(d1[i] == INT64_MAX || d2[i] == INT64_MAX || d3[i] == INT64_MAX) continue;
            else
            {
                ans = min(ans , d1[i] + d2[i] + d3[i]);
            }
        }
        return (ans == INT64_MAX) ? -1 : ans;
    }
};
