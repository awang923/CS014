////
//// Created by jerrywang on 2020/6/2.
//// Copyright (c) 2020 anniewang. All rights reserved.
////
//

//help from previous student and zybooks

#include "Jug.h"
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA){
    capA = Ca;
    capB = Cb;
    goal = N;
    costFillA = cfA;
    costFillB = cfB;
    costEmptyA = ceA;
    costEmptyB = ceB;
    costPourAB = cpAB;
    costPourBA = cpBA;
}
Jug::~Jug(){
    return;
}
//solve is used to check input and find the solution if one exists
//returns -1 if invalid inputs. solution set to empty string.
//returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
//returns 1 if solution is found and stores solution steps in solution string.
int Jug::solve(string& solution){
    stringstream ioSS;
    stack <Vertex*> path2Solution;
    int pathLength = 0;
    if(capA <= 0 || capB <= 0 || goal < 0 || costFillA < 0 ||  costFillB < 0 || costEmptyA < 0 || costEmptyB < 0 ||
    costPourAB < 0 || costPourBA < 0){
        solution = "";
        return -1;
    }


    if(goal > capB || !(capA <= capB) || !(capB <=1000)){
        solution = "";
        return -1;
    }
    createGraph(vertexList);
    //search for solution
    bool found = false;
    int inD;
    for (unsigned i = 0; i < vertexList.size(); i++){
        if(vertexList.at(i).jugs.second == goal && vertexList.at(i).jugs.first == 0){
            found = true;
            inD = i;
            break;
        }
    }
    if(!found){
        solution = "";
        return 0;
    }
    shortestPath();
    Vertex* position = &vertexList.at(inD);
    pathLength = position->distance;
    while(position != nullptr){
        path2Solution.push(position);
        position = position->prev;
    }
    while(path2Solution.size() - 1 != 0){
        Vertex* curr = path2Solution.top();
        path2Solution.pop();
        Vertex* b4 = path2Solution.top();
        if(b4 == &vertexList.at(curr->neighbor[0].first)){
            ioSS << "fill A" << endl;
        }
        else if(b4 == &vertexList.at(curr->neighbor[1].first)){
            ioSS << "fill b" << endl;
        }
        else if(b4 == &vertexList.at(curr->neighbor[2].first)){
            ioSS << "empty A" << endl;
        }
        else if(b4 == &vertexList.at(curr->neighbor[3].first)){
            ioSS << "empty B" << endl;
        }
        else  if(b4 == &vertexList.at(curr->neighbor[4].first)){
            ioSS << "pour A B" << endl;
        }
        else if(b4 == &vertexList.at(curr->neighbor[5].first)){
            ioSS << "pour B A" << endl;
        }
    }
    ioSS << "success " << pathLength;
    solution = ioSS.str();
    return 1;
}

void Jug::fillA(Vertex& n){
    n.jugs.first = capA;
}
void Jug::fillB(Vertex& n){
    n.jugs.second = capB;

}
void Jug::pourAB(Vertex& n){
    while(n.jugs.first != 0){
        if(n.jugs.second == capB){
            return;
        }
        n.jugs.second++;
        n.jugs.first--;
    }
}
void Jug::pourBA(Vertex& n){
    while(n.jugs.second != 0){
        if(n.jugs.first == capA){
            return;
        }
        n.jugs.first++;
        n.jugs.second--;
    }
}
void Jug::emptyA(Vertex& n){
    n.jugs.first = 0;
}
void Jug::emptyB(Vertex& n){
    n.jugs.second = 0;
}
void Jug::createGraph(vector<Vertex>& vertecies){
    Vertex start;
    Vertex currState;
    vertecies.push_back(start);
    for(unsigned i = 0; i < vertecies.size(); i++){
        currState = vertecies.at(i);
        Vertex fa = currState;
        Vertex fb = currState;
        Vertex ea = currState;
        Vertex eb = currState;
        Vertex pab = currState;
        Vertex pba = currState;

        fillA(fa);
        fillB(fb);
        emptyA(ea);
        emptyB(eb);
        pourAB(pab);
        pourBA(pba);

        if(!stateExists(fa)) {
            fa.label = "fill A";
            vertecies.push_back(fa);
        }
        if(!stateExists(fb)) {
            fb.label = "fill B";
            vertecies.push_back(fb);
        }
        if(!stateExists(ea)) {
            ea.label = "empty A";
            vertecies.push_back(ea);
        }
        if(!stateExists(eb)) {
            eb.label = "empty B";
            vertecies.push_back(eb);
        }
        if(!stateExists(pab)) {
            pab.label = "pour A B";
            vertecies.push_back(pab);
        }
        if(!stateExists(pba)) {
            pba.label = "pour B A";
            vertecies.push_back(pba);
        }
        currState.neighbor[0] = pair<int, int>(location(fa),costFillA);
        currState.neighbor[1] = pair<int, int>(location(fb),costFillB);
        currState.neighbor[2] = pair<int, int>(location(ea),costEmptyA);
        currState.neighbor[3] = pair<int, int>(location(eb),costEmptyB);
        currState.neighbor[4] = pair<int, int>(location(pab),costPourAB);
        currState.neighbor[5] = pair<int, int>(location(pba),costPourBA);
        vertecies.at(i) = currState;
    }

}
bool Jug::stateExists(Vertex& v){
    for (unsigned i = 0; i < vertexList.size(); i++) {
        if(v.jugs.first == vertexList.at(i).jugs.first && v.jugs.second == vertexList.at(i).jugs.second){
            return true;
        }
    }
    return false;
}

int Jug::location(Vertex& n){
    for (unsigned i = 0; i < vertexList.size(); i++){
        if(vertexList.at(i).jugs.first == n.jugs.first && vertexList.at(i).jugs.second == n.jugs.second){
            return i;
        }
    }
    return -1;
}

void Jug::shortestPath(){
    Vertex* curr;
    queue<Vertex*> unvisitedQueue;
    for (unsigned i = 0; i < vertexList.size(); ++i){
        vertexList.at(i).distance = INT_MAX;
        vertexList.at(i).prev = 0;
        unvisitedQueue.push(&vertexList.at(i));
    }
    vertexList.at(0).distance = 0;

    while(!unvisitedQueue.empty()){
        curr = unvisitedQueue.front();
        unvisitedQueue.pop();
        for (unsigned i = 0; i < 6; i++) {
            int edgeWeight = curr->neighbor[i].second;
            int altDistance = curr->distance + edgeWeight;
            int adj = curr->neighbor[i].first;
            if (altDistance < vertexList.at(adj).distance){
                vertexList.at(adj).distance = altDistance;
                vertexList.at(adj).prev = curr;
            }
        }
    }
}
