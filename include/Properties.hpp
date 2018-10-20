#pragma once

#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "PropertiesValue.hpp"

class Properties : public PropertiesValue
{
    private:
        std::string fileName;        
        const std::vector<std::string> split(const std::string&, const char&);
        void parse(const std::string& line);
    public:
        Properties(const std::string &);
        void save(const std::string &filename = "");
};