// newClass.cpp
#include<iostream>
#include<string>
#include"newClass.h"
using namespace std;

// 菜式类成员函数

Dish::Dish() {} 

Dish::Dish( string dishIDc, string dishNamec, double pricec ) : dishID(dishIDc), dishName(dishNamec), price(pricec) {} 

Dish::Dish( const Dish & Dish2 ) {
	this->dishID = Dish2.getDishID();
	this->dishName = Dish2.getDishName();
	this->price = Dish2.getPrice();
}

void Dish::setDishName( string s ) {
	this->dishName = s;
}
void Dish::setDishID( string s ) {
	this->dishID = s;
}
void Dish::setPrice( double c ) {
	this->price = c;
}
string Dish::getDishName() {
	return dishName; 
}
string Dish::getDishID() {
	return dishID;
}
double Dish::getPrice() {
	return price;
}
const string & Dish::getDishName() const {
	return dishName; 
}
const string & Dish::getDishID() const {
	return dishID;
}
const double & Dish::getPrice() const {
	return price;
}

// 日期类成员函数

Date::Date() : year(0), month(0), day(0), hour(0) {}

Date::Date( int y, int m, int d, int h ) : year(y), month(m), day(d), hour(h) {}

bool Date::operator==( const Date & D2 ) {
	if ( D2.getYear() == year && D2.getMonth() == month && D2.getDay() == day && D2.getHour() == hour )	return true;
	return false;
}

int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
int Date::getHour() {
	return hour;
}
const int & Date::getYear() const {
	return year;
}
const int & Date::getMonth() const {
	return month;
}
const int & Date::getDay() const {
	return day;
}
const int & Date::getHour() const {
	return hour;
}
void Date::setYear(int y) {
	year = y;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setDay(int d) {
	day = d;
}
void Date::setHour(int h) {
	hour = h;
}

// 订单类成员函数

Order::Order() : modify(1) {}

Order::Order(string dishIDc,string dishNamec,double pricec,string customerName,string address,string phone) : Dish(dishIDc,dishNamec,pricec)
{
	this->customerName = customerName;
	this->address = address;
	this->phone = phone;
	modify = 1;
}

Order::Order(const Dish & di,int nn) : Dish(di), num(nn), modify(1) {} 

bool Order::operator==(const Order & order2) {
	if ( this->customerName == order2.getCustomerName() && this->address == order2.getAddress() && this->phone == order2.getPhone()
	&& this->dishID == order2.getDishID() && this->dishName == order2.getDishName() && this->price == order2.getPrice() 
	 	)	return true;
	return false;
}

string Order::getCustomerName() {
	return customerName;
}

string Order::getAddress() {
	return address;
}

string Order::getPhone(){
	return phone;
}

Date Order::getBookDate() {
	return bookDate;
}

bool Order::getModify() {
	return modify;
}

int Order::getNum() {
	return num;
}

const string & Order::getCustomerName() const {
	return customerName;
}

const string & Order::getAddress() const {
	return address;
}
const string & Order::getPhone() const {
	return phone;
}

const Date & Order::getBookDate() const {
	return bookDate;
}

const bool & Order::getModify() const {
	return modify;
}

const int & Order::getNum() const {
	return num;
}

bool Order::setCustomerName(string customerName) {
	if(!modify) return false;
	this->customerName = customerName;
	return true;
}

bool Order::setAddress(string address) {
	if(!modify) return false;
	this->address = address;
	return true;
}

bool Order::setPhone(string phone) {
	if(!modify) return false;
	this->phone = phone;
	return true;
}

void Order::setModify() {
	modify = 0;
}

bool Order::setBookDate(Date bookDate) {
	if(!modify) return false;
	this->bookDate = bookDate;
	return true;
}

bool Order::setNum(int num) {
	if( !modify || num <= 0 ) return false;
	this->num = num;
	return true;
}
