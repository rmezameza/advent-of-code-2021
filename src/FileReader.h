/*
  This class reads and provide the data from the files which are given by
  the organizers. 
*/

#include <iostream>
#include <fstream>
#include <vector>

class FileReader {
    private:
        std::string line;
        std::vector< std::string > file_input;

        std::ifstream input_file;

    public:

        FileReader(std::string file) {
            try {
                this->input_file.open(file); 
            }
            
        }
};