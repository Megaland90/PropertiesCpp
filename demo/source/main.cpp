#include <Properties/Properties.hpp>

int main()
{
    Properties *config = new Properties("./config");

    std::cout << "Name : " <<  config->get("name")->getValue() << std::endl;
    std::cout << "Key : " <<  config->get("key")->getValue() << std::endl;
    std::cout << "Key.parent : " <<  config->get("key")->get("parent")->getValue() << std::endl;
    std::cout << "key.child : " <<  config->get("key")->get("child")->getValue() << std::endl;

    delete config;
}