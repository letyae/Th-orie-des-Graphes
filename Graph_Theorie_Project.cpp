#include "Graph.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <fstream>
#include <cstdlib> // pour exit
#include <iomanip>
using namespace std;

Graph::Graph(string nm, vector< char > liste_S, vector < vector < int > > mat)
{
     nom=nm;
     list_sommet=liste_S;
     matrice=mat;
}

void Graph:: Add_Arc(int i,int j){
cout<<" Entrez le lien correspondant  a "<<i<<" et a "<<j;
   cin>>matrice[i][j];
cout<<" Le lien est entrer";
}

void Graph:: Pop_Arc(int i,int j){
   matrice[i][j]=0;
cout<<" Le lien est supprimer";
}

/*void Graph::Pop_Noeud(char s){ //CHERCHE A SUPPRIMER LA COLONNE
 int i=recherche(s);

 list_sommet.erase(list_sommet.begin()+i);
 for(j=0;j<nombre_noeud;j++){
  matrice[j][i]=0;
   matrice[i][j]=0;
    }
  }
 }
*/

void Graph::Add_Noeud(){
 int i;
 for(i=0;i<nombre_noeud;i++){
    matrice[i].push_back(-1);
 }
 matrice.push_back(vector<int>(nombre_noeud+1,-1));

 cout<<"Entrez les liens du nouveau sommet:"<<endl;

 for(i=0;i<nombre_noeud+1;i++){
        cout<<"Valeur d'indice"<<i<<"et "<<nombre_noeud;
   cin>> matrice[i][nombre_noeud];
 }

 for(i=0;i<nombre_noeud;i++){
        cout<<"Valeur d'indice "<<nombre_noeud<<"et "<<i;
   cin>> matrice[nombre_noeud][i];
 }

 nombre_noeud=nombre_noeud+1;
 list_sommet.push_back(65+nombre_noeud);
 }






Graph::Graph(string nm, int n,vector < vector < int > > mat){

    int i=0,j=0;
     nom=nm;
     nombre_noeud=n;
     int *d=new int [n];
          for(i=0;i<n;i++)
             d[i]=0;

     traite=d;

    vector <char> lst;
    char c=65;
    for(int i=0;i<n;i++){
         lst.push_back(c);
             c+=1;
     }

/*vector< vector<int> > mat;
       for(int i=0;i<n;i++)
          mat.push_back( vector< int >(n,0));

        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                 cout<< "Lien entre les noeuds au couple d'indice i,j(Entrer 0 pour NON et 1 pour OUI)? "<<endl;
                 cin >> mat[i][j];
                }
        }*/

        matrice=mat;
        list_sommet=lst;
        cout<<"la matrice d'adjacence du graphe est creer"<<endl;
        distmin=new int[n];
        distrouve=new bool[n];
        pred =new int[n];
}


 int Graph::get_nombre_noeud(){
    return nombre_noeud;
 }


  string Graph::get_nom(){
     return nom;
  }

 int Graph::OrdreG(){
   cout<<"L'ordre du graphe est "<< nombre_noeud<<endl;
   return nombre_noeud;
 }


 void Graph::Affiche_Graphe(){
     cout<<"La  matrice d'adjacence du graphe est: " <<endl;
       cout<<"   ";
 for(int k=0;k<nombre_noeud;k++)
     cout<<list_sommet[k]<<"  ";
         cout<<endl;

 for(int i=0;i<nombre_noeud;i++){
     cout<<list_sommet[i]<<"  ";
     for(int j=0;j<nombre_noeud;j++)
        cout<<matrice[i][j]<<"  ";
     cout<<endl;
    }
 }


int Graph::Degre(char S)
{
  int cpt=0,i;
  for(i=0;i<nombre_noeud;i++){
    if(S==list_sommet[i])
    break;
}

  for(int j=0;j<nombre_noeud;j++)
    if(matrice[i][j]!=0) cpt++;
//cout <<"Le degre de "<<S<<" est: "<<cpt<<endl;
 return cpt;
}









   /*void Graph:: Heulerien(){


   };*/


//theoreme de DIRAC
   int Graph:: Hamiltonien(){
                 int d = 1;
                 int i = 0;
                 double n=nombre_noeud;
                 while(i < nombre_noeud && d==1){
                         if(Degre(list_sommet[i]) < n/2)
                             d = 0;
                         else
                             i++;
                 }
                 if(d) cout<<"Le graph est HAMILTONIEN"<<endl;
                 else if(!d) cout<<" Le graphe n'est pas HAMILTONIEN "<<endl;
             }


   void Graph:: Semi_Hamiltonien(){
       int n=get_nombre_noeud();
                 int d = 1;
                 int j = 0;
                 while(j < n && d==1){
                         if((Degre(list_sommet[j])+1) < (n+1)/2)
                             d = 0;
                         else
                             j++;
                 }

        if(d) cout<< "Le graphe est SEMI-HAMILTONIEN"<<endl;
        else if(!d) cout<<" Le graphe n'est pas  SEMI-HAMILTONIEN "<<endl;
   }



deque<int>  Graph:: List_succ(int i){
     deque<int> q;
     int j,n=nombre_noeud;
     for(j=0;j<n;j++){
            if(matrice[i][j])
            q.push_back(j);
     }
return q;
}

int Graph::estmarque(int i){
    if(traite[i])
        return 1;
    else if(!traite[i])
        return 0;
    }

void Graph::Demarque(){
for(int j=0;j<nombre_noeud;j++)
    traite[j]=0;
}


void Graph:: parcourt_prof(int i){
 traite[i]=1;
 cout<<" "<<list_sommet[i]<<" ";
 int temp=Degre(list_sommet[i]);
 deque <int> vs=List_succ(i);

 while(temp--){
        int succ=vs[0];
        vs.pop_front();
        if(!estmarque(succ))
           parcourt_prof(succ);
 }
}


void Graph:: Connexite(){
    if(OrdreG()){
       Demarque();
        cout<<"RECHERCHE DE COMPOSANTE CONNEXE:"<<endl;
       for(int i=nombre_noeud-1;i>=0;i--){
         if(!estmarque(i)){
         cout<<"{ ";

           parcourt_prof(i);
          cout<<" }";
         }
       }
    }else cout<<"GRAPHE Vide";

}


 void Graph:: Heulerien(){
 vector<int> degre;
 int n_paire=0,n_impaire=0;
 for(int i=0;i<nombre_noeud;i++)
    degre.push_back(Degre(list_sommet[i]));

 for(int i=0;i<nombre_noeud;i++){
        if(degre[i]%2==0)
            n_paire++;
        else if(degre[i]%2!=0)
            n_impaire++;
   }

    if(n_paire==nombre_noeud)
       cout<<" Le graphe "<<get_nom()<<" est Heulerien "<<endl;
    else  if(n_impaire==2 || n_impaire==0)
       cout<<" Le graphe "<<get_nom()<<" est Semi-Heulerien "<<endl;
   else
        cout<<" Le graphe "<<get_nom()<<" n'est pas Heulerien "<<endl;

 }



 int Graph:: recherche(char s){
 int k;
  for(k=0;k<nombre_noeud;k++)
        if(list_sommet[k]==source)
            return k;
}


void Graph::initialiser(){

    int i,k,n=nombre_noeud;

   cout<<" Valeur de l'origine "<<endl;
   cin >>source;
   cout<<endl;
   k=recherche(source);
do{
    cout<<" SVP Valeur de l'origine doit bien exster "<<endl;
     cin >>source;
       k=recherche(source);
  } while(k>=nombre_noeud);

 for(i=0; i<nombre_noeud; i++)
       distmin[i]=9999;

  for(int i=0; i<nombre_noeud; i++)
    distrouve[i]=false;

     for(int i=0; i<n; i++)
        pred[i]=-1;
}

void Graph::Dijkstra(){
    int i,j,n=nombre_noeud;
    int k;
        k=recherche(source);

        for(j=0; j<n ;j++){
            distmin[j]=matrice[k][j];
            pred[j]=k;
        }
            distrouve[k]=true;
            distmin[k]=0;
            pred[k]=k;


        for(i=0; i<n-1;i++){
                int mind=9999;
                 int v=k;

          for( j=0; j<n;  j++)
                if(!distrouve[j])
                  if(distmin[j]<mind)
            {
                v=j;
                mind=distmin[v];
            }

            distrouve[v]=true;

            for(int j=0 ;j<n; j++)
                if(!distrouve[j])
                if(mind+matrice[v][j]<distmin[j])
            {
                distmin[j]=mind+matrice[v][j];
                pred[j]=v;
            }

        }
}

//***********************************
void Graph::Affiche_DJ(){
    int k;
     k=recherche(source);

    int i,n=nombre_noeud;
        for(i=0;i<n;i++){
            if(i==k)
                cout<<"Source a la source: "<<k<<"  "<<k;
            else imprime(i);

            if(distmin[i]!=9999)
                cout<<"Dist minimale: "<<distmin[i]<<endl;
            else cout<<"Pas de chemin !!!"<<endl;
       }
}



  void Graph:: imprime(int noeud){
      int k;
       k=recherche(source);

   if(noeud==k)
       cout<<list_sommet[noeud]<<"  ";
else{
     imprime(pred[noeud]);
     cout<<list_sommet[noeud]<<"  ";
    }
  }







/*
 void Graph::  Add_Noeud(){

 }

void Graph::  Pop_Noeud(){

}


/*
void Graph:: Successeur(char S)
{

};


void Graph:: Predeccesseur(char S)
{

};*/


void Graph:: Chaine_2sommet(int i,int j){
int cpt=0;
    if(i==j){
        cout<<" Il n'y pas de chaine/chemin "<<endl;
    }else if(i!=j){
          traite[i]=1;

        for(int k=0;k<nombre_noeud;k++)
            if(traite[k]==1) cpt++;
          if(cpt==nombre_noeud)
                cout<<" Il n'y pas de chaine/chemin entre ces deux sommets "<<endl;
           else{
                cout<<" "<<list_sommet[i]<<" ";
                int temp=Degre(list_sommet[i]);
                deque <int> vs=List_succ(i);

             while(temp--){
                    int succ=vs[0];
                    vs.pop_front();
                    if(!estmarque(succ))
                       if(succ==j){
                            traite[j]=1;
                         cout<<" "<<list_sommet[j]<<" ";
                         cout<<" Il y a une chaine/chemin entre ces deux sommets "<<endl;

                          break;
                       }else
                            Chaine_2sommet(succ,j);
             }
    }
    }
}


  void Graph:: Voisin(char S){
      int i,j;
      for(i=0;i<nombre_noeud;i++)
        if(list_sommet[i]==S)
            break;

    cout<<"Liste des voisins de "<<S<<":"<<endl;
    for( j=0;j<nombre_noeud;j++)
     if(matrice[i][j]!=0)
        cout << list_sommet[matrice[i][j]]<<" ";
  }



 /*void Graph::F_connexite(){
     Demarque();
     for(int i=0;i<nombre_noeud;i++){
        if(!estmarque(i)){
          cout<<"{ ";
            prof(i);
        }
     }
 }



void Graph:: prof(int a){
 deque <int> vs=List_succ(a);
 int i=0;
 if(!vs.size()){
    traite[a]=1;
    cout<<a<<"  }";
}
 else{
      while(vs[i]){
            if(!estmarque(vs[i]))
            break;
            else i++;
      }

    if(List_succ(vs[i]).size()){
        cout<<vs[i]<<"  ";
        traite[vs[i]]=1;
        prof(vs[i]);
    }else if(!List_succ(vs[i]).size()){
        cout<<vs[i]<<" }";
        traite[vs[i]]=1;

        cout<<a<<"  ";
        traite[a]=1;
        }

    }
 }

*/


vector< vector < int > > Graph:: Get_transpose(){
int n=nombre_noeud;
       vector< vector<int> > mat;
       for(int i=0;i<nombre_noeud;i++)
          mat.push_back( vector< int >(n,0));

 for(int i=0;i<nombre_noeud;i++)
    for(int j=0;j<nombre_noeud;j++)
        mat[i][j]=matrice[j][i];

return mat;

 }

void Graph:: set_matrice(vector< vector <int> > mat){
     this->matrice=mat;
}



 bool Graph::F_connexite(){

 Demarque();
 vector < vector < int > > mat=this->matrice;
 int i,v,j,k=0,t=0,verifi=0;

for(v=0;v<nombre_noeud;v++){
    if(!traite[v]){
       verifi++;
        deque < int > q=BFSuttil(v);

    vector <vector < int > > extr=extraction_graphe(q);

     this->set_matrice(extr);
        //this->Affiche_Graphe();


       while(k<q.size()){
          traite[q[k]]=0;
          //q.pop_front();
          k++;
        }
        k=0;


         deque < int > p=BFSuttil(v);

       this->set_matrice(mat);

         if(p.size()>0){
                cout <<"composante connexe: "<<endl;
            cout<<"{ ";
         for(i=0;i<p.size();i++){
                cout<<list_sommet[p[i]]<<" ";
            }
            cout<<" } "<<endl;
       }
   }

  }

  if(verifi==1) return true;
  else if(verifi>1) return false;
 }


bool Graph::chemin2Noeud_O(char a,char z){
     int v=recherche(a);
     int h=recherche(z);

       deque<int> queu;
       deque<int> trace;
        traite[v]=1;
        queu.push_back(v);
        trace.push_back(v);
        int i;
        while(queu.size())
         {

             v=queu.front();
             queu.pop_front();

             deque<int> succ=List_succ(v);

             for(i=0;i<succ.size();i++){
               if(!traite[succ[i]]){
                traite[succ[i]]=1;
                queu.push_back(succ[i]);
                trace.push_back(succ[i]);
             }

           }
        }
        i=0;
        while(i<trace.size()){
            if(h==trace[i])
               return true;
            else i++;
           }

  return false ;
}




deque<int> Graph::BFSuttil(int v){
       deque<int> queu;
       deque<int> trace;
        traite[v]=1;
        queu.push_back(v);
        trace.push_back(v);
       // deque<int>::iterator i;
        int i;
        while(queu.size())
         {

             v=queu.front();
             queu.pop_front();

             deque<int> succ=List_succ(v);

             for(i=0;i<succ.size();i++){
               if(!traite[succ[i]]){
                traite[succ[i]]=1;
                queu.push_back(succ[i]);
                trace.push_back(succ[i]);
             }

           }
        }
  return trace;
}


 void Graph::Pop_Noeud(char s){
     int i=recherche(s);
     int j=0;
 while(j<nombre_noeud){
    matrice[i][j]=0;
    matrice[j][i]=0;
    j++;
   }
 }

vector< vector < int > > Graph:: extraction_graphe(deque < int > q){
    int verifi,k=0,n=nombre_noeud;
    vector< vector < int > > mat;
       for(int i=0;i<nombre_noeud;i++)
          mat.push_back( vector< int >(n,0));
//Transposition
 for(int i=0;i<nombre_noeud;i++){
    for(int j=0;j<nombre_noeud;j++)
        mat[i][j]=matrice[j][i];
 }

    for(int i=0;i<nombre_noeud;i++){
            verifi=0;
       for(int j=0;j<q.size();j++){
          if(i==q[j]){
            verifi=1;
            break;
          }
      }
      if(!verifi){
        while(k<nombre_noeud){
        mat[i][k]=0;
        mat[k][i]=0;
        k++;
      }
      k=0;
       }
    }

return mat;
}



 void Graph :: Heulerien_O(){
    int cpt=0,k=0;
vector<int> out;
vector<int> in;
for(int i=0;i<nombre_noeud;i++){

    for(int j=0;j<nombre_noeud;j++){
        if(matrice[i][j]) cpt++;
     }
            out.push_back(cpt);
            cpt=0;
     for(int j=0;j<nombre_noeud;j++){
        if(matrice[j][i]) cpt++;
     }
        in.push_back(cpt);
            cpt=0;
    }

   while(k<nombre_noeud){
         if(in[k]==out[k]){
            cpt++;
         }else if(in[k]!=out[k]){
         cout<<"Le graphe n'est pas Eulerien"<<endl;
         break;
         }
         k++;
   }
   if(cpt==nombre_noeud)  cout<<"Le graphe est   Eulerien"<<endl;

}


int Graph::Degre_OUT(int i){
 int cpt=0;
for(int j=0;j<nombre_noeud;j++){
                  if(matrice[i][j])
                  cpt++;
                }
                return cpt;
}

int Graph::Degre_IN(int i){
 int cpt=0;

        for(int j=0;j<nombre_noeud;j++){
            if(matrice[j][i])
                  cpt++;
               }

        return cpt;
}

int Graph:: Hamiltonien_O(){
                int d=1,cpt=0,i=0;
                 while(i <nombre_noeud && d==1){
                        if((Degre_IN(i)< nombre_noeud/2) && (Degre_OUT(i)< nombre_noeud/2))
                             d=0;
                        else i++;
                       }
                 return d;
            }


int Graph::Degre_O(int k){
    int cpt=0;
    //k=recherche(s);
                for(int j=0;j<nombre_noeud;j++){
                  if(matrice[k][j])
                  cpt++;
                }

                for(int j=0;j<nombre_noeud;j++){
                  if(matrice[j][k])
                  cpt++;
        }
        return cpt;
}
