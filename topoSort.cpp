#include <iostream>
#include <queue>
#include <string>


using namespace std;


// Topological sort using Matrix 
template <class T>
class CMatrix
{
public:
       T* pMat;
       CMatrix(int m,int n)
       {
            this->n=n;
            this->m=m;
            pMat=new T[n*m];
            memset(pMat,0,n*m*sizeof(T));
       }
       CMatrix(CMatrix<T>& matrix)
       {
            this->n=matrix.n;
            this->m=matrix.m;
            pMat=new T[matrix.n*matrix.m];
            memcpy(pMat,matrix.pMat,n*m*sizeof(T));
       }
       T& valueOf(int r,int c)
       {
             return pMat[r*n+c];    
       }
       int show()
       {
           for(int i=0;i<m;i++)
           {
                for(int j=0;j<n;j++)
                {
                     cout<<valueOf(i,j)<<' ';
                }
                cout<<endl;
           }
           return 0;
       }
       CMatrix<T> operator*(CMatrix<T>& matrix)
       {
           if(getRowNum()!=matrix.getColNum()) return CMatrix<T>(1,1);
           CMatrix<T> r(getRowNum(),matrix.getColNum());
           for(int i=0;i<getRowNum();i++)
           {
                for(int j=0;j<matrix.getColNum();j++)
                {
                     r.valueOf(i,j)=0;
                     for(int k=0;k<getColNum();k++)
                     {
                          r.valueOf(i,j)=(T)(r.valueOf(i,j)+valueOf(i,k)*matrix.valueOf(k,j));
                     }
                }
           }
           return r;
       }
       int getRowNum()
       {
           return m;
       }
       int getColNum()
       {
           return n;
       }
       ~CMatrix()
       {
            if(pMat!=NULL) delete[] pMat;     
       }
	   bool colIsAllZero(int colNum)
	   {
		   for(int i=0;i<getRowNum();i++)
		   {
			   if(valueOf(i,colNum)!=0)
			   {
				   return 0;
			   }
		   }
		   return 1;
	   }
	   int getColNotZeroCount(int colNum)
	   {
		   int count=0;
		   for(int i=0;i<getRowNum();i++)
		   {
			   if(valueOf(i,colNum)!=0)
			   {
				   count++;
			   }
		   }
		   return count;
	   }
	   bool setRowZero(int rowNum)
	   {
		   memset(pMat+rowNum*sizeof(T)*getColNum(),0,getColNum()*sizeof(T));
		   return 1;
	   }
private:
       int m;
       int n; 
};


string map[] = {"JAVA", "C", "C++", "Ruby", "Lisp", "Scala" }; 


bool isContainer(int *p, int length, int element) 
{
    for (int i = 0; i < length; i++)
    {
        if ( p[i] == element )
        {
            return true; 
        }
    }
    return false;
}

void sort( CMatrix<bool> & mat) 
{
    int *pInDegree = new int[mat.getColNum()];
    queue<int> out; 

    memset(pInDegree, 0, mat.getColNum() * sizeof(int)); 
    for (int i = 0; i < mat.getColNum(); i++)
    {
        pInDegree[i] = mat.getColNotZeroCount(i);
        if ( mat.colIsAllZero(i))
            out.push(i); 
    }
    while (!out.empty()) 
    {
        cout << map[out.front()] << endl;       
        for (int i = 0; i < mat.getColNum(); i++ )
        {
            if (mat.valueOf(out.front(), i) == 1)
            {
                pInDegree[i]--; 
                if (pInDegree[i] == 0 )
                    out.push(i); 
            }

        }
        out.pop(); 
    }
    delete [] pInDegree; 
}


int main(){

    CMatrix<bool> a(6,6); 
    a.valueOf(5,1)=1;
    a.valueOf(5,2)=1;
    a.valueOf(1,3)=1;
    a.valueOf(2,3)=1;
    a.valueOf(1,4)=1;
    a.valueOf(2,4)=1;
    a.valueOf(3,0)=1;
    a.valueOf(4,0)=1;
    a.show();
    sort(a);
    a.show(); 

    return 0; 
}







