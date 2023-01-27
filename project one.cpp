#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<chrono>
#include<thread>
#include<stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class one
{
private:
    int order_name=0,order_password=0,order_reg=0,ord,tries=5,lock,ord_reg_check,ran,present_11[3]={0,0,0},present_12[3]={0,0,0},choice,main_ch,dat,p=1,p2=1,ch_menu,retake=0,rep=0;
    char name1[100],name2[150],password1[20],password2[25],reg1[20],reg2[25],reg3[20],qus[100],ans[100],ans1[100],ans2[100],ans3[100];
public:
    void menu()
    {
        menu:cout<<"\n\n\n\n\t************ WELCOME TO ATTENDANCE MAKING SOFTWARE **************\n\n\n"<<endl;
        cout<<"\t\t\t+*+  1.TO MAKE ENTRY\t    +*+\n\t\t\t+*+  2.TO CHECK ATTENDANCE  +*+\n\t\t\t+*+  3.TO EXIT\t\t    +*+";
        cout<<"\n\n\n\t*****************************************************************";
        cout<<endl<<endl<<"ENTER YOUR CHOICE - ";
        cin>>main_ch;
        if(main_ch==1)
        {
            input();
        }
        else if(main_ch==2)
        {
            re:system("cls");
            cout<<"ENTER THE CLASS TO DISPLAY DETAILS\n";
            cin>>dat;
            if(dat==11)
            {
                cout<<"STUDENTS PRESENT IN CLASS 11 ARE:\n";
                for(int i=0;i<=2;i++)
                {
                    if(present_11[i]==0)
                    {
                        if(present_11[0]==0&&present_11[1]==0&&present_11[2]==0)
                        {
                            p=0;
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        cout<<present_11[i]<<endl;
                    }
                }
                if(p==0)
                    {
                        cout<<"\nNO STUDENTS PRESENT\n";
                    }
                    else
                    {
                          ;
                    }
            }
            else if(dat==12)
            {
                cout<<"STUDENTS PRESENT IN CLASS 12 ARE:\n";
                for(int i=0;i<=2;i++)
                {
                    if(present_12[i]==0)
                    {
                        if(present_12[0]==0&&present_12[1]==0&&present_12[2]==0)
                        {
                            p2=0;
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        cout<<present_12[i]<<endl;
                    }
                }
                if(p2==0)
                    {
                        cout<<"\nNO STUDENTS PRESENT\n";
                    }
                    else
                    {
                          ;
                    }
            }
            else
                {
                    system("cls");
                    cout<<"WRONG INPUT ...\n\nENTER AGAIN";
                    chrono::seconds dura(2);
                    this_thread::sleep_for(1*dura);
                    goto re;
                }
            cout<<"\n\n\t\t********************************";
            cout<<"\n\nYOU WANT TO CONTINUE(ENTER 1. TO CONTINUE  ANYTHING ELSE TO EXIT)\n\n";
            cout<<"\t\t********************************\n\n";
            cin>>ch_menu;
            if(ch_menu==1)
            {
                system("cls");
                goto menu;
            }
            else
            {
            system("cls");
            cout<<"EXITING";
            chrono::seconds dura(2);
            this_thread::sleep_for(1*dura);
            exit(0);
            }

        }
        else if(main_ch==3)
        {
            system("cls");
            cout<<"EXITING";
            chrono::seconds dura(2);
            this_thread::sleep_for(1*dura);
            exit(0);
        }
        else
        {
            system("cls");
            cout<<"WRONG INPUT"<<endl<<"ENTER AGAIN";
            goto menu;
        }
    }
    void END()
    {
        system("cls");
        cout<<"YOU ARE LOCKED";
        exit(EXIT_FAILURE);
    }
    void retry()
    {
        chrono::seconds dura(1);
        for(tries=tries;tries>=1;tries=tries)
        {
            cout<<"You Are Left With "<<tries-1<<" Tries";
            this_thread::sleep_for(2*dura);
            system("cls");
            tries--;
            break;
        }
        if(tries==0)
        {
            for(lock=3;lock>=0;lock--)
            {
                cout<<"You Are Being Locked In "<<lock<<" Seconds";
                this_thread::sleep_for(dura);
                system("cls");
            }
            END();
        }
        else
        {
            ;
        }
    }
    void input()
    {
        system("cls");
        chrono::seconds dura(1);
        a:ord=0;order_name=0;
        cin.ignore();
        cout<<"\n\t\t*********************\n\n";
        cout<<"\t   *  ENTER YOUR NAME(TEACHER)  *\n";
        cout<<"\n\t\t*********************\n\n";
        this_thread::sleep_for(2*dura);
        cout<<"\t\t";
        cin.getline(name1,100);
        fstream name_check("employ_data/name.txt",ios::in);
        while(!name_check.eof())
        {
            name_check.getline(name2,150);
            ord++;
            if(strcmp(name1,name2)==0)
            {
                order_name=ord;
            }
            else
            {
                ;
            }
        }
       if(order_name==0)
       {
           system("cls");
           cout<<"NAME NOT FOUND";
           this_thread::sleep_for(2*dura);
           system("cls");
           retry();
           goto a;
       }
       else
       {
           ;
       }
        name_check.close();
        b:ord=0;order_password=0;
        cout<<"\n\t\t*********************\n\n";
        cout<<"\t     *  ENTER YOUR PASSWORD  *"<<endl;
        cout<<"\n\t\t*********************\n\n";
        cout<<"\t\t";
        cin.getline(password1,20);
        fstream password_check("employ_data/password.txt",ios::in);
        while(!password_check.eof())
        {
            password_check.getline(password2,25);
            ord++;
            if(strcmp(password1,password2)==0)
            {
                order_password=ord;
            }
            else
            {
                ;
            }
        }
        if(order_password==0)
        {
            system("cls");
            cout<<"\n\t\t******************\n\n";
            cout<<"\t\tPASSWORD NOT FOUND";
            cout<<"\n\t\t*****************\n\n";
            this_thread::sleep_for(2*dura);
            system("cls");
            retry();
            goto b;
        }
        else
        {
            ;
        }
        password_check.close();
        if(order_name==order_password)
        {
            system("cls");
            cout<<"*** ACCESS GRANTED ***";
            this_thread::sleep_for(2*dura);
            system("cls");
            cout<<"*** WELCOME MR/MRS. "<<name1<<" ***";
            student_entry();
        }
        else
        {
            system("cls");
            cout<<"*** Name And Password Do Not Match ***";
            this_thread::sleep_for(2*dura);
            system("cls");
            retry();
            goto a;
        }
    }
    void student_entry()
    {
        chrono::seconds dura(1);
        this_thread::sleep_for(2*dura);
        system("cls");
        if(order_name==1)
        {
            if(rep!=0)
            {
                retake=0;
            }
            else
            {
                ;
            }
            cout<<"\n\t\t****************************\n";
            cout<<"\t\t\t   CLASS 11\n\t\t\t   STUDENTS\n";
            tries=5;
            d:ord=0;order_reg=0;
            cout<<"\t\t******************************\n";
            cout<<"\t\tENTER YOUR REGISTRATION NUMBER";
            cout<<"\n\t\t******************************\n";
            cout<<"\t\t";
            if(retake!=0)
                {
                    cin.ignore();
                }
            cin.getline(reg1,20);
            fstream reg_check("student_data/class 11/student_reg.txt",ios::in);
            while(!reg_check.eof())
            {
                reg_check.getline(reg2,25);
                ord++;
                if(strcmp(reg1,reg2)==0)
                {
                    order_reg=ord;
                }
                else
                {
                    ;
                }
            }
            reg_check.close();
            if(order_reg==0)
            {
                system("cls");
                cout<<"*** REGESTRATION NUMBER NOT FOUND ***\n";
                this_thread::sleep_for(2*dura);
                retry();
                goto d;
            }
            else
            {
                system("cls");
                ord_reg_check=order_reg;
                order_reg=0;
                ord=0;
                cout<<"\n\t\t*********************\n";
                cout<<"\t\tFOR RE-CONFIRMATION"<<endl;
                cout<<"\t   ENTER YOUR REGESTRATION NUMBER"<<endl;
                cout<<"\t\t*********************\n";
                cout<<"\t\t";
                cin.getline(reg1,20);
                fstream reg_check("student_data/class 11/student_reg.txt",ios::in);
                while(!reg_check.eof())
                {
                    reg_check.getline(reg2,25);
                    ord++;
                    if(strcmp(reg1,reg2)==0)
                    {
                        order_reg=ord;
                    }
                    else
                    {
                        ;
                    }
                }
                    reg_check.close();
                    ord=0,tries=5;
                    if(ord_reg_check==order_reg)
                    {
                        system("cls");
                        cout<<"PLEASE WAIT...";
                        this_thread::sleep_for(2*dura);
                        z:ord=0;
                        srand(time(0));
                        ran=(rand()%10);
                        ran=ran+1;
                        system("cls");
                        cout<<"\n\t\t***************************\n";
                        cout<<"\t\t     SECURITY QUESTION"<<endl;
                        fstream quest("student_data/class 11/q.txt",ios::in);
                        while(!quest.eof())
                        {
                            ord++;
                            quest.getline(qus,100);
                            if(ord==ran)
                            {
                                cout<<"\t\t   "<<qus;
                                cout<<"\n\t\t***************************\n";
                                cin.getline(ans,100);
                            }
                            else
                            {
                                ;
                            }
                        }
                        quest.close();
                        ord=0;
                        if(order_reg==1)
                        {
                            fstream ans_1("student_data/class 11/a1.txt",ios::in);
                            while(!ans_1.eof())
                            {
                                ord++;
                                ans_1.getline(ans1,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans1,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 11201";
                                    present_11[0]=11201;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_1.close();
                        }
                        else if(order_reg==2)
                        {
                             fstream ans_2("student_data/class 11/a2.txt",ios::in);
                            while(!ans_2.eof())
                            {
                                ord++;
                                ans_2.getline(ans2,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans2,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 11202";
                                    present_11[1]=11202;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_2.close();
                        }
                        else
                        {
                             fstream ans_3("student_data/class 11/a3.txt",ios::in);
                            while(!ans_3.eof())
                            {
                                ord++;
                                ans_3.getline(ans3,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans3,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 11203";
                                    present_11[2]=11203;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_3.close();
                        }
                    }
                    else
                    {
                        system("cls");
                        cout<<"REGESTRATION NUMBER NOT MATCHED";
                        this_thread::sleep_for(2*dura);
                        system("cls");
                        retry();
                        goto d;
                    }
            }
            rep++;
        }

         else
        {
            if(rep!=0)
            {
                retake=0;
            }
            else{
                    ;
                }
            cout<<"\n\t\t****************************\n";
            cout<<"\t\t\t   CLASS 12\n\t\t\t   STUDENTS\n";
            tries=5;
            d2:ord=0;order_reg=0;
             cout<<"\t\t******************************\n";
            cout<<"\t\tENTER YOUR REGISTRATION NUMBER";
            cout<<"\n\t\t******************************\n";
            cout<<"\t\t";
            if(retake!=0)
                {
                    cin.ignore();
                }
            cin.getline(reg1,20);
            fstream reg_check("student_data/class 12/student_reg.txt",ios::in);
            while(!reg_check.eof())
            {
                reg_check.getline(reg2,25);
                ord++;
                if(strcmp(reg1,reg2)==0)
                {
                    order_reg=ord;
                }
                else
                {
                    ;
                }
            }
            reg_check.close();
            if(order_reg==0)
            {
                system("cls");
                cout<<"REGESTRATION NUMBER NOT FOUND \n";
                this_thread::sleep_for(2*dura);
                retry();
                goto d2;
            }
            else
            {
                system("cls");
                ord_reg_check=order_reg;
                order_reg=0;
                ord=0;
                cout<<"\n\t\t*********************\n";
                cout<<"\t\tFOR RE-CONFIRMATION"<<endl;
                cout<<"\t   ENTER YOUR REGESTRATION NUMBER"<<endl;
                cout<<"\t\t*********************\n";
                cout<<"\t\t";
                cin.getline(reg1,20);
                fstream reg_check("student_data/class 12/student_reg.txt",ios::in);
                while(!reg_check.eof())
                {
                    reg_check.getline(reg2,25);
                    ord++;
                    if(strcmp(reg1,reg2)==0)
                    {
                        order_reg=ord;
                    }
                    else
                    {
                        ;
                    }
                }
                    reg_check.close();
                    ord=0,tries=5;
                    if(ord_reg_check==order_reg)
                    {
                        system("cls");
                        cout<<"PLEASE WAIT...";
                        this_thread::sleep_for(2*dura);
                        z2:ord=0;
                        srand(time(0));
                        ran=(rand()%10);
                        ran=ran+1;
                        system("cls");
                        cout<<"\n\t\t***************************\n";
                        cout<<"\t\t     SECURITY QUESTION"<<endl;
                        fstream quest("student_data/class 12/q.txt",ios::in);
                        while(!quest.eof())
                        {
                            ord++;
                            quest.getline(qus,100);
                            if(ord==ran)
                            {
                                cout<<"\t\t   "<<qus;
                                cout<<"\n\t\t***************************\n";
                                cin.getline(ans,100);
                            }
                            else
                            {
                                ;
                            }
                        }
                        quest.close();
                        ord=0;
                        if(order_reg==1)
                        {
                            fstream ans_1("student_data/class 12/a1.txt",ios::in);
                            while(!ans_1.eof())
                            {
                                ord++;
                                ans_1.getline(ans1,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans1,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 12201";
                                    present_12[0]=12201;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z2;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_1.close();
                        }
                        else if(order_reg==2)
                        {
                             fstream ans_2("student_data/class 12/a2.txt",ios::in);
                            while(!ans_2.eof())
                            {
                                ord++;
                                ans_2.getline(ans2,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans2,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 12202";
                                    present_12[1]=12202;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z2;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_2.close();
                        }
                        else
                        {
                             fstream ans_3("student_data/class 12/a3.txt",ios::in);
                            while(!ans_3.eof())
                            {
                                ord++;
                                ans_3.getline(ans3,100);
                            if(ord==ran)
                            {
                                if(strcmp(ans3,ans)==0)
                                {
                                    system("cls");
                                    cout<<"ATTENDANCE MARKED FOR 12203";
                                    present_12[2]=12203;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"ANSWER DO NOT MATCH";
                                    retry();
                                    goto z2;
                                }
                            }
                            else
                            {
                                ;
                            }
                            }
                            ans_3.close();
                        }
                    }
                    else
                    {
                        system("cls");
                        cout<<"REGESTRATION NUMBER NOT MATCHED";
                        this_thread::sleep_for(2*dura);
                        system("cls");
                        retry();
                        goto d2;
                    }
            }
            rep++;
        }
        retake++;
            cout<<"\n\n\t\t********************************";
            cout<<"\n\nYOU WANT TO CONTINUE (ENTER 1.TO CONTINUE 2.TO GO TO MENU ANYTHING ELSE TO EXIT)\n\n";
            cout<<"\t\t********************************\n\n";
            cin>>ch_menu;
            if(ch_menu==1)
            {
                student_entry();
            }
            else if(ch_menu==2)
            {
                system("cls");
                menu();
            }
            else
            {
            system("cls");
            cout<<"EXITING";
            chrono::seconds dura(2);
            this_thread::sleep_for(1*dura);
            exit(0);
            }
    }
    }ob;
main()
{
    ob.menu();
    getchar();
}
