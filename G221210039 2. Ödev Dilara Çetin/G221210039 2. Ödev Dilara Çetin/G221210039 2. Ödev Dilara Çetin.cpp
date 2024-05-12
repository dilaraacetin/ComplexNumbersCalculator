/*************************************************************************************************************************************
**					                              SAKARYA ÜNİVERSİTESİ
**			                            BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				                             BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				                               PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				                                     ÖDEV NUMARASI:2
**				                                ÖĞRENCİ ADI: Dilara Çetin
**				                               ÖĞRENCİ NUMARASI: G221210039
**			                                DERS GRUBU: İkinci Öğretim B Grubu
**************************************************************************************************************************************/

#include <iostream>


using namespace std;

const double PI = 3.14159265; //Pi sabitini tanımladım

class KarmasikSayi { // Karmaşık sayı sınıfını oluşturdum.
private:
    double gercel;// Private içerisinde sayının gerçel ve sanal kısmını tanımladım.
    double sanal;
    float radyandanDereceye(float a) //Radyandan dereceye çeviren fonksiyonu oluşturdum.
    {
        return a * 180 / PI;
    }

public:
    double getGercel() const //Gerçel için get fonksiyonu oluşturdum.
    {
        return gercel;
    }
    void setGercel(double _gercel) // Gerçel için set fonksiyonu oluşturdum.
    {
        gercel = _gercel;
    }
    double getSanal() const //Sanal için get fonksiyonu oluşturdum.
    {
        return sanal;
    }
    void setSanal(double _sanal) // Sanal için set fonksiyonu oluşturdum.
    {
        sanal = _sanal;
    }
    void sayiyiGoster() //Girilen sayıyı ekrana yazan fonksiyonu oluşturdum.
    {
        cout << "Sayinin degeri:" << gercel << "+" << sanal << "i" << endl;
    }
    void sayiGir() // Kullanıcıdan sayının değerini girmesini isteyen fonksiyonu oluşturdum.
    {
        double _gercel, _sanal;
        cout << "Lutfen sayinin gercel kismini giriniz:" << endl;
        cin >> _gercel;
        setGercel(_gercel);
        cout << "Lutfen sayinin sanal kismini giriniz:" << endl;
        cin >> _sanal;
        setSanal(_sanal);
    }
    void kutupsalaCevir() // Sayının kutupsal karşılığını yazan fonksiyonu oluşturdum.
    {
        cout << "\nSayinin Kutupsal Karsiligi : ";
        cout << sqrt(pow(getGercel(), 2) + pow(getSanal(), 2)) << "  ";
        cout << radyandanDereceye(atan(getSanal() / getGercel())) << endl;
    }
    KarmasikSayi operator+(KarmasikSayi sayi) { // + operatörünü oluşturdum.
        KarmasikSayi toplam;
        toplam.gercel = gercel + sayi.gercel;
        toplam.sanal = sanal + sayi.sanal;
        return toplam;
    }
    KarmasikSayi operator-(KarmasikSayi sayi) { // - operatörünü oluşturdum.
        KarmasikSayi cikarma;
        cikarma.gercel = gercel - sayi.gercel;
        cikarma.sanal = sanal - sayi.sanal;
        return cikarma;
    }

    KarmasikSayi operator*(const KarmasikSayi sayi) { // * operatörünü oluşturdum.
        double yeniGercel = gercel * sayi.gercel - sanal * sayi.sanal;
        double yeniSanal = gercel * sayi.sanal + sanal * sayi.gercel;
        sanal = yeniSanal;
        gercel = yeniGercel;
        return*this;

    }
    KarmasikSayi operator/(const KarmasikSayi sayi) { // / operatörünü oluşturdum.
        double bolen = sayi.gercel * sayi.gercel + sayi.sanal * sayi.sanal;
        double yeniGercel = (gercel * sayi.gercel + sanal * sayi.sanal) / bolen;
        double yeniSanal = (sanal * sayi.gercel - gercel * sayi.sanal) / bolen;
        sanal = yeniSanal;
        gercel = yeniGercel;
        return *this;
    }
    KarmasikSayi operator += (const KarmasikSayi sayi) { // += operatörünü oluşturdum.
        gercel += sayi.gercel;
        sanal += sayi.sanal;
        return *this;
    }
    KarmasikSayi operator -= (const KarmasikSayi sayi) { // -= operatörünü oluşturdum.
        gercel -= sayi.gercel;
        sanal -= sayi.sanal;
        return *this;
    }
    KarmasikSayi operator *= (const KarmasikSayi sayi) { // *= operatörünü oluşturdum.
        double yeniGercel = gercel * sayi.gercel - sanal * sayi.sanal;
        double yeniSanal = gercel * sayi.sanal + sanal * sayi.gercel;
        gercel = yeniGercel;
        sanal = yeniSanal;
        return *this;
    }
    KarmasikSayi operator /= (const KarmasikSayi sayi) { // /= operatörünü oluşturdum.
        double bolen = sayi.gercel * sayi.gercel + sayi.sanal * sayi.sanal;
        double yeniGercel = (gercel * sayi.gercel + sanal * sayi.sanal) / bolen;
        double yeniSanal = (sanal * sayi.gercel - gercel * sayi.sanal) / bolen;
        sanal = yeniSanal;
        gercel = yeniGercel;
        return *this;
    }

};

int main()
{
    KarmasikSayi sayi1;
    KarmasikSayi sayi2;

    int secim = 0; // Kullanıcını gireceği seçimi tanımladım.


    cout << "Menuye hosgeldiniz. Lutfen yapmak istediginiz islemin oldugu secenegi seciniz." << endl; //Kullanıcıya menüyü sundum.
    cout << "1-> Toplama" << endl;
    cout << "2-> Cikarma" << endl;
    cout << "3-> Carpma" << endl;
    cout << "4-> Bolme" << endl;
    cout << "5-> Kutupsal Gosterim" << endl;
    cout << "6-> +=" << endl;
    cout << "7-> -=" << endl;
    cout << "8-> *=" << endl;
    cout << "9-> /=" << endl;

    cin >> secim;// Kullanıcnın seçimini aldım.

    system("CLS");

    if (secim == 1) { // Kullanıcının seçimine göre if ve else komutlarını kullanarak istenilen işlemleri yaptım.
        cout << "Toplama islemini sectiniz" << endl;
        cout << "Ilk sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Ikinci sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        KarmasikSayi sayi3 = sayi1 + sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi3.sayiyiGoster();
    }

    else if (secim == 2) {
        cout << "Cikarma islemini sectiniz" << endl;
        cout << "Ilk sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Ikinci sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        KarmasikSayi sayi3 = sayi1 - sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi3.sayiyiGoster();

    }

    else if (secim == 3) {
        cout << "Carpma islemini sectiniz" << endl;
        cout << "Ilk sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Ikinci sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        KarmasikSayi sayi3 = sayi1 * sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi3.sayiyiGoster();

    }

    else if (secim == 4) {
        cout << "Bolme islemini sectiniz" << endl;
        cout << "Ilk sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Ikinci sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        KarmasikSayi sayi3 = sayi1 / sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi3.sayiyiGoster();

    }

    else if (secim == 5)
    {
        cout << "Kutupsal gosterimi sectiniz." << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        sayi1.kutupsalaCevir();

    }

    else if (secim == 6) {
        cout << " += islemini sectiniz" << endl;
        cout << "Sabit sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Eklemek istediginiz sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        sayi1 += sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi1.sayiyiGoster();

    }

    else if (secim == 7) {
        cout << " -= islemini sectiniz" << endl;
        cout << "Sabit sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Cikarmak istediginiz sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        sayi1 -= sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi1.sayiyiGoster();
    }

    else if (secim == 8) {
        cout << " *= islemini sectiniz" << endl;
        cout << "Sabit sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Carpmak istediginiz sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        sayi1 *= sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi1.sayiyiGoster();
    }
    else if (secim == 9) {
        cout << " /= islemini sectiniz" << endl;
        cout << "Sabit sayi icin:" << endl;
        sayi1.sayiGir();
        sayi1.sayiyiGoster();
        cout << "Bolmek istediginiz sayi icin:" << endl;
        sayi2.sayiGir();
        sayi2.sayiyiGoster();
        sayi1 /= sayi2;
        system("CLS");
        cout << "Sonuc ";
        sayi1.sayiyiGoster();
    }

}
