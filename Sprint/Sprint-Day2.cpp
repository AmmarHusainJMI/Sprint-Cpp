#include<iostream> 
#include<String> 
#include<algorithm>
#include<iomanip>
using namespace std ; 

class Student 
{
    private : string name , roll_no , branch , tech ; 
    
    pair<string , float>subject[3]; float average , total ;
    int maxindex; 

    public : 
    Student ()
    {
        cout<<"Enter your full name               :   " ;
        getline(cin , name) ;
        cout<<"Enter your roll number             :   " ;
        getline(cin , roll_no) ;
        cout<<"Enter your branch                  :   " ;
        getline(cin , branch) ;
        cout<<"Enter your fav subjects one by one :   " ;
        for (int i = 0 ; i<3 ; i++)
        {
            getline(cin , subject[i].first) ;
        }
        for (int i = 0 ; i<3 ; i++)
        {
        cout<<"Enter your " <<subject[i].first<<" marks  :   "; 
        cin>>subject[i].second ; 
        }
        cin.ignore();
        cout<<"Enter your all technical skills    :   " ;
        getline(cin , tech) ;
    }

    void processing () 
    {
        // Text Formatting 
        bool new_word = true ; 
        for ( int j = 0 ; j< name.length() ; j++ )
        {
            if (isspace(name[j]))
            {    new_word = true ; 
                continue ;
            }

            if (new_word)
            {
                name[j]=toupper(name[j]) ;
                new_word=false;
            }
            else 
            {
                name[j]=tolower(name[j]) ;
            }
        }

        sort(subject , subject+3) ;

        average = (subject[0].second + subject[1].second + subject[2].second)/3 ;
        total = subject[0].second + subject[1].second + subject[2].second ;

        maxindex=0 ; 
        for ( int z = 0 ; z < 3 ; z++)
        {
            if (subject[z].second > subject[maxindex].second)
            maxindex = z ; 
        }

    

    }

    void display ()
    {
        cout<<endl ;
        cout <<"==========================================================================="<<endl ; 
        cout <<"                          STUDENT DETAILS                                  "<<endl;
        cout <<"==========================================================================="<<endl ;
        cout<<endl ; 
        cout << "Full Name"<<setw(20) <<":"<<setw(5)<<""<<name <<endl;
        cout<<"Roll Number and Branch"<<setw(7)<<":"<<setw(5)<<""<<roll_no<<setw(1)<<""<<","<<setw(1)<<""<<branch <<endl;
        cout<<"Favourite Subjects (sorted)"<<setw(2)<<":"<<setw(5)<<""<<subject[0].first<<" , "<<subject[1].first<<" , "<<subject[2].first<<endl;
        cout<<"Subject-Wise Marks"<<setw(11)<<":"<<setw(5)<<""<<"[ "<<subject[0].first<<" , "<<subject[0].second<< " ]" << " , " << "[ "<<subject[1].first<<" , "<<subject[1].second<< " ]" << " , " << "[ "<<subject[2].first<<" , "<<subject[2].second<< " ]"<<endl;
        cout<<"Total Marks"<<setw(18)<<":"<<setw(5)<<""<<total<<endl ; 
        cout<<"Average Marks"<<setw(16)<<":"<<setw(5)<<""<<average<<endl; 
        cout<<"Highest Scoring Subject"<<setw(6)<<":"<<setw(5)<<""<<subject[maxindex].first <<endl; 
        cout<<"Technical Skills"<<setw(13)<<":"<<setw(5)<<""<<tech <<endl; 
        cout<<endl;
        cout <<"==========================================================================="<<endl ;
        cout<<endl ; 
    }

}; 

int main()
{
    Student stu ; 
    stu.processing();
    stu.display(); 
    return 0 ; 
}
