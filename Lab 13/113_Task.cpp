#include<bits/stdc++.h>
using namespace std;

class Person{
protected:
    string name;
    int id;
public:
    Person() : name(""), id(0) {}
    Person(string name, int id) : name(name), id(id){}

    string getName() const { return name; }
    int getId() const { return id; }

    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual ~Person() {}
};

class Student : public Person{
private:
    set<string> coursesEnrolled;

public:
    Student() : Person() {}
    Student(string name, int id) : Person(name, id){}

    void enrollCourse(const string &course){
        coursesEnrolled.insert(course);
    }

    set<string> getCoursesEnrolled() const{
        return coursesEnrolled;
    }

    void display() const override {
        Person::display();
        cout << "Courses Enrolled: ";
        for (const string &course : coursesEnrolled)
            cout << course << " ";
        cout << endl;
    }
};

class Instructor : public Person{
private:
    set<string> coursesTeaching;

public:
    Instructor() : Person() {}
    Instructor(string name, int id) : Person(name, id){}

    void assignCourse(const string &course){
        coursesTeaching.insert(course);
    }

    set<string> getCoursesTeaching() const{
        return coursesTeaching;
    }

    void display() const override{
        Person::display();
        cout << "Courses Teaching: ";
        for (const string &course : coursesTeaching)
            cout << course << " ";
        cout << endl;
    }
};

map<string, string> courses;
map<int, Student> students;
map<int, Instructor> instructors;

void addCourse(const string &code, const string &name) {
    courses[code] = name;
}

void enrollStudent(int studentId, const string &course) {
    if (students.find(studentId) != students.end() && courses.find(course) != courses.end()) {
        students[studentId].enrollCourse(course);
    } else {
        cout << "Invalid student ID or course code!" << endl;
    }
}

void assignInstructor(int instructorId, const string &course) {
    if (instructors.find(instructorId) != instructors.end() && courses.find(course) != courses.end()) {
        instructors[instructorId].assignCourse(course);
    } else {
        cout << "Invalid instructor ID or course code!" << endl;
    }
}

void displayData() {
    cout << "\nCourses:\n";
    for (const auto &pair : courses) {
        cout << "Code: " << pair.first << ", Name: " << pair.second << endl;
    }
    cout << "\nStudents:\n";
    for (const auto &pair : students) {
        cout << "ID: " << pair.first << ", Name: " << pair.second.getName() << "\nEnrolled Courses: ";
        for (const string &course : pair.second.getCoursesEnrolled())
            cout << course << " ";
        cout << endl;
    }
    cout << "\nInstructors:\n";
    for (const auto &pair : instructors) {
        cout << "ID: " << pair.first << ", Name: " << pair.second.getName() << "\nTeaching Courses: ";
        for (const string &course : pair.second.getCoursesTeaching())
            cout << course << " ";
        cout << endl;
    }
    cout<<endl;
}
void saveData() {
    ofstream f1("courses.txt");
    ofstream f2("students.txt");
    ofstream f3("instructors.txt");

    if (!f1 || !f2 || !f3) {
        cout << "Error opening files for saving!" << endl;
        return;
    }

    for (auto& course : courses) {
        f1 << course.first << "," << course.second << endl;
    }

    for (auto& student : students) {
        f2 << student.second.getName() << "," << student.second.getId() << ",";
        for (auto& course : student.second.getCoursesEnrolled()) {
            f2 << course << " ";
        }
        f2 << endl;
    }

    for (auto& instructor : instructors) {
        f3 << instructor.second.getName() << "," << instructor.second.getId() << ",";
        for (auto& course : instructor.second.getCoursesTeaching()) {
            f3 << course << " ";
        }
        f3 << endl;
    }
}


void loadData() {
    string name, course;
    int id;
    ifstream f1("courses.txt");
    ifstream f2("students.txt");
    ifstream f3("instructors.txt");

    if (!f1 || !f2 || !f3) {
        cout << "Error opening files for loading!" << endl;
        return;
    }

    while (getline(f1, name, ',') && getline(f1, course)) {
        courses[name] = course;
    }

    while (getline(f2, name, ',') && f2 >> id) {
        students[id] = Student(name, id);
        f2.ignore();
        while (getline(f2, course, ' ')) {
            students[id].enrollCourse(course);
        }
    }
    while (getline(f3, name, ',') && f3 >> id) {
        instructors[id] = Instructor(name, id);
        f3.ignore();
        while (getline(f3, course, ' ')) {
            instructors[id].assignCourse(course);
        }
    }
}



int main() {
    int choice;
    do {
        cout << "1. Add Course\n2. Enroll Student\n3. Assign Instructor\n4. Display Data\n5. Save Data\n6. Load Data\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string code, name;
            cout << "Enter course code: ";
            cin >> code;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, name);
            addCourse(code, name);
            cout<<"Course added successfully!"<<endl;
        } 
        else if (choice == 2){
            int id;
            string name, course;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            students[id] = Student(name, id);
            cout << "Enter course code: ";
            cin >> course;
            enrollStudent(id, course);
            cout<<"Student enrolled successfully!"<<endl;
        } 
        else if (choice == 3) {
            int id;
            string name, course;
            cout << "Enter instructor ID: ";
            cin >> id;
            cout << "Enter instructor name: ";
            cin.ignore();
            getline(cin, name);
            instructors[id] = Instructor(name, id);
            cout << "Enter course code: ";
            cin >> course;
            assignInstructor(id, course);
            cout<<"Instructor assigned successfully!"<<endl;
        } 
        else if (choice == 4) {
            displayData();
        } 
        else if (choice == 5) {
            saveData();
            cout<<"Data saved to files!"<<endl;
        } 
        else if (choice == 6) {
            loadData();
        }
    } while (choice != 7);

    return 0;
}
