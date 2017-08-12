#ifndef  __CONTACT_H__
#define  __CONTACT_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define  MAX 2  //定义通讯录大小标识符

#define  MAX_NAME 20
#define  MAX_ADDR 25
#define  MAX_TELE 15
#define  MAX_MALE 5

typedef struct inform //定义包含联系人信息的结构体
{
	char name[MAX_NAME];
	char male[MAX_MALE];
	int age;
	char addr[MAX_ADDR];
	char tele[MAX_TELE];
}inform;

typedef struct con  //定义包含联系人与通讯录中联系人数量的结构体
{ 
	inform *data;//定义包含联系人结构体
	int sz;//用来记录通讯录中联系人数量
	int capacity;
}con, *p;

void Init_my_con(p _con);//初始化通讯录函数
void Add_inform(p _con);//添加对象函数
void Del_inform(p _con);//删除对象函数
void Find_inform(p _con);//查找对象函数
void Mod_inform(p _con);//修改对象信息函数
void Dis_inform(p _con);//打印通讯录内容函数
void Emp_inform(p _con);//清空通讯录内容函数
void Sort_inform(p _con);//排序函数
void Save_inform(p _con);//保存对象至文件内函数
void Load_inform(p _con);//从文件中读取保存的对象函数
void Destroy_inform(p _con);//销毁通讯录函数
void Check_capacity(p _con);//增容函数
void Show_inform(p _con, int a);//显示搜寻对象结果函数
void Sorting(p _con, const int input);//排序通讯录内容函数
int Search_inform(const p _con, char * _name);//搜寻对应对象函数

#endif // __CONTACT_H__
		
