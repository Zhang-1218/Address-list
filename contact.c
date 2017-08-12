#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Init_my_con(p _con)
{
	assert(_con);
	_con->data = (inform*)malloc(MAX * sizeof(inform));
	if (_con->data == NULL)
	{
		perror("Init_my_con malloc");
		exit(EXIT_FAILURE);
	}
	memset(_con->data, 0, sizeof(_con->data));//初始化结构体内容为0
	_con->sz = 0;
	_con->capacity = MAX;
	Load_inform(_con);
}

void Load_inform(p _con)
{
	inform temp;
	FILE* pfout = fopen("contact.txt", "r");
	if (pfout == NULL)
	{
		perror("file::read");
		exit(EXIT_FAILURE);
	}
	while (fread(&temp, sizeof(inform), 1, pfout))
	{
		Check_capacity(_con);
		_con->data[_con->sz] = temp;
		_con->sz++;
	}
}

void Save_inform(p _con)
{
	int i = 0;
	FILE* pfin = fopen("contact.txt", "w");
	if (pfin == NULL)
	{
		perror("file::write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < _con->sz; i++)
	{
		fwrite(_con->data + i, sizeof(inform), 1, pfin);
	}
	fclose(pfin); 
}

void Destroy_inform(p _con)
{
	Save_inform(_con);
	free(_con->data);
	_con->data = NULL;
	_con->sz = 0;
	_con->capacity = 0;
}

void Check_capacity(p _con)
{
	inform *new_con = (inform*)realloc(_con->data, (_con->capacity + 1)*sizeof(inform));
	if (new_con != NULL)
	{
		_con->data = new_con;
		_con->capacity += 1;
	}
	else
	{
		perror("Alloc space failed");
		return;
	}
}

void Add_inform(p _con)//添加联系人函数
{
	if (_con->sz == _con->capacity)
	{
		Check_capacity(_con);
	}

	printf("Please input name:<");
	scanf("%s", _con->data[_con->sz].name);
	printf("Please input gender:<");
	scanf("%s", _con->data[_con->sz].male);
	printf("Please input age:<");
	scanf("%d", &(_con->data[_con->sz].age));
	printf("Please input address:<");
	scanf("%s", _con->data[_con->sz].addr);
	printf("Please input phone:<");
	scanf("%s", _con->data[_con->sz].tele);

	printf("Added successfully！\n");
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
		printf("Input error, address book without this contact!\n");
	}
}

void Del_inform(p _con)//删除对应联系人
{
	int a = 0;
	int input = 0;
	char _name[20];

	if (_con->sz <= 0)
	{
		printf("The address book is empty！\n");
		return;
	}

	printf("Please enter the person you want to delete:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name); //查找通讯录中是否存在对象

	if (a == -1)
	{
		printf("Input error, address book without this contact!\n");
		return;
	}

	Show_inform(_con, a); //打印对象信息
	printf("Please confirm whether to delete  %s？\n", _con->data[a].name);//交互界面，让用户确定是否确认删除对象
	printf("confirm：1    cancel：0\nPlease input:<");
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
			printf("successfully deleted\n");
			return;
		case 0:
			return;
		default:
			printf("Choose the wrong, please re-select！\n");
			break;
		}
	} while (input);
}

void Find_inform(p _con)//查找对象函数
{
	char _name[20];
	int a = 0;
	printf("Please enter the person you want to find:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name);//遍历查找对象是否存在
	Show_inform(_con, a);//输出对应结果
}

void Mod_inform(p _con)//修改对象信息
{
	int a = 0;
	int input = 0;
	char _name[20];
	printf("Please enter the contact you want to modify:<");
	scanf("%s", _name);

	a = Search_inform(_con, _name); //遍历查找对象是否存在
	if (a == -1)
	{
		printf("Input error, address book without this contact!\n");
		return;
	}

	Show_inform(_con, a);
	printf("1. Modify the name 2. Modify the gender 3. Modify the age 4. Modify the address 5. Modify the phone 0. Save the changes\n");
	do
	{
		printf("Please choose according to the situation:<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Please enter a new name:<");
			scanf("%s", _con->data[a].name);
			break;
		case 2:
			printf("Please enter a new gender:<");
			scanf("%s", _con->data[a].male);
			break;
		case 3:
			printf("Please enter a new age:<");
			scanf("%d", &(_con->data[a].age));
			break;
		case 4:
			printf("Please enter a new address:<");
			scanf("%s", _con->data[a].addr);
			break;
		case 5:
			printf("Please enter a new call:<");
			scanf("%s", _con->data[a].tele);
			break;
		case 0:
			printf("Saved successfully\n");
			break;
		default:
			printf("Choose the wrong, please re-select！\n");
			break;
		}
	} while (input);
}

void Dis_inform(p _con)//显示所有对象信息
{
	int i = 0;

	if (_con->sz == 0)//判断通讯录是否为空
	{
		printf("The address book is empty！\n");
		return;
	}

	printf("%5s\t%5s\t%3s\t%12s\t%15s\n", "Name", "sex", "age", "address", "telephone");

	for (i = 0; i < _con->sz; i++)
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
	//memset(_con->data, NULL, sizeof(_con->data));//将通讯录内容全部置为NULL
	_con->sz = 0;
	printf("Clear success\n");
}

void Sorting(p _con, const int input)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	inform new_man;

	for (i = 0; i < _con->sz - 1; i++)
	{
		for (j = 0; j < _con->sz - 1 - i; j++)
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
	printf("Sorted successfully！\n");
	Dis_inform(_con);
}

void Sort_inform(p _con)//排序函数
{
	int input = 0;
	printf("1. Name 2. Gender 3. Age 4. Address 5. Telephone\n");
	printf("Please select the sorting request:<");
	scanf("%d", &input);
	Sorting(_con, input);
}