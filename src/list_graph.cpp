#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct vertices
{
    int index;
    vertices(int num):index(num){};
};


class GraphAdjList{
    private:
    unordered_map<vertices *, vector<vertices *>> map;

    public:
    GraphAdjList(const vector<vector<vertices *>> &edges){
        for(const vector<vertices *> edge:edges){
            addVert(edge[0]);
            addVert(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }
    int size() {
        return map.size();
        }

    void addVert(vertices * vert){
        if(map.count(vert))
            return;
        map[vert] = vector<vertices *>();
    }

    void addEdge(vertices *vert1, vertices *vert2){
        if((map.count(vert1)||map.count(vert2)||vert1 != vert2)){
            map[vert1].push_back(vert2);
            map[vert2].push_back(vert1);
        }
        else{
            cout<<"no vert"<<endl;
            return;
        }
    }

    void removeVert(vertices *vert){
        if(!map.count(vert))
            return;
        map.erase(vert);
        for(auto &pair: map){
            for (int i = 0; i <pair.second.size(); i++) {
                if(pair.second[i] == vert)
                pair.second.erase(pair.second.begin() + i);
                break;
            }
        }
    }

    void print(){
        cout<<"-----"<<endl;
        for(const auto &pair : map){
            const auto &key = pair.first;
            const auto &vecs = pair.second;
            cout<<key->index<<":";
            for(int i=0; i<vecs.size();i++)
                cout<<vecs[i]->index<<" ";
            cout<<endl;
        }
    }
};

int main(){
    vertices *vert1 =new vertices(1);
    vertices *vert2 =new vertices(4);
    vertices *vert3 =new vertices(6);
    vertices *vert4 =new vertices(5);
    vector<vertices *> verts = {vert1, vert2, vert3, vert4};
    vector<vector<vertices *>> edges= {
        {vert1, vert2},
        {vert2, vert3},
        {vert3, vert4},
        {vert4, vert1}
        };
    GraphAdjList graph = GraphAdjList(edges);
    graph.print();
}