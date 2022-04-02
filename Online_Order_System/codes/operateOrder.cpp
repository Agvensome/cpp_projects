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

// ����˺ţ���������ȫ�ֱ���
extern string buyerName;

//// ��β/ȡ��������־���� 
//const Order endMark("null", "null", 0);
//const Order cancelMark("cancel", "cancel", 0);
//
//// �ж϶����Ƿ�Ϊ��β��־ 
//bool isEndMark( const Order & od ) {
//	return od.getDishID() == "null" && od.getDishName() == "null";
//}


// ��ӡ���������в�ʽ 	
void printAllDishes( unordered_map<string, Dish> & menu );

// Singletonģʽ���������÷���һ����̬���Ҳ��������� 
sellerOperate & sellOp() {
	static sellerOperate s;
	return s;
}

// Singletonģʽ���������÷���һ����̬��Ҳ��������� 
buyerOperate & buyOp() {
	static buyerOperate b;
	return b;
}

// ���ҳ�ʼ�������ļ� 
void sellerOperate::initializeOrder() {
	cout << endl;
	
	cout << " �������ļ����ڣ���ɾ��ԭ�����ݣ�Ҫ�����ļ���ʼ����( Y / N )\n ";
	char answer;
	cin >> answer;
	if ( answer == 'y' || answer == 'Y' ) {
		// ��д��ʽ�򿪣��������ļ�
		fstream fdat( "order.txt", ios::out );
		cout << " �����ļ��Ѿ���ʼ����"; 
		fdat.close();										
	} else {
		cout << " ��ʼ����ȡ����";
	}
												
	cout << "�������������\n\n";
	cin >> answer;
	return;
}

// ���Ҳ�ѯ����
void sellerOperate::inquireOrder() {
	cout << endl;
	
	char choice;

	string name, dish, num, address, phone;
	int y, m, d, h;
	string sign;
	
	bool end = false;
	while (1) {
		
		cout << " �𾴵��̼ң������ڽ��в�ѯ����ҵ�������붩����ѯ��Χ:\n"
			 << " 1: ȫ������\t" << "2: �ѱ��Ͷ���\t" << "3: ��ȡ������\t" << "4: �����û�����ѯ\t" << "Q: �˳�\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << "��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
					"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
				}
				fdat.close();
				break;
			}
			case '2': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " ��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( sign == "�ѱ���" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '3': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " ��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( sign == "��ȡ��" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '4':{
				cout << " �������û�����\n ";
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
					cout << "��Ǹ�����û��������ڣ��밴���������\n";
					cin >> userCmp;
				} else buyOp().inquireOrder();
				
				break;
			}
			case 'q':
			case 'Q':	{
				end = true;
				break;
			}
			default:	cout << " ����������������롣\n";
		}
		cout << endl;
		if (end)	break;
	} 
	
} 

// �����޸Ĳ˵�
void sellerOperate::modifyOrder( unordered_map<string, Dish> & menu ) {
	cout << endl;
	
	// ���ƿ��޸ĵĶ��������� 
	ifstream instuf("order.txt", ios::in);
	ofstream outstuf("order_copy.txt", ios::out);
	char ch;
	if ( !instuf || !outstuf ) {
		cout << " �����ļ������ڣ���������˳���\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	string name, dish, address, phone, sign;
	int y, m, d, h, num, cnt = 1;
	vector< pair<int, Order> > v;
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		
		if ( sign == "���ύ" ) {
			cout << cnt << "\t" << name << "\t" << dish << "\t" << num << "\t" << sign << "\t" 
				 << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
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
		cout << " \n�𾴵��̼ң��������޸Ķ��������¶��������޸ģ�\n\n";
		cout << " ��  ��" << "\t��  ��" << "\t��   ʽ " << "\t�� ��" << "\t״ ̬" << "\t�� ַ" << "\tʱ     ��" << "\t��    ��\n"; 
		for ( auto & p : v ) {
			if ( p.second.getModify() == 0 )	continue;
			cout << p.first << "\t";
			cout << p.second.getCustomerName() << "\t"; 
			cout << p.second.getDishName() << "\t"; 
			cout << p.second.getNum() << "\t";
			cout << "���ύ" <<"\t";
			cout << p.second.getAddress() << "\t";
			cout << p.second.getBookDate().getYear() << "��";
			cout << p.second.getBookDate().getMonth() << "��"; 
			cout << p.second.getBookDate().getDay() << "��";
			cout << p.second.getBookDate().getHour() << "ʱ" << "\t";
			cout << p.second.getPhone() << endl; 
		}
		cout << "\n ��������޸Ķ������(����-1�˳��޸Ķ���):\n ";
		cin >> n;
		if ( n == -1 )	break;
		else if ( n < 1 || n > v.size() ) {
			cout << " ��Ŵ���\n";
			continue;
		} else if ( v[n-1].second.getModify() == 0 ) {
			cout << "�ö��������޸ģ�\n";
			continue;
		} 
		
		while (1) {
			cout << " �𾴵��̼ң����Ƿ�ȷ��Ϊ����ͣ�(Y/N) \n\n ";
			cin >> ch;
			if ( ch == 'y' || ch == 'Y' ) {
				v[n-1].second.setModify();
				cout << " ����" << n << "�޸���ɣ�\n\n";
				cout << "\n�޸ĺ󶩵����£�\n";
				cout << " ��  ��" << "\t��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				cout << v[n-1].first << "\t";
				cout << v[n-1].second.getCustomerName() << "\t"; 
				cout << v[n-1].second.getDishName() << "\t"; 
				cout << v[n-1].second.getNum() << "\t";
				if ( v[n-1].second.getModify() == 1 ) cout << "���ύ" <<"\t";
				else	cout << "�ѱ���" << "\t"; 
				cout << v[n-1].second.getAddress() << "\t";
				cout << v[n-1].second.getBookDate().getYear() << "��";
				cout << v[n-1].second.getBookDate().getMonth() << "��"; 
				cout << v[n-1].second.getBookDate().getDay() << "��";
				cout << v[n-1].second.getBookDate().getHour() << "ʱ" << "\t";
				cout << v[n-1].second.getPhone() << endl;   
				break;
			} else if ( ch == 'N' || ch == 'n' ) break;
			else cout << " ����������������룡\n\n";	
		}
		 
		cout << " \n�Ƿ�����޸Ķ�����(NΪ��) \n ";
		cin >> ch;
		if ( ch == 'n' || ch == 'N' )	con = false;
	}
	
	// �ѹ�ϣ�������Ƶ�������
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	for (auto & p : v) {
		outstuf << p.second.getCustomerName() << ' ' << p.second.getDishName() << ' ' << p.second.getNum() << ' ';
		if ( p.second.getModify() == 1 ) {
			outstuf << "���ύ ";
		} else outstuf << "�ѱ��� ";
		outstuf << p.second.getAddress() << ' ' << p.second.getBookDate().getYear() << ' '<< p.second.getBookDate().getMonth()
				<< ' ' << p.second.getBookDate().getDay() << ' ' << p.second.getBookDate().getHour() << ' ' << phone << '\n';
	} 
	outstuf.close();
	
	// �Ѷ����ļ����ݻ��ɸ�������
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	instuf.open( "order_copy.txt", ios::in );
	outstuf.open("order.txt", ios::out );
	if ( !instuf || !outstuf ) {
		cout << " �����ļ������ڣ���������˳���\n";
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
	
	cout << "\n�𾴵��̼ң������޸���ɣ��밴�����������\n";
	cin >> ch;
	return; 
} 

// �����Ӷ���
void buyerOperate::appendOrder( unordered_map<string, Dish> & menu ) {
	cout << endl;
	
	string choice;
	ofstream fdat("order.txt", ios::app );
	
	if ( !fdat ) {
		cout << " �����ļ������ڣ���������˳���\n";
		cin >> choice;
		return; 
	}
		
	string address, phone;
	int num, y, m, d, h;
	Order od; 
	vector< pair<string, int> > v;								// ��ʽ������ 
	
	cout << " �𾴵� " << buyerName <<" �û�����������Ӷ��������������ĵ�ַ�͵绰��\n ��ַ? ";
	cin >> address;
	cout << " �绰? ";
	cin >> phone;
	cout << "\n �������ʹ�ʱ��(��/��/��/ʱ)��\n";
	cin >> y >> m >> d >> h; 
	Date book(y, m, d, h);
	
	cout << " \n �����ڵ�ͣ��������²�����ѡ���������ϣ��밴 Q / q ���˳���\n\n";
	
	printAllDishes(menu);
	
	cout << endl;
	
	while ( 1 ) {
		cin >> choice;
		if ( choice == "Q" || choice == "q" ) {
			break;
		}
		else if ( !menu.count(choice) ) {
			cout << " ��Ǹ���ò�ʽ�����ڣ������µ�ͣ�\n\n";
			continue; 
		}
		cout << " ������������\n? ";
		cin >> num;
		
		Order od( menu[choice].getDishID(), choice, menu[choice].getPrice(), buyerName, address, phone );
		od.setBookDate( book );
		
		// ������������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰д�붩���ļ� 
		if( od.setNum(num) ) {
			cout << " �����������һ����ʽ���������ϣ��밴 Q / q ���˳�.\n\n"; 
			string c = "���ύ";
			if ( od.getModify() == 0 ) {
				c = "�ѱ���";
			}
			fdat << buyerName << ' ' << choice << ' ' << num << ' ' << c << ' ' << address
				 << "    " << y << ' ' << m << ' ' << d << ' ' << h << "    " << phone << '\n';
			v.push_back( make_pair(choice, num) );
		} else {
			cout << " ���ʧ�ܣ������µ�͡�\n\n";
		}
	}
	
	cout << " �����ϣ�\n\n";
	
	cout << " �𾴵� " << buyerName << "�����ղŵ�Ĳ�ʽ�У�\n\n";
	for (auto & i : v) {
		cout << "   " << i.first << "  " << i.second << "�ݡ�\n";
	}
	cout << " \n ��ʾ���!\n"; 
	
	fdat.close(); 
	
	cout << "\n ���ε����ɣ��밴�����������\n";
	cin >> choice;
	return;
} 

// ��Ҳ�ѯ����
void buyerOperate::inquireOrder() {
	cout << endl;
	
	char choice;

	string name, dish, num, address, phone;
	int y, m, d, h;
	string sign;
	
	bool end = false;
	while (1) {
		
		cout << " �����붩����ѯ��Χ:\n"
			 << " 1: ȫ������\t" << "2: �̼��Ѵ�����\t" << "3: ��ȡ������\t" << "Q: �˳�\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << "��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					if ( name == buyerName ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '2': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " ��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( name == buyerName && sign == "�ѱ���" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
					}
				}
				fdat.close();
				break;
			}
			case '3': {
				char ch;
				ifstream fdat( "order.txt", ios::in );
				if ( !fdat ) {
					cout << " �����ļ������ڣ���������˳���\n";
					cin >> ch;
					return; 
				}
				fdat.seekg( 0, ios::beg );
				cout << " ��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
				while ( fdat >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
					
					if ( name == buyerName && sign == "��ȡ��" ) {
						cout << name << "\t" << dish << "\t" << num << "\t" << sign <<
						"\t" << address << "\t" << y << "��" << m << "��" << d << "��" << h << "ʱ" << "\t" << phone << endl;
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
			default:	cout << " ����������������롣\n";
		}
		cout << endl;
		if (end)	break;
	} 
	
} 

// ����޸�ȡ������ 
void buyerOperate::modifyOrder(unordered_map<string, Dish> & menu) {
	cout << endl;
	
	// ����ճ�������˿͵Ķ��������������Ʊ��˿͵Ķ��������� 
	ifstream instuf("order.txt", ios::in);
	ofstream outstuf("order_copy.txt", ios::out);
	char ch;
	if ( !instuf || !outstuf ) {
		cout << " �����ļ������ڣ���������˳���\n";
		cin >> ch;
		return; 
	}
	instuf.seekg( 0, ios::beg );
	outstuf.seekp( 0, ios::beg );
	
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	string name, dish, address, phone, sign;
	int y, m, d, h, num, cnt = 1;
	vector< pair<int, Order> > v;
	
	while ( instuf >> name >> dish >> num >> sign >> address >> y >> m >> d >> h >> phone ) {
		
		if ( name == buyerName && sign == "���ύ" ) {
			
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
		// ��ӡ���޸ĵĶ���
		cout << " �𾴵� " << buyerName <<" �û����������޸Ķ������������¿��޸Ķ������������Ӧ���? \n\n";
		cout << " ��  ��" << "\t��  ��" << "\t��   ʽ " << "\t�� ��" << "\t״ ̬" << "\t�� ַ" << "\tʱ     ��" << "\t��    ��\n"; 
		for ( auto & p : v ) {
			if ( p.second.getModify() == 0 )	continue;
			cout << p.first << "\t";
			cout << p.second.getCustomerName() << "\t"; 
			cout << p.second.getDishName() << "\t"; 
			cout << p.second.getNum() << "\t";
			cout << "���ύ" <<"\t";
			cout << p.second.getAddress() << "\t";
			cout << p.second.getBookDate().getYear() << "��";
			cout << p.second.getBookDate().getMonth() << "��"; 
			cout << p.second.getBookDate().getDay() << "��";
			cout << p.second.getBookDate().getHour() << "ʱ" << "\t";
			cout << p.second.getPhone() << endl; 
		}
		cout << "\n �����Ӧ��ţ�(����-1�˳��޸�)\n";
		int n, end = 0;
		cin >> n;
		if ( n == -1 )	break;
		while ( n < 1 || n > v.size() ) {
			cout << " ���������������������.\n\n";
			continue;
		}
		cout << "\n�޸�ǰ�������£�\n";
		cout << " ��  ��" << "\t��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
		cout << v[n-1].first << "\t";
		cout << v[n-1].second.getCustomerName() << "\t"; 
		cout << v[n-1].second.getDishName() << "\t"; 
		cout << v[n-1].second.getNum() << "\t";
		cout << "���ύ" <<"\t";
		cout << v[n-1].second.getAddress() << "\t";
		cout << v[n-1].second.getBookDate().getYear() << "��";
		cout << v[n-1].second.getBookDate().getMonth() << "��"; 
		cout << v[n-1].second.getBookDate().getDay() << "��";
		cout << v[n-1].second.getBookDate().getHour() << "ʱ" << "\t";
		cout << v[n-1].second.getPhone() << endl; 
		
		cout << " \n�����Խ��������޸ģ����������ѡ��:\n"
			 << " 1: �޸Ĳ�ʽ����\t" << "2: �޸��ʹ�ʱ��\t" << "3: �޸��ʹ��ַ\t" << "4��ȡ������\t" << "Q: �˳�\n";

		cin >> ch;
		switch(ch) {
			
			case '1': {
				cout << "\n �������޸Ĳ�ʽ�������������µĲ�ʽ������\n ";
				int num;
				cin >> num;
				if ( num < 1 ) {
					cout << " ��������\n";
				} else {
					v[n-1].second.setNum(num);
					cout << "�޸���ɣ�\n";
				}
				break;
			}
			case '2': {
				cout << "\n �������޸��ʹ�ʱ�䣬�������µ��ʹ�ʱ��(��/��/��/ʱ)��\n";
				cout << " �꣺\n "; 
				cin >> y;
				cout << " �£�\n "; 
				cin >> m;
				cout << " �գ�\n "; 
				cin >> d;
				cout << " Сʱ��\n "; 
				cin >> h;
				Date bookDate(y, m, d, h);
				v[n-1].second.setBookDate( bookDate );
				cout << "�޸���ɣ�\n";
				break;
			}
			case '3': {
				cout << "\n �������޸��ʹ��ַ���������µ��ʹ��ַ��\n ";
				cin >> address;
				v[n-1].second.setAddress( address );
				cout << "�޸���ɣ�\n";
				break;
			}
			case '4': {
				v[n-1].second.setModify();
				cout << "������ȡ����\n";
				break;
			}
			case 'q':
			case 'Q': {
				end = 1; 
				break;
			}
			default: {
				cout << "�����������������룡\n\n";
				break;
			}
		}
		
		cout << "\n�޸ĺ󶩵����£�\n";
		cout << " ��  ��" << "\t��  ��" << "\t��   ʽ " << "\t����" << "\t״̬" << "\t��ַ" << "\tʱ     ��" << "\t��    ��\n"; 
		cout << v[n-1].first << "\t";
		cout << v[n-1].second.getCustomerName() << "\t"; 
		cout << v[n-1].second.getDishName() << "\t"; 
		cout << v[n-1].second.getNum() << "\t";
		if ( v[n-1].second.getModify() == 1 ) cout << "���ύ" <<"\t";
		else	cout << "��ȡ��" << "\t"; 
		cout << v[n-1].second.getAddress() << "\t";
		cout << v[n-1].second.getBookDate().getYear() << "��";
		cout << v[n-1].second.getBookDate().getMonth() << "��"; 
		cout << v[n-1].second.getBookDate().getDay() << "��";
		cout << v[n-1].second.getBookDate().getHour() << "ʱ" << "\t";
		cout << v[n-1].second.getPhone() << endl;  
		
		cout << "\n�밴�����������\n";
		cin >> ch;
		if ( end )	break;
	}
	
	// �Ѹ��û��Ķ���ȫ������������ļ���
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	for (auto & p : v) {
		outstuf << p.second.getCustomerName() << ' ' << p.second.getDishName() << ' ' << p.second.getNum() << ' ';
		if ( p.second.getModify() == 0 ) {
			outstuf << "��ȡ�� ";
		} else outstuf << "���ύ ";
		outstuf << p.second.getAddress() << ' ' << p.second.getBookDate().getYear() << ' '<< p.second.getBookDate().getMonth()
				<< ' ' << p.second.getBookDate().getDay() << ' ' << p.second.getBookDate().getHour() << ' ' << phone << '\n';
	} 
	outstuf.close();
	
	// �Ѷ����ļ����ݻ��ɸ�������
	// ��������ʽ������������״̬����ַ���ꡢ�¡��ա�Сʱ���绰
	instuf.open( "order_copy.txt", ios::in );
	outstuf.open("order.txt", ios::out );
	if ( !instuf || !outstuf ) {
		cout << " �����ļ������ڣ���������˳���\n";
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
	
	cout << "�����˳��޸Ķ������밴�����������\n";
	cin >> ch;
	return;
} 

