#include <iostream>
#include <exception>
#include <iomanip>
using namespace std;

class ChessBoardArray {
    protected:

    class Row {
        public:
        Row (ChessBoardArray &a, int i): 
        chess_array(a) , num(i) {} 

        int & operator [] (int i) {
            return chess_array.select(num,i);
        }

        private:
        ChessBoardArray &chess_array;
        int num;
        
    };

    class ConstRow {   
        public:
        ConstRow (const ChessBoardArray &a, int i): 
        chess_array(a) , num(i) {} 
        
         int  operator [] (int i) const  {
            return chess_array.select(num,i);
        }

        private:
        const ChessBoardArray &chess_array;
        int num;
        
    };

    public:
    
    ChessBoardArray (unsigned size = 0, unsigned base = 0){
        length = size;
        start = base;
        array = new int [(length * length + 1)/2];
        for (int i = 0; i < (length * length + 1)/2; ++i) array[i]=0;
    }
    
    ChessBoardArray (const ChessBoardArray &a){
        length = a.length;
        start = a.start;
        array = new int [(length*length+1)/2];
        for (int i = 0; i < (length*length+1)/2; ++i) array[i]=a.array[i];
    }

    ~ChessBoardArray(){
        delete [] array;
    }

    ChessBoardArray & operator = (const ChessBoardArray &a){
        if(&a == this) return *this;
        else{
            delete [] array;
            length = a.length;
            start = a.start;
            array = new int [(length*length+1)/2];
            for (int i = 0; i < (length*length+1)/2; ++i) array[i] = a.array[i];
            return *this;
        }
    }

    int &select (int i, int j) {
        return array[loc(i, j)];
    }
      
    int select (int i, int j) const {
        return array[loc(i, j)];
    }
      
     Row operator [] (int i){
        return Row(*this, i);
    }

     ConstRow operator [] (int i) const {
        return ConstRow(*this, i);
    }

    friend ostream & operator << (ostream &out, const ChessBoardArray &a){
        for ( int i = 0; i < a.length; ++i){
            for ( int j = 0; j< a.length; ++j){
                out << setw(4);
                if ((i + j) % 2 != 0) out << 0;
                else out << a.select(i + a.start, j + a.start);
            }
            out << endl;
        }
        return out;
    }


    private:
    unsigned length; 
    unsigned start;  
    int *array;
    unsigned int loc(int i, int j) const {
        i -= start;
        j -= start;
        if(i<0 || j<0 || i>=length || j>=length || (i+j)%2==1) throw out_of_range("invalid index");
        return (length*i+j)/2;
    }
};

int main(){
    ChessBoardArray a(4, 1); 
a[3][1] = 42;
a[4][4] = 17;
try { a[2][1] = 7; }
catch(out_of_range &e) { cout << "a[2][1] is black" << endl; }
try { cout << a[1][2] << endl; }
catch(out_of_range &e) { cout << "and so is a[1][2]" << endl; }
cout << a;
return 0;
}