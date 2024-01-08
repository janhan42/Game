/**
 * @file Ant_simulation.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Ant_simulation.hpp"
#include "Graph.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Ant_simulation");
	window.setFramerateLimit(60);
	Graph graph;
	for (int i = 0; i < 5; ++i) {
		graph.addNode(i);
		Graph::Node* node = graph.getNode(i);
		if (node) {
			if (i % 2 == 0) { // 짝수 ID의 노드에 음식 할당
				node->food = new Food(10.0f, {i * 100.0f, 100.0f}, i); // 동적 할당
				node->hasFood = true;
			} else {
				node->food = new Food(0.0f, {i * 100.0f, 100.0f}, i); // 동적 할당
				node->hasFood = true;
			}
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (int i = 0; i < 5; ++i) {
			Graph::Node* node = graph.getNode(i);
			if (node && node->hasFood) {

				if (!node->food->isConsumed()) // 음식이 남아있음.
					std::cout << "Node " << i << " has food." << std::endl;
				else
					std::cout << "Node " << i << " consumed food." << std::endl;
				// SFML을 사용하여 음식 그리기
				Graph::Node* node = graph.getNode(i);
				node->food->draw(window);
			}
		}

		window.display();
	}
}
