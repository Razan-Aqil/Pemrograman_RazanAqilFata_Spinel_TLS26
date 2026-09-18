#include <iostream>

using namespace std;

int maxManual(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void hapusElemen(int arr[], int &ukuran, int indexHapus)
{
    for (int i = indexHapus; i < ukuran - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    ukuran--;
}

int main()
{
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K: ";
    cin >> K;

    if (N < 1)
    {
        cout << "Jumlah astronot harus minimal 1." << endl;
        return 0;
    }

    int astronot[1000];
    int urutanEliminasi[1000];
    int ukuranAstronot = N;
    int ukuranEliminasi = 0;

    for (int i = 0; i < N; i++)
    {
        astronot[i] = i + 1;
    }

    int currentIndex = 0;

    while (ukuranAstronot > 1)
    {
        int indexEliminasi = (currentIndex + K - 1) % ukuranAstronot;

        int astronotTereliminasi = astronot[indexEliminasi];
        urutanEliminasi[ukuranEliminasi] = astronotTereliminasi;
        ukuranEliminasi++;

        hapusElemen(astronot, ukuranAstronot, indexEliminasi);

        currentIndex = indexEliminasi % ukuranAstronot;

        if (astronotTereliminasi % 2 == 0)
        {
            K = K + 2;
        }
        else
        {
            K = maxManual(2, K - 1);
        }
    }

    cout << "\nHasil Simulasi" << endl;
    cout << "Urutan astronot yang tereliminasi: ";
    for (int i = 0; i < ukuranEliminasi; i++)
    {
        cout << urutanEliminasi[i];
        if (i < ukuranEliminasi - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Astronot terakhir: " << astronot[0] << endl;

    return 0;
}
