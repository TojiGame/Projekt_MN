#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#define ROZMIAR 10
using namespace std;

int main()
{
    float m[ROZMIAR][ROZMIAR], x[ROZMIAR], ratio;
    int i,j,k,n;
    cout<<"-5*x1 +0.5*x2 +0.5*x3 -5*x4 +0.5*x5=-2"<<endl;
    cout<<"-2*x1 -5*x2 +4*x3 +0.5*x4 +0.5*x5=-2"<<endl;
    cout<<"4*x1 +0.5*x2 +2*x3 +0.5*x4 +2*x5=0.5"<<endl;
    cout<<"0.5*x1 +4*x2 +0.5*x3 +0.5*x4 -3*x5=3"<<endl;
    cout<<"3*x1 +2*x2 +4*x3 -2*x4 -3*x5=0.5"<<endl;

    cout<<"(Liczba niewiadomych + liczba po rowna sie)"<<endl;
    cout<<"Podaj ilosc niewiadomych"<<endl;

    cin>>n;
    do
    {
        cout<<"Prosze, wprowadz liczbe calkowitom dodatnia"<<endl;
        cin>>n;
    }
    while(n<=0);
    cout<<"Podaj liczby stojace przy niewiadomych: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n+1;j++)
        {
            cout<<"m["<<i<<"] ["<<j<<"]=";
            cin>>m[i][j];
        }
    }
    //Obliczanie Gaussem
    for(i=1;i<=n-1;i++)
    {
        if(m[i][i]=0,0)
        {
            cout<<"Gdzies jest blad, tylko gdzie?"<<endl;
            return 0;
        }
        for(j=i+1; j<=n;j++)
        {
            ratio=m[j][i]/m[i][i];

            for(k=1;k<=n+1;k++)
            {
                m[j][k]=m[j][k]-ratio*m[i][k];
            }
        }
    }
    x[n] = m[n][n+1]/m[n][n];

    for(i=n-1;i>=1;i--)
    {
        x[i] = m[i][n+1];
        for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - m[i][j]*x[j];
		  }
        x[i] = x[i]/m[i][i];
    }
    cout<<endl<<"Wynik: "<<endl;
    for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }
	 return(0);
}
