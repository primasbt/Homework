#include <iostream>
#include <stdlib.h>
using namespace std;

void HitungIPK(string* nama, string* nim, int* n, float grade[90]){
    float ipk, jumlah_nilai;

    cout<<"===================="<<endl;
    cout<<"Hasil Data Mahasiswa"<<endl;
    cout<<"===================="<<endl;
    cout<<"Nama\t: "<<(*nama)<<endl;
    cout<<"Nim\t: "<<(*nim)<<endl;

    for (int i = 0; i < (*n); i++){
        jumlah_nilai += grade[i];
    }

    ipk = jumlah_nilai / (*n);

    cout<<"IPK\t : "<<ipk<<endl;
}

int main() {
    string nama, nim, kelas;
    int n ;
    float rata, jumlah;
    char nilai[999];

    cout<< "Data Mahasiswa\n"<<endl;

    cout<<"Nama\t: ";
    getline(cin, nama);
    cout<<"kelas\t: ";
    cin>>kelas;
    cout<<"nim\t: ";
    cin>>nim;

    cout<<endl;
    cout<<endl;

    cout<<"Input banyak matkul: ";
    cin>>n;
    float grade[n];

    for (int i = 0; i < n; i++){
        cout<<"Input nilai ke-"<< i+1 <<" = ";
        cin>>nilai[i];

        if (nilai[i] == 'A'){
            grade[i] = 4;
        }
        else if (nilai[i] == 'B'){
            grade[i] = 3;
        }
        else if (nilai[i] == 'C'){
            grade[i] = 2;
        }
        else if (nilai[i] == 'D'){    
            grade[i] = 1;
        }
        else if (nilai[i] == 'E'){ 
            grade[i] = 0;
        }
        cout<<endl;
    }

    system("cls");

    
    HitungIPK(&nama, &nim, &n, grade);

    return 0;
    
    
}