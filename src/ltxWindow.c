#include "ltxWindow.h"

void open_activated(GtkWidget *f)
{
    g_print("File -> Open activated.\n");
}

void quit_activated(GtkWidget *f)
{
    g_print("File -> Quit activated... bye.\n");
    gtk_main_quit();
}

void update_statusbar(GtkTextBuffer *buffer, GtkStatusbar *statusbar) 
{
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
        const GtkTextIter *new_location, GtkTextMark *mark, gpointer data)
{
    update_statusbar(buffer, GTK_STATUSBAR(data));
}

void ltx_window_init(LTXWindow *ltx_window)
{
    ltx_window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_set_size_request(ltx_window->window, 800, 600);
    gtk_window_set_title(GTK_WINDOW(ltx_window->window), "LTXApp - Lativextor");
    gtk_window_set_resizable(GTK_WINDOW(ltx_window->window), FALSE);
    /* creates a menu bar, obviously */
    ltx_window->menubar = gtk_menu_bar_new(); 

    ltx_window->filemenu = gtk_menu_new(); /* creates a drop down menu */

    /* create a children for filemenu */
    ltx_window->file = gtk_menu_item_new_with_label("File");
    ltx_window->open = gtk_menu_item_new_with_label("Open"); 
    ltx_window->quit = gtk_menu_item_new_with_label("Quit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(ltx_window->file), ltx_window->filemenu); /* adds 'file' as the submenu of 'filemenu' */
    /* adds a new GtkMenuItem to the end of the menu shell's item list */
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->filemenu), ltx_window->open); 
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->filemenu), ltx_window->quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->menubar), ltx_window->file); 
    //Connects GCallback function open_activated to "activate" signal for "open" menu item
    g_signal_connect(G_OBJECT(ltx_window->open), "activate", G_CALLBACK(open_activated), NULL);
    //Connects GCallback function quit_activated to "activate" signal for "quit" menu item
    g_signal_connect(G_OBJECT(ltx_window->quit), "activate", G_CALLBACK(quit_activated), NULL);

    ltx_window->editmenu = gtk_menu_new();
    ltx_window->edit = gtk_menu_item_new_with_label("Edit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(ltx_window->edit), ltx_window->editmenu); /* adds 'edit' as the submenu of 'filemenu' */
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->menubar), ltx_window->edit);

    ltx_window->formatmenu = gtk_menu_new();
    ltx_window->format = gtk_menu_item_new_with_label("Format");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(ltx_window->format), ltx_window->formatmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->menubar), ltx_window->format);

    ltx_window->viewmenu = gtk_menu_new();
    ltx_window->view = gtk_menu_item_new_with_label("View");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(ltx_window->view), ltx_window->viewmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->menubar), ltx_window-> view);
    
    ltx_window->helpmenu = gtk_menu_new();
    ltx_window->help = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(ltx_window->help), ltx_window->helpmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(ltx_window->menubar), ltx_window->help);
    ltx_window->grid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); 
  
    gtk_box_pack_start(GTK_BOX(ltx_window->grid), ltx_window->menubar, FALSE, FALSE, 0); 

    ltx_window->textview = gtk_text_view_new();
    // gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_WORD);
    ltx_window->buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(ltx_window->textview));
    gtk_text_buffer_get_iter_at_offset(ltx_window->buffer, &ltx_window->iter, 0);

    ltx_window->viewport = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ltx_window->viewport), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(ltx_window->viewport), ltx_window->textview);
    gtk_box_pack_start(GTK_BOX(ltx_window->grid), ltx_window->viewport, TRUE, TRUE, 1); 

    ltx_window->statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(ltx_window->grid), ltx_window->statusbar, FALSE, FALSE, 0);

    g_signal_connect(ltx_window->buffer, "changed", G_CALLBACK(update_statusbar), ltx_window->statusbar);

    g_signal_connect_object(ltx_window->buffer, "mark_set", G_CALLBACK(mark_set_callback), ltx_window-> statusbar, 0);


    //Connects GCallback function gtk_main_quit to "destroy" signal for "window"
    g_signal_connect(G_OBJECT(ltx_window->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(ltx_window->window), ltx_window->grid);

    gtk_widget_show_all(ltx_window->window);

    update_statusbar(ltx_window->buffer, GTK_STATUSBAR(ltx_window->statusbar));
    //

}
