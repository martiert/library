#include "CppUTest/CommandLineTestRunner.h"
#include <execinfo.h>
#include <csignal>
#include <iostream>
#include <string>
#include <cstring>

static void sig_handler(int signo)
{
    std::cout << "Caught signal: " << strsignal(signo) << "\nBacktrace:\n";
    void *buffer[100];
    int num_symbols = backtrace(buffer, 100);
    char ** symbols = backtrace_symbols(buffer, num_symbols);
    for (int i = 0; i < num_symbols; ++i)
        std::cout << symbols[i] << std::endl;
    free(symbols);
    signal(signo, SIG_DFL);
    raise(signo);
}

int main(int ac, char ** av)
{
    signal(SIGINT, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGTERM, sig_handler);
    signal(SIGABRT, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGSEGV, sig_handler);

    return CommandLineTestRunner::RunAllTests(ac, av);
}
