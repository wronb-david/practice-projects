using MvxStarter.Core.Handlers;
using MvxStarter.Core.Models;

namespace MvxStarter.Core
{
    public static class Factory
    {
        public static IJSONHandler CreateJSONHandler()
        {
            return new JSONHandler();
        }

        public static IYTDLHandler CreateYTDLHandler() 
        {
            return new YTDLHandler();
        }

        public static IVideoDownloadModel CreateVideoDownloadModel() 
        {
            return new VideoDownloadModel();
        }

    }
}
