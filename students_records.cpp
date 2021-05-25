#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

struct Students
{
    char First_name[10];
    char Second_name[10];
    int ID;
    int score_of_subject[5];
};

int Students_info(struct Students stu[],int num_Students);

int main()
{
    int N;

    cout<<("Enter the number of students: ");
    cin>>N;
    while (N<=0)
    {
        cout<<("(ERROR)");
        cout<<("Please enter a positive number:");
        cin>>N;
    }
    cout<<("--------------------------------------------\n");

    struct Students stu[N];

    Students_info(stu,N);

    return 0;
}

int Students_info(struct Students stu[],int num_Students)
{
    ofstream file("Students_info.txt");

    file<<"Number of students: "<<num_Students<<"\n";
    file<<("--------------------------------------------\n");

    int flag1 = 0;
    int flag2 = 0;
    int success[5]={0,0,0,0,0};
    float sum;
    float avg;
    float avg_per_student[num_Students];
    float max_avg = 0;
    float min_avg = 0;
    float score[5]={0,0,0,0,0};
    float M[5]={0,0,0,0,0};
    float SD[5]={0,0,0,0,0};

    cout<<("Students info:-\n");
    cout<<("******\n");
    file<<("Students info:-\n");
    file<<("******\n");

    for (int i=0;i<num_Students;i++)
    {
        cout<<("Enter first name for the student: ");
        cin>>stu[i].First_name;
        file<<"-Student no."<<i+1<<"\n";
        file<<("..............\n");
        file<<">>First name: "<<stu[i].First_name<<"\n";

        cout<<("Enter second name for the student: ");
        cin>>stu[i].Second_name;
        file<<">>Second name: "<<stu[i].Second_name<<"\n";

        cout<<("Enter ID for the student: ");
        cin>>stu[i].ID;
        while (stu[i].ID<=0)
        {
            cout<<"(ERROR: Invalid ID) \n";
            cout<<"Please enter your correct ID should be positive: ";
            cin>>stu[i].ID;
        }
        for(int k=i-1;k>=0;k--)
        {
            while(stu[i].ID == stu[k].ID)
            {
                cout<<"(This ID already used) \n";
                cout<<"Please Enter Your correct ID: ";
                cin>>stu[i].ID;
            }
        }
        cout<<("--------------------------------------------\n");
        file<<">>ID: "<<stu[i].ID<<"\n";
        file<<("--------------------------------------------\n");

        for(int j=0;j<5;j++)
        {
            cout<<("Enter score of subject#")<<j+1<<": ";
            cin>>stu[i].score_of_subject[j];
            while(stu[i].score_of_subject[j]<0 || stu[i].score_of_subject[j]>100)
            {
                cout<<("Please enter suitable degree from 0 to 100 \n");
                cout<<("Enter suitable score of subject#")<<j+1<<": ";
                cin>>stu[i].score_of_subject[j];
             }
             file<<"-Subject#"<<j+1<<": "<<stu[i].score_of_subject[j]<<"\n";

            if(stu[i].score_of_subject[j]>=50)
            {
                success[j]++;
            }

            sum += stu[i].score_of_subject[j];
            score[j] += stu[i].score_of_subject[j];
        }

        avg = sum/5.0;
        avg_per_student[i] = avg;

        cout<<"\n";
        cout<<("--------------------------------------------\n");
        file<<("--------------------------------------------\n");
    }

    cout<<("Scores per subject:-\n");
    cout<<("********\n");
    for(int i=0;i<5;i++)
    {
        cout<<"Successful student per subject#"<<i+1<<": "<<success[i]<<"\n";
        cout<<"Score per subject#"<<i+1<<": "<<score[i]<<"\n";
        cout<<"\n";

        M[i] = score[i]/num_Students;
        for(int j=0;j<num_Students;j++)
        {
            SD[i] += pow((stu[i].score_of_subject[j]- M[i]) , 2) ;
        }
        SD[i] = sqrt(SD[i]/num_Students-1);
    }

    flag1 = avg_per_student[0];
    flag2 = avg_per_student[0];
    for(int i=0;i<num_Students;i++)
    {
        if(avg_per_student[i]>max_avg)
        {
            max_avg = avg_per_student[i];
            flag1 = i;
        }
        else
        {
            min_avg = avg_per_student[i];
            flag2 = i;
        }
        if(flag1 == 0 )
        {
            flag1 = 1;
        }
        if(flag2 == 0 )
        {
            flag2 = 1;
        }
     }

    cout<<("--------------------------------------------\n");
    cout<<("Displaying...info:-\n");
    cout<<("********\n");
    cout<<"The details of the students ID who got the highest accumulative score is:-";
    cout<<"\n";
    cout<<">>Name: "<<stu[flag1].First_name <<" "<<stu[flag1].Second_name;
    cout<<"\n";
    cout<<">>ID: "<< stu[flag1].ID<<"\n";
    cout<<("--------------------------------------------\n");
    cout<<"The details of the students ID who get the lowest accumulative score is:-";
    cout<<"\n";
    cout<<">>Name: "<<stu[flag2].First_name <<" "<<stu[flag2].Second_name;
    cout<<"\n";
    cout<<">>ID: "<< stu[flag2].ID<<"\n";
    cout<<("--------------------------------------------\n");
    for(int i=0;i<5;i++)
    {
        cout<<"The mean of subject#"<<i+1<<": "<<M[i]<<"\n";
        cout<<"The SD of subject#"<<i+1<<": "<<SD[i]<<"\n";
    }

    file.close();
}
