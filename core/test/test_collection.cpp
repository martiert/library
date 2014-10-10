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

TEST(CollectionTests, adding_entry_to_collection_makes_it_non_empty)
{
    auto book = std::make_shared<Library::Book>("Foo", std::vector<std::string>{"BAR"}, "BAZ", "1987");

    collection.add_entry(book);
    CHECK(!collection.empty());
}

TEST(CollectionTests, finding_entries_with_given_author)
{
    collection.add_entry(std::make_shared<Library::Book>("A", std::vector<std::string>{"FOO"}, "", ""));
    collection.add_entry(std::make_shared<Library::Book>("B", std::vector<std::string>{"BAR"}, "", ""));

    auto books = collection.find_entries_from_author("FOO");
    CHECK_EQUAL(1U, books.size());
    CHECK_EQUAL("A", books[0]->get_title());
}

TEST(CollectionTests, finding_entries_with_given_author_more_complex)
{
    collection.add_entry(std::make_shared<Library::Book>("A", std::vector<std::string>{"BAR"}, "", ""));
    collection.add_entry(std::make_shared<Library::Book>("B", std::vector<std::string>{"BAR", "FOO", "BAZ"}, "", ""));
    collection.add_entry(std::make_shared<Library::Book>("C", std::vector<std::string>{"FOO"}, "", ""));

    auto books = collection.find_entries_from_author("FOO");
    CHECK_EQUAL(2U, books.size());
    CHECK_EQUAL("B", books[0]->get_title());
    CHECK_EQUAL("C", books[1]->get_title());
}
