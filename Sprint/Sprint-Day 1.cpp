#include <iostream> 
#include <string>
#include<iomanip> 
using namespace std ; 

class Employee
{
    private : string name ; int age ; string address ; string skill_level ; string primary_skill ; string career_stage ; string tag ; string recommendation ; 

    public : 

    void input() ;
    void evaluation () ; 
    void display();
};

void Employee :: input () 
{
    cout << "Enter Your Name : "<<endl ; 
    getline ( cin , name ) ; 
    
    if (name.length() == 0 )
    {
        cout << "CLEAR ERROR MESSAGE "<<endl ; 
        exit(0); 
    }
    
    cout << "Enter Your age : " << endl ; 
    cin>>age ; 

    if (age>60 || age <10)
    {
        cout << "CLEAR ERROR MESSAGE "<<endl ; 
        exit(0); 
    }
    cin.ignore()  ;
    cout << "Enter Your Address : "<<endl ; 
    getline ( cin , address); 

    cout << "Enter Your Primary Skill : "<<endl ; 
    getline (cin , primary_skill ); 

    cout << "Enter your skill level (Beginner , Intermediate , Advanced)" <<endl ; 
    getline(cin , skill_level); 

    if (skill_level != "Beginner" && skill_level != "Intermediate" && skill_level != "Advanced" ) 
    {
        cout<<"CLEAR ERROR MESSAGE "<<endl; 
        exit(0); 
    }
}

void Employee :: evaluation() 
{
    if (age < 18)
    {
        career_stage = "Student"; 
    }
    if (age >= 18 && age <=25)
    {
        career_stage = "Early Professional"; 
    }
    if (age >25 )
    {
        career_stage = "Experienced Professional"; 
    }

    if (skill_level == "Beginner")
    {
        tag = "Foundation Stage" ;
        recommendation = "Focus on core fundamentals and consistency " ;
    }

    if (skill_level == "Intermediate")
    {
        tag = "Intern/Junior Ready" ;
        recommendation = "Start building real-world projects " ;
    }

    if (skill_level == "Advanced")
    {
        tag = "Production Ready" ;
        recommendation = "Contribute to production-grade systems " ;
    }

}
void Employee :: display() 
{
    cout<<endl;
    cout<<endl;
    cout <<"==========================================================================="<<endl ; 
    cout <<"                       CANDIDATE PROFILE CARD                              "<<endl;
    cout <<"==========================================================================="<<endl ; 
    cout <<endl ; 
    cout <<"Name" << setw(22)<<":"<< setw(4)<<""<<name<<endl ; 
    cout <<"Age" << setw(23)<<":"<< setw(4)<<""<<age<<endl ; 
    cout <<"City" << setw(22)<<":"<< setw(4)<<""<<address<<endl ; 
    cout <<"Primary Skill" << setw(13)<<":"<< setw(4)<<""<<primary_skill<<endl ; 
    cout <<"Skill Level" << setw(15)<<":"<< setw(4)<<""<<skill_level<<endl ; 
    cout<<endl;
    cout<<endl;
    cout<<"Career Stage" <<setw(14)<<":"<< setw(4)<<""<<career_stage<<endl ; 
    cout<<"Readiness Tag" <<setw(13)<<":"<< setw(4)<<""<<tag<<endl ; 
    cout<<"Recommendation" <<setw(12)<<":"<< setw(4)<<""<<recommendation<<endl ; 
    cout<<endl; 
    cout <<"==========================================================================="<<endl ; 
}

int main()
{
    Employee employee ;
    employee.input();
    employee.evaluation();
    employee.display();
    return 0 ;
}