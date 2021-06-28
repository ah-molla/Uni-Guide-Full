#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int rollGenerator()
{
    int roll = 202100;
    string rubbish;
    ifstream Roll("Admission Data File.csv");
    while (Roll.good())
    {
        getline(Roll, rubbish, '\n');
        roll++;
    }
    roll = roll - 1;
    return roll;
}

int Admission_test_form_fillup()
{

    string Name;
    int roll_ssc, roll_hsc;
    ofstream AdmissionDataFile;
    AdmissionDataFile.open("Admission Data File.csv", std::ios::app);

    for (int i = 0; i < 11; i++)
    {
        cout << "*";
        usleep(100000);
    }

    string wlcm = "WELCOME";

    for (int i = 0, j = 0; i < 7; i++, j++)
    {
        cout << wlcm[j];

        usleep(100000);
    }

    for (int i = 0; i < 11; i++)
    {
        cout << "*";
        usleep(100000);
    }
    usleep(200000);
    cout << "\nName:\t\t";
    getline(cin, Name);
    cout << "SSC Roll:\t";
    cin >> roll_ssc;
    cout << "SSC Board:\t";
    string boardSSC;
    cin >> boardSSC;
    if (boardSSC == "DHA" | boardSSC == "RAJ" | boardSSC == "JES" | boardSSC == "CHA" | boardSSC == "BAR" | boardSSC == "KUM" | boardSSC == "DIN")
    {
    }
    else
    {
        cerr << "Board name isn't recognized !" << endl;
        exit(1);
    }

    cout << "GPA (out of 5):\t";
    float GPA_SSC;
    cin >> GPA_SSC;
    if (GPA_SSC > 5.00)
    {
        cerr << "Invalid GPA!";
        exit(1);
    }
    else if (GPA_SSC < 4.00)
    {
        cout << "You are not allowed to apply!";
        exit(1);
    }
    cout << "HSC Roll:\t";
    cin >> roll_hsc;
    cout << "HSC Board:\t";
    string boardHSC;
    cin >> boardHSC;
    if (boardSSC == "DHA" | boardSSC == "RAJ" | boardSSC == "JES" | boardSSC == "CHA" | boardSSC == "BAR" | boardSSC == "KUM" | boardSSC == "DIN")
    {
    }
    else
    {
        cerr << "Board name isn't recognized !" << endl;
        exit(1);
    }
    cout << "GPA (out of 5):\t";
    float GPA_HSC;
    cin >> GPA_HSC;
    if (GPA_HSC > 5.00)
    {
        cerr << "Invalid GPA!";
        exit(1);
    }
    else if (GPA_HSC < 4.00)
    {
        cout << "You are not allowed to apply!";
        exit(1);
    }

    int id;
    id = rollGenerator();
    AdmissionDataFile << id << "," << Name << "," << GPA_SSC << "," << GPA_HSC << "," << endl;

    cout << "Proceeding!!!" << endl;
    for (int i = 0; i < 35; i++)
    {
        char c = 219;
        cout << c;
        usleep(300000);
    }
    cout << "\n\nYour admission ID is\t" << id << endl;
    cout << "\n\n\nYour application has been submitted!";
    //usleep(3000000);
    return 0;
}

int Admission_test_result_publish()
{
    int id[100];
    float score[100];
    int i = 0, merit = 1;
    ifstream result;
    ofstream meritList, List;
    meritList.open("Merit List.csv");
    meritList << "merit,roll,score" << endl;
    List.open("List.txt");
    if (meritList.fail())
        exit(1);
    result.open("Admission test result.txt");
    if (result.fail())
        exit(1);
    while (result.good())
    {
        result >> id[i] >> score[i];
        i++;
    }

    int k;
    for (float j = 100; j >= 50; j--)
    {
        for (int sc = 1; sc < 100; sc++)
        {
            if (score[sc] == j)
            {
                meritList << merit << "," << id[sc] << "," << score[sc] << endl;
                List << id[sc] << endl;
                merit++;
            }
        }
    }

    return 0;
}

int University_admission_form()
{
    cout << "Enter Your Admission ID:\t";
    int ID, List[100], trash, i = 0, k;
    int serial = 0;
    cin >> ID;
    ofstream temp;
    temp.open("temp.txt", std::ios::app);
    ifstream temp_t("temp.txt");
    ifstream meritList("List.txt");
    if (meritList.fail())
    {
        cerr << "!fail";
        exit(1);
    }
    while (meritList.good())
    {

        meritList >> List[i];
        i++;
    }
    cout << "Merit:\t";
    for (k = 0; k <= 99; k++)
    {
        if (ID == List[k])
        {
            serial = k + 1;
            if (serial)
                cout << serial << endl;
            break;
        }
    }
    while (temp_t.good())
    {
        int mer;
        temp_t >> mer;
        if (mer == ID)
        {
            cout << "You've applied already!!";
            exit(1);
        }
    }
    if (k > i)
    {
        cout << "failed";
        exit(1);
    }
    int firstChoice, secondChoice, thirdChoice;
    cout << "Subject choice:\n\t\t\t1.EEE\n\t\t\t2.CSE\n\t\t\t3.ME" << endl;

    do
    {
        cout << "1st choice:\t";
        cin >> firstChoice;
        if (firstChoice > 3 | firstChoice < 1)
        {
            std::cout << "invlid!!" << endl;
        }
    } while (firstChoice > 3 | firstChoice < 1);
    do
    {
        cout << "2nd choice:\t";
        cin >> secondChoice;
        if (secondChoice > 3 | secondChoice < 1)
        {
            std::cout << "invlid!!" << endl;
        }
    } while (secondChoice > 3 | secondChoice < 1);
    do
    {
        cout << "3rd choice:\t";
        cin >> thirdChoice;
        if (thirdChoice > 3 | thirdChoice < 1)
        {
            std::cout << "invlid!!" << endl;
        }
    } while (thirdChoice > 3 | thirdChoice < 1);
    ofstream data;
    data.open("Data.csv", std::ios::app);
    data << serial << "," << ID << "," << firstChoice << "," << secondChoice << "," << thirdChoice << endl;
    temp << ID << endl;

    return 0;
}

int Fresult()
{
    ifstream data("Data.csv");
    ofstream out;
    string merit[50], roll[50], fChoice[50], sChoice[50], tChoice[50];

    int merit_pos[50];
    int i = 0, meritPos;
    out.open("data_temp.txt");
    //out << "Merit\troll\tfirstchoice\tsecondchoice\tthirdchoice\n";
    cout << "Merit\troll\tfirstchoice\tsecondchoice\tthirdchoice\n";
    while (data.good())
    {
        i++;
        getline(data, merit[i], ',');
        getline(data, roll[i], ',');
        getline(data, fChoice[i], ',');
        getline(data, sChoice[i], ',');
        getline(data, tChoice[i], '\n');
        stringstream num(merit[i]);
        num >> merit_pos[i];
        //cout << merit_pos[i] << "\t>>>\t";
        //cout << merit[i] + "\t" + roll[i] + "\t" + fChoice[i] + "\t" + sChoice[i] + "\t" + tChoice[i] << endl;
    }
    for (int serial = 1; serial <= 50; serial++)
    {
        for (int d_serial = 1; d_serial <= i; d_serial++)
        {
            if (merit_pos[d_serial] == serial)
            {
                //std::cout << merit_pos[d_serial] << '\n';
                cout << merit[d_serial] + "\t" + roll[d_serial] + "\t\t" + fChoice[d_serial] + "\t\t" + sChoice[d_serial] + "\t\t" + tChoice[d_serial] << endl;
                out << merit[d_serial] + "\t" + roll[d_serial] + "\t\t" + fChoice[d_serial] + "\t\t" + sChoice[d_serial] + "\t\t" + tChoice[d_serial] << endl;
            }
        }
    }
    char trash;
    cin >> trash;

    return 0;
}

int Result_out()
{

    ofstream EEE_list, CSE_list, ME_list, list;
    EEE_list.open("EEE.txt");
    CSE_list.open("CSE.txt");
    ME_list.open("ME.txt");
    list.open("dList.txt");

    ifstream data_temp, Admission_Data_File;
    Admission_Data_File.open("Admission Data File.csv");
    data_temp.open("data_temp.txt");

    int EEE[10], CSE[10], ME[10];
    int EEE_seat = 0, CSE_seat = 0, ME_seat = 0;
    int EEE_roll = 211101, CSE_roll = 211201, ME_roll = 211301;
    int merit, roll, choice1, choice2, choice3;
    string NAME;

    while (data_temp.good())
    {
        data_temp >> merit >> roll >> choice1 >> choice2 >> choice3;

        if (choice1 == 1 && EEE_seat < 10)
        {
            EEE_list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';
            cout << merit << "\t" << NAME << roll << "\t"
                 << "EEE\t" << EEE_roll << '\n';
            EEE_roll++;
            EEE_seat++;
        }

        else if (choice1 == 2 && CSE_seat < 10)
        {
            CSE_list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "CSE\t" << CSE_roll << '\n';
            CSE_roll++;
            CSE_seat++;
        }

        else if (choice1 == 3 && ME_seat < 10)
        {
            ME_list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "ME\t" << ME_roll << '\n';
            ME_roll++;
            ME_seat++;
        }
        else if (choice2 == 1 && EEE_seat < 10)
        {
            EEE_list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "EEE\t" << EEE_roll << '\n';
            EEE_roll++;
            EEE_seat++;
        }
        else if (choice2 == 2 && CSE_seat < 10)
        {
            CSE_list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "CSE\t" << CSE_roll << '\n';
            CSE_roll++;
            CSE_seat++;
        }
        else if (choice2 == 3 && ME_seat < 10)
        {
            ME_list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "EEE\t" << EEE_roll << '\n';
            ME_roll++;
            ME_seat++;
        }
        else if (choice3 == 1 && EEE_seat < 10)
        {
            EEE_list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << EEE_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "EEE\t" << EEE_roll << '\n';
            EEE_roll++;
            EEE_seat++;
        }
        else if (choice3 == 2 && CSE_seat < 10)
        {
            CSE_list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << CSE_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "CSE\t" << CSE_roll << '\n';
            CSE_roll++;
            CSE_seat++;
        }
        else if (choice3 == 3 && ME_seat < 10)
        {
            ME_list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';
            list << merit << "\t" << NAME << roll << "\t" << ME_roll << '\n';

            cout << merit << "\t" << NAME << roll << "\t"
                 << "EEE\t" << EEE_roll << '\n';
            ME_roll++;
            ME_seat++;
        }
    }

    return 0;
}

string loginScreen()
{
    string UserName, UserPassword, pass;
    int con = 0, i = 0;
    bool log = 1;
    char ch;
    //std::cout << "User ID:\t";
    //std::cin >> UserName;

    while (log)
    {
        UserPassword[i] = getch();
        if (UserPassword[i] != 13)
        {
            std::cout << "*";
            pass = pass + UserPassword[i];
            i++;
        }
        else
            log = 0;
    }
    //cout << "\nyour pass is:\t" << pass << endl;
    return pass;
}

int signUP()
{
    ifstream datafile, accdatafile;
    datafile.open("dList.txt");
    accdatafile.open("Account data.txt");
    ofstream acc_data;
    acc_data.open("Account data.txt", std::ios::app);

    string deptRoll_input, password_input, password_confirm, merit, adm_Roll, dept, dept_Roll, test, DEPT_ROLL;

    bool ok;

    ok = false;
    std::cout << "Please enter Depertment roll:\t";
    std::cin >> deptRoll_input;
    while (datafile.good())
    {
        accdatafile >> test;
        datafile >> merit >> adm_Roll >> dept >> dept_Roll;
        //std::cout << merit << "\t" << adm_Roll << "\t" << dept << "\t" << dept_Roll << '\n';
        if (deptRoll_input == dept_Roll)
        {

            std::cout << "merit"
                      << "\t"
                      << "adm_Roll"
                      << "\t"
                      << "dept"
                      << "\t"
                      << "dept_Roll" << '\n';
            std::cout << merit << "\t" << adm_Roll << "\t\t" << dept << "\t" << dept_Roll << '\n';
            DEPT_ROLL = dept_Roll;
            ok = true;
        }
        if (deptRoll_input == test)
        {
            std::cout << "You already have an account!" << '\n';
            exit(1);
        }
    }
    if (ok == false)
    {
        std::cout << "DATA NOT FOUND"
                  << "\nPlease try again later!" << '\n';
        exit(1);
    }
passPoint:
    std::cout << "Password:\t\t";
    string passw = loginScreen();
    std::cout << "\nRe-enter Password:\t";
    string re_passw = loginScreen();
    if (passw != re_passw)
    {
        cout << "\nPassword didn't match!\n";
        goto passPoint;
    }
    acc_data << DEPT_ROLL << "\t" << passw << endl;

    std::cout << "\nAccount has been created!" << '\n';
    string file = "Accounts/" + DEPT_ROLL + ".txt";
    ofstream accounts;
    accounts.open(file, std::ios::app);
    accounts << "ID:\t" << DEPT_ROLL << "\tPassword:\t" << passw << endl;
}

int login()
{
    ifstream acc_file;
    string ID;
    cout << "Enter ID no.:\t";
    cin >> ID;
    string file = "Accounts/" + ID + ".txt";
    acc_file.open(file);
    if (!acc_file.is_open())
    {
        cout << "Account not found!" << endl;
        exit(1);
    }

    cout << "Password:\t";
    string pwd = loginScreen();
    string trash, pwd_temp;
    acc_file >> trash >> trash >> trash >> pwd_temp;
    if (pwd != pwd_temp)
    {
        cout << "\nPassword didn't match!"
             << "\tTry again later" << endl;
        exit(1);
    }
    else
    {
        cout << "\nLogged in!\n";
        string Name = "notepad \"" + file + "\"";
        system(Name.c_str());
    }
}

int main()
{
    cout << "*******************WELCOME*******************" << endl;
    cout << "1. Admission test form fillup" << endl;
    cout << "2. Admission test result publish" << endl;
    cout << "3. University admission form" << endl;
    cout << "4. Department choice result" << endl;
    cout << "5. Student sign up" << endl;
    cout << "6. Student log in" << endl;
    int choice;
    cout << "select:\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Admission_test_form_fillup();
         break;

    case 2:
        Admission_test_result_publish();
        break;

    case 3:
        University_admission_form();
        Fresult();
         break;

    case 4:
        Result_out();
        break;

    case 5:
        signUP();
        break;

    case 6:
        login();
        break;

    }
}
