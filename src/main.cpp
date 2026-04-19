#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;

    /*--------------------------
    Buat loop untuk membuat menginputkan data triangle (3 buah X Y Z data) ke dalam
    variable triangles
    --------------------------*/
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        float x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point2D p1(x1, y1);
        Point2D p2(x2, y2);
        Point2D p3(x3, y3);
        triangles.push_back(Triangle(p1, p2, p3));
    }

    /*------------------------*/


    /*--------------------------
    Implementasikan kode untuk melakukan pengecekan apakah data pada variable triangles
    adalah "sama kaki", "sama sisi", "siku-siku", atau "sembarang"
    --------------------------*/
    for(const auto& t : triangles) {
        cout << t.GetType() << endl;
    }

    /*------------------------*/

    return 0;
}