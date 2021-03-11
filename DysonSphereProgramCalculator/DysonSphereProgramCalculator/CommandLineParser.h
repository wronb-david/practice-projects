#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER
#include "DSPItems.h"
#include <algorithm>
#include <charconv>
#include <iostream>
#include <string>
#include <vector>

namespace DW {
namespace CommandLineParser {
	struct parsed_dbl
	{
		bool const error_occured;
		double const value;
	};

	struct parser_result
	{
		bool const error_occured;
		double const rate;
		DSP::Color const color;
	};

	auto print_usage() -> void;
	auto print_usage(std::ostream &stream, std::string const &err_msg = "") -> void;
	auto check_argument_count(const int count) -> bool;
	auto parse_rate_as_unsigned_long(std::string const &rate) -> parsed_dbl;
	auto parse_arguments(std::string const &color, std::string const &rate) -> parser_result;

	template<typename T>
	auto vector_contains(std::vector<T> haystack, T needle) -> bool const {
		return std::find(begin(haystack), end(haystack), needle) != end(haystack);
	}
	auto match_string_to_color(std::string const &text) noexcept -> std::optional<DSP::Color>;
	auto match_color_to_recipe(DSP::Color const &color) noexcept -> std::optional<DSP::Recipe>;
}// namespace CommandLineParser
}// namespace DW
#endif// !COMMAND_LINE_PARSER
