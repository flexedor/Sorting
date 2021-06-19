// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(suppress : 4996)
#pragma warning(disable : 4996)
#include <string.h>           
#include <stdlib.h>   
#include <iostream>

using namespace std;
const int SZ = 1000;

class verylong
{
private:
    char vlstr[SZ];
    int vlen;

public:

    verylong() : vlen(0)
    {
        vlstr[0] = '\0';
    }
    verylong(const char s[SZ])
    {
        strcpy_s(vlstr, s); vlen = strlen(s);
    }
    verylong(const unsigned long n)
    {
        _ltoa_s(n, vlstr, 10);           //перевод в строку 
       // strrev(vlstr);                //переворот
        vlen = strlen(vlstr);           //длинна
    }
    void putvl() const {  //вывод
        char temp[SZ];
        strcpy_s(temp, vlstr);
        cout << temp << endl;
    }
    void getvl() { //ввод
        cin >> vlstr;
        vlen = strlen(vlstr);
        //strrev(vlstr);             
    }
  
    bool operator > (verylong c2)
    {
        if (this->vlen > c2.vlen)
        {
            return true;
        }
        else if (this->vlen < c2.vlen)
        {
            return false;
        }
        else {

            for (size_t i = 0; i < this->vlen; i++)
            {
                if (this->vlstr[i] > c2.vlstr[i])
                {
                    return true;
                }
                else if (this->vlstr[i] < c2.vlstr[i]) {
                    return false;
                }
            }
        }
        return false;

    }
    /* bool operator < (verylong c1, verylong c2)
     {
         return c1.seconds < c2.seconds;
     }*/
};




int shellSort(verylong  arr[], unsigned int n)
{
   
    for (int przestrzenie = n / 2; przestrzenie > 0; przestrzenie /= 2)
    {
      
        for (int i = przestrzenie; i < n; i += 1)
        {
           
            verylong temp = arr[i];

            int j;
            for (j = i; j >= przestrzenie && arr[j - przestrzenie] > temp; j -= przestrzenie)
                arr[j] = arr[j - przestrzenie];

        
            arr[j] = temp;
        }
    }
    return 0;
}

int main()
{
    unsigned int num_of_iterarion;
    cin >> num_of_iterarion;
    verylong* arr = new verylong[num_of_iterarion];
    for (unsigned int i = 0; i < num_of_iterarion; i++)
    {
        arr[i].getvl();
    }
    shellSort(arr, num_of_iterarion);
    for (unsigned int i = 0; i < num_of_iterarion; i++)
    {
        arr[i].putvl();
    }
    delete arr;
}

