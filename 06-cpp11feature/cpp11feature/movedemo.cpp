#include "movedemo.h"
#include <utility>

//���һ����û��Ĭ�Ϲ��캯������ϵͳ���Զ�����һ��Ĭ�ϵĹ��캯��
//���һ����ʵ���˲������캯������ϵͳ�����Զ�����Ĭ���޲ι��캯������Ҫ�ֶ�ʵ��
//���һ����û��ʵ��copy���캯������ϵͳ���ṩһ��Ĭ�ϵ�copy���캯��
//���һ����û��ʵ��move���캯������ϵͳ���ṩһ��Ĭ�ϵ�move���캯��
//������ʵ����copy���캯������ϵͳ�����ṩĬ�ϵ�move���캯����ͬ��
//�������ʵ����move���캯������ϵͳ�����ṩĬ�ϵ�copy���캯��
//���û��ʵ��copy��ֵ���������ϵͳ���ṩĬ�ϵ�copy��ֵ�����
//���û��ʵ��move��ֵ���������ϵͳ����ṩĬ�ϵ�move��ֵ�������
//���ʵ����copy��ֵ���������ϵͳ�����ṩĬ�ϵ�move��ֵ���������֮����Ȼ��
void use_move() {
	Home home_hyd("Hyd", 326);
	//copy ���캯��
	Home hyd_copy(home_hyd);
	//move ���캯��
	Home  hyd_move (move(hyd_copy));
	Home  home_default;
	//copy ��ֵ
	home_default = home_hyd;
	//���д�����£���ֱ�ӵ���copy����
	Home copy_con = home_hyd;
	//move ��ֵ���캯��
	Home move_assigne;
	move_assigne = std::move(hyd_copy);
	//���д����������ֱ�ӵ���move����
	//����hyd_copy�Ѿ����й��ƶ��������������ڲ���ԱstrΪ�գ�int* Ϊnullptr
	Home move_con = std::move(hyd_copy);
}