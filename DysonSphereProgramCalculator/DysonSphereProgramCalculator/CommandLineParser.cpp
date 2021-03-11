#include "CommandLineParser.h"


namespace DW {
namespace CommandLineParser {

	auto print_usage() -> void {
		print_usage(std::cout);
	}

	auto print_usage(std::ostream &stream, std::string const &err_msg) -> void {
			if ("" != err_msg) {
				stream << "Error: " << err_msg << "\n\n";
		}
		stream << "Usage: dspc.exe science_color production_rate \n\n";
		stream << "science_color (String): blue | red | yellow \n";
		stream << "production_rate as unsigned int \n\n";
		stream << "Example: \n dspc.exe blue 120";
	}

	[[nodiscard]] auto check_argument_count(const int count) -> bool {
		return count == 3;
	}

	[[nodiscard]] auto parse_rate_as_unsigned_long(std::string const &rate) -> parsed_dbl {
		try {
			int result{ 0 };
			auto fcres = std::from_chars(rate.data(), rate.data() + rate.size(), result);
			if (result > 0) {
				return { false, static_cast<double>(result) };
			}
		} catch (const std::exception &) {
			print_usage(std::cerr, "couldn't parse production_per_minute as unsigned long");
		}
		return { true, 0UL };
	}


	[[nodiscard]] auto parse_arguments(std::string const &color, std::string const &rate) -> parser_result {
		const std::vector<std::string> valid_colors{ "blue", "red", "yellow" };
		if (vector_contains(valid_colors, color)) {
			auto [err_occured, desired_rate] = parse_rate_as_unsigned_long(rate);
			if (!err_occured) {
				auto maybeColor = match_string_to_color(color);
				if (maybeColor.has_value()) {
					return { false, desired_rate, maybeColor.value() };
				}
			} else {
				print_usage(std::cerr, "failed to parse production rate.");
			}
		} else {
			print_usage(std::cerr, "color \"" + color + "\" not found.");
		}
		return { true, 0, DSP::Color::Red };
	}

	[[nodiscard]] auto match_string_to_color(std::string const &text) noexcept -> std::optional<DSP::Color> {
			if ("blue" == text) {
				return DSP::Color::Blue;
		}
			if ("red" == text) {
				return DSP::Color::Red;
		}
			if ("yellow" == text) {
				return DSP::Color::Yellow;
		}
			if ("purple" == text) {
				return DSP::Color::Purple;
		}
			if ("green" == text) {
				return DSP::Color::Green;
		}
			if ("white" == text) {
				return DSP::Color::White;
		}
		return std::nullopt;
	}

	[[nodiscard]] auto match_color_to_recipe(DSP::Color const &needle) noexcept -> std::optional<DSP::Recipe> {
			switch (needle) {
				case DSP::Color::Blue:
					return DSP::Recipe::ELECTROMAGNETIC_MATRIX_CRAFTING;
					break;
				case DSP::Color::Red:
					return std::nullopt;
					break;
				case DSP::Color::Yellow:
					return std::nullopt;
					break;
				case DSP::Color::Purple:
					return std::nullopt;
					break;
				case DSP::Color::Green:
					return std::nullopt;
					break;
				case DSP::Color::White:
					return std::nullopt;
					break;
				default:
					return std::nullopt;
					break;
			}
	}

}// namespace CommandLineParser
}// namespace DW
