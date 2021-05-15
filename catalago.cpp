#include <iostream>
using namespace std;

struct serie{
    string nome;
    struct episodio * inicio;
    struct serie * prox, * ant;
};

struct episodio{
    int numero;
    string nome;
    struct episodio * prox, * ant;
};

void inicializar(serie *&s){
    s = NULL;
}

void inserirSerie(serie *& s, string nome){
    serie * novo = new serie;
    novo->nome = nome;
    novo->ant = NULL;
    novo->prox = NULL;
    novo->inicio = NULL;
    
    if (s==NULL){
        s=novo;
    }else{
        serie * perc = s;
        while(perc->prox!=NULL){
            perc = perc->prox;
        }
        perc->prox=novo;
        novo->ant = perc;
    }
}

void inserirEpisodio(episodio * &ep,int numero,string nomeEp){
    episodio * novo = new episodio;
    novo->numero = numero;
    novo->nome = nomeEp;
    novo->ant=NULL;
    novo->prox=NULL;
    
    if(ep==NULL){
        ep = novo;
    }else{
        episodio *perc = ep;
        while(perc->prox!=NULL){
            perc=perc->prox;
        }
        perc->prox=novo;
        perc->ant=perc;
    }
}

serie * buscarSerie(serie *s,string nome){
    serie * perc = s;
    
    while(perc!=NULL && perc->nome!=nome){
        perc=perc->prox;
    }
    return perc;
}

bool novoEp(serie *&s,string nome,int numero,string nomeEp){
    serie * aux = buscarSerie(s,nome);
    if (aux==NULL){
        return false;
    }else{
        inserirEpisodio(aux->inicio,numero,nomeEp);
        return true;
    }
}

void imprimir(serie *s){
        cout<<"------------------------------------"<<endl;
        cout<<"---------CATALAGO DE SERIES---------"<<endl;
        cout<<"------------------------------------"<<endl;
    while (s!=NULL){
        cout<<"Serie \""<<s->nome<<"\""<<endl;
        while (s->inicio!=NULL){
            if (s->inicio->numero<=9){
            cout<<"EP 0"<<s->inicio->numero<<": "<<s->inicio->nome<<endl;
            }else{
            cout<<"EP "<<s->inicio->numero<<": "<<s->inicio->nome<<endl;
            }
            s->inicio = s->inicio->prox;
        }
        s = s->prox;
        cout<<"------------------------------------"<<endl;
    } 
}

int main(){

    serie * catalogo;
    
    inicializar(catalogo);
    inserirSerie(catalogo,"A Vida Depois do Tombo");
    inserirSerie(catalogo,"Chernobyl");
    novoEp(catalogo,"A Vida Depois do Tombo",1,"O Cancelamento");
    novoEp(catalogo,"A Vida Depois do Tombo",2,"Realidade");
    novoEp(catalogo,"A Vida Depois do Tombo",3,"Ruptura");
    novoEp(catalogo,"A Vida Depois do Tombo",4,"O Pai");
    novoEp(catalogo,"Chernobyl",1,"1:23:45");
    novoEp(catalogo,"Chernobyl",2,"Please Remain Calm");
    novoEp(catalogo,"Chernobyl",3,"Open Wide, O Earth");
    novoEp(catalogo,"Chernobyl",4,"The Happiness of All Mankind");
    novoEp(catalogo,"Chernobyl",5,"Vichnaya Pamyat");

    imprimir(catalogo);
    
    return 0;
}