#include "header_files/display.h" 
#include "header_files/menu_bar.h"

    Fl_JPEG_Image* my_jpeg_image; 
    Fl_BMP_Image*  my_bmp_image; 
    Fl_PNG_Image*  my_png_image; 
    Fl_PNM_Image*  my_pnm_image; 
    Fl_GIF_Image*  my_gif_image; 
    Fl_Box *box; 

void draw_image(int database_element){

    const char* file_name;//This gets the path out of the elemenet
    string start_file="";
    string current=database.element(database_element); 
    for(int i=0; i<current.size();i++){
        if (current[i]!=','){
            start_file+=current[i];
        }
        else {
            break; 
        }
    }
     file_name=start_file.c_str();


    const char* error_file;
        error_file= "pictures/error_file.png";

	box = new Fl_Box(150,60,700,465,"");

    string file= file_name; 

    string jpeg_check(".jpg"); 
    string jpeg_check2(".JPG");
    string jpeg_check3(".jpeg"); 
    string jpeg_check4(".JPEG"); 

    string png_check(".png");
    string png_check2(".PNG"); 

    string gif_check(".gif"); 
    string gif_check2(".GIF"); 

    string bmp_check(".bmp"); 
    string bmp_check2(".BMP"); 

    string pnm_check(".pnm"); 
    string pnm_check2(".PNM"); 


    if  (file.find(jpeg_check) != string::npos){ 
            cout<<"You found a .jpg "<<file_name<<endl;

        my_jpeg_image = new Fl_JPEG_Image(file_name);
        Fl_Image *scaled_image = my_jpeg_image->copy(700, 450);
        box->image(scaled_image);

    }
    else if  (file.find(jpeg_check2) != string::npos){ 
            cout<<"You found a .JPG "<<file_name<<endl; 

        my_jpeg_image = new Fl_JPEG_Image(file_name);
        Fl_Image *scaled_image = my_jpeg_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if  (file.find(jpeg_check3) != string::npos){ 
            cout<<"You found a .jpeg "<<file_name<<endl; 

        my_jpeg_image = new Fl_JPEG_Image(file_name);
        Fl_Image *scaled_image = my_jpeg_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if  (file.find(jpeg_check) != string::npos){ 
            cout<<"You found a .JPEG "<<file_name<<endl; 

        my_jpeg_image = new Fl_JPEG_Image(file_name);
        Fl_Image *scaled_image = my_jpeg_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if  (file.find(png_check)  != string::npos){ 
            cout<<"You found a .png "<<file_name<<endl; 

        my_png_image =new Fl_PNG_Image(file_name);
        Fl_Image *scaled_image = my_png_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if  (file.find(png_check2)  != string::npos){ 
            cout<<"You found a .PNG "<<file_name<<endl; 

        my_png_image =new Fl_PNG_Image(file_name);
        Fl_Image *scaled_image = my_png_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if (file.find(gif_check) != string::npos){
            cout<<"You found a .gif "<<file_name<<endl; 

        my_gif_image= new Fl_GIF_Image(file_name);
        Fl_Image *scaled_image = my_gif_image->copy(700, 450);
        box->image(scaled_image);
    }    
    else if (file.find(gif_check2) != string::npos){ 
            cout<<"You found a .GIF "<<file_name<<endl; 

        my_gif_image= new Fl_GIF_Image(file_name);
        Fl_Image *scaled_image = my_gif_image->copy(700, 450);
        box->image(scaled_image);
    }    
    else if (file.find(bmp_check) != string::npos){ 
            cout<<"You found a .bmp "<<file_name<<endl; 
            
        my_bmp_image= new Fl_BMP_Image(file_name); 
        Fl_Image *scaled_image = my_bmp_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if (file.find(bmp_check2) != string::npos){ 
            cout<<"You found a .BMP "<<file_name<<endl; 

        my_bmp_image= new Fl_BMP_Image(file_name); 
        Fl_Image *scaled_image = my_bmp_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if (file.find(pnm_check)!= string::npos){ 
            cout<<"You found a .pnm "<<file_name<<endl; 

        my_pnm_image= new Fl_PNM_Image(file_name); 
        Fl_Image *scaled_image = my_pnm_image->copy(700, 450);
        box->image(scaled_image);
    }
    else if (file.find(pnm_check2)!= string::npos){ 
            cout<<"You found a .PNM "<<file_name<<endl; 

        my_pnm_image= new Fl_PNM_Image(file_name); 
        Fl_Image *scaled_image = my_pnm_image->copy(700, 450);
        box->image(scaled_image);
    }
    else {
        cout<<"You did not load an appropriate image..."<<endl;
        my_png_image = new Fl_PNG_Image(error_file);
        Fl_Image *scaled_image = my_png_image->copy(700, 450);
        box->image(scaled_image);
    }

    
    
}

