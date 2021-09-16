#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "database.h"
using namespace std;

bool compare(const Profile & , const Profile &);
bool comparemark(const Grade & a, const Grade & b);

bool Database::add_profile(string id, string name, string phone){
    vector<Profile>::iterator itr;
    for (itr=pr.begin();itr!=pr.end();itr++){
        if (itr->id == id){
            itr->name=name;
            itr->phone=phone;
            cout<<"Profile Updated"<<endl;
            return true;
        }
    }
    Profile p;
    p.id=id;
    p.name=name;
    p.phone=phone;
    pr.push_back(p);
    return true;
}

bool Database::del_profile(string id){
    bool recordexists=false;
    vector<Profile>::iterator itr;
    vector<Grade>::iterator itr1;
    for (itr=pr.begin();itr!=pr.end();itr++){
        if (itr->id == id){
            recordexists=true;
            pr.erase(itr);
            break;
        }
    }
    
    if (recordexists){
        for (itr1=gr.begin();itr1!=gr.end();itr1++){
            if (itr1->id == id){
                gr.erase(itr1);
            }
        }
    }
    
    else{cout<<"Record Not Exists"<<endl;}
    
    return recordexists;
}

bool Database::add_grade(string id, string class_id, double grade){
    vector<Grade>::iterator itr;
    vector<Profile>::iterator itr1;
    bool exist=false;
    for (itr1=pr.begin();itr1!=pr.end();itr1++){
        if (itr1->id == id){exist=true;break;}
    }
    
    if (exist!=true){
        cout<<"Student Not Exists"<<endl;
        return false;
    }
    
    for (itr=gr.begin();itr!=gr.end();itr++){
        if (itr->id == id && itr->class_id==class_id){
            itr->grade=grade;
            cout<<"Grade Updated"<<endl;
            return false;
        }
    }
    Grade g;
    g.id=id;
    g.class_id=class_id;
    g.grade=grade;
    gr.push_back(g);
    return true;
}

bool Database::del_grade(string id, string class_id){
    vector<Grade>::iterator itr;
    for (itr=gr.begin();itr!=gr.end();itr++){
        if (itr->id == id && itr->class_id == class_id){
            gr.erase(itr);
            return true;
        }
    }
    cout<<"Record Not Exists"<<endl;
    return false;
}

void Database::display_profiles(){
    sort(pr.begin(),pr.end(),compare);
    vector<Profile>::iterator itr;
    for (itr=pr.begin();itr!=pr.end();itr++){
            cout<<itr->name<<" "<<itr->id<<" "<<itr->phone<<endl;
        }
    
}

void Database::display_grades(string class_id){
    bool classexists=false;
    vector<double>m;
    vector<Grade>::iterator itr;
    for (itr=gr.begin();itr!=gr.end();itr++){
        if (itr->class_id == class_id){
            classexists=true;break;
        }
    }
    
    if(classexists){
        sort(gr.begin(),gr.end(),comparemark);
        for (itr=gr.begin();itr!=gr.end();itr++){
            vector<Profile>::iterator itr1;
            if (itr->class_id == class_id){
                for (itr1=pr.begin();itr1!=pr.end();itr1++){
                    if (itr1->id == itr->id){
                        cout<<itr1->name<<" ";break;
                    }
                }
                cout<<itr->id<<" "<<itr->grade<<endl;
                m.push_back(itr->grade);
            }
        }
        double min=*min_element(m.begin(),m.end());
        double max=*max_element(m.begin(),m.end());
        double average = accumulate( m.begin(), m.end(), 0.0)/m.size();
        
        cout<<"Min "<<min<<endl;
        cout<<"Max "<<max<<endl;
        cout<<"Average "<<average<<endl;
    }
    else{cout<<"No Records Found"<<endl;}
}


bool compare(const Profile & a, const Profile & b){
    return a.name<b.name;
}

bool comparemark(const Grade & a, const Grade & b){
    return a.grade<b.grade;
}



    
    
    
    
