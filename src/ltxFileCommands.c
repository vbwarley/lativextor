#include "ltxFileCommands.h"

void new_file(GtkWidget *f)
{
    g_print("File -> New activated.\n");
}

void open_file(GtkWidget *f) 
{
    g_print("File -> Open activated.\n");
}

void save_file(GtkWidget *f)
{
    g_print("File -> Save activated.\n");
}

void save_file_as(GtkWidget *f)
{
    g_print("File -> Save As activated.\n");
}

void quit(GtkWidget *f)
{
    g_print("File -> Quit activated... bye.\n");
    gtk_main_quit();
}
