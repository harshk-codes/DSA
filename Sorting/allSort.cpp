#include <iostream>

using namespace std;

class Collection {
    private:
        int *data;
        int max;
        int cur_size;

    public:
        Collection() {
            cur_size = 0;
            max = 0;
            data = NULL;
        }
        
        Collection(int S) {
            data = (int*)malloc(sizeof(int)*S);
        }

        ~Collection() {
            free(data);
        }

        void insertData(int x);

        void display();

        //Sorting algos
        void bubble();
        void selection();
        void insertion();
        void quick();
        void merge();
};

void Collection::insertData(int x) {
    //code here
}
void Collection::display() {
    //code here
}

//Sorting algos
void Collection::bubble() {
    //code here
}

void Collection::selection() {
    //code here
}

void Collection::insertion() {
    //code here
}

void Collection::quick() {
    //code here
}

void Collection::merge() {
    //code here
}


int main() {

    Collection C;
    C.insertData(50);
    C.insertData(45);
    C.insertData(2);
    C.insertData(47);
    C.insertData(88);
    C.insertData(90);
    C.insertData(69);
    C.insertData(31);
    C.insertData(30);
    C.insertData(7);

    cout<<"Current array is: "<<endl;
    C.display();

    cout<<"Array after bubble sort is: "<<endl;
    C.bubble();
    C.display();

    cout<<"Array after selection sort is: "<<endl;
    C.selection();
    C.display();

    cout<<"Array after insertion sort is: "<<endl;
    C.insertion();
    C.display();

    cout<<"Array after quick sort is: "<<endl;
    C.quick();
    C.display();

    cout<<"Array after merge sort is: "<<endl;
    C.merge();
    C.display();
    return 0;
}