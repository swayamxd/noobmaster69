#include<iostream>
#include<queue>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class DirectedGraph{
  private:
  unordered_map<int, unordered_set<int>> adjacentMap;
  
  public:
  void setAdjacent(int fromNode, int toNode){
    adjacentMap[fromNode].insert(toNode);
  }
  unordered_set<int> getAdjacent(int fromNode){
    return adjacentMap[fromNode];
  }
};

bool routeExists(DirectedGraph &graph, int fromNode, int toNode){
  queue<int> notVisited;
  unordered_set<int> visited;
  int currentNode;
  notVisited.push(fromNode);
  while(!notVisited.empty()){
    currentNode = notVisited.front();
    notVisited.pop();
    visited.insert(currentNode);
    for (int adjacentNode: graph.getAdjacent(currentNode)){
      if (adjacentNode == toNode) {
        return true;
      } 
      else if (visited.find(adjacentNode)!=visited.end()){
        notVisited.push(adjacentNode);
      }
    }
  }
  return false;
}

int main(){
  DirectedGraph graph;
  graph.setAdjacent(1,2);
  graph.setAdjacent(1,3);
  graph.setAdjacent(3,4);
  graph.setAdjacent(2,3);
  graph.setAdjacent(4,5);
  graph.setAdjacent(2,5);
  graph.setAdjacent(5,6);
  cout << (routeExists(graph, 3,5)? "Route exists" : "Route doesn't exist") << endl;
  return 0;
}