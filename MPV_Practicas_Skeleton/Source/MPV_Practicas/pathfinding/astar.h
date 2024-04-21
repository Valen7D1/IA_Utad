#ifndef __ASTAR_H__
#define __ASTAR_H__

#include <CoreMinimal.h>

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>


struct GridLocation;

struct Node {
    int x, z;
    int IdX, IdZ;
    float gCost, hCost;
    Node* parent;

    Node(int _x, int _z, int _idx, int _idz, float _gCost, float _hCost, Node* _parent) : x(_x), z(_z), IdX(_idx), IdZ(_idz), gCost(_gCost), hCost(_hCost), parent(_parent) {}

    float fCost() const {
        return gCost + hCost;
    }
};

bool operator==(const Node& a, const Node& b);
bool operator<(const Node& a, const Node& b);

bool IsOnVisited(const Node* Current, std::vector<Node*>& Visited);
bool IsOnOpenSet(const Node* Current, std::priority_queue<Node*>& OpenSet);



std::vector<GridLocation> GetNeighbours(const GridLocation& current, const std::vector<std::vector<GridLocation>>& grid);

float Heuristic(const GridLocation& a, const GridLocation& b);

std::vector<GridLocation> GetPath(const std::vector<std::vector<GridLocation>>& grid, const GridLocation& start, const GridLocation& end);
#endif