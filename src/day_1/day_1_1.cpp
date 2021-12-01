#include <iostream>
#include "../filereader.h"

int main()
{
    FileReader file_reader{"input.txt"};
    std::vector<std::string> inputs{file_reader.getStringData()};
    std::vector<int> input_numbers;

    for (std::string str_line : inputs)
    {
        input_numbers.push_back(std::stoi(str_line));
    }

    int count_increasings{0};

    for (int i{0}; i < (input_numbers.size() - 1); ++i)
    {
        if (input_numbers.at(i + 1) > input_numbers.at(i))
        {
            ++count_increasings;
        }
    }

    std::cout << "There are >>" << count_increasings << "<< increasings\n";

    return 0;
}