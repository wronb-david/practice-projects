using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Harmony;
using TUNING;

namespace AdjustedFoodDisplay
{
    // Get List of Food Items
    // Get List of Duplicant permissions
    // 
    

    public class AdjustedFoodDisplay {
        private static List<String> _allowedFood = new List<string>();
        private static float _calories = 0f;



        [HarmonyPatch(typeof(ConsumablesTableScreen), "OnActivate")]
        public static class ConsumablesTableScreen_OnActivate_Patch
        {
            public static void Postfix() {
                UpdateAllowedFood();
                UpdateCalories();
            }
        }


        private static void UpdateCalories()
        {
            var calories = 0f;
            Components.Edibles.Items.ForEach(
                edible => calories += _allowedFood.Contains(edible.FoodID) ? edible.Calories : 0
            );
            _calories = calories;
        }

        private static void UpdateAllowedFood() {
            var allowedFood = new List<string>();
            foreach (var edible in Components.Edibles.Items) {
                foreach (var minion in Components.MinionIdentities.Items)
                {
                    var component = minion.GetComponent<ConsumableConsumer>();
                    if (component.IsPermitted(edible.FoodID)) {
                        allowedFood.Add(edible.FoodID);
                        break;
                    }
                }
            }
            _allowedFood = allowedFood;
        }

        [HarmonyPatch(typeof(ConsumableConsumer), "SetPermitted")]
        internal class AdjustedFoodDisplay_ConsumableConsumer_SetPermitted
        {
            private static void Postfix()
            {
                UpdateAllowedFood();
                //Debug.Log($"AllowedFood: {_allowedFood.Count}");
                UpdateCalories();
            }
        }

        [HarmonyPatch(typeof(MeterScreen), "RefreshRations")]
        internal class AdjustedFoodDisplay_MeterScreen_RefreshRations {
            private static void Postfix() {
                MeterScreen.Instance.RationsText.text = GameUtil.GetFormattedCalories((long) _calories);
            }
        }
    }
    
}
