#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "data_structures.h"
using namespace std;



class Lista_Sequencial{

};
class Lista_Sequencial_Ordenada{

};

class Lista_Sequencial_Ord_Circular{

};

class Lista_Encadeada_Ord_Header{

};

class Lista_Encadeada_Ord{

};

class Lista_Encadeada_Ord_Header_Circular{

};

class Lista_Encadeada_Ord_Circular{

};

class Lista_Duplamente_Encadeada_Header{

};
class Lista_Duplamente_Encadeada_Circular_Header{

};

class Pilha_Sequencial{

};
class Fila_Sequencial{

};

class Elemento_Pilha{
    public:
        int chave;
        Elemento_Pilha *prox = NULL;
};

class Pilha_Encadeada{
    public:
        Elemento_Pilha *topo = NULL;
        Elemento_Pilha* empilhar(Elemento_Pilha *aux){
            this->topo = aux;
            return this->topo;
        }
        Elemento_Pilha* desempilhar(){

            if(this->topo != NULL){
                this->topo = topo->prox;
            }else{
                cout << "Pilha vazia!" << endl;
            }
            return this->topo;
        }
        void printTopo(){
            if(this->topo != NULL){
                cout << this->topo->chave; 
            }else{
                cout << "Pilha vazia!" << endl;
            }
        }
};

class Fila_Encadeada{

};

class Folha{
    public:
        int chave;
        Folha *esq = NULL;
        Folha *dir = NULL;
};

struct result_buscar{
    int f;
    Folha *pt;
    Folha *pai;
};

class Arvore{
    public:
        Folha *raiz = NULL;
        void visitar(Folha *f){
          cout << f->chave << " "; 
        }
        result_buscar buscar(Folha *pt,int chave){
            int f;
            Folha *pai = NULL;
            if(pt == NULL){
                f = 0;
            } else{
                if(pt->chave == chave){
                    f = 1;
                }else{
                    if(chave < pt->chave){
                        if(pt->esq != NULL){
                            pt = pt->esq;
                            result_buscar r = buscar(pt, chave);
                            pt = r.pt;
                            f = r.f;
                            pai = r.pai;
                        } else{
                            f = 2;
                        }
                    }else{
                        if(pt->dir != NULL){
                            pt = pt->dir;
                            result_buscar r = buscar(pt, chave);
                            pt = r.pt;
                            f = r.f;
                            pai = r.pai;
                        }else{
                            if(pt->dir == NULL){
                                f = 3;
                            }else{
                            pai = pt;
                            pt= pt->dir;
                            result_buscar r =  buscar(pt, chave);
                            pt = r.pt;
                            f = r.f;
                            pai = r.pai;
                            }
                        }
                    }
                }
            }
            result_buscar r;
            r.pt = pt;
            r.f = f;
            r.pai = pai;
            return r;
        }
        void pre_ordem(Folha *pt){
            visitar(pt);
            if(pt->esq != NULL){
                pre_ordem(pt->esq);
            }
            if(pt->dir != NULL){
                pre_ordem(pt->dir);
            }
        }   
        void pos_ordem(Folha *pt){
            if(pt->esq != NULL){
                pos_ordem(pt->esq);
            }
            if(pt->dir != NULL){
                pos_ordem(pt->dir);
            }
            visitar(pt);
        }
        void em_ordem(Folha *pt){
            if(pt->esq != NULL){
                em_ordem(pt->esq);
            }
            visitar(pt);
            if(pt->dir != NULL){
                em_ordem(pt->dir);
            }
        }
        void it_pre_ordem(Folha *pt){
            Pilha_Encadeada pilha;
            do{
                visitar(pt);               
                Elemento_Pilha *aux = new Elemento_Pilha();
                aux->chave = pt->chave;
                aux->prox = pilha.topo;
                pilha.empilhar(aux);
                pt = pt->esq;
            }while(pt != NULL);
                
            while(pilha.topo != NULL){          
                result_buscar r = buscar(this->raiz, pilha.topo->chave);
                pt = r.pt;
                if(pt->dir != NULL){
                    visitar(pt->dir);
                }
                pilha.desempilhar();
               
            }
              pt = pt->dir;
            do{
                Elemento_Pilha *aux = new Elemento_Pilha();
                aux->chave = pt->chave;
                aux->prox = pilha.topo;
                pilha.empilhar(aux);
                if(pt->esq!= NULL){
                    visitar(pt->esq);
                }               
                pt = pt->esq;
            }while(pt != NULL);
            
            while(pilha.topo != NULL){          
                result_buscar r = buscar(this->raiz, pilha.topo->chave);
                pt = r.pt;
                if(pt->dir != NULL){
                    visitar(pt->dir);
                }
                pilha.desempilhar();
            }
        }   
        void it_pos_ordem(){
            
        }
        void it_em_ordem(){
            
        }
        
        
        Folha* incluir(Folha *raiz, int chave){
            result_buscar r = buscar(raiz, chave);
            int f  = r.f;
            Folha *pt = r.pt;
            if(f == 1){
                cout << "Chave já existe!" << endl;
            }else{
                Folha *aux = new Folha();
                aux->chave = chave;
                aux->esq = NULL;
                aux->dir = NULL;
                if(f == 0){
                    this->raiz = aux;
                }else{
                    if(f == 2){
                        pt->esq = aux;
                    } else{
                        pt->dir = aux;
                    }
                }
            
            }
            return this->raiz;
        }
        Folha * excluir(Folha *raiz, int chave){
            result_buscar r = buscar(raiz, chave);
            Folha *pt = new Folha();
            Folha *pai = new Folha();
            pt = r.pt;
            int f  = r.f;
            Folha *aux = new Folha();
           
            if(f == 1){
                aux = pt;
                if(pt->esq == NULL && pt->dir == NULL){
                    if(this->raiz == pt){
                       this->raiz = NULL;
                    }else{
                        if(chave < pai->chave){
                            pai->esq = NULL;
                        } else{
                            pai->dir = NULL;
                        }
                    }
                }else{
                    if(pt->esq == NULL){
                        if(this->raiz == pt){
                            this->raiz = pt->dir;
                        } else{
                            if(chave < pai->chave){
                                pai->esq = pt->dir;
                            }else{
                                pai->dir = pt->dir;
                            }
                        }
                    }else{
                        if(pt->dir == NULL){
                            if(this->raiz == pt){
                                this->raiz = pt->esq;
                            }else{
                                if(chave < pai->chave){
                                    pai->esq = pt->esq;
                                } else{
                                    pai->dir = pt->esq;
                                }
                            }
                        }else{
                            Folha *y = pt->dir;
                            Folha *pai_y = pt;
                            while(y->esq != NULL){
                                pai_y = y;
                                y = y->esq;
                            
                                if(pai_y != pt){
                                    pai_y->esq = y->dir;
                                    y->dir = pt->dir;
                                    y->esq = pt->esq;
                                }
                                if(pt == this->raiz){
                                    this->raiz = y;
                                }else{
                                    if(chave < pai->chave){
                                        pai->esq = y;
                                    }else{
                                        pai->dir = y;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return this->raiz;
        }

        void start(){
            int aux = -1;
			while(aux != op.encerrar){
				
				cout << "Digite uma das opções: " << endl;
				cout << "[1] para incluir. [2] para excluir, [3] para buscar, [4] para percorrer em pré-ordem, [5]para percorrer em ordem, [6] para percorrer em pós-ordem e [0] para encerrar" << endl;
				cin >> aux;
				cout << endl;
				if(aux == op.incluir){
					int chave;
					cout << "Digite o valor a ser incluído: ";
					cin >> chave;
					arvore1.incluir(arvore1.raiz, chave);
					cout << endl;
				}
				if(aux == op.excluir){
					int chave;
					cout << "Digite o valor a ser excluído: ";
					cin >> chave;
					arvore1.excluir(arvore1.raiz, chave);
					cout << "Valor excluído com sucesso!";
					cout << endl;
				}
				if(aux==op.pre_ordem){
					
					cout << "Pré-Ordem: " << endl;
					arvore1.it_pre_ordem(arvore1.raiz);
					cout << endl;
				}
				if(aux ==op.em_ordem){
					cout << "Em Ordem: " << endl;
					arvore1.em_ordem(arvore1.raiz);
					cout << endl;
				}
				if(aux == op.pos_ordem){
					cout << "Pós Ordem: " << endl;
					arvore1.pos_ordem(arvore1.raiz);
					cout << endl;
				}
			}
		}
};
#endif

