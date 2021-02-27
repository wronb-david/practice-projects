namespace MvxStarter.Core.Models
{
    public interface IVideoDownloadModel
    {
        int EntryID { get; set; }
        string Link { get; set; }
        string Options { get; set; }
    }
}