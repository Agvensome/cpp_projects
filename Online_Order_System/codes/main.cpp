/*
 *	���ߣ�Agvensome��2022/4/1 
 *	��ϵ��Agvensome@126.com
 *	���ˣ�https://leetcode-cn.com/u/agvensome/ 
 *		  https://github.com/Agvensome
 *	���в�ʽ���������вο� https://github.com/AngryHacker/C_plus_plus_exercise/tree/master/
*/

// main.cpp
#include<string>

std::string buyerName = "null";		// ����˺ţ������� 	

// ������ 
void mainInterface();

int main() { 
	mainInterface();
}




// ���������ض�����ͺ�����ʹ������ main ���� 

//int main() {
//	// ���� Dish �� 
//	string s1 = "0001", s2 = "��Ƭ";
//	Dish d1(s1, s2);
//	cout << d1.getDishName() << "    " << d1.getPrice() << endl;
//	
//	Dish d3(d1);
//	d3.setDishID("0003");
//	d3.setDishName("����");
//	d3.setPrice(5.5);
//	cout << d3.getDishID() << "    " << d3.getPrice() << endl;
//	
//	const Dish d2("0002", "⨺���", 10.5);
//	cout << d2.getDishName() << "    " << d2.getPrice() << endl << endl;
//	
//	// ���� Date �� 
//	const Date da1(2022, 3, 21, 2);
//	Date da2;
//	da2.setYear(2021);	da2.setMonth(3);	da2.setDay(21);		da2.setHour(3);
//	cout << "da1 == da2? " << (da2 == da1) << endl;
//	cout << "da1.year = " << da1.getYear() << ". da1.month = " << da1.getMonth() << endl << endl;
//	
//	// ���� Order ��
//	Order Od1;
//	string dishId = "0004", dishName = "�㶹��";
//	Od1.setDishName( dishName );
//	Od1.setDishID( dishId );
//	Od1.setPrice( 12.5 );
//	Od1.setBookDate( da1 );
//	cout << "����Od1���·��ǣ�" << Od1.getBookDate().getMonth() << "��.\n";
//	
//	Order Od2(d1, 6);
//	cout << "����Od2�Ĳ�ʽ�ͷ����ֱ���: " << Od2.getDishName() << "    " << Od2.getNum() << endl; 
//	
//	Order Od3(dishId, dishName, 12.5);
//	string perName = "Agvensome", peraddress = "Earth"; 
//	Od3.setCustomerName(perName);
//	Od3.setAddress(peraddress);
//	Od3.setNum( 3 );
//	cout << "����Od3�Ĺ˿ͺ��ʹ��ַ�ֱ���: " << Od3.getCustomerName() << "    " << Od3.getAddress() << endl; 
//	cout << "����Od3�Ĳ�ʽ�ͷ����ֱ���: " << Od3.getDishName() << "    " << Od3.getNum() << endl << endl; 
//	
//	const Order Od4("0005", "ά����", 12, "Your Dad");
//	cout << "����Od4�Ĺ˿ͺͲ�ʽ�ֱ���: " << Od4.getCustomerName() << "    " << Od4.getDishName() << endl << endl;   
	
//	// ���Բ˵����� 
//	unordered_map<string, Dish> menu;
//	unordered_set<string> possessID;
//	inputAllDishes( menu, possessID ); 
	
//	// ���Դ�ӡ�˵��е����в�ʽ
//	printAllDishes( menu ); 
//	cout << endl;
	
//	// ��������ѯ��һ��ʽ
//	bool isDish = inquireOneDish( menu ); 
//	cout << endl;
//	
//	// ����������²�ʽ 
//	appendOneDish( menu, possessID );
//	
//	// ɾ���������ض���ʽ
//	deleteOneDish( menu, possessID ); 
//	
//	printAllDishes( menu );
//	cout << endl;
	
//	// �����в�ʽ����д�뱾�ز����ļ�
//	outputAllDishes( menu );
//	
//	// ����Ա��¼
//	bool sellerEnter = sellerRegister();
//	 
//	// ����Ա��������
//	bool exchange = sellerSetCode();
	
//	// ���û�����ң�ע�� 
//	buyerSignIn();
	
//	// ��ҵ�¼ 
//	bool buyerEnter = buyerRegister( buyerName );
//	cout << buyerName << endl;
	
//	// ���ҳ�ʼ�������ļ�
//	sellOp().initializeOrder(); 
//	
//	// ����µ�
//	buyOp().appendOrder(menu);

//	// ��Ҳ�ѯ����
//	buyOp().inquireOrder();
//	
//	// ����޸�ȡ������
//	buyOp().modifyOrder(menu); 
	
//	// ���Ҳ�ѯ����
//	sellOp().inquireOrder();
//	
//	// �����޸Ķ���
//	sellOp().modifyOrder( menu ); 
//}

