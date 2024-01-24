/**
 * @file main.cpp
 * @author jang hun han (janhan@student.42Seoul.kr)
 * @brief
 * @version 0.1
 * @date 2024-01-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "core.hpp"


int main(void)
{
	System system;

	while (system.isOpen())
	{
		system.update();
	}
	return (0);
}
