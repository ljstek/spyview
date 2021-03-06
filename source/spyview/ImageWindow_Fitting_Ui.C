// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include "ImageWindow_Fitting_Ui.h"
#include <FL/Fl_File_Chooser.H>
#include "ImageWindow.H"

void NewFitFuncWindow::cb_cancel_i(Fl_Button*, void*) {
  delete this;
}
void NewFitFuncWindow::cb_cancel(Fl_Button* o, void* v) {
  ((NewFitFuncWindow*)(o->parent()->user_data()))->cb_cancel_i(o,v);
}

void NewFitFuncWindow::cb_Ok_i(Fl_Return_Button*, void*) {
  Fitter->HandleEditDialog(this);
delete this;
}
void NewFitFuncWindow::cb_Ok(Fl_Return_Button* o, void* v) {
  ((NewFitFuncWindow*)(o->parent()->user_data()))->cb_Ok_i(o,v);
}

NewFitFuncWindow::NewFitFuncWindow(Fitting::FitFunction *ff ) {
  { newfitfunc = new Fl_Double_Window(545, 385, "New Fit Function");
    newfitfunc->user_data((void*)(this));
    { cancel = new Fl_Button(375, 350, 74, 25, "Cancel");
      cancel->callback((Fl_Callback*)cb_cancel);
    } // Fl_Button* cancel
    { Fl_Input* o = initialization = new Fl_Input(5, 20, 530, 60, "Initialization");
      initialization->type(4);
      initialization->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->initialization.c_str());
    } // Fl_Input* initialization
    { Fl_Input* o = definition = new Fl_Input(5, 180, 530, 25, "Function");
      definition->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->definition.c_str());
    } // Fl_Input* definition
    { Fl_Input* o = description = new Fl_Input(5, 270, 385, 70, "Description");
      description->type(4);
      description->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->description.c_str());
    } // Fl_Input* description
    { Fl_Input* o = name = new Fl_Input(5, 225, 530, 25, "Name");
      name->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->name.c_str());
    } // Fl_Input* name
    { Fl_Return_Button* o = new Fl_Return_Button(460, 350, 76, 25, "Ok");
      o->callback((Fl_Callback*)cb_Ok);
    } // Fl_Return_Button* o
    { Fl_Input* o = guess = new Fl_Input(5, 100, 530, 60, "Initial Guess Processing");
      guess->tooltip("Gnuplot code to go from a user\'s mouse clicks to an initial fit guess.  You \
are given xbar, ybar, sigx, and sigy, and cov, with the obvious definitions.");
      guess->type(4);
      guess->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->guess.c_str());
    } // Fl_Input* guess
    { Fl_Input* o = center = new Fl_Input(400, 270, 135, 25, "Center");
      center->tooltip("Name of variable to use for the peak \"center\" in the overlays.");
      center->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->center.c_str());
    } // Fl_Input* center
    { Fl_Input* o = width = new Fl_Input(400, 310, 135, 25, "Width");
      width->tooltip("Name of variable to use for the peak \"center\" in the overlays.");
      width->align(FL_ALIGN_TOP_LEFT);
      if(ff) o->value(ff->width.c_str());
    } // Fl_Input* width
    newfitfunc->end();
  } // Fl_Double_Window* newfitfunc
  editing = ff;
if(editing != NULL)
  newfitfunc->label("Edit Fit Function");
newfitfunc->show();
}

NewFitFuncWindow::~NewFitFuncWindow() {
  newfitfunc->hide();
delete newfitfunc;
}

void FitControls::cb_funcs_i(Fl_Browser*, void*) {
  Fitter->SelectFitFunction();
}
void FitControls::cb_funcs(Fl_Browser* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_funcs_i(o,v);
}

void FitControls::cb_New_i(Fl_Button*, void*) {
  new NewFitFuncWindow(NULL);
}
void FitControls::cb_New(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_New_i(o,v);
}

void FitControls::cb_current_i(Fl_Browser*, void*) {
  Fitter->update();
}
void FitControls::cb_current(Fl_Browser* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_current_i(o,v);
}

void FitControls::cb_Delete_i(Fl_Button*, void*) {
  new NewFitFuncWindow(NULL);
}
void FitControls::cb_Delete(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Delete_i(o,v);
}

void FitControls::cb_Add_i(Fl_Button*, void*) {
  Fitter->AddFitInstance();
}
void FitControls::cb_Add(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Add_i(o,v);
}

void FitControls::cb_Erase_i(Fl_Button*, void*) {
  Fitter->DelFitInstance();
}
void FitControls::cb_Erase(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Erase_i(o,v);
}

void FitControls::cb_fitall_i(Fl_Button*, void*) {
  Fitter->fit(NULL);
}
void FitControls::cb_fitall(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_fitall_i(o,v);
}

void FitControls::cb_Fit_i(Fl_Button*, void*) {
  Fitter->fit(Fitter->CurrentFitInstance());
}
void FitControls::cb_Fit(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Fit_i(o,v);
}

void FitControls::cb_Clear_i(Fl_Button*, void*) {
  Fitter->ClearInitialGuess();
}
void FitControls::cb_Clear(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_Clear_i(o,v);
}

void FitControls::cb_Apply_i(Fl_Button*, void*) {
  Fitter->UseInitialGuess();
}
void FitControls::cb_Apply(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_Apply_i(o,v);
}

void FitControls::cb_overlayPeaks_i(Fl_Light_Button*, void*) {
  Fitter->update();
}
void FitControls::cb_overlayPeaks(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_overlayPeaks_i(o,v);
}

void FitControls::cb_overlayWidths_i(Fl_Light_Button*, void*) {
  Fitter->update();
}
void FitControls::cb_overlayWidths(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_overlayWidths_i(o,v);
}

void FitControls::cb_plot_fit_i(Fl_Light_Button*, void*) {
  Fitter->update();
}
void FitControls::cb_plot_fit(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_plot_fit_i(o,v);
}

void FitControls::cb_plot_individual_i(Fl_Light_Button*, void*) {
  Fitter->update();
}
void FitControls::cb_plot_individual(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_plot_individual_i(o,v);
}

void FitControls::cb_plot_residual_i(Fl_Light_Button*, void*) {
  Fitter->update();
}
void FitControls::cb_plot_residual(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->parent()->user_data()))->cb_plot_residual_i(o,v);
}

void FitControls::cb_lctype_i(Fl_Choice*, void*) {
  Fitter->updateDirection();
}
void FitControls::cb_lctype(Fl_Choice* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_lctype_i(o,v);
}

Fl_Menu_Item FitControls::menu_lctype[] = {
 {"Vertical", 0,  0, (void*)(VERTLINE), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Horizontal", 0,  0, (void*)(HORZLINE), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

void FitControls::cb__i(Fl_Button*, void*) {
  Fitter->moveLineCut(1,false);
}
void FitControls::cb_(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb__i(o,v);
}

void FitControls::cb_1_i(Fl_Button*, void*) {
  Fitter->moveLineCut(-1,false);
}
void FitControls::cb_1(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_1_i(o,v);
}

void FitControls::cb_Copy_i(Fl_Button*, void*) {
  Fitter->moveLineCut(1,true);
}
void FitControls::cb_Copy(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Copy_i(o,v);
}

void FitControls::cb_Copy1_i(Fl_Button*, void*) {
  Fitter->moveLineCut(-1,true);
}
void FitControls::cb_Copy1(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Copy1_i(o,v);
}

void FitControls::cb_lock_i(Fl_Button*, void*) {
  Fitter->LockFitInstance();
}
void FitControls::cb_lock(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_lock_i(o,v);
}

#include <FL/Fl_Image.H>
static unsigned char idata_padlock[] =
{183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,0,
0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,
255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,
0,0,0,255,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,
183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,
183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,
0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,
183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,
183,56,154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,
183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,
183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,
0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,
154,0,183,56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,
56,154,0,183,56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,
183,56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,183,56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,
0,0,255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,
56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,
183,56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,
0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,
56,154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,
183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,
0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,56,
154,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,
0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,56,154,
0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,
56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,
0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,
0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,56,
154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,183,56,154,0,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,56,154,0,
183,56,154,0,183,56,154,0};
static Fl_RGB_Image image_padlock(idata_padlock, 21, 20, 4, 0);

void FitControls::cb_Push_i(Fl_Button*, void*) {
  Fitter->PushStack();
}
void FitControls::cb_Push(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Push_i(o,v);
}

void FitControls::cb_Pop_i(Fl_Button*, void*) {
  Fitter->PopStack();
}
void FitControls::cb_Pop(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Pop_i(o,v);
}

void FitControls::cb_Clear1_i(Fl_Button*, void*) {
  printf("%p\n",this);
Fitter->ClearStack();
}
void FitControls::cb_Clear1(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Clear1_i(o,v);
}

void FitControls::cb_undo_i(Fl_Button*, void*) {
  Fitter->PopUndo();
}
void FitControls::cb_undo(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_undo_i(o,v);
}

void FitControls::cb_redo_i(Fl_Button*, void*) {
  Fitter->PopRedo();
}
void FitControls::cb_redo(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_redo_i(o,v);
}

void FitControls::cb_Save_i(Fl_Button*, void*) {
  char *fname = fl_file_chooser("Save Fit","Saved Fit (*.fit)",Fitter->DefaultName().c_str());
if(fname != NULL)
  Fitter->SaveFit(fname);
}
void FitControls::cb_Save(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

void FitControls::cb_Load_i(Fl_Button*, void*) {
  char *fname = fl_file_chooser("Load Fit","Saved Fit (*.fit)",Fitter->DefaultName().c_str());
  if(fname != NULL)
    Fitter->LoadFit(fname);
}
void FitControls::cb_Load(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

void FitControls::cb_unlock_i(Fl_Button*, void*) {
  Fitter->LockFitInstance();
}
void FitControls::cb_unlock(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_unlock_i(o,v);
}

static unsigned char idata_openpad[] =
{183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,183,200,50,0,
183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,
0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,
255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,
255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,
0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,
50,0,183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,
0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,
183,200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,
0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,
200,50,0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,
0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,
0,0,255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0,183,200,50,
0,183,200,50,0,183,200,50,0,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,
0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,255,0,0,0,
255,0,0,0,255,0,0,0,255,183,200,50,0,183,200,50,0,183,200,50,0};
static Fl_RGB_Image image_openpad(idata_openpad, 21, 20, 4, 0);

void FitControls::cb_Export_i(Fl_Button*, void*) {
  char *fname = fl_file_chooser("Output as Text","Saved data (*.dat)",Fitter->DefaultName(".dat").c_str());
  if(fname != NULL)
    Fitter->SaveText(fname);
}
void FitControls::cb_Export(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Export_i(o,v);
}

void FitControls::cb_Fit1_i(Fl_Button*, void*) {
  Fitter->FitInSequence();
}
void FitControls::cb_Fit1(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Fit1_i(o,v);
}

void FitControls::cb_fitlimit_i(Fl_Input*, void*) {
  Fitter->updateFitLimit();
}
void FitControls::cb_fitlimit(Fl_Input* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_fitlimit_i(o,v);
}

void FitControls::cb_Debug_i(Fl_Light_Button* o, void*) {
  Gnuplot_Interface::debugMode = o->value();
}
void FitControls::cb_Debug(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Debug_i(o,v);
}

void FitControls::cb_Edit_i(Fl_Button*, void*) {
  new NewFitFuncWindow(Fitter->CurrentFitFunction());
}
void FitControls::cb_Edit(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_Edit_i(o,v);
}

void FitControls::cb_2_i(Fl_Button*, void*) {
  Fitter->bump(-0.002);
}
void FitControls::cb_2(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_2_i(o,v);
}

void FitControls::cb_3_i(Fl_Button*, void*) {
  Fitter->bump(0.002);
}
void FitControls::cb_3(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_3_i(o,v);
}

void FitControls::cb_4_i(Fl_Button*, void*) {
  Fitter->bump(0.02);
}
void FitControls::cb_4(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_4_i(o,v);
}

void FitControls::cb_5_i(Fl_Button*, void*) {
  Fitter->bump(-0.02);
}
void FitControls::cb_5(Fl_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_5_i(o,v);
}

void FitControls::cb_superpose_i(Fl_Light_Button*, void*) {
  if(superpose->value())
  fitall->activate();
else
  fitall->deactivate();
}
void FitControls::cb_superpose(Fl_Light_Button* o, void* v) {
  ((FitControls*)(o->parent()->user_data()))->cb_superpose_i(o,v);
}

FitControls::FitControls() {
  { win = new Fl_Double_Window(825, 405, "Fit Controls");
    win->user_data((void*)(this));
    { funcs = new Fl_Browser(5, 20, 225, 205, "Fitting Functions");
      funcs->type(2);
      funcs->callback((Fl_Callback*)cb_funcs);
      funcs->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Browser* funcs
    { Fl_Button* o = new Fl_Button(5, 230, 45, 25, "New");
      o->callback((Fl_Callback*)cb_New);
    } // Fl_Button* o
    { Fl_Text_Display* o = description = new Fl_Text_Display(5, 270, 275, 80, "Description");
      description->align(FL_ALIGN_TOP_LEFT);
      o->buffer(new Fl_Text_Buffer());
    } // Fl_Text_Display* description
    { Fl_Text_Display* o = definition = new Fl_Text_Display(5, 370, 275, 25, "Definition");
      definition->align(FL_ALIGN_TOP_LEFT);
      o->buffer(new Fl_Text_Buffer());
    } // Fl_Text_Display* definition
    { current = new Fl_Browser(315, 17, 215, 208, "Current Fit");
      current->type(2);
      current->callback((Fl_Callback*)cb_current);
      current->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Browser* current
    { Fl_Button* o = new Fl_Button(115, 230, 65, 25, "Delete ");
      o->callback((Fl_Callback*)cb_Delete);
      o->deactivate();
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(235, 20, 74, 25, "&Add @->");
      o->tooltip("Add a function to the fit.  Shortcut: a");
      o->shortcut(0x61);
      o->callback((Fl_Callback*)cb_Add);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(235, 50, 74, 25, "Erase @9+");
      o->tooltip("Delete the current function from the fit.");
      o->callback((Fl_Callback*)cb_Erase);
    } // Fl_Button* o
    { variables = new Fl_Scroll(540, 20, 260, 135, "Variables");
      variables->type(6);
      variables->box(FL_DOWN_BOX);
      variables->color((Fl_Color)FL_BACKGROUND2_COLOR);
      variables->end();
    } // Fl_Scroll* variables
    { fitall = new Fl_Button(315, 230, 30, 25, "Fit");
      fitall->callback((Fl_Callback*)cb_fitall);
    } // Fl_Button* fitall
    { Fl_Button* o = new Fl_Button(350, 230, 70, 25, "Fit Peak");
      o->callback((Fl_Callback*)cb_Fit);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(540, 240, 170, 45, "Initial Guess");
      o->box(FL_DOWN_BOX);
      o->align(FL_ALIGN_TOP_LEFT);
      { Fl_Button* o = new Fl_Button(550, 250, 74, 25, "Clear");
        o->callback((Fl_Callback*)cb_Clear);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(630, 250, 74, 25, "Apply");
        o->callback((Fl_Callback*)cb_Apply);
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(540, 305, 170, 45, "Overlay");
      o->box(FL_DOWN_BOX);
      o->align(FL_ALIGN_TOP_LEFT);
      { overlayPeaks = new Fl_Light_Button(550, 315, 75, 25, "Peaks");
        overlayPeaks->value(1);
        overlayPeaks->callback((Fl_Callback*)cb_overlayPeaks);
      } // Fl_Light_Button* overlayPeaks
      { overlayWidths = new Fl_Light_Button(630, 315, 75, 25, "Widths");
        overlayWidths->callback((Fl_Callback*)cb_overlayWidths);
      } // Fl_Light_Button* overlayWidths
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(540, 175, 260, 45, "Plot");
      o->box(FL_DOWN_BOX);
      o->color((Fl_Color)FL_BACKGROUND2_COLOR);
      o->align(FL_ALIGN_TOP_LEFT);
      { plot_fit = new Fl_Light_Button(550, 185, 45, 25, "Fit");
        plot_fit->value(1);
        plot_fit->callback((Fl_Callback*)cb_plot_fit);
      } // Fl_Light_Button* plot_fit
      { plot_individual = new Fl_Light_Button(600, 185, 95, 25, "Individual");
        plot_individual->value(1);
        plot_individual->callback((Fl_Callback*)cb_plot_individual);
      } // Fl_Light_Button* plot_individual
      { plot_residual = new Fl_Light_Button(700, 185, 95, 25, "Residual");
        plot_residual->callback((Fl_Callback*)cb_plot_residual);
      } // Fl_Light_Button* plot_residual
      o->end();
    } // Fl_Group* o
    { lctype = new Fl_Choice(355, 290, 165, 25, "Direction");
      lctype->down_box(FL_BORDER_BOX);
      lctype->callback((Fl_Callback*)cb_lctype);
      lctype->menu(menu_lctype);
    } // Fl_Choice* lctype
    { line = new Fl_Output(355, 260, 165, 25, "Line");
    } // Fl_Output* line
    { Fl_Button* o = new Fl_Button(405, 325, 35, 25, "@->");
      o->tooltip("Move right.  Shortcut: Right");
      o->callback((Fl_Callback*)cb_);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(365, 325, 35, 25, "@<-");
      o->tooltip("Move left.  Shortcut: Left");
      o->callback((Fl_Callback*)cb_1);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(445, 325, 75, 25, "Copy @->");
      o->tooltip("Move right and copy.  Shortcut: Shift+Right");
      o->callback((Fl_Callback*)cb_Copy);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(285, 325, 75, 25, "@<-  Copy");
      o->tooltip("Move left and copy.  Shortcut: Shift+Left");
      o->callback((Fl_Callback*)cb_Copy1);
    } // Fl_Button* o
    { lock = new Fl_Button(500, 230, 30, 25);
      lock->image(image_padlock);
      lock->callback((Fl_Callback*)cb_lock);
    } // Fl_Button* lock
    { Fl_Button* o = new Fl_Button(235, 130, 74, 25, "Push");
      o->tooltip("Add a function to the fit.  Shortcut: a");
      o->shortcut(0x61);
      o->callback((Fl_Callback*)cb_Push);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(235, 160, 74, 25, "Pop");
      o->tooltip("Add a function to the fit.  Shortcut: a");
      o->shortcut(0x61);
      o->callback((Fl_Callback*)cb_Pop);
    } // Fl_Button* o
    { Fl_Output* o = stackdepth = new Fl_Output(235, 100, 75, 25, "Stack");
      stackdepth->align(FL_ALIGN_TOP);
      o->value("0");
    } // Fl_Output* stackdepth
    { Fl_Button* o = new Fl_Button(235, 190, 74, 25, "Clear");
      o->tooltip("Add a function to the fit.  Shortcut: a");
      o->shortcut(0x61);
      o->callback((Fl_Callback*)cb_Clear1);
    } // Fl_Button* o
    { undo = new Fl_Button(725, 230, 74, 25, "Undo");
      undo->tooltip("Add a function to the fit.  Shortcut: a");
      undo->shortcut(0x61);
      undo->callback((Fl_Callback*)cb_undo);
      undo->deactivate();
    } // Fl_Button* undo
    { redo = new Fl_Button(725, 260, 74, 25, "Redo");
      redo->tooltip("Add a function to the fit.  Shortcut: a");
      redo->shortcut(0x61);
      redo->callback((Fl_Callback*)cb_redo);
      redo->deactivate();
    } // Fl_Button* redo
    { Fl_Button* o = new Fl_Button(725, 295, 74, 25, "Save...");
      o->callback((Fl_Callback*)cb_Save);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(725, 325, 74, 25, "Load...");
      o->callback((Fl_Callback*)cb_Load);
    } // Fl_Button* o
    { unlock = new Fl_Button(500, 230, 30, 25);
      unlock->image(image_openpad);
      unlock->callback((Fl_Callback*)cb_unlock);
      unlock->hide();
    } // Fl_Button* unlock
    { Fl_Button* o = new Fl_Button(725, 355, 74, 25, "Export...");
      o->callback((Fl_Callback*)cb_Export);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(425, 230, 70, 25, "Fit Seq.");
      o->callback((Fl_Callback*)cb_Fit1);
    } // Fl_Button* o
    { fitlimit = new Fl_Input(540, 370, 90, 25, "Fit Limit");
      fitlimit->type(1);
      fitlimit->callback((Fl_Callback*)cb_fitlimit);
      fitlimit->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Input* fitlimit
    { Fl_Light_Button* o = new Fl_Light_Button(635, 370, 75, 25, "Debug");
      o->callback((Fl_Callback*)cb_Debug);
    } // Fl_Light_Button* o
    { Fl_Button* o = new Fl_Button(55, 230, 55, 25, "Edit");
      o->callback((Fl_Callback*)cb_Edit);
    } // Fl_Button* o
    { Fl_Input* o = peakrange = new Fl_Input(440, 370, 90, 25, "Peak Range");
      peakrange->type(1);
      peakrange->align(FL_ALIGN_TOP_LEFT);
      o->value("-1.0");
    } // Fl_Input* peakrange
    { Fl_Button* o = new Fl_Button(328, 370, 35, 25, "@<-");
      o->tooltip("Move left.  Shortcut: Left");
      o->callback((Fl_Callback*)cb_2);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(363, 370, 35, 25, "@->");
      o->tooltip("Move right.  Shortcut: Right");
      o->callback((Fl_Callback*)cb_3);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(398, 370, 35, 25, "@>>");
      o->tooltip("Move right.  Shortcut: Right");
      o->callback((Fl_Callback*)cb_4);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(293, 370, 35, 25, "@<<");
      o->tooltip("Move right.  Shortcut: Right");
      o->callback((Fl_Callback*)cb_5);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(290, 370, 35, 15, "Bump");
      o->end();
    } // Fl_Group* o
    { superpose = new Fl_Light_Button(245, 230, 65, 25, "Super");
      superpose->tooltip("Fit superposition of functions rather than indpendent functions.  Almost cert\
ainly what you want.");
      superpose->value(1);
      superpose->callback((Fl_Callback*)cb_superpose);
    } // Fl_Light_Button* superpose
    { autoright = new Fl_Light_Button(185, 230, 55, 25, "A @->");
    } // Fl_Light_Button* autoright
    win->end();
  } // Fl_Double_Window* win
}
