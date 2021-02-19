using System;
using System.Collections.Generic;
using System.Text;

namespace MvxStarter.Core.Models
{
    class VideoDownloadModel
    {
        private int _entryID;
        private string _link;
        private string _options;
        public int EntryID
        {
            get { return _entryID; }
            set { _entryID = value; }
        }
        public string Link
        {
            get { return _link; }
            set { _link = value; }
        }
        public string Options
        {
            get { return _options; }
            set { _options = value; }
        }
    }
}
