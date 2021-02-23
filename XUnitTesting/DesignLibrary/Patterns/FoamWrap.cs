using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignLibrary.Patterns
{
    public class FoamWrap : IWrappable
    {
        private IWrappable _item;
        public FoamWrap(IWrappable wrappedItem)
        {
            _item = wrappedItem;
        }
        public List<string> unwrap()
        {
            var messages = _item.unwrap();
            messages.Add("This item was wrapped in foam");
            return messages;
        }
    }
}
