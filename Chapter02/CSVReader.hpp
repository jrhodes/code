//
//  CSVReader.hpp
//  CSVReader
//
//  Created by Joseph Rhodes on 11/25/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include <string>
#include <fstream>

class CSVReader
{
public:
    CSVReader(const std::string &inputFile);
    bool readLine(std::vector<std::string> &tokens);
private:
    const std::string inputFile;
    std::ifstream fileStream;
};

#endif /* CSVReader_hpp */
