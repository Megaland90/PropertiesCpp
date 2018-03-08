#include "ConfigProject.hpp"


ConfigProject::ConfigProject(const std::string &name)
{
    this->name = name;
}

void ConfigProject::setType(const std::string &value)
{
    this->type = value;
}

void ConfigProject::setSource(const std::string &value)
{
    this->source = value;
}

void ConfigProject::setInclude(const std::string &value)
{
    this->include = value;
}

void ConfigProject::setLib(const std::string &value)
{
    this->lib = value;
}

void ConfigProject::setRoot(const std::string &value)
{
    this->root = value;
}

const std::string& ConfigProject::getType() const
{
    return this->type;
}

const std::string& ConfigProject::getSource() const
{
    return this->source;
}

const std::string& ConfigProject::getInclude() const
{
    return this->include;
}

const std::string& ConfigProject::getLib() const
{
    return this->lib;
}


const std::string& ConfigProject::getName() const
{
    return this->name;
}

const std::string& ConfigProject::getRoot() const
{
    return this->root;
}