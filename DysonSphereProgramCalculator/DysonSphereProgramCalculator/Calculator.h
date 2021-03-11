#ifndef DW_CALCULATOR_H
#define DW_CALCULATOR_H

#include "DSPItems.h"

namespace DSP {
namespace Calculator {
	struct recipe_search_result
	{
		bool const recipe_found;
		DSP::Recipe const theRecipe;
		int const item_index;
	};

	auto calculateProductionChainRec(double const &desired_rate, DSP::Recipe const &target, std::vector<DSP::Recipe> &recipeList, const int productIndex) -> void;

	auto calculateProductionChain(const double &desired_rate, const DSP::Recipe &target, const int productIndex) -> void;

	auto findRecipe(DSP::Item const &needle, std::vector<DSP::Recipe> const &recipeList) -> recipe_search_result;
}
}// namespace DSP


#endif// !DW_CALCULATOR_H