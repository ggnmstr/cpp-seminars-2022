#include <iostream>
class Complex {
    public:
        Complex(int rl, int im):rl_(rl),im_(im){
        }
        bool operator==(const Complex &other)const {
            return rl_ == other.rl_ && im_ == other.im_;
        }
        Complex operator+(const Complex &other){
            return Complex(rl_ + other.rl_, im_ + other.im_);
        }
        Complex operator-(const Complex &other){
            return Complex(rl_ - other.rl_, im_ - other.im_);
        }

    private:
        int rl_;
        int im_;
};


int main(){
    Complex a(1,2);
    Complex b(10,123);
    Complex c = a;
    std::cout << (c == a) << std::endl;
    return 0;
}