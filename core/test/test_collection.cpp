#include "CppUTest/TestHarness.h"
#include "Library/Collection.hpp"
#include "Library/Book.hpp"

TEST_GROUP(CollectionTests)
{
    Library::Collection collection;
};

TEST(CollectionTests, initial_collection_is_empty)
{
    CHECK(collection.empty());
}

TEST(CollectionTests, adding_book_to_collection_makes_it_non_empty)
{
    auto book = std::make_shared<Library::Book>("Foo", std::vector<std::string>{"BAR"}, "BAZ", "1987");

    collection.add_book(book);
    CHECK(!collection.empty());
}

TEST(CollectionTests, finding_books_with_given_author)
{
    collection.add_book(std::make_shared<Library::Book>("A", std::vector<std::string>{"FOO"}, "", ""));
    collection.add_book(std::make_shared<Library::Book>("B", std::vector<std::string>{"BAR"}, "", ""));

    auto books = collection.find_books_from_author("FOO");
    CHECK_EQUAL(1U, books.size());
    CHECK_EQUAL("A", books[0]->get_title());
}

TEST(CollectionTests, finding_books_with_given_author_more_complex)
{
    collection.add_book(std::make_shared<Library::Book>("A", std::vector<std::string>{"BAR"}, "", ""));
    collection.add_book(std::make_shared<Library::Book>("B", std::vector<std::string>{"BAR", "FOO", "BAZ"}, "", ""));
    collection.add_book(std::make_shared<Library::Book>("C", std::vector<std::string>{"FOO"}, "", ""));

    auto books = collection.find_books_from_author("FOO");
    CHECK_EQUAL(2U, books.size());
    CHECK_EQUAL("B", books[0]->get_title());
    CHECK_EQUAL("C", books[1]->get_title());
}
