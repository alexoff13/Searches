//
// Created by Machine on 06.12.2020.
//

#ifndef MAIN_CPP_FILLMATRIX_H
#define MAIN_CPP_FILLMATRIX_H

#include <fstream>
#include "Constants.h"

char** getMatrixFromFile(std::ifstream& file, int& n, int& responseCode);
#endif //MAIN_CPP_FILLMATRIX_H
