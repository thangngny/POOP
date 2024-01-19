#include<iostream>
using namespace std;
struct date
{
    int ngay,thang,nam;
};
class VeMayBay{
    private:
        string TenChuyen;
        date NgayBay;
        double GiaVe;
    public:
         VeMayBay(){};//contructor no prameter
         VeMayBay(string name,date ngaybay,double giave){
            this->TenChuyen=name;
            this->NgayBay=ngaybay;
            this->GiaVe=giave;
         }
         ~VeMayBay(){};//Destructor
         void input(){
            cout<<"Nhap Ten chuyen bay : ";cin>>TenChuyen;
            cout<<"Nhap Ngay Bay : ";cin>>NgayBay.ngay>>NgayBay.thang>>NgayBay.nam;
            cout<<"Nhap Gia Ve : ";cin>>GiaVe;
            cin.ignore();
         }
         void output(){
            cout<<"Chuyen : "<<TenChuyen<<"\t"<<"Ngay Bay : "<<NgayBay.ngay<<"-"<<NgayBay.thang<<"-"<<NgayBay.nam<<"\t"<<"Gia ve : "<<GiaVe<<endl;

         }
         double Getgiave(){
            return GiaVe;
         }
};
class Nguoi
{
    protected:
    string Hoten,Gioitinh;
    int tuoi;
    public:
    Nguoi(){};
    Nguoi(string hoten,string gioitinh,int tuoi){
        this->Hoten=hoten;
        this->Gioitinh=gioitinh;
        this->tuoi=tuoi;
    }
    ~Nguoi(){};
    virtual void input(){
        cout<<"Nhap Ten : ";cin>>Hoten;
        cout<<"Nhap GioiTinh : ";cin>>Gioitinh;
        cout<<"Nhap tuoi : ";cin>>tuoi;
        cin.ignore();
    }
    virtual void output(){
        cout<<"Ten : "<<Hoten<<"\t"<<"GioiTinh : "<<Gioitinh<<"\t"<<"Tuoi : "<<tuoi<<endl;
    }
};
class HanhKhach:public Nguoi
{
    private:
    int SoLuong;
    VeMayBay **listVe;
    public:
    HanhKhach(){};//contructor
    //~HanhKhach(){};//destructor
    void input(){
        Nguoi :: input();
        cout<<"Nhap so luong ve : ";cin>>SoLuong;
        listVe= new VeMayBay*[SoLuong];
        for(int i=0;i<SoLuong;i++){
            listVe[i]=new VeMayBay;
            listVe[i]->VeMayBay::input();
        }
    }
    void output(){
        Nguoi::output();
        for(int i=0;i<SoLuong;i++){
            listVe[i]->VeMayBay::output();
        }
    } 
    ~HanhKhach(){
    for(int i=0;i<SoLuong;i++){
        delete listVe[i];
    }
    delete[] listVe;
    }
    double TongTien(){
        double sum=0;
        for(int i=0;i<SoLuong;i++){
            sum+=listVe[i]->Getgiave();
        }
    }
    void sortGiaVe(HanhKhach*a[],int size){
        int i,j,max;
        for(int i=0;i<size-1;i++){
            max=i;
            for(int j=i+1;j<size;j++){
                if(a[j]->TongTien()>a[i]->TongTien()){
                    max=j;    
                }
            }
        }
        if(i!=max){
             HanhKhach*temp=a[i];
             a[i]=a[max];
             a[max]=temp;
        }
    }
};
int main(){
    int size;
    do{
        cout<<"Nhap so hanh khach : ";
        cin>>size;
    }while (size<0);
    HanhKhach*listHanhKhach=new HanhKhach[size];
    for(int i=0;i<size;i++){
        listHanhKhach[i].input();
    }
    for(int i=0;i<size;i++){
        listHanhKhach[i].output();
    }
    delete[]listHanhKhach;
    
    return 0;
}