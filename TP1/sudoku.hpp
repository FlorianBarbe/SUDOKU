#pragma once
#include <vector>
using namespace std;

struct sudoku {
protected:
	int MAX=9;
	vector<vector<int>> grille;
	
public:
	sudoku() : grille(9, vector<int>(9, 0)) {} 	
	sudoku(const vector<vector<int>>& g) : grille(g) {};
	};
	vector<vector<int>> getg() { return grille; }

};