using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignLibrary.Patterns;
using Xunit;

namespace DesignLibrary.Tests
{
    public class ASingletonTests
    {
        [Fact]
        public void GetNextCharacter_ShouldPass_SingleUse()
        {
            ASingleton aSingleton = ASingleton.getInstance();
            string firstChar = aSingleton.getNextCharacter();
            string secondChar = aSingleton.getNextCharacter();

            Assert.NotEqual(firstChar, secondChar);
        }

        [Fact]
        public void GetNextCharacter_ShouldPass_MultiUse()
        {
            ASingleton firstSingleton = ASingleton.getInstance();
            ASingleton secondSingleton = ASingleton.getInstance();
            string firstChar = firstSingleton.getNextCharacter();
            string secondChar = secondSingleton.getNextCharacter();

            Assert.NotEqual(firstChar, secondChar);
        }
    }
}
