#include <iostream>
#include <algorithm>

#include "../filereader.h"

int main()
{
    FileReader file_reader{ "input.txt" };
    std::vector<int> input_numbers{ file_reader.stringToInt(file_reader.getStringData()) };

    std::vector<int> sums;
    int count_increasing{ 0 };

    for (int i{ 1 }; i < input_numbers.size() - 1; ++i) {
        sums.push_back(input_numbers.at(i - 1) + input_numbers.at(i) + input_numbers.at(i + 1));
    }

    for (int i{ 0 }; i < (sums.size() - 1); ++i) {
        if (sums.at(i) < sums.at(i + 1)) {
            ++count_increasing;
        }
    }

    std::cout << "There are >> " << count_increasing << " << sums that are larger than the previous sum.\n";

    return 0;
}