#include <iostream>
#include <stdexcept>
using namespace std;

class complex{
	private:
		double real;
		double imag;
	public:
		complex(double r=0.0,double i=0.0): real(r),imag(i){}
		friend ostream& operator<<(ostream& os,const complex& c){
			if(c.imag>0){
				os<<c.real<<"+"<<c.imag<<"i";
			}else{
				os<<c.real<<""<<c.imag<<"i";
			}
			return os;
		} 
};

class rational{
	private:
		int num;
		int den;
	public:
		rational(int n=0,int d=1): num(n),den(d){
		if (d == 0)
            throw runtime_error("Denominator cannot be zero!");
		}
		friend ostream& operator<<(ostream& os,const rational& r){
			os<<r.num<<"/"<<r.den;
			return os;
		}
};

class vector{
	private:
		int x,y,z;
	public:
		vector(int a=0,int b=0,int c=0): x(a),y(b),z(c){}
		friend ostream& operator<<(ostream& os,const vector& v){
			os<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
			return os;
		}
};

template<typename T>
class matrix33{
	protected:
		T data[3][3];
	public:
		matrix33(){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					data[i][j]=0;
				}
			}
		}
		matrix33(T value){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					data[i][j]=value;
				}
			}
		}
		
		void setvalue(int i,int j,T value){
			data[i][j]=value;
		}
		T getvalue(int i,int j){
			return data[i][j];
		}
		friend ostream& operator<<(ostream& os,const matrix33& m){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					os<<m.data[i][j]<<" ";
				}
				os<<endl;
			}
			return os;
		}
};

template<typename T>
class null33: public matrix33<T>{
	public:
		null33(): matrix33<T>(T()){}
		void display(){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<this->data[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

template<typename T>
class identity33:public matrix33<T>{
	public:
		identity33(){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					this->data[i][j]= (i==j)? T(1): T(0);
				}
			}
		}
		void display(){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<this->data[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

class mexception33: public exception{
	private:
		int code;
		string message;
	public:
		mexception33(int c,string m): code(c),message(m){}
		const char* what() const throw(){
			return message.c_str();
		}
		int getcode() const{
			return code;
		}
};

int main(){
	try{
		matrix33<int>m1;
	m1.setvalue(0,0,1);
	m1.setvalue(0,1,2);
	m1.setvalue(0,2,3);
	m1.setvalue(1,0,4);
	m1.setvalue(1,1,5);
	m1.setvalue(1,2,6);
	m1.setvalue(2,0,7);
	m1.setvalue(2,1,8);
	m1.setvalue(2,2,9);
	cout<<"Int matrix: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<m1.getvalue(i,j)<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	matrix33<float>m2;
	m2.setvalue(0,0,1.4);
	m2.setvalue(0,1,2.5);
	m2.setvalue(0,2,3.2);
	m2.setvalue(1,0,4.6);
	m2.setvalue(1,1,5.9);
	m2.setvalue(1,2,6.5);
	m2.setvalue(2,0,7.4);
	m2.setvalue(2,1,8.3);
	m2.setvalue(2,2,3.4);
    cout<<"Float matrix: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<m2.getvalue(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	matrix33<complex>m3;
	m3.setvalue(0,0,complex(3,5));
	m3.setvalue(0,1,complex(4,5));
	m3.setvalue(0,2,complex(6,7));
	m3.setvalue(1,0,complex(3,8));
	m3.setvalue(1,1,complex(2,5));
	m3.setvalue(1,2,complex(6,7));
	m3.setvalue(2,0,complex(3,3));
	m3.setvalue(2,1,complex(3,1));
	m3.setvalue(2,2,complex(3,8));
	cout<<"Complex matrix: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<m3.getvalue(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	matrix33<vector>m4;
	m4.setvalue(0,0,vector(1,2,3));
	m4.setvalue(1,1,vector(2,4,3));
	m4.setvalue(1,2,vector(5,6,2));
	m4.setvalue(2,1,vector(1,6,8));
	m4.setvalue(2,2,vector(1,2,3));
	cout<<"Vector matrix: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<m4.getvalue(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	matrix33<rational>m5;
	m5.setvalue(0,0,rational(2,3));
	m5.setvalue(1,1,rational(1,4));
	m5.setvalue(0,2,rational(2,6));
	m5.setvalue(0,1,rational(9,1));
	m5.setvalue(1,2,rational(2,3));
	m5.setvalue(2,2,rational(1,2));
	cout<<"Rational matrix: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<m5.getvalue(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
    null33<int>n;
    cout<<"Null matrix: "<<endl;
    n.display();
    cout<<endl;
    cout<<"Identity matrix: "<<endl;
    identity33<int>i;
    i.display();
	}
	catch(const exception& e){
		cout<<"Error: "<<e.what()<<endl;
	}
	
	return 0;
}
