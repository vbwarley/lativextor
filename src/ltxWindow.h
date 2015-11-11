#ifndef _LTXWINDOWH_
#define _LTXWINDOWH_
#include <gtk/gtk.h>
#include "ltxMenubar.h"

typedef struct _LTXWindow LTXWindow;

struct _LTXWindow {

    GtkWidget *window;
    GtkWidget *grid;

    LTXMenubar *menu_bar;
    GtkWidget *statusbar;

    GtkWidget *textview;
    GtkTextBuffer *buffer;
    GtkTextIter iter;
    
    GtkWidget *viewport;

};

void ltx_window_init(LTXWindow *window);

#endif
