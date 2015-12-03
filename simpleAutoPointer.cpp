// smart point uses reference count. once a class object is initialized, ref_count = 1;

using namespace std; 

template<class T>
class SmartPointer {
private:
	T *pt; 
	_counter* pc; 
public:
	SmartPointer(T *t):pc(new _counter(1)) { 
		cout << "SmartPointer::SmartPointer() invoked use is: " << pc -> use << endl; 
		this -> pt = t; 
	}
	SmartPointer(SmartPointer<T> &rhs) {
		this -> pc = rhs.pc; 
		this -> pt = rhs.pt; 
		this -> pc -> use++; 
		cout << "SmartPointer copy invoked use is" << pc -> use << endl; 
	}

	~SmartPointer(){  
            pc->use--;  
            cout<<"SmartPointer::~SmartPointer() invoded use is: "<<pc->use<<endl;  
            if(pc->use == 0)  
            {  
                delete pt;  
                delete pc;  
            }  
        }  
  
    SmartPointer<T>& operator=(SmartPointer<T> rhs){  
            if(rhs == *this){  
                return *this;  
            }  
  
            this->pt = rhs.pt;  
            this->pc = rhs.pc;  
            this->pc->use++;  
            cout<<"SmartPointer::operator=() invoked  use is: "<<pc->use<<endl;  
            return *this;  
        } 


	T & operator *() { return *pt; }
	T * operator -> () {  return pt; } 
};


class _counter {
	template <class T> friend class SmartPointer; 
	_counter(int u):use(u) {}
	~_counter() {}
	int use; 
};


class HasPtr{  
    public:  
        HasPtr(int val):value(val),p(new int(3)){  
            cout<<"HasPtr::HasPtr() invoked"<<endl;  
        }  
        ~HasPtr(){ delete p; cout<<"HasPtr::~HasPtr() invoded"<<endl;}  
  
    private:  
        int *p;  
        int value;  
};  


int main(void)  
{  
    HasPtr *php = new HasPtr(3);  
    SmartPointer<HasPtr> psp(php);  
    SmartPointer<HasPtr> npsp(psp);  
    SmartPointer<HasPtr> nnpsp = npsp;  
  
  
    return 0;  
}  


