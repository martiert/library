project(LibraryCore CXX)
include_directories(include)

set(src src/Book.cpp
        src/Author.cpp
        src/Collection.cpp
)

add_library(LibraryCore SHARED ${src})

add_subdirectory(test)
