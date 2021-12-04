#include <iostream>
#include <algorithm>

#include "../FileReader.h"

int main() {
    FileReader fileReader{ "input.txt" };
    std::vector<std::string> binary_numbers{ fileReader.getStringData() };

    std::string gamma(12, '-');
    std::string epsilon(12, '-');

    std::vector<int> zero_counts(12, 0);
    std::vector<int> one_counts(12, 0);

    std::for_each(binary_numbers.begin(), binary_numbers.end(),
        [&](const std::string& str_line) {
            for(int i{ 0 }; i < str_line.length(); ++i) {
                if(str_line.at(i) == '0') {
                    zero_counts.at(i) = zero_counts.at(i) + 1;
                }
                else {
                    one_counts.at(i) = one_counts.at(i) + 1;
                }
            }
        }
    );

    for(size_t i{ 0 }; i < zero_counts.size(); ++i) {
        if(zero_counts.at(i) > one_counts.at(i)) {
            gamma.at(i) = '0';
        }
        else {
            gamma.at(i) = '1';
        }
    }

    for(size_t i{ 0 }; i < gamma.length(); ++i) {
        if(gamma.at(i) == '0') {
            epsilon.at(i) = '1';
        }
        else {
            epsilon.at(i) = '0';
        }
    }

    

    int gamma_rate{ std::stoi(gamma, 0, 2) };
    int epsilon_rate{ std::stoi(epsilon, 0, 2) };

    std::cout << "Gamma Rate: " << gamma << " | " << gamma_rate << "\n";
    std::cout << "Epsilon Rate: " << epsilon << " | " << epsilon_rate << "\n";
    std::cout << "The power consumption is: " << gamma_rate * epsilon_rate << "\n";

    return 0;
}