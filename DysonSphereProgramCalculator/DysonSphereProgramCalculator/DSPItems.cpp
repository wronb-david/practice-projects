#include "DSPItems.h"
namespace DSP {

// Setup Items
const Item Item::STONE{ "Stone" };
const Item Item::SILICON_ORE{ "Silicon Ore" };
const Item Item::WATER{ "Water" };
const Item Item::LOG{ "Log" };
const Item Item::PLANT_FUEL{ "Plant Fuel" };
const Item Item::STONE_BRICK{ "Stone Brick" };

// Blue Science
const Item Item::COPPER_ORE{ "Copper Ore" };
const Item Item::IRON_ORE{ "Iron Ore" };

const Item Item::COPPER_INGOT{ "Copper Ingot" };
const Item Item::IRON_INGOT{ "Iron Ingot" };
const Item Item::MAGNET{ "Magnet" };

const Item Item::CIRCUIT_BOARD{ "Circuit Board" };
const Item Item::MAGNETIC_COIL{ "Magnetic Coil" };

const Item Item::ELECTROMAGNETIC_MATRIX{ "Electromagnetic Matric" };


// Red Science
const Item Item::COAL{ "Coal" };
const Item Item::CRUDE_OIL{ "Crude Oil" };

const Item Item::ENERGETIC_GRAPHITE{ "Energetic Graphite" };
const Item Item::REFINED_OIL{ "Refined Oil" };
const Item Item::HYDROGEN{ "Hydrogen" };

const Item Item::ENERGY_MATRIX{ "Energy Matric" };


// Yellow Science
const Item Item::TITANIUM_ORE{ "Titanium Ore" };

const Item Item::TITANIUM_INGOT{ "TItanium Ingot" };
const Item Item::PLASTIC{ "Plastic" };
const Item Item::ORGANIC_CRYSTAL{ "Organic Crystal" };

const Item Item::DIAMOND{ "Diamond" };
const Item Item::TITANIUM_CRYSTAL{ "Titanium Crystal" };

const Item Item::STRUCTURE_MATRIX{ "Structure Matric" };

// Setup Buildings
const Building Building::ICARUS{ " by Hand (Icarus)" };

const Building Building::MINING_MACHINE{ "Mining Machine" };
const Building Building::OIL_EXTRACTOR{ "Oil Extractor" };

const Building Building::SMELTER{ "Smelter" };
const Building Building::ASSEMBLING_MACHINE{ "Assembling Machine" };
const Building Building::OIL_REFINERY{ "Oil Refinery" };
const Building Building::CHEMICAL_PLANT{ "Chemical Plant" };

const Building Building::MATRIX_LAB{ "Matrix Lab" };

// Setup Recipes
const Recipe Recipe::COPPER_MINING{
	"Copper Mining",
	180,
	{},
	{ { Item::COPPER_ORE, 1 } },
	Building::MINING_MACHINE
};

const Recipe Recipe::IRON_MINING{
	"Copper Mining",
	180,
	{},
	{ { Item::IRON_ORE, 1 } },
	Building::MINING_MACHINE
};

const Recipe Recipe::COAL_MINING{
	"Coal Mining",
	180,
	{},
	{ { Item::COAL, 1 } },
	Building::MINING_MACHINE
};

const Recipe Recipe::STONE_MINING{
	"Coal Mining",
	180,
	{},
	{ { Item::COAL, 1 } },
	Building::MINING_MACHINE
};

const Recipe Recipe::TREE_CHOPPING{
	"Tree chopping",
	10,
	{},
	{ { Item::LOG, 12 } },
	Building::ICARUS
};

const Recipe Recipe::PLANT_GATHERING{
	"Plant gathering",
	10,
	{},
	{ { Item::PLANT_FUEL, 10 } },
	Building::ICARUS
};

const Recipe Recipe::IRON_INGOT_SMELTING{
	"Iron Ore to Iron Ingot smelting",
	60,
	{ { Item::IRON_ORE, 1 } },
	{ { Item::IRON_INGOT, 1 } },
	Building::SMELTER
};

const Recipe Recipe::COPPER_INGOT_SMELTING{
	"Copper Ore to Copper Ingot smelting",
	60,
	{ { Item::COPPER_ORE, 1 } },
	{ { Item::COPPER_INGOT, 1 } },
	Building::SMELTER
};

const Recipe Recipe::MAGNET_SMELTING{
	"Iron Ore to MAGNET smelting",
	40,
	{ { Item::IRON_ORE, 1 } },
	{ { Item::MAGNET, 1 } },
	Building::SMELTER
};

const Recipe Recipe::MAGNETIC_COIL_CRAFTING {
	"Magnetic Coil crafting",
	60,
	{ { Item::MAGNET, 2 }, { Item::COPPER_INGOT, 1 } },
	{ { Item::MAGNETIC_COIL, 2 } },
	Building::ASSEMBLING_MACHINE
};

const Recipe Recipe::CIRCUIT_BOARD_CRAFTING{
	"Circuit Board crafting",
	60,
	{ { Item::IRON_INGOT, 2 }, { Item::COPPER_INGOT, 1 } },
	{ { Item::CIRCUIT_BOARD, 2 } },
	Building::ASSEMBLING_MACHINE
};

const Recipe Recipe::ELECTROMAGNETIC_MATRIX_CRAFTING{
	"Electromagnetic Matrix Crafting",
	20,
	{ { Item::MAGNETIC_COIL, 1 }, { Item::CIRCUIT_BOARD, 1 } },
	{ { Item::ELECTROMAGNETIC_MATRIX, 1 } },
	Building::MATRIX_LAB
};

const Recipe Recipe::ENERGETIC_GRAPHITE_SMELTING{
	"Coal Smelting",
	30,
	{ { Item::COAL, 2 } },
	{ { Item::ENERGETIC_GRAPHITE, 1 } },
	Building::SMELTER
};

const Recipe Recipe::CRUDE_OIL_EXTRACTING{
	"Crude Oil Extracting",
	60,
	{},
	{ { Item::CRUDE_OIL, 2 } },
	Building::OIL_EXTRACTOR
};

const Recipe Recipe::CRUDE_OIL_REFINING{
	"Crude Oil Refining",
	15,
	{ { Item::CRUDE_OIL, 2 } },
	{ { Item::REFINED_OIL, 2 }, { Item::HYDROGEN, 1 } },
	Building::OIL_REFINERY
};


const Recipe Recipe::ENERGY_MATRIX_CRAFTING{
	"Energy Matrix Crafting",
	10,
	{ { Item::ENERGETIC_GRAPHITE, 2 }, { Item::HYDROGEN, 2 } },
	{ { Item::ENERGY_MATRIX, 1 } },
	Building::MATRIX_LAB
};

// Yellow Science Recipes
const Recipe Recipe::TITANIUM_ORE_MINING{
	"Titanium Ore Mining",
	180,
	{ },
	{ { Item::TITANIUM_ORE, 1 } },
	Building::MINING_MACHINE
};

const Recipe Recipe::TITANIUM_INGOT_SMELTING{
	"Titanium Ingot Crafting",
	60,
	{ { Item::TITANIUM_ORE, 2} },
	{ { Item::TITANIUM_INGOT, 1 } },
	Building::SMELTER
};

const Recipe Recipe::PLASTIC_SYNTHESIS{
	"Plastic Synthesis",
	20,
	{ { Item::REFINED_OIL, 2 }, { Item::ENERGETIC_GRAPHITE, 1} },
	{ { Item::PLASTIC, 1 } },
	Building::CHEMICAL_PLANT
};

const Recipe Recipe::ORGANIC_CRYSTAL_SYNTHESIS{
	"Organic Crystal Synthesis",
	10,
	{ { Item::PLASTIC, 2 }, { Item::WATER, 1 }, { Item::REFINED_OIL, 1 } },
	{ { Item::ORGANIC_CRYSTAL, 1 } },
	Building::CHEMICAL_PLANT
};

const Recipe Recipe::TITANIUM_CRYSTAL_CRAFTING{
	"Titanium Crystal Crafting",
	15,
	{ { Item::TITANIUM_INGOT, 3 }, { Item::ORGANIC_CRYSTAL, 1 } },
	{ { Item::TITANIUM_CRYSTAL, 1 } },
	Building::ASSEMBLING_MACHINE
};

const Recipe Recipe::DIAMOND_SMELTING{
	"Diamond Smelting",
	30,
	{ { Item::ENERGETIC_GRAPHITE, 1 } },
	{ { Item::DIAMOND, 1 } },
	Building::SMELTER
};

const Recipe Recipe::STRUCTURE_MATRIX_CRAFTING{
	"Structure Matrix Crafting",
	7.5,
	{ { Item::ENERGETIC_GRAPHITE, 2 }, { Item::HYDROGEN, 2 } },
	{ { Item::ENERGY_MATRIX, 1 } },
	Building::MATRIX_LAB
};






// C++20 should allow for this to be calculated at compile time (constexpr containers, consteval)
std::vector<Recipe> const Recipe::getAllRecipes() {
	return std::vector{
		// Basic Items 
		STONE_MINING, TREE_CHOPPING, PLANT_GATHERING,
		// For Electromagnetic Matrix (Blue Science)
		COPPER_MINING, IRON_MINING, 
		IRON_INGOT_SMELTING, COPPER_INGOT_SMELTING, MAGNET_SMELTING,
		MAGNETIC_COIL_CRAFTING, CIRCUIT_BOARD_CRAFTING, 
		ELECTROMAGNETIC_MATRIX_CRAFTING,
		// For Energy Matrix (Red Science)
		COAL_MINING, CRUDE_OIL_EXTRACTING,
		ENERGETIC_GRAPHITE_SMELTING,CRUDE_OIL_REFINING,
		ENERGY_MATRIX_CRAFTING,
		// For Structure Matrix (Yellow Science)
		TITANIUM_ORE_MINING, 
		PLASTIC_SYNTHESIS, TITANIUM_INGOT_SMELTING, ORGANIC_CRYSTAL_SYNTHESIS, 
		TITANIUM_CRYSTAL_CRAFTING, DIAMOND_SMELTING, 
		STRUCTURE_MATRIX_CRAFTING
		// For Information Matrix (Purple Science)
		// For Gravity Matrix (Green Science)
		// For Universe Matrix (White Science)
	};
}

}// namespace DSP
