#include "ltxWindow.h"
#include "ltxFileCommands.h"
#include "ltxStatusbar.h"
#include "ltxMenubar.h"

void ltx_window_init(LTXWindow *ltx_window)
{
    ltx_window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_set_size_request(ltx_window->window, 800, 600);
    gtk_window_set_title(GTK_WINDOW(ltx_window->window), "LTXApp - Lativextor");
    gtk_window_set_resizable(GTK_WINDOW(ltx_window->window), FALSE);
    /* creates a menu bar, obviously */
    // ltx_window->menubar = gtk_menu_bar_new(); 
    ltx_window->menu_bar = ltx_create_menubar();
    
    ltx_window->grid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); 
    gtk_box_pack_start(GTK_BOX(ltx_window->grid), ltx_window->menu_bar->menubar, FALSE, FALSE, 0); 

    /* need to model this */
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
