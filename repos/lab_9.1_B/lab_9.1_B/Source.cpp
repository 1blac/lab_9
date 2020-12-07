//Лабораторна робота №9
//lab_9.1_
//Переліки.Структури та об'єднання
//РІВЕНЬ B
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)

enum Speciality { ITIS, IT, KI, KN, PM };
string speciality_str[] = { "Інформатика ",
                            "Інформаційні технології", "Комп'ютерна інженерія",
                            "Комп'ютерні науки", "Прикладна математика" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_pedagogy;
    union
    {
        int grade_programming;
        int grade_numerical_methods;
    };
};

#pragma pack(pop)

void Create(Students* S, const int N);
void Print(Students* S, const int N);
void Print_second(Students* S, const int N);
double Percentage(Students* S, const int N);
int grade_dobre(Students* S, const int i);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);
    Print_second(S, N);
    cout << "Процент студентів, які мають 5 з фізики або 5 з математики: " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    int speciality;
    for (int i = 0; i < N; i++)
    {
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність(0 - Інформатика, 1 - Інформаційні технології, 2 - Комп'ютерна інженерія";
        cout << "\n3 - комп'ютерні науки, 4 - Прикладна математика): ";
        cin >> speciality;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math;
        S[i].speciality = (Speciality)speciality;

        switch (S[i].speciality)
        {
        case KN:
            cout << "Оцінка з програмування: "; cin >> S[i].grade_programming;
            break;
        case ITIS:
            cout << "Оцінка з чисельних методів: "; cin >> S[i].grade_numerical_methods;
            break;
        default:
            cout << "Оцінка з педагогіки: "; cin >> S[i].grade_pedagogy;
        }
        cout << endl;
    }
}
void Print(Students* S, const int N)
{
    cout << "==============================================================================================================================" << endl;
    cout << "|  №  |  Прізвище  |  Курс  |  Спеціальність  |  Фізика  |  Математика  |  Програмування  |";
    cout << "  Чисельні методи  |  Педагогіка  |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(3) << S[i].surname << setw(3);
        cout << "|" << setw(4) << S[i].course << setw(4);
        cout << "|" << setw(3) << speciality_str[S[i].speciality] << setw(3);
        cout << "|" << setw(5) << S[i].grade_physics << setw(5);
        cout << "|" << setw(7) << S[i].grade_math << setw(7);
        switch (S[i].speciality)
        {
        case KN:
            cout << "|" << setw(7) << S[i].grade_programming << setw(7);
            cout << "|" << setw(7) << "-" << setw(7);
            cout << "|" << setw(7) << "-" << setw(7) << "|";
            break;
        case ITIS:
            cout << "|" << setw(8) << "-" << setw(8);
            cout << "|" << setw(8) << S[i].grade_numerical_methods << setw(8);
            cout << "|" << setw(8) << "-" << setw(8) << "|";
            break;
        default:
            cout << "|" << setw(7) << "-" << setw(7);
            cout << "|" << setw(8) << "-" << setw(8);
            cout << "|" << setw(7) << S[i].grade_pedagogy << setw(7) << "|";
        }
        cout << endl;
    }
    cout << "=============================================================================================================================" << endl;
}
int grade_dobre(Students* S, const int i)
{
    int dobre = 4;
    int k = 0;
    switch (S[i].speciality)
    {
        
        
    case KN:
        
        if (S[i].grade_physics == dobre)
            k++;
        if (S[i].grade_math == dobre)
            k++;
        if (S[i].grade_programming == dobre)
            k++;
        return k;
    case ITIS:
        if (S[i].grade_physics == dobre)
            k++;
        if (S[i].grade_math == dobre)
            k++;
        if (S[i].grade_numerical_methods == dobre)
            k++;
        return k;
    default:
        if (S[i].grade_physics == dobre)
            k++;
        if (S[i].grade_math == dobre)
            k++;
        if (S[i].grade_pedagogy == dobre)
            k++;
        return k;
    }
}
void Print_second(Students* S, const int N)
{
    cout << fixed;
    cout << "=======================================" << endl;
    cout << "|  №  |  Прізвище  |  кількість добре  |" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(5) << S[i].surname << setw(4);
        cout << "|" << setw(9) << setprecision(2) << grade_dobre(S, i) << setw(10) << "|";
        cout << endl;
    }
    cout << "=====================================" << endl;
}
double Percentage(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 || S[i].grade_math == 5)
            k++;
    return k / (N * 1.0) * 100;
}