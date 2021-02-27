using MvxStarter.Core.Models;
using System.Collections.Generic;

namespace MvxStarter.Core.Handlers
{
    public interface IJSONHandler
    {
        List<IVideoDownloadModel> LoadQueue();
        void SaveQueue(in ICollection<IVideoDownloadModel> data);
    }
}