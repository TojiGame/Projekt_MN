#include <iostream>
#include <math.h>
using namespace std;

long double f(long double a, long double b, long double x)
{
return a*x + b;
}
int main()
{
const int m = 20;
int z = 2;
long double Y[m] = {534.035,537.32,533.621,506.696,603.526,449.727,542.791,668.92,247.542,805.055,470.622,198.953,1147.33,-86.6649,660.822,1071.95,-599.849,1570.2,187.366,-340.953};
long double X[m] =
{0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1};
long double B[z][z+1];
long double p[z][1];
long double suma_x = 0;
long double suma_x2 = 0;
long double suma_y = 0;
long double suma_xy = 0;
B[0][0]= m;
for(int i = 0; i < m; i++)
{
suma_x += X[i];
suma_y += Y[i];
suma_x2 += X[i]*X[i];
suma_xy += X[i]*Y[i];
}
B[0][1] = suma_x;
B[1][0] = suma_x;
B[1][1] = suma_x2;
B[0][2] = suma_y;
B[1][2] = suma_xy;
for(int s = 0; s <= z-1 ; s++)
{
for(int i = s+1; i < z; i++)
{
for(int j = s+1; j <= z+1; j++)
{
B[i][j]=B[i][j] - B[i][s]/B[s][s] * B[s][j];
}
}
}
p[z-1][0] = B[z-1][z]/B[z-1][z-1];
for(int i = z - 2; i >= 0; i--){
long double suma = 0.0;
for(int s = i + 1; s < z; s++){
suma += B[i][s] * p[s][0];
}
p[i][0] = (B[i][z] - suma) / B[i][i];
}
cout << "Wspolczynniki funkcji aproksymacyjnej: " << endl;
cout << "a = " << p[1][0] <<endl;
cout << "b = " << p[0][0] << '\n' << endl;
cout << "Kolejne punkty: " << endl;
for(int i = 0; i < m; i++)
{
cout << "f(" << i << ") = " << f(p[1][0], p[0][0], X[i]) << endl;
}
return 0;
}
