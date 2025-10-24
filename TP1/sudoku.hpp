#pragma once
#include <vector>
using namespace std;

struct sudoku {
protected:
	int MAX;
	vector<vector<int>> grille;
	
public:
	sudoku() : grille(MAX, vector<int>(MAX, 0)) {};
	//sudoku(int taille);
	vector<vector<int>> getg() { return grille; }

};