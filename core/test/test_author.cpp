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
    CHECK_EQUAL(0U, author->number_of_books());
}

TEST(AuthorTests, adding_book_for_author)
{
    auto book = std::make_shared<Library::Book>("Lord of the rings",
            std::vector<std::string>{"J.R.R. Tolkien"},
            "",
            "");

    author->add_book(book);
    CHECK_EQUAL(1U, author->number_of_books());
    CHECK_EQUAL(book.get(), author->get_books()[0].get());
}

TEST(AuthorTests, adding_book_from_different_author_throws)
{
    CHECK_THROWS(Library::NotAuthorsBookException,
            author->add_book(std::make_shared<Library::Book>(
                "Elantris",
                std::vector<std::string>{"Brandon Sanderson"},
                "",
                "")));
}
