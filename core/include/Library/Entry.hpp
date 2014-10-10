#ifndef LIBRARY_ENTRY_HPP
#define LIBRARY_ENTRY_HPP

#include <string>
#include <vector>

namespace Library
{

class Entry
{
public:
    virtual const std::string & get_title() const = 0;
    virtual const std::vector<std::string> & get_authors() const = 0;
};

}

#endif
