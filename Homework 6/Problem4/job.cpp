
//sources: 
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
//https://www.youtube.com/watch?v=wQqFQeucFDc - cycle detection using color
//https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/ 
//https://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/ used the isReachable function as reference to go inside of my findSum function 
// https://www.geeksforgeeks.org/sum-dependencies-graph/ -- calculate sum of dependencies for the canRun function

#include "job.h"
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

//Create a graph class to make it easier to detect a cycle in the graph
//referenced the Geeks for Geeks link above on how to properly setup the class
//runs in O(V+E) 
class Graph {
    public: 
      Graph(int Vertices); // is constructor
      void add(int vertices, int placement); //adds edge to the graph
      bool checkCyclic(); // checks if it is cyclic used in canFinish function
      bool findSum(int vert, int i); //used in canRun function 

    protected:
      int vertices; // #vertices of the graph
      list<int> *adjacent; 
      bool cyclicHelperFunction(int vert, bool vistited[], bool *rs); // used as a recursive call to determien true or false 

};

Graph :: Graph (int Vertices) { // constructor that assigns protected variable vertices to Vertices and sets the adjacent pointer to a list on the heap
    this->vertices = Vertices;
    adjacent = new list<int>[Vertices];
}

void Graph :: add(int vertices, int placement) {
    adjacent[vertices].push_back(placement); // add placement to the list of vertices
    return;
}

bool Graph :: cyclicHelperFunction(int vert, bool visited[], bool *rs) { 
  if (visited[vert] == 0) {
    rs[vert] = true;
    visited[vert] = true;
    
    //use a recursive call to check all adjacent vertices
    list<int>::iterator it;
    for (it = adjacent[vert].begin(); it != adjacent[vert].end(); ++it) {
      if(!visited[*it] && cyclicHelperFunction(*it, visited, rs))
        return true;
      else if (rs[*it])
        return true;
    }
  }
  
  rs[vert] = false; //don't recursive call on this vertex again 
  return false; //default statement since true is within the for loop  
} 

bool Graph :: checkCyclic() {
  bool *visited = new bool[vertices];
  bool *rs = new bool[vertices];
  for (int i = 0; i < vertices; i++)
    if(!visited[i] && cyclicHelperFunction(i, visited, rs)) //uses recursion to check the cycle in depth first tree 
      return true;

  return false; //else return false  
}

//similar to the bool Graph :: isReachable function from Geeks for Geeks but calculates total dependenecy sum 
bool Graph :: findSum(int vert, int i) { //part of graph class bc it needs to access the adjacent pointer 
  int sum = 0; 
  bool *visited = new bool[vertices];
  //visited[]={false}; tried to make it like an array where tou can initialize all value to false but didn't work 
  for (int i = 0; i < vertices; i++)
    visited[i] = false; // set all values to false initially 
  
  list<int> que; // generate a list
  que.push_back(vert-1);//pushback the passed in input to the list 
  visited[vert-1] = true; //always increase sum by 1 when visited[vert-1] == true
  sum++; // increase sum by 1

  list<int>::iterator it; // use iterator to go through list

  while(que.empty() != 1) { // make sure the que is not empty 
    for (it = adjacent[que.front()].begin(); it != adjacent[que.front()].end(); ++it){
      if(visited[*it] == false) {
        visited[*it] = true; // because true
        sum++; //increase sum by 1
        que.push_back(*it); // push it back into the list 
      }
    }
    que.pop_front(); //keep removing first element in loop not just at the top of the while loop
  }

  if (sum <= i)
    return true;

  return false;
}

// actual functions for assignment to be used 
bool canFinish(int n, vector<pair<int, int>> &dependencies) { 
  Graph job(n); // creates a graph with n vertices 

  for (int i = 0; i < dependencies.size(); i++) // loop through dependencies and add them as an edge to later be used to check cycle 
    //logic is to put second first since it points the its 
    //adjacent required job first, basically second job -> first job
    //have to subract one so that the vertices start from dependencies '0'
    job.add((dependencies[i].second - 1) , (dependencies[i].first - 1)); //add to graph to check cycle later 

  //use similar to the way geeks for geeks did it but instead of statement to the terminal it is either true or false 
  if(job.checkCyclic() == false)
    return true;

  return false; //if cycle is true then return false
}

//implements the findSum function created by using the Geeks for Geeks fucntion
//but adding the sum to determine if j-1 is greater than i 
bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
  Graph job(n);  // creates a graph with n vertices 
  for (int i = 0; i < dependencies.size(); i++) // loop through dependencies and add them as an edge to later be used to check cycle 
    //logic is to put second first since it points the its 
    //adjacent required job first, basically second job -> first job
    //have to subract one so that the vertices start from dependencies '0'
    job.add((dependencies[i].second - 1) , (dependencies[i].first - 1)); //add to graph to check cycle later 

  //use similar to the way geeks for geeks did it but instead of statement to the terminal it
  //is either true or false 
  return (job.findSum(j, i)) ;
}
