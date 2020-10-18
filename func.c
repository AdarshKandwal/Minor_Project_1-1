#include <gtk/gtk.h>
#include <string.h>

char arr[50],arr2[50];

static void open_dialog(GtkWidget* button, gpointer window)
{
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Choose a folder and select any file.", GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN , GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
	gtk_widget_show_all(dialog);
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
	gint resp = gtk_dialog_run(GTK_DIALOG(dialog));



	if(resp == GTK_RESPONSE_OK)
    {
	    strcpy(arr,gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
	    strcpy(arr2,gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog)));

	}
	else
		g_print("You pressed Cancel\n");
	gtk_widget_destroy(dialog);
}