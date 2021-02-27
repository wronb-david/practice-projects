using System.Threading.Tasks;

namespace MvxStarter.Core.Handlers
{
    public interface IYTDLHandler
    {
        Task<bool> StartDownload(string link, string options);
        void UpdateFileLoc(in string newLoc);
    }
}