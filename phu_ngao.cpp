/*
system design
sinhvien class
knows                   |   does
int mssv                | constructor
string name             | access functions
string course           | printsinhvien
double mark             |

store records in a vector<SinhVien>

features:
add records (store in vector)

display all records

search by mssv

search by name

sort records by mark

sort records by name

show topper

show average marks



*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SinhVien {
private:
  long long mssv;
  string name;
  string course;
  double mark;

public:
  // constructor
  SinhVien(long long, string, string, double);
  SinhVien();

  // access functions
  void setMssv(long long);
  int getMssv();

  void setName(string);
  string getName();

  void setCourse(string);
  string getCourse();

  void setMark(double);
  double getMark();

  // print
  void printSV();
};

// void topRow();

void addSV(vector<SinhVien> &);

void displaySV(vector<SinhVien> &);

void searchByMSSV(vector<SinhVien> &);

void searchByName(vector<SinhVien> &);

void sortByMark(vector<SinhVien> &);

void sortByName(vector<SinhVien> &);

void averageMark(vector<SinhVien> &);

int main() {
  // open file by using inFile
  ifstream inFile;
  char fileName[30] = "sv.txt";
  inFile.open(fileName);
  if (!inFile.is_open()) {
    cout << "Cannot open file" << endl;
  }

  // declare variables to get
  long long m;
  string n;
  string c;
  double ma;

  // create a vector SV to store values;
  vector<SinhVien> svVEC;

  while (inFile >> m) {
    inFile.ignore();
    getline(inFile, n);
    getline(inFile, c);
    inFile >> ma;
    inFile.ignore();

    svVEC.push_back(SinhVien(m, n, c, ma));
  }

  // cout << "Size: " << svVEC.size() << endl;

  //   for (int i = 0; i < svVEC.size(); ++i) {
  //     svVEC[i].printSV();
  //   }

  // menu options
  bool done = false;
  int choice;

  while (!done) {
    cout << "1. Them SV\n";
    cout << "2. Hien thi danh sach SV\n";
    cout << "3. Luu file\n";
    cout << "4. Tim kiem SV\n";
    cout << "5. Sap xep ho so\n";
    cout << "6. Diem trung binh mon\n";
    cout << "7. Xet dieu kien hoc bong\n";
    cout << "99. Thoat\n";
    cout << "Lua chon chuc nang: ";

    cin >> choice;

    switch (choice) {
    case 1:
      addSV(svVEC);
      break;

    case 2:
      displaySV(svVEC);
      break;

    case 3: {
      ofstream f("sv.txt", ios::app);
      if (!f.is_open()) {
        cout << "Khong the mo file!\n";
        break;
      }

      f << svVEC.size() << "\n";

      for (int i = 0; i < svVEC.size(); ++i) {
        f << svVEC[i].getMssv() << "\n";
        f << svVEC[i].getName() << "\n";
        f << svVEC[i].getCourse() << "\n";
        f << svVEC[i].getMark() << "\n";
      }
      f.close();
      cout << "Da luu " << svVEC.size() << "Data written to sv.txt\n";
      break;
    }

    case 4:
      cout << "1. Tim kiem theo MSSV" << endl;
      cout << "2. Tim kiem theo ten" << endl;
      int timKiem;
      cout << "Lua chon: ";
      cin >> timKiem;

      switch (timKiem) {
      case 1:
        searchByMSSV(svVEC);
        break;

      case 2:
        searchByName(svVEC);
        break;

      default:
        cout << "Vui long nhap lua chon valid" << endl;
        break;
      }
      break;

    case 5:
      cout << "1. Sap xep theo diem" << endl;
      cout << "2. Sap xep theo ten" << endl;
      int luaChon;
      cin >> luaChon;

      switch (luaChon) {
      case 1:
        sortByMark(svVEC);
        break;

      case 2:
        sortByName(svVEC);
        break;

      default:
        cout << "Vui long nhap lua chon valid" << endl;
        break;
      }
      break;

    case 6:
      averageMark(svVEC);
      break;
    case 7:

      break;

    case 99:
      cout << "Cam on vi da dung!";
      done = true;
      break;
    }
  }

  inFile.close();
  // after using the txt file
  return 0;
}

SinhVien::SinhVien() {
  mssv = 0;
  name = "";
  course = "";
  mark = 0.0;
}

SinhVien::SinhVien(long long m, string n, string c, double ma) {
  mssv = m;
  name = n;
  course = c;
  mark = ma;
}

void SinhVien::setMssv(long long m) { mssv = m; }

int SinhVien::getMssv() { return mssv; }

void SinhVien::setName(string n) { name = n; }

string SinhVien::getName() { return name; }

void SinhVien::setCourse(string c) { course = c; }

string SinhVien::getCourse() { return course; }

void SinhVien::setMark(double ma) { mark = ma; }

double SinhVien::getMark() { return mark; }

void SinhVien::printSV() {
  // cout << left << setw(20) << mssv
  //      << left << setw(20) << name
  //      << setw(20) << course
  //      << setw(20) << fixed << setprecision(2) << mark << endl;
  cout << mssv << "\t" << name << "\t" << course << "\t" << fixed
       << setprecision(2) << mark << endl;
}

// void topRow()
// {
//     cout <<
//     "============================================================================"
//     << endl; cout << "MSSV                      Name                 Course
//     Mark" << endl; cout <<
//     "============================================================================"
//     << endl;
// }

void addSV(vector<SinhVien> &list) {
  long long m;
  cout << "Nhap MSSV: ";
  cin >> m;

  string na;
  cout << "Nhap ten SV: ";
  cin.ignore();
  getline(cin, na);

  string c;
  cout << "Nhap mon: ";
  getline(cin, c);

  double ma;
  cout << "Nhap diem: ";
  cin >> ma;

  // add to the vector
  list.push_back(SinhVien(m, na, c, ma));

  // print out
  list.back().printSV();
}

void displaySV(vector<SinhVien> &list) {
  for (int i = 0; i < list.size(); ++i) {
    list[i].printSV();
  }
}

void searchByMSSV(vector<SinhVien> &list) {
  cout << "Nhap MSSV: ";
  long long m;
  cin >> m;
  bool found = false;

  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMssv() == m) {
      list[i].printSV();
    }
  }

  if (!found) {
    cout << "Unavailable" << endl;
  }
}

void searchByName(vector<SinhVien> &list) {
  cout << "Nhap ten: ";
  string n;
  cin >> n;

  bool found = false;

  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getName() == n) {
      list[i].printSV();
    }
  }

  if (!found) {
    cout << "Unavailable" << endl;
  }
}

void sortByMark(vector<SinhVien> &list) {
  // luu y day la sort tang dan
  SinhVien temp;

  // bubble sort
  for (int i = 0; i < list.size(); ++i) {
    for (int j = i + 1; j < list.size(); ++j) {
      if (list[i].getMark() > list[j].getMark()) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

  // print sorted
  displaySV(list);
}

void sortByName(vector<SinhVien> &list) {
  SinhVien temp;
  for (int i = 0; i < list.size(); ++i) {
    for (int j = i + 1; j < list.size(); ++j) {
      if (list[i].getName() > list[j].getName()) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
  displaySV(list);
}

void averageMark(vector<SinhVien> &list) {
  double totalMark = 0;

  for (int i = 0; i < list.size(); ++i) {
    totalMark += list[i].getMark();
  }

  double avgMark = totalMark / list.size();

  // tim diem cao nhat
  double highestMark = list[0].getMark();
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMark() > highestMark) {
      highestMark = list[i].getMark();
    }
  }

  // tim diem thap nhat
  double lowestMark = list[0].getMark();
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMark() < lowestMark) {
      lowestMark = list[i].getMark();
    }
  }

  cout << "Diem trung binh: " << avgMark << endl;
  cout << "Diem cao nhat: " << highestMark << endl;
  cout << "Diem thap nhat: " << lowestMark << endl;
}
