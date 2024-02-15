# Command Line Brainfuck Interpreter
Interpreter ini dibuat untuk menjalankan kode brainfuck langsung melalui command line.
Sayangnya, ini hanya dapat dipakai dengan OS Windows karena adanya penggunaan `getch()` yang ada pada header `<conio.h>`, yang dikhususkan untuk Windows.

#### Tapi gimana bisa bikin command baru?
Caranya simpel, kamu bisa ambil file `brainf.exe` yang ada di repository ini, dan masukkan file tersebut ke dalam folder `C:\Windows\System32`.
Jika menurutmu ini berbahaya karena file executable ini dapat memiliki sesuatu yang tak terduga, kamu bisa compile file `brainf.cpp` terlebih dahulu menjadi `brainf.exe`.
Kamu juga dapat melihat sendiri bahwa kode yang ada itu tidak memiliki sesuatu yang tak terduga (ya sudah tau jadinya sudah terduga).

#### Lalu cara pakainya gimana?
Jika langkah diatas sudah dilakukan, kamu sudah memiliki command baru yang bernama `brainf`.
Cukup ketik command itu di command line dan kamu dapat melihat cara pemakaian command itu.

#### Kok nama commandnya "brainf" sih? Mau ganti namanya!
Tenang saja, nama command tersebut ditentukan dari nama file executable-nya itu sendiri, jadi kamu cukup mengganti nama file tersebut menjadi apa saja yang kamu inginkan.
Sebagai contoh, jika kamu mau nama commandnya menjadi `bf`, kamu dapat mengganti nama `brainf.exe` menjadi `bf.exe`.

#### Kok penjelasannya masih pakai `brainf` sih?
Ya itu karena saya belum bisa buat penjelasannya menyesuaikan nama filenya, jadi tunggu untuk update kedepannya!

#### Brainfuck apaan dah???
Liat Google coy, gampang brainfuck tuh cuman ada 8 command, harus dicoba pelajarin
