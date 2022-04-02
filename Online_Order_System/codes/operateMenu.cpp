// operateMenu.h
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include"newClass.h"
using namespace std;


// �ӱ����ļ�������������в�ʽ 
void inputAllDishes( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	double price;
	string dishID, dishName;	
	ifstream instuf( "menu.txt", ios::in );				// ���ļ� 
	instuf.seekg( 0, ios::beg );						// ��ָ�������ļ�ͷ 
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 

	while ( instuf >> dishID >> dishName >> price ) {	// ��ȡ
		Dish d( dishID, dishName, price );
		menu[dishName] = d;
		possessID.insert( dishID );
	}
	instuf.close();										// �ر��ļ� 
}

// �����в�ʽ����д�뱾�ز����ļ�
void outputAllDishes( unordered_map<string, Dish> & menu ) {
	double price;
	string dishID, dishName;	
	ofstream outstuf( "menu.txt", ios::out );				// ���ļ� 
	outstuf.seekp( 0, ios::beg );							// ��ָ�������ļ�ͷ 
	for ( const pair<string, Dish> & p : menu ) {			// д 
		dishID = p.second.getDishID();
		dishName =  p.second.getDishName();
		price = p.second.getPrice();
		outstuf << dishID << ' ' << dishName << ' ' << price << '\n'; 
	}
	outstuf.close();										// �ر��ļ� 
}

// ��ӡ���������в�ʽ 
void printAllDishes( unordered_map<string, Dish> & menu ) {
	cout << "----------------  ����  ----------------" << endl << endl;
	cout << " ���" << setw(20) << "����" << setw(14) << "�۸�" << endl << endl;
	for ( const pair<string, Dish> & p : menu ) {
		cout << " " << p.second.getDishID();
		cout << setw(20) << p.second.getDishName();
		cout << setw(14) << p.second.getPrice() << endl << endl;
	}
	cout << endl << "----------- ȫ����ʽ��ʾ��� -----------" << endl;
}

// ��������ѯ��һ��ʽ
bool inquireOneDish(  unordered_map<string, Dish> & menu ) {
	string dish;
	cout << " �����ڽ��в�ѯ��ʽ�������������ҵĲ�����\n? ";
	cin >> dish;
	if ( !menu.count(dish) ) {
		cout << " ��Ǹ���������Ĳ�ʽ�����ڣ�\n";
		return false;
	}
	
	cout << "��ѯ�ɹ���\n\n";
	cout << " ���" << setw(9) << "����" << setw(14) << "�۸�" << endl; 
	cout << " " << menu[dish].getDishID() << "    " << dish << "      \t" << menu[dish].getPrice() << endl;
	return true;
} 

// ����������²�ʽ 
void appendOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	string name, id;
	double price;
	char q;
	
	cout << "�����ڽ�����Ӳ�ʽ�������������ţ�\n? ";
	cin >> id;
	if ( possessID.find(id) != possessID.end() ) {
		cout << " �ñ���Ѿ����ڣ��밴������˳���\n";
		cin >> q;
		return;
	}
	
	cout << " �����������\n? ";
	cin >> name;
	if ( menu.count(name) ) {
		cout << " �ò����Ѿ����ڣ��밴������˳���\n";
		cin >> q;
		return;
	}
	
	cout << " �����뵥�ۣ�\n? ";
	cin >> price;
	
	Dish d(id, name, price);
	menu[name] = d;
	possessID.insert(id);
	
	cout << " ������²�ʽ���£�\n\n";
	cout << " ���" << setw(9) << "����" << setw(14) << "�۸�" << endl; 
	cout << " " << menu[name].getDishID() << "    " << name << "      \t" << menu[name].getPrice() << endl << endl;
	cout << " ��Ӳ�ʽ�ɹ����밴�����������\n";
	cin >> q;
	return;
}

// ɾ�������е�ָ����ʽ
void deleteOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	string name, id;
	char q;
	
	cout << "�����ڽ���ɾ����ʽ�������������Ӧ��ţ�\n? ";
	cin >> id;
	if ( possessID.find(id) == possessID.end() ) {
		cout << " �ñ�Ų����ڣ��밴������˳���\n";
		cin >> q;
		return;
	}
	
	cout << " �������Ӧ������\n? ";
	cin >> name;
	if ( !menu.count(name) ) {
		cout << " �ò��������ڣ��밴������˳���\n";
		cin >> q;
		return;
	}
	
	if ( menu[name].getDishID() != id ) {
		cout << "��������������ɾ��ʧ�ܣ��밴������˳���\n";
		cin >> q;
		return;
	}
	
	cout << " ɾ����ʽ���£�\n\n";
	cout << " ���" << setw(9) << "����" << setw(14) << "�۸�" << endl; 
	cout << " " << menu[name].getDishID() << "    " << name << "      \t" << menu[name].getPrice() << endl << endl;
	
	menu.erase( name );
	possessID.erase( possessID.find(id) );
	cout << "ɾ���ɹ����밴�����������\n";
	cin >> q;
	return;
} 
