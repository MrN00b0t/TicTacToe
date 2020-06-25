#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> start_grid();
void display_grid(std::vector<std::string> grid);
void play_game(std::vector<std::string> &game_grid);
bool check_win(std::vector<std::string> check_grid, std::string check_symbol);