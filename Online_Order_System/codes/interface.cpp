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

extern string buyerName;	// ȫ�ֱ�������˺ţ�������

// ���û�����ң�ע�� 
void buyerSignIn();
// ��ҵ�¼ 
bool buyerRegister( string & buyerName );

// ����Ա��¼ 
bool sellerRegister();
// ����Ա��������
bool sellerSetCode();

// �ӱ����ļ�������������в�ʽ 
void inputAllDishes( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );
// �����в�ʽ����д�뱾�ز����ļ�
void outputAllDishes( unordered_map<string, Dish> & menu ); 
// ��ӡ���������в�ʽ 	
void printAllDishes( unordered_map<string, Dish> & menu );	
// ��������ѯ��һ��ʽ 
bool inquireOneDish( unordered_map<string, Dish> & menu );	
// ����������²�ʽ 
void appendOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );
// ɾ�������е�ָ����ʽ
void deleteOneDish( unordered_map<string, Dish> & menu, unordered_set<string> & possessID );

// ��Ҵ��� 
void buyerInterface( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	while (1) {
		system("cls");
		cout << endl;
		cout << "  �𾴵������ߣ���ѡ��������ݣ�\n\n";
		cout << "  ======  ( 1 )  �û�  ======  ( 2 ) ���û�  ======  ( 0 ) �˳�  ======  \n\n\t"; 
		char ch;
		cin >> ch;
		while ( ch < '0' || ch > '2' ) {
			cout << "��Ų��Ϸ������������룺\t";
			cin >> ch;
		}
		system("cls");
		
		cout << endl;
		
		if ( ch == '0' ) {
			cout << "  ���˳�������ѡ���밴�����������\n";
			cin >> ch;
			return;
		}
		
		else if ( ch == '1' ) {
			cout << "  ��ѡ���û������¼\n\n\t";
			bool sign = buyerRegister( buyerName );
			if ( !sign ) continue;
			while (1) {
				system("cls");
				cout << "  ���ѵ�¼�������Խ������²�����\n\n\t"; 
				cout << "  ======  ( 1 )  ���  ======  ( 2 )  ��ѯ����  ======  ( 3 )  �޸�/ȡ������  ======  ( 0 ) �˳�  ======\n\n\t";
				cout << "  �𾴵��û����������ţ�\n\t";
				
				cin >> ch;
				
				while ( ch < '0' || ch > '3' ) {
					cout << "��Ų��Ϸ������������룺\t";
					cin >> ch;
				}
				system("cls");
				
				if ( ch == '0' ) {
					cout << "  �����˳���¼���밴�����������\n";
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
			cout << "  ��ѡ�����û��������Խ������²�����\n\n\t"; 
			cout << "  ======  ( 1 )  ע���û�  ======  ( 0 ) �˳�  ======  \n\n\t";
			cout << "  �𾴵����û����������ţ�\n\t";
			cin >> ch;
			
			if ( ch != '1' && ch != '0' ) {
				cout << "���벻�Ϸ����밴������˳���\n";
				cin >> ch;
				continue;
			}
			
			else if ( ch == '0' ) {
				cout << "�˳����û�����ɹ����밴������˳���\n";
				cin >> ch;
				continue;
			}
			
			else if ( ch == '1' ) {
				buyerSignIn();
			}
		}
	}
}

// ���Ҵ��� 
void sellerInterface( unordered_map<string, Dish> & menu, unordered_set<string> & possessID ) {
	
	system("cls");
	cout << endl;
	cout << "  �𾴵��̼ҹ���Ա�����¼��\n\n"; 
	
	bool sign = sellerRegister();
	if ( !sign )	return;
	
	while (1) {
		
		system("cls");
		cout << endl;
		
		cout << "  �𾴵��̼ҹ���Ա�������Բ���������Ŀ��\n\n";
		cout << "  ======  ( 1 ) ��  ��  ======  ( 2 ) ��  ��  ======  ( 3 ) ��������  ======  ( 0 ) ��  ��  ======\n\n";
		cout << "  �������Ӧ���:\t";
		
		char ch;
		cin >> ch;	
		
		while ( ch < '0' && ch > '3' ) {
			cout << "��Ų��Ϸ������������롣\n";
			cin >> ch;
		}
		
		if ( ch == '0' ) {
			cout << "  �˳��ɹ����밴�����������\n";
			cin >> ch;
			return;
		}
		
		system("cls");
		cout << endl;
		
		if ( ch == '1' ) {
			cout << "  �𾴵��̼ҹ���Ա�������ԶԶ����������²�����\n\n";
			cout << "  ======  ( 1 ) ��ʼ������  ======  ( 2 ) ��ѯ����  ======  ( 3 ) ���͵Ǽ�  ======  ( 0 ) ��  ��  ======\n\n";
			
			cout << "  �������Ӧ���:\t";
			cin >> ch;

			while ( ch < '0' && ch > '3' ) {
				cout << "��Ų��Ϸ������������롣\n";
				cin >> ch;
			}
			
			if ( ch == '0' ) {
				cout << "  �˳��ɹ����밴�����������\n";
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
			cout << "  �𾴵��̼ҹ���Ա�������ԶԲ˵��������²�����\n\n";
			cout << "  ======  ( 1 ) ��Ӳ�ʽ  ======  ( 2 ) ��ѯ�˵�  ======  ( 3 ) ɾ����ʽ  ======  ( 0 ) ��  ��  ======\n\n";
			
			cout << "  �������Ӧ���:\t";
			cin >> ch;

			while ( ch < '0' && ch > '3' ) {
				cout << "��Ų��Ϸ������������롣( 1 ) ��Ӳ�ʽ��( 2 ) ��ѯ�˵���( 3 ) ɾ����ʽ��( 0 ) ��  ��\n\t";
				cin >> ch;
			}
			
			if ( ch == '0' ) {
				cout << "  �˳��ɹ����밴�����������\n";
				cin >> ch;
				continue;
			}	
		
			system("cls");
			cout << endl; 
			
			switch( ch ) {
				case '1': {
					while (1) {
						appendOneDish(menu, possessID);
						cout << "��ȫ�������ɣ��밴 Q / q �˳�\n";
						cin >> ch;
						if ( ch == 'Q' || ch == 'q' ) {
							system("cls");
							break;
						}
					}
					break;
				}
				case '2': {
					cout << "��ѡ�����²�ѯ������\n\n\t";
					cout << "  ======  ( 1 ) ������ѯ��ʽ  ======  ( 2 ) ��ѯȫ����ʽ  ======\n\n";
					cout << "�������Ӧ���\n\t";
					cin >> ch;
					while ( ch != '1' && ch != '2' ) {
						cout << "��Ų��Ϸ������������롣( 1 ) ������ѯ��ʽ��( 2 ) ��ѯȫ����ʽ\n\t";
						cin >> ch;
					}
			
					system("cls");
					cout << endl;
					
					if ( ch == '1' )	inquireOneDish( menu );
					else if ( ch == '2' )	printAllDishes( menu );
					
					cout << "\n�밴�����������\n\n";
					cin >> ch;					
					break;
				}
				case '3': {
					while (1) {
						deleteOneDish( menu, possessID );
						cout << "��ȫ��ɾ����ɣ��밴 Q / q �˳�\n";
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

// �����溯�� 
void mainInterface() {
	
	unordered_map<string, Dish> menu;		// �˵� 
	unordered_set<string> possessID;		// ������ 
	inputAllDishes( menu, possessID ); 
	
	while (1) {
		system("cls");
		cout << endl;
		cout << "  ======  ======  ��ӭʹ�����϶���ϵͳ  ======  ======  \n\n";
		cout << "  ======  ======     ��ѡ���������     ======  ======  \n\n";
		cout << "          ----    ( 1 ) ��    ��    ----          \n\n";
		cout << "          ----    ( 2 ) �� �� Ա    ----          \n\n";
		cout << "          ----    ( 0 ) ��    ��    ----          \n\n";
		cout << "  ======  ======     �������Ӧ���     ======  ======  \n\n\n";
		
		// ������ 
		cout << "  ��ţ�\t";
		int num;
		cin >> num;
		system("cls");
		
		// ��ѡ����ݣ�������һ������ 
		while ( num != 1 && num != 2 && num != 0 ) {
			cout << "\n  ��Ų��Ϸ��������ԣ�\n  �������Ӧ��ţ�( 1 ) ��ҡ�( 2 ) ����Ա��\n\n\t";
			cin >> num;
		}
		
		// �˳�ϵͳ 
		if ( !num ) {
			cout << "\n  ϵͳ���˳�����л����ʹ�á�\n";
			outputAllDishes( menu );	// �����в�ʽ����д�뱾�ز�����
			return;
		} 
		
		system("cls");
		
		char ch = '0' + num;
		switch ( ch ) {
			case '1': {
				cout << "\n  ѡ����ҳɹ����밴������������\n\n";
				cin >> ch;
				buyerInterface( menu, possessID );
				break;
			}
			case '2': {
				cout << "\n  ѡ�����Ա�ɹ����밴������������\n\n";
				cin >> ch;
				sellerInterface( menu, possessID );
				break;
			}
		} 
	}
}

