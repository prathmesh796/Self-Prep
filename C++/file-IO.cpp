#include <iostream>
#include <fstream> // I/O classes
#include <string.h>

using namespace std;

class student
{
    int roll, div;
    char name[10], address[10];

public:
    void getdata()
    {
        cout << "\nEnter Rollno, Name, Div & Address=\n";
        cin >> roll >> name >> div >> address;
    }
    void putdata()
    {
        cout << "\n" << roll << "\t" << name << "\t" << div << "\t" << address;
    }

    int return_Roll() 
    { 
        return roll; 
    }
};

class seq
{
    char fname[15];

public:
    void create();
    void display();
    void Add();
    void Remove(int);
    void search(int);
};

void seq::create()
{
    ofstream fp; // object of class ofstream(write mode)
    student s;   // class object

    char op;

    cout << "\nenter file name :";
    cin >> fname;
    fp.open(fname); //Opeening a file in write mode 

    do
    {
        s.getdata();                     // enter student data
        fp.write((char *)&s, sizeof(s)); // write student data in file

        cout << "\nDo u want to add new record?(y/n) :";
        cin >> op;
    } while (op == 'y');

    fp.close(); // close the file
}
void seq::display()
{
    ifstream fp; // object of class ifstream(read mode)
    student s;   // class object

    fp.open(fname);// Opening a file in read mode

    cout << "\nRoll\tName\tDiv\tAddress";
    fp.read((char *)&s, sizeof(s)); // read from file

    while (!fp.eof()) // till end of file
    {
        s.putdata(); // display
        fp.read((char *)&s, sizeof(s));
    }

    fp.close(); // close file
}

void seq::Add()
{
    ofstream fp; // write mode
    student s;   // class object

    fp.open(fname, ios::app); // open file in append mode
    s.getdata();              // enter student data

    fp.write((char *)&s, sizeof(s)); // write student data in file
    fp.close();
}

void seq::Remove(int key)
{
    ifstream f1; // read mode
    ofstream f2; // write mode
    student s;

    int flag = 0;
    f1.open(fname);
    f2.open("Temp.Txt");
    f1.read((char *)&s, sizeof(s));

    while (!f1.eof())
    {
        if (key == s.return_Roll())
        {
            s.putdata();
            flag = 1;
        }

        else
        {
            f2.write((char *)&s, sizeof(s));
        }

        f1.read((char *)&s, sizeof(s));
    }

    if (flag == 0)
    {
        cout << "\nRecord does not present";
    }

    f1.close();
    f2.close();
    remove(fname);
    rename("Temp.Txt", fname);
}

void seq::search(int key)
{
    ifstream fp;
    student s;

    int flag = 0;
    fp.open(fname);                 // open a file
    fp.read((char *)&s, sizeof(s)); // read

    while (!fp.eof())
    {
        if (key == s.return_Roll()) // compare
        {
            flag = 1; // rollno found
            break;
        }

        fp.read((char *)&s, sizeof(s)); // read from file
    } // end of while

    if (flag == 0)
    {
        cout << "Record does not present \n";
    }

    else
    {
        s.putdata();
    }

    fp.close();
}

int main()
{
    int ch, R;

    seq ob;

    do
    {
        cout << "\n1: create Database\n2: Display \n3: Add a record\n4: Delete a record\n5: Search a record";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ob.create();
            break;

        case 2:
            ob.display();
            break;

        case 3:
            ob.Add();
            ob.display();
            break;

        case 4:
            cout << "\nEnter Roll No to delete";
            cin >> R;
            ob.Remove(R);
            ob.display();
            break;
            
        case 5:
            cout << "\nEnter Roll No to search";
            cin >> R;
            ob.search(R);
            break;
        }
    } while (ch < 6);
}