#include "tree.h"
#include <qmath.h>
#include <QString>
#include <math.h>
#include <QTextEdit>
Tree::Tree(){
tree=NULL;
}
const double NULL_NAME= 1241552132515351.13256768676753421267;
void Tree::addRec(TTree *&_tree, qreal _data){
 if(_tree==NULL){
     _tree=new TTree;
     _tree->data=_data;
     _tree->right=NULL;
     _tree->left=NULL;
 }
 else {
     if(_data<_tree->data) addRec(_tree->left,_data);
     else addRec(_tree->right,_data);
 }
}


void Tree::add(qreal _data){
    addRec(tree,_data);
}

Tree::~Tree(){
    deleteTree(tree);
}
void Tree::deleteTree(TTree *&_tree){
if(_tree){
    if(_tree->left)deleteTree(_tree->left);
    if(_tree->right)deleteTree(_tree->right);
    delete _tree;
    _tree=NULL;
}
}
unsigned int Tree::heightRec(TTree *_tree){
    if(_tree==NULL) return 0;
    int HL = heightRec(_tree->left);
    int HR = heightRec(_tree->right);
    if(HL<HR) return HR+1;
    else return HL+1;
}
unsigned int Tree::height(){
    return heightRec(tree);
}
int callCount;
void Tree::printRec(TTree *_tree, int rang, double **matrix){
    if(_tree!=NULL){
       printRec(_tree->left,rang+1,matrix);
       matrix[rang][callCount]=_tree->data;


       QString sData;
       sData=QString::number(_tree->data);

       int length=sData.length();

       if(matrix[0][callCount]<length) matrix[0][callCount]=length;
        callCount++;
       printRec(_tree->right,rang+1,matrix);
    }
}

void Tree::print(QTextEdit *memo ){
     double **matrix;
int height=heightRec(tree);
     int length=(int)(2*pow(2,(height-1))-1);

     matrix = new double *[height+1];
     for(int i=0;i<height+1;i++){
         matrix[i]=new double[length];
        if(i!=0){
          for(int j=0;j<length;j++)
              matrix[i][j]=NULL_NAME;
        }
      }
     for(int j=0;j<length;j++){
         matrix[0][j]=0;
     }


callCount=0;
    printRec(tree,1,matrix);
    for(int i=1;i<height+1;i++){
        QString q;
        for(int j=0;j<length;j++){
          if(matrix[i][j]==NULL_NAME){
              for(int k=0;k<matrix[0][j];k++) q=q+"  ";
          }
          else q=q+QString::number(matrix[i][j]);
        }
        memo->append(q);
    }
    for(int i=0;i<height+1;i++){
        delete [] matrix[i];
    }

}

void Tree::clear(){
    deleteTree(tree);
}

bool Tree::smallLeftTurn(TTree *&_tree){
TTree *b=_tree->right;
if(((heightRec(b)-heightRec(_tree->left))>2)&&(heightRec(b->left)<=heightRec(b->right))){
    _tree->right=b->left;
    b->left=_tree;
    _tree=b;
    return true;
}
return false;
}
bool Tree::smallRightTurn(TTree *&_tree){
TTree *b=_tree->left;
if(((heightRec(b)-heightRec(_tree->right))>2)&&(heightRec(b->right)<=heightRec(b->left))){
    _tree->left=b->right;
    b->right=_tree;
    _tree=b;
    return true;
}
return false;
}

bool Tree::bigLeftTurn(TTree *&_tree){
    TTree *b=_tree->right;
    if(((heightRec(b)-heightRec(_tree->left))>2)&&(heightRec(b->left)>heightRec(b->right))){
        smallRightTurn(_tree->right);
        smallLeftTurn(_tree);
        return true;
    }
return false;

}
bool Tree::bigRightTurn(TTree *&_tree){
    TTree *b=_tree->left;
    if(((heightRec(b)-heightRec(_tree->right))>2)&&(heightRec(b->right)>heightRec(b->left))){
        smallLeftTurn(_tree->left);
        smallRightTurn(_tree);
        return true;
    }
    return false;
}

void Tree::balanc(){
   while(true){
   if(!(smallLeftTurn(tree)||smallRightTurn(tree)||bigLeftTurn(tree)||bigRightTurn(tree))){
       break;
   }

   }
}





