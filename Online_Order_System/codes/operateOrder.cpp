// operateOrder.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
#include<unordered_map>
#include"newClass.h"
#include"operateOrder.h"
using namespace std;

// 买家账号（姓名）是全局变量
extern string buyerName;

//// 结尾/取消订单标志变量 
//const Order endMark("null", "null", 0);
//const Order cancelMark("cancel", "cancel", 0);
//
//// 判断订单是否为结尾标志 
//bool isEndMark( const Order & od ) {
//	return od.getDishID() == "null" && od.getDishName() == "null";
//}


// 打印菜谱中所有菜式 	
void printAllDishes( unordered_map<string, Dish> & menu );

// Singleton模式，函数调用返回一个静态卖家操作订单类 
sellerOperate & sellOp() {
	static sellerOperate s;
	return s;
}

// Singleton模式，函数调用返回一个静态买家操作订单类 
buyerOperate & buyOp() {
	static buyerOperate b;
	return b;
}

// 卖家初始化订单文件 
void sellerOperate::initializeOrder() {
	cout << endl;
	
	cout << " 若订单文件存在，将删除原有数据，要进行文件初始化吗？( Y / N )\n ";
	char answer;
	cin >> answer;
	if ( answer == 'y' || answer == 'Y' ) {
		// 以写方式打开，建立新文件
		fstream fdat( "order.txt", ios::out );
		cout << " 订单文件已经初始化，"; 
		fdat.close();										
	} else {
		cout << " 初始化已取消，";
	}
												
	cout << "按任意键继续。\n\n";
	cin >> answer;
	return;
}

// 卖家查询订单
void sellerOperate::inquireOrder() {
	cout << endl;
	
	char choice;

	string name, dish, num, address, phone;
	int y, m, d, h;
	string sign;
	
	bool end = false;
	while (1) {
		
		cout << " 尊敬的商家，您正在进行查询订单业务，请输入订单查询范围:\n"
			 << " 1: 全部订单\t" << "2: 已备餐订单\t" << "3: 已取消订单\t" << "4: 根据用户名查询\t" << "Q: 退出\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << "姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
					"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
				}
				fdat.close();
				break;
			}
			case '2': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " 姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( sign == "已备餐" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '3': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " 姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( sign == "已取消" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '4':{
				cout << " 请输入用户名：\n ";
				cin >> buyerName;
				
				ifstream instuf("buyer.txt", ios::in);
				if ( !instuf ) {
					cerr << "File could not be open.\n";
					abort();
				} 
				instuf.seekg( 0, ios::beg ); 
				string userCmp; 
				while ( instuf >> userCmp ) {
					if ( buyerName == userCmp )	break;
				}
				instuf.close();
				if ( userCmp != buyerName ) {
					cout << "抱歉，该用户名不存在！请按任意键继续\n";
					cin >> userCmp;
				} else buyOp().inquireOrder();
				
				break;
			}
			case 'q':
			case 'Q':	{
				end = true;
				break;
			}
			default:	cout << " 输入错误！请重新输入。\n";
		}
		cout << endl;
		if (end)	break;
	} 
	
} 

// 卖家修改菜单
void sellerOperate::modifyOrder( unordered_map<string, Dish> & menu ) {
	cout << endl;
	
	// 复制可修改的订单到序列 
	ifstream instuf("order.txt", ios::in);
	ofstream outstuf("order_copy.txt", ios::out);
	char ch;
	if ( !instuf || !outstuf ) {
		cout << " 订单文件不存在！按任意键退出。\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	string name, dish, address, phone, sign;
	int y, m, d, h, num, cnt = 1;
	vector< pair<int, Order> > v;
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		
		if ( sign == "已提交" ) {
			cout << cnt << "\t" << name << "\t" << dish << "\t" << num << "\t" << sign << "\t" 
				 << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
			Order od( menu[dish].getDishID(), dish, menu[dish].getPrice(), name, address, phone );
			Date bookDate( y, m, d, h );
			od.setBookDate( bookDate );
			od.setNum( num );
			
			v.push_back( make_pair( cnt++, od ) );
		} else {
			outstuf << ' ' << name << ' ' << dish << ' ' << num << ' ' << sign << ' ' << address << ' ' << y << ' ' << m << ' ' << d << ' ' << h << ' ' << phone << '\n';
		}
	}
	
	instuf.close();
	
	int n;
	bool con = true;
	while (con) {
		cout << " \n尊敬的商家，您正在修改订单，以下订单允许修改：\n\n";
		cout << " 编  号" << "\t姓  名" << "\t菜   式 " << "\t数 量" << "\t状 态" << "\t地 址" << "\t时     间" << "\t电    话\n"; 
		for ( auto & p : v ) {
			if ( p.second.getModify() == 0 )	continue;
			cout << p.first << "\t";
			cout << p.second.getCustomerName() << "\t"; 
			cout << p.second.getDishName() << "\t"; 
			cout << p.second.getNum() << "\t";
			cout << "已提交" <<"\t";
			cout << p.second.getAddress() << "\t";
			cout << p.second.getBookDate().getYear() << "年";
			cout << p.second.getBookDate().getMonth() << "月"; 
			cout << p.second.getBookDate().getDay() << "日";
			cout << p.second.getBookDate().getHour() << "时" << "\t";
			cout << p.second.getPhone() << endl; 
		}
		cout << "\n 请输入待修改订单编号(输入-1退出修改订单):\n ";
		cin >> n;
		if ( n == -1 )	break;
		else if ( n < 1 || n > v.size() ) {
			cout << " 编号错误！\n";
			continue;
		} else if ( v[n-1].second.getModify() == 0 ) {
			cout << "该订单不可修改！\n";
			continue;
		} 
		
		while (1) {
			cout << " 尊敬的商家，您是否确认为其配餐？(Y/N) \n\n ";
			cin >> ch;
			if ( ch == 'y' || ch == 'Y' ) {
				v[n-1].second.setModify();
				cout << " 订单" << n << "修改完成！\n\n";
				cout << "\n修改后订单如下：\n";
				cout << " 编  号" << "\t姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				cout << v[n-1].first << "\t";
				cout << v[n-1].second.getCustomerName() << "\t"; 
				cout << v[n-1].second.getDishName() << "\t"; 
				cout << v[n-1].second.getNum() << "\t";
				if ( v[n-1].second.getModify() == 1 ) cout << "已提交" <<"\t";
				else	cout << "已备餐" << "\t"; 
				cout << v[n-1].second.getAddress() << "\t";
				cout << v[n-1].second.getBookDate().getYear() << "年";
				cout << v[n-1].second.getBookDate().getMonth() << "月"; 
				cout << v[n-1].second.getBookDate().getDay() << "日";
				cout << v[n-1].second.getBookDate().getHour() << "时" << "\t";
				cout << v[n-1].second.getPhone() << endl;   
				break;
			} else if ( ch == 'N' || ch == 'n' ) break;
			else cout << " 输入错误，请重新输入！\n\n";	
		}
		 
		cout << " \n是否继续修改订单？(N为否) \n ";
		cin >> ch;
		if ( ch == 'n' || ch == 'N' )	con = false;
	}
	
	// 把哈希表订单复制到副本中
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	for (auto & p : v) {
		outstuf << p.second.getCustomerName() << ' ' << p.second.getDishName() << ' ' << p.second.getNum() << ' ';
		if ( p.second.getModify() == 1 ) {
			outstuf << "已提交 ";
		} else outstuf << "已备餐 ";
		outstuf << p.second.getAddress() << ' ' << p.second.getBookDate().getYear() << ' '<< p.second.getBookDate().getMonth()
				<< ' ' << p.second.getBookDate().getDay() << ' ' << p.second.getBookDate().getHour() << ' ' << phone << '\n';
	} 
	outstuf.close();
	
	// 把订单文件内容换成副本内容
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	instuf.open( "order_copy.txt", ios::in );
	outstuf.open("order.txt", ios::out );
	if ( !instuf || !outstuf ) {
		cout << " 订单文件不存在！按任意键退出。\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		outstuf << name << ' ' << dish << ' ' << num << ' ' << sign << ' ' << address << ' ' 
				<< y << ' ' << m << ' '<< d << ' ' << h << ' ' << phone << '\n';
	}
	
	instuf.close();
	outstuf.close();
	
	cout << "\n尊敬的商家，订单修改完成！请按任意键继续。\n";
	cin >> ch;
	return; 
} 

// 买家添加订单
void buyerOperate::appendOrder( unordered_map<string, Dish> & menu ) {
	cout << endl;
	
	string choice;
	ofstream fdat("order.txt", ios::app );
	
	if ( !fdat ) {
		cout << " 订单文件不存在！按任意键退出。\n";
		cin >> choice;
		return; 
	}
		
	string address, phone;
	int num, y, m, d, h;
	Order od; 
	vector< pair<string, int> > v;								// 菜式和数量 
	
	cout << " 尊敬的 " << buyerName <<" 用户，您正在添加订单，请输入您的地址和电话：\n 地址? ";
	cin >> address;
	cout << " 电话? ";
	cin >> phone;
	cout << "\n 请输入送达时间(年/月/日/时)：\n";
	cin >> y >> m >> d >> h; 
	Date book(y, m, d, h);
	
	cout << " \n 您正在点餐，请在以下菜谱中选择（若点餐完毕，请按 Q / q 键退出）\n\n";
	
	printAllDishes(menu);
	
	cout << endl;
	
	while ( 1 ) {
		cin >> choice;
		if ( choice == "Q" || choice == "q" ) {
			break;
		}
		else if ( !menu.count(choice) ) {
			cout << " 抱歉，该菜式不存在！请重新点餐！\n\n";
			continue; 
		}
		cout << " 请输入数量：\n? ";
		cin >> num;
		
		Order od( menu[choice].getDishID(), choice, menu[choice].getPrice(), buyerName, address, phone );
		od.setBookDate( book );
		
		// 按照姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话写入订单文件 
		if( od.setNum(num) ) {
			cout << " 请继续输入下一个菜式，若点餐完毕，请按 Q / q 键退出.\n\n"; 
			string c = "已提交";
			if ( od.getModify() == 0 ) {
				c = "已备餐";
			}
			fdat << buyerName << ' ' << choice << ' ' << num << ' ' << c << ' ' << address
				 << "    " << y << ' ' << m << ' ' << d << ' ' << h << "    " << phone << '\n';
			v.push_back( make_pair(choice, num) );
		} else {
			cout << " 点餐失败！请重新点餐。\n\n";
		}
	}
	
	cout << " 点餐完毕！\n\n";
	
	cout << " 尊敬的 " << buyerName << "，您刚才点的菜式有：\n\n";
	for (auto & i : v) {
		cout << "   " << i.first << "  " << i.second << "份。\n";
	}
	cout << " \n 显示完毕!\n"; 
	
	fdat.close(); 
	
	cout << "\n 本次点餐完成，请按任意键继续。\n";
	cin >> choice;
	return;
} 

// 买家查询订单
void buyerOperate::inquireOrder() {
	cout << endl;
	
	char choice;

	string name, dish, num, address, phone;
	int y, m, d, h;
	string sign;
	
	bool end = false;
	while (1) {
		
		cout << " 请输入订单查询范围:\n"
			 << " 1: 全部订单\t" << "2: 商家已处理订单\t" << "3: 已取消订单\t" << "Q: 退出\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << "姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					if ( name == buyerName ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '2': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " 姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( name == buyerName && sign == "已备餐" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '3': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " 订单文件不存在！按任意键退出。\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " 姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( name == buyerName && sign == "已取消" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "年" << m << "月" << d << "日" << h << "时" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case 'q':
			case 'Q':	{
				end = true;
				break;
			}
			default:	cout << " 输入错误！请重新输入。\n";
		}
		cout << endl;
		if (end)	break;
	} 
	
} 

// 买家修改取消单子 
void buyerOperate::modifyOrder(unordered_map<string, Dish> & menu) {
	cout << endl;
	
	// 复制粘贴其他顾客的订单到副本、复制本顾客的订单到序列 
	ifstream instuf("order.txt", ios::in);
	ofstream outstuf("order_copy.txt", ios::out);
	char ch;
	if ( !instuf || !outstuf ) {
		cout << " 订单文件不存在！按任意键退出。\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	string name, dish, address, phone, sign;
	int y, m, d, h, num, cnt = 1;
	vector< pair<int, Order> > v;
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		
		if ( name == buyerName && sign == "已提交" ) {
			
			Order od( menu[dish].getDishID(), dish, menu[dish].getPrice(), name, address, phone );
			Date bookDate( y, m, d, h );
			od.setBookDate( bookDate );
			od.setNum( num );
			
			v.push_back( make_pair( cnt++, od ) );
		} else {
			outstuf << ' ' << name << ' ' << dish << ' ' << num << ' ' << sign << ' ' << address << ' ' << y << ' ' << m << ' ' << d << ' ' << h << ' ' << phone << '\n';
		}
	}
	
	instuf.close();
	
	while (1) {
		// 打印可修改的订单
		cout << " 尊敬的 " << buyerName <<" 用户，您正在修改订单，根据以下可修改订单，请输入对应编号? \n\n";
		cout << " 编  号" << "\t姓  名" << "\t菜   式 " << "\t数 量" << "\t状 态" << "\t地 址" << "\t时     间" << "\t电    话\n"; 
		for ( auto & p : v ) {
			if ( p.second.getModify() == 0 )	continue;
			cout << p.first << "\t";
			cout << p.second.getCustomerName() << "\t"; 
			cout << p.second.getDishName() << "\t"; 
			cout << p.second.getNum() << "\t";
			cout << "已提交" <<"\t";
			cout << p.second.getAddress() << "\t";
			cout << p.second.getBookDate().getYear() << "年";
			cout << p.second.getBookDate().getMonth() << "月"; 
			cout << p.second.getBookDate().getDay() << "日";
			cout << p.second.getBookDate().getHour() << "时" << "\t";
			cout << p.second.getPhone() << endl; 
		}
		cout << "\n 输入对应编号：(输入-1退出修改)\n";
		int n, end = 0;
		cin >> n;
		if ( n == -1 )	break;
		while ( n < 1 || n > v.size() ) {
			cout << " 编号输入有误，请重新输入.\n\n";
			continue;
		}
		cout << "\n修改前订单如下：\n";
		cout << " 编  号" << "\t姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
		cout << v[n-1].first << "\t";
		cout << v[n-1].second.getCustomerName() << "\t"; 
		cout << v[n-1].second.getDishName() << "\t"; 
		cout << v[n-1].second.getNum() << "\t";
		cout << "已提交" <<"\t";
		cout << v[n-1].second.getAddress() << "\t";
		cout << v[n-1].second.getBookDate().getYear() << "年";
		cout << v[n-1].second.getBookDate().getMonth() << "月"; 
		cout << v[n-1].second.getBookDate().getDay() << "日";
		cout << v[n-1].second.getBookDate().getHour() << "时" << "\t";
		cout << v[n-1].second.getPhone() << endl; 
		
		cout << " \n您可以进行以下修改，请输入操作选项:\n"
			 << " 1: 修改菜式数量\t" << "2: 修改送达时间\t" << "3: 修改送达地址\t" << "4：取消订单\t" << "Q: 退出\n";

		cin >> ch;
		switch(ch) {
			
			case '1': {
				cout << "\n 您正在修改菜式数量，请输入新的菜式数量：\n ";
				int num;
				cin >> num;
				if ( num < 1 ) {
					cout << " 输入有误！\n";
				} else {
					v[n-1].second.setNum(num);
					cout << "修改完成！\n";
				}
				break;
			}
			case '2': {
				cout << "\n 您正在修改送达时间，请输入新的送达时间(年/月/日/时)：\n";
				cout << " 年：\n "; 
				cin >> y;
				cout << " 月：\n "; 
				cin >> m;
				cout << " 日：\n "; 
				cin >> d;
				cout << " 小时：\n "; 
				cin >> h;
				Date bookDate(y, m, d, h);
				v[n-1].second.setBookDate( bookDate );
				cout << "修改完成！\n";
				break;
			}
			case '3': {
				cout << "\n 您正在修改送达地址，请输入新的送达地址：\n ";
				cin >> address;
				v[n-1].second.setAddress( address );
				cout << "修改完成！\n";
				break;
			}
			case '4': {
				v[n-1].second.setModify();
				cout << "订单已取消！\n";
				break;
			}
			case 'q':
			case 'Q': {
				end = 1; 
				break;
			}
			default: {
				cout << "输入有误，请重新输入！\n\n";
				break;
			}
		}
		
		cout << "\n修改后订单如下：\n";
		cout << " 编  号" << "\t姓  名" << "\t菜   式 " << "\t数量" << "\t状态" << "\t地址" << "\t时     间" << "\t电    话\n"; 
		cout << v[n-1].first << "\t";
		cout << v[n-1].second.getCustomerName() << "\t"; 
		cout << v[n-1].second.getDishName() << "\t"; 
		cout << v[n-1].second.getNum() << "\t";
		if ( v[n-1].second.getModify() == 1 ) cout << "已提交" <<"\t";
		else	cout << "已取消" << "\t"; 
		cout << v[n-1].second.getAddress() << "\t";
		cout << v[n-1].second.getBookDate().getYear() << "年";
		cout << v[n-1].second.getBookDate().getMonth() << "月"; 
		cout << v[n-1].second.getBookDate().getDay() << "日";
		cout << v[n-1].second.getBookDate().getHour() << "时" << "\t";
		cout << v[n-1].second.getPhone() << endl;  
		
		cout << "\n请按任意键继续。\n";
		cin >> ch;
		if ( end )	break;
	}
	
	// 把该用户的订单全部输出到副本文件中
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	for (auto & p : v) {
		outstuf << p.second.getCustomerName() << ' ' << p.second.getDishName() << ' ' << p.second.getNum() << ' ';
		if ( p.second.getModify() == 0 ) {
			outstuf << "已取消 ";
		} else outstuf << "已提交 ";
		outstuf << p.second.getAddress() << ' ' << p.second.getBookDate().getYear() << ' '<< p.second.getBookDate().getMonth()
				<< ' ' << p.second.getBookDate().getDay() << ' ' << p.second.getBookDate().getHour() << ' ' << phone << '\n';
	} 
	outstuf.close();
	
	// 把订单文件内容换成副本内容
	// 姓名、菜式、数量、订单状态、地址、年、月、日、小时、电话
	instuf.open( "order_copy.txt", ios::in );
	outstuf.open("order.txt", ios::out );
	if ( !instuf || !outstuf ) {
		cout << " 订单文件不存在！按任意键退出。\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		outstuf << name << ' ' << dish << ' ' << num << ' ' << sign << ' ' << address << ' ' 
				<< y << ' ' << m << ' '<< d << ' ' << h << ' ' << phone << '\n';
	}
	
	instuf.close();
	outstuf.close();
	
	cout << "您已退出修改订单！请按任意键继续。\n";
	cin >> ch;
	return;
} 

