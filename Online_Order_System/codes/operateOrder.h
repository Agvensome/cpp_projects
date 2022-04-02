// operateOrder.h

// 买卖家类似操作订单类 
class similarOperate {
	public:
		virtual void inquireOrder() = 0;
		virtual void modifyOrder(unordered_map<string, Dish> & menu) = 0;
};

// 卖家操作订单类
class sellerOperate : public similarOperate {
	public:
		void initializeOrder();											// 初始化订单文件 
		void inquireOrder();											// 查询订单 
		void modifyOrder(unordered_map<string, Dish> & menu);			// 修改订单 
};

// 买家操作订单类
class buyerOperate : public similarOperate {
	public:
		void appendOrder(unordered_map<string, Dish> & menu);			// 添加订单 
		void inquireOrder();											// 查询订单 
		void modifyOrder(unordered_map<string, Dish> & menu);			// 修改取消订单 
};

// 函数调用返回一个静态卖家操作订单类 
sellerOperate & sellOp();

// 函数调用返回一个静态买家操作订单类 
buyerOperate & buyOp();

