#ifndef LIBRARY_COLLECTION_HPP
#define LIBRARY_COLLECTION_HPP

#include "Library/Author.hpp"

#include <memory>
#include <vector>
#include <map>

namespace Library
{

class Entry;

class Collection
{
public:
    bool empty() const;
    void add_entry(std::shared_ptr<Entry> book);
    std::vector<std::shared_ptr<Entry>> find_entries_from_author(const std::string & name) const;

private:
    std::vector<std::shared_ptr<Entry>> entries_;
    std::map<std::string, Author> authors_;
};

}

#endif
