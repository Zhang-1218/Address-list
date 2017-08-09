#ifndef  __CONTACT_H__
#define  __CONTACT_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define  MAX 2  //����ͨѶ¼��С��ʶ��

#define  MAX_NAME 20
#define  MAX_ADDR 25
#define  MAX_TELE 15
#define  MAX_MALE 5

typedef struct inform //���������ϵ����Ϣ�Ľṹ��
{
	char name[MAX_NAME];
	char male[MAX_MALE];
	int age;
	char addr[MAX_ADDR];
	char tele[MAX_TELE];
}inform;

typedef struct con  //���������ϵ����ͨѶ¼����ϵ�������Ľṹ��
{ 
	inform *data;//���������ϵ�˽ṹ��
	int sz;//������¼ͨѶ¼����ϵ������
	int capacity;
}con, *p;

void Init_my_con(p _con);
void Add_inform(p _con);
void Del_inform(p _con);
void Find_inform(p _con);
void Mod_inform(p _con);
void Dis_inform(p _con);
void Emp_inform(p _con);
void Sort_inform(p _con);
void Destroy_inform(p _con);

#endif // __CONTACT_H__
