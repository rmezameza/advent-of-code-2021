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
        catch (const std::exception& e)
        {
            std::cerr << "An error occurred: " << e.what() << "\n";
        }
    }


    std::vector<std::string> getStringData()
    {
        std::string line;

        while (std::getline(this->input_file, line, 'n'))
        {
            input_data.push_back(line);
        }

        return this->input_data;
    }


    std::vector<int> stringToInt(const std::vector<std::string>& input_string_data)
    {
        std::vector<int> input_int_data;

        for (const std::string& line : input_string_data)
        {
            input_int_data.push_back(std::stoi(line));
        }

        return input_int_data;
    }

    std::vector<std::string> specialParsing(const std::vector<std::string>& input_string_data) {
        std::vector<std::string> complete_vec;
        std::vector<std::string> inside_vec;
        std::string temp_num;

        for(size_t i{ 0 }; i < input_string_data.size(); ++i) {
            if(input_string_data.at(i) == "") {
               complete_vec.at(i) = "-";
               continue;
            }

            for(const char& c : input_string_data.at(i)) {
                if(c == ',' || std::isspace(c)) {
                    temp_num.erase(std::remove_if(temp_num.begin(), temp_num.end(), ::isspace), temp_num.end());
                    complete_vec.push_back(temp_num);
                    temp_num.clear();
                }
                else {
                    temp_num.push_back(c);
                }
            }
            
        }

        return complete_vec;
    }
};