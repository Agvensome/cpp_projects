// userEnter.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// 管理员登录
bool sellerRegister() {
	cout << endl;
	
	string code, cmp;
	ifstream instuf( "code.txt", ios::in );				// 打开密码文件 
	instuf.seekg( 0, ios::beg );
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	
	instuf >> code;										// 正确密码 
	instuf.close();										// 关闭密码文件 
	
	int cnt = 5;										// 可输入次数 
	char q;												// 任意继续键 
	
	cout << " 您正在登录管理员，请输入密码：\n\n";
	cin >> cmp;
	while ( cmp != code && cnt > 0 ) {
		--cnt;
		cout << " 密码错误！您最多再输入" << cnt << "次密码。\n";
		cout << " 请再次输入密码：\n\n"; 
		cin >> cmp;
	}
	
	if ( cmp != code )	{
		cout << "\n 密码错误，您的输入机会已用完，请按任意键退出。\n";
		cin >> q;
		return false;
	}
	cout << "\n\n 管理员登录成功！请按任意键继续\n";
	cin >> q;
	return true;
}

// 管理员更换密码
bool sellerSetCode() {
	cout << endl;
	
	string code, cmp;
	ifstream instuf( "code.txt", ios::in );				// 打开密码文件 
	instuf.seekg( 0, ios::beg );
	
	if ( !instuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	
	instuf >> code;										// 读旧密码 
	instuf.close();										// 关闭密码文件 
	
	int cnt = 5;
	char q;
	
	cout << " 管理员您好，您正在更换密码，请输入旧密码：\n\n";
	cin >> cmp;
	while ( cmp != code && cnt > 0 ) {
		--cnt;
		cout << " 密码错误！您最多再输入" << cnt << "次旧密码。\n";
		cout << " 请再次输入旧密码：\n\n"; 
		cin >> cmp;
	}
	
	if ( cmp != code )	{
		cout << "\n 密码错误，您的输入机会已用完，请按任意键退出。\n";
		cin >> q;
		return false;
	}
	
	cout << " 旧密码正确！请输入新密码：\n\n";
	cin >> code;
	cout << " 请再次输入新密码：\n\n";
	cin >> cmp;
	if ( cmp != code ) {
		cout << " 密码错误，请按任意键退出。\n";
		cin >> q;
		return false;
	}
	
	ofstream outstuf( "code.txt", ios::out );
	if ( !outstuf ) {
		cerr << "File could not be open.\n";
		abort();
	} 
	outstuf.seekp( 0, ios::beg );
	outstuf << code;									// 写入新密码 
	outstuf.close();
	
	cout << " \n新密码设置成功！请按任意键退出！\n";
	cin >> q;
	return true;
} 

// 新用户（买家）注册
void buyerSignIn() {
	cout << endl;
	
	// 设置用户名 
	char q;
	string user, code, userCmp, codeCmp;
	cout << "您正在注册新用户，请输入您的用户名:\n";
	cin >> user;
	
	ifstream instuf( "buyer.txt", ios::in );
	instuf.seekg( 0, ios::beg) ;
	while ( instuf >> userCmp >> code ) {
		if ( user == userCmp ) {
			instuf.close();
			cout << "该用户名已存在！请按任意键返回.\n";
			cin >> q;
			return; 
		}
	}
	instuf.close();
	
	// 设置密码 
	cout << "请输入密码：\n";
	cin >> code;
	cout << "请再次输入密码\n";
	cin >> codeCmp;
	if ( code != codeCmp ) {
		cout <<"密码不正确！请按任意键继续。\n";
		cin >> q; 
		return; 
	}
	
	ofstream outstuf( "buyer.txt", ios::app );
	outstuf << user << ' ' << code << '\n';				// 写入新用户和新密码 
	outstuf.close();
	
	cout << "新用户注册成功！请按任意键继续。\n";
	cin >> q;
	return;
} 

// 买家登录 
bool buyerRegister(string & buyerName) {
	cout << endl;
	
	string user, code, userCmp, codeCmp;
	
	cout << "尊敬的用户，您正在登录，请输入账号：\n";
	cin >> user;
	cout << "请输入密码\n";
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
		cout << " 账号或密码错误！请按任意键退出。\n";
		cin >> q;
		return false;
	}
	buyerName = user;
	cout << "登录成功！按任意键继续。\n";
	cin >> q;
	return true;
}

