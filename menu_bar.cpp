//This code is dedicated to the menu bar ontop of the application. 

#include "header_files/display.h"
#include "header_files/menu_bar.h"


void menu(int database_element){
    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,1000,30);
    menu->add("File/Open",     FL_CTRL+'o', Open_CB);
    menu->add("File/Open URL", FL_CTRL+'u', Open_URL_CB); 
    menu->add("File/Load File",FL_CTRL+'y', Load_File_CB); 
    menu->add("File/Save",     FL_CTRL+'s', Save_CB);
    menu->add("File/Quit",     FL_CTRL+'q', Quit_CB);
    menu->add("Edit/Search",   FL_CTRL+'c', Search_CB);
    menu->add("View/Tags",     FL_CTRL+'t', Tags_CB); 
    //menu->add("View/Exif",     FL_CTRL+'e', Exif_CB);
    menu->add("View/About",    FL_CTRL+'/', About_CB);
}

//---------------THIS IS TAKEN FROM FLTK DOCUMENTATION-------------------
//-----LOADS A FILE CHOOSER AND ALLOWS USER TO PICK A FILE---------------
void Load_File_CB(Fl_Widget*, void*){
    Fl_Native_File_Chooser file_chooser;
        file_chooser.title("Pick a Saved File/ Database");
        file_chooser.type(Fl_Native_File_Chooser::BROWSE_FILE);
        file_chooser.filter("Save Files\t*.{txt}\n");
        file_chooser.directory("/home/ugrads/w/wvance/");  // default directory to use

    switch ( file_chooser.show() ) {// Show native chooser
        case -1:    cout<<"ERROR " <<file_chooser.errmsg()<<endl;   break;  // ERROR
        case  1:    cout<<"CANCEL"                        <<endl;   break;  // CANCEL
        default:    cout<<file_chooser.filename()         <<endl;   break;  // FILE CHOSEN
    } 
    string load_file=file_chooser.filename(); 
    database.load(load_file); 
}


//------------------------------------------------------------------------
//---------THIS FUNCTION IS USED TO ADD A NEW PICTURE TO THE DATABASE-----
void Open_CB(Fl_Widget*, void*)  {
    Fl_Native_File_Chooser file_chooser;
        file_chooser.title("Pick a Photo");
        file_chooser.type(Fl_Native_File_Chooser::BROWSE_FILE);
        file_chooser.filter("Photos\t*.{jpg,jpeg,gif,bmp,png}\n" "Program Files\t*.{cxx,h,c,cpp}");
        file_chooser.directory("/home/ugrads/w/wvance");  // default directory to use

    switch ( file_chooser.show() ) {// Show native chooser
        case -1:    cout<<"ERROR " <<file_chooser.errmsg()<<endl;   break;  // ERROR
        case  1:    cout<<"CANCEL"                        <<endl;   break;  // CANCEL
        default:    cout<<file_chooser.filename()         <<endl;   break;  // FILE CHOSEN
    } 
    string open_file= file_chooser.filename(); 
    database.add_pic(open_file); 
}


//------------------------------------------------------------------------
//---------THIS OPENS A WINDOW THAT DISPLAYS THE TAGS IN THE VECTOR-------
void Tags_CB(Fl_Widget *w, void *) {
    Fl_Window   *win      = new Fl_Window(500, 300,450,200);
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 450-40, 200-75, "Picture Tags");
        disp ->buffer(buff);
        win  ->resizable(*disp);
        win  ->show();
    string output; 
    output = database.display(); 
    buff->text(output.c_str()); //Just display entire text file if needed 
}

//------------------------------------------------------------------------
//---------THIS OPENS A WINDOW TO ALLOW USER TO INPUT A URL TO GRAB-------
void Open_URL_CB(Fl_Widget *w, void *){
    Fl_Window *win = new Fl_Window(500, 300,450,200);
    Fl_Input*  URL_input = new Fl_Input         ( 100, 110, 220, 40, "URL Picture" );
    Fl_Button* add_URL   = new Fl_Return_Button (320,110,110,40, "ADD" ); 
        add_URL -> color   (FL_RED); 
        add_URL -> callback(add_URL_CB, URL_input); 

    Fl_Text_Buffer  *buff = new Fl_Text_Buffer  ();
    Fl_Text_Display *disp = new Fl_Text_Display (20, 20, 450-40, 200-130, "URL Grabber");
        disp ->buffer(buff);

    win  ->resizable(*disp);
    win  ->show();
    buff ->text("\n" "                 Please Place your URL Input Below: \n");
}

void add_URL_CB(Fl_Widget *w, void* inp){//This will take the URL in the buffer and do stuff to it. hw3pr3
    string input_url; 
    input_url=static_cast<Fl_Input*>(inp)->value(); 

    string file_type; 
    if (input_url.find(".jpeg")){
        file_type="pictures/download.jpeg";
    }
    else if (input_url.find(".bmp")){
        file_type="pictures/download.bmp"; 
    }
    else if (input_url.find(".gif")){
        file_type="pictures/download.gif";
    }
    else if (input_url.find("pnm")){
        file_type="pictures/download.pnm";
    }
    else if (input_url.find(".png")){
        file_type="pictures/download.png"; 
    }
    else if (input_url.find(".png")){
        file_type="pictures/download.png"; 
    }
    else (cout<<"You did not enter a valid picture URL"); 

     string command = "wget "+ input_url +" -O"+ file_type;

     system(command.c_str());
     string save_url_path; 

     database.add_pic(file_type);
}

//------------------------------------------------------------------------
//----------SEARCHES THE TAGS WITHIN THE VECTOR---------------------------
void Search_CB(Fl_Widget *w, void *) {

}

//------------------------------------------------------------------------
//-------------QUITS THE PROGRAM ASKS USER TO SAVE------------------------
void Quit_CB(Fl_Widget *, void *) {
    Fl_Window *win = new Fl_Window(500, 300,450,200,"WOULD YOU LIKE TO SAVE?");
    Fl_Button* YES = new Fl_Button( 100, 50, 80, 70, "YES" );
        YES -> color   (FL_RED); 
        YES -> callback( ( Fl_Callback* ) YES_CB ); 
    Fl_Button* NO = new Fl_Button( 250, 50, 80, 70, "NO" );
        NO -> color   (FL_RED); 
        NO -> callback( ( Fl_Callback* ) NO_CB );  
    win -> color(FL_WHITE);
    win  ->show();
}

void YES_CB(Fl_Widget *w, void *) {
    database.save(); 
    cout<<"You Saved Your File:"<<endl;
    exit(0); 
}

void NO_CB(Fl_Widget *w, void *) {
    exit(0); 
}

//------------------------------------------------------------------------
//---------SAVES THE PROGRAM TO A TEXTFILE WHICH CAN BE OPENED LATER------
void Save_CB(Fl_Widget *, void *) {
    database.save(); 
}

//------------------------------------------------------------------------
//------------THIS IS AN ADVANCED FEATURE THAT DOESNT WORK YET------------
void Exif_CB(Fl_Widget *, void *) {
    Fl_Window *win = new Fl_Window(500,300,400,150);
    win->end();
    win->show();
}

//------------------------------------------------------------------------
//------------------ABOUT ME WINDOW WITH WHAT PROGRAM DOES----------------
void About_CB(Fl_Widget*, void*) {
     Fl_Window       *win  = new Fl_Window(500, 300,450,200);
     Fl_Text_Buffer  *buff = new Fl_Text_Buffer();
     Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 450-40, 200-40, "About PicView");
        disp ->buffer(buff);
        win  ->resizable(*disp);
        win  ->show();
     buff->text("\n"
                "       This program 'PicView' stores and displays an image.   \n"
                "      These images are a part of a database, saved with tags.  \n"
                "        Use the menu bar above to access additional features.   \n"
                "   --------------------------------------------------------------------------- \n"
                "      Picview was created as a project at TAMU for CSCE 121.  \n"
                "                    Credit for this project goes to:          \n"
                "               Wesley Vance, Alex Vincent, Dawson Turechek            \n" );
} 
//------------------------------------------------------------------------
//------------------------------------------------------------------------
