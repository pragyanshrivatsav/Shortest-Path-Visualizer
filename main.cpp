#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    vector<vector<pair<int,int>>> adj;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void displayGraph(){
        cout<<"\nGraph:\n";

        for(int i=0;i<V;i++){
            cout<<i<<" -> ";

            for(auto &edge:adj[i]){
                cout<<"("<<edge.first<<","<<edge.second<<") ";
            }

            cout<<endl;
        }
    }
    void shortestPath(int src){
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<int> dist(V,1e9);

        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;

            pq.pop();

            for(auto &it:adj[node]){
                int adjNode=it.first;
                int weight=it.second;

                if(dis+weight<dist[adjNode]){
                    dist[adjNode]=dis+weight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        cout<<"\nShortest Distance From Node "
            <<src<<":\n";

        for(int i=0;i<V;i++){
            cout<<"Node "<<i
                <<" -> "
                <<dist[i]
                <<endl;
        }
    }
};
int main(){
    int vertices;

    cout<<"Enter Number of Vertices: ";
    cin>>vertices;

    Graph g(vertices);

    int choice;
    do{
        cout<<"\n===== SHORTEST PATH VISUALIZER =====";
        cout<<"\n1. Add Edge";
        cout<<"\n2. Display Graph";
        cout<<"\n3. Run Dijkstra";
        cout<<"\n4. Exit";
        cout<<"\nEnter Choice: ";

        cin>>choice;

        switch(choice){

            case 1:{
                int u,v,w;

                cout<<"Enter Source: ";
                cin>>u;

                cout<<"Enter Destination: ";
                cin>>v;

                cout<<"Enter Weight: ";
                cin>>w;

                g.addEdge(u,v,w);

                cout<<"Edge Added!\n";
                break;
            }

            case 2:
                g.displayGraph();
                break;

            case 3:{
                int src;

                cout<<"Enter Source Node: ";
                cin>>src;

                g.shortestPath(src);
                break;
            }

            case 4:
                cout<<"Thank You!\n";
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

    }while(choice!=4);

    return 0;
}
