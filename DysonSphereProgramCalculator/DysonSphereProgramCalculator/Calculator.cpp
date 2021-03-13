#include "Calculator.h"
#include <cmath>

namespace DSP {
namespace Calculator {

	auto calculateProductionChainRec(const double &desired_rate, const DSP::Recipe &target, std::vector<DSP::Recipe> &recipeList, const int productIndex = 0) -> void {
		DSP::MaterialData productData = target.products[productIndex];
		const double num_produced = productData.count;
		const double production_rate = target.production_cycles_per_minute * num_produced;
		const double num_producers = std::ceil(desired_rate / production_rate);
		
		std::cout << "Producing " << desired_rate << " of " << productData.theItem.name << " requires " << num_producers << " "<< target.production_building.name <<"\n";

		for (DSP::MaterialData materialData : target.materials) {
			auto [search_success, sourceRecipe, material_index] = findRecipe(materialData.theItem, recipeList);
			if (search_success) {
				double ratio = materialData.count / num_produced;
				double target_rate = ratio * desired_rate;
				calculateProductionChainRec(target_rate, sourceRecipe, recipeList, material_index);
			}
		}
	}


	auto calculateProductionChain(const double &desired_rate, const DSP::Recipe &target, const int productIndex = 0) -> void {
		auto theRecipes = DSP::Recipe::getAllRecipes();
		calculateProductionChainRec(desired_rate, target, theRecipes, productIndex);
	}

	auto findRecipe(DSP::Item const &needle, std::vector<DSP::Recipe> const &recipeList) -> recipe_search_result {
		int index = 0;
		for (DSP::Recipe recipe : recipeList) {
			auto products = recipe.products;
			auto found_it = std::find_if(begin(products), end(products), [needle](DSP::MaterialData md) { return md.theItem == needle; });
			if (found_it != end(products)) {
				index = static_cast<int>(std::distance(begin(products), found_it));
				return { true, recipe, index };
			}
		}
		return { false, {}, index };
	}
}// namespace Calculator
}// namespace DSP
