/**
 * @file Graph.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <list>
#include <limits>
#include <iostream>
#include "Food.hpp"

class Graph
{
	public: /* -------- struct ------- */
		struct Node {
			int	id;
			bool hasFood;
			bool hasColony;
			Food *food;

			Node() : id(-1), hasFood(false), food(nullptr) {}
			Node(int id) : id(id), hasFood(false), food(nullptr){}
			~Node() { delete food; }
		};
		struct Edge {
			Node *from;
			Node *to;
			double weight;
		};

	public: /* ---------- func --------- */
		void				addNode(int id);
		void				addEdge(int fromId, int toId, double weight);
		Node*				getNode(int id);
		std::list<Node *>	findPath(int fromId, int toId);
		size_t				getSize() const;


	private:
		std::map<int, Node> nodes;
		std::map<int, std::list<Edge>> adjacencyList;
};
