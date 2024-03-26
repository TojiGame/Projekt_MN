#include <iostream>
#include <math.h>
using namespace std;
typedef struct {
double **mat;
int m;
int n;
} matrix;
void pamiecDel(matrix *w)
{
for (int i = 0; i < w->m; ++i)
delete []w->mat[i];
delete []w->mat;
}
void pamiecNew(matrix *w, const int& m_, const int& n_)
{
w->mat = new double* [m_];
for (int i = 0; i < m_; i++){
w->mat[i] = new double[n_];
}
w->m = m_;
w->n = n_;
}
int wypisz(const matrix *a){
for(int i = 0; i < a->m; i++){
for(int j = 0; j < a->n; j++){
printf("%2.2f ", a->mat[i][j]);
}
cout << endl;
}
cout << "\n" << endl;
return 0;
}
void interpolacjaL(double *x, double *y, unsigned int size){
double *table = new double[size];
double wynik = 0;
matrix d;
pamiecNew(&d, size, size);
for(int i = 0; i < size; i++){
for(int j = 0; j < size; j++){
if(j == 2)
d.mat[i][j] = 1;
for(int k = 0; k < size; k++){
if(k != i){
if(j == 1)
d.mat[i][j] -= x[k];
else {
d.mat[i][j] *= -x[k];
}
}
}
}
}
for(int i = 0; i < size; i++){
table[i] = 1;
for(int j = 0; j < size; j++){
if(j != i){
table[i] *= (x[i] - x[j]);
}
}
table[i] = y[i] / table[i];
}
double a = table[0] + table[1] + table[2];
double b = table[0] * d.mat[0][1] + table[1] * d.mat[1][1] + table[2] * d.mat[2][1];
double c = table[0] * d.mat[0][2] + table[1] * d.mat[1][2] + table[2] * d.mat[2][2];
pamiecDel(&d);
cout << "Interpolacja Lagrange'a\n" << endl;
cout << "a = " << a << endl;
cout << "b = " << b << endl;
cout << "c = " << c << endl;
}
double g(double x, int i){
if(i >= 0 && i <= 1)
return -13879 * x * x + 1641.59 * x + 71.8237;
if(i >= 2 && i <= 3)
return 40034.7 * x * x -13499.9 * x + 1068.29;
if(i >= 4 && i <= 5)
return -61124 * x * x + 34381.1 * x - 4528.45;
if(i >= 6 && i <= 7)
return 74366.8 * x * x - 58840.4 * x + 11398.4;
if(i >= 8 && i <= 9)
return -77131.4 * x * x + 79417.7 * x - 19957.2;
if(i >= 10 && i <= 11)
return 67819.8 * x * x - 87292.1 * x + 27632.2;
if(i >= 12 && i <= 13)
return -45275.8 * x * x + 73260.5 * x - 28656.6;
if(i >= 14 && i <= 15)
return 9613.21 * x * x - 28677.3 * x + 16654.3;
if(i >= 16 && i <= 17)
return 38504.5 * x * x - 53485 * x + 17057;
if(i >= 18 && i <= 19)
return -274188 * x * x + 522528 * x - 247996;
return 0;
}
int main(){
int n = 20;
double tab1[n] = {534.035,537.32,533.621,506.696,603.526,449.727,542.791,668.92,247.542,805.055,470.622,198.953,1147.33,-86.6649,660.822,1071.95,-599.849,1570.2,187.366,-340.953};
double tab2[n] =
{0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1};
double y[3];
double x[3];
int l = 0;
for(int j = 0; j < 10; j++)
{
if(l+2 < 20)
{
y[0] = tab1[l];
y[1] = tab1[l+1];
y[2] = tab1[l+2];
x[0] = tab2[l];
x[1] = tab2[l+1];
x[2] = tab2[l+2];
cout << "Wspolrzedne punktow:" << endl;
for(int i = 0; i < 3; i++)
{
cout << "x" << i << " = " << x[i] << endl;
cout << "y" << i << " = " << y[i] << endl;
}
cout << "\n" << endl;
interpolacjaL(x, y, 3);
cout << "\n" << endl;
}
else
{
l = 17;
y[0] = tab1[l];
y[1] = tab1[l+1];
y[2] = tab1[l+2];
x[0] = tab2[l];
x[1] = tab2[l+1];
x[2] = tab2[l+2];
cout << "Wspolrzedne punktow:" << endl;
for(int i = 0; i < 3; i++)
{
cout << "x" << i << " = " << x[i] << endl;
cout << "y" << i << " = " << y[i] << endl;
}
cout << "\n" << endl;
interpolacjaL(x, y, 3);
cout << "\n" << endl;
}
l += 2;
}
double a = 0;
double b = 1;
double x_l, x_p, x_s;
double calka = 0.0;
double h = 0.0526316;
for(int i = 0 ; i < n-1 ; i++){
x_l = a + i * h;
x_p = a + i * h + h;
x_s = a + i * h + (h/2);
calka += (h / 6) * (g(x_l, i) + 4 * g(x_s, i) + g(x_p, i));
}
cout << "Calka funkcji interpolacyjnej: "<< calka << '\n';
}
