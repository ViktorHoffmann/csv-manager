#include "csv_manager_header.h"

void measure_csv(std::string csv_Input_file) {
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
		while (getline(csv_iline, csv_line, ';'))
		{
			csv_cols++;
			csv_defs.push_back(csv_line);
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

	std::vector<std::vector<double>> csv_mtrx();

	csv_Infile.close();
	exe_measure_csv = true;
	std::cout << "Measuring done\n";
}

void read_csv(std::string csv_Input_file) {
	if (exe_measure_csv != true) // check for measurement
	{
		measure_csv(csv_Input_file);
	}

	std::ifstream csv_Infile;
	csv_Infile.open(csv_Input_file);

	std::cout << "Reading csv...\n";

	int i = 0; int j = 0;
	while (csv_Infile.good()) {
		std::string csv_line;
		// Read whole line
		while (getline(csv_Infile, csv_line))
		{
			std::istringstream csv_iline(csv_line);
			// Seperate line by the delimiter
			while (getline(csv_iline, csv_line, ';'))
			{







				/*
				if (j == 1)
				{
					// Column 2
					//todo y[i].push_back(strtod(csv_line.c_str(), NULL));
					i++; j--;
				}
				else if (j == 0)
				{
					// Column 1
					//todo x[i].push_back(strtod(csv_line.c_str(), NULL));
					i++; j++;
				}
				*/
			}
		}
	}
	csv_Infile.close();
	//todo
	/*std::cout << (alt.size() * (vel.size() <= alt.size()) + (vel.size() * (vel.size() > alt.size()))) << " lines parsed\n";
	std::cout << (alt.size() + vel.size()) << " elements parsed\n";*/
	std::cout << "Reading done\n";
}

void write_csv(std::string csv_Output_file) {
	std::cout << "Printing to csv...\n";

	std::ofstream Outfile;
	Outfile.open(csv_Output_file);

	Outfile << "output" << ";" << "csv file" << "\n";

	//parsing loop
	for (int i = 0; i < 10; i++)
	{
		Outfile << "Test" << ";" << "Output" << "\n";
	}
	Outfile.close();

	std::cout << "Printing done\n";
}

int main()
{
	std::string csv_Input_file = "Test.csv";
	std::string csv_Output_file = "output.csv";

	measure_csv(csv_Input_file);
	std::cout << "Columns: " << csv_cols << "Rows: " << csv_rows << std::endl;
	std::cin.get();
	read_csv(csv_Input_file);
	write_csv(csv_Output_file);
}