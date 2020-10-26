#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string lgg = "en-adult";
string Impossible2ReadFile = "Error: impossible to read the file: ";
string Impossible2WriteFile = "Error: impossible to write in the file: ";
string fr_FR_is_true = ""; // " " for French of France only, "" for other languages, like "fr_BE", or "en" for example. If you do not know why, it's ""!
string interface = "interface";
string symboles = "symbols";
string synonymes = "synonyms";
string fileIn = "file.txt";
string resultFile = "result.txt";

// Erreur des symboles en multimots : "animal amical devenant agressif.txt" et "animal amical.txt" ?

string removeSpaces(string line = ""){
  string lineNoSpace = "";
    for (int i=0; i<line.size()+1; i++)  // ints all incuded, imax+1 turns.
    {
       if (line[i]!=' '){
       lineNoSpace = lineNoSpace + line[i];
       }
    }
return lineNoSpace;
}

void config_lgg(string config = "config.cfg")
{
     ifstream fileLgg(config.c_str(), ios::in);  // What language?
    if(!fileLgg) // No file.
    {
cerr << "Impossible to read the configuration file: " << config << endl;

    lgg = "en-adult";
    string Impossible2ReadFile = "Error: impossible to read the file: ";
    string Impossible2WriteFile = "Error: impossible to write in the file: ";
    interface = "interface";
    synonymes = "synonyms";
    symboles = "symbols";
    fr_FR_is_true = ""; // " " for French of France, "" for other languages, like "fr_BE", or "en" for example. If you do not know why, it's ""!
    fileIn = "file.txt";
    resultFile = "result.txt";
    }
    else
    {
         while (lgg == "")
        {
            getline(fileLgg, lgg);
        }
        fileLgg.close();
        if (lgg == "") // Empty file...
        {
            lgg = "EN.lgg";

        }
    }
};

void config(string lgg = "en-adult"){
}

void coutFile(string fileToread = "", bool alert = true)
{
    ifstream file2Display(fileToread.c_str(), ios::in);
    if((!file2Display) && (alert))
    {
        cerr << Impossible2ReadFile << fileToread << fr_FR_is_true << "!" << endl;
    }
    else
    {
        string ligne;
        while(getline(file2Display, ligne))
        {
            cout << ligne << endl;
        }
        cout << "" << endl;
        file2Display.close();
    }
}

void readFile(string fileToread = "")
{
    ifstream file2Display(fileToread.c_str(), ios::in);
    if(!file2Display)
    {
        cerr << Impossible2ReadFile << fileToread << fr_FR_is_true << "!" << endl;
    }
    else
    {
        string ligne;
        while(getline(file2Display, ligne))
        {
            string wordToTest = "";
            for (int i=0; i<ligne.size()+1; i++)
            {
                if ((ligne[i]!=' ') && (ligne[i]!='.') && (ligne[i]!=',') && (ligne[i]!='?') && (ligne[i]!='!') && (ligne[i]!=';')) // For each line: find word.

                {
                    wordToTest=wordToTest+ligne[i];
                }
                else
                {
                    coutFile(lgg + "/" + symboles + "/" + wordToTest + ".txt", false); // For each word, try to read this file.
                    wordToTest = "";
                }
            }
        }
        file2Display.close();
    }
}

int appendFunctionFileString(string file, string data = "", bool display = true)  // And create new file if does not exist.
{
    ofstream outfile(file.c_str(), ios_base::app);
    if (!outfile)
    {
        cerr << Impossible2WriteFile << file << fr_FR_is_true << "!" << endl;
        return -1;
    }
    else
    {
        outfile << data;
        if (display)
        {
            cout << data;
        }
        outfile.close();
    }
    return 0; // Ok.
}

void intro(string lgg = "en-adult")
{
    coutFile(lgg + "/" + interface + "/intro.txt", true);
    cout << "M. Tristan Moir, HYM MEDIA." << endl;
    cout << "(https://www.youtube.com/channel/UCfxAKP2hCl9_WaQsYR2OjRg)" << endl;
}

void outtro(string lgg = "en-adult")
{
    coutFile(lgg + "/" + interface + "/outtro.txt", true);
}
copyright(){
cout << "https://github.com/RedGuff" << endl;
cout << "AnalyseOnirique 0.2" << endl;
cout << "2020/10/27" << endl;
}
int main()
{
    config_lgg();
    config(lgg);
    intro(lgg);
// Enregistrement de la personne, si seule, si avec enfant, en retraite... ?
// synonymes ?
// BdD ASCII !
// PHP et MySQL ?
// Selon ce qui est lu, on donne des points aux conseils ?
// Les conseils aux maximums de points seront inscrits (en premier) ? Au moins pour supprimer les redites.
    cout << "" << endl;
    readFile(fileIn);
    cout << "" << endl;
    outtro(lgg);
    copyright();
    return 0;
}
