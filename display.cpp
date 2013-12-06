//This is the code for the display of the application. 

#include "header_files/display.h" 
#include "header_files/menu_bar.h"

Fl_Window *win; 
static int database_element=0;

void display(){

    win = new Fl_Window(200,100,1000,600); //Creates a new large window (Everything is inside this)    
      win->color(FL_WHITE);

    draw_image(database_element); //This is where we draw the picture in a "virtual box", and display its title/path. This is in images.cpp

    menu(database_element); //This creates the menu bar, its buttons and all its functions. this is in menu_bar.cpp
   
    //This will draw a button that will incrase the element in a vector that holds the paths to pictures. EX: Vec[0] = example1.jpg, Vec[1] = example2.jpg 
    Fl_Button* next_pic = new Fl_Button( 920, 30, 80, 600, "@+9->" );
      next_pic-> shortcut(FL_CTRL + 'd');
      next_pic-> color(FL_RED); 
      next_pic-> callback( ( Fl_Callback* ) next_pic_cb );

    //this will draw a button that will decrease the element in a vector which will then redraw the picture of the new path. 
    Fl_Button* previous_pic = new Fl_Button( 0, 30, 80, 600, "@+9<-" );
      previous_pic -> shortcut(FL_CTRL + 'a');
      previous_pic -> color(FL_RED);
      previous_pic -> callback( ( Fl_Callback* ) previous_pic_cb ); 

    //This is where the inputs for tags will be inputed.
    Fl_Input*  tag_input = new Fl_Input( 200, 550, 140, 40, "TAGS" ); 

    Fl_Button* add_tag   = new Fl_Return_Button(340,550,140,40, "ADD" ); 
      add_tag -> color(FL_RED); 
      add_tag->callback(add_tag_cb, tag_input);
    win->end();
    win->show();
}

void next_pic_cb( Fl_Widget* obj , void* )
{
   obj->label( "@+9->" );
   obj->redraw();
   database.next_pic(database_element); 
   draw_image(database_element); 
   win->redraw(); 
   
}

void previous_pic_cb( Fl_Widget* obj , void* )
{

   obj->label( "@+9<-" );
   obj->redraw();
   database.previous_pic(database_element); 
   draw_image( database_element); 
   win->redraw(); 
}


void add_tag_cb(Fl_Widget* obj, void* inp)
{
    obj->label("ADD");
    obj->resize(340,550,140,40);
    obj->redraw(); 
    string input; 
    input=static_cast<Fl_Input*>(inp)->value(); 
    database.add_tag(database_element, input); 
    cout<<database.element(database_element)<<endl; 
}
