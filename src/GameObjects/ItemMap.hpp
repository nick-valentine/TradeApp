#ifndef ITEM_MAP_HPP
#define ITEM_MAP_HPP

#include <map>
#include <fstream>
#include <string>
#include <sstream>

#include "Globals.hpp"
#include "Services/Logger/Logger.hpp"
#include "GameObjects/Item.hpp"

class ItemMap
{
public:
    static void init(Logger::LoggerPtr logger);
    static void fromStringStream(std::stringstream *ss);
    static void toStringStream(std::stringstream *ss);
    static Item get(int id);
    static std::vector<int> validIds();
private:
    const static std::string filename;
    
    static std::map<int, Item> collection;
};

#endif //ITEM_MAP_HPP
