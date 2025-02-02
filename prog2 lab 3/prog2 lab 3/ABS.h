
#include <iostream>
//#include "leaker.h"
//#include "leaker.cpp"
//#include "ABS.h"
using namespace std;



template <typename T>
class ABS {
    //variables
private:
    float _scaleFactor;
    int _currentSize;
    int _capacity;
    T* _stackArrayPointer = nullptr;
public:
    //constructors
    ABS() {
        _capacity = 1;
        _currentSize = 0;
        _scaleFactor = 2.0f;
        _stackArrayPointer = new T[_capacity];

    }
    ABS(int capacity) {
        _capacity = capacity;
        _currentSize = 0;
        _scaleFactor = 2.0f;
        _stackArrayPointer = new T[_capacity];
    }
    ABS(const ABS& d) {
        _capacity = d.capacity;
        _currentSize = d.currentSize;
        _scaleFactor = d.scaleFactor;
        _stackArrayPointer = d._stackArrayPointer;
        _stackArrayPointer = new T[_capacity];
        for (int i = 0; i < _currentSize; i++) {
            _stackArrayPointer[i] = d.stackArrayPointer[i];
        }
    }
    ABS& operator=(const ABS& d) {
        _capacity = d.capacity;
        _currentSize = d.currentSize;
        _scaleFactor = d.scaleFactor;
        _stackArrayPointer = d._stackArrayPointer;

        for (int i = 0; i < _currentSize; i++) {
            _stackArrayPointer[i] = d.stackArrayPointer[i];
        }
        return *this;
    }
    ~ABS() {
        delete[] _stackArrayPointer;
    }

    //functions
    void push(T data) {
        //cout << "new pushed current size " << _currentSize << endl;
        if (_currentSize == _capacity) {

            _capacity *= _scaleFactor;

            T* tempArray = new T[_capacity];

            for (int i = 0; i < _currentSize; i++) {
                tempArray[i] = _stackArrayPointer[i];
            }
            //tempArray[_currentSize] = data;
            //_currentSize++;
            delete[] _stackArrayPointer;
            _stackArrayPointer = tempArray;
            //delete[] tempArray;


            /*
            tempArray = _stackArrayPointer;
            tempArray.push_back(data);
            _stackArrayPointer = tempArray;
            delete tempArray;
            */
        }
        _stackArrayPointer[_currentSize] = data;
        _currentSize++;
        

    }
    
    T pop() {
        if (_currentSize == 0) {
            throw runtime_error("An error has occured");
        }
        
        _currentSize--;
        //cout << "popped current size " << _currentSize << endl;

        T poppedValue = _stackArrayPointer[_currentSize];

        if (_currentSize == 0) {

            poppedValue = 1;
        }

        float halfCapacity = _capacity / _scaleFactor;
        //cout << "half capacity " << halfCapacity << endl;

        if (_currentSize < halfCapacity && halfCapacity!=0) {
            _capacity = halfCapacity;

            T* tempArray = new T[_capacity];
            for (int i = 0; i < _currentSize; i++) {
                tempArray[i] = _stackArrayPointer[i];
            }
            //T removed_value = _stackArrayPointer[_currentSize-1];

            //_currentSize--;
            delete[] _stackArrayPointer;
            _stackArrayPointer = tempArray;

            //delete[] tempArray;

            //return removed_value;
        }
        else {
            T* tempArray = new T[_capacity];
            for (int i = 0; i < _currentSize; i++) {
                tempArray[i] = _stackArrayPointer[i];
            }
            //T removed_value = _stackArrayPointer[_currentSize-1];

            //_currentSize--;
            delete[] _stackArrayPointer;
            _stackArrayPointer = tempArray;
            //delete[] tempArray;
        }

        return poppedValue;


    }
    
    T peek() {
        if (_currentSize == 0) {
            throw runtime_error("An error has occured");
        }
        T recentValue = _stackArrayPointer[_currentSize - 1];
        return recentValue;
        
    }
    unsigned int getSize() {
        return _currentSize;
     }
    unsigned int getMaxCapacity() {
        return _capacity;
    }
    T* getData() {
        return _stackArrayPointer;
    }
        
};
      