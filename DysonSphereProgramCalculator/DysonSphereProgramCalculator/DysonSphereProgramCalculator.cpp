#include "CommandLineParser.h"
#include "Calculator.h"

int main(const int argc, char const *const argv[]) {
	if (DW::CommandLineParser::check_argument_count(argc)) {
		auto [error_occured, rate, color] = DW::CommandLineParser::parse_arguments(argv[1], argv[2]);
		if (!error_occured) {
			auto maybeRecipe = DW::CommandLineParser::match_color_to_recipe(color);
			if (maybeRecipe.has_value()) {
				DSP::Calculator::calculateProductionChain(rate, maybeRecipe.value(), 0);
			}
		}
	} else {
		DW::CommandLineParser::print_usage();
	}
}

