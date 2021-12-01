/*
  This class reads and provide the data from the files which are given by
  the organizers.
*/

#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include <string>

class FileReader
{
private:
    std::vector<std::string> input_data;

    std::ifstream input_file;

public:
    FileReader(std::string file)
    {
        try
        {
            this->input_file.open(file);
        }
        catch (const std::exception &e)
        {
            std::cerr << "An error occurred: " << e.what() << "\n";
        }
    }

    std::vector<std::string> getStringData()
    {
        std::string line;

        while (std::getline(this->input_file, line))
        {
            input_data.push_back(line);
        }

        return this->input_data;
    }
};