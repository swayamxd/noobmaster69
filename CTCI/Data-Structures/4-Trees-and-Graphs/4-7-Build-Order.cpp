#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class buildGraph{
public:
    unordered_map<int,unordered_set<int>> graph;
    void setNode(int dependency, int dependent){
        graph[dependent].insert(dependency);
    }
    unordered_set<int> getNode(int dependent){
        return graph[dependent];
    }
};

void display(vector<int> buildOrder){
    for(auto i=buildOrder.begin();i!=buildOrder.end();i++){
        cout << (*i) << " ; ";
    }
    cout << endl;
}

unordered_set<int> findNoDependency(buildGraph graph, unordered_set<int> toBuild, unordered_set<int> alreadyBuilt){
    bool check;
    unordered_set<int> noDependency = toBuild;
    for(auto i:graph.graph){
        check=false;
        for(auto j:i.second){
            if(alreadyBuilt.find(j)==alreadyBuilt.end()) {
                check = true;
                break;
            }
        }
        if(check && noDependency.find(i.first)!=noDependency.end()){
            noDependency.erase(noDependency.find(i.first));
        }
    }
    return noDependency;
}

vector<int> buildOrder(buildGraph graph, unordered_set<int> toBuild){
    vector<int> buildList;
    int toBuildSizeChecker = toBuild.size()+1;
    unordered_set<int> noDependency;
    unordered_set<int> alreadyBuilt;
    while(!toBuild.empty()){
        if(toBuildSizeChecker <= toBuild.size()) {
            cout << "Cycle in build order detected after : ";
            break;
        }
        toBuildSizeChecker = toBuild.size();
        noDependency = findNoDependency(graph,toBuild,alreadyBuilt);
        for(auto i:noDependency){
            // cout << i << " ; ";
            buildList.push_back(i);
            alreadyBuilt.insert(i);
            toBuild.erase(toBuild.find(i));
        }
        // cout << endl;
    }
    return buildList;
}

int main(){
    buildGraph graph;
    unordered_set<int> toBuild;
    for (int i=1;i<7;i++){
        toBuild.insert(i);
    }
    graph.setNode(1,2);
    // graph.setNode(2,1);
    graph.setNode(2,3);
    graph.setNode(4,3);
    graph.setNode(5,6);
    graph.setNode(2,6);
    cout << "Build Order" << endl;
    display(buildOrder(graph,toBuild));
    return 0;
}