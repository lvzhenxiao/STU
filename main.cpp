#include<iostream>
#include<cstring>///库函数，判断长度，复制，比较大小
#include<string>
#include<fstream>///文件流
#include<algorithm>///算法库
#include<iomanip>///主要是对cin,cout之类的一些操纵运算子
#include<conio.h>///主要是对getch()
#include<windows.h>///清屏文件
using namespace std;

class student
{
private:
    long long  num;///学号
    char name[20];///姓名
    char sex[6];///性别
    int age;///年龄
    char  phone[20];///电话号
public:
    static int NUM;///将NUM定义为静态成员变量,这段代码声明了一个静态成员变量 NUM，用来统计学生的人数。
    ///静态成员可以通过类访问，也可以通过对象访问
    void input();///学生信息输入
    ///friend 是为了最大型程度保护公有函数
    friend  void show();///学生信息显示
    friend  void mood();///学生信息修改
    friend  void del();///学生信息删除
    friend  void save();///学生信息保存
    friend  void soort();///学生信息排序
    friend  void findyou();///学生信息查找
} xuesheng[1000];

int student::NUM=0;///必须初始化才可以用，初始化时同时赋初值，并分配空间
///空与对象无关，在对象之外开辟的空间

void show()///学生信息显示
{
    int i;
    if(student::NUM==0)///如果还没输入学生信息;
        cout<<endl<<endl<<setw(10)<<"暂无学生信息";
    else
    {
        cout<<"学生信息显示"<<endl<<endl;
        cout<<"学号"<<setw(15)<<"姓名"<<setw(15)
            <<"性别"<<setw(15)<<"年龄"<<setw(15)<<"电话"
            <<endl;
        for(i=1; i<=student::NUM; i++)
        {
            cout<<xuesheng[i].num<<setw(15)<<xuesheng[i].name<<setw(15)
                <<xuesheng[i].sex<<setw(15)<<xuesheng[i].age<<setw(15)<<xuesheng[i].phone
                <<endl;
        }
    }
    cout<<endl<<setw(40)<<"按任意键退出";
    getch();
}
void mood()///学生信息修改
{
    long long L;///更大空间范围的学号
    int i;
    cout<<"请输入想修改的学号：";
    cin>>L;
    cout<<endl<<setw(40)<<"确认修改(y/n)";///setw是控制输出间隔的
    if(getch()=='y')
    {
        system("cls");
        for( i=1; i<=student::NUM; i++)
            if(L==xuesheng[i].num)
            {
                cout<<"学生信息修改"<<endl<<endl;
                cout<<"学号:";
                cin>>xuesheng[i].num;
                cout<<endl<<endl;
                cout<<"姓名:";
                cin>>xuesheng[i].name;
                cout<<endl<<endl;
                cout<<"性别:";
                cin>>xuesheng[i].sex;
                cout<<endl<<endl;
                cout<<"年龄:";
                cin>>xuesheng[i].age;
                cout<<endl<<endl;
                cout<<"电话:";
                cin>>xuesheng[i].phone;
                cout<<endl<<endl;
                break;
            }
        cout<<endl<<setw(40)<<"已修改，按任意键退出";
        getch();
    }
    else
        return;
}
void del()///学生信息删除
{
    int sum=0;
    cout<<setw(50)<<"[1]按学号删除                 [2]按姓名删除"<<endl;
    if(getch()=='1')
    {
        cout<<"请输入学号：";
        long long it;
        cin>>it;
        cout<<endl<<setw(30)<<"您确定删除此学生吗？(y/n)";
        if(getch()=='y')
        {
            system("cls");
            for(int i=1; i<=student::NUM; i++)
            {
                if(xuesheng[i].num==it)
                {
                    for(int j=i+1; j<=student::NUM; j++)
                        xuesheng[j-1]=xuesheng[j];
                    student::NUM--;
                    sum++;
                    break;
                }
            }
            cout<<"共删除"<<sum<<"人";
        }
        else
            return;
    }
    else  if(getch()=='2')
    {
        char name1[20];
        cout<<"请输入姓名：";
        cin>>name1;
        cout<<endl<<setw(30)<<"您确定删除此学生吗？(y/n)";
        if(getch()=='y')
        {
            system("cls");
            for(int i=1; i<=student::NUM; i++)
            {
                if(strcmp(xuesheng[i].name,name1)==0)///比较
                {
                    for(int j=i+1; j<=student::NUM; j++)
                        xuesheng[j-1]=xuesheng[j];
                    student::NUM--;
                    sum++;
                }
            }
            cout<<"共删除"<<sum<<"人";
        }
        else
            return;
    }
    cout<<endl<<endl<<setw(40)<<"按任意键结束";
    getch();
}

void save()///保存学生信息
{
    ofstream out("inf.txt",ios::binary);///以二进制方式打开文件
    cout<<endl<<setw(40)<<"已保存，按任意键退出";
    for(int i=1; i<=student::NUM; i++)
    {
        out.write((char*)&xuesheng[i],sizeof(xuesheng[i]));
    }
    out.close();
    getch();
}


void soort()///学生信息排序
{
    cout<<setw(50)<<"[1]按学号排序                 [2]按年龄排序"<<endl;
    if(getch()=='1')
    {
        for(int i=1; i<student::NUM; i++)
            for(int j=1; j<student::NUM-i+1; j++)
            {
                if(xuesheng[j].num>xuesheng[j+1].num)
                {
                    student it=xuesheng[j];
                    xuesheng[j]=xuesheng[j+1];
                    xuesheng[j+1]=it;
                }
            }
        cout<<endl<<setw(50)<<"已排序，按任意键退出";
        getch();
    }
    else  if(getch()=='2')
    {
        for(int i=1; i<student::NUM; i++)
            for(int j=1; j<student::NUM-i+1; j++)
            {
                if(xuesheng[j].age>xuesheng[j+1].age)
                {
                    student it=xuesheng[j];
                    xuesheng[j]=xuesheng[j+1];
                    xuesheng[j+1]=it;
                }
            }
        cout<<endl<<setw(50)<<"已排序，按任意键退出";
        getch();
    }
}
void student::input()
{
LI:
    NUM++;
    cout<<"学生信息输入"<<endl<<endl;
    cout<<"学号:";
    cin>>xuesheng[NUM].num;
    cout<<endl<<endl;
    cout<<"姓名:";
    cin>>xuesheng[NUM].name;
    cout<<endl<<endl;
    cout<<"性别:";
    cin>>xuesheng[NUM].sex;
    cout<<endl<<endl;
    cout<<"年龄:";
    cin>>xuesheng[NUM].age;
    cout<<endl<<endl;
    cout<<"电话:";
    cin>>xuesheng[NUM].phone;
    cout<<endl<<endl;
    cout<<"已输入，是否继续  (y/n)";
    if(getch()=='y')
    {
        system("cls");
        goto LI;
    }
    else return;
}


void findyou()///学生信息查找
{
    int sum=0;
    cout<<setw(50)<<"[1]按学号查找                 [2]按姓名查找"<<endl;
    if(getch()=='1')
    {
        cout<<"请输入学号：";
        long long it;
        cin>>it;
        cout<<endl<<setw(30)<<"您确定查看此学生吗？(y/n)";
        if(getch()=='y')
        {
            system("cls");
            cout<<"查看学生信息"<<endl<<endl;
            for(int i=1; i<=student::NUM; i++)
            {
                if(xuesheng[i].num==it)
                {
                    cout<<setw(20)<<"学号:"<<xuesheng[i].num<<endl
                        <<setw(20)<<"姓名:"<<xuesheng[i].name<<endl
                        <<setw(20)<<"性别:"<<xuesheng[i].sex<<endl
                        <<setw(20)<<"年龄:"<<xuesheng[i].age<<endl
                        <<setw(20)<<"电话:"<<xuesheng[i].phone<<endl;
                    cout<<"---------------------------------------"<<endl<<endl;
                    sum++;
                }
            }
            cout<<"共显示"<<sum<<"人";
        }
        else
            return;
    }
    else  if(getch()=='2')
    {
        char name1[20];
        cout<<"请输入姓名：";
        cin>>name1;///按姓名查找
        cout<<endl<<setw(30)<<"您确定查看具有此姓名的学生吗？(y/n)";
        if(getch()=='y')
        {
            system("cls");
            cout<<"查看学生信息"<<endl<<endl;
            for(int i=1; i<=student::NUM; i++)
            {
                if(strcmp(xuesheng[i].name,name1)==0)
                {
                    cout<<setw(20)<<"学号:"<<xuesheng[i].num<<endl
                        <<setw(20)<<"姓名:"<<xuesheng[i].name<<endl
                        <<setw(20)<<"性别:"<<xuesheng[i].sex<<endl
                        <<setw(20)<<"年龄:"<<xuesheng[i].age<<endl
                        <<setw(20)<<"电话:"<<xuesheng[i].phone<<endl;
                    cout<<"---------------------------------------"<<endl<<endl;
                    sum++;
                }
            }
            cout<<"共显示"<<sum<<"人";
        }
        else
            return;
    }
    cout<<endl<<endl<<setw(40)<<"按任意键结束";///setw是控制输出间隔的
    getch();
}
char mainmenu()///欢迎界面
{
    cout<<"\n\n           欢迎进入学生信息管理系统 "<<endl<<endl;
    cout<<"\n\n          [1]管理员            [2]学生"<<endl<<endl;
    char ff=getch();
    return ff;
}
void adminmainmenu()
{
    cout<<"\n\n           欢迎进入学生信息管理系统(管理者) "<<endl<<endl
        <<endl
        <<endl
        <<"            1: 录入学生信息 "<<endl<<endl
        <<"            2: 显示学生信息 "<<endl<<endl
        <<"            3: 修改学生信息 "<<endl<<endl
        <<"            4: 删除学生信息 "<<endl<<endl
        <<"            5: 保存学生信息 "<<endl<<endl
        <<"            6: 查找学生信息 "<<endl<<endl
        <<"            7: 排序学生信息"<<endl<<endl
        <<"            8: 返回初始页面"<<endl<<endl
        <<"            0: 退出系统"<<endl;
}
void mainmenu1()
{
    cout<<"\n\n           欢迎进入学生信息管理系统(学生) "<<endl<<endl
        <<endl
        <<endl
        <<"            1: 显示学生信息 "<<endl<<endl
        <<"            2: 查找学生信息 "<<endl<<endl
        <<"            3: 排序学生信息"<<endl<<endl
        <<"            4: 返回初始页面"<<endl<<endl
        <<"            0: 退出系统"<<endl;
}


int main()
{
LIIIII:
    system("cls");
    char get =  mainmenu();
    if(get=='1')
    {
        char adminname[20],mima[20];
        ifstream in;///写文件
        ofstream out;///读文件
        in.open("admin.txt",ios::in);///文件以输入方式打开（文件输入到内存）
        if(!in)
        {
            cout<<"无管理员账号，请先设定："<<endl<<endl;
FF:
            cout<<"输入账号名：";
            cin>>adminname;
            cout<<"输入密码：";
            cin>>mima;
            cout<<"确定创建(y/n)";
            char fff=getch();
            if(fff=='y')
            {
                out.open("admin.txt",ios::app);///（以追加的方式打开文件）
                out<<adminname<<' '<<mima<<' ';
                system("cls");
                cout<<"                          已创建，按任意键返回";
                getch();
                out.close();
                goto LIIIII;
            }
            else if(fff=='n')
                goto LIIIII;
        }
        else
        {
            system("cls");
            cout<<"                 已存在用户"<<endl<<endl;
            cout<<"是否新建管理员账户(y/n)";
            char gr=getch();
            if(gr=='y')
            {
                system("cls");
                goto FF;
            }
ss1:
            system("cls");
            cout<<"登录账号：";
            cin>>adminname;
            cout<<"输入密码：";
            cin>>mima;
            char adminname1[20],mima1[20];
            int flog=0;
            while(!in.eof())
            {
                in>>adminname1>>mima1;
                if(!strcmp(adminname,adminname1)&&!strcmp(mima1,mima))
                {
                    flog=0;
                    break;
                }
            }
            if(flog==0)
            {
                system("cls");
                cout<<"            登陆成功         按任意键继续";
                getch();
            }
            else
            {
                cout<<"密码错误"<<endl<<endl;
                cout<<"[1]返回初始界面      [2]重新输入密码";
                char gg=getch();
                if(gg=='1')
                    goto LIIIII;
                else
                {
                    system("cls");
                    goto ss1;
                }
            }
        }
        while(1)
        {
            adminmainmenu();
            char ch;
            ch=getchar();
            system("CLS");
            switch(ch)
            {
            case '1':
                xuesheng[student::NUM].input();
                break;
            case '2':
                show();
                break;
            case '3':
                mood();
                break;
            case '4':
                del();
                break;
            case '5':
                save();
                break;
            case '6':
                findyou();
                break;
            case '7':
                soort();
                break;
            case '8':
                goto LIIIII;
            case '0':
                cout<<"\n\n\n\n                      谢谢使用~~";
                exit(1);
            }
        }
    }
    else if(get=='2')
    {
        char stuname[20],stumima[20];
        ifstream in;
        ofstream out;
        in.open("student.txt",ios::in);
        if(!in)
        {
            cout<<"无学生账号，请先设定："<<endl<<endl;
LL:
            cout<<"输入账号名：";
            cin>>stuname;
            cout<<"输入密码：";
            cin>>stumima;
            cout<<"确定创建(y/n)";
            char fff=getch();
            if(fff=='y')
            {
                out.open("student.txt",ios::app);///以追加的方式打开文件
                out<<stuname<<' '<<stumima<<' ';
                system("cls");
                cout<<"                          已创建，按任意键返回";
                getch();
                out.close();
                goto LIIIII;
            }
            else if(fff=='n')
                goto LIIIII;
        }
        else
        {
            system("cls");
            cout<<"                 已存在用户"<<endl<<endl;
            cout<<"是否新建账户(y/n)";
            char gr=getch();
            if(gr=='y')
            {
                system("cls");
                goto LL;
            }
sss:
            system("cls");
            cout<<"登录账号：";
            cin>>stuname;
            cout<<"输入密码：";
            cin>>stumima;
            char stuname1[20],stumima1[20];
            int flog=1;
            while(!in.eof())
            {
                in>>stuname1>>stumima1;
                if(!strcmp(stuname,stuname1)&&!strcmp(stumima1,stumima))
                {
                    flog=0;
                    break;
                }
            }
            if(flog==0)
            {
                system("cls");
                cout<<"            登陆成功         按任意键继续";
                getch();
            }
            else if(flog==1)
            {
                system("cls");
                cout<<"密码错误"<<endl<<endl;
                cout<<"[1]返回初始界面      [2]重新输入密码";
                char gg=getch();
                if(gg=='1')
                    goto LIIIII;
                else
                {
                    system("cls");
                    goto  sss;
                }
            }
            in.close();
        }
        while(1)
        {
            mainmenu1();
            char ch;
            ch=getchar();
            system("CLS");
            switch(ch)
            {
            case '1':
                show();
                break;
            case '2':
                findyou();
                break;
            case '3':
                soort();
                break;
            case '4':
                goto LIIIII;
            case '0':
                cout<<"\n\n\n\n                      谢谢使用~~";
                exit(1);
            }
        }
    }
    return 0;
}
