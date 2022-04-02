// operateMenu.h
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include"newClass.h"
using namespace std;


// 从本地文件载入菜谱中所有菜式 
void inputAllDishes( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	double price;
	string dishID, dishName;	
	ifstream instuf( "menu.txt", ios::in );				// 打开文件 
	instuf.seekg( 0, ios::beg );						// 流指针置在文件头 
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 

	while ( instuf >> dishID >> dishName >> price ) {	// 提取
		Dish d( dishID, dishName, price );
		menu[dishName] = d;
		possessID.insert( dishID );
	}
	instuf.close();										// 关闭文件 
}

// 将所有菜式重新写入本地菜谱文件
void outputAllDishes( unordered_map<string, Dish> & menu ) {
	double price;
	string dishID, dishName;	
	ofstream outstuf( "menu.txt", ios::out );				// 打开文件 
	outstuf.seekp( 0, ios::beg );							// 流指针置在文件头 
	for ( const pair<string, Dish> & p : menu ) {			// 写 
		dishID = p.second.getDishID();
		dishName =  p.second.getDishName();
		price = p.second.getPrice();
		outstuf << dishID << ' ' << dishName << ' ' << price << '\n'; 
	}
	outstuf.close();										// 关闭文件 
}

// 打印菜谱中所有菜式 
void printAllDishes( unordered_map<string, Dish> & menu ) {
	cout << "----------------  菜谱  ----------------" << endl << endl;
	cout << " 编号" << setw(20) << "菜名" << setw(14) << "价格" << endl << endl;
	for ( const pair<string, Dish> & p : menu ) {
		cout << " " << p.second.getDishID();
		cout << setw(20) << p.second.getDishName();
		cout << setw(14) << p.second.getPrice() << endl << endl;
	}
	cout << endl << "----------- 全部菜式显示完毕 -----------" << endl;
}

// 按菜名查询单一菜式
bool inquireOneDish(  unordered_map<string, Dish> & menu ) {
	string dish;
	cout << " 您正在进行查询菜式，请输入您查找的菜名：\n? ";
	cin >> dish;
	if ( !menu.count(dish) ) {
		cout << " 抱歉，您期望的菜式不存在！\n";
		return false;
	}
	
	cout << "查询成功！\n\n";
	cout << " 编号" << setw(9) << "菜名" << setw(14) << "价格" << endl; 
	cout << " " << menu[dish].getDishID() << "    " << dish << "      \t" << menu[dish].getPrice() << endl;
	return true;
} 

// 往菜谱添加新菜式 
void appendOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	string name, id;
	double price;
	char q;
	
	cout << "您正在进行添加菜式操作，请输入编号：\n? ";
	cin >> id;
	if ( possessID.find(id) != possessID.end() ) {
		cout << " 该编号已经存在！请按任意键退出。\n";
		cin >> q;
		return;
	}
	
	cout << " 请输入菜名：\n? ";
	cin >> name;
	if ( menu.count(name) ) {
		cout << " 该菜名已经存在！请按任意键退出。\n";
		cin >> q;
		return;
	}
	
	cout << " 请输入单价：\n? ";
	cin >> price;
	
	Dish d(id, name, price);
	menu[name] = d;
	possessID.insert(id);
	
	cout << " 已添加新菜式如下：\n\n";
	cout << " 编号" << setw(9) << "菜名" << setw(14) << "价格" << endl; 
	cout << " " << menu[name].getDishID() << "    " << name << "      \t" << menu[name].getPrice() << endl << endl;
	cout << " 添加菜式成功！请按任意键继续。\n";
	cin >> q;
	return;
}

// 删除菜谱中的指定菜式
void deleteOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	string name, id;
	char q;
	
	cout << "您正在进行删除菜式操作，请输入对应编号：\n? ";
	cin >> id;
	if ( possessID.find(id) == possessID.end() ) {
		cout << " 该编号不存在！请按任意键退出。\n";
		cin >> q;
		return;
	}
	
	cout << " 请输入对应菜名：\n? ";
	cin >> name;
	if ( !menu.count(name) ) {
		cout << " 该菜名不存在！请按任意键退出。\n";
		cin >> q;
		return;
	}
	
	if ( menu[name].getDishID() != id ) {
		cout << "编号与菜名不符，删除失败！请按任意键退出。\n";
		cin >> q;
		return;
	}
	
	cout << " 删除菜式如下：\n\n";
	cout << " 编号" << setw(9) << "菜名" << setw(14) << "价格" << endl; 
	cout << " " << menu[name].getDishID() << "    " << name << "      \t" << menu[name].getPrice() << endl << endl;
	
	menu.erase( name );
	possessID.erase( possessID.find(id) );
	cout << "删除成功！请按任意键继续。\n";
	cin >> q;
	return;
} 
