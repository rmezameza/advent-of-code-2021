#include <iostream>
#include "../filereader.h"

int main()
{
    FileReader file_reader{"input.txt"};
    std::vector<std::string> inputs{file_reader.getStringData()};
    std::vector<int> input_numbers;

    std::vector<int> sums;
    int count_increasings{0};

    for (std::string str_line : inputs)
    {
        input_numbers.push_back(std::stoi(str_line));
    }

    for (int i{1}; i < input_numbers.size() - 1; ++i)
    {
        sums.push_back((input_numbers.at(i - 1) + input_numbers.at(i) + input_numbers.at(i + 1)));
    }

    for (int i{0}; i < (sums.size() - 1); ++i)
    {
        if (sums.at(i) < sums.at(i + 1))
        {
            ++count_increasings;
        }
    }

    std::cout << "There are >> " << count_increasings << " << sums that are larger than the previous sum\n";

    return 0;
}