project(LibraryCoreTests CXX)
include_directories(${CppUTest_INCLUDE_DIR})

set(src main.cpp
        test_collection.cpp
        test_author.cpp
)

add_executable(LibraryCoreTests ${src})
target_link_libraries(LibraryCoreTests LibraryCore CppUTest)

add_test(LibraryCoreTests ${EXECUTABLE_OUTPUT_PATH}/LibrarySharedTests)
