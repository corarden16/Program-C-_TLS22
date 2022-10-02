#include <iostream>
#include <ctime>
using namespace std;

time_t t = time(0);  
tm* now = localtime(&t);

int age(int pd, int pm, int py,int bd, int bm, int by)
{
  int d, m, y;
  int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  y = py - by;
  if (pm < bm)
  {
    y--;
    m = 12 - (bm - pm);       
  }
  else
  {m = pm - bm;}
  if (pd < bd)
  {
    m--;
    d = md[pm - 1] - (bd - pd);
  }
  else
  {d = pd - bd;}
//   cout << "your age is : \n";
//   cout << y << " years " << m << " months " << d << " days. ";
  return y;
}

class Admin{
    private:
    unsigned char umur;
    string angkatan;
    string nama;
    string prodi;
    string TL;
    string asal, idline, NIM;
    

    public: 
    Admin(){

    }

    Admin(string inputNama,string inputTL,string inputNIM,string inputAsal,string inputProdi,string inputIDLine,string inputAngkatan)
        {
            nama = inputNama;
            TL = inputTL;
            NIM = inputNIM;
            asal = inputAsal;
            prodi = inputProdi;
            idline = inputIDLine;
            angkatan = inputAngkatan;

            umur = age(
                now->tm_mday,
                (now->tm_mon + 1),
                (now->tm_year + 1900),
                (TL[0]-'0')*10+TL[1]-'0', //dd
                (TL[3]-'0')*10+TL[4]-'0', //mm
                (TL[6]-'0')*1000+(TL[7]-'0')*100+(TL[8]-'0')*10+TL[9]-'0' //yyyy
            );
         }  
         void setnama(string nama){
            Admin::nama = nama;
         } 
         string getnama()
         {
            return nama;
         }
         void setTL(string TL){
            Admin::TL = TL;
            Admin::umur = age(
                now->tm_mday,
                (now->tm_mon + 1),
                (now->tm_year + 1900),
                (TL[0]-'0')*10+TL[1]-'0', //dd
                (TL[3]-'0')*10+TL[4]-'0', //mm
                (TL[6]-'0')*1000+(TL[7]-'0')*100+(TL[8]-'0')*10+TL[9]-'0' //yyyy
            );
         }
         string getTL(){
            return TL;
         }
         void setNIM(string NIM){
            Admin::NIM = NIM;
         }
         string getNIM(){
            return NIM;
         }
         void setAsal(string ssal){
            Admin::asal = asal;
         }
         string getAsal(){
            return asal;
         }
         void setProdi(string prodi){
            Admin::prodi = prodi;
         }
         string getProdi(){
            return prodi;
         }
         void setIDLine(string idline){
            Admin::idline = idline;
         }
         string getIDLine(){
            return idline;
         }
         int getUmur(){
            return umur;
         }
         void setAngkatan(string angkatan){
            Admin::angkatan = angkatan;
         }
         string getAngkatan(){
            return angkatan;
         }
         void getAll(){

            cout << "Nama: "<< nama << endl;
            cout << "Tanggal lahir: "<< TL << endl;
            cout << "NIM: "<< NIM << endl;
            cout << "Asal daerah: " << asal << endl;
            cout << "Prodi: " << prodi << endl;
            cout << "ID Line: " << idline << endl;
            cout << "Umur: " << int(umur) << endl;
          
            cout << "Angkatan: " << angkatan << endl;
            
         }

};
    

    int main()
    {
        
        Admin data[32];
        int n;
        string input;
        cout << "Masukkan jumlah data mahasiswa yang ingin diinput: ";
        cin >> n;
        for (int i=0; i < n; i++){
            cout << endl;
            cout << "Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
            cout << "Nama: ";
            cin >> input;
            data[i].setnama(input);

            cout << "Tanggal lahir (format dd/mm/yyyy): ";
            cin >> input;
            data[i].setTL(input);

            cout << "NIM: ";
            cin >> input;
            data[i].setNIM(input);
            
            cout << "Kota asal: ";
            cin >> input;
            data[i].setAsal(input);
            
            cout << "Prodi: ";
            cin >> input;
            data[i].setProdi(input);
            
            cout << "ID Line: ";
            cin >> input;
            data[i].setIDLine(input);
            
            cout << "Angkatan (2 digit terakhir, contoh:22): ";
            cin >> input;
            data[i].setAngkatan(input);
            
        }
        cout << "DATA MAHASISWA" << endl;
        cout << "--------------------" << endl;
        cout << endl;

        for(int i=0; i < n; i++){
            cout << "Data mahasiswa ke-" << i + 1 << endl;
            data[i].getAll();
            cout << endl;
        }

        


        

 

        return 0;
    }