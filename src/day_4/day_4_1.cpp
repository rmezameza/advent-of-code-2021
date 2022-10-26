#include <iostream>
#include <algorithm>

#include "../FileReader.h"

int main() {
    FileReader file_reader{ "input.txt" };
    FileReader file_reader_winning_numbers{ "input_winning_nr.txt"};

    std::vector<std::string> winning_numbers_raw{ file_reader_winning_numbers.getStringData() };
    std::vector<std::string> fields_raw_vec{ file_reader.getStringData() };
    std::string fields_raw {fields_raw_vec.at(0)};
    std::string num;

    std::vector<std::string> winning_numbers;
    std::vector<std::string> field; 
    std::vector<std::vector<std::string>> fields;
    size_t count{ 1 };

    for(const char& c : winning_numbers_raw.at(0)) {
        if(c == ',' || std::isspace(c)) {
            winning_numbers.push_back(num);
            num.clear();
        }
        else {
            num.push_back(c);
        }
    }

    winning_numbers.push_back(num);
    num.clear();

    for(size_t i{ 0 }; i < fields_raw.size(); ++i) {
        if(i > 0 && fields_raw.at(i) == ' ' && fields_raw.at(i - 1) == ' ') {
            continue;
        }

        if(count == 25) {
            fields.push_back(field);
            field.clear();
            count = 1;
        }

        if(fields_raw.at(i) == ' ') {
            field.push_back(num);
            num.clear();
            ++count;
        }
        else {
            if(std::isdigit(fields_raw.at(i))) {
                num.push_back(fields_raw.at(i));
            }
        }
    }

    for(const std::vector<std::string>& vec : fields) {
        for(const std::string& str : vec) {
            std::cout << str << ' ';
        }

        std::cout << "\n\n";
    }


    return 0;
}