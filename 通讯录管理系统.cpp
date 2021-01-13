#include<iostream>
using namespace std;

#include<string>
#define MAX 1000
//联系人具体
struct person
{
	string m_Name;		//名字
	int m_Sex;			//性别
	int m_Age;			//年龄
	string m_Phone;		//电话
	string m_Addr;		//地址
};

//通讯录
struct addressbooks
{
	//联系人数组
	struct person personArray[MAX];
	//联系人个数
	int m_Size;
};
//菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "*************************" << endl;
}


//添加联系人
void addPerson(addressbooks* abs)
{
	//判断通讯录人数是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else //添加具体人数
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：1---男 2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄	
		int age = 0;
		cout << "请输入年龄" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "请输入正确的年龄" << endl;
		}

		//电话
		string phone = "";
		cout << "请输入电话" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "当前输入手机号不足11位，请输入正确的手机号！" << endl;
		}

		//地址
		string addr;
		cout << "请输入地址" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;


		system("pause");
		system("cls");			//清屏
	}
}

//显示联系人
void showperson(addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别:" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "手机号：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//确认联系人存在
int isExist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;			//返回查找结果的下标编号
		}
	}
	return -1;			//无结果返回-1
}
//删除联系人
void deletePerson(addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];		//数据前移
		}
		abs->m_Size--;			//更新通讯录人数
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//查找联系人
void findperson(addressbooks* abs)
{
	cout << "请输入联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别:" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女")<<"\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "手机号：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "未找到该联系人" << endl;
	}

	system("pause");
	system("cls");

}

//修改联系人
void modifyperson(addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：1---男 2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄	
		int age = 0;
		cout << "请输入年龄" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "请输入正确的年龄" << endl;
		}

		//电话
		string phone = "";
		cout << "请输入电话" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "当前输入手机号不足11位，请输入正确的手机号！" << endl;
		}

		//地址
		string addr;
		cout << "请输入地址" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
	}
	else
	{
		cout<< "未找到联系人" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanperson(addressbooks* abs)
{
	cout << "请确认是否清空" << endl;
	cout << "确认 ----  1" << endl;
	cout << "返回 ----  输入任意值（除1以外）" << endl;
	int ret = 0;
	cin >> ret;
	if (ret == 1)
	{
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	addressbooks abs;
	//初始化人员个数
	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		showMenu();  //菜单界面调用

		cin >> select;

		switch (select)
		{
		case 1:  // 1、添加联系人
			addPerson(&abs);
			break;
		case 2:  // 2、显示联系人
			showperson(&abs);
			break;
		case 3:  // 3、删除联系人
			deletePerson(&abs);
		case 4:  // 4、查找联系人
			findperson(&abs);
			break;
		case 5:  // 5、修改联系人
			modifyperson(&abs);
			break;
		case 6:  // 6、清空联系人
			cleanperson(&abs);
			break;
		case 0:  // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}