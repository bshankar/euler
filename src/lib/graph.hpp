#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using std::vector;

template <class T, W>
class Graph {
public:
  Graph(int size, bool digraph = false,
                  bool edgeWeights = false,
                  bool nodeWeights = false) {

    adjList.resize(size, vector<T>(0));

    if (edgeWeights)
      edgeWts.resize(size, vector<T>(0));

    if (nodeWeights)
      nodeWts.resize(size);
  }


  void addEdge(T v1, T v2) {
    adjList[v1].push_back(v2);

    if (!digraph)
      adjList[v2].push_back(v1);
  }

  
  bool addEdge(T v1, T v2, W wt) {
    // add a weighted edge between v1 and v2
    addEdge(v1, v2);
    edgeWts[v1].push_back(wt);

      if (!digraph)
        edgeWts[v2].push_back(wt);
  }


  void addNodeWeight(T v, W wt) {
    nodeWts[v] = wt;
  }


  void dfs();
  
  
private:
  vector<vector<T>> adjList, edgeWts;
  vector<W> nodeWts;
};

#endif
