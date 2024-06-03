#include "wx/wx.h"

// declare the application class
class MyApp : public wxApp
{
public:
  // called on application startup
  virtual bool OnInit(); /* virtual indicates defined later */
};

class MyFrame : public wxFrame
{
public:
  // Constructor
  MyFrame(const wxString& title);

  // Event Handlers
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

private:
  // This class handles events
  DECLARE_EVENT_TABLE()
};

// Impletemnts MyApp& GetApp()
DECLARE_APP(MyApp)

// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)

// Initialize the application
bool MyApp::OnInit()
{
  // Create the main application window
  MyFrame *frame= new MyFrame(wxT("Minimal wxWidgets App"));

  // Show it!
  frame->Show(true);

  // Start the Event Loop
  return true;
}

// Event table for MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& Event)
{
  wxString msg;
  msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);
  wxMessageBox(msg, wxT("About Minimal"),
               wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
  // Destroy the frame
  Close();
}

//#include "mondrian.xpm"

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
  // Set the frame icon
  // SetIcon(wxIcon(mondrian_xpm));

  // Create the menu bar
  wxMenu *fileMenu= new wxMenu;

  // The "About" item should be in the help menu
  wxMenu *helpMenu= new wxMenu;
  
  helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
                   wxT("Show about dialog"));

  fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
                   wxT("Quit this program"));

  // Now append the freshly created menu to the menu bar
  wxMenuBar *menuBar= new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  menuBar->Append(helpMenu, wxT("&Help"));

  // ... and attach this menu bar to the frame
  SetMenuBar(menuBar);

  //Create a status bar just for fun
  CreateStatusBar(2);
  SetStatusText(wxT("Welcome to wxWidgets!"));

  /* create a button! */
  wxButton *button= new wxButton(this, wxID_OK, "Save Scum!");
}
