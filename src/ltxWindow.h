#include <gtk/gtk.h>

typedef struct _LTXWindow LTXWindow;

struct _LTXWindow {

    GtkWidget *window;
    GtkWidget *grid;

    GtkWidget *menubar;
    GtkWidget *statusbar;

    GtkWidget *textview;
    GtkTextBuffer *buffer;
    GtkTextIter iter;
    
    GtkWidget *filemenu;
    GtkWidget *editmenu;
    GtkWidget *viewmenu;
    GtkWidget *formatmenu;
    GtkWidget *helpmenu;

    GtkWidget *file;
    GtkWidget *open;
    GtkWidget *quit;

    GtkWidget *edit;
    GtkWidget *format;
    GtkWidget *view;
    GtkWidget *help;

    GtkWidget *viewport;

};

void open_activated(GtkWidget *f);
void quit_activated(GtkWidget *f);
void update_statusbar(GtkTextBuffer *buffer, GtkStatusbar *statusbar);
void mark_set_callback(GtkTextBuffer *buffer, 
        const GtkTextIter *new_location, GtkTextMark *mark, gpointer data);
void ltx_window_init(LTXWindow *window);
