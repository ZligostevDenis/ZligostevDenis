#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Размер шахматной доски
vector<vector<int>> solutions;

// Функция для проверки, можно ли поставить ферзя на данную позицию
bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для размещения ферзей
void solveNQueens(vector<int>& board, int row) {
    if (row == N) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1);
        }
    }
}

// Функция для вывода решений
void printSolutions() {
    int count = 1;
    for (vector<int>& solution : solutions) {
        cout << "Решение " << count << ":\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (solution[i] == j) {
                    cout << "Q ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        count++;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<int> board(N, 0); // Создание доски

    solveNQueens(board, 0); // Нахождение всех решений

    printSolutions(); // Вывод результатов

    return 0;
}
