#include <bits/stdc++.h>

using namespace std;

struct stud{                //struktura studento duomenims saugoti
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
    float med;
};

int main()
{
    srand(time(0));
    vector<stud> studentas;
    studentas.push_back(stud());
    string v, p;
    int a=1;
    float pazsum=0; // pazymiu suma
    int i=0;
    int j=0;
    int u;
    while(true)
    {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> v >> p;
        studentas[i].vardas = v;
        studentas[i].pavarde = p;
        char A;
        cout << "Ar norite atsitiktinai sugeneruoti mokinio namu darbu ir egzamino pazymius? (Y/N) ";
        while(true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if(A == 'Y' || A == 'y')
        {
            cout << "Iveskite norimu sugeneruoti pazymiu skaiciu: ";
            cin >> u;
            for(int p=0; p<u; p++)
            {
                a = rand()%10+1;
                studentas[i].nd.push_back(a);
                pazsum += a;         
                j++;
            }
            j++;
            a = rand()%10+1;
            studentas[i].egz = a;
            a=1;
        }
        else
        {
            cout << "Veskite studento pazymius, baige vesti, iveskite 0: ";
            while(true)
            {

                if(a!=0)
                {
                    cin >> a;
                    while(!cin)
                    {
                        cin.clear(); // reset failbit
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziame neteisinga ivesti
                        cout << "Prasome ivesti skaiciu: ";
                        cin >> a;
                    }
                    studentas[i].nd.push_back(a);
                    pazsum += a;
                    j++;
                }
                else
                {
                    if(pazsum==0)
                    {
                        cout << "prasome ivesti bent viena pazymi: ";
                        cin >> a;
                        pazsum += a;
                    }
                    else
                        break;
                }
                    
            }
            cout << "Iveskite egzamino rezultata: ";
            cin >> a;
            studentas[i].egz = a;
            a=1;
        }

        j--;
        float mediana;
        sort(studentas[i].nd.begin(), studentas[i].nd.end());
        studentas[i].nd.erase(studentas[i].nd.begin());
        
        
        if(j==1)
        mediana=studentas[i].nd[j];
        else if(j%2==0) //medianos skaiciavimas jei nariu skaicius yra lyginis
        {
            mediana=(studentas[i].nd[j/2]+studentas[i].nd[j/2 - 1])/2.0;
        }
        else        //medianos skaiciavimas jei nariu skaicius nelyginis
            mediana=(studentas[i].nd[j/2]);

        studentas[i].med = mediana;


       
        
        studentas[i].gal = (0.4*(pazsum/(float)j)) + (0.6*studentas[i].egz);
        studentas[i].med = (0.4*(pazsum/(float)j)) + (0.6*studentas[i].med);

        cout << "Ar norite ivesti kita mokini? (Y/N) ";
        while(true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if(A == 'n' || A == 'N')
        {
            break;
        }
        j=0;
        i++;
        pazsum=0;
        studentas.push_back(stud());
    }


    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)"<< "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for(int k=0; k <= i; k++)
    {
        cout << "|"<< left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << left << setw(20) << studentas[k].med << endl;;
    }

}
