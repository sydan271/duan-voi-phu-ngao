#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class SinhVien{
	private:
	    int mssv;
	    string name;
		int age;
	public:
	    int getmssv(){
	    	return mssv;
		}	
		SinhVien(int x){ //// ham khoi tao phai o trong public, ten cua ham la ten cua class
			mssv = x;
		}
		SinhVien(int x, string n){
			mssv = x;
			name = n;
		}
		SinhVien(int x, string n, int a){
			mssv = x;
			name = n;
			age = a;
		}
				void display(){
			cout << mssv << " " << name << " " << age;
		}
		
};

int main(){
	vector<SinhVien> dsSV;
	ifstream f("sv.txt");
	string data;
	getline(f, data);
	int n = atoi(data);
	///dsSV= new SinhVien[3];
	for (int i =0; i < n; i++){
		getline(f,data);
		int mssv = atoi(data);
		getline(f, data);
		string name = data;
		getline(f, data);
		int age = atoi(data);
		SinhVien sv(mssv, name, age);
		sv.display();
		dsSV.push_back(sv);
	}
	while (getline(f,data)){
		cout<< data<< "\n";
	}
	f.close();
	
	int choice = 0;
	while (choice != 99){
		cout << "1. Them Sv\n";
	    cout<< "2. Xoa Sv\n";
	    cout<< "3. List tat ca sv\n";
	    cout<< "4. save file\n";
	    cout<< "99. Exit\n";
	    cout<< "Lua chon:";
	
	cin >> choice;
	
	if (choice == 4){
	  ofstream f1("sv1.txt");
	f1 << dsSV.size()<< "\n";
	for (int i = 0; i < n; i++)
		f1 << dsSV[i].output();
	f1.close();
}
    else if (choice == 3){
    	for ( int i = 0; i < dsSV.size(); i++)
    	dsSV[i].display();
	}
}
	}

	
	
	
