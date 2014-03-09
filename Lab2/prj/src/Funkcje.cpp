#include "Funkcje.hh"
/*!
 * \file
 * \brief Modul odpowiedzialny za operacje na kontenerach tablic.
 *
 *  Plik zawiera opisy funkcji odpowiedzialnych za wykonywanie operacji na kontenerach tablic
 *  sa to funkcje wczytaj, pomnoz, porownaj dzialajace w oparciu o biblioteke <vector>
 */

bool TablicaLiczb::wczytaj(string NazwaPliku) {
	int LiczbaElementow;	
	int x;
	ifstream StrmWe;
	StrmWe.open(NazwaPliku.c_str());
	if(!StrmWe.is_open()) {
		cerr << "!!! Plik nie zostal otwarty" << endl; 
		return 1;
	}
	StrmWe >> LiczbaElementow;
	if (StrmWe.fail()) {
	StrmWe.clear();
	StrmWe.ignore(numeric_limits<int>::max( ),'\n');
		} 
	while(!StrmWe.eof()) {
		StrmWe>>x;
		if (StrmWe.fail()) {
			StrmWe.clear();
			StrmWe.ignore(numeric_limits<int>::max( ),'\n');
		} 
		else { 
			Tab.push_back( x );
		}
	}
	StrmWe.close();
return 0; 
}
/**********************************************************/
bool TablicaLiczb::wyswietl() {
/*for(unsigned int i = 0; i < Tab.size(); i++ )
cout << Tab[i] << endl;*/
if(!Tab.size()) { cout << "Tablica jest pusta." << endl; return 1; }
     vector <int>::iterator it_tab = Tab.begin();     
     for(; it_tab != Tab.end(); it_tab++)
	cout << *it_tab << endl;
return 0;
}


bool TablicaLiczb::pomnoz() {
if(!Tab.size()) { cout << "Tablica jest pusta." << endl; return 1; }
	for(unsigned int  i = 0; i < Tab.size(); i++ ) 
		Tab[i]=Tab[i]*2;  
return 0;
}


bool porownaj(TablicaLiczb Tab1, TablicaLiczb Tab2 ) {
	return equal(Tab1.Tab.begin(), Tab1.Tab.end(), Tab2.Tab.begin());
}


bool TablicaLiczb::zamien_elementy(unsigned int i,unsigned int j) {
	int temp;
     if(Tab.size() < i)
        if(Tab.size() < j)
	  { cout<<"Wskazane pozycje nie istnieja" << endl; return 1; }
	else 
	  { cout << "Pozycja " << i << " nie istnieje." << endl; return 1; }
     else if(Tab.size() < j) 
	  { cout << "Pozycja " << j << " nie istnieje." << endl; return 1; }   

temp=Tab[i];
Tab[i]=Tab[j];
Tab[j]=temp;
return 0;
}


bool TablicaLiczb::odwroc_kolejnosc() {
     vector <int> tmp;
     vector <int>::iterator it_tab = Tab.begin();
     if(!Tab.size()) { cout << "Tablica jest pusta." << endl; return 1; }
     if(Tab.size() == 1) { cout << "Tablica zawiera jedynie jeden element. Dodaj kolejny aby moc ja obrocic." << endl; return 1; }
     for(; it_tab != Tab.end(); it_tab++)
         tmp.insert(tmp.begin(), *it_tab);
     
     Tab = tmp;
     
     return 0;

}

int TablicaLiczb::dodaj_element(int element) {
Tab.push_back(element);
return Tab.size();	
}


TablicaLiczb dodaj_elementy(TablicaLiczb Tab1, TablicaLiczb Tab2) {
	vector <int>::iterator it_tab = Tab2.Tab.begin();
     for(; it_tab != Tab2.Tab.end(); it_tab++)         
	Tab1.Tab.push_back(*it_tab);
	
return Tab1;
     }



TablicaLiczb TablicaLiczb::operator + (TablicaLiczb Tab2) {
	vector <int>::iterator it_tab = Tab2.Tab.begin();
     for(; it_tab != Tab2.Tab.end(); it_tab++)
         Tab.push_back(*it_tab);
return *this;
}

TablicaLiczb TablicaLiczb::operator = (TablicaLiczb Tab2) {
Tab = Tab2.Tab;
return *this;
}

bool operator == (TablicaLiczb Tab1, TablicaLiczb Tab2) {
return equal(Tab1.Tab.begin(), Tab1.Tab.end(), Tab2.Tab.begin());
}


/**********************************************************************/

void TablicaLiczb::wyczysc() {
Tab.clear();
}
