#include "Library/Author.hpp"
#include "Library/Book.hpp"
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

void Author::add_book(std::shared_ptr<Book> book)
{
    if (std::find(begin(book->get_authors()), end(book->get_authors()), name_) == end(book->get_authors()))
        throw NotAuthorsBookException();
    books_.push_back(book);
}

size_t Author::number_of_books() const
{
    return books_.size();
}

const std::vector<std::shared_ptr<Book>> & Author::get_books() const
{
    return books_;
}

}
