namespace MvxStarter.Core.Models
{
    class VideoDownloadModel : IVideoDownloadModel
    {
        private int _entryID;
        private string _link;
        private string _options;

        /// <summary>
        /// This constructor is required for the JSON deserializer to be able
        /// to identify concrete classes to use when deserializing the interface properties.
        /// </summary>
        /// <param name="entryID">The Entry's ID number.</param>
        /// <param name="link">The target link to download.</param>
        /// <param name="options">The options supplied for the download.</param>
        public VideoDownloadModel(int entryID, string link, string options)
        {
            _entryID = entryID;
            _link = link;
            _options = options;
        }

        public VideoDownloadModel() { }

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
