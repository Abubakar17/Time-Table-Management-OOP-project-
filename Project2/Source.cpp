#include <iostream>
#include<fstream>
#include <string>
using namespace std;
class teacher;
class Class;

class Class  {
    friend class teacher;
    string class_name;
    string teachass[8];
    bool subs[7]; //array for subjects 
    //index 0=maths, 1=english, 2=urdu, 3=islamiat, 4=pak-stds, 5=science, 6=bio/comp
public:
    bool slotfilled(int a) {
        if (teachass[a] == "N/A") {
            return false;
        }
        else return true;

    }
    void setteachasstonull() {
        for (int i = 0; i < 8; i++) {
            teachass[i] = "N/A";
        }
    }
    void setteach(int slot, string name) {
        teachass[slot] = name;
    }
    string getclassname() {
        return class_name;
    }
    void setclassname(string a) {
        class_name = a;
    }
    void setsubs(int a) {
        switch (a)
        {
        case 0: {subs[0] = true;
            break; }
        case 1: {subs[1] = true;
            break; }
        case 2: {subs[2] = true;
            break; }
        case 3: {subs[3] = true;
            break; }
        case 4: {subs[4] = true;
            break; }
        case 5: {subs[5] = true;
            break; }
        case 6: {subs[6] = true;
            break; }
        default:
            break;
        }

    }

};


class teacher  {

    string busy[8];
     string teachsub1,teachsub2;
    string teach_name, teach_class;
    //index 0=maths, 1=english, 2=urdu, 3=islamiat, 4=pak-stds, 5=science, 6=comp, 7=bio
public:

    void setallfree() {
            for (int j = 0; j < 8; j++) {
                busy[j] = "Null";
            }
        
    }
    bool isfree( int j) {
        if (busy[j] == "Null") {  return true; }
        else {  return false; }
    }
    void setbusy(int j,string a) {
        busy[j] = a;
    }
    string getbusy(int i) {
        return busy[i];
    }
    void setteachclass(string a) {
        teach_class = a;
    }
   
    void setteachname(string a) {
        teach_name = a;
    }
    string getteachclass() {
        return teach_class;
    }
    string getteachname() {
        return teach_name;
    }
    
    void setsub1(string a) {
        teachsub1 = a;
    }
    void setsub2(string a) {
        teachsub2 = a;
    }
    string getsub1() {
       return teachsub1 ;
    }

    string getsub2() {
        return teachsub2;
    }
    void printtt() {
        fstream myfile;
        myfile.open("teacher_timetable.csv", ios::app);
        if (teach_class[0]!='9') {

            myfile << "\r" << teach_name << "\r";
            myfile << ",Duration\rDay,0800-0900,0900-1000,1000-1100,1100-1130,1130-1230,1230-0130,0130-0230\r";
            myfile << "class:" << "," << busy[0] << "," << busy[1] << "," << busy[2] <<",break,"<<  busy[3] << "," << busy[4] << "," << busy[5];
        }
        else {

            myfile << "\r" << teach_name << "\r";
            myfile << ",Duration\rDay,0800-0845,0845-0930,0930-1015,1015-1100,1100-1130,1130-1215,1215-0100,0100-0145,0145-0230\r";
            myfile << "class:" << "," << busy[0] << "," << busy[1] << "," << busy[2] << "," << busy[3] << ",break," << busy[4] << "," << busy[5] << "," << busy[6] << "," << busy[7];
        }
    }
};
//all functions used for printing classes ka data
void preset(string clas) {
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    myfile << "\r\r" << clas << "\r";
    myfile << ",Duration\rDay,0800-0900,0900-1000,1000-1100,1100-1130,1130-1230,1230-0130,0130-0230\r";

}
//overloaded functions
void row(int day, string a, string b, string c, string d, string e, string f) {
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    switch (day) {
    case 0: {myfile << "mon," << a << "," << b << "," << c << ",B," << d << "," << e << "," << f << "\n"; break; }
    case 1: {myfile << "tue," << a << "," << b << "," << c << ",R," << d << "," << e << "," << f << "\n"; break; }
    case 2: {myfile << "wed," << a << "," << b << "," << c << ",E," << d << "," << e << "," << f << "\n"; break; }
    case 3: {myfile << "thurs," << a << "," << b << "," << c << ",A," << d << "," << e << "," << f << "\n"; break; }
    case 4: {
        //friday is shorter day
        myfile << ",Duration\rDay,0800-0830,0830-0900,0900-0930,0930-1000,1000-1030,1030-1100,1100-1130\r";
        myfile << "FRIDAY," << a << "," << b << "," << c << ",K," << d << "," << e << "," << f << "\n";
        break;
    }
    }
}
void row(int day, string subjects[6]) {
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    switch (day) {
    case 0: {myfile << "mon," << subjects[0] << "," << subjects[1] << "," << subjects[2] << ",B," << subjects[3] << "," << subjects[4] << "," << subjects[5] << "\n"; break; }
    case 1: {myfile << "tues," << subjects[0] << "," << subjects[1] << "," << subjects[2] << ",R," << subjects[3] << "," << subjects[4] << "," << subjects[5] << "\n"; break; }
    case 2: {myfile << "wed," << subjects[0] << "," << subjects[1] << "," << subjects[2] << ",E," << subjects[3] << "," << subjects[4] << "," << subjects[5] << "\n"; break; }
    case 3: {myfile << "thurs," << subjects[0] << "," << subjects[1] << "," << subjects[2] << ",A," << subjects[3] << "," << subjects[4] << "," << subjects[5] << "\n"; break; }
    case 4: {
        //friday is shorter day
        myfile << ",Duration\rDay,0800-0830,0830-0900,0900-0930,0930-1000,1000-1030,1030-1100,1100-1130\r";
        myfile << "fri," << subjects[0] << "," << subjects[1] << "," << subjects[2] << ",K," << subjects[3] << "," << subjects[4] << "," << subjects[5] << "\n";
        break;
    }
    }
}

void row2(int day, string subjects[8]) {	//FOR CLASS 9 AND 10
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    switch (day) {
    case 0: {myfile << "mon," << subjects[0] << "," << subjects[1] << "," << subjects[2] <<","<< subjects[3] << ",B," << subjects[4] << "," << subjects[5] << "," << subjects[6] << "," << subjects[7] << "\n"; break; }
    case 1: {myfile << "tue," << subjects[0] << "," << subjects[1] << "," << subjects[2] << "," << subjects[3] << ",R," << subjects[4] << "," << subjects[5] << "," << subjects[6] << "," << subjects[7] << "\n"; break; }
    case 2: {myfile << "wed," << subjects[0] << "," << subjects[1] << "," << subjects[2] << "," << subjects[3] <<  ",E," << subjects[4]<< "," << subjects[5] << "," << subjects[6] << "," << subjects[7] << "\n"; break; }
    case 3: {myfile << "thurs," << subjects[0] << "," << subjects[1] << "," << subjects[2] << "," << subjects[3] <<  ",A," << subjects[4] << "," << subjects[5] << "," << subjects[6] << "," << subjects[7] << "\n"; break; }
    case 4: {
        //friday is shorter day
        myfile << ",Duration\rDay,0800-0830,0830-0900,0900-0930,0930-1000,1000-1015,1015-1045,1045-1115,1115-1145,1145-1215\r";
        myfile << "fri," << subjects[0] << "," << subjects[1] << "," << subjects[2] << "," << subjects[3] <<  ",K," << subjects[4] << "," << subjects[5] << "," << subjects[6] << "," << subjects[7] << "\n"; break; }
    }
}
void preset2(string clas) {	//FOR CLASS 9 AND 10
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    myfile << "\r\r" << clas << "\r";
    myfile << ",Duration\rDay,0800-0845,0845-0930,0930-1015,1015-1100,1100-1130,1130-1215,1215-0100,0100-0145,0145-0230\r";
}
void teach(int day, string tc[6]) {
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    switch (day) {
    case 0: { myfile <<"teacher:,"<<tc[0]<< "," << tc[1] << "," << tc[2] << ",," << tc[3] << "," << tc[4] <<"," << tc[5]<<"\r"; break; }
    }
}
void teach2(int day, string tc[8]) {
    fstream myfile;
    myfile.open("timetable.csv", ios::app);
    switch (day) {
    case 0: { myfile << "teacher:," << tc[0] << "," << tc[1] << "," << tc[2] <<","<< tc[3] << ",," << tc[4] << "," << tc[5] << "," << tc[6] << "," << tc[7] << "\r"; break; }
    }
}

int main()
{
    teacher t1, t3, t4;
    Class c;    //object
    teacher* T[22];

    //extracting data from teachers file
    ifstream fin;
    string line;
    fin.open("teachers.csv");
    string temp = "";
    int l; int co = 0;
    fin >> line; fin >> line;    //to skip 1st line
    for (int i = 0; i < 22; i++) {
        T[i] = new teacher;
        T[i]->setallfree();
        T[i]->setsub1("");
        T[i]->setsub2("");


        l = 0; co = 0;
        fin >> line;
        temp = "";
        while (line.at(l) != ',') {
            l++;
        }
        l++;
        while (line.at(l) != ',') {
            temp = temp + line[l];
            l++;
        }
        T[i]->setteachclass(temp);
        temp = "";
        l++;
        while (line.at(l) != ',') {
            temp = temp + line[l];
            l++;
        }
        T[i]->setteachname(temp);
        temp = "";
        //this code is perfect for finding the next letter to ,
        while (line.at(l) != '|') {
            if (line.at(l - 1) == ',') {
                while (line.at(l) != ',') {
                    temp = temp + line[l];
                    l++;
                }
                if (co == 0) {
                    T[i]->setsub1(temp); co++;
                    temp = "";
                }
                else
                    T[i]->setsub2(temp);
            }
            l++;
        }
    }
    // we got the teacher's name, which class and subject he teaches here

    //extracting data from classes file
    Class* C[15];
    ifstream fin2;
    fin2.open("classes.csv");
    temp = ""; string line2 = "";
    fin2 >> line2; fin2 >> line2; fin2 >> line2; //skiping first 3 lines
    fin2 >> line2;    //required
    for (int i = 0; i < 15; i++) {
        C[i] = new Class;
        C[i]->setteachasstonull();
        l = 0;
        fin2 >> line2;
        temp = "";
        //skipping |
        while (line2.at(l) != ',') {
            l++;
        }
        l++;
        while (line2.at(l) != ',') {
            temp = temp + line2[l];
            l++;
        }
        C[i]->setclassname(temp);
        //this code is perfect for finding the next letter to ,
        while (line2.at(l) != '|') {
            if (line2.at(l - 1) == ',') {
                switch (line2.at(l)) { //send an integer from here to set data
                case 'a': {C[i]->setsubs(8);  break; }
                case 'm': {C[i]->setsubs(0);  break; }
                case 'e': {C[i]->setsubs(1);  break; }
                case 'u': {C[i]->setsubs(2);  break; }
                case 'i': {C[i]->setsubs(3);  break; }
                case 'p': {C[i]->setsubs(4);  break; }
                case 's': {C[i]->setsubs(5);  break; }
                case 'b': {C[i]->setsubs(6);  break; }
                default:break;
                }
            }
            l++;
        }
    }
    //we got the class data and what subjects they require to study now


    fstream myfile;
    myfile.open("timetable.csv", ios::out);
    //these here are the main prinitng functions


    teacher tea;
    Class b;
    string teachname[7];
    string subjects[6] = { "","","","","","" };
    string subject2[6] = { "","","","","","" };
    string sub; int ty;
    string temp2;
    for (int c = 0; c < 10; c++) {
        b = *C[c];
        temp2 = b.getclassname(); //each class name

        preset(b.getclassname());
        ty = c;
        for (int slot = 0; slot < 6; slot++) {

            tea = *T[ty];
            T[ty]->setbusy(slot, b.getclassname());
            teachname[slot] = tea.getteachname();
            b.setteach(slot, tea.getteachname());
            ty++;
            ty = ty % 10;
        }
        for (int d = 0; d < 5; d++) {
            if (d == 2) { sub = "isl"; }// take care of the games wala clash
            else if (d == 3 || d == 4) { sub = "isl"; }
            else { sub = "pakstds"; }
            teach(d, teachname);
            row(d, "maths", "english", "urdu", sub, "science", "comp");
        }

    }


    for (int i=0;i<6;i++)subjects[i] ="";
    ty = 10;
    for (int c = 10; c < 13; c++) {
        b = *C[c];
        temp2 = b.getclassname(); //each class name

        preset(b.getclassname());
        for (int slot = 0; slot < 6; slot++) {
            if (b.slotfilled(slot)) {
                continue;
            }else{
                tea = *T[ty];
                if (tea.getsub2() != "") { //sub 2 exists

                    T[ty]->setbusy(slot, b.getclassname());
                    teachname[(slot)] = tea.getteachname();
                    b.setteach(slot, tea.getteachname());
                    subjects[slot] = tea.getsub1();
                    T[ty]->setbusy((slot + 3) % 6, b.getclassname());
                    teachname[(slot + 3) % 6] = tea.getteachname();
                    b.setteach((slot + 3) % 6, tea.getteachname());
                    subjects[(slot + 3) % 6] = tea.getsub2();
                }
                else {
                    T[ty]->setbusy((slot), b.getclassname());
                    teachname[(slot)] = tea.getteachname();
                    b.setteach(slot, tea.getteachname());
                    subjects[slot] = tea.getsub1();
                }
            } 

            
            ty++;
            if (ty == 14)ty = 10;
        }
        ty = c - 1;
        if (ty < 10)ty = 13;
        if (c == 11) {
            ty = ty - 2;
            if (ty < 10)ty = 12;
        }


        for (int d = 0; d < 5; d++) {
            teach(d, teachname);
            row(d, subjects);
        }
    }

    T[12]->setbusy(0, "Null");
    string teachname2[8];

    string subjects2[8] = { "" };
    for (int c = 13; c < 15; c++) {
        b = *C[c];
        temp2 = b.getclassname(); //each class name

        preset2(b.getclassname());
        ty = c+1;
        for (int slot = 0; slot < 8; slot++) {

            tea = *T[ty];
            T[ty]->setbusy((slot) , b.getclassname());
            teachname2[(slot )] = tea.getteachname();
            b.setteach(slot , tea.getteachname());
            subjects2[slot] = tea.getsub1();
            ty++;
            if (ty == 22)ty = 14;
        }
        for (int d = 0; d < 5; d++) {
            teach2(d, teachname2);
            row2(d, subjects2);
        }

    }

    fstream file;
    file.open("teacher_timetable.csv", ios::out);
    //these here are the main prinitng functions
    teacher tea2;
    for (int t = 0; t < 22; t++) {
        tea2 = *T[t];
        T[t]->printtt();
    }
    cout << "making time table\n";
    cout << "time table compelted and tables are in 2 files timetable.csv and teacher_timetable.csv...";

    getchar();
    getchar();
    return 0;
}