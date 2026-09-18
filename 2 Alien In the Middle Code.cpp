#include <iostream>

using namespace std;

bool apakahHuruf(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


bool apakahKapital(char c)
{
    return (c >= 'A' && c <= 'Z');
}


char ubahKeKapital(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - ('a' - 'A');
    }
    return c;
}

int hitungPanjang(char teks[])
{
    int panjang = 0;
    while (teks[panjang] != '\0')
    {
        panjang++;
    }
    return panjang;
}

void enkripsiSandiAstronot(char teks[], char hasil[])
{
    int panjang = hitungPanjang(teks);
    if (panjang == 0)
    {
        hasil[0] = '\0';
        return;
    }

    hasil[0] = teks[0];

    for (int i = 1; i < panjang; i++)
    {
        if (apakahHuruf(teks[i]))
            {
                bool isUpper = apakahKapital(teks[i]);
            
                char hurufAcuan = ubahKeKapital(teks[i - 1]);
                int nilaiPergeseran = hurufAcuan - 'A' + 1;

                char hurufSaatIni = ubahKeKapital(teks[i]);
                int posisiAsli = hurufSaatIni - 'A';

                int posisiBaru = (posisiAsli + nilaiPergeseran) % 26;

                hasil[i] = posisiBaru + (isUpper ? 'A' : 'a');
            }
        else
                {
                    hasil[i] = teks[i];
                }
    }
    
    hasil[panjang] = '\0';
    
}
int main()
{
    char inputTeks[100];
    char hasilEnkripsi[100];

    cout << "Masukkan kata/pesan: ";
    cin >> inputTeks;

    enkripsiSandiAstronot(inputTeks, hasilEnkripsi);

    cout << "Hasil Enkripsi: " << hasilEnkripsi << endl;

    return 0;
}
