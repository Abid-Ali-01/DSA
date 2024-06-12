#include <iostream>
using namespace std;

class Array{

private:
static const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int currentSize;

public:
Array(): currentSize(0){}

int getSize(){
    return currentSize;
}

void displayArray(){
    for(int i = 0; i < currentSize; i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

void insertElement(int element, int index){
    if(index < 0 || index > currentSize){
        cout<<"Invalid Index Provided"<<endl;
    }

    for( int i = currentSize; i < index ; --i){
        arr[i] = arr[i-1];
    }
        arr[index] = element;
        currentSize ++;
}

void deleteElement(int index){
    if(index < 0 || index > currentSize){
        cout<<"Invalid Index Provided"<<endl;
    }
    for(int i = index; i < currentSize; i++){
        arr[i] = arr[i+1];
    }
    currentSize--;
}

int searchElement(int element) {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1; // Element not found
    }
};

int main (){

Array myArray;
int choice , element, index;

do {
        cout << "\nMenu:\n";
        cout << "1. Display array\n";
        cout << "2. Insert element\n";
        cout << "3. Delete element\n";
        cout << "4. Search element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myArray.displayArray();
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter Index to insert (0 to " << myArray.getSize() << "): ";
                cin >> index;
                myArray.insertElement(element, index);
                break;

            case 3:
                cout << "Enter Index to delete (0 to " << myArray.getSize() - 1 << "): ";
                cin >> index;
                myArray.deleteElement(index);
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                index = myArray.searchElement(element);
                if (index != -1) {
                    cout << "Element found at position " << index << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;


        }//End of Switch


}while (choice != 5);//End of DO


return 0;
}//End of Program