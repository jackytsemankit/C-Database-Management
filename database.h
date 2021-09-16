/* database.h */
#include <string>
#include <vector>
using namespace std;
typedef struct profile_t {
    //Define variable to store a student profile
    string name;
    string id;
    string phone;
    
} Profile;
typedef struct grade_t {
    //Define variables to store the grade for a student in a specific class
    string id;
    string class_id;
    double grade;
} Grade;
class Database {
    private:
    // Define some data structure using STL containers here to store all students' profiles and the grade records.
        vector<Grade>gr;
        vector<Profile>pr;

        
    public:
        bool add_profile(string id, string name, string phone);
        bool del_profile(string id);
        bool add_grade(string id, string class_id, double grade);
        bool del_grade(string id, string class_id);
    //Display data
    void display_profiles();
    void display_grades(string class_id);
};
