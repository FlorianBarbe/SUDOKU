#include "sudoku.hpp"
using namespace std;

static bool row_ok(const array<array<int, N>, N>& g, int r, int v) {
    for (int c = 0; c < N; c++)
        if (g[r][c] == v) return false;
    return true;
}
static bool col_ok(const array<array<int, N>, N>& g, int c, int v) {
    for (int r = 0; r < N; r++)
        if (g[r][c] == v) return false;
    return true;
}
static bool box_ok(const array<array<int, N>, N>& g, int r, int c, int v) {
    int r0 = (r / 3) * 3, c0 = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (g[r0 + i][c0 + j] == v) return false;
    return true;
}
static bool can_place(const array<array<int, N>, N>& g, int r, int c, int v) {
    return row_ok(g, r, v) && col_ok(g, c, v) && box_ok(g, r, c, v);
}
static bool find_empty(const array<array<int, N>, N>& g, int& r, int& c) {
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (g[r][c] == 0) return true;
    return false;
}

bool solve(array<array<int, N>, N>& g) {
    int r, c;
    if (!find_empty(g, r, c)) return true;
    for (int v = 1; v <= 9; v++) {
        if (can_place(g, r, c, v)) {
            g[r][c] = v;
            if (solve(g)) return true;
            g[r][c] = 0;
        }
    }
    return false;
}

int count_solutions(array<array<int, N>, N>& g, int limit) {
    int r, c;
    if (!find_empty(g, r, c)) return 1;

    int count = 0;
    for (int v = 1; v <= 9; v++) {
        if (can_place(g, r, c, v)) {
            g[r][c] = v;
            count += count_solutions(g, limit);
            if (count >= limit) {
                g[r][c] = 0;
                return count;
            }
            g[r][c] = 0;
        }
    }
    return count;
}

void print_grid(const array<array<int, N>, N>& g) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cout << g[r][c] << (c == N - 1 ? '\n' : ' ');
    }
}

bool make_unique(array<array<int, N>, N>& grid) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 8);

    int tries = 0;
    while (count_solutions(grid) != 1 && tries < 100) {
        int r = dist(gen);
        int c = dist(gen);
        if (grid[r][c] == 0) {
            array<array<int, N>, N> tmp = grid;
            solve(tmp);
            grid[r][c] = tmp[r][c]; // ajoute une valeur correcte
        }
        tries++;
    }
    return count_solutions(grid) == 1;
}
