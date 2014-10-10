#ifndef LIBRARY_AUTHOR_HPP
#define LIBRARY_AUTHOR_HPP

#include <string>
#include <vector>
#include <memory>
#include <exception>

namespace Library
{

class Entry;

class NotAuthorsEntryException : public std::exception
{
};

class Author
{
public:
    Author(std::string name);

    std::string get_name() const;

    void add_entry(std::shared_ptr<Entry> book);
    const std::vector<std::shared_ptr<Entry>> & get_entries() const;
    size_t number_of_entries() const;

private:
    std::string name_;
    std::vector<std::shared_ptr<Entry>> entries_;
};

}
#endif
