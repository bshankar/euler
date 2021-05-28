#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define DONE 0x7FFF
#define SIZE 15 
int matrix[SIZE][SIZE] = {};
bool masked[SIZE][SIZE] = {};
int cols = 0; // colns that are covered
int sum_ = 0, maxSum = 0, nextCol = -1;

int chooseMax(int row) {
    int maxCol = -1, max_ = 0;
    for (int col = 0; col < SIZE; ++col) {
        if (matrix[row][col] > max_ && !(masked[row][col]) && 
                !((1 << col) & cols)) {
            max_ = matrix[row][col];
            maxCol = col;
        }
    }
    nextCol = maxCol;
    return nextCol; // success?
}


void search(int row, int min_) {

    if (row == SIZE) {
        if (cols == DONE && sum_ > maxSum) {
            maxSum = sum_;
        }

        return;
    }
    
    while (chooseMax(row) != -1) {
        masked[row][nextCol] = true;
        if (matrix[row][nextCol] > min_) {
            int sum__ = sum_, cols_ = cols;
            sum_ += matrix[row][nextCol];
            cols |= 1 << nextCol;
            search(row + 1, min_);
            sum_ = sum__;
            cols = cols_;
        }
    }

    for (int col = 0; col < SIZE; ++col)
        masked[row][col] = false;
}


int main(int argc, const char *argv[]) {
    
    ifstream file("345.txt");
    string row;
    int i = 0;
    while (getline(file, row)) {
        stringstream ss(row);
        int value, j = 0;
        while (ss >> value) {
            matrix[i][j] = value;
            ++j;
        }
        ++i;
    }
    
    int min_ = 999;
    while (!maxSum) {
        search(0, min_);
        min_ -= 25;
    }
    cout << maxSum << endl;
}
