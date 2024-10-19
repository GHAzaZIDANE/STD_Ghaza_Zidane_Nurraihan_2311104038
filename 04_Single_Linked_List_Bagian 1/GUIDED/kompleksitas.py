def maximum(A):
    # Mengembalikan nilai maksimum dari array A
    maxval = A[0]  # Inisialisasi nilai maksimum dengan elemen pertama
    for i in range(1, len(A)):  # Mulai iterasi dari elemen kedua hingga terakhir
        if A[i] > maxval:  # Jika elemen saat ini lebih besar dari maxval
            maxval = A[i]  # Perbarui maxval dengan elemen tersebut
    return maxval  # Kembalikan nilai maksimum

array = [3, 1, 4, 1, 5, 9, 2, 6, 5]
print("Nilai maksimum dalam array:", maximum(array))