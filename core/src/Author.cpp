#include "Library/Author.hpp"
#include "Library/Entry.hpp"
#include <algorithm>

namespace Library
{

Author::Author(std::string name)
    : name_(name)
{
}

std::string Author::get_name() const
{
    return name_;
}

void Author::add_entry(std::shared_ptr<Entry> entry)
{
    if (std::find(begin(entry->get_authors()), end(entry->get_authors()), name_) == end(entry->get_authors()))
        throw NotAuthorsEntryException();
    entries_.push_back(entry);
}

size_t Author::number_of_entries() const
{
    return entries_.size();
}

const std::vector<std::shared_ptr<Entry>> & Author::get_entries() const
{
    return entries_;
}

}
