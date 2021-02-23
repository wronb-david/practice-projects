using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignLibrary.Patterns
{
    public class Package : IWrappable
    {
        public List<string> unwrap()
        {
            List<string> messages = new List<string>();
            messages.Add("You've unwrapped a Package");
            return messages;
        }
    }
}
