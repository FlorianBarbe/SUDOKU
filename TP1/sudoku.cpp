#include "sudoku.hpp"
#include <vector>
using namespace std;

sudoku::sudoku() { return vector<vector<int>>(MAX, vector<int>(MAX,0)); }