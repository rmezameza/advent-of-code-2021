#include <iostream>
#include <algorithm>

#include "../filereader.h"

int main() {
    FileReader fileReader{ "input.txt" };
    std::vector<std::string> str_lines{fileReader.getStringData()};

    std::vector<std::string> directions;
    std::vector<int> direction_values;

    int forward{ 0 };
    int depth{ 0 };

    std::for_each(str_lines.begin(), str_lines.end(),
        [&](std::string line) {

            std::size_t pos{ line.find(" ") };
            std::size_t length{ pos - 0 };

            directions.push_back(line.substr(0, length));
            direction_values.push_back(std::stoi(line.substr(pos)));
        });


    for(int i{ 0 }; i < directions.size(); i++) {
        if(directions.at(i) == "forward") {
            forward += direction_values.at(i);
        }
        else if(directions.at(i) == "down") {
            depth += direction_values.at(i);
        }
        else {
            depth -= direction_values.at(i);
        }
    }

    std::cout << "Muliply final depth position by final horizontal position: " << forward * depth << "\n";

    return 0;
}