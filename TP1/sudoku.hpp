#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <array>
#include <iostream>
#include <random>

constexpr int N = 9;

bool solve(std::array<std::array<int, N>, N>& grid);
int count_solutions(std::array<std::array<int, N>, N>& grid, int limit = 2);
void print_grid(const std::array<std::array<int, N>, N>& grid);
bool make_unique(std::array<std::array<int, N>, N>& grid);

#endif
