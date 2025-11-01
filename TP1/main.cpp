#include "sudoku.hpp"
using namespace std;

int main() {
    array<array<int, N>, N> grid{};
    cout << "Entrez la grille (9 lignes de 9 entiers, 0 pour vide):\n";
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> grid[r][c];

    int nb = count_solutions(grid);

    if (nb == 0) {
        cout << "Aucune solution.\n";
        return 0;
    }
    if (nb == 1) {
        cout << "Solution unique :\n";
        solve(grid);
        print_grid(grid);
        return 0;
    }

    cout << "Plusieurs solutions detectees (" << nb << ").\n";
    cout << "Generation d'une grille derivee avec une seule solution...\n";

    if (make_unique(grid)) {
        cout << "Grille modifiee avec une seule solution :\n";
        print_grid(grid);
    }
    else {
        cout << "Echec apres plusieurs tentatives.\n";
    }

    return 0;
}
