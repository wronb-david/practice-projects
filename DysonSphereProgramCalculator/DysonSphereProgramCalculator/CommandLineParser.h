#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<charconv>

namespace DW {
	namespace CommandLineParser {
        struct parsed_ul {
          bool const error_occured;
          unsigned long const value;
        };

        auto print_usage() -> void;
        auto print_usage(std::ostream &stream, std::string const &err_msg = "") -> void;
        auto check_argument_count(const int count) -> bool;
        auto parse_rate_as_unsigned_long(std::string const &rate) -> parsed_ul;

        auto parse_arguments(std::string const &color, std::string const &rate) -> void;

		template<typename T>
        auto vector_contains(std::vector<T> haystack, T needle) -> bool const
        {
            return std::find(begin(haystack), end(haystack), needle) != end(haystack);
        }
	}
}



#endif// !COMMAND_LINE_PARSER
