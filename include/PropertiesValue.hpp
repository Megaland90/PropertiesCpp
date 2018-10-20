#pragma once

#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class PropertiesValue
{
    private:
        std::string value;
        std::vector<std::string> keys;
        std::map<std::string, PropertiesValue*> map;
    public:
        PropertiesValue();
        ~PropertiesValue();
        void setValue(const std::string &);
        std::string getValue();
        const std::vector<std::string> &getAllKeys();
        PropertiesValue *add(const std::string &);
        PropertiesValue *get(const std::string &);
        int countKey() const;
        void foreachKeys(std::function<void(std::string&)>);
};
