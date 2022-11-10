class TreeAncestor {
    int LOG;
    vector < vector < int > > par;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        //Calculating the maximum Power of 2 which satifies 2 ^(LOG) >= n
        while((1 << LOG) <= n) LOG++;
        par.resize(n , vector < int >(LOG));
        // Initilzaing the Parents for the nodes i.e. Ancestor at level 1
        for(int i = 0 ; i < n ; i++) {
            par[i][0] = parent[i];
        }
        // Calculating the ancestors at level equal to different powers of 2
        for(int j = 1 ; j < LOG ; j++) {
            for(int i = 0 ; i < n ; i++) {
                if(par[i][j - 1] == -1) par[i][j] = -1;
                else par[i][j] = par[ par[i][j - 1] ][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // We can express k as sum of powers of 2
        // Calculating node value at each power of 2 corresponding to k gives the kth
        // ancestor
        for(int i = 0 ; i < LOG && node != -1 ; i++) {
            if(k & (1 << i)) {
                node = par[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
