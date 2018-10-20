#include "PropertiesValue.hpp"

PropertiesValue::PropertiesValue()
{
    this->value = "";
}

void PropertiesValue::setValue(const std::string &value)
{
    this->value = value;
}

std::string PropertiesValue::getValue()
{
    return this->value;
}

PropertiesValue *PropertiesValue::get(const std::string &key)
{
    return (this->map.find(key) == this->map.end()) ? nullptr : this->map[key];
}

PropertiesValue *PropertiesValue::add(const std::string &key)
{
    if (this->map.find(key) == this->map.end())
    {
        this->map[key] = new PropertiesValue();
        this->keys.push_back(key);
    }
    return this->map[key];
}

const std::vector<std::string> &PropertiesValue::getAllKeys()
{
    return this->keys;
}

int PropertiesValue::countKey() const
{
    return this->keys.size();
}

void PropertiesValue::foreachKeys(std::function<void(std::string&)> func)
{
    for(std::string & key : this->keys)
    {
        func(key);
    }
}

PropertiesValue::~PropertiesValue()
{
    this->foreachKeys([&](std::string &key)
    {
        delete this->get(key);
    });
}