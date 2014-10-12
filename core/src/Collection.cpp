#include "Library/Collection.hpp"
#include "Library/Entry.hpp"
#include <boost/algorithm/string/find.hpp>

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
    auto result = std::vector<std::shared_ptr<Entry>>{};
    for (const auto & author : authors_)
        if (boost::algorithm::ifind_first(author.first, name))
            result.insert(end(result), begin(author.second.get_entries()), end(author.second.get_entries()));
    return result;
}

std::vector<std::shared_ptr<Entry>> Collection::find_entries_with_title(const std::string & title) const
{
    auto result = std::vector<std::shared_ptr<Entry>>{};
    for (auto entry : entries_)
        if (boost::algorithm::ifind_first(entry->get_title(), title))
            result.push_back(entry);

    return result;
}

}
