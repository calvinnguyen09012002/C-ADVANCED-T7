#include <iostream>
#include <string>

using namespace std;


class Sinhvien{
    private:
    //Properties
        int ID;
        string NAME;
        int OLD;
        string LOP;
    public:
    //Constructor
    Sinhvien(string name, int old, string lop){
        static int id = 100;
        ID = id;
        id++;

        NAME = name;
        OLD = old;
        LOP = lop;
    }

    //Method
    void Set_Name(string name){
        NAME = name;
    }

    void Set_Lop(string lop){
        LOP = lop;
    }

    void Set_Old(int old){
        OLD = old;
    }

    int Get_ID(){
        return ID;
    }
    string Get_Name(){
        return NAME;
    }
    string Get_Lop(){
        return LOP;
    }
    int Get_Old(){
        return OLD;
    }
    //Properties
        //string NAME;
        //int OLD;
        //string LOP;

    //Destructor
    //~Sinhvien(){
    //    cout<<NAME<<endl;
    //}
};

void Test(){
    Sinhvien sv1 = {"KHANH", 21, "DDT20TDH01"};
    Sinhvien sv2 = {"MINH", 21, "DDT20TDH02"};
    Sinhvien sv3 = {"NGHIA", 21, "DDT20TDH03"};
}

void Print_Infor(Sinhvien sv){
    cout<<"ID: "<<sv.Get_ID()<<endl;
    cout<<"NAME: "<<sv.Get_Name()<<endl;
    cout<<"TUOI: "<<sv.Get_Old()<<endl;
    cout<<"LOP: "<<sv.Get_Lop()<<endl;
}

void Edit(Sinhvien &sv){
    sv.Set_Name("NGUYEN");
}

int main(int argc, char const *argv[])
{
    Sinhvien sv = {"PHUC", 21, "DDT20TDH01"};
    Edit(sv);
    Print_Infor(sv);
    cout<<"----------"<<endl;
    Sinhvien sv1 = {"HUY", 23, "DDT20TDH04"};
    Print_Infor(sv1);

    //Test();
    return 0;
}
