#include <gtk/gtk.h>
#include <stdlib.h>
#include "ltxWindow.h"

int main( int argc, char *argv[])
{

    LTXWindow *window = malloc(sizeof(*window));

    gtk_init(&argc, &argv);
    ltx_window_init(window);
    gtk_main();

    return 0;
}
