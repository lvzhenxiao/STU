#include<iostream>
#include<cstring>///�⺯�����жϳ��ȣ����ƣ��Ƚϴ�С
#include<string>
#include<fstream>///�ļ���
#include<algorithm>///�㷨��
#include<iomanip>///��Ҫ�Ƕ�cin,cout֮���һЩ����������
#include<conio.h>///��Ҫ�Ƕ�getch()
#include<windows.h>///�����ļ�
using namespace std;

class student
{
private:
    long long  num;///ѧ��
    char name[20];///����
    char sex[6];///�Ա�
    int age;///����
    char  phone[20];///�绰��
public:
    static int NUM;///��NUM����Ϊ��̬��Ա����,��δ���������һ����̬��Ա���� NUM������ͳ��ѧ����������
    ///��̬��Ա����ͨ������ʣ�Ҳ����ͨ���������
    void input();///ѧ����Ϣ����
    ///friend ��Ϊ������ͳ̶ȱ������к���
    friend  void show();///ѧ����Ϣ��ʾ
    friend  void mood();///ѧ����Ϣ�޸�
    friend  void del();///ѧ����Ϣɾ��
    friend  void save();///ѧ����Ϣ����
    friend  void soort();///ѧ����Ϣ����
    friend  void findyou();///ѧ����Ϣ����
} xuesheng[1000];

int student::NUM=0;///�����ʼ���ſ����ã���ʼ��ʱͬʱ����ֵ��������ռ�
///��������޹أ��ڶ���֮�⿪�ٵĿռ�

void show()///ѧ����Ϣ��ʾ
{
    int i;
    if(student::NUM==0)///�����û����ѧ����Ϣ;
        cout<<endl<<endl<<setw(10)<<"����ѧ����Ϣ";
    else
    {
        cout<<"ѧ����Ϣ��ʾ"<<endl<<endl;
        cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)
            <<"�Ա�"<<setw(15)<<"����"<<setw(15)<<"�绰"
            <<endl;
        for(i=1; i<=student::NUM; i++)
        {
            cout<<xuesheng[i].num<<setw(15)<<xuesheng[i].name<<setw(15)
                <<xuesheng[i].sex<<setw(15)<<xuesheng[i].age<<setw(15)<<xuesheng[i].phone
                <<endl;
        }
    }
    cout<<endl<<setw(40)<<"��������˳�";
    getch();
}
void mood()///ѧ����Ϣ�޸�
{
    long long L;///����ռ䷶Χ��ѧ��
    int i;
    cout<<"���������޸ĵ�ѧ�ţ�";
    cin>>L;
    cout<<endl<<setw(40)<<"ȷ���޸�(y/n)";///setw�ǿ�����������
    if(getch()=='y')
    {
        system("cls");
        for( i=1; i<=student::NUM; i++)
            if(L==xuesheng[i].num)
            {
                cout<<"ѧ����Ϣ�޸�"<<endl<<endl;
                cout<<"ѧ��:";
                cin>>xuesheng[i].num;
                cout<<endl<<endl;
                cout<<"����:";
                cin>>xuesheng[i].name;
                cout<<endl<<endl;
                cout<<"�Ա�:";
                cin>>xuesheng[i].sex;
                cout<<endl<<endl;
                cout<<"����:";
                cin>>xuesheng[i].age;
                cout<<endl<<endl;
                cout<<"�绰:";
                cin>>xuesheng[i].phone;
                cout<<endl<<endl;
                break;
            }
        cout<<endl<<setw(40)<<"���޸ģ���������˳�";
        getch();
    }
    else
        return;
}
void del()///ѧ����Ϣɾ��
{
    int sum=0;
    cout<<setw(50)<<"[1]��ѧ��ɾ��                 [2]������ɾ��"<<endl;
    if(getch()=='1')
    {
        cout<<"������ѧ�ţ�";
        long long it;
        cin>>it;
        cout<<endl<<setw(30)<<"��ȷ��ɾ����ѧ����(y/n)";
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
            cout<<"��ɾ��"<<sum<<"��";
        }
        else
            return;
    }
    else  if(getch()=='2')
    {
        char name1[20];
        cout<<"������������";
        cin>>name1;
        cout<<endl<<setw(30)<<"��ȷ��ɾ����ѧ����(y/n)";
        if(getch()=='y')
        {
            system("cls");
            for(int i=1; i<=student::NUM; i++)
            {
                if(strcmp(xuesheng[i].name,name1)==0)///�Ƚ�
                {
                    for(int j=i+1; j<=student::NUM; j++)
                        xuesheng[j-1]=xuesheng[j];
                    student::NUM--;
                    sum++;
                }
            }
            cout<<"��ɾ��"<<sum<<"��";
        }
        else
            return;
    }
    cout<<endl<<endl<<setw(40)<<"�����������";
    getch();
}

void save()///����ѧ����Ϣ
{
    ofstream out("inf.txt",ios::binary);///�Զ����Ʒ�ʽ���ļ�
    cout<<endl<<setw(40)<<"�ѱ��棬��������˳�";
    for(int i=1; i<=student::NUM; i++)
    {
        out.write((char*)&xuesheng[i],sizeof(xuesheng[i]));
    }
    out.close();
    getch();
}


void soort()///ѧ����Ϣ����
{
    cout<<setw(50)<<"[1]��ѧ������                 [2]����������"<<endl;
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
        cout<<endl<<setw(50)<<"�����򣬰�������˳�";
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
        cout<<endl<<setw(50)<<"�����򣬰�������˳�";
        getch();
    }
}
void student::input()
{
LI:
    NUM++;
    cout<<"ѧ����Ϣ����"<<endl<<endl;
    cout<<"ѧ��:";
    cin>>xuesheng[NUM].num;
    cout<<endl<<endl;
    cout<<"����:";
    cin>>xuesheng[NUM].name;
    cout<<endl<<endl;
    cout<<"�Ա�:";
    cin>>xuesheng[NUM].sex;
    cout<<endl<<endl;
    cout<<"����:";
    cin>>xuesheng[NUM].age;
    cout<<endl<<endl;
    cout<<"�绰:";
    cin>>xuesheng[NUM].phone;
    cout<<endl<<endl;
    cout<<"�����룬�Ƿ����  (y/n)";
    if(getch()=='y')
    {
        system("cls");
        goto LI;
    }
    else return;
}


void findyou()///ѧ����Ϣ����
{
    int sum=0;
    cout<<setw(50)<<"[1]��ѧ�Ų���                 [2]����������"<<endl;
    if(getch()=='1')
    {
        cout<<"������ѧ�ţ�";
        long long it;
        cin>>it;
        cout<<endl<<setw(30)<<"��ȷ���鿴��ѧ����(y/n)";
        if(getch()=='y')
        {
            system("cls");
            cout<<"�鿴ѧ����Ϣ"<<endl<<endl;
            for(int i=1; i<=student::NUM; i++)
            {
                if(xuesheng[i].num==it)
                {
                    cout<<setw(20)<<"ѧ��:"<<xuesheng[i].num<<endl
                        <<setw(20)<<"����:"<<xuesheng[i].name<<endl
                        <<setw(20)<<"�Ա�:"<<xuesheng[i].sex<<endl
                        <<setw(20)<<"����:"<<xuesheng[i].age<<endl
                        <<setw(20)<<"�绰:"<<xuesheng[i].phone<<endl;
                    cout<<"---------------------------------------"<<endl<<endl;
                    sum++;
                }
            }
            cout<<"����ʾ"<<sum<<"��";
        }
        else
            return;
    }
    else  if(getch()=='2')
    {
        char name1[20];
        cout<<"������������";
        cin>>name1;///����������
        cout<<endl<<setw(30)<<"��ȷ���鿴���д�������ѧ����(y/n)";
        if(getch()=='y')
        {
            system("cls");
            cout<<"�鿴ѧ����Ϣ"<<endl<<endl;
            for(int i=1; i<=student::NUM; i++)
            {
                if(strcmp(xuesheng[i].name,name1)==0)
                {
                    cout<<setw(20)<<"ѧ��:"<<xuesheng[i].num<<endl
                        <<setw(20)<<"����:"<<xuesheng[i].name<<endl
                        <<setw(20)<<"�Ա�:"<<xuesheng[i].sex<<endl
                        <<setw(20)<<"����:"<<xuesheng[i].age<<endl
                        <<setw(20)<<"�绰:"<<xuesheng[i].phone<<endl;
                    cout<<"---------------------------------------"<<endl<<endl;
                    sum++;
                }
            }
            cout<<"����ʾ"<<sum<<"��";
        }
        else
            return;
    }
    cout<<endl<<endl<<setw(40)<<"�����������";///setw�ǿ�����������
    getch();
}
char mainmenu()///��ӭ����
{
    cout<<"\n\n           ��ӭ����ѧ����Ϣ����ϵͳ "<<endl<<endl;
    cout<<"\n\n          [1]����Ա            [2]ѧ��"<<endl<<endl;
    char ff=getch();
    return ff;
}
void adminmainmenu()
{
    cout<<"\n\n           ��ӭ����ѧ����Ϣ����ϵͳ(������) "<<endl<<endl
        <<endl
        <<endl
        <<"            1: ¼��ѧ����Ϣ "<<endl<<endl
        <<"            2: ��ʾѧ����Ϣ "<<endl<<endl
        <<"            3: �޸�ѧ����Ϣ "<<endl<<endl
        <<"            4: ɾ��ѧ����Ϣ "<<endl<<endl
        <<"            5: ����ѧ����Ϣ "<<endl<<endl
        <<"            6: ����ѧ����Ϣ "<<endl<<endl
        <<"            7: ����ѧ����Ϣ"<<endl<<endl
        <<"            8: ���س�ʼҳ��"<<endl<<endl
        <<"            0: �˳�ϵͳ"<<endl;
}
void mainmenu1()
{
    cout<<"\n\n           ��ӭ����ѧ����Ϣ����ϵͳ(ѧ��) "<<endl<<endl
        <<endl
        <<endl
        <<"            1: ��ʾѧ����Ϣ "<<endl<<endl
        <<"            2: ����ѧ����Ϣ "<<endl<<endl
        <<"            3: ����ѧ����Ϣ"<<endl<<endl
        <<"            4: ���س�ʼҳ��"<<endl<<endl
        <<"            0: �˳�ϵͳ"<<endl;
}


int main()
{
LIIIII:
    system("cls");
    char get =  mainmenu();
    if(get=='1')
    {
        char adminname[20],mima[20];
        ifstream in;///д�ļ�
        ofstream out;///���ļ�
        in.open("admin.txt",ios::in);///�ļ������뷽ʽ�򿪣��ļ����뵽�ڴ棩
        if(!in)
        {
            cout<<"�޹���Ա�˺ţ������趨��"<<endl<<endl;
FF:
            cout<<"�����˺�����";
            cin>>adminname;
            cout<<"�������룺";
            cin>>mima;
            cout<<"ȷ������(y/n)";
            char fff=getch();
            if(fff=='y')
            {
                out.open("admin.txt",ios::app);///����׷�ӵķ�ʽ���ļ���
                out<<adminname<<' '<<mima<<' ';
                system("cls");
                cout<<"                          �Ѵ����������������";
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
            cout<<"                 �Ѵ����û�"<<endl<<endl;
            cout<<"�Ƿ��½�����Ա�˻�(y/n)";
            char gr=getch();
            if(gr=='y')
            {
                system("cls");
                goto FF;
            }
ss1:
            system("cls");
            cout<<"��¼�˺ţ�";
            cin>>adminname;
            cout<<"�������룺";
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
                cout<<"            ��½�ɹ�         �����������";
                getch();
            }
            else
            {
                cout<<"�������"<<endl<<endl;
                cout<<"[1]���س�ʼ����      [2]������������";
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
                cout<<"\n\n\n\n                      ллʹ��~~";
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
            cout<<"��ѧ���˺ţ������趨��"<<endl<<endl;
LL:
            cout<<"�����˺�����";
            cin>>stuname;
            cout<<"�������룺";
            cin>>stumima;
            cout<<"ȷ������(y/n)";
            char fff=getch();
            if(fff=='y')
            {
                out.open("student.txt",ios::app);///��׷�ӵķ�ʽ���ļ�
                out<<stuname<<' '<<stumima<<' ';
                system("cls");
                cout<<"                          �Ѵ����������������";
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
            cout<<"                 �Ѵ����û�"<<endl<<endl;
            cout<<"�Ƿ��½��˻�(y/n)";
            char gr=getch();
            if(gr=='y')
            {
                system("cls");
                goto LL;
            }
sss:
            system("cls");
            cout<<"��¼�˺ţ�";
            cin>>stuname;
            cout<<"�������룺";
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
                cout<<"            ��½�ɹ�         �����������";
                getch();
            }
            else if(flog==1)
            {
                system("cls");
                cout<<"�������"<<endl<<endl;
                cout<<"[1]���س�ʼ����      [2]������������";
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
                cout<<"\n\n\n\n                      ллʹ��~~";
                exit(1);
            }
        }
    }
    return 0;
}
