# csv-manager

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/a15ca6086fb7418a98117763250ae00a)](https://app.codacy.com/gh/ViktorHoffmann/csv-manager?utm_source=github.com&utm_medium=referral&utm_content=ViktorHoffmann/csv-manager&utm_campaign=Badge_Grade_Settings)

C++ csv manager

# Using it:
1. Define the .csv input and output file somewhere (default is input and output.csv respectively)
2. Define the delimiter (dafault is the semicolon)
3. call the functions you want to use:

# Functions:
- measure_csv:
takes the file name & delimiter as inputs and saves the size of the csv file in an empty matrix and the csv titles in another vector

- read_csv:
measures the csv file if it didn't happen before and then parses the values of the csv file into the matrix

- write_csv:
takes the output file name, delimiter, title vector and value matrix as inputs and then writes them into the selected csv file
