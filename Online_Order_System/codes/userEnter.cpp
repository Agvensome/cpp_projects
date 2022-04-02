// userEnter.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// ����Ա��¼
bool sellerRegister() {
	cout << endl;
	
	string code, cmp;
	ifstream instuf( "code.txt", ios::in );				// �������ļ� 
	instuf.seekg( 0, ios::beg );
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	
	instuf >> code;										// ��ȷ���� 
	instuf.close();										// �ر������ļ� 
	
	int cnt = 5;										// ��������� 
	char q;												// ��������� 
	
	cout << " �����ڵ�¼����Ա�����������룺\n\n";
	cin >> cmp;
	while ( cmp != code && cnt > 0 ) {
		--cnt;
		cout << " ������������������" << cnt << "�����롣\n";
		cout << " ���ٴ��������룺\n\n"; 
		cin >> cmp;
	}
	
	if ( cmp != code )	{
		cout << "\n �����������������������꣬�밴������˳���\n";
		cin >> q;
		return false;
	}
	cout << "\n\n ����Ա��¼�ɹ����밴���������\n";
	cin >> q;
	return true;
}

// ����Ա��������
bool sellerSetCode() {
	cout << endl;
	
	string code, cmp;
	ifstream instuf( "code.txt", ios::in );				// �������ļ� 
	instuf.seekg( 0, ios::beg );
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	
	instuf >> code;										// �������� 
	instuf.close();										// �ر������ļ� 
	
	int cnt = 5;
	char q;
	
	cout << " ����Ա���ã������ڸ������룬����������룺\n\n";
	cin >> cmp;
	while ( cmp != code && cnt > 0 ) {
		--cnt;
		cout << " ������������������" << cnt << "�ξ����롣\n";
		cout << " ���ٴ���������룺\n\n"; 
		cin >> cmp;
	}
	
	if ( cmp != code )	{
		cout << "\n �����������������������꣬�밴������˳���\n";
		cin >> q;
		return false;
	}
	
	cout << " ��������ȷ�������������룺\n\n";
	cin >> code;
	cout << " ���ٴ����������룺\n\n";
	cin >> cmp;
	if ( cmp != code ) {
		cout << " ��������밴������˳���\n";
		cin >> q;
		return false;
	}
	
	ofstream outstuf( "code.txt", ios::out );
	if ( !outstuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	outstuf.seekp( 0, ios::beg );
	outstuf << code;									// д�������� 
	outstuf.close();
	
	cout << " \n���������óɹ����밴������˳���\n";
	cin >> q;
	return true;
} 

// ���û�����ң�ע��
void buyerSignIn() {
	cout << endl;
	
	// �����û��� 
	char q;
	string user, code, userCmp, codeCmp;
	cout << "������ע�����û��������������û���:\n";
	cin >> user;
	
	ifstream instuf( "buyer.txt", ios::in );
	instuf.seekg( 0, ios::beg) ;
	while ( instuf >> userCmp >> code ) {
		if ( user == userCmp ) {
			instuf.close();
			cout << "���û����Ѵ��ڣ��밴���������.\n";
			cin >> q;
			return; 
		}
	}
	instuf.close();
	
	// �������� 
	cout << "���������룺\n";
	cin >> code;
	cout << "���ٴ���������\n";
	cin >> codeCmp;
	if ( code != codeCmp ) {
		cout <<"���벻��ȷ���밴�����������\n";
		cin >> q; 
		return; 
	}
	
	ofstream outstuf( "buyer.txt", ios::app );
	outstuf << user << ' ' << code << '\n';				// д�����û��������� 
	outstuf.close();
	
	cout << "���û�ע��ɹ����밴�����������\n";
	cin >> q;
	return;
} 

// ��ҵ�¼ 
bool buyerRegister(string & buyerName) {
	cout << endl;
	
	string user, code, userCmp, codeCmp;
	
	cout << "�𾴵��û��������ڵ�¼���������˺ţ�\n";
	cin >> user;
	cout << "����������\n";
	cin >> code;
	
	ifstream instuf("buyer.txt", ios::in);
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	instuf.seekg( 0, ios::beg ); 
	while ( instuf >> userCmp >> codeCmp ) {
		if ( user == userCmp && codeCmp == code )	break;
	}
	instuf.close();
	
	char q;
	if ( user != userCmp || code != codeCmp ) {
		cout << " �˺Ż���������밴������˳���\n";
		cin >> q;
		return false;
	}
	buyerName = user;
	cout << "��¼�ɹ����������������\n";
	cin >> q;
	return true;
}

