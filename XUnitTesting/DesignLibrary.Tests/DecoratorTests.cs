using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignLibrary.Patterns;
using Xunit;

namespace DesignLibrary.Tests
{
    public class DecoratorTests
    {
        [Fact]
        public void DecoratorWrapping() {
            IWrappable wrappedItem = new FoamWrap(new BubbleWrap( new Package()));
            var messages = wrappedItem.unwrap();

            Assert.Contains<string>("This item was wrapped in bubble wrap.", messages);
        }
    }
}
