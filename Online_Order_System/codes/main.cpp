/*
 *	作者：Agvensome，2022/4/1 
 *	联系：Agvensome@126.com
 *	个人：https://leetcode-cn.com/u/agvensome/ 
 *		  https://github.com/Agvensome
 *	其中菜式、订单类有参考 https://github.com/AngryHacker/C_plus_plus_exercise/tree/master/
*/

// main.cpp
#include<string>

std::string buyerName = "null";		// 买家账号（姓名） 	

// 主界面 
void mainInterface();

int main() { 
	mainInterface();
}




// 独立测试特定的类和函数可使用以下 main 函数 

//int main() {
//	// 测试 Dish 类 
//	string s1 = "0001", s2 = "薯片";
//	Dish d1(s1, s2);
//	cout << d1.getDishName() << "    " << d1.getPrice() << endl;
//	
//	Dish d3(d1);
//	d3.setDishID("0003");
//	d3.setDishName("番茄");
//	d3.setPrice(5.5);
//	cout << d3.getDishID() << "    " << d3.getPrice() << endl;
//	
//	const Dish d2("0002", "猕猴桃", 10.5);
//	cout << d2.getDishName() << "    " << d2.getPrice() << endl << endl;
//	
//	// 测试 Date 类 
//	const Date da1(2022, 3, 21, 2);
//	Date da2;
//	da2.setYear(2021);	da2.setMonth(3);	da2.setDay(21);		da2.setHour(3);
//	cout << "da1 == da2? " << (da2 == da1) << endl;
//	cout << "da1.year = " << da1.getYear() << ". da1.month = " << da1.getMonth() << endl << endl;
//	
//	// 测试 Order 类
//	Order Od1;
//	string dishId = "0004", dishName = "鱼豆腐";
//	Od1.setDishName( dishName );
//	Od1.setDishID( dishId );
//	Od1.setPrice( 12.5 );
//	Od1.setBookDate( da1 );
//	cout << "订单Od1的月份是：" << Od1.getBookDate().getMonth() << "月.\n";
//	
//	Order Od2(d1, 6);
//	cout << "订单Od2的菜式和份数分别是: " << Od2.getDishName() << "    " << Od2.getNum() << endl; 
//	
//	Order Od3(dishId, dishName, 12.5);
//	string perName = "Agvensome", peraddress = "Earth"; 
//	Od3.setCustomerName(perName);
//	Od3.setAddress(peraddress);
//	Od3.setNum( 3 );
//	cout << "订单Od3的顾客和送达地址分别是: " << Od3.getCustomerName() << "    " << Od3.getAddress() << endl; 
//	cout << "订单Od3的菜式和份数分别是: " << Od3.getDishName() << "    " << Od3.getNum() << endl << endl; 
//	
//	const Order Od4("0005", "维他奶", 12, "Your Dad");
//	cout << "订单Od4的顾客和菜式分别是: " << Od4.getCustomerName() << "    " << Od4.getDishName() << endl << endl;   
	
//	// 测试菜单载入 
//	unordered_map<string, Dish> menu;
//	unordered_set<string> possessID;
//	inputAllDishes( menu, possessID ); 
	
//	// 测试打印菜单中的所有菜式
//	printAllDishes( menu ); 
//	cout << endl;
	
//	// 按菜名查询单一菜式
//	bool isDish = inquireOneDish( menu ); 
//	cout << endl;
//	
//	// 往菜谱添加新菜式 
//	appendOneDish( menu, possessID );
//	
//	// 删除菜谱中特定菜式
//	deleteOneDish( menu, possessID ); 
//	
//	printAllDishes( menu );
//	cout << endl;
	
//	// 将所有菜式重新写入本地菜谱文件
//	outputAllDishes( menu );
//	
//	// 管理员登录
//	bool sellerEnter = sellerRegister();
//	 
//	// 管理员更换密码
//	bool exchange = sellerSetCode();
	
//	// 新用户（买家）注册 
//	buyerSignIn();
	
//	// 买家登录 
//	bool buyerEnter = buyerRegister( buyerName );
//	cout << buyerName << endl;
	
//	// 卖家初始化订单文件
//	sellOp().initializeOrder(); 
//	
//	// 买家下单
//	buyOp().appendOrder(menu);

//	// 买家查询订单
//	buyOp().inquireOrder();
//	
//	// 买家修改取消订单
//	buyOp().modifyOrder(menu); 
	
//	// 卖家查询订单
//	sellOp().inquireOrder();
//	
//	// 卖家修改订单
//	sellOp().modifyOrder( menu ); 
//}

