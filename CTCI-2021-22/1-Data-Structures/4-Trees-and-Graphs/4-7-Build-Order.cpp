#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph{
  public:
  unordered_map<int, unordered_set<int>> graph;
  void setDependency (int dependent, int dependency){
    graph[dependent].insert(dependency);
  }
  unordered_set<int> getDependency (int dependent){
    return graph[dependent];
  }
};

void display(vector<int> buildOrder){
  cout << "Build Order" <<endl;
  for(int i=0; i<buildOrder.size(); i++){
    cout << buildOrder[i] << "," ;
  }
  cout << endl;
}

unordered_set<int> findNoDependency(Graph& graph, unordered_set<int> &toBuild, unordered_set<int> &alreadyBuilt){
  bool check;
  unordered_set<int> noDependency = toBuild;
  for(auto i:graph.graph){
    check=false;
    for(auto j:i.second){
      if(alreadyBuilt.find(j)==alreadyBuilt.end()){
        check = true;
        break;
      }
    }
    if (check && noDependency.find(i.first)!=noDependency.end()){
      noDependency.erase(noDependency.find(i.first));
    }
  }
  return noDependency;
}


vector<int> buildOrder(Graph& graph, unordered_set<int> &toBuild){
  vector<int> buildList;
  int toBuildSizeChecker = toBuild.size()+1;
  unordered_set<int> noDependency;
  unordered_set<int> alreadyBuilt;
  while(!toBuild.empty()){
    if (toBuildSizeChecker <= toBuild.size()){
      cout << "Cycle detected." << endl ;
      break;
    }
    toBuildSizeChecker = toBuild.size();
    noDependency = findNoDependency(graph, toBuild, alreadyBuilt);
    for(auto x: noDependency){
      buildList.push_back(x);
      alreadyBuilt.insert(x);
      toBuild.erase(toBuild.find(x));
    }
  }
  return buildList;
}

int main(){
  Graph graph;
  unordered_set<int> toBuild;
  for(int i=0;i<7;i++){
    toBuild.insert(i);
  }
  graph.setDependency(1,2);
  // graph.setDependency(2,1);
  graph.setDependency(2,3);
  graph.setDependency(4,3);
  graph.setDependency(5,6);
  graph.setDependency(2,6);
  display(buildOrder(graph, toBuild));
  return 0;
}