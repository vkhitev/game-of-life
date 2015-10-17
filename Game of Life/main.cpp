/*
   Author: Khitev Vlad
   17.10.2015
   The worst implementation of Game of Life.
   Really.
*/

#include <iostream>
#include "World.h"
#include "Grid.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

const std::vector<std::string> plan = {
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooo+oooooooooo++ooooooooooo",
	"ooooooooooooooooooooooooooooooooooooo+++++oooooo++oooooooooooo",
	"ooooooooooooooooooooooooooooooooooooo+oo++oooooooo+ooooooo++oo",
	"ooooooooooooooooooooooooooooooooooooooo++o+ooooo++oooooo+++o+o",
	"oooooooooooooooooooooooooooooooooooooooooooooooo++ooo+o++ooooo",
	"oooooooooooooooooooooooooooooooooooooooooo+o+oooooo++ooooooooo",
	"ooooooooooooooooooooooooooooooooooooooooooooooo+++o+oooo+ooooo",
	"oooooooooooooooooooooooooooooooooooooooooooo+++ooo+oooo+oooooo",
	"ooooooooooooooooooooooooooooooooooooooooooooo+ooooooo+oooooooo",
	"ooooooooooooooooooooooooooooooooooooooooooooo+oooooo+ooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooo+ooooooooooooo",
	"oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo",
};

int main()
{
	World world(plan);

	world.run();

	std::cin.get();
	return 0;
}