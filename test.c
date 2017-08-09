#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("***************************************************\n");
	printf("**********      Welcome To My Contacts   **********\n");
	printf("*******        1.Add           2.Delete     *******\n");
	printf("*******        3.Find          4.Modify     *******\n");
	printf("*******        5.Display       6.Empty      *******\n");
	printf("*******        7.Sort          0.Exit       *******\n");
	printf("***************************************************\n");

}

enum option  //定义枚举变量，确定选择顺序
{
	Exit,
	Add,
	Del,
	Find,
	Mod,
	Dis,
	Emp,
	Sort
};

void test()
{
	con my_con;
	Init_my_con(&my_con); //初始化结构体
	int input = 0;
	do 
	{
		menu();
		printf("please choose：< ");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Add_inform(&my_con);
			break;
		case Del:
			Del_inform(&my_con);
			break;
		case Find:
			Find_inform(&my_con);
			break;
		case Mod:
			Mod_inform(&my_con);
			break;
		case Dis:
			Dis_inform(&my_con);
			break;
		case Emp:
			Emp_inform(&my_con);
			break;
		case Sort:
			Sort_inform(&my_con);
			break;
		case Exit:
			Destroy_inform(&my_con);
			break;
		default:
			printf("Choose the wrong, please re-select！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
}