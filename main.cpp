#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <windows.h>
#include <list>
#include <time.h>
#include <math.h>
#include <cstring>
#define  Max  10
using namespace std;
int num;//总共上课的门数
string store[4][5];//用来存储
float flag[5][5];//用来储存单双周的情况
char major[20];
char username[10];
int  number;
struct project
{
    int pri;//确定优先级
    char name[60];//课程名称
    char teacher[10];//任课老师名字
    int data[2];//课程的特殊需求
    string code;//课程代号
    int period;//课程学时
    int count;//一周上课次数
    int odd_even;//是否有单双周
    bool operator == (project p)
    {
        if (p.code == code)
            return true;
        return false;
    }
};
list <project> l;



bool cmp(const project &p1,const project &p2)
{
    if (p2.pri < p1.pri)
        return true;
    return false;
}

///储存课表
void Store()
{
    FILE *fpt;
    fpt=fopen("课表.txt","w");
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|                               %s课表                                   |\n",major);
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    for(int s=0;s<2;s++)
    {
        if (s == 0)
        {
            fprintf(fpt,"\t\t\t\t\t   *单周*");
            fprintf(fpt,"                                                                  \n");
            fprintf(fpt,"\t第一节");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t第二节");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t第三节");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t第四节");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"\n\n");
            fprintf(fpt,"-----------------------------------------------------------------------------");
            fprintf(fpt,"\n\n");
            for (int i = 0 ; i < 5 ; i++)
            {
                bool tmp = true;
                switch(i)
                {
                case 0:
                    {
                        fprintf(fpt,"周一\t");
                    }break;
                case 1:
                    {
                        fprintf(fpt,"周二\t");
                    }break;
                case 2:
                    {
                        fprintf(fpt,"周三\t");
                    }break;
                case 3:
                    {
                        fprintf(fpt,"周四\t");
                    }break;
                case 4:
                    {
                        fprintf(fpt,"周五\t");
                    }break;
                }
                for (int j = 1; j < 5 && tmp; j++)
                {
                    if (flag[j][i] == 1)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        fprintf(fpt,"%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                fprintf(fpt," ");
                        }
                        fprintf(fpt,"        ");
                    }
                    else if (flag[j][i] == 4)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        fprintf(fpt,"%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                fprintf(fpt," ");
                        }
                         fprintf(fpt,"        ");
                    }
                    else if (flag[j][i] == 3)
                    {
                        string code1,code2;
                        int len = store[j - 1][i].length();
                        int k = 0;
                        while (store[j - 1][i][k] != '&')
                        {
                            code1 += store[j - 1][i][k];
                            k++;
                        }
                        k++;
                        for (; k < len;k++)
                        {
                            code2 += store[j - 1][i][k];
                        }
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == code1)
                            {
                                fprintf(fpt,"%s",it -> name);
                                if (it -> odd_even == 1)
                                {
                                    int name_len = strlen(it -> name);
                                    if(name_len + 4 < Max)
                                    {
                                        for(int i = 0;i < Max - name_len - 4;i++)
                                            fprintf(fpt," ");
                                    }
                                    fprintf(fpt,"        ");
                                }
                            }
                            it++;
                        }
                    }
                    else
                    {
                        for(int i = 0;i < Max;i++)
                            fprintf(fpt," ");
                        fprintf(fpt,"        ");
                    }
                }
                fprintf(fpt,"\n\n");
            }
            fprintf(fpt,"------------------------------------------------------------------------------\n");
        }

        else
        {
            fprintf(fpt,"\t\t\t\t   *双周*");
            fprintf(fpt,"                                                                  \n");
            fprintf(fpt,"\t第一节");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"第二节");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"第三节");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"第四节");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"\n\n");
            fprintf(fpt,"-----------------------------------------------------------------------------");
            fprintf(fpt,"\n\n");

            for (int i = 0 ; i < 5 ; i++)
            {
                bool tmp = true;
                switch(i)
                {
                case 0:
                    {
                        fprintf(fpt,"周一\t");
                    }break;
                case 1:
                    {
                        fprintf(fpt,"周二\t");
                    }break;
                case 2:
                    {
                        fprintf(fpt,"周三\t");
                    }break;
                case 3:
                    {
                        fprintf(fpt,"周四\t");
                    }break;
                case 4:
                    {
                        fprintf(fpt,"周五\t");
                    }break;
                }
                for (int j = 1; j < 5 && tmp; j++)
                {

                    if (flag[j][i] == 2)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        fprintf(fpt,"%s",it -> name);
                        if(name_len  < Max)
                        {
                            for(int i = 0 ;i < Max - name_len ;i++)
                                fprintf(fpt," ");
                        }
                         fprintf(fpt,"        ");
                    }
                    else if (flag[j][i] == 4)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        fprintf(fpt,"%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                fprintf(fpt," ");
                        }
                         fprintf(fpt,"        ");
                    }
                    else if (flag[j][i] == 3)
                    {
                        string code1,code2;
                        int len = store[j - 1][i].length();
                        int k = 0;
                        while (store[j - 1][i][k] != '&')
                        {
                            code1 += store[j - 1][i][k];
                            k++;
                        }
                        k++;
                        for (; k < len;k++)
                        {
                            code2 += store[j - 1][i][k];
                        }
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                             if (it -> code == code2)
                            {
                                fprintf(fpt,"%s",it -> name);
                                if(it -> odd_even == 1)
                                {
                                    int name_len = strlen(it -> name);
                                    if(name_len + 4 < Max)
                                    {
                                        for(int i = 0 ;i < Max - name_len - 4;i++)
                                            fprintf(fpt," ");
                                    }
                                    fprintf(fpt,"        ");
                                }
                            }
                            it++;
                        }
                    }
                    else
                    {
                        for(int i = 0;i < Max;i++)
                            fprintf(fpt," ");
                        fprintf(fpt,"        ");
                    }
                }
                fprintf(fpt,"\n\n");
            }
            fprintf(fpt,"------------------------------------------------------------------------------\n");
        }
    }
    fclose(fpt);
}


///向课程储存文件中排课
void SetSchedule(project *it)
{
    if ((it -> data[0] && (it -> data[1] > 10)) || ((it -> period == 96 || it -> period == 80) && it -> data[1] > 10))//给确定了哪天而又确定哪一节
    {
        if (it -> period == 96 || it -> period == 80)
        {
            int day = 1;
            int fday = 2 * (rand() % 3) + 1;
            while (true && day != 7)
            {
                int lesson = ((it -> data[1]) / 10 + 1 ) / 2;
                if (flag[0][day - 1] != 4)
                {
                    ///必须可以安排
                    flag[lesson][day - 1] = 4;
                    store[lesson - 1][day - 1] = it -> code;
                    flag[0][day - 1]++;
                    day += 2;
                }
                if (day == fday && it -> period == 80)
                {
                    flag[lesson][day - 1] = it ->odd_even;
                    flag[0][day - 1] -= (it -> odd_even == 1) ? 0.8 : 0.2;
                }
            }
        }
        else
        {
            while (true)
            {
                int lesson = ((it -> data[1]) / 10 + 1 ) / 2;
                int day = it -> data[0];
                if (flag[0][day - 1] != 4)
                {
                    ///如果可以安排
                    if (flag[lesson][day - 1] == 0)
                    {
                        if (!it -> odd_even)
                        {
                            flag[lesson][day - 1] = 4;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1]++;
                        }
                        else
                        {
                            flag[lesson][day - 1] = it -> odd_even;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1] -= (it -> odd_even == 1 ? 0.8:0.2);
                        }
                        break;
                    }
                    ///如果已经安排了单双周都上的课程
                    else if (flag[lesson][day - 1] == 4 || flag[lesson][day - 1] == 3)
                    {
                        printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                        printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                    ///如果安排了双周上课
                    else if (flag[lesson][day - 1] == 2)
                    {
                        if (it -> odd_even == 2 || !it -> odd_even)
                        {
                            printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                            printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                            scanf("%d%d",&it -> data[0],&it -> data[1]);
                        }
                        else
                        {
                            flag[lesson][day - 1] += 1;
                            store[lesson - 1][day - 1] += '&';
                            store[lesson - 1][day - 1] += it -> code;
                            flag[0][day - 1] += 0.2;
                            break;
                        }
                    }
                    ///如果安排了单周上课
                    else
                    {
                        if (it -> odd_even == 1 || !it -> odd_even)
                        {
                            printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                            printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                            scanf("%d%d",&it -> data[0],&it -> data[1]);
                        }
                        else
                        {
                            flag[lesson][day - 1] += 2;
                            store[lesson - 1][day - 1] += '&';
                            store[lesson - 1][day - 1] += it -> code;
                            flag[0][day - 1] += 0.8;
                            break;
                        }
                    }
                }
                else
                {
                    printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                    printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                    scanf("%d%d",&it -> data[0],&it -> data[1]);
                }
            }
        }
    }///指定了哪一天的哪一节课

    ///给确定了哪天并指定了上午或者下午
    else if ((it -> data[0] && (it -> data[1] > 0)) || ((it -> period == 96 || it -> period == 80) && it -> data[1] > 0))
    {
        if (it -> period == 96 || it -> period == 80)
        {
            int day = 1;
            int fday = 2 * (rand() % 3) + 1;
            while (true && day != 7)
            {
                int lesson = 2 * (it -> data[1]) - 1;
                lesson += rand() % 2;
                if (flag[0][day - 1] != 4 && (day == 1 || day == 3 || day == 5))
                {
                    ///如果可以安排
                    if (flag[lesson][day - 1] == 0)
                    {
                        if (!it -> odd_even)
                        {
                            flag[lesson][day - 1] = 4;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1]++;
                            day += 2;
                        }
                    }
                    if (day == fday && it -> period == 80)
                    {
                        flag[lesson][day - 1] = it ->odd_even;
                        flag[0][day - 1] -= (it -> odd_even == 1) ? 0.8 : 0.2;
                    }
                }///if
             }///while
        }
        else
        {
            while (true)
            {
                int lesson = 2 * (it -> data[1]) - 1;
                lesson += (rand() % 5) % 5;
                int day = it -> data[0];
                if (flag[0][day - 1] != 4)
                {
                    ///如果可以安排
                    if (flag[lesson][day - 1] == 0)
                    {
                        if (!it -> odd_even)
                        {
                            flag[lesson][day - 1] = 4;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1]++;
                        }
                        else if (it -> odd_even == 2)
                        {
                            flag[lesson][day - 1] = 2;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1] += 0.8;
                        }
                        else
                        {
                            flag[lesson][day - 1] = 1;
                            store[lesson - 1][day - 1] = it -> code;
                            flag[0][day - 1] += 0.2;
                        }
                        break;
                    }

                    ///如果上午已经安排了单双周都上的课程
                    else if ((flag[lesson][day - 1] == 4 || flag[lesson][day - 1] == 3) && (flag[lesson + 1][day - 1] == 4 || flag[lesson + 1][day - 1] == 3))
                    {
                        printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                        printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                    ///再看第一节是否符合要求
                    else if (flag[lesson][day - 1] == 2 && it -> odd_even == 1)
                    {
                        flag[lesson][day - 1] += 1;
                        store[lesson - 1][day - 1] += '&';
                        store[lesson - 1][day - 1] += it -> code;
                        flag[0][day - 1] += 0.2;
                        break;
                    }
                    ///再看第一节课
                    else if (flag[lesson][day - 1] == 1 && it -> odd_even == 2)
                    {
                        flag[lesson][day - 1] += 2;
                        store[lesson - 1][day - 1] += '&';
                        store[lesson - 1][day - 1] += it -> code;
                        flag[0][day - 1] += 0.8;
                        break;
                    }
                    ///再看第二节
                    else if (flag[lesson + 1][day - 1] == 2 && it -> odd_even == 1)
                    {
                        flag[lesson + 1][day - 1] += 1;
                        store[lesson][day - 1] += '&';
                        store[lesson][day - 1] += it -> code;
                        flag[0][day - 1] += 0.2;
                        break;
                    }
                    ///再看第二节课
                    else if (flag[lesson + 1][day - 1] == 1 && it -> odd_even == 2)
                    {
                        flag[lesson + 1][day - 1] += 2;
                        store[lesson][day - 1] += '&';
                        store[lesson][day - 1] += it -> code;
                        flag[0][day - 1] += 0.8;
                        break;
                    }
                    else
                    {
                        printf("您对%s要求的安排与其他课程有冲突,请重新输入：",it -> name);
                        printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午  2.仅要求下午]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                }///是否少于四节课
            }///是否安排好课程
        }
    }///指定了哪一天的上午或者下午

    ///仅指定了哪一天，肯定能安排上
    else if ((it -> data[0] && !it -> data[1]) || it -> period == 96 || it -> period == 80)
    {
        ///一周三节课
        if (it -> period == 96 || it -> period == 80)
        {
            int day = 1;
            while(true)
            {
                int lesson = (rand() % 4) + 1;
                ///如果可以排课
                if (flag[lesson][day - 1] == 0)
                {
                    flag[lesson][day - 1] = 4;
                    store[lesson - 1][day - 1] = it -> code;
                    flag[0][day - 1]++;
                    if (day != 5)
                        day += 2;
                    else if (day == 5 && it -> period == 80)
                    {
                        flag[lesson][day - 1] = it -> odd_even;
                        break;
                    }
                    else
                        break;
                }
                else
                    continue;
            }
        }
        ///一周一节课
        else
        {
            int day = it -> data[0];
            while(true)
            {
                int lesson = (rand() % 4) + 1;
                ///如果可以排课
                if (flag[lesson][day - 1] == 0)
                {
                    if (it -> odd_even == 0)
                    {
                        flag[lesson][day - 1] = 4;
                        store[lesson - 1][day - 1] = it -> code;
                        flag[0][day - 1]++;
                    }
                    else if (it -> odd_even == 1)
                    {
                        flag[lesson][day - 1] += 1;
                        store[lesson - 1][day - 1] = it -> code;
                        flag[0][day - 1] += 0.2;
                    }
                    else
                    {
                        flag[lesson][day - 1] += 2;
                        store[lesson - 1][day - 1] = it -> code;
                        flag[0][day - 1] += 0.8;
                    }
                    break;
                }
                else if (it -> odd_even == 1 && flag[lesson][day - 1] == 2)
                {
                    flag[lesson][day - 1] += 1;
                    store[lesson - 1][day - 1] += '&';
                    store[lesson - 1][day - 1] = it -> code;
                    flag[0][day - 1] += 0.2;
                    break;
                }
                else if (it -> odd_even == 2 && flag[lesson][day - 1] == 1)
                {
                    flag[lesson][day - 1] += 2;
                    store[lesson - 1][day - 1] += '&';
                    store[lesson - 1][day - 1] += it -> code;
                    flag[0][day - 1] += 0.8;
                    break;
                }
                else
                    continue;
            }

        }
    }///仅仅指定了哪一天

    ///仅仅指定了哪一节
    else if (!it -> data[0] && it -> data[1] > 10)
    {
        int lesson = (it -> data[1] / 10 + 1) / 2;
        int day1,day2;
        if (it -> period == 64 || it -> period == 48)
        {
            while (true)
            {
                day1 = (rand() % 5) + 1;
                day2 = (rand() % 5) + 1;
                if (fabs(day1 - day2) > 1)
                {
                    if (flag[lesson][day1 - 1] == 0 && flag[lesson][day2 - 1] == 0)
                    {
                        flag[lesson][day1 -1] = 4;
                        flag[lesson][day2 -1] = 4;
                        store[lesson - 1][day1 - 1] = it -> code;
                        store[lesson - 1][day2 - 1] = it -> code;
                        flag[0][day1 - 1]++;
                        flag[0][day2 - 1]++;
                        break;
                    }
                }
            }
            if (it -> period == 48)
            {
                int sele = (rand() % 2);
                if (sele)
                {
                    flag[lesson][day1 - 1] = it -> odd_even;
                    flag[0][day1 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
                else
                {
                    flag[lesson][day2 - 1] = it -> odd_even;
                    flag[0][day2 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
            }
        }
        else
        {
            int day;
            while (true)
            {
                day = (rand() % 5) + 1;
                if (flag[lesson][day - 1] == 0)
                {
                    flag[lesson][day -1] = 4;
                    store[lesson - 1][day - 1] = it -> code;
                    flag[0][day - 1]++;
                    break;
                }
            }
            if (it -> period == 16)
            {
                flag[lesson - 1][day - 1] = it -> odd_even;
                flag[0][day - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
            }
        }
    }///仅仅指定了哪一节课

    ///仅仅指定了是上午还是下午
    else if (!it -> data[0] && it -> data[1] > 0)
    {
        int lesson1,lesson2;
        int day1,day2;
        if (it -> period == 64 || it -> period == 48)
        {
            int lesson = 2 * (it -> data[1]) - 1;
            while (true)
            {
                day1 = (rand() % 5) + 1;
                day2 = (rand() % 5) + 1;
                lesson1 = (rand() % 4) + 1;
                lesson2 = (rand() % 4) + 1;
                if (fabs(day1 - day2) > 1 && (lesson1 == lesson || lesson1 == lesson + 1) && (lesson2 == lesson || lesson2 == lesson + 1))
                {
                    if (flag[lesson1][day1 - 1] == 0 && flag[lesson2][day2 - 1] == 0)
                    {
                        flag[lesson1][day1 -1] = 4;
                        flag[lesson2][day2 -1] = 4;
                        store[lesson1 - 1][day1 - 1] = it -> code;
                        store[lesson2 - 1][day2 - 1] = it -> code;
                        flag[0][day1 - 1]++;
                        flag[0][day2 - 1]++;
                        break;
                    }
                }
            }
            if (it -> period == 48)
            {
                int sele = (rand() % 2);
                if (sele)
                {
                    flag[lesson1][day1 - 1] = it -> odd_even;
                    flag[0][day1 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
                else
                {
                    flag[lesson2][day2 - 1] = it -> odd_even;
                    flag[0][day2 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
            }
        }
        else
        {
            int lesson = 2 * (it -> data[1]) - 1;
            while (true)
            {
                day1 = (rand() % 5) + 1;
                lesson1 = (rand() % 4) + 1;
                if (flag[lesson1][day1 - 1] == 0 && (lesson1 == lesson || lesson1 == lesson + 1))
                {
                    flag[lesson1][day1 -1] = 4;
                    store[lesson1 - 1][day1 - 1] = it -> code;
                    flag[0][day1 - 1]++;
                    break;
                }
            }
            if (it -> period == 16)
            {
                flag[lesson1 - 1][day1 - 1] = it -> odd_even;
                flag[0][day1 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
            }
        }
    }///仅仅指定了上午还是下午

    ///什么都没指定
    else
    {
        int lesson1,lesson2;
        int day1,day2;
        if (it -> period == 64 || it -> period == 48)
        {
            while (true)
            {
                day1 = (rand() % 5) + 1;
                day2 = (rand() % 5) + 1;
                lesson1 = (rand() % 4) + 1;
                lesson2 = (rand() % 4) + 1;
                if (fabs(day1 - day2) > 1 )
                {
                    if (flag[lesson1][day1 - 1] == 0 && flag[lesson2][day2 - 1] == 0)
                    {
                        flag[lesson1][day1 -1] = 4;
                        flag[lesson2][day2 -1] = 4;
                        store[lesson1 - 1][day1 - 1] = it -> code;
                        store[lesson2 - 1][day2 - 1] = it -> code;
                        flag[0][day1 - 1]++;
                        flag[0][day2 - 1]++;
                        break;
                    }
                }
            }
            if (it -> period == 48)
            {
                int sele = (rand() % 2);
                if (sele)
                {
                    flag[lesson1][day1 - 1] = it -> odd_even;
                    flag[0][day1 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
                else
                {
                    flag[lesson2][day2 - 1] = it -> odd_even;
                    flag[0][day2 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
                }
            }
        }
        else
        {
            while (true)
            {
                day1 = (rand() % 5) + 1;
                lesson1 = (rand() % 4) + 1;
                if (flag[lesson1][day1 - 1] == 0)
                {
                    flag[lesson1][day1 -1] = 4;
                    store[lesson1 - 1][day1 - 1] = it -> code;
                    flag[0][day1 - 1]++;
                    break;
                }
            }
            if (it -> period == 16)
            {
                flag[lesson1 - 1][day1 - 1] = it -> odd_even;
                flag[0][day1 - 1] -= (it -> odd_even == 1 ? 0.8 :0.2 );
            }
        }
    }
}


///新建一个课表
void CreateSchedule()
{
    printf("-----------------------------欢迎进入创建课程系统-----------------------------\n");
    l.clear();
    memset(flag,0,sizeof(flag));//初始化状态现在还没有存任何的信息
    flag[3][1] = 4;
    flag[4][1] = 4;
    printf("请输入专业名称:");
    scanf("%s",major);
    printf("请输入%s专业本学期的课程总数:",major);
    scanf("%d",&num);

    for (int i = 0;i<num;i++)
    {
        project p;
        p.pri = 0;
        printf("\n-----------------现在将添加第%d个课程-----------------\n", i + 1);
        int Sel = 1;
        while (Sel)
        {
            printf("请输入该课程的代号:");
            cin >> p.code;

            printf("请输入该课程的名称:");
            scanf("%s",p.name);

            printf("请输入该课程的任课老师:");
            scanf("%s",p.teacher);

            printf("请输入该课程的学时(注：16的奇数倍有单双周之分):");
            scanf("%d",&p.period);

            p.pri += (p.period / 16);//优先级相加
            p.count = (p.period + 16) / 32;//一周上多少节课,不分单双周

            //单双周
            if ( (p.period / 32) == (p.period - 16) / 32)
            {
                int select;
                printf("您所要创建的课程需要有单双周安排，是否自己确定？\n");
                printf("请输入您的选择[1.自己确定 2.随机确定]:");
                scanf("%d",&select);
                while (select != 1 && select != 2)
                {
                    printf("输入有误，请重新输入:");
                    scanf("%d",&select);
                }
                switch (select)
                {
                case 1://自己设定单双周
                    {
                        printf("请输入您的选择的代号[1.单周 2.双周]:");
                        scanf("%d",&p.odd_even);
                    }break;
                case 2://随机生成单双周
                    {
                        srand(time(NULL));
                        p.odd_even = (rand() % 2) + 1;
                    }break;
                }
            }
            else
            {
                p.odd_even = 0;//单双周都要上课
            }

            //特殊要求
            int option;
            printf("对上课时间有没有什么特殊要求？\n");
            printf("请输入您的选择[1.指定时间段上课  2.没有要求]:");
            scanf("%d",&option);
            while (option != 1 && option != 2)
            {
                printf("输入有误,请重新输入:");
                scanf("%d",&option);
            }
            p.data[0] = 0;
            p.data[1] = 0;
            if (option == 1)
            {
                printf("输入格式：星期 上课时间[0.无特殊要求  1.仅要求上午   2.仅要求下午]\n");
                printf("例如指定第一二节而未指定哪天，输入0 12(请不要指定周二下午的课程)\n");
                printf("请输入指定时间:");
                scanf("%d%d",&p.data[0],&p.data[1]);
                if (p.data[0] && (p.data[1] > 10))//指定了哪一天的哪一节
                {
                    p.pri += 15;
                }
                else if (p.data[0] && p.data[1])//指定了哪一天的上午或者下午
                {
                    p.pri += 14;
                }
                else if ( (p.data[0] && !p.data[1]) || (p.period == 96) || (p.period == 80))//指定了哪一天
                {
                    p.pri += 13;
                }
                else if (!p.data[0] && p.data[1] > 10)//未指定哪一天但指定了哪一节
                {
                    p.pri += 10;
                }
                else if (!p.data[0] && p.data[1])//未指定哪一天但指定了上午还是下午
                {
                    p.pri += 9;
                }
            }
            printf("请确定输入信息无误并且无重复课程[1.重新输入   0.继续]：");
            scanf("%d",&Sel);
        }
        l.push_back(p);
    }
    l.sort(cmp);
    while (true)
    {
        printf("\n--------------接下来输出将要排课的先后顺序--------------\n");
        list<project>::iterator it;
        for(it=l.begin();it!=l.end();it++)
        {
            printf("%s",it -> name);
            printf("\n");
        }
        printf("是否同意排课顺序？\n");
        printf("[1.同意  0.不同意]:");
        int opt;
        scanf("%d",&opt);
        if (!opt)
        {
            printf("\n请输入需要调整的两个课程的代号(两个代号之间用空格隔开):\n");
            while (true)
            {
                string code1,code2;
                bool flg1 = false,flg2 = false;
                cin >> code1 >> code2;
                list<project>::iterator it1;
                list<project>::iterator it2;
                list<project>::iterator it3;
                for(it3=l.begin();it3!=l.end();it3++)
                {
                    if (it3 -> code == code1)
                    {
                        it1 = it3;
                        flg1 = true;
                    }
                    else if (it3 -> code == code2)
                    {
                        it2 = it3;
                        flg2 = true;
                    }
                }
                if (flg2 && flg1)
                {
                    l.insert(it1,*it2);
                    l.insert(it2,*it1);
                    l.erase(it1);
                    l.erase(it2);
                    break;
                }
                else
                {
                    printf("请输入正确的代号:");
                    cin >> code1 >> code2;
                }
            }
        }
        else
        {
            break;
        }
    }
    system("pause");
    system("cls");//清屏
    printf("-------------现在将进行随机进行排课-----------\n");
    list<project>::iterator it;
    for (it = l.begin(); it != l.end();it++)
    {
        project ir;
        ir = *it;
        SetSchedule(&ir);
        printf("%s已排好.\n",it -> name);
        system("pause");
    }
    printf("-------------------排课完成!------------------\n");
    system("pause");
}


///打印课表
void Print()
{
    for(int s=0;s<2;s++)
    {
        if(s==0)
        {
            printf("\t\t\t\t   *单周*");
            printf("                                                                  \n");
            printf("\t第一节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第二节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第三节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第四节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("\n\n");
            printf("-----------------------------------------------------------------------------");
            printf("\n\n");

            for (int i = 0 ; i < 5 ; i++)
            {
                bool tmp = true;
                switch(i)
                {
                case 0:
                    {
                        printf("周一\t");
                    }break;
                case 1:
                    {
                        printf("周二\t");
                    }break;
                case 2:
                    {
                        printf("周三\t");
                    }break;
                case 3:
                    {
                        printf("周四\t");
                    }break;
                case 4:
                    {
                        printf("周五\t");
                    }break;
                }
                for (int j = 1; j < 5 && tmp; j++)
                {
                    if (flag[j][i] == 1)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        printf("%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                printf(" ");
                        }
                        printf("        ");
                    }
                    else if (flag[j][i] == 4)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        printf("%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                printf(" ");
                        }
                         printf("        ");
                    }
                    else if (flag[j][i] == 3)
                    {
                        string code1,code2;
                        int len = store[j - 1][i].length();
                        int k = 0;
                        while (store[j - 1][i][k] != '&')
                        {
                            code1 += store[j - 1][i][k];
                            k++;
                        }
                        k++;
                        for (; k < len;k++)
                        {
                            code2 += store[j - 1][i][k];
                        }
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == code1)
                            {
                                printf("%s",it -> name);
                                if (it -> odd_even == 1)
                                {
                                    int name_len = strlen(it -> name);
                                    if(name_len + 4 < Max)
                                    {
                                        for(int i = 0;i < Max - name_len - 4;i++)
                                            printf(" ");
                                    }
                                    printf("        ");
                                }
                            }
                            it++;
                        }
                    }
                    else
                    {
                        for(int i = 0;i < Max;i++)
                            printf(" ");
                        printf("        ");
                    }
                }
                printf("\n\n");
            }
            printf("------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\t\t\t\t   *双周*");
            printf("                                                                  \n");
            printf("\t第一节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第二节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第三节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("第四节");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("\n\n");
            printf("-----------------------------------------------------------------------------");
            printf("\n\n");

            for (int i = 0 ; i < 5 ; i++)
            {
                bool tmp = true;
                switch(i)
                {
                case 0:
                    {
                        printf("周一\t");
                    }break;
                case 1:
                    {
                        printf("周二\t");
                    }break;
                case 2:
                    {
                        printf("周三\t");
                    }break;
                case 3:
                    {
                        printf("周四\t");
                    }break;
                case 4:
                    {
                        printf("周五\t");
                    }break;
                }
                for (int j = 1; j < 5 && tmp; j++)
                {

                    if (flag[j][i] == 2)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        printf("%s",it -> name);
                        if(name_len  < Max)
                        {
                            for(int i = 0 ;i < Max - name_len ;i++)
                                printf(" ");
                        }
                         printf("        ");
                    }
                    else if (flag[j][i] == 4)
                    {
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                            if (it -> code == store[j - 1][i])
                                break;
                            else
                                it++;
                        }
                        int name_len = strlen(it -> name);
                        printf("%s",it -> name);
                        if(name_len < Max)
                        {
                            for(int i = 0;i < Max - name_len ;i++)
                                printf(" ");
                        }
                         printf("        ");
                    }
                    else if (flag[j][i] == 3)
                    {
                        string code1,code2;
                        int len = store[j - 1][i].length();
                        int k = 0;
                        while (store[j - 1][i][k] != '&')
                        {
                            code1 += store[j - 1][i][k];
                            k++;
                        }
                        k++;
                        for (; k < len;k++)
                        {
                            code2 += store[j - 1][i][k];
                        }
                        list<project>::iterator it;
                        it = l.begin();
                        while (it != l.end())
                        {
                             if (it -> code == code2)
                            {
                                printf("%s",it -> name);
                                if(it -> odd_even == 1)
                                {
                                    int name_len = strlen(it -> name);
                                    if(name_len + 4 < Max)
                                    {
                                        for(int i = 0 ;i < Max - name_len - 4;i++)
                                            printf(" ");
                                    }
                                    printf("        ");
                                }
                            }
                            it++;
                        }
                    }
                    else
                    {
                        for(int i = 0;i < Max;i++)
                            printf(" ");
                        printf("        ");
                    }
                }
                printf("\n\n");
            }
            printf("------------------------------------------------------------------------------\n");
        }
    }
}
///修改课程表
void ReviseProject()
{
    printf("********************课表修改菜单*****************************\n");
    printf("*******************1.删除课程************************************\n");
    printf("*******************2.添加课程************************************\n");
    int opv,pc;//判断输入字符的
    printf("请输入您要进行的操作的代号:");
    scanf("%d",&opv);
    while (opv != 1 && opv != 2)
            {
                printf("您输入有误请重新输入您的选择:");
                scanf("%d",&opv);
            }
    if(opv == 1)
    {
        string code1,code2,code3;
        int i,j,jk[3],t[3],s = 1,le;//k是课，t是天，s是一共几节课，le是记录要删除第几节
        printf("请输入要删除的课程的代码：（必须是已经存在的课程的代号）");
        list<project>::iterator it;
        while(true)
        {
            cin>>code1;
            bool tag = false;
            it = l.begin();
            while (it != l.end())
            {
               if (it -> code == code1)
               {
                   tag = true;
                   break;
               }
               else
                   it++;
           }
           if(!tag)
           {
               printf("没有这门课，请重新输入课程代号：\n");
           }
           else
               break;
        }
        printf("这门课在  ");
        for(j = 0;j < 5;j++)
        for(i = 0;i < 4;i++)
        {
             if(flag[i + 1][j] == 4)
             {
                 if(store[i][j] == code1)
                 {
                    printf("周%d第%d%d节  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                 }
             }
             else if(flag[i + 1][j] == 1)
             {
                 if(store[i][j] == code1)
                 {
                    printf("周%d第%d%d节（单）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
             }
             else if(flag[i + 1][j] == 2)
             {
                 if(store[i][j] == code1)
                 {
                    printf("周%d第%d%d节（双）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
             }
             else if(flag[i + 1][j] == 3)
             {
                int len = store[i][j].length(),k = 0;
                while (store[i][j][k] != '&')
                {
                    code2 += store[i][j][k];
                    k++;
                }
                k++;
                while (k < len)
                {
                    code3 += store[i][j][k];
                    k ++;
                }
                if(code3 == code1)
                {
                    if(it -> odd_even == 1)
                    printf("周%d第%d%d节（单）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    else if(it -> odd_even == 2)
                    printf("周%d第%d%d节（双）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
                else if(code2 == code1)
                {
                    if(it -> odd_even == 1)
                    printf("周%d第%d%d节（单）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    else if(it -> odd_even == 2)
                    printf("周%d第%d%d节（双）  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
             }
        }
        printf("有课。\n   要删除第几节？");
        scanf("%d",&le);
        s--;
        while(le > s || le <= 0)
        {
            printf("输入错，请重新输入！");
            scanf("%d",&le);
        }
        printf("是否确认删除？ 确认1 取消0 : ");
        scanf("%d",&pc);
        while (pc != 1 && pc != 0)
            {
                printf("您输入有误请重新输入您的选择:");
                scanf("%d",&pc);
            }
        if(pc == 1)
        {
            if(flag[jk[le] + 1][t[le]] != 3)
            {
                store[jk[le]][t[le]] = "";
                flag[jk[le] + 1][t[le]] = 0;
                if(flag[jk[le] + 1][t[le]] == 2 || flag[jk[le] + 1][t[le]] == 1)
                    {
                        it -> period -= 16;
                        it -> odd_even = 0;
                    }
                else
                    it -> period -= 32;
                printf("*********删除成功！**********\n");
            }
            else
            {
                if(code3 == code1)
                {
                    store[jk[le]][t[le]] = code2;
                    if(it -> odd_even == 1)
                    {
                        flag[jk[le] + 1][t[le]] = 2;
                        it -> odd_even = 0;
                        it -> period -= 16;
                    }
                    else if(it -> odd_even == 2)
                    {
                        flag[jk[le] + 1][t[le]] = 1;
                        it -> odd_even = 0;
                        it -> period -= 16;
                    }
                    printf("*********删除成功！**********\n");
                }
                else if(code2 == code1)
                {
                    store[jk[le]][t[le]] = code3;
                    if(it -> odd_even == 1)
                    {
                        flag[jk[le] + 1][t[le]] = 2;
                        it -> odd_even = 0;
                        it -> period -= 16;
                    }
                    else if(it -> odd_even == 2)
                    {
                        flag[jk[le] + 1][t[le]] = 1;
                        it -> odd_even = 0;
                        it -> period -= 16;
                    }
                    printf("*********删除成功！**********\n");
                }
            }
        }
        else
            printf("已经取消\n");

    }
    else if(opv == 2)
    {
        printf("请选择要 增加一门课程并随机安排:1 还是将已存在的课程添加一节到固定的时间:2\n");
        int buew;
        project p;
        string code1;//用于判断选择
        scanf("%d",&buew);
        if(buew == 1)
        {
            p.pri = 0;
            printf("\n***********现在您将对%s专业添加课程***********\n",major);
            int Sel = 1;
            while (Sel)
            {
                printf("请输入该课程的代号:");
                cin >> p.code;

                printf("请输入该课程的名称:");
                scanf("%s",p.name);

                printf("请输入该课程的任课老师:");
                scanf("%s",p.teacher);

                printf("请输入该课程的学时:");
                scanf("%d",&p.period);

                p.pri += (p.period / 16);//优先级相加
                p.count = (p.period + 16) / 32;//一周上多少节课,不分单双周

                //单双周
                if ( (p.period / 32) == (p.period - 16) / 32)
                {
                    int select;
                    printf("您所要创建的课程需要有单双周安排，是否自己确定\n");
                    printf("请输入您的选择(1代表自己确定,2代表随机确定):");
                    scanf("%d",&select);
                    while (select != 1 && select != 2)
                    {
                        printf("您输入有误请重新输入您的选择:");
                        scanf("%d",&select);
                    }
                    switch (select)
                    {
                    case 1://自己设定单双周
                        {
                            printf("请输入您的选择的代号(1代表单周，2代表双周):");
                            scanf("%d",&p.odd_even);
                        }
                    case 2://随机生成单双周
                        {
                            srand(time(NULL));
                            p.odd_even = (rand() % 2) + 1;
                        }
                    }
                }
                else
                {
                    p.odd_even = 0;//单双周都要上课
                }

                //特殊要求
                int option;
                printf("请问您对上课时间有没有什么特殊要求？\n");
                printf("请输入您的选择(1代表指定时间段上课，2代表您没有要求):");
                scanf("%d",&option);
                while (option != 1 && option != 2)
                {
                    printf("您输入有误请重新输入您的选择:");
                    scanf("%d",&option);
                }
                p.data[0] = 0;
                p.data[1] = 0;
                if (option == 1)
                {
                    printf("请输入您的指定时间(先输入周几，再输入第几节课，若无特殊要求选择0,中间用空格隔开,如果仅要求上午则用1表示，下午则用2表示)\n");
                    printf("例如指定第一二节而未指定哪天，输入0 12(请不要指定周二下午的课程)\n");
                    printf("请输入您的要求:");
                    scanf("%d%d",&p.data[0],&p.data[1]);
                    if (p.data[0] && (p.data[1] > 10))//指定了哪一天的哪一节
                    {
                        p.pri += 15;
                    }
                    else if (p.data[0] && p.data[1])//指定了哪一天的上午或者下午
                    {
                        p.pri += 14;
                    }
                    else if ( (p.data[0] && !p.data[1]) || (p.period == 96))//指定了哪一天
                    {
                        p.pri += 10;
                    }
                    else if (!p.data[0] && p.data[1] > 10)//未指定哪一天但指定了哪一节
                    {
                        p.pri += 9;
                    }
                    else if (!p.data[0] && p.data[1])//未指定哪一天但指定了上午还是下午
                    {
                        p.pri += 8;
                    }
                }
                printf("确定输入信息无误并且无重复性课？如若要修改信息请选择1，不修改请选择0: ");
                scanf("%d",&Sel);
            }
        l.push_back(p);
        list<project>::iterator it;
        it = l.end();
        it--;
            project ir;
            ir = *it;
            SetSchedule(&ir);
            printf("现在%s已经安排好.\n",it -> name);
            system("pause");

        printf("***********排课完成!!***********\n");
    }

    else if(buew == 2)
    {
        int i,j,xznz;//xznt就是选择单双周
        printf("请输入要添加的课程的代号：\n");
        list<project>::iterator it;
        while(true)
        {
            cin >> p.code;
            bool tag = false;
            it = l.begin();
            while (it != l.end())
            {
               if (it -> code == p.code)
               {
                   tag = true;
                   break;
               }
               else
                   it++;
           }
           if(!tag)
           {
               printf("没有这门课，请重新输入课程代号：\n");
           }
           else
               break;
        }
        printf("请输入要插入周几 哪节（格式：1 2即周一第二大节）（请不要添加课程到周二下午）: \n");
        scanf("%d %d",&i,&j);
        printf("是否设置单双周（不设置：0 单周上课：1 双周上课：2）：");
        scanf("%d",&xznz);
        while (xznz != 1 && xznz != 2 && xznz != 0)
            {
                printf("您输入有误请重新输入您的选择:");
                scanf("%d",&xznz);
            }
        if(flag[j][i-1]==0&&xznz==0)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=4;
                it->period+=32;
                printf("******插入成功！******\n");
            }
        else if(flag[j][i-1]==0&&xznz==1)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=1;
                it->odd_even=1;
                it->period+=16;
                printf("******插入成功！******\n");
            }
        else if(flag[j][i-1]==0&&xznz==2)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=2;
                it->odd_even=2;
                it->period+=16;
                printf("******插入成功!******\n");
            }
        else if(flag[j][i-1]==1&&xznz==2)
            {
                code1=store[j-1][i-1];
                store[j-1][i-1]=p.code;
                store[j-1][i-1]+= '&';
                store[j-1][i-1]+=code1;
                flag[j][i-1]=3;
                it->odd_even=2;
                it->period+=16;
                printf("******插入成功!******\n");
            }
        else if(flag[j][i-1]==2&&xznz==1)
            {
                code1=store[j-1][i-1];
                store[j-1][i-1]=p.code;
                store[j-1][i-1]+= '&';
                store[j-1][i-1]+=code1;
                flag[j][i-1]=3;
                it->odd_even=1;
                it->period+=16;
                printf("******插入成功!******\n");
            }
        else
            printf("输入错 这节有课！\n");
    }
    }
    system("pause");

}
///查询信息
void Inquiry()
{
    int i,j;
    project ccp;
    string code2,code3;
    list<project>::iterator it;
    it = l.begin();
    while (it != l.end())
        {
            printf("%s-> ",it->name);
            cout<<it->code<<"\n";
            it++;
        }
    printf("请输入要查询的课程的代号:");
    while(true)
    {
        cin>>ccp.code;
        bool tag = false;
        it = l.begin();
        while (it != l.end())
        {
            if(it -> code == ccp.code)
            {
                tag=true;
                break;
            }
            else
                it++;
        }
        if(!tag)
        {
            printf("没有这门课,请重新输入\n");
        }
        else
            break;
    }
    printf("你查询的课程是：        %s\n\n",it->name);
    printf("%s的授课老师是：  %s\n\n",it->name,it->teacher);
    printf("共有%d课时 \n\n",it->period);
    printf("%s在  ",it->name);
    for(j=0;j<5;j++)
        for(i=0;i<4;i++)
        {
            if(flag[i+1][j]== 4)
            {
               if(store[i][j]==it->code)
               printf("周%d第%d%d节  ",j+1,i*2+1,i*2+2);
            }
            else if(flag[i+1][j]==1)
            {
                if(store[i][j]==it->code)
                printf("周%d第%d%d节（单）  ",j+1,i*2+1,i*2+2);
            }
            else if(flag[i+1][j]==2)
            {
                if(store[i][j]==it->code)
                printf("周%d第%d%d节（双）  ",j+1,i*2+1,i*2+2);

            }
            else if(flag[i+1][j]==3)
            {
                int len = store[i][j].length(),k = 0;
                while (store[i][j][k] != '&')
                {
                    code2 += store[i][j][k];
                    k++;
                }
                k++;
                while (k < len)
                {
                    code3 += store[i][j][k];
                    k ++;
                }
                if(code3==it->code||code2==it->code)
                {
                    if(it->odd_even==1)
                    printf("周%d第%d%d节（单）  ",j+1,i*2+1,i*2+2);
                    else if(it->odd_even==2)
                    printf("周%d第%d%d节（双）  ",j+1,i*2+1,i*2+2);

                }
            }
        }
        printf("有课。\n\n ");
        system("pause");
}
///登录界面
void log()
{

    printf("|---------------------------------------------------------------------------|\n");
    printf("|                             欢迎登录课表创建系统                          |\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("                                       登录                                  \n");
    printf("\n");
    printf("                             姓名:");
    scanf("%s",username);
    printf("                             学工号:");
    scanf("%d",&number);
    printf("\n");
    }
///显示主菜单
void menu()
{
    printf("-----------------------------------------------------------------------------\n");
    printf("▏                               课程表系统菜单                              ▏\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("▏                                 1.新建课表                                ▏\n");
    printf("▏                                 2.修改课表                                ▏\n");
    printf("▏                                 3.保存课表                                ▏\n");
    printf("▏                                 4.显示课表                                ▏\n");
    printf("▏                                 5.查询课程                                ▏\n");
    printf("▏                                 0.退出                                    ▏\n");
    printf("-----------------------------------------------------------------------------\n");
}
int main()
{
    system("color F0");
    log();
    menu();
    int select;
    srand(time(NULL));
    printf("请输入所需操作的对应代号:");
    while (scanf("%d",&select) && select)
    {
        while (select < 0 || select > 5)
        {
            printf("输入有误，请重新输入:");
            scanf("%d",&select);
        }
        switch (select)
        {
        //创建课表
        case 1:
            {
                system("cls");//清理屏幕，准备写入
                CreateSchedule();
                system("cls");//清理屏幕，准备写入
            }break;
        //修改课程表
        case 2:
            {
                system("cls");//清理屏幕，准备写入
                printf("|---------------------------------------------------------------------------|\n");
                printf("|                                                                           |\n");
                printf("|                              %s课表                                  |\n",major);
                printf("|                                                                           |\n");
                printf("|---------------------------------------------------------------------------|\n");
                ReviseProject();
                Print();
                printf("------------------------如您已经修改成功请选择保存--------------------------\n");

            }break;

        //保存课程表
        case 3:
            {
                system("cls");//清理屏幕，准备写入
                Store();
                printf("现在课表信息已经存放在“课表.txt文件中”.");
                system("pause");
                system("cls");
            }break;

        //输出一个课表
        case 4:
            {
                system("cls");//清理屏幕，准备写入
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                               %s课表                                  \n",major);
                printf("                                                                             \n");
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                  姓名：%s",username);
                printf("               学号：%d                 \n",number);
                printf("                                                                             \n");
                printf("-----------------------------------------------------------------------------\n");
                Print();
                system("pause");
            }break;
        case 5:
            {
                system("cls");
                Inquiry();
            }break;
        }
        system("cls");//清理屏幕，准备写入
        menu();
        printf("请输入所需操作的对应代号:");
    }
    printf("感谢您的使用！\n");
    system("pause");
    return 0;
}
