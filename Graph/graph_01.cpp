#include<iostream>
#include<vector>
using namespace std;

class Edge{
    public:
        int v;
        int w;
        Edge(int v, int w){
            this->v = v;
            this->w = w;
        }
};
int N;
vector<vector<Edge>> graph;

void addEdge(int u, int v, int w){
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));           // Comment for Directed Graph
}

void addEdge2(int u, int v, int w){
    graph[u].push_back(Edge(v,w));
    
}


void display(){
    for(int i = 0; i<graph.size(); i++){
        cout<<i<< " -> ";
        for(Edge e : graph[i]){
            cout<<"(" <<e.v<<", "<<e.w<<" ) ";
        }
        cout<<endl;
    }
}


int findVertex(int u, int v){
    int idx = -1;
    for(int i = 0; i<graph[u].size(); i++){
        Edge e = graph[u][i];
        if(e.v == v){
            idx  = i;
            return idx;
        }
    }
    return idx;
}

int searchVertex(int u, int v){
    int idx = -1;
    for(int i = 0; i<graph[u].size(); i++){
        Edge e = graph[u][i];
        if(e.v == v)    
    }
}

void removeEdge(int u, int v){
    int idx1 = findVertex(u,v);
    int idx2 = findVertex(v,u);
    graph[u].erase(graph[u].begin()+idx1);
    graph[v].erase(graph[v].begin()+idx2);
}


void removeVtx(int u){
    while(graph[u].size() != 0){
        int v = graph[u][graph[u].size()-1].v;
        removeEdge(u,v);
    }
}

bool hasPath(int src, int dstn, vector<bool> & vis){
    if(src == dstn){
        return true;
    }
    vis[src] = true;
    bool res = false;
    for(Edge e : graph[src]){
        if(!vis[e.v]){
            res = res || hasPath(e.v,dstn,vis);
        }
    }
    return res;
}

int printAllPath(int s, int d , string path,vector<bool> & vis){
    if(s==d){
        cout<<path<<d<<endl;
        return 1; 
    }
    int count = 0;
    vis[s] = true;
    for(Edge e : graph[s]){
        if(!vis[e.v]){
            count += printAllPath(e.v,d,path+to_string(s)+" ",vis);
        }
    }
    vis[s] = false;
    return count;
}

int printAllPathWithCost(int s, int d, string path, vector<bool> & vis, int weight){
    if(s==d){
        cout<<path<<d<<" @ " << weight<<endl;
        return 1;
    }
    int count = 0;
    vis[s] = true;
    for(Edge e : graph[s])
        if(!vis[e.v])
            count += printAllPathWithCost(e.v,d,path+to_string(s)+" ",vis,weight+e.w);
    vis[s] = false;
    return count;
}


class pairPath{
    public:
        int len = 0;        //in terms of edges
        string path = "";
        pairPath(int a, string b){
            len = a;
            path = b;
        }
};

pairPath smallestPath_Edges(int s, int d, vector<bool> & vis){
    if(s == d){
        return pairPath(0,to_string(s));
    }
    vis[s] = true;
    pairPath myans(1e8,"");
    for(Edge e : graph[s]){
        if(!vis[e.v]){
            pairPath recAns = smallestPath_Edges(e.v,d,vis);
            if(recAns.len + 1 < myans.len ){
                myans.len = recAns.len + 1;
                myans.path = to_string(s)+" "+recAns.path;
            }
        }
    }
vis[s] = false;
return myans;

}

//===========CLASS 2 -> 8 JUNE 2020 ==============================================
int hamiltonianPath(int source, int originalSource ,int edgeCount ,string path,vector<bool> & vis){
    if(edgeCount == N-1){
        int idx = findVertex(source,originalSource);
        path += to_string(source);
        if(idx != -1){
            cout<<"Cycle : "<<path<<endl;
        }
        else{
            cout<<"Non-Cycle : "<<path<<endl;
        }
        return 1;
    }
    int count = 0;
    vis[source] = true;
    for(Edge e : graph[source]){
        if(!vis[e.v]){
            count += hamiltonianPath(e.v,originalSource,edgeCount+1,path+to_string(source)+" ",vis);
        }
    }
    vis[source] = false;
    return count;
}

void gcc_(int source, vector<bool> & vis){
    vis[source] = true;
    for(Edge e : graph[source]){
        if(!vis[e.v]){
            gcc_(e.v,vis);
        }
    }
}

void gcc(){
    int count = 0;
    vector<bool> vis(N,false);
    for(int i = 0; i<N; i++){
        if(!vis[i]){
            gcc_(i,vis);
            count++;
        }
    }
}


    //Graph Continue == 10/July/20
    //=======================================================================================
    //BFS.============================================================

void BFS_01(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);
    int desti = 6;

    while (que.size() != 0)
    {
        int rvtx = que.front();
        que.pop();

        vis[rvtx] = true;
        for (Edge e : graph[rvtx])
        {
            if (!vis[e.v])
                que.push(e.v);
        }
    }
}

void BFS_02(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);
    int desti = 6;

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            vis[rvtx] = true;
            for (Edge e : graph[rvtx])
            {
                if (!vis[e.v])
                    que.push(e.v);
            }
        }
        level++;
    }
}

void BFS_03(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);
    int desti = 6;

    int level = 0;
    vis[src] = true;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            for (Edge e : graph[rvtx])
            {
                if (!vis[e.v])
                {
                    vis[e.v] = true;
                    que.push(e.v);
                }
            }
        }
        level++;
    }
}

void GCC_UsingBFS()
{
    vector<bool> vis(N, false);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            BFS_03(i, vis);
            count++;
        }
    }
}


void BFS()
{

    vector<bool> vis(N, false);
    BFS_01(0, vis);
}



// Graph Continue == 12/July/20
    //==========================================================
    //TopoLogical SOrt
    void topo_DFS(int src, vector<bool> & vis, stack<int > & st){
        vis[src] = true;
        for(Edge e : graph[src]){
            if(!vis[e.v]){
                topo_DFS(e.v,vis,st)
            }
        }
        st.push(src);
    }

    void topologicalSort(){
        vector<bool> vis(N, false);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
             if (!vis[i])
                topoDFS(i, vis, st);
        }
    }

    //Topological Sort using BFS or say KAHN's ALGO

    void kahnsAlgo(){
        vector<int> indegree(N,0);
        for(int i = 0; i<N; i++){
            for(Edge e : graph[i]){
                indegree[e.v]++;
            }
        }

        queue<int > qu;
        vector<int > ans;

        for(int ele : indegree){
            if(ele == 0){
                qu.push(ele);
            }
        }

        while(qu.size!=0){
            int rvtx = qu.front();
            qu.pop();
            ans.push_back(rvtx);
            for(Edge e : graph[rvtx]){
                if(--indegree[e.v] == 0)
                    qu.push_back(e.v);
            }
        }

        if(ans.size() != N) cout<<"There is Cycle";
        else {
            for(int ele : ans){
                cout<<ele<<" ";
            }
        }
    }

//======13 JULY 2020==================
// KOSARAJU'S ALGO

void dfs(int src, vector<bool> &vis, vector<vector<Edge>> & graph, vector<int> & res){
    vis[src] = true;
    for(Edge e : graph[src]){
        if(!vis[e.v]){
            dfs(e.v,vis,graph,res);
        }
    }
    res.push_back(src);
}

void kosarajuAlgoFor_SCC(){
    vector<bool> vis(N,false);
    vector<int> res;
    for(int i = 0; i<N; i++){
        if(!vis[i]) dfs(i,vis,graph,res);
    }
    vector<vector<Edge>> gp(N,vector<Edge>());
    for(int i = 0; i<N; i++){
        for(Edge e : graph[i]){
            gp[e.v].push_back(Edge(i,e.w));

        }
    }
    for(int i = 0; i<N; i++) vis[i] = false;
    int count = 1;
    vector<int> vtx;
}


//Kruskal's Algo 15 July 2020=========================================
vector<int > par;
void findPar(int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = findPar(par[u]);
}
void kruskals(int n, vector<vector<int>> & edges){
    for(int i = 0; i<n; i++){
        par.push_back(i);
    }
    for(vector<int> e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        int p1 = findPar(u);
        int p2 = findPar(v);
        if(p1 != p2){
            par[p1] = p2;
            addEdge(u,v,w);
        }
    }
    display();
}


void constructDirectedGraph(){
    N=11;
    graph.resize(N,vector<Edge>());
    addEdge2(0,1,10);
    addEdge2(1,2,10);
    addEdge2(2,3,40);
    addEdge2(3,0,10);
    addEdge2(3,4,2);
    addEdge2(4,5,2);
    addEdge2(4,6,8);
    addEdge2(5,6,3);

    // addEdge(6,0,7);     // Just to Check Hamiltonian
}

void constructGraph(){
    N=7;
    graph.resize(N,vector<Edge>());
    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,0,10);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,8);
    addEdge(5,6,3);

    // addEdge(6,0,7);     // Just to Check Hamiltonian
}
void solve(){
    constructGraph();
    // display();
    // cout<<findVertex(2,1);
    // cout<<"==============================++++++=========="<<endl;
    // removeVtx(3);
    // display();
    vector<bool> vis(N,false);
    // cout<<hasPath(0,30,vis);
    // cout<<printAllPath(0,6,"",vis);
    // cout<<printAllPathWithCost(0,6,"",vis,0);
    // pairPath p = smallestPath_Edges(0, 3, vis);
    // cout << p.path << " @ " << p.len << endl;
    // cout<<hamiltonianPath(0,0,0,"",vis);



}

int main(){
    solve();
    return 0;
}