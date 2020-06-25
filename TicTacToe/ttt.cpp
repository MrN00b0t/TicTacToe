#include <iostream>
#include <string>
#include <vector>
#include "ttt.hpp"

int main() {

std::vector<std::string> grid = start_grid();
display_grid(grid);
play_game(grid);

}