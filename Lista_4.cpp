#include <iostream>
using namespace std;
void read_text(char tab[], int size)
{
    cout << "Podaj tekst do wczytania.\n";
    cin.ignore();
    cin.getline(tab, size);

}
void printS(char tab[], int size)       /* funkcja do sprawdzania wartości kodów ASCII danych znaków */
{
    for (int i = 0; i < size; i++)
    {
        cout << (int)tab[i] << "\t";
    }
    cout << "\n";
}
void show_text(char tab[], int size)
{
    cout << "Tekst przechowywany w tablicy dynamicznej.\n";
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << "\t";
    }
    cout << "\n";
}
int number_of_characters(char tab[], int size)
{
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] > 0)
        {
            num++;
        }
    }
    return num;
}
void UL_case(char tab[], int size, bool uppercase)
{

    for (int i = 0; i < size - 1; i++)
    { 
        if (uppercase && tab[i] >= 'a' && tab[i] <= 'z')
        {
            tab[i] -= 32;
        }
        else if (!uppercase && tab[i] >= 'A' && tab[i] <= 'Z')
        {
            tab[i] += 32;
        }
    }
}
void UL_case_menu(char tab[], int size)
{
    bool uppercase;
    cout << "Zmienić na duże czy małe litery? \n Małe - 0 \n Duże - 1\n";
    cin >> uppercase;
    UL_case(tab, size, uppercase);
}
void histogram(char tab[], int size)
{
    cout << "HISTOGRAM\n";
    //liczba znaków alfabetu - 26
    int NoC = 26;
    int table[26] = { 0 };
    UL_case(tab, size, 0);
    for (int i = 0; i < size - 1; i++)
    {
        table[(int)tab[i] - 97]++;
    }
    for (int i = 0; i < NoC; i++)
    {
        if (table[i] != 0)
        {
            cout << (char)(i + 97) << " ";
            for (int k = 0; k < table[i]; k++)
            {
                cout << "#";
            }
            cout << "\n";
        }
    }
}
void add_element(int*& tab, int &size, int elem)
{
    bool done=false;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == NULL)
        {
            tab[i] = elem;
            done = true;
            break;
        }
    }
    if (!done) 
    {
        int* temp_tab;
        temp_tab = new int[size];
        for (int i = 0; i < size; i++)
        {
            temp_tab[i] = tab[i];
        }
        tab = new int[2 * size];
        for (int i = 0; i < 2 * size; i++)
        {
            tab[i] = NULL;
        }
        for (int i = 0; i < size; i++)
        {
            tab[i] = temp_tab[i];
        }
        tab[size] = elem;
        size *= 2;
        delete[] temp_tab;
    }
}
void delete_element(int*& tab, int size, int poz)
{
    if (poz == (size - 1))
    {
        tab[poz] = NULL;
    }
    else if (poz < size - 1)
    {
        for (int i = poz; i < size - 1; i++)
        {
            tab[i] = tab[i + 1];
        }
        tab[size - 1] = NULL;
    }
}
void ile_elem(int*& tab, int size)
{
    int licz = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] != NULL)
        {
            licz++;
        }
    }
    cout << "Zajęte: " << licz << "\n Wolne: " << size - licz << "\n";
}
void zad3()
{
    int size = 4;
    int* tab;
    tab = new int[size];
    for (int i = 0; i < size; i++)
    {
        tab[i] = NULL;
    }
    int dec;
    int poz;
    int elem;
    do
    {
        cout << "Podaj decyzję.\n";
        cin >> dec;
        switch (dec)
        {
        case 1:
            cout << "Podaj element do dodania.\n";
            cin >> elem;
            add_element(tab, size, elem);
            break;
        case 2:
            cout << "Podaj pozycję.\n";
            cin >> poz;
            delete_element(tab, size, poz);
            break;
        case 3:
            ile_elem(tab, size);
            break;
        default:
            for (int i = 0; i < size; i++)
            {
                cout << tab[i] << ";";
            }
            cout << "\n";
            break;
        }
    } while (dec != 0);
}
int main()
{
    /*
    int size;
    cout << "Podaj rozmiar tablicy.Pamiętaj, że tablica musi być większa o 1 od długości tekstu.\n";
    cin >> size;
    char* tab;
    tab = new char[size];
    read_text(tab, size);
    show_text(tab, size);
    printS(tab, size);
    //UL_case_menu(tab, size);
    //show_text(tab, size);
    int temp=number_of_characters(tab, size);
    cout << "Liczba wczytanych znaków: " << temp << "\n";
    histogram(tab, size);
    delete[] tab;
    */

    //Zadanie 3
    zad3();
}