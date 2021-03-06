#include "Properties.hpp"

Properties::Properties(const std::string &file)
{
    this->fileName = file;
    std::string line;
    std::ifstream myfile (file);
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            if (line.length() > 0 && line[0] != '#')
                this->parse(line);
        }
        myfile.close();
    }
    else std::cerr << "Unable to open file";
}

void Properties::parse(const std::string& line)
{
    PropertiesValue *last = nullptr;
    bool first = true;
    std::vector<std::string> value = this->split(line, '=');
    std::vector<std::string> tab = this->split(value[0], '.');
    for(std::string &key : tab)
    {
        if (first)
        {
            last = this->add(key);
            last->setValue(key);
            first = false;
        }
        else
        {
            last = last->add(key);
        }
    }
    last->setValue(value[1]);
}

const std::vector<std::string> Properties::split(const std::string& line, const char& c)
{
	std::string buff {""};
	std::vector<std::string> v;
	
	for(auto n: line)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

void Properties::save(const std::string &filename)
{
    std::ofstream myfile;
    (fileName.length() > 0 ) ? myfile.open (filename) : myfile.open (this->fileName);
    std::string path;

    std::function<void(std::string path, PropertiesValue *pr, const std::string &key)> process;
    process = [&process, &myfile](std::string path, PropertiesValue *lastPr, const std::string &key)
        {
            if (path.length() != 0)
            {
                    path += ".";     
            }
            path += key;
            PropertiesValue *pr = lastPr->get(key);
            pr->foreachKeys([&](std::string &key)
            {
                process(path, pr, key);
            });
            if (pr->getValue().length() != 0)
            {
                path += "=" + pr->getValue();
                myfile << path << std::endl;
            }          
        };

    this->foreachKeys([&](std::string &key)
    {
        process(path, this,  key);
    });
    myfile.close();
}