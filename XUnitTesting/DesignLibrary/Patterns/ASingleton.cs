using DesignLibrary.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignLibrary.Patterns
{
    public class ASingleton
    {
        private static ASingleton _instance = new ASingleton();
        private List<CharacterModel> _characters = new List<CharacterModel>();
        private int _characterID = 0;

        private ASingleton()
        {
            _characters.Add(new CharacterModel { FirstName = "Jane", LastName = "Doe" });
            _characters.Add(new CharacterModel { FirstName = "John", LastName = "Doe" });
        }


        public static ASingleton getInstance() {
            return _instance;
        }

        public string getNextCharacter()
        {
            CharacterModel theChar = _characters[_characterID];
            _characterID = (_characterID + 1) % _characters.Count();
            return theChar.FullName;
        }
    }
}
