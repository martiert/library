#ifndef LIBRARY_COLLECTION_HPP
#define LIBRARY_COLLECTION_HPP

#include "Library/Author.hpp"

#include <memory>
#include <vector>
#include <map>

namespace Library
{

class Book;

class Collection
{
public:
    bool empty() const;
    void add_book(std::shared_ptr<Book> book);
    std::vector<std::shared_ptr<Book>> find_books_from_author(const std::string & name) const;

private:
    std::vector<std::shared_ptr<Book>> books_;
    std::map<std::string, Author> authors_;
};

}

#endif
