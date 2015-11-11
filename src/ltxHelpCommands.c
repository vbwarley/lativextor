#include "ltxHelpCommands.h"

void ltx_help_about(GtkWidget *f) 
{

    static const gchar * const authors[] = {
        "Warley Vital",
        NULL
    };

    static const gchar comments[] = \
        {"lativextor is a simple text editor as a requirement to discipline P1."};

    GdkPixbuf *logo = gdk_pixbuf_new_from_file("logo.png", NULL);;
    
    gtk_show_about_dialog (NULL,
            "authors", authors,
            "program-name", "LTX",
            "comments", comments,
            "logo", logo,
            "title", ("About LTX - Lativextor"),
            "website", "http://latived.wordpress.com",
            "website-label", "latived.wordpress.com",
            NULL);
}
