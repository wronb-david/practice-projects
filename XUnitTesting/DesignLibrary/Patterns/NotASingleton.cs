using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignLibrary.Models;

namespace DesignLibrary.Patterns
{
    public class NotASingleton
    {
        private List<CharacterModel> _characters = new List<CharacterModel>();
        private int _characterID = 0;
        public NotASingleton()
        {
            _characters.Add(new CharacterModel { FirstName = "Jane", LastName = "Doe" });
            _characters.Add(new CharacterModel { FirstName = "John", LastName = "Doe" });
        }

        public string getNextCharacter() {
            CharacterModel theChar = _characters[_characterID];
            _characterID = (_characterID + 1) % _characters.Count();
            return theChar.FullName;
        }
    }
}
