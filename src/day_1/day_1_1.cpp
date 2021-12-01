#include "../filereader.h"
#include <iostream>

int main() {
  FileReader file_reader{ "input.txt" };
  std::vector<int> input_numbers{ file_reader.stringToInt(file_reader.getStringData()) };

  int count_increasing{ 0 };

  for (int i{ 0 }; i < input_numbers.size() - 1; ++i) {
    if (input_numbers.at(i + 1) > input_numbers.at(i)) {
      ++count_increasing;
    }
  }

  std::cout << "There are >> " << count_increasing << " << measurements larger than the previous measurement.\n";

  return 0;
}