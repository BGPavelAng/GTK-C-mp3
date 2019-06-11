#include <ctype.h>
#include <stdlib.h>
#include <gtk/gtk.h>

  GtkWidget *tlab2, *tlab4, *tlab6, *tlab8, *_tlab1, *_tlab3, *_tlab10;

void clse(GtkWidget *widget, gpointer data){

gtk_widget_destroy(data);

}

void opn(GtkWidget *widget, gpointer data){

    GtkWidget *selct;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    char buff[30];
    char tbuf[30];
    char abuf[30];
    char albuf[30];
    char anbuff[30];
    char _size[30];
    char du[30];
    char comm[40];
    int len;
    float pos, dur, posdur;

    //Creacion de dialog_menu

    selct = gtk_file_chooser_dialog_new("Abrir archivo", NULL, action, ("_Cancel"), GTK_RESPONSE_CANCEL, ("_Open"), GTK_RESPONSE_ACCEPT, NULL);
    //Limitar acciones
    gtk_window_set_modal(GTK_WINDOW(selct), TRUE);

    //iniciar acciones de dialog

    if(gtk_dialog_run(GTK_DIALOG(selct)) == GTK_RESPONSE_ACCEPT){

        char *filename;
        FILE *fp;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(selct));
        sprintf(buff, "%s", filename);
        //abrir archivo
        fp = fopen(buff, "rb");
        //buscar los offsets necesarios
        fseek(fp, -125L, SEEK_END);
        fread(tbuf, sizeof(tbuf), 1, fp);
        //segundo offset
        fseek(fp, -95L, SEEK_END);
        fread(abuf, sizeof(abuf), 1, fp);
        //tercer offset
        fseek(fp, -65L, SEEK_END);
        fread(albuf, sizeof(albuf), 1, fp);
        //cuarto offset
        fseek(fp, -35L, SEEK_END);
        fread(anbuff, sizeof(anbuff), 1, fp);
        //quinto offset
        fseek(fp, -31L, SEEK_END);
        fread(comm, sizeof(comm), 1, fp);
        //tamaño del archivo
        fseek(fp, 0, SEEK_END);
        len = ftell(fp);
        pos = (((len/1000.0)/1000.0));
        sprintf(_size, "%0.1f MB", pos);
        //duracion
        posdur = ((len/1024.0)/1024.0);
        dur = ((((posdur*1024.0)*8)/320)/60);
        sprintf(du, "%0.1f", dur);
        //mostrar resultado
        gtk_label_set_text(GTK_LABEL(tlab2), tbuf);
        gtk_label_set_text(GTK_LABEL(tlab4), abuf);
        gtk_label_set_text(GTK_LABEL(tlab6), albuf);
        gtk_label_set_text(GTK_LABEL(tlab8), anbuff);
        gtk_label_set_text(GTK_LABEL(_tlab1), _size);
        gtk_label_set_text(GTK_LABEL(_tlab3), du);
        gtk_label_set_text(GTK_LABEL(_tlab10), comm);

        //liberar
        g_free(filename);
        fclose(fp);
    }

gtk_widget_destroy(selct);
}


void minf(GtkWidget *widget, gpointer data){

  GtkWidget *wi;
  GtkWidget *hbox1, *hbox2, *hbox3, *hbox4, *hbox5, *hbox6, *hbox7, *hbox8;
  GtkWidget *vbox1;
  GtkWidget *tlab1, *tlab3, *tlab5, *tlab7, *tlab9, *_tlab2, *tlab10;
  GtkWidget *but1, *but2;
  

  //iniciar ventana
  wi = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width(GTK_CONTAINER(wi), 50);
  gtk_window_set_title(GTK_WINDOW(wi), "Informacion del mp3");
  gtk_window_set_position(GTK_WINDOW(wi), GTK_WIN_POS_CENTER);
  gtk_widget_realize(wi);

  //iniciar labels y botones
  hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox8 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  hbox7 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  //inicio de los labels
  tlab1 = gtk_label_new("TITULO: ");
  tlab2 = gtk_label_new(NULL);
  tlab3 = gtk_label_new("ARTISTA: ");
  tlab4 = gtk_label_new(NULL);
  tlab5 = gtk_label_new("ALBUM: ");
  tlab6 = gtk_label_new(NULL);
  tlab7 = gtk_label_new("AÑO: ");
  tlab8 = gtk_label_new(NULL);
  tlab9 = gtk_label_new("TAMAÑO: ");
  _tlab1 = gtk_label_new(NULL);
  _tlab2 = gtk_label_new("DURACION: ");
  _tlab3 = gtk_label_new(NULL);
  tlab10 = gtk_label_new("COMENTARIO: ");
  _tlab10 = gtk_label_new(NULL);
  //acciones botones
  but1 = gtk_button_new_with_label("Examinar..");
  g_signal_connect(but1, "clicked", G_CALLBACK(opn), (gpointer)wi);
  but2 = gtk_button_new_with_label("Cancelar");
  g_signal_connect(but2, "clicked", G_CALLBACK(clse), (gpointer)wi);

  //acomodar los elementos en la ventana

    //posicion de labels
  gtk_box_pack_start(GTK_BOX(hbox1), tlab1, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox1), tlab2, FALSE, TRUE, 0);

   //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox2), tlab3, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox2), tlab4, FALSE, TRUE, 0);

   //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox3), tlab5, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox3), tlab6, FALSE, TRUE, 0);
  //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox4), tlab7, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox4), tlab8, FALSE, TRUE, 0);
  //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox5), tlab9, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox5), _tlab1, FALSE, TRUE, 0);
  //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox6), _tlab2, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox6), _tlab3, FALSE, TRUE, 0);
  //posicion labels
  gtk_box_pack_start(GTK_BOX(hbox8), tlab10, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox8), _tlab10, FALSE, TRUE, 0);
   //Posicion de botones
  gtk_box_pack_start(GTK_BOX(hbox7), but1, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox7), but2, FALSE, TRUE, 0);

  //Posicion vbox
  vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_add(GTK_CONTAINER(wi), vbox1);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox1, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox2, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox3, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox4, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox5, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox6, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox8, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox7, FALSE, TRUE, 0);

  gtk_widget_show_all(wi);

}

int main (int argc, char *argv[])
{
  GtkWidget *win;
  GtkWidget *lab1;
  GtkWidget *vbox1;
  GtkWidget *hsep1;
  GtkWidget *hbox1;
  GtkWidget *but1, *but2, *but3;

  //inicializar gtk
  g_log_set_handler("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init(&argc, &argv);
  g_log_set_handler("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  //crear ventana
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  //tamaño de la gui
  gtk_container_set_border_width(GTK_CONTAINER(win),58 );
  //titulo
  gtk_window_set_title(GTK_WINDOW(win), "Lector y Modificador de mp3");
  //posicion
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
  gtk_widget_realize(win);
  //cerrar ventana
  g_signal_connect(win, "destroy", gtk_main_quit, NULL);
  //repeticion para mantener ventana

  //creacion de label separado por hbox para acomodar
  vbox1 = gtk_box_new(FALSE, 6);
  lab1 = gtk_label_new("Software libre para el manejo, configuracion y modificacion\n de las propiedades de los archivos mp3\n\n Hecho por BG\n");
  //a la ventana se le agrega el elemento
  gtk_container_add(GTK_CONTAINER(win), vbox1);
  //al elemento se le agrega el objetivo para no usar la ventana principal
  gtk_box_pack_start(GTK_BOX(vbox1), lab1, TRUE, TRUE, 0);

  //separador
  hsep1 = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start(GTK_BOX(vbox1), hsep1, FALSE, TRUE, 20);

  //boton para ver los datos
  hbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
  but1 = gtk_button_new_with_label("Mostar informacion");
  g_signal_connect(but1, "clicked", G_CALLBACK(minf), (gpointer)win);
  gtk_box_pack_start(GTK_BOX(hbox1), but1, FALSE, TRUE, 0);

  //boton para modificar los datos
  but2 = gtk_button_new_with_label("Modificar informacion");
  gtk_box_pack_start(GTK_BOX(hbox1), but2, FALSE, TRUE, 0);

  //boton de salida
  but3 = gtk_button_new_with_label("Salir del programa");
  g_signal_connect(but3, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start(GTK_BOX(hbox1), but3, FALSE, TRUE, 0);

  //Ordenar los botones
  gtk_box_pack_start(GTK_BOX(vbox1), hbox1, FALSE, TRUE, 0);

  //mostrar todo e inicio de gtk
  gtk_widget_show_all(win);
  gtk_main ();
  return 0;
}
