#ifndef _LTXMENUBARH_
#define _LTXMENUBARH_
#include <gtk/gtk.h>

typedef struct _LTXMenubar LTXMenubar;

struct _LTXMenubar {
    
    GtkWidget *menubar;
    GtkWidget *filemenu;
    GtkWidget *editmenu;
    GtkWidget *viewmenu;
    GtkWidget *formatmenu;
    GtkWidget *helpmenu;

    GtkWidget *file;
    GtkWidget *new_file;
    GtkWidget *open_file;
    GtkWidget *save_file;
    GtkWidget *save_file_as;
    GtkWidget *quit;

    GtkWidget *edit;
    GtkWidget *undo; /* nem sei */
    GtkWidget *cut;
    GtkWidget *copy;
    GtkWidget *del;
    GtkWidget *find;
    GtkWidget *find_next;
    GtkWidget *replace;
    GtkWidget *go_to;
    GtkWidget *select_all;
    // time/date

    GtkWidget *format;
    GtkWidget *word_wrap;
    GtkWidget *font;

    GtkWidget *view;
    GtkWidget *show_statusbar;

    GtkWidget *help;
    GtkWidget *about;

};

LTXMenubar * ltx_create_menubar();
void ltx_create_menubar_file();
void ltx_create_menubar_edit();
void ltx_create_menubar_format();
void ltx_create_menubar_view();
void ltx_create_menubar_help();

#endif
