#include<iostream>
#include<vector>

using namespace std;

class Item{
	protected: //// de dung duoc o cac class con chau 
		int price;
	public:
	   int id;
	   string name;
	   Item(){
	   }
	   virtual void display(){  //// neu them virtual thi ham nay co the bi thay the boi display o class con neu class con ko co thi moi chay con ko thi uu tien dung cua class con
	   	cout<< id << " "<< name << "\n";
	   }
	   virtual int getPrice(){
	   	return price;
	   }
};

class Book: public Item{
	public:
		string author;
		int year;
		int getPrice(){
			return price;
		}
		void display(){
			cout<< author << " " << year << "\n";
		}
};

class Food: public Item{
	public:
		string expire_date;
		string nsx;
};

class Vegetable: public Food{
	public:
		float weight;
};

int main(){
	Vegetable raumuong;
	raumuong.id = 100;
	raumuong.weight = 0.1;
	Book tieuthuyet;
	tieuthuyet.id = 101;
	tieuthuyet.author = "VuTrongPhung";
	Book b;
	b.id = 102;
	b.name = "Harry Potter";
	b.author = "ABC";
	b.year = 2000;
	b.display();
	
	vector<Item *> khohang;
	khohang.push_back(&raumuong);
	khohang.push_back(&tieuthuyet);
	khohang.push_back(&b);
	khohang[2]->display();
}
