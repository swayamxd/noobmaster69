#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Graph{
    unordered_map<int,unordered_set<int>> graphMap;
public:
    void setAdjacent(int nodeA, int nodeB){
        graphMap[nodeA].insert(nodeB);
        return;
    }
    unordered_set<int> getAdjacent(int nodeA){
        return graphMap[nodeA];
    }
};

bool findRoute(Graph graph, int startNode, int endNode){
    queue<int> unvisitedNodes;
    unordered_set<int> visitedNodes;
    int currentNode;
    unvisitedNodes.push(startNode);
    while(!unvisitedNodes.empty()){
        currentNode = unvisitedNodes.front();
        unvisitedNodes.pop();
        visitedNodes.insert(currentNode);
        for (int node : graph.getAdjacent(currentNode)){
            if(node==endNode) return true;
            if(visitedNodes.find(node)==visitedNodes.end()) unvisitedNodes.push(node);
        }
    }
    return false;
}

int main(){
    Graph newGraph;
    newGraph.setAdjacent(1,2);
    newGraph.setAdjacent(1,3);
    newGraph.setAdjacent(3,4);
    newGraph.setAdjacent(2,3);
    newGraph.setAdjacent(4,5);
    newGraph.setAdjacent(2,5);
    newGraph.setAdjacent(5,6);
    findRoute(newGraph,3,2) ? cout << "Route exists" << endl : cout << "Route dowsn't exist" << endl;
    return 0;
}