# SoalShiftSISOP20_modul3_C08
### VANIA MEILANI TAQIYYAH - 05111840000045 ###
### IVAN ABDILLAH RAHMAN - 0511840000137 ###

#### SOAL 1
```
Poke*ZONE adalah sebuah game berbasis text terminal mirip dengan Pokemon GO.
Ketentuan permainan sebagai berikut:
a. Menggunakan IPC-shared memory, thread, fork-exec.
b. Kalian bebas berkreasi dengan game ini asal tidak konflik dengan
requirements yang ada. (Contoh: memberi nama trainer, memberi notifikasi
kalau barang di shop sudah penuh, dan lain-lain).
c. Terdapat 2 code yaitu soal2_traizone.c dan soal2_pokezone.c.
d. soal2_traizone.c mengandung fitur:
i. Normal Mode (3 Menu)
1. Cari Pokemon
a. Jika diaktifkan maka setiap 10 detik akan memiliki
60% chance untuk menemui pokemon bertipe normal,
rare, legendary dengan encounter rate sesuai pada
tabel di bawah (Gunakan Thread).
b. Cari pokemon hanya mengatur dia menemukan
pokemon atau tidak. Untuk tipe pokemon dan pokemon
tersebut shiny atau tidak diatur oleh soal2_pokezone.c.
c. Opsi “Cari Pokemon” akan berubah jadi “Berhenti
Mencari” ketika state mencari pokemon aktif.
d. State mencari pokemon hanya bisa dihentikan ketika
pokemon sudah ditemukan atau trainer memilih untuk
berhenti pada menu.
e. Jika menemui pokemon maka akan masuk ke Capture
Mode.
f. Untuk mempermudah boleh menambah menu go to
capture mode untuk berpindah dari mode normal ke
mode capture setelah menemukan pokemon dari
thread Cari Pokemon.

2. Pokedex
a. Melihat list pokemon beserta Affection Point (AP) yang
dimiliki.
b. Maksimal 7 pokemon yang dimiliki.
c. Jika menangkap lebih dari 7 maka pokemon yang baru
saja ditangkap akan langsung dilepas dan
mendapatkan pokedollar sesuai dengan tabel dibawah.
d. Setiap pokemon yang dimiliki, mempunyai Affection
Point (AP) dengan initial value 100 dan akan terus
berkurang sebanyak -10 AP/10 detik dimulai dari
waktu ditangkap (Gunakan Thread).
e. Jika AP bernilai 0, maka pokemon tersebut memiliki
90% chance untuk lepas tanpa memberikan pokedollar
ke trainer atau 10% chance untuk reset AP menjadi 50
AP.
f. AP tidak akan berkurang jika dalam Capture Mode.

g. Di Pokedex trainer juga bisa melepas pokemon yang
ditangkap dan mendapat pokedollar sesuai dengan
tabel dibawah.
h. Bisa memberi berry ke semua pokemon yang dimiliki
untuk meningkatkan AP sebesar +10 (1 berry untuk
semua pokemon yang ada di pokedex).

3. Shop
a. Membeli item dari soal2_pokezone.
b. Maksimal masing-masing item yang dapat dibeli dan
dipunya oleh trainer adalah 99.

ii. Capture Mode (3 Menu)
1. Tangkap → Menangkap menggunakan pokeball. Berhasil
ditangkap maupun tidak, pokeball di inventory -1 setiap
digunakan.
2. Item → Menggunakan item sesuai dengan tabel item dibawah
(hanya lullaby powder).
3. Keluar → Keluar dari Capture Mode menuju Normal Mode.
● Pokemon tersebut memiliki peluang untuk lari dari trainer
sesuai dengan persentase escape rate pada tabel dibawah
(gunakan thread).
e. soal2_pokezone.c mengandung fitur:
i. Shutdown game → Mematikan program soal2_pokezone dan
soal2_traizone (Gunakan fork-exec).
ii. Jual Item (Gunakan Thread)
1. Stock awal semua item adalah 100.
2. Masing-masing item akan bertambah +10 item/10 detik.
3. Maximum item yang dalam shop adalah 200.
4. List item ada pada tabel dibawah.
```

#### SOAL 2
```
Qiqi adalah sahabat MamMam dan Kaka. Qiqi , Kaka dan MamMam sangat senang
bermain “Rainbow six” bersama-sama , akan tetapi MamMam sangat Toxic ia selalu
melakukan Team killing kepada Qiqi di setiap permainannya. Karena Qiqi orang yang
baik hati, meskipun marah Qiqi selalu berkata “Aku nggk marah!!”. Kaka ingin
meredam kemarahan Qiqi dengan membuatkannya sebuah game yaitu TapTap
Game. akan tetapi Kaka tidak bisa membuatnya sendiri, ia butuh bantuan mu. Ayo!!
Bantu Kaka menenangkan Qiqi.
TapTap Game adalah game online berbasis text console. Terdapat 2 program yaitu
tapserver.c dan tapplayer.c
Syarat :
- Menggunakan Socket, dan Thread
Hint :
- fwrite, fread
Spesifikasi Game :

CLIENT SIDE

Screen 1 :
1. Login
2. Register
Choices : {your input}
★ Pada screen 1 kalian dapat menginputkan “login”, setelah menekan enter
anda diminta untuk menginputkan username dan password seperti berikut
Screen 1 :
1. Login
2. Register
Choices : login
Username : { ex : qiqi }
Password : { ex : aku nggak marah!! }
★ Jika login berhasil maka akan menampilkan pesan “login success”, jika gagal
akan menampilkan pesan “login failed” (pengecekan login hanya mengecek
username dan password, maka dapat multi autentikasi dengan username dan
password yang sama)
★ Pada screen 1 kalian juga dapat menginputkan “register”, setelah menekan
enter anda diminta untuk menginputkan username dan password sama
halnya seperti login
★ Pada register tidak ada pengecekan unique username, maka setelah register
akan langsung menampilkan pesan “register success” dan dapat terjadi
double account
★ Setelah login berhasil maka anda berpindah ke screen 2 dimana
menampilkan 2 fitur seperti berikut.

Screen 2 :
1. Find Match
2. Logout
Choices : {your input}
★ Pada screen 2 anda dapat menginputkan “logout” setelah logout anda akan
kembali ke screen 1
★ Pada screen 2 anda dapat menginputkan “find”, setelah itu akan
menampilkan pesan “Waiting for player ...” print terus sampai menemukan
lawan
★ Jika menemukan lawan maka akan menampilkan pesan “Game dimulai
silahkan tap tap secepat mungkin !!”
★ Pada saat game dimulai diberikan variable health = 100,dan anda dapat
men-tap (menekan space pada keyboard tanpa harus menekan enter)
★ Pada saat anda men-tap maka akan menampilkan pesan “hit !!”, dan pada
lawan healthnya akan berkurang sebanyak 10 kemudian pada lawan
menampilkan pesan status healthnya sekarang. (conclusion : anda tidak bisa
melihat status health lawan)
★ Jika health anda <= 0 maka akan menampilkan pesan “Game berakhir kamu
kalah”, apabila lawan anda healthnya <= 0 maka akan menampilkan pesan
”Game berakhir kamu menang”
★ Setelah menang atau kalah maka akan kembali ke screen 2

SERVER SIDE

★ Pada saat program pertama kali dijalankan maka program akan membuat file
akun.txt jika file tersebut tidak ada. File tersebut digunakan untuk menyimpan
username dan password
★ Pada saat user berhasil login maka akan menampilkan pesan “Auth success” jika
gagal “Auth Failed”
★ Pada saat user sukses meregister maka akan menampilkan List account yang
terdaftar (username dan password harus terlihat)
```

#### SOAL 3
```
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.
● Semisal program dijalankan:
# File kategori terletak di /home/izone/kategori
$ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip
#Hasilnya adalah sebagai berikut
/home/izone
|-jpg
|--file1.jpg
|-c
|--file2.c
|-zip
|--file3.zi
● Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
dikategorikan sebanyak yang user inginkan seperti contoh di atas.
● Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.
● Program kategori ini juga menerima perintah (*) seperti di bawah;
$ ./kategori \*
● Artinya mengkategori seluruh file yang ada di working directory ketika
menjalankan program C tersebut.
● Selain hal itu program C ini juga menerima opsi -d untuk melakukan kategori
pada suatu directory. Untuk opsi -d ini, user hanya bisa menginput 1 directory
saja, tidak seperti file yang bebas menginput file sebanyak mungkin.
$ ./kategori -d /path/to/directory/
● Hasilnya perintah di atas adalah mengkategorikan file di /path/to/directory dan
hasilnya akan disimpan di working directory di mana program C tersebut
berjalan (hasil kategori filenya bukan di /path/to/directory).
● Program ini tidak rekursif. Semisal di directory yang mau dikategorikan, atau
menggunakan (*) terdapat folder yang berisi file, maka file dalam folder
tersebut tidak dihiraukan, cukup file pada 1 level saja.
● Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan
secara paralel sehingga proses kategori bisa berjalan lebih cepat. Dilarang
juga menggunakan fork-exec dan system.
● Silahkan download soal3.zip sebagai percobaan. Namun silahkan
dicoba-coba sendiri untuk kemungkinan test case lainnya yang mungkin
belum ada di soal3.zip.
```

#### SOAL 4
```
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri
jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap
pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan
setiap batunya memiliki warna yang berbeda.
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat
mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di
pilar tersebut. Norland menghampiri setiap pilar secara bergantian.
- Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada
batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:
1. Buatlah program C dengan nama "4a.c", yang berisi program untuk
melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
2. Tampilkan matriks hasil perkalian tadi ke layar.

- Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya
adalah:

1. Buatlah program C kedua dengan nama "4b.c". Program ini akan
mengambil variabel hasil perkalian matriks dari program "4a.c" (program
sebelumnya), dan tampilkan hasil matriks tersebut ke layar.
(Catatan!: gunakan shared memory)
2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan
format seperti matriks.

Contoh: misal array [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...],

maka:

1 2 6 24
120 720 ... ...
...

(Catatan! : Harus menggunakan Thread dalam penghitungan
faktorial)
- Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan
teka-teki berikut!

1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak
memiliki hubungan terhadap program yang lalu.
2. Pada program ini, Norland diminta mengetahui jumlah file dan
folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
IPC, Norland mengerjakannya dengan semangat.
(Catatan! : Harus menggunakan IPC Pipes)
Begitu batu terakhir berhasil didapatkan. Gemuruh yang semakin lama semakin
besar terdengar. Seluruh tempat berguncang dahsyat, tanah mulai merekah. Sebuah
batu yang di atasnya terdapat kotak kayu muncul ke atas dengan sendirinya.

Sementara batu tadi kembali ke posisinya. Tanah kembali menutup, seolah tidak
pernah ada lubang merekah di atasnya satu detik lalu.
Norland segera memasukkan tiga buah batu mulia Emerald, Amethys, Onyx pada
Peti Kayu. Maka terbukalah Peti Kayu tersebut. Di dalamnya terdapat sebuah harta
karun rahasia. Sampai saat ini banyak orang memburu harta karun tersebut.
Sebelum menghilang, dia menyisakan semua petunjuk tentang harta karun tersebut
melalui tulisan dalam buku catatannya yang tersebar di penjuru dunia. "One Piece
does exist".
```
##### Penjelasan
##### 3
Soal ini diminta untuk mengkategorikan file-file yang terdapat di soal3.zip ke dalam folder yang sesuai dengan ekstensinya. Sebagai contoh apabila terdapat file1.jpg, file tersebut akan dikategorikan ke dalam folder yang bernama jpg. Contoh lain adalah jika terdapat file2.c, file akan dikategorikan ke dalam folder yang bernama c. Begitu seterusnya. Namun, jika terdapat file yang tidak memiliki ekstensi, file tersebut harus dikategorikan ke dalam folder yang bernama Unknown.

Pada soal ini terdapat 3 input yang harus dilakukan, yaitu -f, * , dan -d. Pada input -f, user dapat memasukkan input file sebanyak yang diinginkan yang berisi path directory file berada. Pada input * , user akan mengkategorikan seluruh file yang terdapat di soal3.zip yang sudah diekstrak ke dalam folder sesuai dengan ekstensi file masing-masing. Sedangkan pada input -d, user hanya bisa input 1 directory saja.

Program ini menggunakan library `dirent.h` yang berfungsi untuk looping pada tiap direktori dan mengecek setiap ekstensi file. Pada soal ini dibuat fungsi untuk memindahkan file ke folder cwd (current working directory) pada setiap file.

```
char cwd[1000];
//mendeteksi file atau folder
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
```
Ini adalah fungsi untuk mendeteksi apakah sebuah direktori berupa file atau folder.

```
void pindahFile(char *argv){ //memindah file ke folder berekstensi atau bukan
  
  char string[1000];
  strcpy(string, argv);
  puts(string);
  int isFile = is_regular_file(string);
  char dot = '.'; 
  char slash = '/';
  char* tipe = strrchr(string, dot); 
  char* nama = strrchr(string, slash);
  
  char tipeLow[100];
  if(tipe)
  {
    if((tipe[strlen(tipe)-1] >= 'a' && tipe[strlen(tipe)-1] <= 'z') || (tipe[strlen(tipe)-1] >= 'A' && tipe[strlen(tipe)-1] <= 'Z'))
    {
      strcpy(tipeLow, tipe);
      for(int i = 0; tipeLow[i]; i++){
        tipeLow[i] = tolower(tipeLow[i]);
      }
    }
    else {
      strcpy(tipeLow, tipe);
    }
  }
  else
  {
    if(!isFile){
      printf("ini adalah folder, salah argumen\n");
      return;
    }
    else
    {
      strcpy(tipeLow, " Unknown"); //bikin folder untuk tanpa ekstensi
    }
  }
    mkdir((tipeLow + 1), 0777); //bikin folder untuk file berekstensi

    size_t len = 0 ;
    char a[1000] ; //res
    strcpy(a, argv);
    char b[1000] ; //des
    strcpy(b, cwd);
    strcat(b, "/");
    strcat(b, tipeLow+1);
    strcat(b, nama);
    printf("a = %s\n", a);
    printf("b = %s\n", b);
    rename(a, b);
    remove(a);
}
```
Ini adalah fungsi untuk memindah file ke dalam folder yang sesuai dengan ekstensi filenya, juga terdapat permisalan jika file tidak berekstensi, file dikategorikan ke dalam folder Unknown.

```
void *pindahf(void* arg){ //sebagai jembatan untuk membuat thread
  char* asal = (char*) arg;
  printf("asal = %s\n", asal);
  pindahFile(asal);
  pthread_exit(0);
}
```
Ini adalah fungsi untuk menjembatani pembuatan thread.

```
void sortHere(char *asal){
  // strcpy(cwd, asal);
  DIR *dirp;
  char files[240][240];
    struct dirent *entry;
    dirp = opendir(asal);
    int index = 0;
 
      while ((entry = readdir(dirp)) != NULL)
      {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
          continue;
          
        if(entry->d_type == DT_REG)
        {
          char namafile[105];
          strcpy(namafile, entry->d_name);
          
          sprintf(files[index], "%s/%s", asal, entry->d_name);
          index++;
        }
        else
        {
          printf("%s is a directory\n", entry->d_name);
        }
      }
      closedir(dirp);
  

    
    pthread_t threads[index]; 
    for (int i = 0; i < index; i++)
      pthread_create(&threads[i], NULL, pindahf, files[i]);

    for (int i = 0; i < index; i++)
      pthread_join(threads[i], NULL);
}
```
Ini adalah fungsi untuk menjalankan perintah -f dan *

```
int main(int argc, char* argv[]) 
{ 
  getcwd(cwd, sizeof(cwd));
  char asal[120];
  strcpy(asal, cwd); 

  if(strcmp(argv[1],"-f")==0)
  {
    pthread_t tid[1000]; //1000 thread
    int index = 0;
    for (int i = 2; i < argc; i++)
    {
 
      pthread_create(&tid[index], NULL, pindahf, argv[i]);
      sleep(2);
      index++;
    }
    for (int i = 0; i < index; i++) {
        pthread_join(tid[i], NULL);
    }
  }
  else if(strcmp(argv[1],"*")==0)
  {
  //  char asal[1000];
  //  strcpy(asal, cwd);
    sortHere(asal);
  }
  else if(strcmp(argv[1],"-d")==0){
      char asal[1000];
      strcpy(asal, argv[2]);
  //    printf ("%s", asal);
      sortHere(asal);

  }
  else
  {
      printf("Argumen yang dimasukkan salah\n");
      return 0;
  }
  
	return 0; 
}
```
Pada fungsi `main`, dijalankan fungsi-fungsi yang telah dibuat sebelumnya untuk melakukan input -d, * , dan -f.

##### 4a
Pada soal ini diminta untuk menampilkan hasil dari perkalian matriks, dengan ukuran matriks pertama 4x2 dan matriks kedua 2x5. Untuk hasil perkalian matriksnya akan berupa matriks berukuran 4x5. 

Fungsi `runner` berfungsi untuk melakukan perkalian kedua matriks, serta menghitung jumlah thread yang digunakan.
```
void *runner(void *ptr) //threads
{
    // casting parameter to struct yay pointer
    struct yay *data=ptr;
    int i, sum=0;

    for (i=0; i<2; i++)
    {
        sum += A[data->i][i] * B[i][data->j];
    }
    C[data->i][data->j] = sum;
    pthread_exit(0);
}
```
Menyimpan size matriks ke dalam struct untuk memudahkan proses perkalian. 
```
struct yay *data = (struct yay*) malloc(sizeof(struct yay));
            data->i = i;
            data->j = j;
```
Membuat thread.
```
pthread_create(&nay[counter],NULL,runner,data); //create thread passing it data as a parameter
counter++;
```
`pthread_join` ini berfungsi untuk menunggu proses semua thread dilakukan. Setelah selesai, maka `pthread_join` ini akan mengembalikan hasil dari proses thread untuk ditampilkan.
```
pthread_join(nay[i], NULL);
```

`sleep` ini digunakan agar proses soal 4a tidak langsung berhenti, sehingga program pada soal 4b dapat dijalankan dan ditampilkan outputnya sebelum proses soal 4a berhenti.
```
sleep(20);
```

##### 4b
Pada soal 4b ini diminta untuk menampilkan hasil penjumlahan setiap elemen matriks yang berasal dari hasil matriks di soal 4a, dengan menggunakan Shared Memory. Contoh :
Salah satu elemen hasil matriks 4a : 24 . Maka, diminta di soal 4b hasil penjumlahannya yaitu 24+23+..+1 . 
Penjumlahan tersebut dilakukan pada setiap elemen matriks 4a tersebut. 

Fungsi ini untuk menghasilkan penjumlahan setiap elemen matriks 4a.
```
void *runner (void *ptr) {

    struct yay* data;
    data = (struct yay*) ptr;

    int n = data->n;
    
    n = ((n * (n + 1)) / 2);
    printf("%d\t", n);

}
```
Program dibawah ini merupakan bagian dari shared memory. 
```
int *value;
key_t key = 1234;
int shmid = shmget(key, sizeof(int)*4*5, IPC_CREAT | 0666);
value = (int *)shmat(shmid, NULL, 0);
```
```
shmdt(value);
shmctl(shmid, IPC_RMID, NULL);
```
##### 4c
Soal bagian ini diminta untuk menampilkan jumlah file dan folder di direktori yang sedang dibuka. Perintah pada linux untuk menampilkan jumlah tersebut yaitu `ls | wc -l` . Perintah tersebut dibuat program pada soal ini menggunakan IPC Pipes.

Bagian ini merupakan parent proses dimana menunggu inputan dari proses child. Pada dup2 pertama, bagian tersebut `store1[0]` yang artinya membaca data pada store1 untuk dieksekusi. Kemudian, baru ditulis pada dup2 kedua dan ditampilkan outputnya pada `store2`.
```
 close(store1[1]);
 close(store2[0]);
 close(store2[1]);

dup2(store1[0],0); //read
dup2(store2[1],1); 

close(store1[0]);

char *argv[] = {"wc","-l",NULL};
execv("/usr/bin/wc", argv);
```
Bagian ini merupakan child proses. Disini menggunakan dup2 dengan membuka bagian `store1[1]` yang artinya `write`, menulis informasi / data pada `ls` . Dan, `1` berfunsgi seperti `stdout` dimana untuk menampilkan output.
```
close(store1[0]); //close 
dup2(store1[1],1); //write

close(store1[1]);

char *argv[] = {"ls",NULL};
execv("/bin/ls", argv);
```


