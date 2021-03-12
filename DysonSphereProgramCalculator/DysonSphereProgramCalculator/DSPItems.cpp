﻿#include "DSPItems.h"
namespace DSP {
const Item Item::STONE{ "Stone" };
const Item Item::COPPER_ORE{ "Copper Ore" };
const Item Item::IRON_ORE{ "Iron Ore" };
const Item Item::SILICON_ORE{ "Silicon Ore" };
const Item Item::TITANIUM_ORE{ "Titanium Ore" };
const Item Item::WATER{ "Water" };
const Item Item::LOG{ "Log" };
const Item Item::PLANT_FUEL{ "Plant Fuel" };
const Item Item::STONE_BRICK{ "Stone Brick" };


// Blue Science
const Item Item::IRON_INGOT{ "Iron Ingot" };
const Item Item::MAGNET{ "Magnet" };
const Item Item::COPPER_INGOT{ "Copper Ingot" };
const Item Item::CIRCUIT_BOARD{ "Circuit Board" };
const Item Item::MAGNETIC_COIL{ "Magnetic Coil" };
const Item Item::ELECTROMAGNETIC_MATRIX{ "Electromagnetic Matric" };
// Red Science
const Item Item::COAL{ "Coal" };
const Item Item::CRUDE_OIL{ "Crude Oil" };
const Item Item::ENERGY_MATRIX{ "Energy Matric" };
const Item Item::REFINED_OIL{ "Refined Oil" };
const Item Item::HYDROGEN{ "Hydrogen" };
const Item Item::ENERGETIC_GRAPHITE{ "Energetic Graphite" };

const Recipe Recipe::COPPER_MINING{
	"Copper Mining",
	180,
	{},
	{ { Item::COPPER_ORE, 1 } }
};

const Recipe Recipe::IRON_MINING{
	"Copper Mining",
	180,
	{},
	{ { Item::IRON_ORE, 1 } }
};

const Recipe Recipe::COAL_MINING{
	"Coal Mining",
	180,
	{},
	{ { Item::COAL, 1 } }
};

const Recipe Recipe::STONE_MINING{
	"Coal Mining",
	180,
	{},
	{ { Item::COAL, 1 } }
};

const Recipe Recipe::TREE_CHOPPING{
	"Tree chopping",
	10,
	{},
	{ { Item::LOG, 12 } }
};

const Recipe Recipe::PLANT_GATHERING{
	"Plant gathering",
	10,
	{},
	{ { Item::PLANT_FUEL, 10 } }
};

const Recipe Recipe::IRON_INGOT_SMELTING{
	"Iron Ore to Iron Ingot smelting",
	60,
	{ { Item::IRON_ORE, 1 } },
	{ { Item::IRON_INGOT, 1 } }
};

const Recipe Recipe::COPPER_INGOT_SMELTING{
	"Copper Ore to Copper Ingot smelting",
	60,
	{ { Item::COPPER_ORE, 1 } },
	{ { Item::COPPER_INGOT, 1 } }
};

const Recipe Recipe::MAGNET_SMELTING{
	"Iron Ore to MAGNET smelting",
	40,
	{ { Item::IRON_ORE, 1 } },
	{ { Item::MAGNET, 1 } }
};

const Recipe Recipe::MAGNETIC_COIL_CRAFTING {
	"Magnetic Coil crafting",
	60,
	{ { Item::MAGNET, 2 }, { Item::COPPER_INGOT, 1 } },
	{ { Item::MAGNETIC_COIL, 2 }}
};

const Recipe Recipe::CIRCUIT_BOARD_CRAFTING{
	"Circuit Board crafting",
	60,
	{ { Item::IRON_INGOT, 2 }, { Item::COPPER_INGOT, 1 } },
	{ { Item::CIRCUIT_BOARD, 2 } }
};

const Recipe Recipe::ELECTROMAGNETIC_MATRIX_CRAFTING{
	"Electromagnetic Matrix Crafting",
	20,
	{ { Item::MAGNETIC_COIL, 1 }, { Item::CIRCUIT_BOARD, 1 } },
	{ { Item::ELECTROMAGNETIC_MATRIX, 1 } }
};

const Recipe Recipe::ENERGETIC_GRAPHITE_SMELTING{
	"Coal Smelting",
	30,
	{ { Item::COAL, 2 } },
	{ { Item::ENERGETIC_GRAPHITE, 1 } }
};

const Recipe Recipe::CRUDE_OIL_EXTRACTING{
	"Crude Oil Extracting",
	60,
	{},
	{ { Item::CRUDE_OIL, 2 } }
};

const Recipe Recipe::CRUDE_OIL_REFINING{
	"Crude Oil Refining",
	15,
	{ { Item::CRUDE_OIL, 2 } },
	{ { Item::REFINED_OIL, 2 }, { Item::HYDROGEN, 1 } }
};


const Recipe Recipe::ENERGY_MATRIX_CRAFTING{
	"Energy Matrix Crafting",
	10,
	{ { Item::ENERGETIC_GRAPHITE, 2 }, { Item::HYDROGEN, 2 } },
	{ { Item::ENERGY_MATRIX, 1 } }
};

std::vector<Recipe> const Recipe::getAllRecipes() {
	return std::vector{
		COPPER_MINING, IRON_MINING, COAL_MINING, STONE_MINING, TREE_CHOPPING, PLANT_GATHERING,
		// Derived items
		IRON_INGOT_SMELTING, COPPER_INGOT_SMELTING, MAGNET_SMELTING, 
		MAGNETIC_COIL_CRAFTING, CIRCUIT_BOARD_CRAFTING, ELECTROMAGNETIC_MATRIX_CRAFTING,
		// For Energy Matrix
		CRUDE_OIL_EXTRACTING,ENERGETIC_GRAPHITE_SMELTING, CRUDE_OIL_REFINING, ENERGY_MATRIX_CRAFTING
	};
}

}// namespace DSP