#include <fstream>
#include "Constants.h"
 using namespace std;
//
// Created by Machine on 06.12.2020.
//
int getRows(std::ifstream& file) {
    std::string line;
    int rows = 0;
    file.clear();
    file.seekg(0);
    while (!file.eof()) {
        getline(file, line);
        ++rows;
    }
    file.clear();
    file.seekg(0);
    return rows;
}

/*
 * -1 - пустая строка
 * 0 - неправильно записана строка
 * иначе - количество столбцов
 */
int getColumns(std::string& row) {
    if (row.length() == 0) {
        return -1;
    } else if (row[0] == ' ') {
        return 0;
    } else {
        int columns = 1;
        int index = 0;
        while (int(row.find(' ', index)) > 0) {
            ++columns;
            index = int(row.find(' ', index)) + 1;
            if (index < row.length() && row[index] == ' ') {
                return 0;
            }
        }
        return columns;
    }
}


void deleteMatrix(char** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char** getNewMatrix(int n) {
    char** matrix = new char*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[i]{};
    }
    return matrix;
}

bool fillRowWithElements(char** matrix, std::string& row, int rowIndex, int n) {
    int rowLength = row.length();
    if (rowLength == n * 2 - 1) {
        for (int i = 0; i < rowLength; ++i) {
            if (i % 2 == 0 && row[i] != ' ') {
                matrix[rowIndex - 1][i / 2] = row[i];
            } else if (i % 2 == 0 && row[i] == ' ' || i % 2 == 1 && row[i] != ' ') {
                return false;
            }
        }
        return true;
    }
    return false;
}

char** getMatrixFromFile(std::ifstream& file, int& n, int& responseCode) {
    n = 0;
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        if (file.tellg() == 0) {
            responseCode = ExceptionsMatrix::FILE_IS_EMPTY;
            return new char *;
        }
        file.clear();
        file.seekg(0);

        std::string line;
        int rowIndex = 0;
        int rows = getRows(file);
        int columns;
        char** matrix = getNewMatrix(rows);

        while (!file.eof()) {
            ++rowIndex;
            getline(file, line);
            if (int(line.find('\r')) > -1) {
                line.erase(line.length() - 1);
            }
            columns = getColumns(line);
            if (columns == -1) {
                responseCode = ExceptionsMatrix::UNPARSEABLE;
                deleteMatrix(matrix, rows);
                return new char*;
            } else if (rows != columns) {
                responseCode = ExceptionsMatrix::NOT_A_QUADRATIC_MATRIX;
                deleteMatrix(matrix, rows);
                return new char*;
            } else if (!fillRowWithElements(matrix, line, rowIndex, rows)) {
                responseCode = ExceptionsMatrix::WRONG_ELEMENT;
                deleteMatrix(matrix, rows);
                return new char*;
            }
        }
        file.clear();
        file.seekg(0);

        n = rows;
        responseCode = ExceptionsMatrix::SUCCESS;
        return matrix;
    } else {
        responseCode = ExceptionsMatrix::FILE_NOT_FOUND;
        return new char*;
    }
}
#include "FillMatrix.h"
