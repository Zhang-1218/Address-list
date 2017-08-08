#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Init_my_con(p _con)
{
	assert(_con);
	memset(_con->data, 0, sizeof(_con->data));//初始化结构体内容为0
	_con->sz = 0;
}

void Add_inform(p _con)//添加联系人函数
{
	if (_con->sz == MAX)
	{
		printf("通讯录已满!\n");
		return;
	}

	printf("请输入姓名:<");
	scanf("%s", _con->data[_con->sz].name);
	printf("请输入性别:<");
	scanf("%s", _con->data[_con->sz].male);
	printf("请输入年龄:<");
	scanf("%d", &(_con->data[_con->sz].age));
	printf("请输入地址:<");
	scanf("%s", _con->data[_con->sz].addr);
	printf("请输入电话:<");
	scanf("%s", _con->data[_con->sz].tele);

	printf("添加成功！\n");
	_con->sz++;
}

int Search_inform(const p _con, char * _name)
{
	int ret = 0;
	int a = 0;

	while ((a <= _con->sz) && (ret = (strcmp(_con->data[a].name, _name))))
	{
		a++; //遍历查找对象是否存在
	}

	if (ret == 0)
		return a; //存在返回其所在位数
	else
		return -1; //不存在返回-1
}

void Show_inform(p _con, int a) //根据Search_infor函数的查找结果，分别处理情况
{
	if (a != -1)
	{
		printf("%5s\t%5s\t%3s\t%12s\t%15s\n", "姓名", "性别", "年龄", "住址", "电话");
		printf("%5s\t%5s\t%3d\t%12s\t%10s\n",
			_con->data[a].name,
			_con->data[a].male,
			_con->data[a].age,
			_con->data[a].addr,
			_con->data[a].tele);
	}
	else
	{
		printf("输入错误，通讯录无此联系人!\n");
	}
}

void Del_inform(p _con)//删除对应联系人
{
	int a = 0;
	int input = 0;
	char _name[20];

	if (_con->sz <= 0)
	{
		printf("通讯录为空！\n");
		return;
	}

	printf("请输入要删除的人:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name); //查找通讯录中是否存在对象

	if (a == -1)
	{
		printf("输入错误，通讯录无此联系人!\n");
		return;
	}

	Show_inform(_con, a); //打印对象信息
	printf("请你确认是否删除  %s？\n", _con->data[a].name);//交互界面，让用户确定是否确认删除对象
	printf("确认请按：1    取消请按：0\n请输入:<");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			while (a < _con->sz)
			{
				_con->data[a] = _con->data[a + 1];//通过将对象之后的联系人整体向前挪动一位，对对象进行覆盖，达到删除目的
				a++;
			}
			_con->sz--; //_con->sz的指向向前挪动一位
			printf("删除成功\n");
			return;
		case 0:
			return;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}

void Find_inform(p _con)//查找对象函数
{
	char _name[20];
	int a = 0;
	printf("请输入要查找的人:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name);//遍历查找对象是否存在
	Show_inform(_con, a);//输出对应结果
}

void Mod_inform(p _con)//修改对象信息
{
	int a = 0;
	int input = 0;
	char _name[20];
	printf("请输入你要修改的联系人:<");
	scanf("%s", _name);

	a = Search_inform(_con, _name); //遍历查找对象是否存在
	if (a == -1)
	{
		printf("输入错误，通讯录无此联系人!\n");
		return;
	}

	Show_inform(_con, a);
	printf("1.修改姓名  2.修改性别  3.修改年龄  4.修改地址  5.修改电话  0.保存修改\n");
	do
	{
		printf("请根据情况选择:<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入新的姓名:<");
			scanf("%s", _con->data[a].name);
			break;
		case 2:
			printf("请输入新的性别:<");
			scanf("%s", _con->data[a].male);
			break;
		case 3:
			printf("请输入新的年龄:<");
			scanf("%d", &(_con->data[a].age));
			break;
		case 4:
			printf("请输入新的姓名:<");
			scanf("%s", _con->data[a].addr);
			break;
		case 5:
			printf("请输入新的电话:<");
			scanf("%s", _con->data[a].tele);
			break;
		case 0:
			printf("保存成功\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}

void Dis_inform(p _con)//显示所有对象信息
{
	int i = 0;

	if (_con->sz == 0)//判断通讯录是否为空
	{
		printf("通讯录为空！\n");
		return;
	}

	printf("%5s\t%5s\t%3s\t%12s\t%15s\n", "姓名", "性别", "年龄", "住址", "电话");

	for (; i < _con->sz; i++)
	{
		printf("%5s\t%5s\t%3d\t%12s\t%10s\n",
			_con->data[i].name,
			_con->data[i].male,
			_con->data[i].age,
			_con->data[i].addr,
			_con->data[i].tele);
	}
}

void Emp_inform(p _con)//清除通讯录内容
{
	_con->sz = 0;
	printf("清除成功\n");
}

void Sorting(p _con, const int input)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	inform new_man;

	for (; i < _con->sz - 1; i++)
	{
		for (; j < _con->sz - 1 - i; j++)
		{
			switch (input)
			{
			case 1:
				ret = strcmp(_con->data[j].name, _con->data[j + 1].name);//通过姓名进行排序
				break;
			case 2:
				ret = strcmp(_con->data[j].male, _con->data[j + 1].male);//通过性别进行排序
				break;
			case 3:
				if (_con->data[j].age - _con->data[j + 1].age > 0) //通过年龄进行排序
					ret = -1;
				break;
			case 4:
				ret = strcmp(_con->data[j].addr, _con->data[j + 1].addr);//通过地址进行排序
				break;
			case 5:
				ret = strcmp(_con->data[j].tele, _con->data[j + 1].tele);//通过电话进行排序
				break;
			}

			if (ret == -1)
			{
				new_man = _con->data[j];
				_con->data[j] = _con->data[j + 1];
				_con->data[j + 1] = new_man;
			}
		}
	}
	printf("排序成功！\n");
	Dis_inform(_con);
}

void Sort_inform(p _con)//排序函数
{
	int j = 0;
	int input = 0;
	printf("1.姓名  2.性别  3.年龄  4.地址  5.电话\n");
	printf("请选择排序要求:<");
	scanf("%d", &input);
	Sorting(_con, input);
}