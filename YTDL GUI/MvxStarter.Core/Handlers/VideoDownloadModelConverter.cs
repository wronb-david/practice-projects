using MvxStarter.Core.Models;
using System;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace MvxStarter.Core.Handlers
{
    internal class VideoDownloadModelConverter : JsonConverter<IVideoDownloadModel>
    {
        public override IVideoDownloadModel Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options)
        {
            return JsonSerializer.Deserialize<VideoDownloadModel>(ref reader, options);
        }

        public override void Write(Utf8JsonWriter writer, IVideoDownloadModel value, JsonSerializerOptions options)
        {
            switch (value)
            {
                case null:
                    JsonSerializer.Serialize(writer, (IVideoDownloadModel)null, options);
                    break;
                default:
                    JsonSerializer.Serialize(writer, value, options);
                    break;
            }
        }
    }
}