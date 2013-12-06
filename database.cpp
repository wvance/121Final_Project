#include "header_files/display.h" 
#include "header_files/menu_bar.h"

//database.cpp
Database database;

Database::Database(){//Default database savefile to load. 
}

Database::~Database(){
}

int Database::save()//This should open a textfile, and save the contents of the vector into the textfile. 
{
	ofstream save_data; 
		if (!save_data){
   			cout << "File couldn't be opened." << endl;
    	return -1;
		}
	save_data.open("Database.txt"); 

	for (int i=0; i< database_vector.size(); i++){
		save_data<<database_vector[i]<<"\n"; 
	}
	save_data.close(); 
	return 1; 
}

int Database::load(string textfile)  //Loads a .txt file into a vector
{
	string line; 
	ifstream load_data; 
		if (!load_data){
    		cout << "File couldn't be opened." << endl;
    		return -1;
    	}
	load_data.open(textfile); 
		while (getline(load_data, line)){
   			database_vector.push_back(line);
		}
	load_data.close(); 
	return 1; 
}

int Database::add_pic(string path){ //This adds a picture to the vector in a new element. 
	database_vector.push_back(path); 
	return 1; 
}

int Database::add_tag(int element, string tag){ // This function adds a tag to the vector then later will save it to the database.txt file. 
	database_vector[element] += ","; 			// Find element then add a ',' to indicate a new tag. 
	database_vector[element]+= tag; 
	return 1; 
}

int Database::next_pic(int &current_element){ 
	if (current_element != database_vector.size()-1){ //Handles cases when you click next button and there isnt element
		++current_element; 
	}
		else (cout<<"There are no more pictures"<<endl); 
	return current_element; 
}

int Database::previous_pic(int &current_element){
	if (current_element!=0){
	--current_element;	
	}
	else(cout<<"There are no more pictures"<<endl); 
	return current_element;
}

string Database::display(){
// while()	
	for (int i=0;i<database_vector.size();i++)
	{	
		string output; 
		output=database_vector[i]+"\n";
		return output; 
	}
}	

string Database::display_tags(int current_element){
	string display_tags;
	display_tags= database_vector[current_element];
	return display_tags;
}	

string Database::element(int x){//This returns the string of whatever is in the vector. 
	string element;
	element = database_vector[x]; 
	return element;
}



