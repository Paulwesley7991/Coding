import wx

class windowClass(wx.Frame):
    def __init__(self, *args, **kwargs):
        super(windowClass, self).__init__(*args, **kwargs)
        self.Center()
        self.basicGUI()

    def basicGUI(self):

        panel = wx.Panel(self)
        menuBar = wx.MenuBar()
        fileButton = wx.Menu()
        editButton = wx.Menu()

        exitItem = fileButton.Append(wx.ID_EXIT, 'Exit','status msg')

        menuBar.Append(fileButton, 'File')
        menuBar.Append(editButton, 'Edit')

        self.SetMenuBar(menuBar)
        self.Bind(wx.EVT_MENU, self.Quit, exitItem)

        wx.TextCtrl(panel, pos=(10,10), size = (250,150))

        self.SetTitle('Epic Window')
        self.Show(True)

    def Quit(self, e):
        self.Close()

if __name__ =='__main__':
    app = wx.App()
    windowClass(None,title='epic window')
    app.MainLoop()