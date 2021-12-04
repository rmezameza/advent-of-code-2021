#include <iostream>
#include <algorithm>

#include "../FileReader.h"

int main() {
    FileReader fileReader{ "input.txt" };
    std::vector<std::string> binary_numbers{ fileReader.getStringData() };

    std::vector<std::string> oxygen_values { binary_numbers };
    std::vector<std::string> co2_values { binary_numbers };

    std::string oxygen_gen(12, '-');
    std::string co2_scrub(12, '-');

    

    int count { 0 };

     while(true) {

         std::vector<int> zero_counts(12, 0);
        std::vector<int> one_counts(12, 0);
        std::vector<std::string> temp_oxygen;

        
        if(oxygen_values.size() == 1) {
            oxygen_gen = oxygen_values.at(0);
            break;
        }

        std::for_each(oxygen_values.begin(), oxygen_values.end(),
            [&](const std::string& str_line) {
                for(size_t i{ 0 }; i < str_line.length(); i++) {
                    if(str_line.at(i) == '0') {
                        zero_counts.at(i) = zero_counts.at(i) + 1;
                    }
                    else {
                        one_counts.at(i) = one_counts.at(i) + 1;
                    }
                }
            }
        );

        

         if(one_counts.at(count) >= zero_counts.at(count)) {
            std::copy_if(oxygen_values.begin(), oxygen_values.end(), std::back_inserter(temp_oxygen),
            [&](const std::string& str_line) {
                return str_line.at(count) == '1';
            });
        }
        else {
            std::copy_if(oxygen_values.begin(), oxygen_values.end(), std::back_inserter(temp_oxygen),
            [&](const std::string& str_line) {
                return str_line.at(count) == '0';
            });
        }

        oxygen_values = temp_oxygen;

        ++count;

    }

    count = 0;

    while(true) {

        std::vector<int> zero_counts(12, 0);
        std::vector<int> one_counts(12, 0);
        std::vector<std::string> temp_co2;

        std::cout << "Round: " << count << "\n";
        
        if(co2_values.size() == 1) {
            co2_scrub = co2_values.at(0);
            break;
        }

        std::for_each(co2_values.begin(), co2_values.end(),
            [&](const std::string& str_line) {
                for(size_t i{ 0 }; i < str_line.length(); i++) {
                    if(str_line.at(i) == '0') {
                        zero_counts.at(i) = zero_counts.at(i) + 1;
                    }
                    else {
                        one_counts.at(i) = one_counts.at(i) + 1;
                    }
                }
            }
        );

        

         if(one_counts.at(count) >= zero_counts.at(count)) {
            std::copy_if(co2_values.begin(), co2_values.end(), std::back_inserter(temp_co2),
            [&](const std::string& str_line) {
                return str_line.at(count) == '0';
            });
        }
        else {
            std::copy_if(co2_values.begin(), co2_values.end(), std::back_inserter(temp_co2),
            [&](const std::string& str_line) {
                return str_line.at(count) == '1';
            });
        }

        co2_values = temp_co2;

        ++count;

    }

    std::cout << oxygen_gen << "\n";
    
    int oxygen_int{ std::stoi(oxygen_gen, 0, 2) };
    int co2_int{ std::stoi(co2_scrub, 0, 2) };

    std::cout << "Oxygen Generator: " << oxygen_gen << " | " << oxygen_int << "\n";
    std::cout << "Epsilon Rate: " << co2_scrub << " | " << co2_int << "\n";
    std::cout << "Life support rating: " << oxygen_int * co2_int << "\n";

    return 0;
}