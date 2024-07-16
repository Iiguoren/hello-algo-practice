#include <vector>
#include <iostream>
using namespace std;

class GraphAdjMat{
    private:
    vector<int> vertices;
    vector<vector<int>> adjMat;

    public:
    GraphAdjMat(vector<int> &verts, vector<vector<int>> &edges){
        for(int vert:verts)
            addVert(vert);
        for (const vector<int> &edge : edges) {
            addEdge(edge[0], edge[1]);
            }
    }

    int size(){
        return vertices.size();
    }

    void addVert(int val){
        vertices.push_back(val);
        adjMat.emplace_back(vector<int>(size(), 0));
        for(vector<int> &row:adjMat)
            row.push_back(0);
    }

    void removeVert(int index){
        if(index >= size()){
            cout<<"out of range"<<endl;
            return;
        }
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        for(vector<int> &row:adjMat)
            row.erase(row.begin() + index);
    }

    void addEdge(int i, int j){
        if(i<0 || j<0 || i>=size()|| j>=size() || i == j){
            cout<<"out of range"<<endl;
            return;
            }
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    void removeEdge(int i, int j){
        if(i<0 || j<0 || i>=size()|| j>=size() || i == j){
            cout<<"out of range"<<endl;
            return;
            }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    void print(){
        for(int i=0; i<size(); i++)
            cout<<vertices[i]<<" ";
        cout<<endl;   
        for(int i=0; i<size(); i++){
            for(int j=0; j<size(); j++)
                cout<<adjMat[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main(){
    vector<int> verts = {1,2,3,4,5};
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        {4,5}
        };
    GraphAdjMat graph = GraphAdjMat(verts, edges);
    graph.print();
    graph.addEdge(1,3);
    cout<<"---------"<<endl;
    graph.print();
    graph.addVert(8);
    cout<<"---------"<<endl;
    graph.print();
    graph.removeVert(5);
    cout<<"---------"<<endl;
    graph.print();
}