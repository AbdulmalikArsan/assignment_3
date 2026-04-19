# Programming Assignment 3: Triangle Classification

## Deskripsi Program

Program ini mengimplementasikan sistem klasifikasi segitiga berdasarkan jenis-jenisnya. Program menerima input berupa koordinat 3 titik (sebagai representasi segitiga) dan menentukan apakah segitiga tersebut termasuk:

- **Sama sisi** (equilateral): ketiga sisi memiliki panjang yang sama
- **Sama kaki** (isosceles): dua sisi memiliki panjang yang sama
- **Siku-siku** (right-angled): memenuhi teorema Pythagoras (a² + b² = c²)
- **Sembarang** (scalene): ketiga sisi memiliki panjang berbeda

## Struktur Kode

### File-file yang diimplementasikan:

1. **`src/include/point2d.hpp`** - Header untuk class Point2D
   - Menyimpan koordinat 2D (x, y)
   - Method `Distance()` untuk menghitung jarak antar 2 titik

2. **`src/point2d.cpp`** - Implementasi class Point2D
   - Constructor: `Point2D()` dan `Point2D(float x, float y)`
   - Getter: `GetX()`, `GetY()`
   - Setter: `SetX()`, `SetY()`
   - `Distance(const Point2D& other)` - menghitung jarak menggunakan rumus Euclidean: $\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$

3. **`src/include/triangles.hpp`** - Header untuk class Triangle
   - Menyimpan 3 titik sebagai Point2D
   - Method `GetType()` untuk menentukan jenis segitiga

4. **`src/triangles.cpp`** - Implementasi class Triangle
   - Constructor: `Triangle()` dan `Triangle(Point2D t1, Point2D t2, Point2D t3)`
   - Setter: `SetT1()`, `SetT2()`, `SetT3()`
   - `GetType()` - mengklasifikasikan segitiga berdasarkan panjang sisi

5. **`src/main.cpp`** - Program utama
   - Input: jumlah segitiga (N) dan koordinat masing-masing (6 nilai: x1, y1, x2, y2, x3, y3)
   - Output: jenis segitiga untuk setiap input

## Algoritma Klasifikasi

```
1. Hitung panjang ketiga sisi menggunakan Distance()
   a = jarak(p1, p2)
   b = jarak(p2, p3)
   c = jarak(p3, p1)

2. Urutkan sisi dari terkecil ke terbesar
   sides[0] ≤ sides[1] ≤ sides[2]

3. Cek kondisi (tolerance: 1e-5):
   - Jika |sides[0] - sides[1]| < ε AND |sides[1] - sides[2]| < ε
     → Sama sisi
   - Jika sides[0]² + sides[1]² ≈ sides[2]²
     → Siku-siku
   - Jika |a - b| < ε OR |b - c| < ε OR |a - c| < ε
     → Sama kaki
   - Selainnya
     → Sembarang
```

## Cara Kompilasi dan Menjalankan

### Kompilasi:
```bash
g++ -std=c++11 -Wall -Isrc src/main.cpp src/point2d.cpp src/triangles.cpp -o myapp.exe
```

### Menjalankan:

**Opsi 1: Input interaktif**
```bash
./myapp.exe
4
0 0 3 0 0 4
0 0 1 0 2 3
0 0 2 0 1 2
0 0 2 0 1 1.732
```

**Opsi 2: Dari file**
```bash
Get-Content test.txt | ./myapp.exe
```

## Contoh Input dan Output

### Input:
```
4
0 0 3 0 0 4
0 0 2 0 1 1.732
0 0 2 0 1 2
0 0 1 0 2 3
```

### Output:
```
siku-siku
sama sisi
sama kaki
sembarang
```

### Penjelasan:

| No | Koordinat | Perhitungan Sisi | Hasil | Alasan |
|---|-----------|------------------|-------|--------|
| 1 | (0,0)-(3,0)-(0,4) | Sisi: 3, 4, 5 | **siku-siku** | $3^2 + 4^2 = 9 + 16 = 25 = 5^2$ |
| 2 | (0,0)-(2,0)-(1,1.732) | Sisi: 2, 2, 2 | **sama sisi** | Ketiga sisi sama panjang |
| 3 | (0,0)-(2,0)-(1,2) | Sisi: 2, √5, √5 | **sama kaki** | Dua sisi sama panjang (√5 ≈ 2.236) |
| 4 | (0,0)-(1,0)-(2,3) | Sisi: 1, √10, √13 | **sembarang** | Semua sisi berbeda panjang |

## Testing

Program telah diuji dengan berbagai kasus:

✅ **Siku-siku**: Triangle 3-4-5 (klasik Pythagoras)
✅ **Sama sisi**: Semua sisi = 2 unit
✅ **Sama kaki**: Dua sisi = √5 unit, satu sisi = 2 unit
✅ **Sembarang**: Sisi 1, √10, √13

Semua test case menghasilkan output yang sesuai dengan ekspektasi.

## Catatan Implementasi

- Menggunakan namespace `std` untuk kemudahan
- Tolerance untuk perbandingan float: **1e-5**
- Koordinat berbentuk `float` untuk presisi desimal
- Menggunakan STL `vector` untuk menyimpan koleksi Triangle
- Class Point2D dan Triangle dipisahkan untuk modularitas kode
