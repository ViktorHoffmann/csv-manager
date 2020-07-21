#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::string csv_Output_file;
std::string csv_Input_file;
char csv_delimiter;
bool exe_measure_csv;
int csv_cols; int csv_rows;
std::vector<std::string>            csv_idefs;    // input csv title row
std::vector<std::string>            csv_odefs;    // output csv title row
std::vector<std::vector<double>>    csv_imtrx;    // input csv value matrix
std::vector<std::vector<double>>    csv_omtrx;    // output csv value matrix