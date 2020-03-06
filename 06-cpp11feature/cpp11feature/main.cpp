#include<iostream>
#include "shared_ptrdm.h"
#include "stldemo.h"
#include "movedemo.h"
#include "lambdademo.h"
#include "functiondemo.h"
#include "functionbind.h"

using namespace std;
int main()
{
	use_sharedptr();
	use_uniqueptr();
	use_weakptr();
	raw_ptr();
	use_weakptr();
	use_vector();
	use_array();
	use_deque();
	use_list();
	use_map();
	use_unorderd_map();
	use_move();
	use_lambda();
	test_lambdalife();
	use_funclass();
	use_function();
	use_funcmem();
	getchar();
    return 0;
}

