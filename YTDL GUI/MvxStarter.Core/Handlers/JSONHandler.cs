using MvxStarter.Core.Models;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;

namespace MvxStarter.Core.Handlers
{
    class JSONHandler : IJSONHandler
    {
        private readonly string _jsonfile = "./queue.json";



        public List<IVideoDownloadModel> LoadQueue()
        {
            if (File.Exists(_jsonfile))
            {
                var jsonText = File.ReadAllText(_jsonfile);
                return JsonSerializer.Deserialize<List<IVideoDownloadModel>>(jsonText, new JsonSerializerOptions
                {
                    Converters = { new VideoDownloadModelConverter() }
                });
            }
            else
            {
                return new List<IVideoDownloadModel>();
            }

        }

        public void SaveQueue(in ICollection<IVideoDownloadModel> data)
        {
            var jsonText = JsonSerializer.Serialize<ICollection<IVideoDownloadModel>>(data);
            File.WriteAllText(_jsonfile, jsonText);
        }

    }
}
