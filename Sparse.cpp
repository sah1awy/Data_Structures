#include<iostream>
using namespace std;
class Element{
public:
    int i;
    int j;
    int x;
};
class Sparse{
private:
    int m;
    int n;
    int num;
    struct Element *e;
public:
    Sparse(int m,int n,int num){
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[this->num];
    }
    void read(){
        cout << "Enter the matrix" << endl;
        for(int i=0;i<num;i++)
            cin >> e[i].i >> e[i].j >> e[i].x;
    }
    void display(){
        int i ,j,k=0;
        for(i=0;i< m;i++){
            for(j=0;j<n;j++){
                if(e[k].i == i && e[k].j == j)
                    cout << e[k++].x << " ";
                else
                    cout <<"0 ";
            }
            cout << endl;
        }
    }
    ~Sparse(){
        delete [] e;
    }
};
int main(){
    Sparse s1(3,3,3);
    s1.read();
    s1.display();
    return 0;
}
