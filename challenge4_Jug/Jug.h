//
// Created by jerrywang on 2020/6/2.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef CHALLENGE4_JUG_JUG_H
#define CHALLENGE4_JUG_JUG_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Vertex{
    pair<int, int> jugs;
    pair<int, int> neighbor[6];
    string label;
    int distance;
    Vertex* prev;

    Vertex(): label(""), distance(INT_MAX), prev(nullptr){};
    ~Vertex(){};
};

class Jug {
private:
    int capA;
    int capB;
    int goal;
    int costFillA;
    int costFillB;
    int costPourAB;
    int costPourBA;
    int costEmptyA;
    int costEmptyB;
    vector<Vertex> vertexList;
public:
    Jug(int,int,int,int,int,int,int,int,int);
    ~Jug();

    //solve is used to check input and find the solution if one exists
    //returns -1 if invalid inputs. solution set to empty string.
    //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
    //returns 1 if solution is found and stores solution steps in solution string.
    int solve(string &solution);
private:
    void fillA(Vertex&);
    void fillB(Vertex&);
    void pourAB(Vertex&);
    void pourBA(Vertex&);
    void emptyA(Vertex&);
    void emptyB(Vertex&);
    bool stateExists(Vertex&);
    void createGraph(vector<Vertex>&);
    void shortestPath();
    int location(Vertex&);
};


#endif //CHALLENGE4_JUG_JUG_H
