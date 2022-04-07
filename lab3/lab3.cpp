#include <iostream>
#include <ctime>

using namespace std;

int main()
{
   
    srand(time(0));
    int n=6;
    long long array[n][n];
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j]=rand()%9+1; 
            cout<<array[i][j]<< " ";
        }
         cout << endl;
    }
    
   int sum=0;
   
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum+=array[i][j]*array[i][j];
        }
       
    }

    cout << "Сумма полученная в с++: " << sum << endl;
  
    int a=0; 
    
    long long *ptr_array=&array[0][0]; 
    long long *end_array=&array[n-1][n-1]; 
       
        asm (
	"movq $0, %%rax\n\t"
	"movq %[ptr_array], %%rbx \n\t"
	"subq $8, %%rbx \n\t"
	"movq $0, %%rcx \n\t"

	"start1: \n\t"
		"addq $8, %%rbx \n\t"
		"movq (%%rbx), %%rax\n\t"
		"mulq %%rax \n\t"
		"addq %%rax, %%rcx \n\t"
		"cmpq %%rbx, %[end_array] \n\t"
		"jne start1 \n\t"
	"movq %%rcx, %%rax \n\t"
		:"=a"(a)
		:[ptr_array]"m"(ptr_array), [end_array]"m"(end_array)
		:"%rbx"
	);
    cout << "Сумма полученная в ассемблере " << a << endl;
    return 0;
}

