#include <iostream>
#include <string>
#include <vector>
#include "ttt.hpp"

std::vector<std::string> start_grid(){

    std::vector<std::string> start_grid = {};
  for (int i = 1; i < 10; i++){
    start_grid.push_back(std::to_string(i));
  }
    return start_grid;

}

void display_grid(std::vector<std::string> grid){

    std::cout << "     *     *     \n";
  std::cout << "  " + grid[0] + "  *  " + grid[1] + "  *  " + grid[2] + "  \n";
  std::cout << "     *     *     \n";
  std::cout << "*****************\n";
  std::cout << "     *     *     \n";
  std::cout << "  " + grid[3] + "  *  " + grid[4] + "  *  " + grid[5] + "  \n";
  std::cout << "     *     *     \n";
  std::cout << "*****************\n";
  std::cout << "     *     *     \n";
  std::cout << "  " + grid[6] + "  *  " + grid[7] + "  *  " + grid[8] + "  \n";
  std::cout << "     *     *     \n";
  
}

void play_game(std::vector<std::string> &game_grid){

//initialise variables for gameplay
int player = 0;
std::vector<std::string> symbols = {"X", "O"};
int choice;
int turn_count = 0;

while (turn_count < 9){
//get player input
std::cout << "Player " << player+1 << " turn.\nChoose a numbered square to play.\nYour symbol is " + symbols[player] + ".\n";
std::cin >> choice;

//check for valid choice
if (choice < 1 || choice > 9){
  std::cout << "That is not a valid numbered square.\n";
  //toggle player to remain that players turn
  player = !player;
  turn_count--;
} else if (game_grid[choice - 1] == "X" || game_grid[choice - 1] == "O") {
  std::cout << "That square is already taken.\n";
  //toggle player to remain that players turn
  player = !player;
  turn_count--;
} else {
  game_grid[choice - 1] = symbols[player];
}
display_grid(game_grid);
if (check_win(game_grid, symbols[player])){
    std::cout << "Player " << player+1 << " wins!\n";
    break;
}
turn_count++;
player = !player;
}
if (!check_win(game_grid, symbols[player])){ 
    std::cout << "Game Over! It's a draw!\n";
}
}

bool check_win(std::vector<std::string> check_grid, std::string check_symbol){
    std::string win_cond = check_symbol + check_symbol + check_symbol;
    std::vector<std::string> win_lines;
    //horizontal win lines
    win_lines.push_back(check_grid[0]+check_grid[1]+check_grid[2]);
    win_lines.push_back(check_grid[3]+check_grid[4]+check_grid[5]);
    win_lines.push_back(check_grid[6]+check_grid[7]+check_grid[8]);
    //vertical win lines
    win_lines.push_back(check_grid[0]+check_grid[3]+check_grid[6]);
    win_lines.push_back(check_grid[1]+check_grid[4]+check_grid[7]);
    win_lines.push_back(check_grid[2]+check_grid[5]+check_grid[8]);
    //diagonal win lines
    win_lines.push_back(check_grid[0]+check_grid[4]+check_grid[8]);
    win_lines.push_back(check_grid[2]+check_grid[4]+check_grid[6]);
    for (std::string line:win_lines){
        if (line == win_cond){
            return true;
        }
    }
    return false;
}