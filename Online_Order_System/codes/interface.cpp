// interface.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include"newClass.h"
#include"operateOrder.h"
using namespace std;

extern string buyerName;	// 全局变量买家账号（姓名）

// 新用户（买家）注册 
void buyerSignIn();
// 买家登录 
bool buyerRegister( string & buyerName );

// 管理员登录 
bool sellerRegister();
// 管理员更换密码
bool sellerSetCode();

// 从本地文件载入菜谱中所有菜式 
void inputAllDishes( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );
// 将所有菜式重新写入本地菜谱文件
void outputAllDishes( unordered_map<string, Dish> & menu ); 
// 打印菜谱中所有菜式 	
void printAllDishes( unordered_map<string, Dish> & menu );	
// 按菜名查询单一菜式 
bool inquireOneDish( unordered_map<string, Dish> & menu );	
// 往菜谱添加新菜式 
void appendOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );
// 删除菜谱中的指定菜式
void deleteOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );

// 买家处理 
void buyerInterface( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	while (1) {
		system("cls");
		cout << endl;
		cout << "  尊敬的消费者，请选择您的身份：\n\n";
		cout << "  ======  ( 1 )  用户  ======  ( 2 ) 新用户  ======  ( 0 ) 退出  ======  \n\n\t"; 
		char ch;
		cin >> ch;
		while ( ch < '0' || ch > '2' ) {
			cout << "编号不合法，请重新输入：\t";
			cin >> ch;
		}
		system("cls");
		
		cout << endl;
		
		if ( ch == '0' ) {
			cout << "  已退出消费者选择，请按任意键继续。\n";
			cin >> ch;
			return;
		}
		
		else if ( ch == '1' ) {
			cout << "  已选择用户，请登录\n\n\t";
			bool sign = buyerRegister( buyerName );
			if ( !sign ) continue;
			while (1) {
				system("cls");
				cout << "  您已登录，您可以进行以下操作：\n\n\t"; 
				cout << "  ======  ( 1 )  点餐  ======  ( 2 )  查询订单  ======  ( 3 )  修改/取消订单  ======  ( 0 ) 退出  ======\n\n\t";
				cout << "  尊敬的用户，请输入编号：\n\t";
				
				cin >> ch;
				
				while ( ch < '0' || ch > '3' ) {
					cout << "编号不合法，请重新输入：\t";
					cin >> ch;
				}
				system("cls");
				
				if ( ch == '0' ) {
					cout << "  您已退出登录，请按任意键继续。\n";
					cin >> ch;
					break;
				}
				
				switch(ch) {
					case '1': {
						buyOp().appendOrder(menu); 
						break;
					}
					case '2': {
						buyOp().inquireOrder();
						break;
					}
					case '3': {
						buyOp().modifyOrder(menu);
						break;
					}
				}
			}
			
			
		} 
		
		else if ( ch == '2' ) {
			cout << "  已选择新用户，您可以进行以下操作：\n\n\t"; 
			cout << "  ======  ( 1 )  注册用户  ======  ( 0 ) 退出  ======  \n\n\t";
			cout << "  尊敬的新用户，请输入编号：\n\t";
			cin >> ch;
			
			if ( ch != '1' && ch != '0' ) {
				cout << "输入不合法！请按任意键退出。\n";
				cin >> ch;
				continue;
			}
			
			else if ( ch == '0' ) {
				cout << "退出新用户界面成功！请按任意键退出。\n";
				cin >> ch;
				continue;
			}
			
			else if ( ch == '1' ) {
				buyerSignIn();
			}
		}
	}
}

// 卖家处理 
void sellerInterface( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	
	system("cls");
	cout << endl;
	cout << "  尊敬的商家管理员，请登录：\n\n"; 
	
	bool sign = sellerRegister();
	if ( !sign )	return;
	
	while (1) {
		
		system("cls");
		cout << endl;
		
		cout << "  尊敬的商家管理员，您可以操作以下栏目：\n\n";
		cout << "  ======  ( 1 ) 订  单  ======  ( 2 ) 菜  单  ======  ( 3 ) 重置密码  ======  ( 0 ) 退  出  ======\n\n";
		cout << "  请输入对应编号:\t";
		
		char ch;
		cin >> ch;	
		
		while ( ch < '0' && ch > '3' ) {
			cout << "编号不合法，请重新输入。\n";
			cin >> ch;
		}
		
		if ( ch == '0' ) {
			cout << "  退出成功，请按任意键继续。\n";
			cin >> ch;
			return;
		}
		
		system("cls");
		cout << endl;
		
		if ( ch == '1' ) {
			cout << "  尊敬的商家管理员，您可以对订单进行以下操作：\n\n";
			cout << "  ======  ( 1 ) 初始化订单  ======  ( 2 ) 查询订单  ======  ( 3 ) 备餐登记  ======  ( 0 ) 退  出  ======\n\n";
			
			cout << "  请输入对应编号:\t";
			cin >> ch;

			while ( ch < '0' && ch > '3' ) {
				cout << "编号不合法，请重新输入。\n";
				cin >> ch;
			}
			
			if ( ch == '0' ) {
				cout << "  退出成功，请按任意键继续。\n";
				cin >> ch;
				continue;
			}	
			
			switch(ch) {
				case '1' :{
					sellOp().initializeOrder();
					break;
				}
				case '2' :{
					sellOp().inquireOrder();
					break;
				}
				case '3' :{
					sellOp().modifyOrder( menu ); 
					break;
				}
			}
		}
		
		else if ( ch == '2' ) {
			cout << "  尊敬的商家管理员，您可以对菜单进行以下操作：\n\n";
			cout << "  ======  ( 1 ) 添加菜式  ======  ( 2 ) 查询菜单  ======  ( 3 ) 删除菜式  ======  ( 0 ) 退  出  ======\n\n";
			
			cout << "  请输入对应编号:\t";
			cin >> ch;

			while ( ch < '0' && ch > '3' ) {
				cout << "编号不合法，请重新输入。( 1 ) 添加菜式、( 2 ) 查询菜单、( 3 ) 删除菜式、( 0 ) 退  出\n\t";
				cin >> ch;
			}
			
			if ( ch == '0' ) {
				cout << "  退出成功，请按任意键继续。\n";
				cin >> ch;
				continue;
			}	
		
			system("cls");
			cout << endl; 
			
			switch( ch ) {
				case '1': {
					while (1) {
						appendOneDish(menu, possessID);
						cout << "若全部添加完成，请按 Q / q 退出\n";
						cin >> ch;
						if ( ch == 'Q' || ch == 'q' ) {
							system("cls");
							break;
						}
					}
					break;
				}
				case '2': {
					cout << "请选择以下查询操作：\n\n\t";
					cout << "  ======  ( 1 ) 按名查询菜式  ======  ( 2 ) 查询全部菜式  ======\n\n";
					cout << "请输入对应编号\n\t";
					cin >> ch;
					while ( ch != '1' && ch != '2' ) {
						cout << "编号不合法，请重新输入。( 1 ) 按名查询菜式、( 2 ) 查询全部菜式\n\t";
						cin >> ch;
					}
			
					system("cls");
					cout << endl;
					
					if ( ch == '1' )	inquireOneDish( menu );
					else if ( ch == '2' )	printAllDishes( menu );
					
					cout << "\n请按任意键继续。\n\n";
					cin >> ch;					
					break;
				}
				case '3': {
					while (1) {
						deleteOneDish( menu, possessID );
						cout << "若全部删除完成，请按 Q / q 退出\n";
						cin >> ch;
						if ( ch == 'Q' || ch == 'q' ) {
							system("cls");
							break;
						}
					}
					break;
				}
			}
		}
		
		else if ( ch == '3') {
			sellerSetCode();
			return;
		}
	}
	
};

// 主界面函数 
void mainInterface() {
	
	unordered_map<string, Dish> menu;		// 菜单 
	unordered_set<string> possessID;		// 菜名集 
	inputAllDishes( menu, possessID ); 
	
	while (1) {
		system("cls");
		cout << endl;
		cout << "  ======  ======  欢迎使用线上订餐系统  ======  ======  \n\n";
		cout << "  ======  ======     请选择您的身份     ======  ======  \n\n";
		cout << "          ----    ( 1 ) 买    家    ----          \n\n";
		cout << "          ----    ( 2 ) 管 理 员    ----          \n\n";
		cout << "          ----    ( 0 ) 退    出    ----          \n\n";
		cout << "  ======  ======     请输入对应编号     ======  ======  \n\n\n";
		
		// 输入编号 
		cout << "  编号：\t";
		int num;
		cin >> num;
		system("cls");
		
		// 已选择身份，继续下一步操作 
		while ( num != 1 && num != 2 && num != 0 ) {
			cout << "\n  编号不合法，请重试！\n  请输入对应编号：( 1 ) 买家、( 2 ) 管理员。\n\n\t";
			cin >> num;
		}
		
		// 退出系统 
		if ( !num ) {
			cout << "\n  系统已退出，感谢您的使用。\n";
			outputAllDishes( menu );	// 将所有菜式重新写入本地菜谱文
			return;
		} 
		
		system("cls");
		
		char ch = '0' + num;
		switch ( ch ) {
			case '1': {
				cout << "\n  选择买家成功！请按任意键请继续。\n\n";
				cin >> ch;
				buyerInterface( menu, possessID );
				break;
			}
			case '2': {
				cout << "\n  选择管理员成功！请按任意键请继续。\n\n";
				cin >> ch;
				sellerInterface( menu, possessID );
				break;
			}
		} 
	}
}

