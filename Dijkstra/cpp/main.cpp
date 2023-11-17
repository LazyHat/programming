#include <iostream>
#include <map>
#include <utility>

void insertGraph(std::map<char, std::pair<char, unsigned int>> &map, char begin, char end, unsigned int weight)
{
    map[begin] = std::make_pair(end, weight);
}

void dijkstraAlgorithm(std::map<char, std::pair<char, unsigned int>> &map, char begin, char end)
{
    std::map<char, unsigned int> nodes;
    nodes[begin] = 0;
    for (auto it : map)
    {
        if (it.first == begin)
            nodes[it.second.first] = it.second.second;
    }
}

int main()
{
    std::map<char, std::pair<char, unsigned int>> graph;
    insertGraph(graph, 'A', 'B', 4);
    insertGraph(graph, 'A', 'C', 6);
    insertGraph(graph, 'A', 'D', 2);
    insertGraph(graph, 'D', 'C', 2);
    insertGraph(graph, 'B', 'C', 1);
    insertGraph(graph, 'B', 'F', 2);
    insertGraph(graph, 'C', 'F', 3);
    insertGraph(graph, 'D', 'F', 4);
    dijkstraAlgorithm(graph, 'A', 'F');
}