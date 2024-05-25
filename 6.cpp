#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
class Printable{
public:
    virtual void print(const vector<int>& arr) = 0;
};

class LinePrintable: public Printable{
public:
    LinePrintable(int n): _n(n) {}
    void print(const vector<int>& arr) override{
        for (int i = 0; i < arr.size(); i++){
            cout << setw(_n) << arr[i] << " ";
        }
        cout << endl;
    }
private:
    int _n;
};

class IndentedPrintable: public Printable{
public:
    void print(const vector<int>& arr) override{
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Printable* linePrintable = new LinePrintable(5);
    Printable* indentedPrintable = new IndentedPrintable();

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    linePrintable->print(arr);
    indentedPrintable->print(arr);

    delete linePrintable;
    delete indentedPrintable;
    return 0;
}
