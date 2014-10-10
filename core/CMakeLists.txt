project(LibraryCore CXX)

find_package(Boost REQUIRED)
include_directories(include ${Boost_INCLUDE_DIRS})

set(src src/Author.cpp
        src/Collection.cpp
)

add_library(LibraryCore SHARED ${src})

add_subdirectory(test)
