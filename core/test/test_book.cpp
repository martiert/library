#include "CppUTest/TestHarness.h"
#include "Library/Book.hpp"

TEST_GROUP(BookTests)
{
};

TEST(BookTests, test_creating_book)
{
    auto book = Library::Book{"Title", {"Author1", "Author2"}, "ISBN", "1987"};

    CHECK_EQUAL("Title", book.get_title());
    CHECK_EQUAL(2U, book.get_authors().size());
    CHECK_EQUAL("Author1", book.get_authors()[0]);
    CHECK_EQUAL("Author2", book.get_authors()[1]);
    CHECK_EQUAL("ISBN", book.get_isbn());
    CHECK_EQUAL("1987", book.get_publication_year());
}
