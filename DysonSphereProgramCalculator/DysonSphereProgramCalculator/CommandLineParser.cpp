#include "CommandLineParser.h"

namespace DW {
namespace CommandLineParser {
  
  auto print_usage() -> void {
    print_usage(std::cout);
  }

  auto print_usage(std::ostream &stream, std::string const &err_msg) -> void
  {
    if ("" != err_msg) {
      stream << "Error: " << err_msg << "\n\n";
    }
    stream << "Usage: dspc.exe science_color production_rate \n\n";
    stream << "science_color (String): blue | red | yellow \n";
    stream << "production_rate as unsigned int \n\n";
    stream << "Example: \n dspc.exe blue 120";
  }

  auto check_argument_count(const int count) -> bool {
    return count == 3;
  }

  [[nodiscard]] auto parse_rate_as_unsigned_long(std::string const &rate) -> parsed_ul
    {
    try {
      // return std::stoul(rate, nullptr, 10);
      int result{ 0 };
      auto fcres = std::from_chars(rate.data(), rate.data() + rate.size(), result);
      if (result > 0) {
        return { false, static_cast<unsigned long>(result) };
      }
    } catch (const std::exception &) {
      print_usage(std::cerr, "couldn't parse production_per_minute as unsigned long");
    }
    return { true, 0UL };
  }


  auto parse_arguments(std::string const &color, std::string const &rate) -> void
  {
    const std::vector<std::string> valid_colors{ "blue", "red", "yellow" };
    if (vector_contains(valid_colors, color)) {
      auto [err_occured, desired_rate] = parse_rate_as_unsigned_long(rate);
      if (!err_occured) {
        std::cout << "Color: " << color << "; Rate: " << desired_rate << "\n\n";
      } else {
        print_usage(std::cerr, "failed to parse production rate.");
      }
      
    } else {
      print_usage(std::cerr, "color \"" + color + "\" not found.");
    }
  }


  
}
}

