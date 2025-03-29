
#include "Number.h"
#include<iostream>
using namespace std;

//CONSTRUCTORI

//folositi pt a initialia o instanta de tipul clasei doar( in acest caz Number),in functie de parametrii dati
Number::Number(const char* value, int base)//=>creez o instanta Number dintr un sir de caractere

{
    this->base = base;
    this->value = new char[strlen(value) + 1];
    memcpy(this->value, value, strlen(value) + 1);//destinatie, sursa, nr octeti
}//-----------Number n1("101", 2)---------------------

Number::Number(int value)
{
    this->base = 10;//un nr int e implicit considerat in baza 10
     // conversie din întreg în char( clasa e declarat char*numar)
    int d = value;
    int nr = 0;
    while (d > 0)
    {
        nr++;
        d = d / 10;
    }

    this->value = new char[nr + 1];//+1 pt acel ultim caracter \0
    this->value[nr] = '\0';//aici pun respectivul caracter in sir

    for (int i = nr - 1; i >= 0; i--)
    {
        this->value[i] = '0' + (value % 10);//transform cifra in caracter
        value = value / 10;
    }
}//---------------------Number n2(1234)---------------------------------

Number::Number(const Number& obiect)
{  // parametru-o referinta constanta la un obiect de tip number(pe care vr sa l copii)
    this->base = obiect.base;//copiez baza din obiectul sursa in obiectul nou
    this->value = new char[strlen(obiect.value) + 1];//aloc memorie obiectului copiat
    memcpy(this->value, obiect.value, strlen(obiect.value) + 1);
}//--------------------------Number n3 = n1-----------------------------

Number::Number(Number&& obiect)//move constructor
{
    this->base = obiect.base;
    this->value = obiect.value;
    obiect.value = nullptr;//pt ca l am mutat trb sa pointeze la nullptr acolo unde era, pt ca nu mai exista acolo
}//---------------------Number n4 =move(n2)-------------------

//operator de atribire din int
Number& Number::operator=(int number) //sterge vechiul sir, pune noul int ca sir
{
    delete[] this->value;//sterge vechiul sir din memorie
    //covertesc numar in sir
    int d = number;
    int nr = 0;
    while (d > 0)
    {
        nr++;
        d = d / 10;
    }

    this->value = new char[nr + 1];
    this->value[nr] = '\0';

    for (int i = nr - 1; i >= 0; i--)
    {
        this->value[i] = '0' + (number % 10);
        number = number / 10;
    }
    this->base = 10;//fiind un int e clar in baza 10

    return *this;//pointer catre obiectul modificat
}

//operator de atribire din sir
Number& Number::operator=(const char* sir)//cand ai deja un nr creat ca sir si ii atribui un nou sir de caractere
{
    delete[] this->value;
    this->value = new char[strlen(sir) + 1];
    memcpy(this->value, sir, strlen(sir) + 1);

    // baza rãmâne neschimbatã(obiectul deja exista intr o baza, doar ii inlocuiesc valoarea cu un alt string)

    return *this;
}

//move assisment( tot operator= doar ca are ca parametru un obiect de tipul clasei)si de aia se numeste move
Number& Number::operator=(Number&& obiect)
{
    if (this != &obiect)
    {
        delete[] this->value;
        this->value = obiect.value;
        this->base = obiect.base;
        obiect.value = nullptr;//obiectul sursa gol
    }
    return *this;
}

Number::~Number()//destructor se apeleeaza automat in main la return 0;
{
    delete[] value;//prin [] eliberez tot sirl de caractere; daca era doar delete eliberam doar prima valoare din sir
}

//METODE--------------------------------------------------------------

void Number::SwitchBase(int newBase)
{
    int base10 = ToDecimal(this->value, this->base);//convertesc la baza 10 valoarea actuala

    delete[] this->value;//sterg sirul vechi

    if (base10 == 0)
    {
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        this->base = newBase;
        return;
    }
    //aflu cate cifre are numarul
    int nr_aux = 0;
    int aux = base10;
    while (aux > 0)
    {
        nr_aux++;
        nr_aux = nr_aux / newBase;
    }
    //aloc spatiu pt noul sir
    this->value = new char[nr_aux + 1];
    this->value[nr_aux] = '\0';
    // Construiesc noul sir în noua bazã (de la final spre început)
    for (int i = nr_aux - 1; i >= 0; i--)
    {
        int cifra = base10 % newBase;
        if (cifra < 10)
            this->value[i] = '0' + cifra;
        else
            this->value[i] = 'A' + (cifra - 10);
        base10=base10/newBase;
    }
    this->base = newBase;
}

void Number::Print() 
{
   cout << value << " (in baza " << base << ")";
   cout << endl;
}

int Number::GetDigitsCount() 
{
    return strlen(value);
}

int Number::GetBase() 
{
    return base;
}


//FRIEND-----------------------------------------------------

Number operator+(const Number& a, const Number& b)
{
    int A = Number::ToDecimal(a.value, a.base); // accesez pentru cã e friend
    int B = Number::ToDecimal(b.value, b.base);
    int result = A + B; // adun valorile

    int baza_noua;
    if (a.base > b.base)
        baza_noua = a.base;
    else
        baza_noua = b.base;

    //nr cifre rezultat in noua baza
    int nr_aux = 0;
    int aux = result;//ii fac copie numaruli

    if (aux == 0)
        nr_aux = 1;
    else
    {
        while (aux > 0)
        {
            nr_aux++;
            aux = aux / baza_noua;
        }
    }
    char* sir = new char[nr_aux + 1];//aloc spatiu pt sirul rezultat din adunarea numerelor
    sir[nr_aux] = '\0';

    // Transform valoarea în baza noua
    aux = result;
    for (int i = nr_aux - 1; i >= 0; i--)
    {
        int cifra = aux % baza_noua;

        if (cifra < 10)
            sir[i] = '0' + cifra;
        else
            sir[i] = 'A' + (cifra - 10);

        aux = aux / baza_noua;
    }
    Number rezultat(sir, baza_noua);//creez noul obiect prin constructor folosind sirul si baza
    delete[] sir;//pt ca apeland constructorul s face noul obiect si nu mai am nevoie de acest sir
    return rezultat;
}


Number operator-(const Number& a, const Number& b)
{
    int A = Number::ToDecimal(a.value, a.base);
    int B = Number::ToDecimal(b.value, b.base);
    int result = A - B;

    int baza_noua;
    if (a.base > b.base)
        baza_noua = a.base;
    else
        baza_noua = b.base;

    //nr cifre rezultate in noua baza
    int nr_aux = 0;
    int aux = result;

    if (aux == 0)
        nr_aux = 1;
    else
    {
        while (aux > 0)
        {
            nr_aux++;
            aux = aux / baza_noua;
        }
    }
    char* sir = new char[nr_aux + 1];
    sir[nr_aux] = '\0';

    //transform valoarea in noua baza
    aux = result;
    for (int i = nr_aux - 1; i >= 0; i--)
    {
        int cifra = aux % baza_noua;

        if (cifra < 10)
            sir[i] = '0' + cifra;
        else
            sir[i] = 'A' + (cifra - 10);

        aux = aux / baza_noua;
    }

    Number rezultat(sir, baza_noua);
    delete[] sir;
    return rezultat;
}//------------Number n3 = n1 - n2; ----------------

//OPERATORI---------------------------------------------------------
bool Number::operator<(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) < ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}
bool Number::operator>(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) > ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}
bool Number::operator<=(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) <= ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}
bool Number::operator>=(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) >= ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}
bool Number::operator==(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) == ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}
bool Number::operator!=(const Number& obiect)
{
    if (ToDecimal(this->value, this->base) != ToDecimal(obiect.value, obiect.base))
        return true;
    else
        return false;
}

char& Number::operator[](int index) 
{
    return this->value[index];
}


// --;++

Number& Number::operator--() //--i
{
    if (strlen(this->value) <= 1)
    {
        delete[] this->value;
        this->value = new char[2];
        memcpy(this->value, "0", 2);
    }
    else
    {
        for (int i = 0; value[i] != '\0'; ++i)//sterg primul caract
        {
            value[i] = value[i + 1];
        }
    }
    return *this;//returnez obiectul modificat
}

Number Number::operator--(int)//i--
{
    Number aux = *this;//o copie
    if (strlen(this->value) <= 1)
    {
        delete[] this->value;
        this->value = new char[2];
        memcpy(this->value, "0", 2);
    }
    else 
    {
        this->value[strlen(this->value) - 1] = '\0';//sterg ultimul caracter; in loc de 16 se pune 1
    }
    return aux;
}

//functie nr in baza 10
int Number::ToDecimal(const char* val, int base)
{
    int len = strlen(val);
    int result = 0;
    for (int i = 0; i < len; ++i)
    {
        char c = val[i];
        int d;
        if (c >= '0' && c <= '9')
            d = c - '0';
        else if (c >= 'A' && c <= 'F')
            d = 10 + (c - 'A');
        else
            d = 0;

        result = result * base + d;
    }
    return result;
}
