using MvvmCross.ViewModels;
using MvxStarter.Core.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using MvvmCross.Commands;
using MvxStarter.Core.Handlers;
using System.Threading.Tasks;

namespace MvxStarter.Core.ViewModels
{
    class YtdlViewModel : MvxViewModel
    {
        private string _linkText;
        private string _optionsText;
        private bool _processRunning = false;

        private ObservableCollection<IVideoDownloadModel> _queuedDownloads;
        private IVideoDownloadModel _selectedDownload = null;

        private ObservableCollection<string> _downlaodOutput = new ObservableCollection<string>();
        private readonly IYTDLHandler _ytdlHandler;
        private readonly IJSONHandler _jsonHandler;

        public YtdlViewModel()
        {
            _ytdlHandler = Factory.CreateYTDLHandler();
            _jsonHandler = Factory.CreateJSONHandler();
            
            QueuedDownloads = new ObservableCollection<IVideoDownloadModel>(_jsonHandler.LoadQueue());
            
            EnqueueDownloadCommand = new MvxCommand(EnqueueDownload);
            StartDirectDownloadCommand = new MvxCommand(StartDirectDownload);
            RemoveDownloadCommand = new MvxCommand(RemoveDownload);
            StartQueueCommand = new MvxCommand(StartQueue);
        }

        // As there's seemingly no easy way to trigger this on
        // application exit call this manually when the queue is changed.
        public void SaveQueue()
        {
            _jsonHandler.SaveQueue(QueuedDownloads);
        }

        public IMvxCommand EnqueueDownloadCommand { get; set; }
        public IMvxCommand StartDirectDownloadCommand { get; set; }
        public IMvxCommand RemoveDownloadCommand { get; set; }
        public IMvxCommand StartQueueCommand { get; set; }

        public ObservableCollection<IVideoDownloadModel> QueuedDownloads
        {
            get { return _queuedDownloads; }
            set
            {
                SetProperty(ref _queuedDownloads, value);
            }
        }

        public ObservableCollection<string> DownloadOutput
        {
            get { return _downlaodOutput; }
            set
            {
                SetProperty(ref _downlaodOutput, value);
            }
        }

        public string LinkText
        {
            get { return _linkText; }
            set {
                SetProperty(ref _linkText, value);
                RaisePropertyChanged(() => CanEnqueueDownload);
                RaisePropertyChanged(() => CanStartDirectDownload);
            }
        }
        public string OptionsText
        {
            get { return _optionsText; }
            set { SetProperty(ref _optionsText, value); }
        }

        public IVideoDownloadModel SelectedDownload
        {
            get { return _selectedDownload; }
            set 
            { 
                SetProperty(ref _selectedDownload, value);
                RaisePropertyChanged(() => CanRemoveDownload);
                RaisePropertyChanged(() => CanStartQueue);
            }
        }

        public bool CanEnqueueDownload => LinkText?.Length > 0;
        public void EnqueueDownload()
        {
            int freeID = GetFreeID();
            IVideoDownloadModel addedEntry = Factory.CreateVideoDownloadModel();
            addedEntry.EntryID = freeID;
            addedEntry.Link = LinkText;
            addedEntry.Options = OptionsText;
            QueuedDownloads.Add(addedEntry);
            ClearTextFields();
            RaisePropertyChanged(() => CanStartQueue);
            SaveQueue();
        }
        private int GetFreeID()
        {
            var reservedInts = QueuedDownloads.Select(item => item.EntryID).ToList();
            return Enumerable.Range(0, int.MaxValue)
                             .Except(reservedInts)
                             .FirstOrDefault();
        }

        public bool CanStartDirectDownload => (!_processRunning && LinkText?.Length > 0);
        public async void StartDirectDownload() {
            ToggleDLButtons(setDisabled: true);
            string currentLink = LinkText;
            string currentOptions = OptionsText;
            try
            {
                LogOutput(message: "Starting to download", link: currentLink);
                Task<bool> result = _ytdlHandler.StartDownload(currentLink, currentOptions);
                bool _ = await result;
                LogOutput(message: "Finished downloading", link: currentLink);
                ClearTextFields();
            }
            catch (Exception e) {
                LogOutput(message : "Failed to download", link: currentLink);
                LogError(e.Message);
            }
            

            ToggleDLButtons(setDisabled: false);
        }

        private void ClearTextFields() {
            LinkText = string.Empty;
            _ = RaisePropertyChanged(LinkText);

            if (ClearOptions) {
                OptionsText = string.Empty;
                _ = RaisePropertyChanged(OptionsText);
            }
            
        }

        private void LogOutput(string message, string link) {
            DownloadOutput.Add($"{System.DateTime.Now:yyyy'-'MM'-'dd'T'HH':'mm':'ss} {message}: {link}");
        }
        private void LogError(string message)
        {
            DownloadOutput.Add($"{System.DateTime.Now:yyyy'-'MM'-'dd'T'HH':'mm':'ss} Error: {message}");
        }


        public bool CanRemoveDownload => SelectedDownload != null;
        public void RemoveDownload() {
            QueuedDownloads.Remove(SelectedDownload);
            SaveQueue();
        }

        public bool CanStartQueue => (QueuedDownloads?.Count > 0 && !_processRunning);

        async public void StartQueue() {
            List<IVideoDownloadModel> helperList = QueuedDownloads.ToList();
            // Disable Buttons
            ToggleDLButtons(setDisabled: true);
            foreach (var item in helperList) {
                string link = item.Link;
                string options = item.Options;
                try
                {
                    LogOutput(message: "Starting to download", link: link);
                    Task<bool> result = _ytdlHandler.StartDownload(link, options);
                    _ = await result;
                    LogOutput(message: "Finished downloading", link: link);
                }
                catch (Exception e)
                {
                    LogOutput(message: "Failed to download", link: link);
                    LogError(e.Message);
                }
                
                
                QueuedDownloads.Remove(item);
                SaveQueue();
            }
            // re-enable buttons
            ToggleDLButtons(setDisabled : false);
        }

        private bool CanUpdateLocation => !_processRunning;

        private string _ytdlloc = "F:/YTDL/youtube-dl.exe";

        public string YTDLLoc
        {
            get { return _ytdlloc; }
            set { 
                SetProperty(ref _ytdlloc, value);
                UpdateYTDLLoc();
            }
        }

        private void ToggleDLButtons(bool setDisabled) {
            _processRunning = setDisabled;
            _ = RaisePropertyChanged(() => CanStartDirectDownload);
            _ = RaisePropertyChanged(() => CanStartQueue);
            _ = RaisePropertyChanged(() => CanUpdateLocation);
        }

        private void UpdateYTDLLoc() {
            _ytdlHandler.UpdateFileLoc(YTDLLoc);
        }

        private bool _clearOptions = false;

        public bool ClearOptions
        {
            get { return _clearOptions; }
            set { SetProperty(ref _clearOptions, value); }
        }


    }
}
