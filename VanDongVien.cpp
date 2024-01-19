#include<iostream>
#include<vector>
using namespace std;

class VanDongVien{
    private:
            string hoten;
            int tuoi;
            string monthidau;
            float cannang;
            float chieucao;
    public:
           VanDongVien(){};
           VanDongVien(string hoten,int tuoi,string monthidau,float cannang,float chieucao){
            this->hoten=hoten;
            this->tuoi = tuoi;
            this->monthidau=monthidau;
            this->cannang=cannang;
            this->chieucao=chieucao;
           }
           ~VanDongVien(){};
           friend istream & operator >>(istream&in,VanDongVien&a){
            cout<<"Nhap ho ten : ";in>>a.hoten;
            cout<<"Nhap tuoi : ";in>>a.tuoi;
            cout<<"Nhap mon thi dau : ";in>>a.monthidau;
            cout<<"Nhap Can Nang : ";in>>a.cannang;
            cout<<"Nhap chieu cao : ";in>>a.chieucao;
            return in;
           }
           friend ostream & operator <<(ostream & out , VanDongVien & a){
            out<<"Ho ten : "<<a.hoten<<endl;
            out<<"Tuoi : "<<a.tuoi<<endl;
            out<<"mon thi dau : "<<a.monthidau<<endl;
            out<<"Can nang : "<<a.cannang;
            out<<"Chieu cao : "<<a.chieucao;
            return out;
           }
           bool operator > (VanDongVien a){
            if(this->chieucao > a.chieucao){
                return true ;
            }
            else if (this->chieucao == a.chieucao){
                if(this->cannang > a.cannang){
                    return true;
                }
            }
            else {
                return false;
            }
           }
void input(vector<VanDongVien>&athlete, int n){
    for(int i = 0; i < n; i++){
        cin >> athlete[i];
    }
 }
};
void output(vector<VanDongVien>&athlele){
    int size = athlele.size();
    for(int i = 0; i < size; i++){
        cout << athlele[i];
    }
};
int main(){
    VanDongVien p = VanDongVien("Quang", 19,"Cau Long",60,1.75 );
    int n;
    cout << "Nhap N: ";
    cin >> n;
    vector<VanDongVien> athlete(n);
    cout << "Enter information of athlete: " << endl;
    input(a,n);
    int min_index;
    for(int i = 0; i < n - 1; i++){
        min_index = i;
        for(int j = i + 1; j < n; j++){
            if(!athlete[j].operator>(athlete[min_index])){
                min_index = j;
            }
        }
        swap(athlete[min_index], athlete[i]);
    }
    cout << "After sort: " << endl;
    output(athlete);
    return 0;
}