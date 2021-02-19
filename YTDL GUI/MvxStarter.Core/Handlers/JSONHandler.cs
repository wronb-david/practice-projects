using MvxStarter.Core.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.Json;

namespace MvxStarter.Core.Handlers
{
    class JSONHandler
    {
        private readonly string _jsonfile = "./queue.json";



        public List<VideoDownloadModel> LoadQueue()
        {
            if (File.Exists(_jsonfile))
            {
                var jsonText = File.ReadAllText(_jsonfile);
                return JsonSerializer.Deserialize<List<VideoDownloadModel>>(jsonText);
            }
            else {
                return new List<VideoDownloadModel>();
            }

        }

        public void SaveQueue(in ICollection<VideoDownloadModel> data)
        {
            var jsonText = JsonSerializer.Serialize<ICollection<VideoDownloadModel>>(data);
            File.WriteAllText(_jsonfile, jsonText);
        }

    }
}
