// Student class is implemented based on string and do not need any change
//Liam Turcotte 
#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(string n);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(string n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  
    string currentName = ""; 
    double currentGrade; 

    list<Student> c; 

    cout << "Please enter student name and grade. Example format: Liam 90. "
         << "Enter q to stop inputting names." << endl; 

    list<Student>::iterator a; 

    bool insertElement = false; 

    while (cin >> currentName) {
        if (currentName == "q") {
            break; 
        }
        cin >> currentGrade; 

        Student s; 
        s.setname(currentName); 
        s.setgrade(currentGrade); 

        for (a = c.begin(); a != c.end(); a++) {
            if (s.getgrade() < (*a).getgrade()) {
                c.insert(a, s); 
                insertElement = true; 
                break; 
            }
        }

        if (!insertElement) {
            c.push_back(s); 
        }

        insertElement = false; 

    }

    cout << endl; 
	
    list<Student>::iterator i;

    cout << "Ascending order:" << endl; 
    for (i=c.begin(); i != c.end(); i++) {
        cout << *i << endl; 
    }

    cout << endl << "Descending order:" << endl;; 
    list<Student>::reverse_iterator r; 
    for (r=c.rbegin(); r != c.rend(); r++) {
        cout << *r << endl; 
    }
}
