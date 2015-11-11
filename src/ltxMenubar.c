#include "ltxMenubar.h"
#include "ltxFileCommands.h"
#include "ltxHelpCommands.h"

#include <stdlib.h>

LTXMenubar *menu_bar;

void ltx_create_menubar_file() 
{
   
    menu_bar->filemenu = gtk_menu_new();

    menu_bar->file = gtk_menu_item_new_with_label("File");
    menu_bar->new_file = gtk_menu_item_new_with_label("New");
    menu_bar->open_file = gtk_menu_item_new_with_label("Open");
    menu_bar->save_file = gtk_menu_item_new_with_label("Save");
    menu_bar->save_file_as = gtk_menu_item_new_with_label("Save as...");
    menu_bar->quit = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar->file), menu_bar->filemenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->filemenu), menu_bar->new_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->filemenu), menu_bar->open_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->filemenu), menu_bar->save_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->filemenu), menu_bar->save_file_as);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->filemenu), menu_bar->quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->menubar), menu_bar->file);

    g_signal_connect(G_OBJECT(menu_bar->open_file), "activate", G_CALLBACK(open_file), NULL);
    g_signal_connect(G_OBJECT(menu_bar->quit), "activate", G_CALLBACK(quit), NULL);

}

void ltx_create_menubar_edit()
{
    menu_bar->editmenu = gtk_menu_new();

    menu_bar->edit = gtk_menu_item_new_with_label("Edit");
    menu_bar->undo = gtk_menu_item_new_with_label("Undo");
    menu_bar->cut = gtk_menu_item_new_with_label("Cut");
    menu_bar->copy = gtk_menu_item_new_with_label("Copy");
    menu_bar->del = gtk_menu_item_new_with_label("Delete");
    menu_bar->find = gtk_menu_item_new_with_label("Find");
    menu_bar->find_next = gtk_menu_item_new_with_label("Find Next");
    menu_bar->replace = gtk_menu_item_new_with_label("Replace");
    menu_bar->go_to = gtk_menu_item_new_with_label("Go To");
    menu_bar->select_all = gtk_menu_item_new_with_label("Select All");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar->edit), menu_bar->editmenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->undo);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->cut);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->copy);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->del);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->find);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->find_next);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->replace);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->go_to);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->editmenu), menu_bar->select_all);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->menubar), menu_bar->edit);

    /*
    g_signal_connect(G_OBJECT(menu_bar->open_file), "activate", G_CALLBACK(menu_bar->open_file), NULL);

    g_signal_connect(G_OBJECT(menu_bar->quit), "activate", G_CALLBACK(menu_bar->quit), NULL);
    */

}

void ltx_create_menubar_format() 
{
    menu_bar->formatmenu = gtk_menu_new();
    
    menu_bar->format = gtk_menu_item_new_with_label("Format");
    menu_bar->word_wrap = gtk_menu_item_new_with_label("Word Wrap"); /* check box */
    menu_bar->font = gtk_menu_item_new_with_label("Font..."); /* dialog box */

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar->format), menu_bar->formatmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->formatmenu), menu_bar->word_wrap);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->formatmenu), menu_bar->font);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->menubar), menu_bar->format);

    /* signals */

}


void ltx_create_menubar_view() 
{
    menu_bar->viewmenu = gtk_menu_new();

    menu_bar->view = gtk_menu_item_new_with_label("View");
    menu_bar->show_statusbar = gtk_menu_item_new_with_label("Show Statusbar"); /* check box */

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar->view), menu_bar->viewmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->viewmenu), menu_bar->show_statusbar);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->menubar), menu_bar->view);

    /* signals */

}

void ltx_create_menubar_help() 
{
    menu_bar->helpmenu = gtk_menu_new();

    menu_bar->help = gtk_menu_item_new_with_label("Help");
    menu_bar->about = gtk_menu_item_new_with_label("About");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar->help), menu_bar->helpmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->helpmenu), menu_bar->about);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar->menubar), menu_bar->help);

    /* signals */
    g_signal_connect(G_OBJECT(menu_bar->about), "activate", G_CALLBACK(ltx_help_about), NULL);
}

LTXMenubar * ltx_create_menubar() 
{
    menu_bar = malloc(sizeof(*menu_bar));
    menu_bar-> menubar = gtk_menu_bar_new();


    ltx_create_menubar_file();
    ltx_create_menubar_edit();
    ltx_create_menubar_format();
    ltx_create_menubar_view();
    ltx_create_menubar_help();

    return menu_bar;
}
