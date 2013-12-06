//This holds all the declarations of the functions. 
#include "std_lib_facilities_3.h"
#include "database.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Box.H>
#include <stdlib.h>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_draw.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_PNM_Image.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_XPM_Image.H>


void display(); 
void add_tag_cb(Fl_Widget* obj, void*); 
void previous_pic_cb(Fl_Widget* obj , void* ); 
void next_pic_cb(Fl_Widget* obj , void* ); 

void draw_image(int database_element); 
