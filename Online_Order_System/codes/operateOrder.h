// operateOrder.h

// ���������Ʋ��������� 
class similarOperate {
	public:
		virtual void inquireOrder() = 0;
		virtual void modifyOrder(unordered_map<string, Dish> & menu) = 0;
};

// ���Ҳ���������
class sellerOperate : public similarOperate {
	public:
		void initializeOrder();											// ��ʼ�������ļ� 
		void inquireOrder();											// ��ѯ���� 
		void modifyOrder(unordered_map<string, Dish> & menu);			// �޸Ķ��� 
};

// ��Ҳ���������
class buyerOperate : public similarOperate {
	public:
		void appendOrder(unordered_map<string, Dish> & menu);			// ��Ӷ��� 
		void inquireOrder();											// ��ѯ���� 
		void modifyOrder(unordered_map<string, Dish> & menu);			// �޸�ȡ������ 
};

// �������÷���һ����̬���Ҳ��������� 
sellerOperate & sellOp();

// �������÷���һ����̬��Ҳ��������� 
buyerOperate & buyOp();

