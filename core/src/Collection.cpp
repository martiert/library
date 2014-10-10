#include "Library/Collection.hpp"
#include "Library/Book.hpp"

namespace Library
{

bool Collection::empty() const
{
    return books_.empty();
}

void Collection::add_book(std::shared_ptr<Book> book)
{
    books_.push_back(book);

    for (const auto & name : book->get_authors()) {
        if (authors_.find(name) == end(authors_))
            authors_.insert(std::make_pair(name, Author{name}));
        authors_.at(name).add_book(book);
    }
}

std::vector<std::shared_ptr<Book>> Collection::find_books_from_author(const std::string & name) const
{
    auto author = authors_.find(name);
    if (author == end(authors_))
        return std::vector<std::shared_ptr<Book>>{};
    return author->second.get_books();
}

}
