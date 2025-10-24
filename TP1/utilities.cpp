#include <vector>
#include <iostream>
#include "utilities.hpp"
using namespace std;

void affiche_grille(const sudoku& s){
	for (vector<int> colonne : s.getg()) {
		for (int elt : ligne) {
			cout << elt << " ";
		}
		cout << endl;
	}

