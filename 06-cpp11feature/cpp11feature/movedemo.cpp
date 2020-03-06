#include "movedemo.h"
#include <utility>

//如果一个类没有默认构造函数，则系统会自动生成一个默认的构造函数
//如果一个类实现了参数构造函数，则系统不会自动生成默认无参构造函数，需要手动实现
//如果一个类没有实现copy构造函数，则系统会提供一个默认的copy构造函数
//如果一个类没有实现move构造函数，则系统会提供一个默认的move构造函数
//当我们实现了copy构造函数，则系统不会提供默认的move构造函数。同样
//如果我们实现了move构造函数，则系统不会提供默认的copy构造函数
//如果没有实现copy赋值运算符，则系统会提供默认的copy赋值运算符
//如果没有实现move赋值运算符，则系统会会提供默认的move赋值运算符。
//如果实现了copy赋值运算符，则系统不会提供默认的move赋值运算符。反之，亦然。
void use_move() {
	Home home_hyd("Hyd", 326);
	//copy 构造函数
	Home hyd_copy(home_hyd);
	//move 构造函数
	Home  hyd_move (move(hyd_copy));
	Home  home_default;
	//copy 赋值
	home_default = home_hyd;
	//如果写成如下，则直接调用copy构造
	Home copy_con = home_hyd;
	//move 赋值构造函数
	Home move_assigne;
	move_assigne = std::move(hyd_copy);
	//如果写成这样，则直接调用move构造
	//由于hyd_copy已经进行过移动操作，所以其内部成员str为空，int* 为nullptr
	Home move_con = std::move(hyd_copy);
}