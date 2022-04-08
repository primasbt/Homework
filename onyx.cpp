#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

string *nama;
string *nim;

int jumlah_mhs;

void InputMahasiswa(){
    nama = new string[99];
    nim = new string[99];

    cout<<"Masukan jumlah mahasiswa : ";
    cin>>jumlah_mhs;

    for (int i =0; i < jumlah_mhs; i++){
        cout<<"Input data mahasiswa - "<<i+1<<" : "<<endl;
        cout<<"Nama\t : ";
        cin>>*(nama+i);
        cout<<"NIM\t : ";
        cin>>*(nim+i);
    }


}

void HitungIpk(int* matkul, int grade[99]){
    float ipk , nilai;

    for(int i = 0; i < (*matkul); i++){
        nilai += grade[i];
    }

    ipk = nilai / (*matkul);

    cout<<"IPK\t : "<< ipk<<endl;
}

void InputNilaiMatkul(){
    int matkul;

    system("cls");
    cout<<"=========================="<<endl;
    cout<<"  Input Nilai Matkul MHS  "<<endl;
    cout<<"=========================="<<endl;
    cout<<"Jumlah matkul : ";
    cin>>matkul;
    int grade[matkul];
    char nilai[matkul];

    for (int i = 0; i < matkul; i++){
        cout<<"Nilai matkul ke - "<<i+1<<" [A/B/C/D/E] : ";
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
    }

    system("cls");
    HitungIpk(&matkul, grade);

}

void urutkanNIM(){
    int i, max, j;
    string temp;

    for(i = 0; i < jumlah_mhs; i++){
        max = i;
        
        for(j = i + 1; j < jumlah_mhs; j++){
            if(*(nim+max) > *(nim+j)){
                max = j;
            }
        }
        
        if(*(nim+i) != *(nim+max)){
            temp = *(nama+i);
            *(nama+i) = *(nama+max);
            *(nama+max) = temp;

            temp = *(nim+i);
            *(nim+i) = *(nim+max);
            *(nim+max) = temp;
        }
    }

    cout<<"Berhasil diurutkan Ascending"<<endl;

}

void tampilkanMahasiswa(){
    system("cls");

    cout<<"=================="<<endl;
    cout<<" Daftar Mahasiswa "<<endl;
    cout<<"=================="<<endl;
    cout<<"=  NIM  =  NAMA  ="<<endl;

    for (int i = 0; i < jumlah_mhs; i++){
        cout<<"= "<<*(nim+i)<<" = "<<*(nama+i)<<" = "<<endl;
    }
}

int main(){
    int menu;
    string exit;
    bool isExit = false;

    do {
        system("cls");
        cout<<"===================="<<endl;
        cout<<"     Aplikasi       "<<endl;
        cout<<"===================="<<endl;
        cout<<"1. Input data mahasiswa"<<endl;
        cout<<"2. Hitung IPK mahasiswa"<<endl;
        cout<<"3. Urutkan data mahasiswa berdasarkan NIM"<<endl;
        cout<<"4. Tampilkan daftar mahasiswa"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Pilih salah satu menu diatas [1/2/3/4/5]: ";
        cin>>menu;

        switch (menu){
            case 1:
                InputMahasiswa();
                break;
            case 2:
                InputNilaiMatkul();
                break;
            case 3:
                urutkanNIM();
                break;
            case 4:
                tampilkanMahasiswa();
                break;
            case 5:
                goto keluar;
            default:
                cout<<"Menu tidak ada "<<endl;
                break;
        } 

        cout<<"Ingin keluar? [y/n] : ";
        cin>>exit;

        isExit = exit == "y" ? true : false;
    }while (!isExit);

    keluar:

    delete [] nama;
    delete [] nim;
    return 0;

}