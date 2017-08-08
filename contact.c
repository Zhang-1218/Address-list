#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Init_my_con(p _con)
{
	assert(_con);
	memset(_con->data, 0, sizeof(_con->data));//��ʼ���ṹ������Ϊ0
	_con->sz = 0;
}

void Add_inform(p _con)//�����ϵ�˺���
{
	if (_con->sz == MAX)
	{
		printf("ͨѶ¼����!\n");
		return;
	}

	printf("����������:<");
	scanf("%s", _con->data[_con->sz].name);
	printf("�������Ա�:<");
	scanf("%s", _con->data[_con->sz].male);
	printf("����������:<");
	scanf("%d", &(_con->data[_con->sz].age));
	printf("�������ַ:<");
	scanf("%s", _con->data[_con->sz].addr);
	printf("������绰:<");
	scanf("%s", _con->data[_con->sz].tele);

	printf("��ӳɹ���\n");
	_con->sz++;
}

int Search_inform(const p _con, char * _name)
{
	int ret = 0;
	int a = 0;

	while ((a <= _con->sz) && (ret = (strcmp(_con->data[a].name, _name))))
	{
		a++; //�������Ҷ����Ƿ����
	}

	if (ret == 0)
		return a; //���ڷ���������λ��
	else
		return -1; //�����ڷ���-1
}

void Show_inform(p _con, int a) //����Search_infor�����Ĳ��ҽ�����ֱ������
{
	if (a != -1)
	{
		printf("%5s\t%5s\t%3s\t%12s\t%15s\n", "����", "�Ա�", "����", "סַ", "�绰");
		printf("%5s\t%5s\t%3d\t%12s\t%10s\n",
			_con->data[a].name,
			_con->data[a].male,
			_con->data[a].age,
			_con->data[a].addr,
			_con->data[a].tele);
	}
	else
	{
		printf("�������ͨѶ¼�޴���ϵ��!\n");
	}
}

void Del_inform(p _con)//ɾ����Ӧ��ϵ��
{
	int a = 0;
	int input = 0;
	char _name[20];

	if (_con->sz <= 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}

	printf("������Ҫɾ������:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name); //����ͨѶ¼���Ƿ���ڶ���

	if (a == -1)
	{
		printf("�������ͨѶ¼�޴���ϵ��!\n");
		return;
	}

	Show_inform(_con, a); //��ӡ������Ϣ
	printf("����ȷ���Ƿ�ɾ��  %s��\n", _con->data[a].name);//�������棬���û�ȷ���Ƿ�ȷ��ɾ������
	printf("ȷ���밴��1    ȡ���밴��0\n������:<");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			while (a < _con->sz)
			{
				_con->data[a] = _con->data[a + 1];//ͨ��������֮�����ϵ��������ǰŲ��һλ���Զ�����и��ǣ��ﵽɾ��Ŀ��
				a++;
			}
			_con->sz--; //_con->sz��ָ����ǰŲ��һλ
			printf("ɾ���ɹ�\n");
			return;
		case 0:
			return;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

void Find_inform(p _con)//���Ҷ�����
{
	char _name[20];
	int a = 0;
	printf("������Ҫ���ҵ���:< ");
	scanf("%s", _name);
	a = Search_inform(_con, _name);//�������Ҷ����Ƿ����
	Show_inform(_con, a);//�����Ӧ���
}

void Mod_inform(p _con)//�޸Ķ�����Ϣ
{
	int a = 0;
	int input = 0;
	char _name[20];
	printf("��������Ҫ�޸ĵ���ϵ��:<");
	scanf("%s", _name);

	a = Search_inform(_con, _name); //�������Ҷ����Ƿ����
	if (a == -1)
	{
		printf("�������ͨѶ¼�޴���ϵ��!\n");
		return;
	}

	Show_inform(_con, a);
	printf("1.�޸�����  2.�޸��Ա�  3.�޸�����  4.�޸ĵ�ַ  5.�޸ĵ绰  0.�����޸�\n");
	do
	{
		printf("��������ѡ��:<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�������µ�����:<");
			scanf("%s", _con->data[a].name);
			break;
		case 2:
			printf("�������µ��Ա�:<");
			scanf("%s", _con->data[a].male);
			break;
		case 3:
			printf("�������µ�����:<");
			scanf("%d", &(_con->data[a].age));
			break;
		case 4:
			printf("�������µ�����:<");
			scanf("%s", _con->data[a].addr);
			break;
		case 5:
			printf("�������µĵ绰:<");
			scanf("%s", _con->data[a].tele);
			break;
		case 0:
			printf("����ɹ�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

void Dis_inform(p _con)//��ʾ���ж�����Ϣ
{
	int i = 0;

	if (_con->sz == 0)//�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}

	printf("%5s\t%5s\t%3s\t%12s\t%15s\n", "����", "�Ա�", "����", "סַ", "�绰");

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

void Emp_inform(p _con)//���ͨѶ¼����
{
	_con->sz = 0;
	printf("����ɹ�\n");
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
				ret = strcmp(_con->data[j].name, _con->data[j + 1].name);//ͨ��������������
				break;
			case 2:
				ret = strcmp(_con->data[j].male, _con->data[j + 1].male);//ͨ���Ա��������
				break;
			case 3:
				if (_con->data[j].age - _con->data[j + 1].age > 0) //ͨ�������������
					ret = -1;
				break;
			case 4:
				ret = strcmp(_con->data[j].addr, _con->data[j + 1].addr);//ͨ����ַ��������
				break;
			case 5:
				ret = strcmp(_con->data[j].tele, _con->data[j + 1].tele);//ͨ���绰��������
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
	printf("����ɹ���\n");
	Dis_inform(_con);
}

void Sort_inform(p _con)//������
{
	int j = 0;
	int input = 0;
	printf("1.����  2.�Ա�  3.����  4.��ַ  5.�绰\n");
	printf("��ѡ������Ҫ��:<");
	scanf("%d", &input);
	Sorting(_con, input);
}