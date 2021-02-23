using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignLibrary.Patterns;
using Xunit;
namespace DesignLibrary.Tests
{
    public class NotASingletonTests
    {
        [Fact]
        public void GetNextCharacter_ShouldPass_SingleUse() {
            NotASingleton notASingleton = new NotASingleton();
            string firstChar = notASingleton.getNextCharacter();
            string secondChar = notASingleton.getNextCharacter();

            Assert.NotEqual(firstChar, secondChar);
        }

        [Fact]
        public void GetNextCharacter_ShouldFail_MultiUse()
        {
            NotASingleton firstNotASingleton = new NotASingleton();
            NotASingleton secondNotASingleton = new NotASingleton();
            string firstChar = firstNotASingleton.getNextCharacter();
            string secondChar = secondNotASingleton.getNextCharacter();

            Assert.NotEqual(firstChar, secondChar);
        }
    }
}
