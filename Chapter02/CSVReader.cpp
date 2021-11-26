//
//  CSVReader.cpp
//  CSVReader
//
//  Created by Joseph Rhodes on 11/25/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#include "CSVReader.hpp"
#include <iostream>
#include <sstream>
#include <vector>

CSVReader::CSVReader(const std::string &inputFile)
    : inputFile(inputFile)
    , fileStream(std::ifstream(inputFile))
{
}

bool CSVReader::readLine(std::vector<std::string> &tokens)
{
    std::string line;
    bool hasLine = std::getline(this->fileStream, line) ? true : false;
    tokens.clear();

    if (hasLine)
    {
        auto lineStream = std::stringstream(line);
        std::string cell;

        while(std::getline(lineStream, cell, ','))
        {
            tokens.emplace_back(cell);
        }
    }

    return hasLine;
}
