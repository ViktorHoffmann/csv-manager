#include "csv_manager_header.h"

std::string csv_Input_file = "input.csv";
std::string csv_Output_file = "output.csv";
char csv_delimiter = ';';


void measure_csv(std::string csv_Input_file, char csv_delimiter) {
	bool exe_measure_csv = false;

	std::cout << "Measuring csv...\n";

	std::ifstream csv_Infile;
	csv_Infile.open(csv_Input_file);


	if (csv_Infile.good()) {
		std::string csv_line;

		// measure whole row
		getline(csv_Infile, csv_line);
		csv_rows++;

		// Seperate row by the delimiter
		std::istringstream csv_iline(csv_line);
		while (getline(csv_iline, csv_line, csv_delimiter))
		{
			csv_cols++;
			csv_idefs.push_back(csv_line);
		}

		// measure all following rows
		while (getline(csv_Infile, csv_line))
		{
			csv_rows++;
		}
	}
	else
	{
		std::cout << "Problem occured opening the file!\n";
	}

	std::vector<std::vector<double>> csv_imtrx(csv_rows, std::vector<double>(csv_cols));

	csv_Infile.close();
	exe_measure_csv = true;
	std::cout << "Measuring done\n";
}

void read_csv(std::string csv_Input_file, char csv_delimiter) {
	if (exe_measure_csv != true) // check for measurement
	{
		measure_csv(csv_Input_file, csv_delimiter);
	}

	std::ifstream csv_Infile;
	csv_Infile.open(csv_Input_file);

	std::cout << "Reading csv...\n";

	int i = 0;    // row iterator
	int j = 0;    // column iterator
	while (csv_Infile.good()) {
		std::string csv_line;
		// Read whole row
		while (getline(csv_Infile, csv_line))
		{
			std::istringstream csv_iline(csv_line);
			// Seperate row by the delimiter
			while (getline(csv_iline, csv_line, csv_delimiter))
			{
				if (i != 0)    // skip title (csv_idefs)
				{
					csv_imtrx[i][j] = strtod(csv_line.c_str(), NULL);
					j++;
				}
			}
			i++;
		}
	}
	csv_Infile.close();

	std::cout << csv_rows << " rows parsed\n";
	std::cout << csv_imtrx.size() << " elements parsed\n";
	std::cout << "Reading done\n";
}

void write_csv(std::string csv_Output_file, char csv_delimiter) {
	std::cout << "Printing to csv...\n";

	std::ofstream Outfile;
	Outfile.open(csv_Output_file);

	Outfile << "output" << csv_delimiter << "csv file" << "\n";

	//parsing loop
	for (int i = 0; i < 10; i++)
	{
		Outfile << "Test" << csv_delimiter << "Output" << "\n";
	}
	Outfile.close();

	std::cout << "Printing done\n";
}

int main()
{
	measure_csv(csv_Input_file, csv_delimiter);
	read_csv(csv_Input_file, csv_delimiter);
	write_csv(csv_Output_file, csv_delimiter);
	std::cin.get();
}