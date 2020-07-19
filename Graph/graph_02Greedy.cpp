#include<iostream>
#include<algorithm>
#include <vector>
#include<queue>
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

class PrimsPair{
    public:
    int u, par, w;
    PrimsPair(int u, int par, int w){
        this->u = u;
        this->par = par;
        this->w = w;
    }
};

class dijkstraPair{
    public:
    int u, par, w, wsf;
    dijkstraPair(int u, int par, int w, int wsf){
        this->u = u;
        this->par = par;
        this->w = w;
        this->wsf = wsf;
    }
};

void display(vector<vector<Edge>> & graph){
    for(int i = 0; i<graph.size(); i++){
        cout<<i<< " -> ";
        for(Edge e : graph[i]){
            cout<<"(" <<e.v<<", "<<e.w<<" ) ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void addEdge(vector<vector<Edge>> & graph, int u, int v, int w){
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));
}


class compareTo{            
    public :
        bool operator()(const PrimsPair & self, const PrimsPair & other) const{
            return self.w>other.w;      
        }
};


void primsAlgo_01(int src, vector<bool> &vis)
{
    vector<vector<Edge>> primsGraph(N, vector<Edge>());
    priority_queue<PrimsPair,vector<PrimsPair>, compareTo> que;
    
    que.push(PrimsPair(src,-1,0));
    int noOfEdge = 0;
    int noOfVtx = N;

    while (noOfEdge<noOfVtx-1)
    {
        PrimsPair p = que.top();
        que.pop();
        if(vis[p.u]) continue;
        if(p.par != -1){
            addEdge(primsGraph,p.u, p.par, p.w);
            noOfEdge++;
        }
        vis[p.u] = true;
        for (Edge e : graph[p.u])
        {
            if (!vis[e.v])
                que.push(PrimsPair(e.v,p.u,e.w));
        }
    }
    display(primsGraph);
}


//DijkstraAlgo==========================================================================

void dijkstraAlgo_01(int src, vector<bool> &vis)
{
    vector<vector<Edge>> dijkstraGraph(N, vector<Edge>());
    priority_queue<dijkstraPair,vector<dijkstraPair>, compareTo> que;
    
    que.push(dijkstraPair(src,-1,0,0));
    int noOfEdge = 0;
    int noOfVtx = N;

    while (noOfEdge<noOfVtx-1)
    {
        dijkstraPair p = que.top();
        que.pop();
        if(vis[p.u]) continue;
        if(p.par != -1){
            addEdge(dijkstraGraph,p.u, p.par, p.w);
            noOfEdge++;
        }
        vis[p.u] = true;
        for (Edge e : graph[p.u])
        {
            if (!vis[e.v])
                que.push(dijkstraPair(e.v,p.u,e.w,e.w+p.wsf));
        }
    }
    display(dijkstraGraph);
}

void constructGraph()
{
    N = 9;
    graph.resize(N, vector<Edge>());
    vector<vector<int>> edges{
        {0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {7, 8, 7}, {7, 6, 1}, {8, 6, 6}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}, {5, 6, 2}};

    for (vector<int> &e : edges)
        addEdge(graph, e[0], e[1], e[2]);

    vector<bool> vis(N, false);
    // for (int i = 0; i < N; i++)
    // {
    //     if (!vis[i])
    //         primsAlgo_01(0, vis);
    // }

    display(graph);
}
int main(){
    constructGraph();
    return 0;
}