/*
   Sources: 
    https://www.educative.io/edpresso/what-is-the-maze-problem - Maze Problem
    https://www.geeksforgeeks.org/check-possible-path-2d-matrix/
    https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/ 0 how to make a 2D vector in C++
*/

#include "escape_zoo.h"
#include <vector>
#include <utility> 
#include <iostream>

using namespace std; 

class Adj { //class to store data on each coordinate of the grid
    public:
        coordinate location;
        bool isWall;
        bool isEscape;

        Adj() {
            location = {0, 0};
            isWall = false;
            isEscape = false;
        }

        Adj(int x, int y) {
            location = {x, y};
            isWall = false;
            isEscape = false;
        }
};

void BFS(grid const &M, coordinate start, Heading facing, Adj **adjMat, bool **norVisited, bool **souVisited, bool **easVisited, bool **wesVisited, motion_plan &route, bool &exitFound, motion_plan &best) {
    
    if(exitFound) return; //if exit has already been found return

    if(adjMat[start.second][start.first].isEscape) {
        //if exit just found now store steps in 'best' vector
        exitFound = true;
        for(int i = 0; i < route.size(); i++)
            best.push_back(route[i]);
        return;
    }

    switch(facing) { //return if visited already
        case North: 
            if(norVisited[start.second][start.first]) {
                route.pop_back();
                return;
            }
            break;
        case South:
            if(souVisited[start.second][start.first]) {
                route.pop_back();
                return;
            }
            break;
        case East:
            if(easVisited[start.second][start.first]) {
                route.pop_back();
                return;
            }
            break; 
        case West:
            if(wesVisited[start.second][start.first]) {
                route.pop_back();
                return;
            }
            break;
    }

    switch(facing) { //set visited to true based on where it is facing
        case North: norVisited[start.second][start.first] = true;
        case South: souVisited[start.second][start.first] = true;
        case East: easVisited[start.second][start.first] = true;
        case West: wesVisited[start.second][start.first] = true;
    }

    if(adjMat[start.second][start.first].isWall) { //if wall return and pop back
        route.pop_back();
        return;
    }

    switch(facing) { //move depending on what direction
        case North:
            route.push_back(go_straight);
            BFS(M, {start.first, start.second-1}, North, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            route.push_back(go_left);
            BFS(M, {start.first-1, start.second}, West, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            break;
        case South:
            route.push_back(go_straight);
            BFS(M, {start.first, start.second+1}, South, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            route.push_back(go_left);
            BFS(M, {start.first+1, start.second}, East, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            break;
        case East:
            route.push_back(go_straight);
            BFS(M, {start.first+1, start.second}, East, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            route.push_back(go_left);
            BFS(M, {start.first, start.second-1}, North, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            break;
        case West:
            route.push_back(go_straight);
            BFS(M, {start.first-1, start.second}, West, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            route.push_back(go_left);
            BFS(M, {start.first, start.second+1}, South, adjMat, norVisited, souVisited, easVisited, wesVisited, route, exitFound, best);
            break;
    }
    route.pop_back(); //if non found pop back
}

motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading) {
    
    //Variable Declaration
    Adj adjMat[M.size()][M[0].size()];
    Adj *adjRow[M.size()];
    bool norVisited[M.size()][M[0].size()];
    bool *norRow[M.size()];
    bool souVisited[M.size()][M[0].size()];
    bool *souRow[M.size()];
    bool easVisited[M.size()][M[0].size()];
    bool *easRow[M.size()];
    bool wesVisited[M.size()][M[0].size()];
    bool *wesRow[M.size()];
    bool exitFound = false;
    motion_plan route;
    motion_plan best;

    //2D Matrices Population
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[0].size(); j++) {
            adjMat[i][j].location.first = j;
            adjMat[i][j].location.second = i;
            norVisited[i][j] = false;
            souVisited[i][j] = false;
            easVisited[i][j] = false;
            wesVisited[i][j] = false;
            if(M[i][j] == 1) 
                adjMat[i][j].isWall = true;
            if(M[i][j] == 0 && (i == 0 || j == 0 || i == M.size() - 1 || j == M[0].size() - 1))
                adjMat[i][j].isEscape = true;
        }
        adjRow[i] = adjMat[i];
        norRow[i] = norVisited[i];
        souRow[i] = souVisited[i];
        easRow[i] = easVisited[i];
        wesRow[i] = wesVisited[i];
    }

    //Breadth First Search
    BFS(M, init_coordinate, init_heading, adjRow, norRow, souRow, easRow, wesRow, route, exitFound, best);
    
    return {best};
}
