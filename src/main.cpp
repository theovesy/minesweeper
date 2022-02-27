#include <iostream>
#include "player/player.h"

int main()
{
	std::cout << "Minesweeper." << std::endl;
	Player player(9,9,5);
	player.play();
	return 0;
}
