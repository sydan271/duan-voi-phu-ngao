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
  long long getMssv();

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

void sortByMark(vector<SinhVien> &, string);

void sortByMSSV(vector<SinhVien> &, string);

void averageMark(vector<SinhVien> &);

double averageMarkBySV(vector<SinhVien> &, long long);

void xetHocBong(vector<SinhVien> &, long long);

void averageMarkByCourse(vector<SinhVien> &, string);

void removeSV(vector<SinhVien> &, long long);

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
  int size_ban_dau = svVEC.size();

  //   for (int i = 0; i < svVEC.size(); ++i) {
  //     svVEC[i].printSV();
  //   }

  // menu options
  bool done = false;
  int choice;

  while (!done) {
    cout << "\n";
    cout << "Quan ly sinh vien\n";
    cout << "----------------\n";
    cout << "1. Them SV\n";
    cout << "2. Hien thi danh sach SV\n";
    cout << "3. Luu file\n";
    cout << "4. Tim kiem SV\n";
    cout << "5. Sap xep ho so\n";
    cout << "6. Diem trung binh mon\n";
    cout << "7. Xet dieu kien hoc bong\n";
    cout << "8. Xoa SV\n";
    cout << "99. Thoat\n";
    cout << "Lua chon chuc nang: ";

    cin >> choice;
    cout << "----------------\n";
    cout << "\n";

    switch (choice) {
    case 1:
      addSV(svVEC);
      cout << "\n";
      break;

    case 2:
      displaySV(svVEC);
      cout << "\n";
      break;

    case 3: {
      ofstream f("sv.txt", ios::app);
      if (!f.is_open()) {
        cout << "Khong the mo file!\n";
        break;
      }
      // f << svVEC.size() << "\n";

      //   for (int i = svVEC.size(); i > size_ban_dau; --i) {
      //     f << svVEC[i].getMssv() << "\n";
      //     f << svVEC[i].getName() << "\n";
      //     f << svVEC[i].getCourse() << "\n";
      //     f << svVEC[i].getMark() << "\n";
      //   }
      for (int i = size_ban_dau; i < svVEC.size(); ++i) {
        f << svVEC[i].getMssv() << "\n";
        f << svVEC[i].getName() << "\n";
        f << svVEC[i].getCourse() << "\n";
        f << svVEC[i].getMark() << "\n";
      }

      size_ban_dau = svVEC.size();
      f.close();
      cout << "Da luu vao file\n";
      cout << "\n";
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
        cout << "\n";
        break;

      case 2:
        searchByName(svVEC);
        cout << "\n";
        break;

      default:
        cout << "Vui long nhap lua chon valid" << endl;
        break;
      }
      break;

    case 5: {
      cout << "1. Sap xep theo diem" << endl;
      cout << "2. Sap xep theo mssv" << endl;
      int luaChon;
      cin >> luaChon;

      switch (luaChon) {
        case 1: {
          cout << "Nhap mon (Vat Ly, Giai Tich, Dai So): ";
          string mon;
          cin.ignore();
          getline(cin, mon);
          sortByMark(svVEC, mon);
          cout << "\n";
          break;
        }

        case 2: {
          cout << "Nhap mon (Vat Ly, Giai Tich, Dai So): ";
          string sbj;
          cin.ignore();
          getline(cin, sbj);
          sortByMSSV(svVEC, sbj);
          break;
        }

        default:
          cout << "Vui long nhap lua chon valid" << endl;
          break;
      }
      break;
    }

    case 6:
      cout << "1. Thong ke chung" << endl;
      cout << "2. Tinh diem trung binh cua mot sinh vien" << endl;
      cout << "3. Thong ke theo tung mon" << endl;
      int subCh;
      cout << "Lua chon: ";
      cin >> subCh;
      if (subCh == 1) {
        averageMark(svVEC);
        cout << "\n";
      } else if (subCh == 2) {
        cout << "Nhap MSSV: ";
        long long maso;
        cin >> maso;
        double trungBinh = averageMarkBySV(svVEC, maso);
        cout << "Diem trung binh cua sinh vien " << maso << " la: " << fixed
             << setprecision(2) << trungBinh << endl;
        cout << "\n";
      } else if (subCh == 3) {
        cout << "Nhap mon (Vat Ly, Giai Tich, Dai So): ";
        string subj;
        cin.ignore();
        getline(cin, subj);
        averageMarkByCourse(svVEC, subj);
      }
      break;

    case 7: {
      cout << "Nhap MSSV: ";
      long long maso;
      cin >> maso;
      xetHocBong(svVEC, maso);
      break;
    }

    case 8: {
      cout << "Nhap MSSV: ";
      long long maso;
      cin >> maso;
      cout << "Ban co chac chan muon xoa sinh vien co MSSV " << maso
           << " khong? (y/n)";
      char conf;
      cin >> conf;
      switch (conf) {
      case 'y':
        removeSV(svVEC, maso);
        break;
      case 'n':
        break;
      default:
        cout << "Vui long nhap y/n";
        break;
      }
      cout << "\n";
      break;
    }

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

// initialization
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

// access functions
void SinhVien::setMssv(long long m) { mssv = m; }

long long SinhVien::getMssv() { return mssv; }

void SinhVien::setName(string n) { name = n; }

string SinhVien::getName() { return name; }

void SinhVien::setCourse(string c) { course = c; }

string SinhVien::getCourse() { return course; }

void SinhVien::setMark(double ma) { mark = ma; }

double SinhVien::getMark() { return mark; }

void SinhVien::printSV() {
  cout << left << setw(30) << mssv << left << setw(30) << name << setw(30)
       << course << setw(30) << fixed << setprecision(2) << mark << endl;
  // cout << mssv << "\t" << name << "\t" << course << "\t" << fixed
  //      << setprecision(2) << mark << endl;
}

void addSV(vector<SinhVien> &list) {
  long long m;
  cout << "Nhap MSSV: ";
  cin >> m;
  //   for (int i = 0; i < list.size(); ++i) {
  //     if (list[i].getMssv() == m) {
  //       cout << "MSSV da ton tai!\n";
  //       return;
  //     }
  //   }

  string na;
  cout << "Nhap ten SV: ";
  cin.ignore();
  getline(cin, na);

  bool daTonTai = false;
  string c;
  while (!daTonTai) {
    cout << "Nhap mon: ";
    getline(cin, c);
    for (int i = 0; i < list.size(); ++i) {
      if (list[i].getCourse() == c && list[i].getMssv() == m) {
        daTonTai = false;
        cout << "Sinh vien da dang ky mon nay!\n";
      }
    }
    daTonTai = true;
  }

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
  string n;
  cin.ignore();
  getline(cin, n);

  bool notfound = true;

  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMssv() == m) {
      list[i].printSV();
      notfound = false;
    }
  }

  if (notfound) {
    cout << "Unavailable" << endl;
  }
}

void searchByName(vector<SinhVien> &list) {
  cout << "Nhap ten: ";
  string n;
  cin >> n;

  bool notfound = true;

  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getName() == n) {
      list[i].printSV();
      notfound = false;
    }
  }

  if (notfound) {
    cout << "Unavailable" << endl;
  }
}

void sortByMark(vector<SinhVien> &list, string mon) {
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
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getCourse() == mon) {
      list[i].printSV();
    }
  }
}

void sortByMSSV(vector<SinhVien> &list, string mon) {
  SinhVien temp;
  for (int i = 0; i < list.size(); ++i) {
    for (int j = i + 1; j < list.size(); ++j) {
      if (list[i].getMssv() > list[j].getMssv()) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
  
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getCourse() == mon){
      list[i].printSV();
    }
  }
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

void xetHocBong(vector<SinhVien> &list, long long m) {
  double avg = averageMarkBySV(list, m);
  if (avg >= 3.5) {
    cout << "Hoc bong: 500000 VND" << endl;
  } else if (avg >= 3) {
    cout << "Hoc bong: 200000 VND" << endl;
  } else {
    cout << "Khong du dieu kien" << endl;
  }
}

double averageMarkBySV(vector<SinhVien> &list, long long m) {
  double total = 0;
  int count = 0;
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMssv() == m) {
      total += list[i].getMark();
      count++;
    }
  }
  if (count == 0)
    return 0.0;
  return total / count;
}

void averageMarkByCourse(vector<SinhVien> &list, string s) {
  double total = 0;
  int count = 0;
  double AvgMark;
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getCourse() == s) {
      total += list[i].getMark();
      count++;
    }
  }
  if (count == 0)
    AvgMark = 0.0;
  else
    AvgMark = total / count;

  cout << "Diem trung binh: " << AvgMark << endl;

  sortByMark(list, s);
  cout << "Diem cao nhat cua mon " << s << " la: " << list.back().getMark()
       << endl;
  cout << "Diem thap nhat cua mon " << s << " la: " << list.front().getMark()
       << endl;
}

void removeSV(vector<SinhVien> &list, long long ms) {
  bool deleted = false;
  for (int i = 0; i < list.size(); ++i) {
    if (list[i].getMssv() == ms) {
      list.erase(list.begin() + i);
      deleted = true;
      --i;
    }
  }

  if (!deleted) {
    cout << "Unavailable" << endl;
  } else {
    cout << "Da xoa sinh vien co MSSV: " << ms << endl;
  }
}
