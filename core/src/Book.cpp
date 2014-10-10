#include "Library/Book.hpp"

namespace Library
{

Book::Book(std::string title, std::vector<std::string> authors, std::string ISBN, std::string year)
    : title_(title),
      authors_(authors),
      isbn_(ISBN),
      year_(year)
{}

const std::string & Book::get_title() const
{
    return title_;
}

const std::vector<std::string> & Book::get_authors() const
{
    return authors_;
}

const std::string & Book::get_isbn() const
{
    return isbn_;
}

const std::string & Book::get_publication_year() const
{
    return year_;
}


}
