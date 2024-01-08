/**
 * @file Graph.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Graph.hpp"

void	Graph::addNode(int id)
{
	Node node(id);
	node.id = id;
	nodes[id] = node;
}

void	Graph::addEdge(int fromId, int toId, double weight)
{
	Edge edge;
	edge.from = &nodes[fromId];
	edge.to = &nodes[toId];
	edge.weight = weight;
	adjacencyList[fromId].push_back(edge);
}

Graph::Node*	Graph::getNode(int id)
{
	auto it = nodes.find(id);
		if (it != nodes.end()) {
			return &it->second;
		}
		return nullptr;
}

std::list<Graph::Node *> Graph::findPath(int fromId, int toId)
{
	std::list<Node*> path;
	std::queue<Node*> queue;
	std::map<int, bool> visited;
	std::map<int, int> predecessors;
	queue.push(getNode(fromId));
	visited[fromId] = true;
	predecessors[fromId] = -1;
	while (!queue.empty()) {
		Node* current = queue.front();
		queue.pop();
		if (current->id == toId) {
			// 경로를 추적하여 반환
			int crawl = toId;
			path.push_front(getNode(crawl));
			while (predecessors[crawl] != -1) {
				crawl = predecessors[crawl];
				path.push_front(getNode(crawl));
			}
			return path;
		}
		for (auto& edge : adjacencyList[current->id]) {
			if (!visited[edge.to->id]) {
				visited[edge.to->id] = true;
				queue.push(edge.to);
				predecessors[edge.to->id] = current->id;
			}
		}
	}
	return path; // 경로가 없는 경우 빈 리스트 반환
}

size_t Graph::getSize() const
{
	return nodes.size();
}

