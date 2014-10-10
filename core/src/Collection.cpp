#include "Library/Collection.hpp"
#include "Library/Entry.hpp"

namespace Library
{

bool Collection::empty() const
{
    return entries_.empty();
}

void Collection::add_entry(std::shared_ptr<Entry> book)
{
    entries_.push_back(book);

    for (const auto & name : book->get_authors()) {
        if (authors_.find(name) == end(authors_))
            authors_.insert(std::make_pair(name, Author{name}));
        authors_.at(name).add_entry(book);
    }
}

std::vector<std::shared_ptr<Entry>> Collection::find_entries_from_author(const std::string & name) const
{
    auto author = authors_.find(name);
    if (author == end(authors_))
        return std::vector<std::shared_ptr<Entry>>{};
    return author->second.get_entries();
}

}
