#ifndef DynamicArray_h
#define DynamicArray_h

#include <bits/stdc++.h>

/*
Nếu các ông muốn sử dụng thì chỉ cần khai báo DynamicArray<Kiểu dữ liệu các ôg cần> là nó sẽ ra được cái mảng động với kiểu dữ liệu các ông cần chèn vô
Các lệnh trong này thì ý nghĩa như sau
Data là cái mảng trong đó(sử dụng lệnh thì cứ gọi <tên biến>[] như bth)
count là size
cap là cái size của data(tôi dùng để hỗ trợ việc mảng động dạng x2 cho dễ)
lệnh = giữa 2 cái mảng là tôi sử dụng thêm cái hàm copyFrom hỗ trợ
push_back thì cứ hiểu là như vector đi
còn cái lệnh resize thì nó là định nghĩa như sử dụng vector đi=))
*/

template <typename T>
class DynamicArray{
private:
    T* data;
    int count;
    int cap;

    void resize(int newCap){
        T* newData = new T[newCap];
        for(int i = 0 ; i < count ; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

    void copyFrom(const DynamicArray& other){
        count = other.count;
        cap = other.cap;
        if(cap > 0){
            data = new T[cap];
            for(int i = 0 ; i < count ; i++){
                data[i] = other.data[i];
            }
        }else{
            data = nullptr;
        }
    }

    void moveFrom(DynamicArray& other){
        data = other.data;
        count = other.count;
        cap = other.cap;
        other.data = nullptr;
        other.count = 0;
        other.cap = 0;
    }

public:
    DynamicArray() : data(nullptr), count(0), cap(0){}

    ~DynamicArray(){
        delete[] data;
    }

    DynamicArray(const DynamicArray& other){
        copyFrom(other);
    }

    DynamicArray& operator=(const DynamicArray& other){
        if(this != &other) {
            delete[] data;
            copyFrom(other);
        }
        return *this;
    }

    DynamicArray(DynamicArray&& other){
        moveFrom(other);
    }

    DynamicArray& operator=(DynamicArray&& other) {
        if(this != &other) {
            delete[] data;
            moveFrom(other);
        }
        return *this;
    }

    void push(const T& value) {
        if (count == cap){
            int newCap = (cap == 0) ? 4 : cap * 2;
            resize(newCap);
        }
        data[count++] = value;
    }

    void remove(int index) {
        for (int i = index ; i < count - 1 ; i++) {
            data[i] = data[i + 1];
        }
        count--;
    }

    void clear(){
        count = 0;
    }

    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index)const{
        return data[index];
    }

    T& at(int index){
        return data[index];
    }

    const T& at(int index) const{
        return data[index];
    }

    T& get(int index){
        return at(index);
    }

    const T& get(int index) const{
        return at(index);
    }

    int size() const{
        return count;
    }

    int capacity() const{
        return cap;
    }

    bool empty() const{
        return count == 0;
    }
};

#endif
