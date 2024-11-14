#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;   

int main(){
        
    int node,edge;
    
    cin>>node>>edge; //taking input of number of nodes and edges
    vector<pair<int,int>>adjlist[node]; //pair adjacentcy list

    int a,b,wt;
    for(int i=0;i<edge;i++){
        cin>>a>>b>>wt; //push back 2 times beacuse it is undirected graph for directed push back only 1 time
        adjlist[a].push_back(make_pair(b,wt));
        adjlist[b].push_back(make_pair(a,wt));
    }

    int parent[node];
    int key[node];
    bool mstSet[node];

    for(int i=0;i<node;i++){ //initialize all values of key and parent array
        key[i]=MAX;
        mstSet[i]=false;
    }

     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min-heap priority queue(puts minimum value at first/top)

     key[0]=0;
     parent[0]=-1;
     pq.push(make_pair(0,0)); //insert into priorityqueue source node in form of (distance,node)

     

     while(!pq.empty()){
        int prev=pq.top().second; //taking number(value) of current node
        pq.pop(); //removing from priorityqueue
        mstSet[prev]=true; //marking it as visited

        for(auto it:adjlist[prev]){ //finding the adjacent nodes of current node (Dont know how work??)
                                    //interation will be equal to number of adjacent nodes (e.g- node 1 has adj node 2,4) 
                                    //so it runs 2 time
                                    //one for node (2) and another for node (4)

            int next=it.first; //adjacent node number(value)
            int nextDist=it.second; //distance of adjacent node to current node

            if(mstSet[next]==false && nextDist<key[next]){ //key is initially infinite remember (look line 23)
                 parent[next]=prev;
                 key[next]=nextDist;
                
                 pq.push(make_pair(key[next],next)); //push adjacent node to priorityqueue
                                                      //key[next] is weight of adjacent node
                                                      //next is number(value) of adjacent node
            }
            

        }
     }
     int mst_weight=0;
     for(int i=1;i<node;i++){
        mst_weight=mst_weight+key[i];
     }


     cout<<"Edges are : "<<endl;
     for(int i=1;i<node;i++){
        cout<<parent[i]<<"----"<<i<<endl;
     }
    cout<<"Total weight of MST : "<<mst_weight<<endl;
    return 0;
}