/***********************************************
**		      SAKARYA UNIVERSITESI
**	BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**	BILGISAYAR MUHENDISLIGI BOLUMU
**	PROGRAMLAMAYA GIRISI DERSI
**	
**	ODEV NUMARASI.: 1.Odev
**	OGRENCI ADI.: Mahmud Ch
***********************************************/


#include <iostream> // cin ve cout icin
#include <ctime> // time(NULL) icin
#include <cmath> // standart sapma icin (sqrt() ve pow())
#include <sstream> // basNot desimal sayilari duzgun gostermek icin (str() ve stringstream)
#include <iomanip> // setw() ve istedigim desimal kadar almasi icin (fixed ve setprecision)
#include <clocale> // visual studioda turkce dil icin (setlocale())
#include <cstdlib> // ne olur ne olmaz (srand ve rand icin)
using namespace std;


// int main() temiz gozuksun diye bu kadar fonksiyon kullandim

// sıfıları gösteriyor
void siniflar();
//istediğinizin oğrenciyi, öğrenci numarası girip bulup yazdıriyor 
void ogrenciArama(int sinif);
// öğrenci bilgileri yazıyor
void ogrenciBilYaz(int sinif, int ogrSay);
// oğrenci bilgileri hazırlıyor
void ogrenciBilgi(struct ogrenci sinif[], int ders);
// sınıfın standart sapmayı hesaplıyor
void standartSap(struct ogrenci sinif[], int ders);
// Sınıfın ortalama notları yazdıriyor
void sinifNotCout(int sinif);
// string int'e çeviriyor
int stringToInt(string stringOgr);
// öğrencinin yil içi notu hesapliyor
double yilIciHesap(int odev1, int odev2, int proje, int vize);
// öğrencinin genel notunu hesapliyor
double genelNotHesaplama(int final, double yilIci);
// öğrenci telefon numarası hazırliyor
string ogrenciTel(string ogrenci);
// öğrenci basarı notu sözel ve sayısalı 
// birlestirip tek string halinde dönustiriyor
string basariNotu(double basNotSayi);
// öğrencinin isim, soyasim ve sehirini rastagle veriyor
string isimSoySeh(int sira, int randNum);

// ogrenci bilgileri
struct ogrenci
{
  string ad = "";
  string soyad = "";
  string telNum = "";
  string sehir = "";
  string dersAd = "";
  string odev1 = "";
  string odev2 = "";
  string proje = "";
  string vize = "";
  string final = "";
  string yilIci ="";
  string basNot = "";
  double genelNot = 0;
};

// sınıf bilgileri
struct sinifNot
{
  double ortalama;
  string stanSap;
  string aa = "";
  string ba = "";
  string bb = "";
  string cb = "";
  string cc = "";
  string dc = "";
  string dd = "";
  string ff = "";
};


// 5 tane yüz ogrencilik sinifları
// güzel gözüksün diye bes tane yaptım
ogrenci programlamayaGiris[100];
ogrenci matematic[100];
ogrenci fizik[100];
ogrenci bilgisayarGiris[100];
ogrenci ingilizce[100];

// siniflarin standart sapma, ortalamalari ve basari notları
sinifNot progNotlar;
sinifNot matNotlar;
sinifNot fizNotlar;
sinifNot bilgNotlar;
sinifNot ingNotlar;

int main()
{
  // olmadı "ı" ları çalısmiyordu
  setlocale(LC_ALL, "Turkish");

  // ogrenciBilgi()'nin içindeki rastagle notlar olusturmak için
  srand(time(NULL));

  // her sinif için oğrenci Bilgileri olusturiyor
  ogrenciBilgi(programlamayaGiris, 1);
  ogrenciBilgi(matematic, 2);
  ogrenciBilgi(fizik, 3);
  ogrenciBilgi(bilgisayarGiris, 4);
  ogrenciBilgi(ingilizce, 5);

  siniflar();
  
  return 0;
}


void siniflar()
{
  int sinif = 1;

  while (sinif != 0)
  {
    string stringSinif = "";
    cout << "\n----------------------------------------------------------------------\n";

    cout << "Aradiginiz Sinifi Seciniz.\n" << endl;
    cout << "1) Programlamaya Giris Icin Bir (1) Giriniz" << endl;
    cout << "2) Matematik Icin iki (2) Giriniz" << endl;
    cout << "3) Fizik Icin Uc (3) Giriniz" << endl;
    cout << "4) Bilgisayar Muhendislige Giris Icin Dort (4) Giriniz" << endl;
    cout << "5) Ingilizce Icin Bes (5) Giriniz" << "  |  Cikmak Icin Sifir (0) Giriniz." << endl;

    cin >> stringSinif;

    sinif = stringToInt(stringSinif);

    if(sinif < 0 || sinif > 5)
    {
      cout << "\nListede Olan Bir Sinifi Giriniz." << endl;
      continue;
    } else if (sinif == 0) 
    {
      break;
    }

    ogrenciArama(sinif);
  }

  return;
}

void ogrenciArama(int sinif)
{
  int ogr = 0;

  while (ogr != -1)
  {
    string stringOgr = "";
    cout << "\n----------------------------------------------------------------------\n";
    
    sinifNotCout(sinif);

    cout << "\nBakmak Istediginiz Orencinin Numarasini Giriniz (1-100)" << endl;
    cout << "          Geri Gitmek Icin Sifir (0) Giriniz" << endl;
    cin >> stringOgr;

    ogr = stringToInt(stringOgr) - 1; // dizi icin bir azaltiyor

    // ogrenci numarasi yanlis girilidigise
    if(ogr < -1 || ogr > 99) 
    {
      cout << endl << "Olmayan Ogrenci Numarasi Girdiniz." <<endl;
      cout << "Bir Daha Girin." << endl;
      continue;
    } else if (ogr == -1) 
    {
      break;
    }

    ogrenciBilYaz(sinif, ogr);
  }

  return;
}

void ogrenciBilYaz(int sinif, int ogrSay)
{
  ogrenci *ogr;
  string bos;

  switch(sinif)
  {
    case 1:
      ogr = &programlamayaGiris[ogrSay];
      break;
    case 2:
      ogr = &matematic[ogrSay];
      break;
    case 3:
      ogr = &fizik[ogrSay];
      break;
    case 4:
      ogr = &bilgisayarGiris[ogrSay];
      break;
    case 5:
      ogr = &ingilizce[ogrSay];
      break;
  }

  // arada esit mesafeli bosluk için 
  int maxWidth = 0;
  // (signed, unsigned)'dan dolayı bana error veriyor ondan diye (int)'e chevirdim
  maxWidth = max(maxWidth, (int)ogr->odev1.size());
  maxWidth = max(maxWidth, (int)ogr->odev2.size());
  maxWidth = max(maxWidth, (int)ogr->proje.size());
  maxWidth = max(maxWidth, (int)ogr->vize.size());
  maxWidth = max(maxWidth, (int)ogr->final.size());
  maxWidth = max(maxWidth, (int)ogr->yilIci.size());


  cout << "\n----------------------------------------------------------------------\n";

  cout << "Isim: " << ogr->ad << ", " << "Soyisim: " << ogr->soyad << endl;
  cout << "Sehir: " << ogr->sehir << endl;
  cout << "Telefon: " << ogr->telNum << endl;
  cout << "Sinif: " << ogr->dersAd << endl;


  cout << '\n' << left << setw(maxWidth + 2) << ogr->odev1;
  cout << left << setw(maxWidth + 2) << ogr->odev2 << endl;

  cout << left << setw(maxWidth + 2) << ogr->proje;
  cout << left << setw(maxWidth + 2) << ogr->vize << endl;

  cout << left << setw(maxWidth + 2) << ogr->final;
  cout << left << setw(maxWidth + 2) << ogr->yilIci << endl;

  cout << "\nGenel Not Ortalama: %" << ogr->genelNot << endl;
  cout << "Basari Notu: " << ogr->basNot << endl;

  // burda hep sayi girdiğimiz için sayı dedım ama herhangi bir sey girebiliriz
  cout << "\nGeri Gitmek Icin Herhangi Bir Sayi Giriniz" << endl;
  cin >> bos;

  return;
}

void standartSap(struct ogrenci sinif[], int ders)
{
  double ortalama = 0;
  double toplamGenel = 0;
  double doubleStanSap = 0; // ciktisi 3 decimal gosteriyor; 
  stringstream stanSap;

  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    ortalama += (ogr.genelNot); 
  }
  ortalama = ortalama / 100;


  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    toplamGenel += pow(ogr.genelNot - ortalama, 2);
  }
  doubleStanSap = sqrt(toplamGenel / 100);
  stanSap << fixed << setprecision(2) << doubleStanSap;


  switch(ders)
  {
    case 1:
      progNotlar.ortalama = ortalama;
      progNotlar.stanSap = stanSap.str();
      break;
    case 2:
      matNotlar.ortalama = ortalama;
      matNotlar.stanSap = stanSap.str();
      break;
    case 3:
      fizNotlar.ortalama = ortalama;
      fizNotlar.stanSap = stanSap.str();
      break;
    case 4:
      bilgNotlar.ortalama = ortalama;
      bilgNotlar.stanSap = stanSap.str();
      break;
    case 5:
      ingNotlar.ortalama = ortalama;
      ingNotlar.stanSap = stanSap.str();
      break;
  }
  return;
}

void sinifNotCout(int sinif)
{
  
  sinifNot *sinifNotlar;

  switch(sinif)
  {
    case 1:
      sinifNotlar = &progNotlar;
      break;

    case 2:
      sinifNotlar = &matNotlar;
      break;

    case 3:
      sinifNotlar = &fizNotlar;
      break;

    case 4:
      sinifNotlar = &bilgNotlar;
      break;

    case 5:
      sinifNotlar = &ingNotlar;
      break;
  }

  
  int maxWidth = 0;

  maxWidth = max(maxWidth, (int)sinifNotlar->aa.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->ba.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->bb.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->cb.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->cc.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->dc.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->dd.size());
  maxWidth = max(maxWidth, (int)sinifNotlar->ff.size());


  cout << "Sinif Ortalamasi: %"<<  sinifNotlar->ortalama << ", Sinifin Standart Sapmasi: %" << sinifNotlar->stanSap << '\n';

  cout << '\n' << left << setw(maxWidth + 4) << sinifNotlar->aa;
  cout << left << setw(maxWidth + 4) << sinifNotlar->cc << endl;

  cout << left << setw(maxWidth + 4) << sinifNotlar->ba;
  cout << left << setw(maxWidth + 4) << sinifNotlar->dc << endl;
  
  cout << left << setw(maxWidth + 4) << sinifNotlar->bb;
  cout << left << setw(maxWidth + 4) << sinifNotlar->dd << endl;
  
  cout << left << setw(maxWidth + 4) << sinifNotlar->cb;
  cout << left << setw(maxWidth + 4) << sinifNotlar->ff << endl;

  return;
}

void ogrenciBilgi(struct ogrenci sinif[], int ders)
{
  //  ad, soyad, telefon numarasi, sehir, ders adi ve 
  //  odev1, odev2, proje, vize, final notlari belirliyor
  for(int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    //telefon numaralari belirliyor
    ogr.telNum = ogrenciTel(ogr.telNum);


    int randNum = rand() % 50;
    ogr.ad = isimSoySeh(1, randNum);
    ogr.soyad = isimSoySeh(2, randNum);
    ogr.sehir = isimSoySeh(3, randNum);

    switch(ders)
    {
      case 1:
        ogr.dersAd = "Programlamaya giris";
        break;    
      case 2:
        ogr.dersAd = "Matematik";
        break;
      case 3:
        ogr.dersAd = "Fizik";
        break;
      case 4:
        ogr.dersAd = "Bilgisayar Muhendisligine giris";
        break;
      case 5:
        ogr.dersAd = "Ingilizce";
        break;
    }

    // Ortalama cok kotu cikiyordu
    // bundan diye + 20 ekledim
    // sinav kagidinda adini soyadini yazan +20
    int randOdev1 = rand() % 100 + 20;
      if(randOdev1 >= 100)
      {
        randOdev1 = 100;
      }
    int randOdev2 = rand() % 100 + 20;
      if(randOdev2 >= 100) 
      {
        randOdev2 = 100;
      }
    int randProje = rand() % 100 + 20;
      if(randProje >= 100) 
      {
        randProje = 100;
      }
    int randVize = rand() %  100 + 20;
      if(randVize >= 100) 
      {
        randVize = 100;
      }
    int randFinal = rand() % 100 + 20;
      if(randFinal >= 100)
      {
        randFinal = 100;
      }

    
    int yilIci = yilIciHesap(randOdev1, randOdev2, randProje, randVize);
    ogr.genelNot = genelNotHesaplama(randFinal, yilIci);
    ogr.basNot = basariNotu(ogr.genelNot);

    
    ogr.odev1 = "1.Odev: %" + to_string(randOdev1);
    ogr.odev2 = "2.Odev: %" + to_string(randOdev2);
    ogr.proje = "Proje: %" + to_string(randProje);
    ogr.vize = "Vize: %" + to_string(randVize);
    ogr.final = "Final: %" + to_string(randFinal);
    ogr.yilIci = "Yil Ici: %" + to_string(yilIci);
  }
  

  // farkli sekilde yapamadim
  int aa = 0;
  int ba = 0;
  int bb = 0;
  int cb = 0;
  int cc = 0;
  int dc = 0;
  int dd = 0;
  int ff = 0;

  // sinifin bas not harflerin ortalaması buliyor
  for (int i = 0; i < 100; i++)
  {
    ogrenci &ogr = sinif[i];

    double basNotSayi = (ogr.genelNot * 4)  / 100;


    if(basNotSayi == 4)
    {
      aa++;

    }else if(basNotSayi < 4 && basNotSayi >= 3.5)
    {
      ba++;

    }else if(basNotSayi < 3.5 && basNotSayi >= 3)
    {
      bb++;

    }else if(basNotSayi < 3 && basNotSayi >= 2.5)
    {
      cb++;

    }else if(basNotSayi < 2.5 && basNotSayi >= 2)
    {
      cc++;

    }else if(basNotSayi < 2 && basNotSayi >= 1.5)
    {
      dc++;

    }else if(basNotSayi < 1.5 && basNotSayi >= 1)
    {
      dd++;

    }else
    {
      ff++;
    }
  }

  // sinifNotCout() gibi yapmaya denedim olmadı
  switch(ders)
  {
    case 1:
      progNotlar.aa = "AA alan: %" + to_string(aa);
      progNotlar.ba = "BA alan: %" + to_string(ba);
      progNotlar.bb = "BB alan: %" + to_string(bb);
      progNotlar.cb = "CB alan: %" + to_string(cb);
      progNotlar.cc = "CC alan: %" + to_string(cc);
      progNotlar.dc = "DC alan: %" + to_string(dc);
      progNotlar.dd = "DD alan: %" + to_string(dd);
      progNotlar.ff = "FF alan: %" + to_string(ff);
      break;
    case 2:
      matNotlar.aa = "AA alan: %" + to_string(aa);
      matNotlar.ba = "BA alan: %" + to_string(ba);
      matNotlar.bb = "BB alan: %" + to_string(bb);
      matNotlar.cb = "CB alan: %" + to_string(cb);
      matNotlar.cc = "CC alan: %" + to_string(cc);
      matNotlar.dc = "DC alan: %" + to_string(dc);
      matNotlar.dd = "DD alan: %" + to_string(dd);
      matNotlar.ff = "FF alan: %" + to_string(ff);
      break;
    case 3:
      fizNotlar.aa = "AA alan: %" + to_string(aa);
      fizNotlar.ba = "BA alan: %" + to_string(ba);
      fizNotlar.bb = "BB alan: %" + to_string(bb);
      fizNotlar.cb = "CB alan: %" + to_string(cb);
      fizNotlar.cc = "CC alan: %" + to_string(cc);
      fizNotlar.dc = "DC alan: %" + to_string(dc);
      fizNotlar.dd = "DD alan: %" + to_string(dd);
      fizNotlar.ff = "FF alan: %" + to_string(ff);
      break;
    case 4:
      bilgNotlar.aa = "AA alan: %" + to_string(aa);
      bilgNotlar.ba = "BA alan: %" + to_string(ba);
      bilgNotlar.bb = "BB alan: %" + to_string(bb);
      bilgNotlar.cb = "CB alan: %" + to_string(cb);
      bilgNotlar.cc = "CC alan: %" + to_string(cc);
      bilgNotlar.dc = "DC alan: %" + to_string(dc);
      bilgNotlar.dd = "DD alan: %" + to_string(dd);
      bilgNotlar.ff = "FF alan: %" + to_string(ff);
      break;
    case 5:
      ingNotlar.aa = "AA alan: %" + to_string(aa);
      ingNotlar.ba = "BA alan: %" + to_string(ba);
      ingNotlar.bb = "BB alan: %" + to_string(bb);
      ingNotlar.cb = "CB alan: %" + to_string(cb);
      ingNotlar.cc = "CC alan: %" + to_string(cc);
      ingNotlar.dc = "DC alan: %" + to_string(dc);
      ingNotlar.dd = "DD alan: %" + to_string(dd);
      ingNotlar.ff = "FF alan: %" + to_string(ff);
      break;
  }

  //standart sapmayi buliyor
  standartSap(sinif, ders);

  return;
}


string basariNotu(double genelNot)
{
  string basNot = "";

  double basNotSayi = (genelNot * 4)  / 100;

  // bellekte yer veriyoruz 32 ile 48 byte arasi
  stringstream basNotStream;

  // format oldu ilk desemale kadar gosetrir
  basNotStream << fixed << setprecision(2) << basNotSayi; 


  if(basNotSayi == 4)
  {

    basNot += basNotStream.str() + " AA";

    // diger else if leri bakmasin diye return basNot koydum
    return basNot;

  }else if(basNotSayi < 4 && basNotSayi >= 3.5)
  {
    basNot += basNotStream.str() + " BA";
    return basNot;

  }else if(basNotSayi < 3.5 && basNotSayi >= 3)
  {
    basNot += basNotStream.str() + " BB";
    return basNot;

  }else if(basNotSayi < 3 && basNotSayi >= 2.5)
  {
    basNot += basNotStream.str()  + " CB";
    return basNot;

  }else if(basNotSayi < 2.5 && basNotSayi >= 2)
  {
    basNot += basNotStream.str() + " CC";
    return basNot;

  }else if(basNotSayi < 2 && basNotSayi >= 1.5)
  {
    basNot += basNotStream.str() + " DC";
    return basNot;

  }else if(basNotSayi < 1.5 && basNotSayi >= 1)
  {
    basNot += basNotStream.str() + " DD";
    return basNot;

  }else
  {
    basNot += basNotStream.str() + " FF";
  }
  return basNot;
}

string isimSoySeh(int sira, int randNum)
{
  // isimler, soyadlar ve sehirler birer dizi 
  // her dizinin icinde 50 kelime vardir
  string isim[50] = {
    "Ahmet", "Mehmet", "Ayse", "Fatma", "Emre", "Elif", "Ali", "Zeynep", "Can", "Merve",
    "Huseyin", "Cem", "Ebru", "Selim", "Deniz", "Derya", "Baris", "Busra", "Okan", "Seda",
    "Tolga", "Irem", "Burak", "Yasemin", "Murat", "Gizem", "Onur", "Furkan", "Aylin", "Serkan",
    "Kerem", "Ozge", "Eren", "Sule", "Kaan", "Melis", "Ilker", "Ece", "Umut", "Ceren",
    "Engin", "Hande", "Suat", "Bora", "Zehra", "Oguz", "Selin", "Caglar", "Nilay", "Tuncay"
  };
  string soyad[50] = {
    "Yilmaz", "Kaya", "Demir", "Sahin", "Celik", "Koc", "Aydin", "Ozturk", "Arslan", "Polat",
    "Aksoy", "Yildiz", "Gunes", "Ozkan", "Cetin", "Erdogan", "Bulut", "Kurt", "Tas", "Gur",
    "Kilic", "Kaplan", "Ozdemir", "Bayrak", "Aslan", "Erdem", "Tekin", "Yalcin", "Karaca", "Tuna",
    "Dogan", "Demirtas", "Kara", "Cakir", "Karagoz", "Kocak", "Sonmez", "Ozer", "Mutlu", "Cakmak",
    "Acar", "Ari", "Basar", "Eren", "Gurkan", "Karaoglu", "Topal", "Altin", "Onal", "Erkut"
  };
  string sehir[50] = {
    "Istanbul", "Ankara", "Izmir", "Bursa", "Adana", "Gaziantep", "Konya", "Antalya", "Mersin", "Kayseri",
    "Samsun", "Eskisehir", "Diyarbakir", "Sakarya", "Trabzon", "Malatya", "Erzurum", "Aydin", "Balikesir", "Mugla",
    "Manisa", "Denizli", "Ordu", "Hatay", "Kocaeli", "Mardin", "Sanliurfa", "Batman", "Bolu", "Kutahya",
    "Tekirdag", "Canakkale", "Elazig", "Rize", "Sivas", "Usak", "Zonguldak", "Amasya", "Bingol", "Kirklareli",
    "Yozgat", "Nigde", "Kahramanmaras", "Isparta", "Afyonkarahisar", "Osmaniye", "Kirikkale", "Siirt", "Bartin", "Ardahan"
  };

  switch (sira)
  {
    case 1:
      return isim[randNum];
      // diger case leri okumasin diye break koydum
      break;

    case 2:
      return soyad[randNum];
      break;

    case 3:
      return sehir[randNum];
      break;
  }

  return "";
}

string ogrenciTel(string ogr)
{
  ogr += "+90 5";

  for(int j = 1; j < 3; j++) 
  {
    int telNum = rand() % 10;
    ogr +=  to_string(telNum);
  }
  ogr += " ";
  for(int j = 1; j < 4; j++) 
  {
    int telNum = rand() % 10;
    ogr +=  to_string(telNum);
  }
  ogr += " ";
  for (int j = 1; j < 3; j++) 
  {
    for (int k = 1; k < 3; k++) 
    {
      int telNum = rand() % 10;
      ogr +=  to_string(telNum);
    }
    ogr += " ";
  }

  return ogr;
}


double yilIciHesap(int odev1, int odev2, int proje, int vize)
{
  double yilIci = (odev1 * 5 + odev2 * 5 + proje * 10 + vize * 30) / 50;

  if (yilIci > 100)
  { 
    yilIci = 100;
  }

  return yilIci;
}

double genelNotHesaplama(int final, double yilIci)
{
  int basNot = (yilIci * 0.5) +(final * 0.5); // prog giris icin boyle

  if (basNot > 100)
  {
    basNot = 100;
  }

  return basNot;
}


int stringToInt(string stringOgr)
{
  for(int i = 0; i < stringOgr.size(); i++)
  {
    if(isalpha(stringOgr[i]))
    {
      return -2; // do while tekrar etmesi için
    }
  }
  
  return stoi(stringOgr);
};