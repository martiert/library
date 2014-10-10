#ifndef LIBRARY_AUTHOR_HPP
#define LIBRARY_AUTHOR_HPP

#include <string>
#include <vector>
#include <memory>
#include <exception>

namespace Library
{

class Book;

class NotAuthorsBookException : public std::exception
{
};

class Author
{
public:
    Author(std::string name);

    std::string get_name() const;

    void add_book(std::shared_ptr<Book> book);
    const std::vector<std::shared_ptr<Book>> & get_books() const;
    size_t number_of_books() const;

private:
    std::string name_;
    std::vector<std::shared_ptr<Book>> books_;
};

}
#endif
