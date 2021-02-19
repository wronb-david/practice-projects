using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;

namespace MvxStarter.Core.Handlers
{
    class YTDLHandler
    {
        private readonly string _defaultfileLoc = "F:/YTDL/youtube-dl.exe";
        private readonly Process _process;
        private readonly ProcessStartInfo _psi;

        public delegate void CallbackHandler(string data);

        public YTDLHandler()
        {
            _psi = new ProcessStartInfo
            {
                FileName = _defaultfileLoc,
                Arguments = "",
                UseShellExecute = false,
                RedirectStandardOutput = false,
                CreateNoWindow = true
            };
            _process = new Process
            {
                StartInfo = _psi
            };
        }

        public void UpdateFileLoc(in string newLoc)
        {
            _process.StartInfo.FileName = newLoc;
        }

        async public Task<bool> StartDownload( string link, string options)
        {
            try
            {
                _process.StartInfo.Arguments = $"{link} {options}";
                var hasStarted = _process.Start();
                if (!hasStarted) {
                    return true;
                }
                var waitforexit = WaitForExitAsync(_process);
                bool hasEnded = await waitforexit;
                return true;
            }
            catch (Exception)
            {
                _process.Kill();
                return true;
            }
        }

        private static Task<bool> WaitForExitAsync(Process process)
        {
            return Task.Run(() => process.WaitForExit(int.MaxValue));
        }

    }
}
