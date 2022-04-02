// newClass.h

using namespace std;
// 定义菜式 
#ifndef DISH_H
#define DISH_H
class Dish
{
protected:
	string dishID, dishName;	// 编号、菜名 
	double price;				// 单价 
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

//定义日期类 
#ifndef DATE_H
#define DATE_H
class Date
{
private:
	int year, month, day, hour;				// 年月日时 
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

// 定义订单类
#ifndef ORDER_H
#define ORDER_H
class Order:public Dish
{
private:
	string customerName, address, phone;	// 用户名，地址，电话
	int num;								// 数量
	Date bookDate;							// 日期 
	bool modify;							// 修改权限 
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
