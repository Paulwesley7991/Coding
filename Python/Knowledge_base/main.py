import wx

class MyFrame(wx.Frame):
    def __int__(self, parent, title):
        super(MyFrame, self).__init__(parent, title=title)

class Myapp(wx.App):
    def OnInit(self):
        self.frame = MyFrame(parent = None, title= "Our First WIndow", (600, 500))
        self.frame.Show()

        return True

app = Myapp()
app.MainLoop()