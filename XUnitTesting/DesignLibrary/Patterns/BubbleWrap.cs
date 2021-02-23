using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignLibrary.Patterns
{
    public class BubbleWrap : IWrappable
    {
        private IWrappable _item;
        public BubbleWrap(IWrappable wrappedItem)
        {
            _item = wrappedItem;
        }
        public List<string> unwrap()
        {
            List<string> messages = _item.unwrap();
            messages.Add("This item was wrapped in bubble wrap.");
            return messages;
        }
    }
}
