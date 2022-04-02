// newClass.h

using namespace std;
// �����ʽ 
#ifndef DISH_H
#define DISH_H
class Dish
{
protected:
	string dishID, dishName;	// ��š����� 
	double price;				// ���� 
public:
	Dish();
	Dish( const Dish & );
	Dish( string dishID, string dishName, double price = 0 );
	void setDishName( string );
	void setDishID( string );
	void setPrice( double );
	string getDishName();
	string getDishID();
	double getPrice();
	const string & getDishName() const;
	const string & getDishID() const;
	const double & getPrice() const;
};
#endif

//���������� 
#ifndef DATE_H
#define DATE_H
class Date
{
private:
	int year, month, day, hour;				// ������ʱ 
public:
	Date();
	Date( int, int, int, int );
	bool operator==( const Date & );
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	const int & getYear() const;
	const int & getMonth() const;
	const int & getDay() const;
	const int & getHour() const;
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	void setHour(int);
};
#endif

// ���嶩����
#ifndef ORDER_H
#define ORDER_H
class Order:public Dish
{
private:
	string customerName, address, phone;	// �û�������ַ���绰
	int num;								// ����
	Date bookDate;							// ���� 
	bool modify;							// �޸�Ȩ�� 
public:
	Order();
	Order(string dishIDc,string dishNamec,double pricec,string customerName = "no",string address = "no",string phone = "no");
	Order(const Dish &, int);
	bool operator==(const Order & order2);
	string getCustomerName();
	string getAddress();
	string getPhone();
	Date getBookDate();
	bool getModify();
	int getNum();
	const string & getCustomerName() const;
	const string & getAddress() const;
	const string & getPhone() const;
	const Date & getBookDate() const;
	const bool & getModify() const;
	const int & getNum() const;
	bool setCustomerName( string );
	bool setAddress( string );
	bool setPhone( string );
	bool setNum( int );
	bool setBookDate( Date );
	void setModify();
};
#endif
