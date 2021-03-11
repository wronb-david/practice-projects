#ifndef DSP_ITEMS
#define DSP_ITEMS
#include <string>
#include <optional>
#include <vector>
#include <iostream>

namespace DSP {
struct Item
{
	std::string const name;

	// Base Items
	static const Item COPPER_ORE;
	static const Item IRON_ORE;
	static const Item STONE;
	static const Item COAL;
	static const Item SILICON_ORE;
	static const Item TITANIUM_ORE;
	static const Item WATER;
	static const Item CRUDE_OIL;
	static const Item LOG;
	static const Item PLANT_FUEL;

	// Derived Items
	static const Item IRON_INGOT;
	static const Item MAGNET;
	static const Item COPPER_INGOT;
	static const Item ENERGETIC_GRAPHITE;
	static const Item STONE_BRICK;
	static const Item CIRCUIT_BOARD;
	static const Item MAGNETIC_COIL;
	static const Item ELECTROMAGNETIC_MATRIX;

	bool operator==(const Item &rhs) const {
		return rhs.name == this->name;
	}
};

struct MaterialData;// forward declaration

enum class Color {Blue, Red, Yellow, Purple, Green, White};

struct Recipe
{
	std::string const identifier;
	double const production_cycles_per_minute;
	std::vector<MaterialData> const materials;
	std::vector<MaterialData> const products;
	// bool const is_manual;
	// Building const produced_in;

	static const Recipe COPPER_MINING;
	static const Recipe IRON_MINING;
	static const Recipe COAL_MINING;
	static const Recipe STONE_MINING;
	static const Recipe TREE_CHOPPING;
	static const Recipe PLANT_GATHERING;

	static const Recipe IRON_INGOT_SMELTING;
	static const Recipe COPPER_INGOT_SMELTING;
	static const Recipe MAGNET_SMELTING;// !

	static const Recipe MAGNETIC_COIL_CRAFTING;
	static const Recipe CIRCUIT_BOARD_CRAFTING;
	static const Recipe ELECTROMAGNETIC_MATRIX_CRAFTING;

	static std::vector<Recipe> const getAllRecipes();
};

struct MaterialData
{
	Item const theItem;
	double const count;
};

}// namespace DSP


#endif// !DSP_ITEMS