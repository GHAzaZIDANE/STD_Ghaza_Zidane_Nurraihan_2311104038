#include<iostream>
#include<conio.h> // library untuk getch
#include<stdlib.h> // library angka untuk alokasi memori
using namespace std;

struct mahasiswa
{
  char nim[10];
  int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

int main ()
{
  mahasiswa mhs;
  inputMhs(mhs);
  cout << "rata-rata = "<< rata2(mhs);
  return 0;
}

void inputMhs(mahasiswa &m){ // &m mengirim referensi langsung ke data asli, 
  cout << "input nim = ";
  cin >> m.nim;
  cout << "input nilai1 = ";
  cin >> m.nilai1;
  cout << "input nilai2 = ";
  cin >> m.nilai2;
}

float rata2(mahasiswa m){
  return (m.nilai1 * m.nilai2) / 2.0; // membagi dengan 2.0 untuk pembagian float
}