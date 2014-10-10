#include "CppUTest/TestHarness.h"
#include "Library/Author.hpp"
#include "Library/Book.hpp"

TEST_GROUP(AuthorTests)
{
    void setup()
    {
        author.reset(new Library::Author("J.R.R. Tolkien"));
    }

    std::unique_ptr<Library::Author> author;
};

TEST(AuthorTests, initialize_author)
{
    CHECK_EQUAL("J.R.R. Tolkien", author->get_name());
    CHECK_EQUAL(0U, author->number_of_entries());
}

TEST(AuthorTests, adding_entry_for_author)
{
    auto entry = std::make_shared<Library::Book>("Lord of the rings",
            std::vector<std::string>{"J.R.R. Tolkien"},
            "",
            "");

    author->add_entry(entry);
    CHECK_EQUAL(1U, author->number_of_entries());
    CHECK_EQUAL(entry.get(), author->get_entries()[0].get());
}

TEST(AuthorTests, adding_entry_from_different_author_throws)
{
    CHECK_THROWS(Library::NotAuthorsEntryException,
            author->add_entry(std::make_shared<Library::Book>(
                "Elantris",
                std::vector<std::string>{"Brandon Sanderson"},
                "",
                "")));
}
