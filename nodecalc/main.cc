// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx.h"

#include "graph/graph.h"

class MyApp: public wxApp
{
 public:
  virtual bool OnInit();
};

class MyFrame: public wxFrame
{
 public:
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
 private:
  void OnSelectColor(wxCommandEvent &event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
};

enum
{
  ID_SelectColor = 1
};

bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
  frame->Show( true );
  return true;
}

wxIMPLEMENT_APP(MyApp);

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{

  Bind(wxEVT_MENU, &MyFrame::OnSelectColor, this, ID_SelectColor);
  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
  Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);

  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_SelectColor, "&Select color...\tCtrl-S", "");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append( menuFile, "&File" );
  menuBar->Append( menuHelp, "&Help" );
  SetMenuBar( menuBar );

  CreateStatusBar();
  SetStatusText( "Welcome to wxWidgets!" );

  wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

  Graph* graph = new Graph( this );
  sizer->Add(graph, 1, wxEXPAND);

  SetSizer(sizer);
  SetAutoLayout(true);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
  Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxMessageBox( "This is a wxWidgets' Hello world sample",
                "About Hello World", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnSelectColor(wxCommandEvent &event)
{
}
