#include "CommandLineParser.h"

int main(const int argc, char const *const argv[])
{
    if (DW::CommandLineParser::check_argument_count(argc)) {
      DW::CommandLineParser::parse_arguments(argv[1], argv[2]);
    } else {
      DW::CommandLineParser::print_usage();
    }
}

