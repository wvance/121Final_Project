//database.h

class Database // Standard way of defining the class
{
public:
  Database(); // Constructor
  ~Database(); // Destructor
  int save ();
  int load (string textfile);
  int add_tag (int element, string tag); 
  int next_pic (int &current_element);
  int previous_pic (int &current_element); 
  string display(); 
  string element(int x);
  int add_pic(string path); 
  string display_tags(int current_element);


private:
  vector<string> database_vector;
};

extern Database database;
