#include "Main.hpp"
#include "Properties.hpp"

int Main::main(const int ac, const std::string *av)
{
    if (ac == 2)
    {
        Properties properties(av[1]);
        properties.get("zia")->foreachKeys([](std::string & key)
        {
            std::cout << key << std::endl;
        });
        std::cout << properties.get("zia")->get("root")->getValue() << std::endl;
        
        properties.add("test")->setValue("ok");
        properties.save("test.properties");
    }
    else
    {
        std::cerr << "Usage : " << av[0] << " [configFile]" << std::endl;
    }
    return (0);
}