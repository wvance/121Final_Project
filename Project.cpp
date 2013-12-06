#include "header_files/display.h"
#include "header_files/menu_bar.h"


int main() {
	database.load("Database.txt"); //This should add two elements
    display(); 
    return(Fl::run());
}