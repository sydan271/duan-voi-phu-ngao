#include <iostream>
#include <fstream>
#include <string>
#include<limits>


using namespace std;



struct SinhVien {
    int mssv;
    string hoten;
    string course;
    float marks;
};

int main() {
    SinhVien* dsSV = new SinhVien[100];
    int count = 0;
    int choice = 0;

    while (choice != 99) {
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

        if (choice == 1) {
            SinhVien sv;

            cout << "Nhap MSSV: ";
            cin >> sv.mssv;

            cout << "Nhap ho ten: ";
            cin.ignore();              
            getline(cin, sv.hoten);    

            cout << "Nhap mon: ";
            cin.ignore();              
            getline(cin, sv.course);
            
            cout << "Nhap diem: ";
            cin >> sv.marks;

            cout << sv.mssv << " " << sv.hoten << " "
                 << sv.course << " " << sv.marks << endl;

            dsSV[count] = sv;
            count++;
        }

        else if (choice == 2) {
            ifstream fi("sv.txt");
            if (!fi.is_open()) {
            	cout << "Khong the mo file \n";
			}
			else {
				int n;
				if (!(fi >> n)) {
                    cout << "Loi khi doc so luong sinh vien tu file\n";
                }
                else {
                    fi.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    if (n > 100) n = 100; 
                    count = 0;
                    for (int i = 0; i < n; ++i) {
                        SinhVien tmp;
                        if (!(fi >> tmp.mssv)) break;
                        fi.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(fi, tmp.hoten);
                        getline(fi, tmp.course);
                        if (!(fi >> tmp.marks)) break;
                        fi.ignore(numeric_limits<streamsize>::max(), '\n');

                        dsSV[count] = tmp;
                        ++count;
                    }
                    for (int i = 0; i < count; ++i) {
                        cout << dsSV[i].mssv << " "
                             << dsSV[i].hoten << " "
                             << dsSV[i].course << " "
                             << dsSV[i].marks << "\n";
                    }
                }
                fi.close();
			}
        }

        else if (choice == 3) {
            ofstream f("sv.txt");
            if (!f.is_open()) {
                cout << "Khong the mo file!\n";
                continue;
            }

            f << count << "\n";

            for (int i = 0; i < count; i++) {
                f << dsSV[i].mssv << "\n";
                f << dsSV[i].hoten << "\n";   
                f << dsSV[i].course << "\n";
                f << dsSV[i].marks << "\n";
            }

            f.close();
            cout << "Data written to sv.txt\n";
        }
        
        else if (choice == 4){
        	int searchtype;
        	cout << "Tim kiem theo: \n";
        	cout << "1. MSSV \n";
        	cout << "2. Ho ten \n";
        	cout << "Lua chon: ";
        	cin >> searchtype;
        	
        	if (searchtype == 1){
        		int searchmssv;
        		cout << "Nhap MSSV can tim: ";
        		cin >> searchmssv;
        		
        		bool found = false;
        		for (int i = 0; i < count; i++){
        			if (dsSV[i].mssv == searchmssv){
        				cout << "Tim thay: " << dsSV[i].mssv << " "
        			     << dsSV[i].hoten << " "
        			     << dsSV[i].course << " "
        			     << dsSV[i].marks << endl;
        			found = true;
					break;
					}
				}
				if (!found){
					cout << "Khong tim thay sinh vien\n";
				}
			}
			else if (searchtype == 2){
				string searchname;
				cout << "Nhap ten sinh vien: ";
				cin >> searchname;
				cin.ignore();
				getline(cin, searchname);
				
				bool found = false;
				for (int i = 0; i< count ; i++){
					if (dsSV[i].hoten == searchname){
						cout << "Tim thay: " << dsSV[i].mssv << " "
						     << dsSV[i].hoten << " "
						     << dsSV[i].course << " "
						     << dsSV[i].marks << endl;
						found = true;     
					}
				}
				if (!found){
					cout << "Khong tim thay sinh vien \n";
				}
			}
		}
		
		
		
		
    }

    delete[] dsSV;
    return 0;
}




