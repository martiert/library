#ifndef LIBRARY_BOOK_HPP
#define LIBRARY_BOOK_HPP

#include "Library/Entry.hpp"
#include <string>
#include <vector>

namespace Library
{

class Book : public Entry
{
public:
    Book(std::string title, std::vector<std::string> authors, std::string ISBN, std::string year);
    const std::string & get_title() const override;
    const std::vector<std::string> & get_authors() const override;
    const std::string & get_isbn() const;
    const std::string & get_publication_year() const;

private:
    std::string title_;
    std::vector<std::string> authors_;
    std::string isbn_;
    std::string year_;
};

}

#endif
