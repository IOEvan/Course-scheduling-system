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
int num;//�ܹ��Ͽε�����
string store[4][5];//�����洢
float flag[5][5];//�������浥˫�ܵ����
char major[20];
char username[10];
int  number;
struct project
{
    int pri;//ȷ�����ȼ�
    char name[60];//�γ�����
    char teacher[10];//�ο���ʦ����
    int data[2];//�γ̵���������
    string code;//�γ̴���
    int period;//�γ�ѧʱ
    int count;//һ���Ͽδ���
    int odd_even;//�Ƿ��е�˫��
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

///����α�
void Store()
{
    FILE *fpt;
    fpt=fopen("�α�.txt","w");
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|                               %s�α�                                   |\n",major);
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    for(int s=0;s<2;s++)
    {
        if (s == 0)
        {
            fprintf(fpt,"\t\t\t\t\t   *����*");
            fprintf(fpt,"                                                                  \n");
            fprintf(fpt,"\t��һ��");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t�ڶ���");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t������");
            for(int i = 0;i < Max - 6;i++)
                fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"\t���Ľ�");
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
                        fprintf(fpt,"��һ\t");
                    }break;
                case 1:
                    {
                        fprintf(fpt,"�ܶ�\t");
                    }break;
                case 2:
                    {
                        fprintf(fpt,"����\t");
                    }break;
                case 3:
                    {
                        fprintf(fpt,"����\t");
                    }break;
                case 4:
                    {
                        fprintf(fpt,"����\t");
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
            fprintf(fpt,"\t\t\t\t   *˫��*");
            fprintf(fpt,"                                                                  \n");
            fprintf(fpt,"\t��һ��");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"�ڶ���");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"������");
            for(int i = 0;i < Max - 6;i++)
            fprintf(fpt," ");
            fprintf(fpt,"        ");
            fprintf(fpt,"���Ľ�");
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
                        fprintf(fpt,"��һ\t");
                    }break;
                case 1:
                    {
                        fprintf(fpt,"�ܶ�\t");
                    }break;
                case 2:
                    {
                        fprintf(fpt,"����\t");
                    }break;
                case 3:
                    {
                        fprintf(fpt,"����\t");
                    }break;
                case 4:
                    {
                        fprintf(fpt,"����\t");
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


///��γ̴����ļ����ſ�
void SetSchedule(project *it)
{
    if ((it -> data[0] && (it -> data[1] > 10)) || ((it -> period == 96 || it -> period == 80) && it -> data[1] > 10))//��ȷ�����������ȷ����һ��
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
                    ///������԰���
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
                    ///������԰���
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
                    ///����Ѿ������˵�˫�ܶ��ϵĿγ�
                    else if (flag[lesson][day - 1] == 4 || flag[lesson][day - 1] == 3)
                    {
                        printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                        printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                    ///���������˫���Ͽ�
                    else if (flag[lesson][day - 1] == 2)
                    {
                        if (it -> odd_even == 2 || !it -> odd_even)
                        {
                            printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                            printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
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
                    ///��������˵����Ͽ�
                    else
                    {
                        if (it -> odd_even == 1 || !it -> odd_even)
                        {
                            printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                            printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
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
                    printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                    printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
                    scanf("%d%d",&it -> data[0],&it -> data[1]);
                }
            }
        }
    }///ָ������һ�����һ�ڿ�

    ///��ȷ�������첢ָ���������������
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
                    ///������԰���
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
                    ///������԰���
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

                    ///��������Ѿ������˵�˫�ܶ��ϵĿγ�
                    else if ((flag[lesson][day - 1] == 4 || flag[lesson][day - 1] == 3) && (flag[lesson + 1][day - 1] == 4 || flag[lesson + 1][day - 1] == 3))
                    {
                        printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                        printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                    ///�ٿ���һ���Ƿ����Ҫ��
                    else if (flag[lesson][day - 1] == 2 && it -> odd_even == 1)
                    {
                        flag[lesson][day - 1] += 1;
                        store[lesson - 1][day - 1] += '&';
                        store[lesson - 1][day - 1] += it -> code;
                        flag[0][day - 1] += 0.2;
                        break;
                    }
                    ///�ٿ���һ�ڿ�
                    else if (flag[lesson][day - 1] == 1 && it -> odd_even == 2)
                    {
                        flag[lesson][day - 1] += 2;
                        store[lesson - 1][day - 1] += '&';
                        store[lesson - 1][day - 1] += it -> code;
                        flag[0][day - 1] += 0.8;
                        break;
                    }
                    ///�ٿ��ڶ���
                    else if (flag[lesson + 1][day - 1] == 2 && it -> odd_even == 1)
                    {
                        flag[lesson + 1][day - 1] += 1;
                        store[lesson][day - 1] += '&';
                        store[lesson][day - 1] += it -> code;
                        flag[0][day - 1] += 0.2;
                        break;
                    }
                    ///�ٿ��ڶ��ڿ�
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
                        printf("����%sҪ��İ����������γ��г�ͻ,���������룺",it -> name);
                        printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������  2.��Ҫ������]\n");
                        scanf("%d%d",&it -> data[0],&it -> data[1]);
                    }
                }///�Ƿ������Ľڿ�
            }///�Ƿ��źÿγ�
        }
    }///ָ������һ��������������

    ///��ָ������һ�죬�϶��ܰ�����
    else if ((it -> data[0] && !it -> data[1]) || it -> period == 96 || it -> period == 80)
    {
        ///һ�����ڿ�
        if (it -> period == 96 || it -> period == 80)
        {
            int day = 1;
            while(true)
            {
                int lesson = (rand() % 4) + 1;
                ///��������ſ�
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
        ///һ��һ�ڿ�
        else
        {
            int day = it -> data[0];
            while(true)
            {
                int lesson = (rand() % 4) + 1;
                ///��������ſ�
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
    }///����ָ������һ��

    ///����ָ������һ��
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
    }///����ָ������һ�ڿ�

    ///����ָ���������绹������
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
    }///����ָ�������绹������

    ///ʲô��ûָ��
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


///�½�һ���α�
void CreateSchedule()
{
    printf("-----------------------------��ӭ���봴���γ�ϵͳ-----------------------------\n");
    l.clear();
    memset(flag,0,sizeof(flag));//��ʼ��״̬���ڻ�û�д��κε���Ϣ
    flag[3][1] = 4;
    flag[4][1] = 4;
    printf("������רҵ����:");
    scanf("%s",major);
    printf("������%sרҵ��ѧ�ڵĿγ�����:",major);
    scanf("%d",&num);

    for (int i = 0;i<num;i++)
    {
        project p;
        p.pri = 0;
        printf("\n-----------------���ڽ���ӵ�%d���γ�-----------------\n", i + 1);
        int Sel = 1;
        while (Sel)
        {
            printf("������ÿγ̵Ĵ���:");
            cin >> p.code;

            printf("������ÿγ̵�����:");
            scanf("%s",p.name);

            printf("������ÿγ̵��ο���ʦ:");
            scanf("%s",p.teacher);

            printf("������ÿγ̵�ѧʱ(ע��16���������е�˫��֮��):");
            scanf("%d",&p.period);

            p.pri += (p.period / 16);//���ȼ����
            p.count = (p.period + 16) / 32;//һ���϶��ٽڿ�,���ֵ�˫��

            //��˫��
            if ( (p.period / 32) == (p.period - 16) / 32)
            {
                int select;
                printf("����Ҫ�����Ŀγ���Ҫ�е�˫�ܰ��ţ��Ƿ��Լ�ȷ����\n");
                printf("����������ѡ��[1.�Լ�ȷ�� 2.���ȷ��]:");
                scanf("%d",&select);
                while (select != 1 && select != 2)
                {
                    printf("������������������:");
                    scanf("%d",&select);
                }
                switch (select)
                {
                case 1://�Լ��趨��˫��
                    {
                        printf("����������ѡ��Ĵ���[1.���� 2.˫��]:");
                        scanf("%d",&p.odd_even);
                    }break;
                case 2://������ɵ�˫��
                    {
                        srand(time(NULL));
                        p.odd_even = (rand() % 2) + 1;
                    }break;
                }
            }
            else
            {
                p.odd_even = 0;//��˫�ܶ�Ҫ�Ͽ�
            }

            //����Ҫ��
            int option;
            printf("���Ͽ�ʱ����û��ʲô����Ҫ��\n");
            printf("����������ѡ��[1.ָ��ʱ����Ͽ�  2.û��Ҫ��]:");
            scanf("%d",&option);
            while (option != 1 && option != 2)
            {
                printf("��������,����������:");
                scanf("%d",&option);
            }
            p.data[0] = 0;
            p.data[1] = 0;
            if (option == 1)
            {
                printf("�����ʽ������ �Ͽ�ʱ��[0.������Ҫ��  1.��Ҫ������   2.��Ҫ������]\n");
                printf("����ָ����һ���ڶ�δָ�����죬����0 12(�벻Ҫָ���ܶ�����Ŀγ�)\n");
                printf("������ָ��ʱ��:");
                scanf("%d%d",&p.data[0],&p.data[1]);
                if (p.data[0] && (p.data[1] > 10))//ָ������һ�����һ��
                {
                    p.pri += 15;
                }
                else if (p.data[0] && p.data[1])//ָ������һ��������������
                {
                    p.pri += 14;
                }
                else if ( (p.data[0] && !p.data[1]) || (p.period == 96) || (p.period == 80))//ָ������һ��
                {
                    p.pri += 13;
                }
                else if (!p.data[0] && p.data[1] > 10)//δָ����һ�쵫ָ������һ��
                {
                    p.pri += 10;
                }
                else if (!p.data[0] && p.data[1])//δָ����һ�쵫ָ�������绹������
                {
                    p.pri += 9;
                }
            }
            printf("��ȷ��������Ϣ���������ظ��γ�[1.��������   0.����]��");
            scanf("%d",&Sel);
        }
        l.push_back(p);
    }
    l.sort(cmp);
    while (true)
    {
        printf("\n--------------�����������Ҫ�ſε��Ⱥ�˳��--------------\n");
        list<project>::iterator it;
        for(it=l.begin();it!=l.end();it++)
        {
            printf("%s",it -> name);
            printf("\n");
        }
        printf("�Ƿ�ͬ���ſ�˳��\n");
        printf("[1.ͬ��  0.��ͬ��]:");
        int opt;
        scanf("%d",&opt);
        if (!opt)
        {
            printf("\n��������Ҫ�����������γ̵Ĵ���(��������֮���ÿո����):\n");
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
                    printf("��������ȷ�Ĵ���:");
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
    system("cls");//����
    printf("-------------���ڽ�������������ſ�-----------\n");
    list<project>::iterator it;
    for (it = l.begin(); it != l.end();it++)
    {
        project ir;
        ir = *it;
        SetSchedule(&ir);
        printf("%s���ź�.\n",it -> name);
        system("pause");
    }
    printf("-------------------�ſ����!------------------\n");
    system("pause");
}


///��ӡ�α�
void Print()
{
    for(int s=0;s<2;s++)
    {
        if(s==0)
        {
            printf("\t\t\t\t   *����*");
            printf("                                                                  \n");
            printf("\t��һ��");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("�ڶ���");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("������");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("���Ľ�");
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
                        printf("��һ\t");
                    }break;
                case 1:
                    {
                        printf("�ܶ�\t");
                    }break;
                case 2:
                    {
                        printf("����\t");
                    }break;
                case 3:
                    {
                        printf("����\t");
                    }break;
                case 4:
                    {
                        printf("����\t");
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
            printf("\t\t\t\t   *˫��*");
            printf("                                                                  \n");
            printf("\t��һ��");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("�ڶ���");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("������");
            for(int i = 0;i < Max - 6;i++)
            printf(" ");
            printf("        ");
            printf("���Ľ�");
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
                        printf("��һ\t");
                    }break;
                case 1:
                    {
                        printf("�ܶ�\t");
                    }break;
                case 2:
                    {
                        printf("����\t");
                    }break;
                case 3:
                    {
                        printf("����\t");
                    }break;
                case 4:
                    {
                        printf("����\t");
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
///�޸Ŀγ̱�
void ReviseProject()
{
    printf("********************�α��޸Ĳ˵�*****************************\n");
    printf("*******************1.ɾ���γ�************************************\n");
    printf("*******************2.��ӿγ�************************************\n");
    int opv,pc;//�ж������ַ���
    printf("��������Ҫ���еĲ����Ĵ���:");
    scanf("%d",&opv);
    while (opv != 1 && opv != 2)
            {
                printf("������������������������ѡ��:");
                scanf("%d",&opv);
            }
    if(opv == 1)
    {
        string code1,code2,code3;
        int i,j,jk[3],t[3],s = 1,le;//k�ǿΣ�t���죬s��һ�����ڿΣ�le�Ǽ�¼Ҫɾ���ڼ���
        printf("������Ҫɾ���Ŀγ̵Ĵ��룺���������Ѿ����ڵĿγ̵Ĵ��ţ�");
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
               printf("û�����ſΣ�����������γ̴��ţ�\n");
           }
           else
               break;
        }
        printf("���ſ���  ");
        for(j = 0;j < 5;j++)
        for(i = 0;i < 4;i++)
        {
             if(flag[i + 1][j] == 4)
             {
                 if(store[i][j] == code1)
                 {
                    printf("��%d��%d%d��  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                 }
             }
             else if(flag[i + 1][j] == 1)
             {
                 if(store[i][j] == code1)
                 {
                    printf("��%d��%d%d�ڣ�����  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
             }
             else if(flag[i + 1][j] == 2)
             {
                 if(store[i][j] == code1)
                 {
                    printf("��%d��%d%d�ڣ�˫��  ",j + 1,i * 2 + 1,i * 2 + 2);
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
                    printf("��%d��%d%d�ڣ�����  ",j + 1,i * 2 + 1,i * 2 + 2);
                    else if(it -> odd_even == 2)
                    printf("��%d��%d%d�ڣ�˫��  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
                else if(code2 == code1)
                {
                    if(it -> odd_even == 1)
                    printf("��%d��%d%d�ڣ�����  ",j + 1,i * 2 + 1,i * 2 + 2);
                    else if(it -> odd_even == 2)
                    printf("��%d��%d%d�ڣ�˫��  ",j + 1,i * 2 + 1,i * 2 + 2);
                    jk[s] = i;
                    t[s] = j;
                    s++;
                }
             }
        }
        printf("�пΡ�\n   Ҫɾ���ڼ��ڣ�");
        scanf("%d",&le);
        s--;
        while(le > s || le <= 0)
        {
            printf("��������������룡");
            scanf("%d",&le);
        }
        printf("�Ƿ�ȷ��ɾ���� ȷ��1 ȡ��0 : ");
        scanf("%d",&pc);
        while (pc != 1 && pc != 0)
            {
                printf("������������������������ѡ��:");
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
                printf("*********ɾ���ɹ���**********\n");
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
                    printf("*********ɾ���ɹ���**********\n");
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
                    printf("*********ɾ���ɹ���**********\n");
                }
            }
        }
        else
            printf("�Ѿ�ȡ��\n");

    }
    else if(opv == 2)
    {
        printf("��ѡ��Ҫ ����һ�ſγ̲��������:1 ���ǽ��Ѵ��ڵĿγ����һ�ڵ��̶���ʱ��:2\n");
        int buew;
        project p;
        string code1;//�����ж�ѡ��
        scanf("%d",&buew);
        if(buew == 1)
        {
            p.pri = 0;
            printf("\n***********����������%sרҵ��ӿγ�***********\n",major);
            int Sel = 1;
            while (Sel)
            {
                printf("������ÿγ̵Ĵ���:");
                cin >> p.code;

                printf("������ÿγ̵�����:");
                scanf("%s",p.name);

                printf("������ÿγ̵��ο���ʦ:");
                scanf("%s",p.teacher);

                printf("������ÿγ̵�ѧʱ:");
                scanf("%d",&p.period);

                p.pri += (p.period / 16);//���ȼ����
                p.count = (p.period + 16) / 32;//һ���϶��ٽڿ�,���ֵ�˫��

                //��˫��
                if ( (p.period / 32) == (p.period - 16) / 32)
                {
                    int select;
                    printf("����Ҫ�����Ŀγ���Ҫ�е�˫�ܰ��ţ��Ƿ��Լ�ȷ��\n");
                    printf("����������ѡ��(1�����Լ�ȷ��,2�������ȷ��):");
                    scanf("%d",&select);
                    while (select != 1 && select != 2)
                    {
                        printf("������������������������ѡ��:");
                        scanf("%d",&select);
                    }
                    switch (select)
                    {
                    case 1://�Լ��趨��˫��
                        {
                            printf("����������ѡ��Ĵ���(1�����ܣ�2����˫��):");
                            scanf("%d",&p.odd_even);
                        }
                    case 2://������ɵ�˫��
                        {
                            srand(time(NULL));
                            p.odd_even = (rand() % 2) + 1;
                        }
                    }
                }
                else
                {
                    p.odd_even = 0;//��˫�ܶ�Ҫ�Ͽ�
                }

                //����Ҫ��
                int option;
                printf("���������Ͽ�ʱ����û��ʲô����Ҫ��\n");
                printf("����������ѡ��(1����ָ��ʱ����ϿΣ�2������û��Ҫ��):");
                scanf("%d",&option);
                while (option != 1 && option != 2)
                {
                    printf("������������������������ѡ��:");
                    scanf("%d",&option);
                }
                p.data[0] = 0;
                p.data[1] = 0;
                if (option == 1)
                {
                    printf("����������ָ��ʱ��(�������ܼ���������ڼ��ڿΣ���������Ҫ��ѡ��0,�м��ÿո����,�����Ҫ����������1��ʾ����������2��ʾ)\n");
                    printf("����ָ����һ���ڶ�δָ�����죬����0 12(�벻Ҫָ���ܶ�����Ŀγ�)\n");
                    printf("����������Ҫ��:");
                    scanf("%d%d",&p.data[0],&p.data[1]);
                    if (p.data[0] && (p.data[1] > 10))//ָ������һ�����һ��
                    {
                        p.pri += 15;
                    }
                    else if (p.data[0] && p.data[1])//ָ������һ��������������
                    {
                        p.pri += 14;
                    }
                    else if ( (p.data[0] && !p.data[1]) || (p.period == 96))//ָ������һ��
                    {
                        p.pri += 10;
                    }
                    else if (!p.data[0] && p.data[1] > 10)//δָ����һ�쵫ָ������һ��
                    {
                        p.pri += 9;
                    }
                    else if (!p.data[0] && p.data[1])//δָ����һ�쵫ָ�������绹������
                    {
                        p.pri += 8;
                    }
                }
                printf("ȷ��������Ϣ���������ظ��ԿΣ�����Ҫ�޸���Ϣ��ѡ��1�����޸���ѡ��0: ");
                scanf("%d",&Sel);
            }
        l.push_back(p);
        list<project>::iterator it;
        it = l.end();
        it--;
            project ir;
            ir = *it;
            SetSchedule(&ir);
            printf("����%s�Ѿ����ź�.\n",it -> name);
            system("pause");

        printf("***********�ſ����!!***********\n");
    }

    else if(buew == 2)
    {
        int i,j,xznz;//xznt����ѡ��˫��
        printf("������Ҫ��ӵĿγ̵Ĵ��ţ�\n");
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
               printf("û�����ſΣ�����������γ̴��ţ�\n");
           }
           else
               break;
        }
        printf("������Ҫ�����ܼ� �Ľڣ���ʽ��1 2����һ�ڶ���ڣ����벻Ҫ��ӿγ̵��ܶ����磩: \n");
        scanf("%d %d",&i,&j);
        printf("�Ƿ����õ�˫�ܣ������ã�0 �����ϿΣ�1 ˫���ϿΣ�2����");
        scanf("%d",&xznz);
        while (xznz != 1 && xznz != 2 && xznz != 0)
            {
                printf("������������������������ѡ��:");
                scanf("%d",&xznz);
            }
        if(flag[j][i-1]==0&&xznz==0)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=4;
                it->period+=32;
                printf("******����ɹ���******\n");
            }
        else if(flag[j][i-1]==0&&xznz==1)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=1;
                it->odd_even=1;
                it->period+=16;
                printf("******����ɹ���******\n");
            }
        else if(flag[j][i-1]==0&&xznz==2)
            {
                store[j-1][i-1]=p.code;
                flag[j][i-1]=2;
                it->odd_even=2;
                it->period+=16;
                printf("******����ɹ�!******\n");
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
                printf("******����ɹ�!******\n");
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
                printf("******����ɹ�!******\n");
            }
        else
            printf("����� ����пΣ�\n");
    }
    }
    system("pause");

}
///��ѯ��Ϣ
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
    printf("������Ҫ��ѯ�Ŀγ̵Ĵ���:");
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
            printf("û�����ſ�,����������\n");
        }
        else
            break;
    }
    printf("���ѯ�Ŀγ��ǣ�        %s\n\n",it->name);
    printf("%s���ڿ���ʦ�ǣ�  %s\n\n",it->name,it->teacher);
    printf("����%d��ʱ \n\n",it->period);
    printf("%s��  ",it->name);
    for(j=0;j<5;j++)
        for(i=0;i<4;i++)
        {
            if(flag[i+1][j]== 4)
            {
               if(store[i][j]==it->code)
               printf("��%d��%d%d��  ",j+1,i*2+1,i*2+2);
            }
            else if(flag[i+1][j]==1)
            {
                if(store[i][j]==it->code)
                printf("��%d��%d%d�ڣ�����  ",j+1,i*2+1,i*2+2);
            }
            else if(flag[i+1][j]==2)
            {
                if(store[i][j]==it->code)
                printf("��%d��%d%d�ڣ�˫��  ",j+1,i*2+1,i*2+2);

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
                    printf("��%d��%d%d�ڣ�����  ",j+1,i*2+1,i*2+2);
                    else if(it->odd_even==2)
                    printf("��%d��%d%d�ڣ�˫��  ",j+1,i*2+1,i*2+2);

                }
            }
        }
        printf("�пΡ�\n\n ");
        system("pause");
}
///��¼����
void log()
{

    printf("|---------------------------------------------------------------------------|\n");
    printf("|                             ��ӭ��¼�α���ϵͳ                          |\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("                                       ��¼                                  \n");
    printf("\n");
    printf("                             ����:");
    scanf("%s",username);
    printf("                             ѧ����:");
    scanf("%d",&number);
    printf("\n");
    }
///��ʾ���˵�
void menu()
{
    printf("-----------------------------------------------------------------------------\n");
    printf("��                               �γ̱�ϵͳ�˵�                              ��\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("��                                 1.�½��α�                                ��\n");
    printf("��                                 2.�޸Ŀα�                                ��\n");
    printf("��                                 3.����α�                                ��\n");
    printf("��                                 4.��ʾ�α�                                ��\n");
    printf("��                                 5.��ѯ�γ�                                ��\n");
    printf("��                                 0.�˳�                                    ��\n");
    printf("-----------------------------------------------------------------------------\n");
}
int main()
{
    system("color F0");
    log();
    menu();
    int select;
    srand(time(NULL));
    printf("��������������Ķ�Ӧ����:");
    while (scanf("%d",&select) && select)
    {
        while (select < 0 || select > 5)
        {
            printf("������������������:");
            scanf("%d",&select);
        }
        switch (select)
        {
        //�����α�
        case 1:
            {
                system("cls");//������Ļ��׼��д��
                CreateSchedule();
                system("cls");//������Ļ��׼��д��
            }break;
        //�޸Ŀγ̱�
        case 2:
            {
                system("cls");//������Ļ��׼��д��
                printf("|---------------------------------------------------------------------------|\n");
                printf("|                                                                           |\n");
                printf("|                              %s�α�                                  |\n",major);
                printf("|                                                                           |\n");
                printf("|---------------------------------------------------------------------------|\n");
                ReviseProject();
                Print();
                printf("------------------------�����Ѿ��޸ĳɹ���ѡ�񱣴�--------------------------\n");

            }break;

        //����γ̱�
        case 3:
            {
                system("cls");//������Ļ��׼��д��
                Store();
                printf("���ڿα���Ϣ�Ѿ�����ڡ��α�.txt�ļ��С�.");
                system("pause");
                system("cls");
            }break;

        //���һ���α�
        case 4:
            {
                system("cls");//������Ļ��׼��д��
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                               %s�α�                                  \n",major);
                printf("                                                                             \n");
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                  ������%s",username);
                printf("               ѧ�ţ�%d                 \n",number);
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
        system("cls");//������Ļ��׼��д��
        menu();
        printf("��������������Ķ�Ӧ����:");
    }
    printf("��л����ʹ�ã�\n");
    system("pause");
    return 0;
}
