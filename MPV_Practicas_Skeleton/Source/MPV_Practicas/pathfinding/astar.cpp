#include "astar.h"
#include "../data/data.h"

// operator to compare to nodes using their cost
bool operator<(const Node& a, const Node& b) {
    return a.fCost() > b.fCost();
}

bool operator>(const Node& a, const Node& b) {
    return a.fCost() < b.fCost();
}

bool operator==(const Node& a, const Node& b) {
    return a.IdX == b.IdX && a.IdZ == b.IdZ;
}

class Compare {
public:
    bool operator()(Node* below, Node* above)
    {
        return below->fCost() > above->fCost();
    }
};


bool IsOnVisited(const Node* Current, std::vector<Node*>& Visited)
{
    for (const Node* node : Visited) {
        if (Current->IdX == node->IdX && Current->IdZ == node->IdZ  && Current->fCost() > node->fCost()) {
            return true;
        }
    }
    return false;
}

bool IsOnOpenSet(const Node* Current, std::priority_queue<Node*, std::vector<Node*>, Compare>& OpenSet)
{
   std::priority_queue<Node*, std::vector<Node*>, Compare> tempOpenSet = OpenSet;

    while (!tempOpenSet.empty()) {
        Node* node = tempOpenSet.top();
        tempOpenSet.pop();
        if (Current->IdX == node->IdX && Current->IdZ == node->IdZ && Current->fCost() > node->fCost()) {
            return true;
        }
    }
    return false;
}

// we iterate to check all four neighbours ( we could consider the diagonals too but for simplification we wont
std::vector<GridLocation> GetNeighbours(const GridLocation& Current, const std::vector<std::vector<GridLocation>>& Grid) {
    std::vector<GridLocation> Neighbours;

    // values to get all 4 neighbours
    const int Dx[4] = {1, 0, -1, 0};
    const int Dz[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; ++i) {
        
        const int NewX = Current.IdX + Dx[i];
        const int NewZ = Current.IdZ + Dz[i];

        // check if index is valid
        if (NewX >= 0 && NewX < Grid.size() && NewZ >= 0 && NewZ < Grid[0].size()) {
            if (Grid[NewX][NewZ].EntryCost >= 0) // if grid location is accessible
            {
                Neighbours.push_back(Grid[NewX][NewZ]);
            }
        }
    }
    return Neighbours;
}

// Euclidean distance
float Heuristic(const GridLocation& a, const GridLocation& b) {
    return std::sqrt((a.Location.X - b.Location.X) * (a.Location.X - b.Location.X)
        + (a.Location.Z - b.Location.Z) * (a.Location.Z - b.Location.Z));
}

std::vector<GridLocation> GetPath(const std::vector<std::vector<GridLocation>>& grid, const GridLocation& start, const GridLocation& end) {
    
    std::priority_queue<Node*, std::vector<Node*>, Compare> openSet;
    //std::priority_queue<Node*> openSet;
    std::vector<Node*> Visited;

    openSet.push(new Node(start.Location.X, start.Location.Z,start.IdX, start.IdZ, 0, Heuristic(start, end), nullptr));

    while (!openSet.empty()) { // while not more nodes (or return correct path below)
        Node* current = openSet.top();
        openSet.pop();

        if (current->x == end.Location.X && current->z == end.Location.Z) {
            std::vector<GridLocation> path;
            while (current->parent != nullptr) { // backtrack to get all the path
                path.push_back(grid[current->IdX][current->IdZ]);
                current = current->parent;
            }
            path.push_back(grid[current->IdX][current->IdZ]);
            std::reverse(path.begin(), path.end());
            return path;
        }

        Visited.push_back(current);

        std::vector<GridLocation> neighbours = GetNeighbours(grid[current->IdX][current->IdZ], grid);
        for (const auto& neighbour : neighbours) {
            float gCost = current->gCost + neighbour.EntryCost;
            float hCost = Heuristic(neighbour, end);
            Node* newNode = new Node(neighbour.Location.X, neighbour.Location.Z, neighbour.IdX, neighbour.IdZ ,gCost, hCost, current);

            // check if its already been visited
           if (!IsOnVisited(newNode, Visited) && !IsOnOpenSet(newNode, openSet))
           {
               openSet.push(newNode);
           }
        }
    }

    return {};
}

