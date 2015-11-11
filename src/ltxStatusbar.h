#ifndef _LTXSTATUSBARH_
#define _LTXSTATUSBARH_

#include <gtk/gtk.h>

void update_statusbar(GtkTextBuffer *buffer, GtkStatusbar *statusbar);
void mark_set_callback(GtkTextBuffer *buffer,
        const GtkTextIter *new_location, GtkTextMark *mark, gpointer data);

GtkWidget * ltx_create_statusbar();

#endif
