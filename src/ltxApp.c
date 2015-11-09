#include <gtk/gtk.h>

static void open_activated(GtkWidget *f)
{
    g_print("File -> Open activated.\n");
}

static void quit_activated(GtkWidget *f)
{
    g_print("File -> Quit activated...bye.\n");
    gtk_main_quit();
}

static void another_activated(GtkWidget *widget, gpointer data)
{
    g_print("%s clicked.\n", (gchar*)data);
}


static void update_statusbar(GtkTextBuffer *buffer,
        GtkStatusbar  *statusbar) {
    gchar *msg;
    gint row, col;
    GtkTextIter iter;

    gtk_statusbar_pop(statusbar, 0); 

    gtk_text_buffer_get_iter_at_mark(buffer,
            &iter, gtk_text_buffer_get_insert(buffer));

    row = gtk_text_iter_get_line(&iter);
    col = gtk_text_iter_get_line_offset(&iter);

    msg = g_strdup_printf("Col: %d Ln: %d", col+1, row+1);

    gtk_statusbar_push(statusbar, 0, msg);

    g_free(msg);
}

void mark_set_callback(GtkTextBuffer *buffer, 
        const GtkTextIter *new_location, GtkTextMark *mark, gpointer data) {

    update_statusbar(buffer, GTK_STATUSBAR(data));
}


int main( int argc, char *argv[])
{
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

    GtkWidget *viewport; // to scroll

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_set_size_request(window, 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "LTXApp - Lativextor");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    /* creates a menu bar, obviously */
    menubar = gtk_menu_bar_new(); 

    filemenu = gtk_menu_new(); /* creates a drop down menu */

    /* create a children for filemenu */
    file = gtk_menu_item_new_with_label("File");
    open = gtk_menu_item_new_with_label("Open"); 
    quit = gtk_menu_item_new_with_label("Quit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu); /* adds 'file' as the submenu of 'filemenu' */
    /* adds a new GtkMenuItem to the end of the menu shell's item list */
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open); 
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file); 
    //Connects GCallback function open_activated to "activate" signal for "open" menu item
    g_signal_connect(G_OBJECT(open), "activate", G_CALLBACK(open_activated), NULL);
    //Connects GCallback function quit_activated to "activate" signal for "quit" menu item
    g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(quit_activated), NULL);

    editmenu = gtk_menu_new();
    edit = gtk_menu_item_new_with_label("Edit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editmenu); /* adds 'edit' as the submenu of 'filemenu' */
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit);

    formatmenu = gtk_menu_new();
    format = gtk_menu_item_new_with_label("Format");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(format), formatmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), format);

    viewmenu = gtk_menu_new();
    view = gtk_menu_item_new_with_label("View");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), viewmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), view);

    helpmenu = gtk_menu_new();
    help = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

    grid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); 

    gtk_box_pack_start(GTK_BOX(grid), menubar, FALSE, FALSE, 0); 
   
    textview = gtk_text_view_new();
    // gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_WORD);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

    viewport = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(viewport), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(viewport), textview);
    gtk_box_pack_start(GTK_BOX(grid), viewport, TRUE, TRUE, 1); 

    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(grid), statusbar, FALSE, FALSE, 0);

    g_signal_connect(buffer, "changed", G_CALLBACK(update_statusbar), statusbar);

    g_signal_connect_object(buffer, "mark_set", G_CALLBACK(mark_set_callback), statusbar, 0);


    //Connects GCallback function gtk_main_quit to "destroy" signal for "window"
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    gtk_container_add(GTK_CONTAINER(window), grid);
    
    gtk_widget_show_all(window);

    update_statusbar(buffer, GTK_STATUSBAR(statusbar));

    gtk_main();

    return 0;
}
